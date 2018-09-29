all:str.o
	gcc str.o
	./a.out
	rm *.o ./a.out
str.o: str.c str.h
	gcc -c str.c