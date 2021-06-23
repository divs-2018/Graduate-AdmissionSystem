#compile and link the application
all: main

#run the application
run: main
	./main

#run the unit test
runu: unit
	./unit

#link main.o and student.o to executable main
main: main.o student.o
	g++ -g -o main main.o student.o

unit: unittest.o student.o
	g++ -g -o unit unittest.o student.o

#compile the main.cpp to main.o
main.o: main.cpp
	g++ -g -c main.cpp

#compile the student.cpp to student.o
student.o: student.cpp
	g++ -g -c student.cpp

unittest.o: unittest.cpp
	g++ -g -c unittest.cpp

#remove built files
clean:
	rm -rf main main.o student.o unit unittest.o*~
