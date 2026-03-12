COMPILER = gcc
OPT = -Wreturn-type -Wimplicit-function-declaration -pedantic

all: bit_decode bit_decode

bit_decode: bit_decode.o
	$(COMPILER) bit_decode.o -o bit_decode

bit_decode.o: bit_decode.c
	$(COMPILER) $(OPT) -c bit_decode.c -o bit_decode.o

lab2.zip: Makefile bit_decode.c
	zip lab2.zip Makefile bit_decode.c

clean:
	rm -rf *.o bit_decode lab2.zip
