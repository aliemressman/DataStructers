#include <iostream>
using namespace std;

class Node {
  public:
    int data;
    Node *left, *right;

    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
};

Node *insert(Node *root, int data) {
    if (root == NULL) {
        return new Node(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

Node *search(Node *root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }
    if (key < root->data) {
        return search(root->left, key);
    }
    return search(root->right, key);
}

Node *minValueNode(Node *node) {
    Node *current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

Node *deleteNode(Node *root, int key) {
    if (root == NULL) {
        return root;
    }
    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == NULL) {
            Node *temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        Node *temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main() {
 setlocale(LC_ALL, "Turkish");
 Node* root = nullptr;
 root = insert(root, 10);
 root = insert(root, 90);
 root = insert(root, 30);
 root = insert(root, 40);
 root = insert(root, 70);
 root = insert(root, 60);
 root = insert(root, 80);
 Node* foundNode = search(root, 40);
 if (foundNode != nullptr){
 cout << "Aradığınız öğe " << foundNode->data << " bulundu." << endl;
 }
 else {
 cout << "Öğe bulunamadı." << endl;
 }
 root = deleteNode(root, 20);
 foundNode = search(root, 20);
 if (foundNode != nullptr){
 cout << "Aradığınız öğe " << foundNode->data << " bulundu." << endl;
 }
 else {
 cout << "Öğe bulunamadı." << endl;
 }
 return 0;
}
