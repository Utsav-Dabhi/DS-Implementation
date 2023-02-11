#include<iostream>
using namespace std;

const bool RED = false;
const bool BLACK = true;

struct RBTNode* root = NULL;

// color = false(red) & = true(black)
class RBTNode {
    public:
        int key;
        RBTNode *left, *right, *parent;
        bool color;

        RBTNode(int key) {
            this->key = key;
            this->left = this->right = this->parent = NULL;
            this->color = RED;
        }
};

class NilNode: public RBTNode {
    public:
        NilNode(): RBTNode(-999) {
            this->color = BLACK;
        }
};

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

void fixViolationsAfterInsert(RBTNode* node) {
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
        fixViolationsAfterInsert(grandparent);
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
    RBTNode* newNode = new RBTNode(key);

    if (parent == NULL) {
        root = newNode;
    } else if (key < parent->key) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }
    newNode->parent = parent;

    fixViolationsAfterInsert(newNode);
}

RBTNode* deleteNodeWithZeroOrOneChild(RBTNode* node) {
    // if node has only a left child -> replace with left child
    if (node->left != NULL) {
        replaceParentsChild(node->parent, node, node->left);
        return node->left; // moved-up node
    }
    // if node has only a right child -> replace with right child
    else if (node->right != NULL) {
        replaceParentsChild(node->parent, node, node->right);
        return node->right; // moved-up node
    }

    // if node has no children -->
    // * node is red -> just remove it
    // * node is black -> replace it by a temporary NIL node (needed to fix the R-B rules)
    else {
        RBTNode* newChild = node->color == BLACK ? new NilNode() : NULL;
        replaceParentsChild(node->parent, node, newChild);
        return newChild;
    }
}

RBTNode* findMinimum(RBTNode* node) {
    RBTNode* current = node;

    while (current && current->left != NULL) {
        current = current->left;
    }

    return current;
}

RBTNode* getSibling(RBTNode* node) {
    RBTNode* parent = node->parent;

    if (parent->left == node) {
        return parent->right;
    } else if (parent->right == node) {
        return parent->left;
    } else {
        return NULL;
    }
}

void handleRedSibling(RBTNode* node, RBTNode* sibling) {
    // recolor ..
    sibling->color = BLACK;
    node->parent->color = RED;

    // .. and rotate
    if (node->parent->left == node) {
        leftRotate(node->parent);
    } else {
        rightRotate(node->parent);
    }
}

bool isBlack(RBTNode* node) {
    return node == NULL || node->color == BLACK;
}

void handleBlackSiblingWithAtLeastOneRedChild(RBTNode* node, RBTNode* sibling) {
    bool nodeIsLeftChild = node == node->parent->left;

    // Case 5: Black sibling with at least one red child + "outer nephew" is black
    // --> Recolor sibling and its child, and rotate around sibling
    if (nodeIsLeftChild && isBlack(sibling->right)) {
        sibling->left->color = BLACK;
        sibling->color = RED;
        rightRotate(sibling);
        sibling = node->parent->right;
    } else if (!nodeIsLeftChild && isBlack(sibling->left)) {
        sibling->right->color = BLACK;
        sibling->color = RED;
        leftRotate(sibling);
        sibling = node->parent->left;
    }

    // Fall-through to case 6...

    // Case 6: Black sibling with at least one red child + "outer nephew" is red
    // --> Recolor sibling + parent + sibling's child, and rotate around parent
    sibling->color = node->parent->color;
    node->parent->color = BLACK;
    if (nodeIsLeftChild) {
        sibling->right->color = BLACK;
        leftRotate(node->parent);
    } else {
        sibling->left->color = BLACK;
        rightRotate(node->parent);
    }
}

void fixViolationsAfterDelete(RBTNode* node) {
    // Case 1: Examined node is root, end of recursion
    if (node == root) {
        node->color = BLACK; // enforcing black roots
        return;
    }

    RBTNode* sibling = getSibling(node);

    // Case 2: Red sibling
    if (sibling->color == RED) {
        handleRedSibling(node, sibling);
        sibling = getSibling(node); // Get new sibling for fall-through to cases 3-6
    }

    // Cases 3+4: Black sibling with two black children
    if (isBlack(sibling->left) && isBlack(sibling->right)) {
        sibling->color = RED;

        // Case 3: Black sibling with two black children + red parent
        if (node->parent->color == RED) {
            node->parent->color = BLACK;
        }

        // Case 4: Black sibling with two black children + black parent
        else {
            fixViolationsAfterDelete(node->parent);
        }
    }

    // Case 5+6: Black sibling with at least one red child
    else {
        handleBlackSiblingWithAtLeastOneRedChild(node, sibling);
    }
}

void deleteKey(int key) {
    RBTNode* node = root;

    // Find the node to be deleted
    while (node != NULL && node->key != key) {
        // Traverse the tree to the left or right depending on the key
        if (key < node->key) {
            node = node->left;
        } else {
            node = node->right;
        }
    }

    // node not found?
    if (node == NULL) {
        return;
    }

    // In this variable, we'll store the node at which we're going to start to fix the R-B 
    // properties after deleting a node.
    RBTNode* movedUpNode;
    bool deletedNodeColor;

    // if node has zero or one child
    if (node->left == NULL || node->right == NULL) {
        movedUpNode = deleteNodeWithZeroOrOneChild(node);
        deletedNodeColor = node->color;
    }

    // if node has two children
    else {
        // Find minimum node of right subtree ("inorder successor" of current node)
        RBTNode* inorderSuccessor = findMinimum(node->right);

        // Copy inorder successor's data to current node (keep its color!)
        node->key = inorderSuccessor->key;

        // Delete inorder successor just as we would delete a node with 0 or 1 child
        movedUpNode = deleteNodeWithZeroOrOneChild(inorderSuccessor);
        deletedNodeColor = inorderSuccessor->color;
    }

    if (deletedNodeColor == BLACK) {
        fixViolationsAfterDelete(movedUpNode);

        // Remove the temporary NIL node
        if (typeid(*movedUpNode) == typeid(NilNode)) {
            replaceParentsChild(movedUpNode->parent, movedUpNode, NULL);
        }
    }
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

            case 3:
                cout << "\nEnter element to be deleted: ";
                cin >> ele;
                
                deleteKey(ele);
                printTree();

                break;

            case 4:
                cout << "\nExited successfully";
        }
    }
    
    return 0;
}