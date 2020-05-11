
bin/main: bin/DNI.o include/arbol_bb.hpp include/nodo_bb.hpp src/main.cpp
	g++ -g bin/DNI.o src/main.cpp -o bin/main


bin/DNI.o: include/DNI.hpp src/DNI.cpp
	g++ -g -c src/DNI.cpp -o bin/DNI.o

.PHONY:
clean:
	rm bin/*
