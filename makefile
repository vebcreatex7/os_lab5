


all: main


main: libarr.so main_dynamic.o main_static.o
	gcc -o static main_static.o -L. -larr -Wl,-rpath,.
	gcc -o dynamic main_dynamic.o -ldl

main_dynamic.o: main_dynamic.c
	gcc -c main_dynamic.c

main_static.o: main_static.c
	gcc -c main_static.c

libarr.so: stack.o
	gcc -shared -o libarr.so stack.o

stack.o: stack.c
	gcc -c -fPIC stack.c

clean:
	rm -f *.o *.so static dynamic