#include <iostream>

using namespace std;

class Node {
public:
    int data;  //key
    Node* left;
    Node* right;
};


// Binary Search Tree
class BST {
public:
    Node* root;

    // Insertion
    Node* insert(Node* tree, int x);


    // Traversal
    // 1) Infix = LNR, RNL
    // 2) Prefix = NLR, NRL
    // 3) Postfix = LRN, RLN

    void inOrder(Node* tree);
    void preOrder(Node* tree);
    void postOrder(Node* tree);


    // Search
    int search(Node* tree, int x);


    // Max and Min
    int max(Node* tree);
    int min(Node* tree);


    // Deletion
    Node* deleteNode(Node* tree, int x);
};



Node* BST::insert(Node* tree, int x) {
    // if tree is empty
    if (tree == NULL) {
        Node* node = new Node();
        node->left = NULL;
        node->right = NULL;
        node->data = x;
        return node;
    }
    if (tree->data < x)
        tree->right = insert(tree->right, x);
    else
        tree->left = insert(tree->left, x);

    return tree;
}

void BST::inOrder(Node* tree) {
    if (tree == NULL) return;

    inOrder(tree->left); //L
    cout << tree->data << " "; //N
    inOrder(tree->right); //R
}

int BST::search(Node* tree, int x) {
    if (tree == NULL) return -1;

    if (tree->data == x) return 1;

    if (search(tree->right, x) == 1) return 1;

    if (search(tree->left, x) == 1) return 1;

    return -1;
}

int BST::max(Node* tree) {
    while (tree->right != NULL)
    {
        tree = tree->right;
    }
    return tree->data;
}

int BST::min(Node* tree) {
    while (tree->left != NULL)
    {
        tree = tree->left;
    }
    return tree->data;
}


Node* BST::deleteNode(Node* tree, int x) {
    if (tree == NULL) return NULL;

    if (tree->data == x) {
        if (tree->left == NULL && tree->right == NULL) return NULL;

        if (tree->right != NULL) {
            //... code here
            Node* temp = root;
            root = root->right;
            delete temp;
            return tree;
        }
        else {
            //... code here
            Node* temp = root;
            root = root->left;
            delete temp;
            return tree;
        }
    }

    // ya kicikdir, ya da boyukdur
    if (tree->data < x) {
        //... code here
        tree->right = deleteNode(tree->right, x);
    }
    else {
        //... code here
        tree->left = deleteNode(tree->left, x);
    }

    return tree;
}

int main()
{
    BST bst;
    bst.root = NULL; //tree

    bst.root = bst.insert(bst.root, 10);
    bst.root = bst.insert(bst.root, 20);
    bst.root = bst.insert(bst.root, 8);
    bst.root = bst.insert(bst.root, 32);
    bst.root = bst.insert(bst.root, 28);
    bst.root = bst.insert(bst.root, -3);

    bst.inOrder(bst.root);

    //cout << bst.search(bst.root, 32) << endl;

    //cout << "Max: " << bst.max(bst.root) << endl;
    //cout << "Min: " << bst.min(bst.root) << endl;
    
    bst.root = bst.deleteNode(bst.root, 28);
    bst.root = bst.deleteNode(bst.root, 32);
    cout << endl;
    bst.inOrder(bst.root);

    return 0;
}
