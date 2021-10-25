Path=$(PWD)


IncludeDir="$(Path)/include"
IncludeHPP = $(wildcard include/*.hpp)


LONG=long #use this for long doubles
# LONG= 

CC=g++
OPT=-O3
STD=-std=c++17

FLG=-I$(IncludeDir) $(OPT) $(STD) -DLONG=$(LONG)

all: example_comET.run

example_comET.run:  makefile $(IncludeHPP) example_comET.cpp
	$(CC) -o example_comET.run $(FLG) example_comET.cpp

clean:
	rm example_comET.run || true