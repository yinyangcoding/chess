# build the build directory

Main: build build/Main.o build/objects/Coordinate.o build/objects/Move.o build/objects/Piece.o build/objects/pieces/King.o build/objects/pieces/Queen.o build/objects/pieces/Bishop.o build/objects/pieces/Knight.o build/objects/pieces/Rook.o build/objects/pieces/Pawn.o build/objects/Board.o build/objects/Player.o build/resources/Tools.o
	g++ build/Main.o build/objects/Coordinate.o build/objects/Move.o build/objects/Piece.o build/objects/pieces/King.o build/objects/pieces/Queen.o build/objects/pieces/Bishop.o build/objects/pieces/Knight.o build/objects/pieces/Rook.o build/objects/pieces/Pawn.o build/objects/Board.o build/objects/Player.o build/resources/Tools.o -o bin/Main

build/Main.o: build src/Main.cpp
	g++ -c src/Main.cpp -o build/Main.o

build/objects/Coordinate.o: build src/objects/Coordinate.cpp include/objects/Coordinate.hpp
	g++ -c src/objects/Coordinate.cpp -o build/objects/Coordinate.o

build/objects/Move.o: build src/objects/Move.cpp include/objects/Move.hpp
	g++ -c src/objects/Move.cpp -o build/objects/Move.o

build/objects/Piece.o: build src/objects/Piece.cpp include/objects/Piece.hpp
	g++ -c src/objects/Piece.cpp -o build/objects/Piece.o

build/objects/Board.o: build src/objects/Board.cpp include/objects/Board.hpp
	g++ -c src/objects/Board.cpp -o build/objects/Board.o

build/objects/Player.o: build src/objects/Player.cpp include/objects/Player.hpp
	g++ -c src/objects/Player.cpp -o build/objects/Player.o


build/objects/pieces/King.o: build src/objects/pieces/King.cpp include/objects/pieces/King.hpp
	g++ -c src/objects/pieces/King.cpp -o build/objects/pieces/King.o

build/objects/pieces/Queen.o: build src/objects/pieces/Queen.cpp include/objects/pieces/Queen.hpp
	g++ -c src/objects/pieces/Queen.cpp -o build/objects/pieces/Queen.o

build/objects/pieces/Bishop.o: build src/objects/pieces/Bishop.cpp include/objects/pieces/Bishop.hpp
	g++ -c src/objects/pieces/Bishop.cpp -o build/objects/pieces/Bishop.o

build/objects/pieces/Knight.o: build src/objects/pieces/Knight.cpp include/objects/pieces/Knight.hpp
	g++ -c src/objects/pieces/Knight.cpp -o build/objects/pieces/Knight.o

build/objects/pieces/Rook.o: build src/objects/pieces/Rook.cpp include/objects/pieces/Rook.hpp
	g++ -c src/objects/pieces/Rook.cpp -o build/objects/pieces/Rook.o

build/objects/pieces/Pawn.o: build src/objects/pieces/Pawn.cpp include/objects/pieces/Pawn.hpp
	g++ -c src/objects/pieces/Pawn.cpp -o build/objects/pieces/Pawn.o


build/resources/Tools.o: build src/resources/Tools.cpp include/resources/Tools.hpp
	g++ -c src/resources/Tools.cpp -o build/resources/Tools.o


build:
	mkdir -p build/objects/pieces
	mkdir -p build/resources
	mkdir -p bin/test

clean:
	rm bin/Main build/objects/*.o build/objects/pieces/*.o build/resources/*.o build/*.o
