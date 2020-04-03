all:
	make -C examples
	make -C tests

clean:
	make -C examples clean
	make -C tests clean

check:
	make -C tests check
