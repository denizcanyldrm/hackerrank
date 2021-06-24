#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

bool helper(Node* node, Node* left, Node* right) {
	if (node == nullptr)
		return true;

	if (left != nullptr && node->data <= left->data)
		return false;

	if (right != nullptr && node->data >= right->data)
		return false;        

	return helper(node->left, left, node) && helper(node->right, node, right);
}

bool checkBST(Node* root) {
	return helper(root, nullptr, nullptr);
}

void printTree(Node* root) {
    Node* node = root;
    if (node != nullptr) {
        printTree(node->left);
        cout << node->data << " ";
        printTree(node->right);
    }
}

int main()
{
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);

    /*
    Node* root = new Node(75);
    root->left = new Node(30);
    root->right = new Node(90);
    root->left->left = new Node(20);
    root->left->right = new Node(60);
    root->right->left = new Node(80);
    root->right->right = new Node(100);
    root->left->left->left = new Node(10);
    root->left->left->right = new Node(40);
    root->left->right->left = new Node(50);
    root->left->right->right = new Node(70);
    */
    
    printTree(root);
    cout << endl;
    bool isBst = checkBST(root);
    cout << "isBst: " << isBst << endl;
    return 0;
}