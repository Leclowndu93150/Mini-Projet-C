all: run

main: main.c source.c
	gcc main.c source.c -o main

run: main
	./main

clean:
	rm -f main *.o