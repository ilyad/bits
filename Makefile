.PHONY: test

all: bits.exe test

bits.exe: foo.inline.c++ main.c++
	cc -o $@ main.c++

test: bits.exe
	./bits.exe
