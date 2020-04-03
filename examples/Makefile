all: example1 example2 example3

example1: example1.c
	$(CC) $(CFLAGS) -I.. -o example1 example1.c ../ea-roots.c -lm $(LDFLAGS)

example2: example2.c
	$(CC) $(CFLAGS) -I.. -o example2 example2.c ../ea-roots.c -lm $(LDFLAGS)

example3: example3.c
	$(CC) $(CFLAGS) -I.. -o example3 example3.c ../ea-roots.c -lm $(LDFLAGS)

clean:
	rm -f example1 example2 example3
