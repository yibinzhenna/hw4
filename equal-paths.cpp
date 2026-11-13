#ifndef RECCHECK
//if you want to add any #includes like <iostream> you must do them here (before the next endif)

#endif

#include "equal-paths.h"
using namespace std;


// You may add any prototypes of helper functions here

int leafDepth(Node* node);

int leafDepth(Node* node)
{
    if (node == nullptr) return 0;

    // Leaf node
    if (node->left == nullptr && node->right == nullptr) return 1;

    // Only one child: only that side's paths matter
    if (node->left == nullptr) {
        int r = leafDepth(node->right);
        return (r == -1) ? -1 : r + 1;
    }
    if (node->right == nullptr) {
        int l = leafDepth(node->left);
        return (l == -1) ? -1 : l + 1;
    }

    // Two children: both sides must be valid and equal
    int l = leafDepth(node->left);
    int r = leafDepth(node->right);
    if (l == -1 || r == -1 || l != r) return -1;
    return l + 1;
}

bool equalPaths(Node * root)
{
    // Add your code below
  return leafDepth(root) != -1;
}

