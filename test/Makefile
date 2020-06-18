# ../build the ../build directory

Test: dependencies
	g++ ../build/test/Test.o ../build/objects/Coordinate.o ../build/objects/Move.o ../build/objects/Piece.o ../build/objects/pieces/King.o ../build/objects/pieces/Queen.o ../build/objects/pieces/Bishop.o ../build/objects/pieces/Knight.o ../build/objects/pieces/Rook.o ../build/objects/pieces/Pawn.o ../build/objects/Board.o ../build/objects/Player.o ../build/resources/Tools.o -o ../bin/test/Test
	cp ../bin/test/Test ./Test

../build/test/Test.o:
	g++ -c Test.cpp -o ../build/test/Test.o

dependencies: ../build ../build/test/Test.o ../build/objects/Coordinate.o ../build/objects/Move.o ../build/objects/Piece.o ../build/objects/pieces/King.o ../build/objects/pieces/Queen.o ../build/objects/pieces/Bishop.o ../build/objects/pieces/Knight.o ../build/objects/pieces/Rook.o ../build/objects/pieces/Pawn.o ../build/objects/Board.o ../build/objects/Player.o ../build/resources/Tools.o
	# Make dependencies

../build/objects/Coordinate.o: ../build ../src/objects/Coordinate.cpp ../src/objects/Coordinate.hpp
	g++ -c ../src/objects/Coordinate.cpp -o ../build/objects/Coordinate.o

../build/objects/Move.o: ../build ../src/objects/Move.cpp ../src/objects/Move.hpp
	g++ -c ../src/objects/Move.cpp -o ../build/objects/Move.o

../build/objects/Piece.o: ../build ../src/objects/Piece.cpp ../src/objects/Piece.hpp
	g++ -c ../src/objects/Piece.cpp -o ../build/objects/Piece.o

../build/objects/Board.o: ../build ../src/objects/Board.cpp ../src/objects/Board.hpp
	g++ -c ../src/objects/Board.cpp -o ../build/objects/Board.o

../build/objects/Player.o: ../build ../src/objects/Player.cpp ../src/objects/Player.hpp
	g++ -c ../src/objects/Player.cpp -o ../build/objects/Player.o


../build/objects/pieces/King.o: ../build ../src/objects/pieces/King.cpp ../src/objects/pieces/King.hpp
	g++ -c ../src/objects/pieces/King.cpp -o ../build/objects/pieces/King.o

../build/objects/pieces/Queen.o: ../build ../src/objects/pieces/Queen.cpp ../src/objects/pieces/Queen.hpp
	g++ -c ../src/objects/pieces/Queen.cpp -o ../build/objects/pieces/Queen.o

../build/objects/pieces/Bishop.o: ../build ../src/objects/pieces/Bishop.cpp ../src/objects/pieces/Bishop.hpp
	g++ -c ../src/objects/pieces/Bishop.cpp -o ../build/objects/pieces/Bishop.o

../build/objects/pieces/Knight.o: ../build ../src/objects/pieces/Knight.cpp ../src/objects/pieces/Knight.hpp
	g++ -c ../src/objects/pieces/Knight.cpp -o ../build/objects/pieces/Knight.o

../build/objects/pieces/Rook.o: ../build ../src/objects/pieces/Rook.cpp ../src/objects/pieces/Rook.hpp
	g++ -c ../src/objects/pieces/Rook.cpp -o ../build/objects/pieces/Rook.o

../build/objects/pieces/Pawn.o: ../build ../src/objects/pieces/Pawn.cpp ../src/objects/pieces/Pawn.hpp
	g++ -c ../src/objects/pieces/Pawn.cpp -o ../build/objects/pieces/Pawn.o


../build/resources/Tools.o: ../build ../src/resources/Tools.cpp ../src/resources/Tools.hpp
	g++ -c ../src/resources/Tools.cpp -o ../build/resources/Tools.o


../build:
	mkdir -p ../build/objects/pieces
	mkdir -p ../build/resources

clean:
	rm ../build/objects/*.o ../build/test/*.o ../build/objects/pieces/*.o ../build/resources/*.o ../build/*.o
