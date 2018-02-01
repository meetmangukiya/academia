CC=gcc

sort: bubble_sort.o insertion_sort.o shell_sort.o quick_sort.o utils.o
	$(CC) bubble_sort.o insertion_sort.o shell_sort.o quick_sort.o utils.o sort.c -o sort

bubble_sort.o: bubble_sort.c sort.h
	$(CC) -c bubble_sort.c

insertion_sort.o: insertion_sort.c sort.h
	$(CC) -c insertion_sort.c

shell_sort.o: shell_sort.c sort.h insertion_sort.o
	$(CC) -c shell_sort.c

quick_sort.o: quick_sort.c sort.h
	$(CC) -c quick_sort.c

utils.o: utils.c
	$(CC) -c utils.c

clean:
	rm bubble_sort.o insertion_sort.o shell_sort.o utils.o quick_sort.o sort
