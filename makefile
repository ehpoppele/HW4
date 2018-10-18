CXX = g++
CCFLAGS = -O3 -Wall -Wextra -pedantic

all: pi test 

test: test.cc
	$(CXX) $(CCFLAGS) test.cc -o test

pi: main.o gridpi.o
	$(CXX) $(CCFLAGS) main.o gridpi.o -o pi

gridpi.o: gridpi.cc
	$(CXX) $(CCFLAGS) gridpi.cc -c

main.o: main.cc
	$(CXX) $(CCFLAGS) main.cc -c

clean :
	rm main.o gridpi.o