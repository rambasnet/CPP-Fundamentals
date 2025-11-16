CXX = g++
CXXFLAGS = -std=c++17 -I tests
SRC = $(wildcard src/*.cpp)
TESTS = $(wildcard tests/*.cpp)

run_tests:
	$(CXX) $(CXXFLAGS) $(TESTS) $(SRC) -o doctest_runner.exe
	./doctest_runner.exe
	@echo "All tests executed successfully!"

clean:
	find . -type f -name "doctest_runner.exe" -delete
	find . -type f -name "*.o" -delete