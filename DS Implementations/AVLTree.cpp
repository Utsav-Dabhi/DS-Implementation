#include<iostream>
#include<string>
#include<math.h>
using namespace std;

struct BSTNode {
    int key;
    BSTNode *left, *right;
    int height;
};

int getHeight(BSTNode* node) {
    if (node == NULL)
        return 0;
    
    return node->height;
}

BSTNode* createNode(int data) {
    BSTNode* new_node = new BSTNode;
    new_node->key = data;
    new_node->left = new_node->right = NULL;
    new_node->height = 0;

    return new_node;
}

/*
     y                               x
    / \     Right Rotation          /  \
   x   T3   - - - - - - - >        T1   y 
  / \       < - - - - - - -            / \
 T1  T2     Left Rotation            T2  T3
*/

BSTNode* rightRotate(BSTNode* y) {
    BSTNode* x = y->left;
    BSTNode* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

BSTNode* leftRotate(BSTNode* x) {
    BSTNode* y = x->right;
    BSTNode* T2 = y->left;

    y->left = x;
    x->right = T2;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

int getBalanceFactor(BSTNode* node) {
    if (node == NULL)
        return 0;
    
    return getHeight(node->left) - getHeight(node->right);
}

BSTNode* insertKey(BSTNode* root, int key) {
    if (root == NULL) {
        root = createNode(key);
    } else if (key < root->key) {
        root->left = insertKey(root->left, key);
    } else if (key > root->key) {
        root->right = insertKey(root->right, key);
    } else {
        return root;
    }

    // update height of ancestor node
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;

    int bf = getBalanceFactor(root);

    // insertion cases
    if (bf > 1) {
        if (key < root->left->key) {
            // LL case
            return rightRotate(root);
        } else if (key > root->left->key) {
            // LR case
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
    } else if (bf < -1) {
        if (key > root->right->key) {
            // RR case
            return leftRotate(root);
        } else if (key < root->right->key) {
            // RL case
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
    }

    return root;
}

void printTree(const string& prefix, const BSTNode* node, bool isLeft, bool isRoot) {
    if (node != nullptr) {
        if (isRoot) {
            cout << "--->";
        } else {
            cout << prefix << (isLeft ? "R-->" : "L-->");
        }

        cout << node->key << endl;

        printTree(prefix + (isLeft ? "|   " : "    "), node->right, true, false);
        printTree(prefix + (isLeft ? "|   " : "    "), node->left, false, false);
    }
}

void printTree(const BSTNode* node) {
    printTree("", node, false, true);
}

int main() {
    BSTNode* root = NULL;

    int i = 0;
    while (i != 3) {
        cout << "\nWhat operation do you want to perform?\n1. Create a AVL tree\n2. Insert a element\n3. Exit\nChoice: ";
        cin >> i;

        switch(i) {
            case 1:
                int ele;
                cout << "\nEnter root element: ";
                cin >> ele;

                root = insertKey(root, ele);
                printTree(root);

                break;

            case 2:
                cout << "\nEnter element to be inserted: ";
                cin >> ele;

                root = insertKey(root, ele);
                printTree(root);

                break;
        }
    }
    
    return 0;
}