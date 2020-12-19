#include <iostream>
#include <ctime>
#include "Maze.h"
#include "MCell.h"
#include "MTreeNode.h"
using namespace std;

Maze* createMaze(Maze* maze);
void addWeights(MTreeNode* node, Maze& maze, int weights[5][5]);
void  printWeights(int weights[5][5]);

int main()
{
	srand(time(0));
	int weights[5][5];
	Maze* maze = new Maze(5, 5);
	weights[0][0] = 0;
	maze = createMaze(maze);
	MTreeNode* tree = MTreeNode::beginTree(0, 0);
	addWeights(tree, *maze, weights);
	maze->printMaze();
	cout << endl;
	printWeights(weights);
	return 0;
}

Maze* createMaze(Maze* maze) {
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5 - 1 - i; j++)
		{
			maze->makeConnection(i, i + j, i, i + j + 1);
			maze->makeConnection(i + j, i, i + j + 1, i);
		}
		maze->makeConnection(i, i + 1, i + 1, i + 1);
	}
	return maze;
}

void addWeights(MTreeNode* node, Maze& maze, int weights[5][5])
{
	int i = node->i();
	int j = node->j();
	MCell cell = maze.cell(i, j);
	if (cell.down())
	{
		node->addChild(i + 1, j);
		weights[i + 1][j] = node->distance() + 1;
		addWeights(node->hasChild(i + 1, j), maze, weights);
	}
	if (cell.right())
	{
		node->addChild(i, j + 1);
		weights[i][j + 1] = node->distance() + 1;
		addWeights(node->hasChild(i, j + 1), maze, weights);
	}
}

void  printWeights(int weights[5][5])
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << weights[i][j];
		}
		cout << endl;
	}
}
