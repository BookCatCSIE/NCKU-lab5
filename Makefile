HugeInt: HugeInt.o main.o
	g++ HugeInt.o main.o -o HugeInt

HugeInt.o: HugeInt.cpp HugeInt.h
	g++ -c HugeInt.cpp

main.o: main.cpp HugeInt.h
	g++ -c main.cpp

clean:
	rm HugeInt*.o
