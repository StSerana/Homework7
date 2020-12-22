#include "MTreeNode.h"
#include "Maze.h"
#include <queue>

MTreeNode::MTreeNode() {

}
MTreeNode::MTreeNode(MTreeNode* parent)
{
    m_parent = parent;
    m_distance = parent == nullptr ? 0 : parent->m_distance + 1;
}

MTreeNode::~MTreeNode()
{
    for (int i = 0; i < m_child_count; i++) {
        delete (m_children + i);
    }
}

const MTreeNode* MTreeNode::child(int i) const
{
    const MTreeNode* m = m_children[i];
    return m;
}

bool MTreeNode::addChild(int i, int j)
{
    MTreeNode* m = new MTreeNode(this);
    m->m_i = i;
    m->m_j = j;
    this->m_children[this->childCount()] = m;
    this->m_child_count++;
    return true;
}

MTreeNode* MTreeNode::hasChild(int i, int j)
{
    for (int t = 0; t < childCount(); t++) {
        MTreeNode *child = m_children[t];
        if (child->m_i == i && child->m_j == j)
            return child;
    }
    return nullptr;
}

MTreeNode* MTreeNode::beginTree(int i, int j)
{
    MTreeNode* tree = new MTreeNode(nullptr);
    tree->m_i = i;
    tree->m_j = j;
    tree->m_child_count = 0;
    return tree;
}
MTreeNode* MTreeNode::searchNode(const int i, const int j) const
{
    std::queue<const MTreeNode*> nodes;
    nodes.push(this);
    while (!nodes.empty())
    {
        const MTreeNode* node = nodes.front();
        nodes.pop();
        if (node->m_i == i && node->m_j == j)
            return (MTreeNode*)node;
        for (int i = 0; i < node->m_child_count; i++)
            nodes.push(node->m_children[i]);
    }
    return nullptr;
}
