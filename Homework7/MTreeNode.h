#pragma once
#include "Maze.h"

class MTreeNode
{
private:
	MTreeNode(MTreeNode* parent);
	MTreeNode();
	~MTreeNode();
	int m_i = 0; 
	int m_j = 0;
	MTreeNode* m_parent;
	MTreeNode* m_children[4];
	int m_distance = 0;
	int m_child_count = 0;
public:
	int i() const { return m_i; }
	int j() const { return m_j; }
	const MTreeNode* parent() const { return m_parent; };
	const MTreeNode* child(int i) const;
	int distance() const { return m_distance; };
	int childCount() const { return m_child_count; };
	bool addChild(int i, int j);
	MTreeNode* hasChild(int i, int j);
	static MTreeNode* beginTree(int i, int j);
};

