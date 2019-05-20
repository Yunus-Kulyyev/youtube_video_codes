#include <iostream>

using namespace std;

struct node
{
    int key;
    node *left = nullptr;
    node *right = nullptr;
};

node *root = NULL;

void insertNode(int key);
void insertNode(int key, node *leaf);

node *searchKey(int key);
node *searchKey(int key, node *leaf);

void destroyTree();
void destroyTree(node *leaf);

int main()
{
    insertNode(500);
    insertNode(100);
    insertNode(200);
    insertNode(300);
    insertNode(600);
    insertNode(700);
    insertNode(800);

    searchKey(800);
    searchKey(100);
    searchKey(200);
    searchKey(1000);

    destroyTree();
}

void destroyTree(node *leaf)
{
    if(leaf != nullptr)
    {
        destroyTree(leaf->left);
        destroyTree(leaf->right);
        delete root;
    }
}

void destroyTree()
{
    destroyTree(root);
}

node *searchKey(int key, node *leaf)
{
    if(leaf != nullptr)
    {
        cout << leaf->key << " | ";
        if(leaf->key == key)
        {
            cout << "FOUND" << endl;
        }
        else if(key < leaf->key)
        {
            return searchKey(key, leaf->left);
        }
        else if(key > leaf->key)
        {
            return searchKey(key, leaf->right);
        }
    }
    else
    {
        cout << "NOT FOUND" << endl;
        return NULL;
    }
}

node *searchKey(int key)
{
    if(root != NULL)
    {
        searchKey(key, root);
    }
    else
    {
        return NULL;
    }
}


void insertNode(int key, node *leaf)
{
    if(key < leaf->key)
    {
        if(leaf->left != nullptr)
        {
            insertNode(key, leaf->left);
        }
        else
        {
            leaf->left = new node;
            leaf->left->key = key;
            leaf->left->left = nullptr;
            leaf->left->right = nullptr;
        }
    }
    else if(key > leaf->key)
    {
        if(leaf->right != nullptr)
        {
            insertNode(key, leaf->right);
        }
        else
        {
            leaf->right = new node;
            leaf->right->key = key;
            leaf->right->right = nullptr;
            leaf->right->left = nullptr;
        }
    }
}

void insertNode(int key)
{
    if(root == NULL)
    {
        root = new node;
        root->key = key;
        root->left = nullptr;
        root->right = nullptr;
    }
    else
    {
        insertNode(key, root);
    }
}
