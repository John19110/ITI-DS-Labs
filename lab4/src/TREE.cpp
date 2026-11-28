
#include "Tree.h"


NodeTree::NodeTree(int data)
{
    this->data = data;
    left = NULL;
    right = NULL;
}

Tree::Tree()
{
    root = NULL;
}

Tree::~Tree()
{
    clear(root);
}

NodeTree* Tree::getNodeByData(int data)
{
    NodeTree* current = root;

    while (current != NULL)
    {
        if (data == current->data)
            return current;

        else if (data < current->data)
            current = current->left;

        else
            current = current->right;
    }

    return NULL;
}

NodeTree* Tree::getParent(int data)
{
    NodeTree* current = root;
    NodeTree* parent = NULL;

    while (current != NULL && current->data != data)
    {
        parent = current;

        if (data < current->data)
            current = current->left;
        else
            current = current->right;
    }

    return current == NULL ? NULL : parent;
}

void Tree::displayLDR(NodeTree* current)
{
    if (current == NULL)
        return;

    displayLDR(current->left);

    cout << current->data << " ";

    displayLDR(current->right);
}

int Tree::maxDepthDFS(NodeTree* current)
{
    if (current == NULL)
        return 0;

    int leftHeight = maxDepthDFS(current->left);
    int rightHeight = maxDepthDFS(current->right);

    return 1 + max(leftHeight, rightHeight);
}

void Tree::clear(NodeTree* current)
{
    if (current == NULL)
        return;

    clear(current->left);
    clear(current->right);

    delete current;
}


void Tree::add(int data)
{
    NodeTree* newNode = new NodeTree(data);

    if (root == NULL)
    {
        root = newNode;
        return;
    }

    NodeTree* current = root;
    NodeTree* parent = NULL;

    while (current != NULL)
    {
        parent = current;

        if (data < current->data)
            current = current->left;

        else if (data > current->data)
            current = current->right;

        else
        {
            delete newNode;
            return;
        }
    }

    if (data < parent->data)
        parent->left = newNode;
    else
        parent->right = newNode;
}

bool Tree::getNodeData(int data)
{
    return getNodeByData(data) != NULL;
}

int Tree::getParentData(int data)
{
    NodeTree* parent = getParent(data);

    if (parent == NULL)
        return -1;

    return parent->data;
}

NodeTree* Tree::maxRight(int data)
{
    NodeTree* current = getNodeByData(data);

    if (current == NULL)
        return NULL;

    while (current->right != NULL)
        current = current->right;

    return current;
}

int Tree::maxRightData(int data)
{
    NodeTree* current = maxRight(data);

    if (current == NULL)
        return -1;

    return current->data;
}


void Tree::removeNode(int data)
{
    NodeTree** link = &root;

    while (*link != NULL && (*link)->data != data)
    {
        if (data < (*link)->data)
            link = &((*link)->left);
        else
            link = &((*link)->right);
    }

    if (*link == NULL)
        return;

    NodeTree* current = *link;

    if (current->left == NULL)
    {
        *link = current->right;
    }

    else if (current->right == NULL)
    {
        *link = current->left;
    }

    else
    {
        NodeTree** predecessorLink = &(current->left);

        while ((*predecessorLink)->right != NULL)
        {
            predecessorLink = &((*predecessorLink)->right);
        }

        NodeTree* predecessor = *predecessorLink;

        *predecessorLink = predecessor->left;

        predecessor->left = current->left;
        predecessor->right = current->right;

        *link = predecessor;
    }

    delete current;
}



void Tree::displayLDR()
{
    displayLDR(root);
    cout << endl;
}


int Tree::maxDepthDFS()
{
    return maxDepthDFS(root);
}


int Tree::maxDepthBFS()
{
    if (root == NULL)
        return 0;

    queue<NodeTree*> q;

    q.push(root);

    int height = 0;

    while (!q.empty())
    {
        int levelSize = q.size();

        for (int i = 0; i < levelSize; i++)
        {
            NodeTree* current = q.front();

            q.pop();

            if (current->left != NULL)
                q.push(current->left);

            if (current->right != NULL)
                q.push(current->right);
        }

        height++;
    }

    return height;
}
