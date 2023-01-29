#include<iostream>
using namespace std;

const bool RED = false;
const bool BLACK = true;

struct RBTNode* root = NULL;

// color = false(red) & = true(black)
struct RBTNode {
    int key;
    RBTNode *left, *right, *parent;
    bool color;
};

RBTNode* createNode(int data) {
    RBTNode* new_node = new RBTNode;

    new_node->key = data;
    new_node->left = new_node->right = new_node->parent = NULL;
    new_node->color = RED;

    return new_node;
}

void replaceParentsChild(RBTNode* parent, RBTNode* oldChild, RBTNode* newChild) {
    if (parent == NULL) {
        root = newChild;
    } else if (parent->left == oldChild) {
        parent->left = newChild;
    } else if (parent->right == oldChild) {
        parent->right = newChild;
    }

    if (newChild != NULL) {
        newChild->parent = parent;
    }
}

void rightRotate(RBTNode* node) {
    RBTNode* parent = node->parent;
    RBTNode* leftChild = node->left;

    node->left = leftChild->right;
    if (leftChild->right != NULL) {
        leftChild->right->parent = node;
    }

    leftChild->right = node;
    node->parent = leftChild;

    replaceParentsChild(parent, node, leftChild);
}

void leftRotate(RBTNode* node) {
    RBTNode* parent = node->parent;
    RBTNode* rightChild = node->right;

    node->right = rightChild->left;
    if (rightChild->left != NULL) {
        rightChild->left->parent = node;
    }

    rightChild->left = node;
    node->parent = rightChild;

    replaceParentsChild(parent, node, rightChild);
}

RBTNode* getUncle(RBTNode* parent) {
    RBTNode* grandparent = parent->parent;

    if (parent == grandparent->left) {
        return grandparent->right;
    } else {
        return grandparent->left;
    }
}

void fixViolations(RBTNode* node) {
    RBTNode* parent = node->parent;

    // Case 1: Parent is null, we've reached the root, the end of the recursion
    if (parent == NULL) {
        node->color = BLACK;
        return;
    }

    // Parent is black --> nothing to do
    if (parent->color == BLACK) {
        return;
    }


    // From here on, parent is red
    RBTNode* grandparent = parent->parent;

    // Get the uncle (may be null, in which case its color is BLACK)
    RBTNode* uncle = getUncle(parent);

    // Case 2: Uncle is red -> recolor parent, grandparent and uncle
    if (uncle != NULL && uncle->color == RED) {
        parent->color = BLACK;
        grandparent->color = RED;
        uncle->color = BLACK;

        // Call recursively for grandparent, which is now red.
        // It might be root or have a red parent, in which case we need to fix more...
        fixViolations(grandparent);
    }

    // Parent is left child of grandparent
    else if (parent == grandparent->left) {
        // Case 3a: Uncle is black and node is left->right "inner child" of its grandparent
        if (node == parent->right) {
            leftRotate(parent);

            // Let "parent" point to the new root node of the rotated sub-tree
            parent = node;
        }

        // Case 4a: Uncle is black and node is left->left "outer child" of its grandparent
        rightRotate(grandparent);

        // Recolor original parent and grandparent
        parent->color = BLACK;
        grandparent->color = RED;
    }

    // Parent is right child of grandparent
    else {
        // Case 3b: Uncle is black and node is right->left "inner child" of its grandparent
        if (node == parent->left) {
            rightRotate(parent);

        // Let "parent" point to the new root node of the rotated sub-tree
            parent = node;
        }

        // Case 4b: Uncle is black and node is right->right "outer child" of its grandparent
        leftRotate(grandparent);

        // Recolor original parent and grandparent
        parent->color = BLACK;
        grandparent->color = RED;
    }
}

void insertKey(int key) {
    RBTNode* node = root;
    RBTNode* parent = NULL;

    // Traverse the tree to the left or right depending on the key while keeping track of parent
    while (node != NULL) {
        parent = node;

        if (key < node->key) {
            node = node->left;
        } else if (key > node->key) {
            node = node->right;
        } else {
            cout << "\nCannot enter duplicate key!" << endl;
            return;
        }
    }

    // insert new node
    RBTNode* newNode = createNode(key);

    if (parent == NULL) {
        root = newNode;
    } else if (key < parent->key) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }
    newNode->parent = parent;

    fixViolations(newNode);
}

// functions related to printing
void printTree(const string& prefix, const RBTNode* node, bool isLeft, bool isRoot) {
    if (node != nullptr) {
        if (isRoot) {
            cout << "--->";
        } else {
            cout << prefix << (isLeft ? "R-->" : "L-->");
        }

        cout << node->key  << "(" << node->color << ")" << endl;

        printTree(prefix + (isLeft ? "|   " : "       "), node->right, true, false);
        printTree(prefix + (isLeft ? "|   " : "       "), node->left, false, false);
    }
}

void printTree() {
    printTree("", root, false, true);
}
// printing functions end

int main() {
    int i = 0;
    while (i != 4) {
        cout << "\nWhat operation do you want to perform?\n1. Create a red black tree\n2. Insert a element\n3. Delete a element\n4. Exit\nChoice: ";
        cin >> i;

        switch(i) {
            case 1:
                int ele;
                cout << "\nEnter root element: ";
                cin >> ele;

                insertKey(ele);
                printTree();

                break;

            case 2:
                cout << "\nEnter element to be inserted: ";
                cin >> ele;
                
                insertKey(ele);
                printTree();

                break;

            case 4:
                cout << "\nExited successfully";
        }
    }
    
    return 0;
}