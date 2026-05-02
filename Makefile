all: main

main: main.c source.c
	gcc main.c source.c -o main

clean:
	rm -f main *.o