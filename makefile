all: clear clean compile run 

clear:
	@clear

clean:
	@rm -rf *.o a.out

compile: KNNClassifier.o Point.o main.o
	@g++ KNNClassifier.o Point.o main.o -std=c++11

run:
	@./a.out

KNNClassifier.o: KNNClassifier.cpp
	@g++ -c KNNClassifier.cpp -std=c++11

Point.o: Point.cpp
	@g++ -c Point.cpp -std=c++11

main.o: main.cpp
	@g++ -c main.cpp -std=c++11

