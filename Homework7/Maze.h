#pragma once
#include "MCell.h"
class Maze
{
private:
	int horizontal_size = 1;
	MCell *m_field;
public:
	Maze(int n, int m);
	~Maze();
	const MCell& cell(int i, int j) const;
	bool hasConnection(int i1, int j1, int i2, int j2);
	bool makeConnection(int i1, int j1, int i2, int j2);
	bool removeConnection(int i1, int j1, int i2, int j2);
	void  printMaze();
};

