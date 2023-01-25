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
    new_node->height = 1;

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

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

int getBalanceFactor(BSTNode* node) {
    if (node == NULL)
        return 0;
    
    return getHeight(node->left) - getHeight(node->right);
}

BSTNode* insertKey(BSTNode* root, int key) {
    // normal BST Node insertion steps
    if (root == NULL) {
        root = createNode(key);
    }
    
    if (key < root->key) {
        root->left = insertKey(root->left, key);
    } else if (key > root->key) {
        root->right = insertKey(root->right, key);
    } else {
        cout << "\nCannot enter duplicate key!" << endl;
        return root;
    }

    // update height of ancestor node
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;

    // get the balance factor of ancestor node
    int bf = getBalanceFactor(root);

    // insertion cases
    if (bf > 1) {
        // LL case
        if (key < root->left->key) {
            return rightRotate(root);
        } 
        // LR case
        else if (key > root->left->key) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
    } else if (bf < -1) {
        // RR case
        if (key > root->right->key) {
            return leftRotate(root);
        } 
        // RL case
        else if (key < root->right->key) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
    }

    return root;
}

// functions related to deletion
bool isLeaf(BSTNode* node) {
    if (node->right == NULL && node->left == NULL) {
        return true;
    }

    return false;
}

BSTNode* minValueNode(BSTNode* node) {
    BSTNode* current = node;

    while (current && current->left != NULL) {
        current = current->left;
    }

    return current;
}

BSTNode* deleteKey(BSTNode* root, int key) {
    // normal BST Node deletion steps
    if (root == NULL) {
        return root;
    } 
    
    if (key < root->key) {
        root->left = deleteKey(root->left, key);
    } else if (key > root->key) {
        root->right = deleteKey(root->right, key);
    } else {
        // if node is a leaf node
        if (isLeaf(root)) {
            return NULL;
        }

        // if node has one child
        if (root->left == NULL) {
            BSTNode* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            BSTNode* temp = root->left;
            free(root);
            return temp;
        }
        // if node has two child
        else {
            BSTNode* temp = minValueNode(root->right);

            root->key = temp->key;
            root->right = deleteKey(root->right, temp->key);
        }
    }

    if (root == NULL) {
        return root;
    }

    // update height of ancestor node
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;

    // get the balance factor of ancestor node
    int bf = getBalanceFactor(root);
    
    // deletion cases
    if (bf > 1) {
        // LL case
        if (getBalanceFactor(root->left) >= 0) {
            return rightRotate(root);
        }
        // LR case 
        else if (getBalanceFactor(root->left) < 0) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
    } else if (bf < -1) {
        // RR case
        if (getBalanceFactor(root->right) <= 0) {
            return leftRotate(root);
        }
        // RL case
        else if (getBalanceFactor(root->right) > 0) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
    }

    return root;
}
// delete functions end

// functions related to printing
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
// printing functions end

int main() {
    BSTNode* root = NULL;

    int i = 0;
    while (i != 4) {
        cout << "\nWhat operation do you want to perform?\n1. Create a AVL tree\n2. Insert a element\n3. Delete a element\n4. Exit\nChoice: ";
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
                cout << "\nEnter the element to be inserted: ";
                cin >> ele;

                root = insertKey(root, ele);
                printTree(root);

                break;

            case 3:
                cout << "\nEnter the element to be deleted: ";
                cin >> ele;

                root = deleteKey(root, ele);
                printTree(root);

                break;
            
            case 4:
                cout << "\nExited successfully";
        }
    }
    
    return 0;
}