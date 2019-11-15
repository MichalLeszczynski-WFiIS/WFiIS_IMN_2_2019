CXX = g++
EXEC = Program
CXXFLAGS = -Wall -g -pedantic -MMD -MP  -Wextra -Wshadow -Wnon-virtual-dtor -Wold-style-cast -Wcast-align -Wunused -Woverloaded-virtual -Wpedantic -Wconversion -Wsign-conversion -Wnull-dereference -Wdouble-promotion -Wformat=2 -Wduplicated-cond -Wduplicated-branches -Wlogical-op -Wuseless-cast -fsanitize=leak -fsanitize=address  -fsanitize=undefined  -fsanitize=pointer-compare  -fsanitize=pointer-subtract

LIBS = -lm

CALL=$(wildcard callgrind*)

SRC=$(wildcard *.cpp)
OBJS=$(SRC:.cpp=.o)
DEPS=$(SRC:.cpp=.d)
all:
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
	rm -f *.o
	rm -f *~
	rm -f *.d
	rm -f $(EXEC)
	rm -f callgrind*

cleandata:
	rm -f *.dat

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