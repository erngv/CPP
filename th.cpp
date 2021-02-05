/*
 * This program finds the height of any given binary tree
 * based on the root node.
 */

#include <bits/stdc++.h>
using namespace std;

struct node
{
    int key;
    struct node *left;
    struct node *right;
};

struct node *make_node(int key)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->key = key;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

int height(struct node *node)
{
    if (!node) return 0;

    int left_height = height(node->left);
    int right_height = height(node->right);

    if (left_height < right_height) return right_height + 1;
    else return left_height + 1;
}

int main()
{
    struct node *root = make_node(10);
    root->left = make_node(8);
    root->right = make_node(16);
    root->left->left = make_node(7);
    root->left->right = make_node(9);
    root->right->left = make_node(14);
    cout << "Height up to this line --> " << height(root) << endl; // returns 3

    root->left->left->left = make_node(4);
    cout << "Height up to this line --> " << height(root) << endl; // returns 4

    root->left->left->left->left = make_node(1);
    root->left->left->left->right = make_node(3);
    cout << "Height up to this line --> " << height(root) << endl; // returns 5

    return 0;
}
