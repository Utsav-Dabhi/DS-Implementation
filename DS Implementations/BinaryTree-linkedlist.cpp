#include<iostream>
#include<math.h>
#include<queue>
using namespace std;

struct BTNode {
    int data;
    BTNode* left;
    BTNode* right;

    BTNode(int ele) {
        this->data = ele;
        this->left = NULL;
        this->right = NULL;
    }
};

void preorder(BTNode* node) {
    if (node != NULL) {
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }
}

void postorder(BTNode* node) {
    if (node != NULL) {
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }
}

void inorder(BTNode* node) {
    if (node != NULL) {
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }
}

void bfs(BTNode* node) {
    queue<BTNode> que;

    BTNode curr = *node;
    que.push(curr);

    while (!que.empty()) {
        cout << que.front().data << " ";

        if (que.front().left != NULL) {
            BTNode curr_left = *que.front().left;
            que.push(curr_left);
        }

        if (que.front().right != NULL) {
            BTNode curr_right = *que.front().right;
            que.push(curr_right);
        }

        que.pop();
    }
}

int getHeight(BTNode* node) {
    if (node == NULL) {
        return 0;
    } else {
        int leftHeight = getHeight(node->left);
        int rightHeight = getHeight(node->right);

        return max(leftHeight, rightHeight) + 1;
    }
}

bool isFullBT(BTNode* root) {
    if (root == NULL) {
        return true;
    }

    if (root->left == NULL && root->right == NULL) {
        return true;
    }

    if (root->left && root->right) {
        return (isFullBT(root->left) && isFullBT(root->right));
    }

    return false;
}

int main() {
    /* TREE 1 */
    // level 0
    BTNode* root = new BTNode(1);

    // level 1
    root->left = new BTNode(2);
    root->right = new BTNode(3);

    // level 2
    root->left->left = new BTNode(4);
    root->left->right = new BTNode(5);

    root->right->left = new BTNode(6);
    root->right->right = new BTNode(7);

    // level 3
    root->left->left->left = new BTNode(8);
    root->left->left->right = new BTNode(9);

    root->left->right->left = new BTNode(10);
    root->left->right->right = new BTNode(11);

    root->right->left->left = new BTNode(12);
    root->right->left->right = new BTNode(13);

    root->right->right->left = new BTNode(14);
    root->right->right->right = new BTNode(15);


    // Preorder Traversal
    cout << "\nPreorder Traversal: ";
    preorder(root);
    cout << endl;

    // Postorder Traversal
    cout << "\nPostorder Traversal: ";
    postorder(root);
    cout << endl;

    // Inorder Traversal
    cout << "\nPostorder Traversal: ";
    inorder(root);
    cout << endl;

    // Level Order Traversal
    cout << "\nLevel Order Traversal: ";
    bfs(root);
    cout << endl;

    // Height
    cout << "\nHeight of the tree is: " << getHeight(root);
    cout << endl;

    // Check for full Binary Tree
    string isFull = isFullBT(root) ? "complete" : "not complete";
    cout << "\nTree 1 is " << isFull;

    return 0;
}