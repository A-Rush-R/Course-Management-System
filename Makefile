main : main.o utils.o course.o terminal.o schedule.o catalogue.o course_container.o
	@g++ main.o utils.o course.o terminal.o schedule.o catalogue.o course_container.o -o main

main.o: main.cpp
	@g++ -c main.cpp -o main.o
utils.o: utils.cpp
	@g++ -c utils.cpp -o utils.o
course.o : course.cpp
	@g++ -c course.cpp -o course.o
schedule.o : schedule.cpp 
	@g++ -c schedule.cpp -o schedule.o
terminal.o : terminal.cpp
	@g++ -c terminal.cpp -o terminal.o
catalogue.o : catalogue.cpp
	@g++ -c catalogue.cpp -o catalogue.o
course_container.o : course_container.cpp
	@g++ -c course_container.cpp -o course_container.o

.PHONY: clean
clean: 
	@rm -f *.o main
