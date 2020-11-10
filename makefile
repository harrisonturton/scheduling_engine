
name=main

files=avl/avl.cpp *.cpp

build: $(files)
	g++ -Wall -std=c++17 $(files) -o $(name)
