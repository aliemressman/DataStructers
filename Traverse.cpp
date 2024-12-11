#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *left, *right;

        Node(int value){
            data = value;
            left = right = NULL;
        }
};

// Preorder traversal (Root, Left, Right)

void preOrder(Node *root){
    if(root != nullptr){
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

// Inorder traversal (Left, Root, Right)

void inOrder(Node *root){
    if(root != nullptr){
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}

// Postorder traversal (Left, Right, Root)

void postOrder(Node *root){
    if(root != NULL){
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
}

int main(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout << "\nPreorder traversal: ";
    preOrder(root);
    cout << "\n";

    cout << "\nInorder traversal: ";
    inOrder(root);
    cout << "\n";

    cout << "\nPostorder traversal: ";
    postOrder(root);
    cout << "\n";

    return 0;
}