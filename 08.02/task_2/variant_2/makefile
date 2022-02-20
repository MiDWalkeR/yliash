# This is the default target, which will be built when 
# you invoke make
.PHONY: all
all: main install

# This rule tells make how to build main from main.cpp
main: main.cpp
	g++ -Wall -std=c++2a -o main main.cpp

# This rule tells make to copy main to the binaries subdirectory,
# creating it if necessary
.PHONY: install
install:
	mkdir -p binaries
	mv main binaries

# This rule tells make to delete main and main.o
.PHONY: clean 
clean:
	rm -rf main binaries
