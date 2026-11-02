CXX = g++
CXXFLAGS = -Wall -std=c++11

TARGET = router_network
OBJ = router_lib.o router_main.o
TEST_TARGET = router_tests
MEMORY_TARGET = router_memory_test

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET) $(TEST_TARGET) $(MEMORY_TARGET)

run: $(TARGET)
	./$(TARGET)

test: router_unit_test.cpp router_lib.cpp router_lib.h
	$(CXX) -Wall -std=c++14 router_unit_test.cpp router_lib.cpp -lgtest -lgtest_main -pthread -o $(TEST_TARGET)
	./$(TEST_TARGET)

memtest: router_memory_test.cpp router_lib.cpp router_lib.h
	$(CXX) $(CXXFLAGS) -g -O0 router_memory_test.cpp router_lib.cpp -o $(MEMORY_TARGET)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(MEMORY_TARGET)
