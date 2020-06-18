# build the bin directory

Main: bin bin/Main.o bin/objects/Coordinate.o bin/objects/Move.o bin/objects/Piece.o bin/objects/pieces/King.o bin/objects/pieces/Queen.o bin/objects/pieces/Bishop.o bin/objects/pieces/Knight.o bin/objects/pieces/Rook.o bin/objects/pieces/Pawn.o bin/objects/Board.o bin/objects/Player.o bin/resources/Tools.o
	g++ bin/Main.o bin/objects/Coordinate.o bin/objects/Move.o bin/objects/Piece.o bin/objects/pieces/King.o bin/objects/pieces/Queen.o bin/objects/pieces/Bishop.o bin/objects/pieces/Knight.o bin/objects/pieces/Rook.o bin/objects/pieces/Pawn.o bin/objects/Board.o bin/objects/Player.o bin/resources/Tools.o -o Main

bin/Main.o: bin src/Main.cpp
	g++ -c src/Main.cpp -o bin/Main.o

bin/objects/Coordinate.o: bin src/objects/Coordinate.cpp src/objects/Coordinate.hpp
	g++ -c src/objects/Coordinate.cpp -o bin/objects/Coordinate.o

bin/objects/Move.o: bin src/objects/Move.cpp src/objects/Move.hpp
	g++ -c src/objects/Move.cpp -o bin/objects/Move.o

bin/objects/Piece.o: bin src/objects/Piece.cpp src/objects/Piece.hpp
	g++ -c src/objects/Piece.cpp -o bin/objects/Piece.o

bin/objects/Board.o: bin src/objects/Board.cpp src/objects/Board.hpp
	g++ -c src/objects/Board.cpp -o bin/objects/Board.o

bin/objects/Player.o: bin src/objects/Player.cpp src/objects/Player.hpp
	g++ -c src/objects/Player.cpp -o bin/objects/Player.o


bin/objects/pieces/King.o: bin src/objects/pieces/King.cpp src/objects/pieces/King.hpp
	g++ -c src/objects/pieces/King.cpp -o bin/objects/pieces/King.o

bin/objects/pieces/Queen.o: bin src/objects/pieces/Queen.cpp src/objects/pieces/Queen.hpp
	g++ -c src/objects/pieces/Queen.cpp -o bin/objects/pieces/Queen.o

bin/objects/pieces/Bishop.o: bin src/objects/pieces/Bishop.cpp src/objects/pieces/Bishop.hpp
	g++ -c src/objects/pieces/Bishop.cpp -o bin/objects/pieces/Bishop.o

bin/objects/pieces/Knight.o: bin src/objects/pieces/Knight.cpp src/objects/pieces/Knight.hpp
	g++ -c src/objects/pieces/Knight.cpp -o bin/objects/pieces/Knight.o

bin/objects/pieces/Rook.o: bin src/objects/pieces/Rook.cpp src/objects/pieces/Rook.hpp
	g++ -c src/objects/pieces/Rook.cpp -o bin/objects/pieces/Rook.o

bin/objects/pieces/Pawn.o: bin src/objects/pieces/Pawn.cpp src/objects/pieces/Pawn.hpp
	g++ -c src/objects/pieces/Pawn.cpp -o bin/objects/pieces/Pawn.o


bin/resources/Tools.o: bin src/resources/Tools.cpp src/resources/Tools.hpp
	g++ -c src/resources/Tools.cpp -o bin/resources/Tools.o


bin:
	mkdir -p bin/objects/pieces
	mkdir -p bin/resources

clean:
	rm Main bin/objects/*.o bin/objects/pieces/*.o bin/resources/*.o bin/*.o
