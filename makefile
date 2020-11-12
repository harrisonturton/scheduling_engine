
name=main

src=src/*.cpp

tests=tests/*cpp

build: $(src)
	g++ -Wall -std=c++17 $(src) -o $(name)

test: $(tests)
	g++ -Wall -std=c++17 $(tests) -o run_tests
	./run_tests
