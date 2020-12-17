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
	return 0;
}

Maze* createMaze(Maze* maze) {
	int i = 1;
	int j = 0;
	while (i * j < 5 * 5) {
		maze->makeConnection(i, j, i, j + 1);
		j++;
		maze->makeConnection(i, j, i + 1, j);
		i++;
	}
	return maze;
}