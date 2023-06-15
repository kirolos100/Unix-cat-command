all: Say_hello Say_cat
Say_hello:
	gcc -o main.out main.c
Say_cat:
	./main.out
