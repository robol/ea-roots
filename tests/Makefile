COMMON_FILES = common.c

all: tests

tests: nroots

check: tests
	./nroots

nroots: nroots.c common.c
	$(CC) -I.. -o nroots nroots.c $(COMMON_FILES) ../ea-roots.c -lm

clean:
	rm -f nroots
