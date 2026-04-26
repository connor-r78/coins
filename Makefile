run:
	cython -o src/circulate.c src/circulate.pyx
	gcc src/circulate.c src/cython.c src/main.c -o circulate.out \
        $$(python3-config --embed --cflags --ldflags) \
	-Wl,-rpath,/Users/connorrakov/anaconda3/lib \
	-L/Users/connorrakov/anaconda3/lib
	./circulate.out
