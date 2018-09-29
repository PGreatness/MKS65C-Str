all:str.o
	gcc str.o
	./a.out
str.o: str.c
	gcc -c str.c