CXX=clang++-14
CXXVERSION=c++2a
TIDY=clang-tidy-14
SOURCE_PATH=sources
OBJECT_PATH=objects
CXXFLAGS=-std=$(CXXVERSION) -Werror -Wsign-conversion -I$(SOURCE_PATH)
TIDY_FLAGS=-extra-arg=-std=$(CXXVERSION) -checks=bugprone-*,clang-analyzer-*,cppcoreguidelines-*,performance-*,portability-*,readability-*,-cppcoreguidelines-pro-bounds-pointer-arithmetic,-cppcoreguidelines-owning-memory --warnings-as-errors=*
VALGRIND_FLAGS=-v --leak-check=full --show-leak-kinds=all  --error-exitcode=99

run: test

demo: Demo.o
	$(CXX) $(CXXFLAGS) $^ -o $@
demo2: Demo2.o
	$(CXX) $(CXXFLAGS) $^ -o $@

demo3: Box.o
	$(CXX) $(CXXFLAGS) $^ -o $@
demo4: MatrixSquare.o
	$(CXX) $(CXXFLAGS) $^ -o $@

demo5: MyIterator.o
	$(CXX) $(CXXFLAGS) $^ -o $@
demo6: syntax.o
	$(CXX) $(CXXFLAGS) $^ -o $@
clean:
	rm -f $(OBJECTS) *.o test* demo*
