all: bin/bst

bin/bst : build/bst.o
	@echo "Linking.."
	gcc -Iinclude -o bin/bst build/bst.o

build/bst.o : src/bst.c
	@echo " compiling..."
	gcc -Iinclude -o build/bst.o -c src/bst.c

clean :
	@echo " cleaning build dir..."
	rm -f build/*
	@echo " cleaning bin dir..."
	rm -f bin/*

run: bin/bst
	./bin/bst
