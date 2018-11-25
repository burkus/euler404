all:
	gcc -std=c99 -Wall main.c euler.c -o bin/main -lm

optimal:
	gcc -std=c99 -Wall main.c euler.c -lm -O3 -o bin/main 

clean:
	rm bin/*
