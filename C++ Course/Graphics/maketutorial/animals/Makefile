dog.o : dog.cpp dog.hpp
	g++ -c dog.cpp

main.o : main.cpp
	g++ -c main.cpp

dog_program : dog.o main.o
	g++ dog.o main.o -o dog_program

clean :
	rm dog_program *.o