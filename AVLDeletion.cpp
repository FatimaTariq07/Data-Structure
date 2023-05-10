#include <iostream>
using namespace std;
class AVL
{
public:
    int data;
    AVL *LeftSide;
    AVL *rightSide;
    int height;
};
int Getheight(AVL *node)
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
int GetMax(int x, int y)
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
    newNode->LeftSide = NULL;
    newNode->rightSide = NULL;
    return newNode;
}
int GetBalance(AVL *node)
{
    if (node == NULL)
    {
        return 0;
    }
    else
    {
        return Getheight(node->LeftSide) - Getheight(node->rightSide);
    }
}
AVL *LeftRotation(AVL *x)
{
    AVL *y = x->rightSide;
    AVL *ychild = y->LeftSide;

    y->LeftSide = x;
    x->rightSide = ychild;
    x->height = GetMax(Getheight(x->LeftSide), Getheight(x->rightSide)) + 1;
    y->height = GetMax(Getheight(y->LeftSide), Getheight(y->rightSide)) + 1;
    return y;
}
AVL *RightRotation(AVL *x)
{
    AVL *y = x->LeftSide;
    AVL *ychild = y->rightSide;

    y->rightSide = x;
    x->LeftSide = ychild;
    x->height = GetMax(Getheight(x->LeftSide), Getheight(x->rightSide)) + 1;
    y->height = GetMax(Getheight(y->LeftSide), Getheight(y->rightSide)) + 1;
    return y;
}
AVL *InsertNode(AVL *node, int element)
{
    if (node == NULL)
    {
        return CreateNode(element);
    }
    if (element > node->data)
    {
        node->rightSide = InsertNode(node->rightSide, element);
    }
    if (element < node->data)
    {
        node->LeftSide = InsertNode(node->LeftSide, element);
    }
    else
        return node;
    node->height = GetMax(Getheight(node->LeftSide), Getheight(node->rightSide)) + 1;
    int bfFactor = GetBalance(node);
    if (bfFactor > 1)
    {
        if (element < node->LeftSide->data)
        {
            return RightRotation(node);
        }
        if (element > node->LeftSide->data)
        {
            node->LeftSide = LeftRotation(node->LeftSide);
            return RightRotation(node);
        }
    }
    if (bfFactor < -1)
    {
        if (element > node->rightSide->data)
        {
            return LeftRotation(node);
        }
        if (element < node->rightSide->data)
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
        PrintAVL(node->LeftSide);
        PrintAVL(node->rightSide);
    }
}
AVL *Predecessor(AVL *node)
{
    while (node && node->rightSide != NULL)
    {
        node = node->LeftSide;
        return node;
    }
}
AVL *Successor(AVL *node)
{
    while (node && node->LeftSide != NULL)
    {
        node = node->rightSide;
        return node;
    }
}
AVL *DeleteNode(AVL *node, int key)
{
    AVL *tempPtr;
    if (node == NULL)
    {
        return NULL;
    }
    if (node->LeftSide == NULL && node->rightSide == NULL)
    {
        node = NULL;
        delete node;
        return NULL;
    }
    if (key < node->data)
    {
        node->LeftSide = DeleteNode(node, key);
    }
    else if (key > node->data)
    {
        node->rightSide = DeleteNode(node, key);
    }
    else
    {
        if (Getheight(node->LeftSide) > Getheight(node->rightSide))
        {
           
            tempPtr = Predecessor(node->LeftSide);
            node->data = tempPtr->data;
            node->LeftSide = DeleteNode(node->LeftSide, tempPtr->data);
        }
        else
        {
             tempPtr = Successor(node->rightSide);
            node->data = tempPtr->data;
            node->rightSide = DeleteNode(node->rightSide, tempPtr->data);
        }
    }
    node->height = GetMax(Getheight(node->LeftSide), Getheight(node->rightSide)) + 1;
    int bfFactor = GetBalance(node);
    if (bfFactor > 1)
    {
        if (key < node->LeftSide->data)
        {
            return RightRotation(node);
        }
        if (key > node->LeftSide->data)
        {
            node->LeftSide = LeftRotation(node->LeftSide);
            return RightRotation(node);
        }
    }
    if (bfFactor < -1)
    {
        if (key > node->rightSide->data)
        {
            return LeftRotation(node);
        }
        if (key < node->rightSide->data)
        {
            node->rightSide = RightRotation(node->rightSide);
            return LeftRotation(node);
        }
    }
    return node;
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
    node = DeleteNode(node, 200);
    cout << endl;
    PrintAVL(node);
}
