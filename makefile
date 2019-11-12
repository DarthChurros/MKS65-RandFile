ifdef MEM
	DATA  = -g
	VG = valgrind --leak-check=full
endif

all: main.o randgen.o
	gcc $(DATA) -o program main.o randgen.o

main.o: main.c randgen.h
	gcc $(DATA) -c main.c

randgen.o: randgen.c randgen.h
	gcc $(DATA) -c randgen.c

run:
	$(VG) ./program

clean:
	rm *.o
	rm program
