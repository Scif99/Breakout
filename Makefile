# -*- MakeFile -*-

main: main.cpp
	g++ -std=c++2a main.cpp ball.cpp block.cpp game.cpp -o breakout -lsfml-graphics -lsfml-window -lsfml-system


.PHONY : clean # Prevent unnexpected name clashes
clean:
	rm *.o breakout