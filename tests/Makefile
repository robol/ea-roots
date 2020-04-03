COMMON_FILES = common.c

all: tests

tests: nroots

check: tests
	./nroots

nroots: nroots.c common.c
	$(CC) $(CFLAGS) -I.. -o nroots nroots.c $(COMMON_FILES) ../ea-roots.c -lm $(LDFLAGS)

clean:
	rm -f nroots
