all:str.o
    gcc str.o
str.o: str.c str.h
	gcc --c str.c

