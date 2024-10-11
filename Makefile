main : main.o utils.o course.o
	@g++ main.o utils.o course.o -o main

main.o: main.cpp
	@g++ -c main.cpp -o main.o
utils.o: utils.cpp
	@g++ -c utils.cpp -o utils.o
course.o : course.cpp
	@g++ -c course.cpp -o course.o

.PHONY: clean
clean: 
	@rm -f *.o main
