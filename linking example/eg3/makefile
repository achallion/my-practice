all:	progcpp	progc

progcpp:	progcpp.o
	g++ progcpp.o -o progcpp

progcpp.o:	main.o	sum.o
	ld -r main.o sum.o -o progcpp.o

main.o:	main.cpp
	g++ -c main.cpp -o main.o

sum.o:	sum.cpp
	g++ -c sum.cpp -o sum.o

progc:	progc.o
	g++ progc.o	-o progc

progc.o:	mainc.o	sum.o
	ld -r mainc.o sum.o -o progc.o

mainc.o:	main.c
	g++ -c main.c -o mainc.o

sum.o:	sum.cpp
	g++ -c sum.cpp -o sum.o

clean:
	rm *.o progcpp progc