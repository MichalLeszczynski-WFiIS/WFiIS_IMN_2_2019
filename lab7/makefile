CXX = g++
EXEC = Program
CXXFLAGS = -Wall -g -pedantic -MMD -MP  -Wextra -Wshadow -Wnon-virtual-dtor -Wold-style-cast -Wcast-align -Wunused -Woverloaded-virtual -Wpedantic -Wconversion -Wsign-conversion -Wnull-dereference -Wdouble-promotion -Wformat=2 -Wduplicated-cond -Wduplicated-branches -Wlogical-op -Wuseless-cast -fsanitize=leak -fsanitize=address  -fsanitize=undefined  -fsanitize=pointer-compare  -fsanitize=pointer-subtract

LIBS = -lm

CALL=$(wildcard callgrind*)

SRC=$(wildcard *.cpp)
OBJS=$(SRC:.cpp=.o)
DEPS=$(SRC:.cpp=.d)

all: 
	make gendata
	make draw

$(EXEC): $(OBJS) 
	$(CXX) $(CXXFLAGS) $+ -o $@


*.o: *.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean run rebuild debug memcheck

rebuild: 
	make clean
	make run
	make clean

clean:
	make cleancompiled
	make cleandata


cleandata:
	rm -f *.dat
	rm -f callgrind*
	rm -f *.jpeg
	rm -f *.png

cleancompiled:
	rm -f *.o
	rm -f *~
	rm -f *.d
	rm -f $(EXEC)

gendata:
	make clean
	make run
	make cleancompiled

draw: 
	gnuplot gnuskrypt.sh

debug:
	gdb $(EXEC)
memcheck:
	valgrind --leak-check=full ./$(EXEC)

run: $(EXEC)
	./$(EXEC)

callgrind: $(EXEC)
	rm -rf callgrind*
	valgrind --tool=callgrind ./$(EXEC)
	callgrind_annotate $(CALL)

-include $(DEPS)