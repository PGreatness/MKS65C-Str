compile:str.o
	gcc str.o
run:
	./a.out
	rm *.o ./a.out
str.o: str.c str.h
	gcc -c str.c
