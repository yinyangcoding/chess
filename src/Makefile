Main: ../include/resources/Constants.h ../build ../build/Main.o ../build/objects/Coordinate.o ../build/resources/Move.o ../build/objects/Piece.o ../build/objects/Board.o ../build/objects/Player.o ../build/resources/Tools.o ../build/resources/BlandTools.o
	g++ ../build/Main.o ../build/objects/Coordinate.o ../build/resources/Move.o ../build/objects/Piece.o ../build/objects/Board.o ../build/objects/Player.o ../build/resources/Tools.o ../build/resources/BlandTools.o -o Main

../build/Main.o: ../build ../src/Main.cpp ../include/resources/Constants.h
	g++ -c ../src/Main.cpp -o ../build/Main.o

../build/objects/Coordinate.o: ../include/resources/Constants.h ../build ../src/objects/Coordinate.cpp ../include/objects/Coordinate.hpp
	g++ -c ../src/objects/Coordinate.cpp -o ../build/objects/Coordinate.o

../build/resources/Move.o: ../include/resources/Constants.h ../build ../src/resources/Move.cpp ../include/resources/Move.hpp
	g++ -c ../src/resources/Move.cpp -o ../build/resources/Move.o

../build/objects/Piece.o: ../include/resources/Constants.h ../build ../src/objects/Piece.cpp ../include/objects/Piece.hpp
	g++ -c ../src/objects/Piece.cpp -o ../build/objects/Piece.o

../build/objects/Board.o: ../include/resources/Constants.h ../build ../src/objects/Board.cpp ../include/objects/Board.hpp
	g++ -c ../src/objects/Board.cpp -o ../build/objects/Board.o

../build/objects/Player.o: ../include/resources/Constants.h ../build ../src/objects/Player.cpp ../include/objects/Player.hpp
	g++ -c ../src/objects/Player.cpp -o ../build/objects/Player.o


../build/resources/Tools.o: ../include/resources/Constants.h ../build ../src/resources/Tools.cpp ../include/resources/Tools.hpp
	g++ -c ../src/resources/Tools.cpp -o ../build/resources/Tools.o

../build/resources/BlandTools.o: ../include/resources/Constants.h ../build ../src/resources/BlandTools.cpp ../include/resources/BlandTools.hpp
	g++ -c ../src/resources/BlandTools.cpp -o ../build/resources/BlandTools.o


../build:
	mkdir ../build
	mkdir ../build/objects
	mkdir ../build/resources

clean:
	rm ../build/objects/*.o ../build/resources/*.o ../build/*.o

