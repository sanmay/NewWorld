build: MergeSort.cpp
	g++ MergeSort.cpp -o MergeSort.o

build_debug: MergeSort.cpp
	g++ MergeSort.cpp -o MergeSort.o -D DEBUG
clean: 
	rm -f *.o

execute:
	./MergeSort.o
	
rebuild: clean build

run: rebuild execute