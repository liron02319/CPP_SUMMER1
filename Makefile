#!make -f

CXX=clang
CXXFLAGS=-std=c++11 -Werror -Wsign-conversion
VALGRIND_FLAGS=-v --leak-check=full --show-leak-kinds=all  --error-exitcode=99

TEST_S=TestCounter.cpp Test.cpp
CODE_S = Graph.cpp Algorithms.cpp 
CODE_OBJECTS=$(subst .cpp,.o,$(CODE_S))
TEST_OBJECTS=$(subst .cpp,.o,$(TEST_S))

run: demo
	./$^

demo: Demo.o $(CODE_OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o demo -lstdc++

test: $(CODE_OBJECTS) $(TEST_OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o test -lstdc++ -lm

tidy:
	clang-tidy $(SOURCES) -checks=bugprone-*,clang-analyzer-*,cppcoreguidelines-*,performance-*,portability-*,readability-*,-cppcoreguidelines-pro-bounds-pointer-arithmetic,-cppcoreguidelines-owning-memory --warnings-as-errors=-* --

valgrind: demo test
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./demo 2>&1 | { egrep "lost| at " || true; }
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./test 2>&1 | { egrep "lost| at " || true; }

%.o: %.cpp
	$(CXX) $(CXXFLAGS) --compile $< -o $@

clean:
	rm -f *.o demo test