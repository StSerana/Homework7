#pragma once
#include "MCell.h"
#include <map>

class Maze
{
private:
	int m_rows;
	int m_columns;
	MCell *m_field;
	int start[2];
	Maze();
	static std::map<int, char> symbols;
public:
	Maze(int n, int m);
	~Maze();
	int rows() const;
	int columns() const;
	int startX() const;
	int startY() const;
	const MCell& cell(int i, int j) const;
	bool hasConnection(int i1, int j1, int i2, int j2);
	bool makeConnection(int i1, int j1, int i2, int j2);
	bool removeConnection(int i1, int j1, int i2, int j2);
	void  printMaze();
};

