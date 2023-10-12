
build:
	g++ -c main.cpp 			-o outputFiles\main.o
	g++ -c screen.cpp 			-o outputFiles\screen.o
	g++ -c entity.cpp 			-o outputFiles\entity.o	        
	g++ -c moveEntity.cpp		-o outputFiles\moveEntity.o
	g++ -c background.cpp		-o outputFiles\background.o
	g++ -c ball.cpp				-o outputFiles\ball.o
	g++ -c paddle.cpp			-o outputFiles\paddle.o
	g++ -c interaction.cpp		-o outputFiles\interaction.o
	g++ -c brick.cpp			-o outputFiles\brick.o
	g++ -c brickGrid.cpp		-o outputFiles\brickGrid.o
	
	@echo "linking"
	g++ outputFiles\\*.o -lmingw32 -lSDL2main -lSDL2	-o a.exe

	a.exe