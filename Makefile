exec=Chess

Chess: buildAlert build include/resources/Constants.h build/Chess.o build/Coordinate.o build/Move.o build/Piece.o build/Board.o build/Player.o build/Tools.o build/BlandTools.o
	g++ build/Chess.o build/Coordinate.o build/Move.o build/Piece.o build/Board.o build/Player.o build/Tools.o build/BlandTools.o -o bin/Chess

buildAlert:
	@echo "🚧 Building..."

build/Chess.o: src/Chess.cpp include/resources/Constants.h
	g++ -c src/Chess.cpp -o build/Chess.o

build/Coordinate.o: include/resources/Constants.h build src/objects/Coordinate.cpp include/objects/Coordinate.hpp
	g++ -c src/objects/Coordinate.cpp -o build/Coordinate.o

build/Move.o: include/resources/Constants.h build src/resources/Move.cpp include/resources/Move.hpp
	g++ -c src/resources/Move.cpp -o build/Move.o

build/Piece.o: include/resources/Constants.h build src/objects/Piece.cpp include/objects/Piece.hpp
	g++ -c src/objects/Piece.cpp -o build/Piece.o

build/Board.o: include/resources/Constants.h build src/objects/Board.cpp include/objects/Board.hpp
	g++ -c src/objects/Board.cpp -o build/Board.o

build/Player.o: include/resources/Constants.h build src/objects/Player.cpp include/objects/Player.hpp
	g++ -c src/objects/Player.cpp -o build/Player.o


build/Tools.o: include/resources/Constants.h build src/resources/Tools.cpp include/resources/Tools.hpp
	g++ -c src/resources/Tools.cpp -o build/Tools.o

build/BlandTools.o: include/resources/Constants.h build src/resources/BlandTools.cpp include/resources/BlandTools.hpp
	g++ -c src/resources/BlandTools.cpp -o build/BlandTools.o


build:
	mkdir build
	mkdir bin


BuildClean: Chess clean
	@echo "🔧 Configuring..."
ifeq ($(OS),Windows_NT)
	@exec=Chess.exe
else
	@exec=Chess
endif

run: BuildClean
	@echo "🚀 Executing..."
	@echo ""
	@echo "====================="
	@echo ""
	@./bin/$(exec)

clean:
	@echo "🧹 Cleaning..."
ifeq ($(OS),Windows_NT)
	@echo "Skip over, TEMP"
else
	rm build/*.o
endif

