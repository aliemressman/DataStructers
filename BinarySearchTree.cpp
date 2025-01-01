#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node *right;

    Node(int value) : data(value), left(nullptr),right(nullptr){}
};

Node* insert(Node *root, int data){
    if(root == NULL) {
        return new Node(data);
    }
    else{
        if(data < root-> data){
            root->left = insert(root->left,data);
        }
        else if(data > root->data){
            root->right = insert(root->right,data);
        }
    }
    return root;
}

Node* minValueNode(Node *node){
    Node *current = node;
    while(current && current->left != nullptr){
        current = current->left;
    }
    return current;
}

Node *search(Node *root, int key){
    if(root == NULL || root->data == key){
        return root;
    }
    else if(key < root->data){
        return search(root->left,key);
    }
    else{
        return search(root->right,key);
    }
}


int main(){
    Node *root = nullptr;

    root = insert(root, 250);
    root = insert(root, 90);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);
    
    Node* minNode = minValueNode(root);
    cout << "Min value: " << minNode->data << endl ;
    
    Node* findNode = search(root,40);
    if(findNode != NULL) {
        cout << "bulundu : " << findNode->data <<endl;
    }
    else{
        cout << "bulunamadi" ;
    }
    
}
