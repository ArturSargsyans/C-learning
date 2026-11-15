CFLAGS = -Wno-implicit-function-declaration

all: final

final: part1.o part2.o
	echo "linking part1.o and part2.o to get final app"
	gcc $(CFLAGS) part1.o part2.o -o final_program

part1.o: part1.c
	echo "compiling part1"
	gcc $(CFLAGS) -c part1.c

part2.o: part2.c
	echo "compiling part2"
	gcc $(CFLAGS) -c part2.c

clean:
	echo "Removing all temp files"
	rm part1.o part2.o final_program