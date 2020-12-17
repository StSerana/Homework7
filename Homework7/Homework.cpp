#include <iostream>
#include <ctime>
#include "Maze.h"
#include "MCell.h"
using namespace std;

Maze* createMaze(Maze* maze); 

int main()
{
	srand(time(0));
	Maze* maze = new Maze(5, 5);
	maze = createMaze(maze);
	maze->printMaze();
	return 0;
}

Maze* createMaze(Maze* maze) {
	int i = 0;
	int j = 1;
	while (i * j < 5 * 5 && i + 1 <= 5 && j + 1 <= 5) {
		maze->makeConnection(i, j, i + 1, j);
		i++;
		maze->makeConnection(i, j, i, j + 1);
		j++;
	}
	return maze;
}