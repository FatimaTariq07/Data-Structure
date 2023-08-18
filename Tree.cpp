#include <iostream>
using namespace std;
class BST
{
private:
    int data;
    BST *leftNode;
    BST *rightNode;

public:
    BST(int data)
    {
        this->data = data;
        leftNode = NULL;
        rightNode = NULL;
    }
    void Insert(int data)
    {
        if (data > this->data)
        {
            if (rightNode == NULL)
            {
                rightNode = new BST(data);
            }
            else
            {
                rightNode->Insert(data);
            }
        }

        else
        {
            if (leftNode == NULL)
            {
                leftNode = new BST(data);
            }
            else
            {
                leftNode->Insert(data);
            }
        }
    }
    void PrintInorder()
    {
        if (leftNode != NULL)
        {
            leftNode->PrintInorder();
        }
        cout << data << " ";
        if (rightNode != NULL)
        {
            rightNode->PrintInorder();
        }
    }
    void PrintPreorder()
    {
        cout << data << " ";
        if (leftNode != NULL)
        {
            leftNode->PrintPreorder();
        }
        if (rightNode != NULL)
        {
            rightNode->PrintPreorder();
        }
    }
    void PrintPostorder()
    {
        if (leftNode != NULL)
        {
            leftNode->PrintPostorder();
        }
        if (rightNode != NULL)
        {
            rightNode->PrintPostorder();
        }
        cout << data << " ";
    }
    bool SearchNode(BST *node, int key)
    {
        if (node == NULL)
        {
            return false;
        }
        else if (key == node->data)
        {
            return true;
        }
        else if (key < node->data)
        {
            return leftNode->SearchNode(leftNode, key);
        }
        else if (key > node->data)
        {
            return rightNode->SearchNode(rightNode, key);
        }
        else
        {
            cout << "Invalid ";
        }
    }
    int FinMax(BST *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        else if (root->rightNode == NULL)
        {
            return root->data;
        }
        return FinMax(root->rightNode);
    }
    int FindMin(BST *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        else if (root->leftNode == NULL)
        {
            return root->data;
        }
        return FindMin(root->leftNode);
    }
    int Height(BST *node)
    {
        int leftHeight, rightHeight;
        if (node == NULL)
        {
            return 0;
        }
        if (node != NULL)
        {
            leftHeight = Height(node->leftNode);
            rightHeight = Height(node->rightNode);
        }
        if (leftHeight > rightHeight)
        {
            return leftHeight + 1;
        }
        else
        {
            return rightHeight + 1;
        }
    }
    // Deletion
    BST *Predecessor(BST *node)
    {
        while (node && node->rightNode != NULL)
        {
            node = node->rightNode;
            return node;
        }
    }
    BST *Successor(BST *node)
    {
        while (node && node->leftNode != NULL)
        {
            node = node->leftNode;
            return node;
        }
    }
    BST *DeleteNode(BST *node, int key)
    {
        BST *tempPtr;
        if (node == NULL)
        {
            return NULL;
        }
        if (node->leftNode == NULL && node->rightNode == NULL)
        {
            if (key == node->data)
            {
                node = NULL;
                delete node;
                return NULL;
            }
        }
        if (key < node->data)
        {
            node->leftNode = DeleteNode(node->leftNode, key);
        }
        else if (key > node->data)
        {
            node->rightNode = DeleteNode(node->rightNode, key);
        }
        else
        {
            if (Height(node->leftNode) > Height(node->rightNode))
            {
                tempPtr = Predecessor(node->leftNode);
                node->data = tempPtr->data;
                node->leftNode = DeleteNode(node->leftNode, tempPtr->data);
            }
            else
            {
                tempPtr = Successor(node->rightNode);
                node->data = tempPtr->data;
                node->rightNode = DeleteNode(node->rightNode, tempPtr->data);
            }
        }
        return node;
    }
};
int main()
{
    BST obj(100);
    obj.Insert(2);
    obj.Insert(200);
    obj.Insert(20);
    obj.Insert(500);
    obj.Insert(205);
    obj.Insert(1);
    obj.PrintInorder();
    if (obj.SearchNode(&obj, 2))
    {
        cout << "Found ";
    }
    else
    {
        cout << "Not found ";
    }
    cout << endl;
    cout << "Maximum data in tree is " << obj.FinMax(&obj);
    cout << endl;
    cout << "Height of tree is " << obj.Height(&obj);
    obj.DeleteNode(&obj, 200);
    cout << endl;
    obj.PrintInorder();
}