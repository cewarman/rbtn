CC=gcc -Ofast

all: search_network RBTN
	@echo -n
RBTN: RBTN.o TNlib.o
	gcc -Ofast -o RBTN RBTN.o TNlib.o
clean:
	rm -rf RBTN RBTN.o TNlib.o
search_network:
	cd fst_gen; gcc -Ofast -o tools/bin/fst2network_h tools/src/fst2network_h.c; sh new_run.sh; cd ..
.PHONY: build_RBTN clean
