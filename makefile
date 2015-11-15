project: main.o library.o
	cc main.o library.o -o project
main.o: main.c library.h
	cc -Wall -c main.c
library.o: library.c library.h
	cc -Wall -c library.c
