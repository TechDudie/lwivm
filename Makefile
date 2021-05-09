lwivm:
	mkdir bin
	gcc src/lwivm.c -o bin/lwivm
	gcc src/assembler.c -o bin/assembler
	gcc src/compiler.c -o bin/compiler