#include <iostream>
#include "Maze.h"
#include "MCell.h"
#include <ctime>
#include <ctime>
#include "MTreeNode.h"
#include <queue>
using namespace std;

Maze* createMaze(Maze* maze);
void buildFullMaze(Maze& iMaze, MTreeNode& tree);


int main()
{
	const int n = 50;
	const int m = 50;
	int weights[n][m];
	Maze* maze = new Maze(n, m);
	//maze = createMaze(maze);
	weights[maze->startX()][maze->startY()] = 0;
	MTreeNode* tree = MTreeNode::beginTree(maze->startX(), maze->startY());
	buildFullMaze(*maze, *tree);
	maze->printMaze();
	cout << endl;
	return 0;
}

Maze* createMaze(Maze* maze) {
	/* //Homework 8
	int i = 0;
	int j = 1;
	while (i * j < 5 * 5 && i + 1 <= 5 && j + 1 <= 5) {
		maze->makeConnection(i, j, i + 1, j);
		i++;
		maze->makeConnection(i, j, i, j + 1);
		j++;
	}
	return maze;
	*/
	 //Homework 9
	for (int i = 0; i < maze->rows(); i++)
	{
		for (int j = 0; j <maze->columns() - 1 - i; j++)
		{
			maze->makeConnection(i, i + j, i, i + j + 1);
			maze->makeConnection(i + j, i, i + j + 1, i);
		}
		maze->makeConnection(i, i + 1, i + 1, i + 1);
	}
	return maze;
}

bool isConnected(Maze& iMaze, const int i, const int j)
{
	return iMaze.hasConnection(i, j, i, j + 1)
		|| iMaze.hasConnection(i, j, i, j - 1)
		|| iMaze.hasConnection(i, j, i + 1, j)
		|| iMaze.hasConnection(i, j, i - 1, j);
}

void shuffle(std::pair<int, int>* steps, const int size)
{
	srand(time(0));
	for (int i = 0; i < size; i++)
	{
		int n = rand() % size;
		if (i != n)
			std::swap(steps[i], steps[n]);
	}
}

void buildFullMaze(Maze& iMaze, MTreeNode& tree)
{
	queue<MTreeNode*> nodes;
	std::pair<int, int> possibleDirections[4] = { std::pair<int,int> { 0, -1 },
													std::pair<int,int> { 0, 1 },
													std::pair<int,int> { -1, 0 },
													std::pair<int,int> { 1, 0 } };
	srand(time(0));
	nodes.push(&tree);
	bool canConnect = true;
	bool wasConnected = false;
	while (!nodes.empty()) {
		MTreeNode& node = *nodes.front();
		nodes.pop();
		while (!wasConnected && canConnect)
		{
			canConnect = false;
			for (pair<int, int> p : possibleDirections) {
				if (node.i() < 0 || node.i() > iMaze.columns() - 1 || node.i() + p.first < 0 || node.i() + p.first > iMaze.columns() - 1 ||
					node.j() < 0 || node.j() > iMaze.rows() - 1 || node.j() + p.second < 0 || node.j() + p.second >  iMaze.rows() - 1
					|| isConnected(iMaze, p.first, p.second))
					continue;
				canConnect = true;
				if (rand() % 5 == 0)
				{
					iMaze.makeConnection(node.i(), node.j(), p.first, p.second);
					node.addChild(p.first, p.second);
					nodes.push(node.hasChild(p.first, p.second));
					wasConnected = true;
				}
			}
		}
	}
	bool wasDisconnected = true;
	while (wasDisconnected) // adding points that were not added during the main generation
	{
		wasDisconnected = false;
		for (int i = 0; i < iMaze.rows(); i++)
			for (int j = 0; j < iMaze.columns(); j++)
			{
				if (isConnected(iMaze, i, j))
					continue;
				wasDisconnected = true;
				shuffle(possibleDirections, 4);
				for (int k = 0; k < 4; k++)
					if (isConnected(iMaze, i + possibleDirections[k].first, j + possibleDirections[k].second))
					{
						iMaze.makeConnection(i, j, i + possibleDirections[k].first, j + possibleDirections[k].second);
						tree.searchNode(i + possibleDirections[k].first, j + possibleDirections[k].second)->addChild(i, j);
						break;
					}
			}
	}
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
