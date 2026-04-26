import joblib
import numpy
import pandas
import warnings

from sklearn.svm import SVC
from sklearn.preprocessing import StandardScaler
from sklearn.model_selection import train_test_split

warnings.filterwarnings("ignore")

scaler = None;
svm_clf = None;

features = [
  "Commemorative", "Mintage", "Year"
]

cdef public int create_circulator():
  global scaler, svm_clf

  data = pandas.read_csv("src/data/data.csv", usecols = ["Year", "Commemorative", "Count", "Mintage"])
  data = data.dropna(subset = ["Mintage"])
  data = data.dropna(subset = ["Year"])
  data = data.fillna(0)
  data["Mintage"] = data["Mintage"].str.replace(',', '', regex=False).astype(float)
  data = data[data["Mintage"] != 0]

  X = data[features].values
  y = data["Count"].astype(int).values

  scaler = StandardScaler()
  X_scaled = scaler.fit_transform(X)

  X_train, X_test, y_train, y_test = train_test_split(X_scaled, y)

  svm_clf = SVC(kernel = "rbf", random_state = 0, class_weight = "balanced")
  svm_clf.fit(X_train, y_train)

  joblib.dump(scaler, "models/circulator_scaler.joblib")
  joblib.dump(svm_clf, "models/circulator_svm.joblib")

  return 0

cdef public int load_circulator():
  global scaler, svm_clf

  scaler = joblib.load("models/circulator_scaler.joblib")
  svm_clf = joblib.load("models/circulator_svm.joblib")

  return 0

cdef public int predict_circulation():
  global scaler, svm_clf

  test_data = pandas.DataFrame([
    {"Year": 1820, "Commemorative": 0, "Mintage": 500}
  ])

  X_new = scaler.transform(test_data[features])
  preds = svm_clf.predict(X_new)

  test_data["Predicted_Count"] = preds
  print(test_data)

  return 0
