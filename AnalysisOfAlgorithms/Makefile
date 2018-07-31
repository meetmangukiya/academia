CC=gcc

O_FILES=bubble_sort.o insertion_sort.o shell_sort.o quick_sort.o radix_sort.o utils.o

sort: $(O_FILES) sort.c
	$(CC) -g bubble_sort.o insertion_sort.o shell_sort.o quick_sort.o radix_sort.o utils.o sort.c -o sort -lm

bubble_sort.o: bubble_sort.c sort.h
	$(CC) -c bubble_sort.c

insertion_sort.o: insertion_sort.c sort.h
	$(CC) -c insertion_sort.c

shell_sort.o: shell_sort.c sort.h insertion_sort.o
	$(CC) -c shell_sort.c

quick_sort.o: quick_sort.c sort.h
	$(CC) -c quick_sort.c

radix_sort.o: radix_sort.c sort.h
	$(CC) -c radix_sort.c

utils.o: utils.c
	$(CC) -c utils.c

clean:
	rm -f $(O_FILES) sort
