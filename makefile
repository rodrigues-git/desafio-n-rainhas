all: main.o
	gcc main.o -o programa.exe

main.o: main.c
	gcc -Wall -c main.c

run: programa.exe
	./programa.exe

clean:
	del *.o *.exe