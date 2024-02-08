project01: main.o fraction.o point.o
	g++ -o project01 main.o fraction.o point.o

main.o: main.cc 
	g++ -c main.cc

fraction.o: fraction.cc fraction.h
	g++ -c fraction.cc

point.o: point.cc point.h fraction.h
	g++ -c point.cc
