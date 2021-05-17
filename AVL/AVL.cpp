#include <iostream>

using namespace std;

struct TreeNode {
    int key;
    TreeNode *left, *right;
    int height;
    TreeNode(int v)
    : key(v), left(nullptr), right(nullptr), height(1) { }
};

void printPreOrder(TreeNode* root) {
    if(!root) return;

    cout << root->key << "(height: " << root->height << ") ";
    printPreOrder(root->left);
    printPreOrder(root->right);
}

int getHeight(TreeNode* root) {
    if(!root) return 0;
    return root->height;
}

int getBalance(TreeNode* root) {
    return getHeight(root->left) - getHeight(root->right);
}

/*
T1, T2 and T3 are subtrees of the tree 
rooted with y (on the left side) or x (on 
the right side)           
     y                               x
    / \     Right Rotation          /  \
   x   T3   - - - - - - - >        T1   y 
  / \       < - - - - - - -            / \
 T1  T2     Left Rotation            T2  T3
Keys in both of the above trees follow the 
following order 
 keys(T1) < key(x) < keys(T2) < key(y) < keys(T3)
So BST property is not violated anywhere.
*/
TreeNode* rightRotate(TreeNode* y) {
    TreeNode* x = y->left;
    y->left = x->right;
    x->right = y;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

TreeNode* leftRotate(TreeNode* x) {
    TreeNode* y = x->right;
    x->right = y->left;
    y->left = x;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}


TreeNode* insert(TreeNode* root, int key) {
    if(root == nullptr) {
        root = new TreeNode(key);
        return root;
    }
    
    if(key == root->key) return root;
    else if(key < root->key) {
        if(root->left)
            root->left = insert(root->left, key);
        else root->left = new TreeNode(key);
    } else if(key > root->key) {
        if(root->right)
            root->right = insert(root->right, key);
        else root->right = new TreeNode(key);
    }

    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
    int balance = getBalance(root);

    // LL
    if(balance > 1 && key < root->left->key) {
        return rightRotate(root);
    }

    // LR
    if(balance > 1 && key > root->left->key) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // RR
    if(balance < -1 && key > root->right->key) {
        return leftRotate(root);
    }

    // RL
    if(balance < -1 && key < root->right->key) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;

}

int main() {
    TreeNode* root = nullptr;

    for(int i: {33, 20, 30, 40, 50, 25}) {
        root = insert(root, i);
        printPreOrder(root);
        cout << endl;
    }

}

