COMMON_FILES = common.c

all: tests

tests: nroots simple

check: tests
	./nroots
	./simple

nroots: nroots.c common.c
	$(CC) $(CFLAGS) -I.. -o $@ $< $(COMMON_FILES) ../ea-roots.c -lm $(LDFLAGS)

simple: simple.c 
	$(CC) $(CFLAGS) -I.. -o $@ $< ../ea-roots.c -lm $(LDFLAGS)


clean:
	rm -f nroots
