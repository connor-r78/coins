train:
	./main.out -t

run:
	./main.out -r

compile:
	cython -o src/circulate.c src/circulate.pyx
	gcc src/circulate.c src/cython.c src/main.c \
        -o main.out \
        $$(python3-config --embed --cflags --ldflags) \
	-Wl,-rpath,/Users/connorrakov/anaconda3/lib \
	-L/Users/connorrakov/anaconda3/lib
