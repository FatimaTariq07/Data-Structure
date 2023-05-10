#include <iostream>
using namespace std;
struct AVL
{
    int data;
    AVL *leftSide;
    AVL *rightSide;
    int height;
};
int height(AVL *node)
{
    if (node == NULL)
    {
        return 0;
    }
    else
    {
        return node->height;
    }
}
int max(int x, int y)
{
    if (x > y)
    {
        return x;
    }
    else
    {
        return y;
    }
}
AVL *CreateNode(int element)
{
    AVL *newNode = new AVL();
    newNode->data = element;
    newNode->leftSide = NULL;
    newNode->rightSide = NULL;
    newNode->height = 1;
    return newNode;
}
int GetBalanceFactor(AVL *node)
{
    if (node == NULL)
    {
        return 0;
    }
    else
    {
        return height(node->leftSide) - height(node->rightSide);
    }
}
AVL *RightRotation(AVL *y)
{
    AVL *x = y->leftSide;
    AVL *xrChild = x->rightSide;

    x->rightSide = y;
    y->leftSide = xrChild;

    y->height = max(height(y->leftSide), height(y->rightSide)) + 1;
    x->height = max(height(x->leftSide), height(x->rightSide)) + 1;
    return x;
}
AVL *LeftRotation(AVL *x)
{
    AVL *y = x->rightSide;
    AVL *ychild = y->leftSide;

    y->leftSide = x;
    x->rightSide = ychild;
    y->height = max(height(y->leftSide), height(y->rightSide)) + 1;
    x->height = max(height(x->leftSide), height(x->rightSide)) + 1;
    return y;
}
AVL *InsertNode(AVL *node, int element)
{
    if (node == NULL)
    {
        return CreateNode(element);
    }
    if (element < node->data)
    {
        node->leftSide = InsertNode(node->leftSide, element);
    }
    else if (element > node->data)
    {
        node->rightSide = InsertNode(node->rightSide, element);
    }
    else
        return node;
    node->height = max(height(node->leftSide), height(node->rightSide)) + 1;
    int bFactor = GetBalanceFactor(node);
    if (bFactor > 1)
    {
        if (element < node->leftSide->data)
        {
            return RightRotation(node);
        }
        else if (element > node->rightSide->data)
        {
            node->leftSide = LeftRotation(node->leftSide);
            return RightRotation(node);
        }
    }
    if (bFactor < -1)
    {
        if (element > node->rightSide->data)
        {
            return LeftRotation(node);
        }
        else if (element < node->rightSide->data)
        {
            node->rightSide = RightRotation(node->rightSide);
            return LeftRotation(node);
        }
    }
    return node;
}
void PrintAVL(AVL *node)
{
    if (node != NULL)
    {
        cout << node->data << " ";
        PrintAVL(node->leftSide);
        PrintAVL(node->rightSide);
    }
}
int main()
{
    AVL *node = NULL;
    node = InsertNode(node, 10);
    node = InsertNode(node, 100);
    node = InsertNode(node, 20);
    node = InsertNode(node, 90);
    node = InsertNode(node, 110);
    node = InsertNode(node, 200);
    node = InsertNode(node, 104);
    node = InsertNode(node, 4);
    node = InsertNode(node, 1);
    PrintAVL(node);
}
