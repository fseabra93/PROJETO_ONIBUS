all: 
	g++ -c main.cpp onibus.cpp
	g++ -o prog main.o onibus.o

rodar:
	./prog

limpar:
	rm -f prog *.o 
