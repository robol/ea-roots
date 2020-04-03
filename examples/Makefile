all: example1 example2 example3

example1: example1.c
	$(CC) -I.. -o example1 example1.c ../ea-roots.c -lm

example2: example2.c
	$(CC) -I.. -o example2 example2.c ../ea-roots.c -lm

example3: example3.c
	$(CC) -I.. -o example3 example3.c ../ea-roots.c -lm

clean:
	rm -f example1 example2 example3
