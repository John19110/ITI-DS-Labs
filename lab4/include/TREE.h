
#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

class NodeTree
{
public:
    int data;
    NodeTree* left;
    NodeTree* right;

    NodeTree(int data);
};

class Tree
{
private:

    NodeTree* root;

    NodeTree* getNodeByData(int data);

    NodeTree* getParent(int data);

    void displayLDR(NodeTree* current);

    int maxDepthDFS(NodeTree* current);

    void clear(NodeTree* current);

public:

    Tree();

    Tree(const Tree&) = delete;
    Tree& operator=(const Tree&) = delete;

    ~Tree();

    void add(int data);

    bool getNodeData(int data);

    int getParentData(int data);

    NodeTree* maxRight(int data);

    int maxRightData(int data);

    void removeNode(int data);

    void displayLDR();

    int maxDepthDFS();

    int maxDepthBFS();
};

#endif
