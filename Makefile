all:
	g++ -I src/include -L src/lib -o main main.cpp Baseobject.cpp CommonFunc.cpp game_map.cpp MainObject.cpp ImpTimer.cpp-lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf 
	./main

