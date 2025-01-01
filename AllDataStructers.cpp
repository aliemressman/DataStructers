// HASHTABLE
#include <iostream>
#include <string>

using namespace std; // Tüm standart kütüphaneleri kolaylıkla kullanmak için

#define TABLE_SIZE 128 // Hash tablosunun boyutunu sabit olarak tanımlıyoruz

// Bağlantılı liste için düğüm sınıfı
class Node {
public:
    string key; // Düğümün anahtar değeri
    int value;  // Düğümün değer kısmı
    Node* next; // Bir sonraki düğümü işaret eden gösterici

    // Yapıcı: Yeni bir düğüm oluştururken anahtar ve değer atanır
    Node(const string& k, int v) : key(k), value(v), next(nullptr) {}
};

// Hash tablosu sınıfı
class HashTable {
private:
    Node* table[TABLE_SIZE]; // Hash tablosu için bir dizi

    // Hash fonksiyonu: Anahtar değerini tablo boyutuna göre bir indise dönüştürür
    int hash(const string& key) {
        int hashValue = 0;
        for (char ch : key) {
            hashValue = (hashValue * 31) + ch; // Yaygın bir hash fonksiyonu
        }
        return hashValue % TABLE_SIZE; // Tablo boyutuna göre mod alarak indeks oluşturur
    }

public:
     // Yapıcı: Hash tablosunu başlatır ve tüm bucket'ları NULL yapar
    HashTable() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            table[i] = nullptr;
        }
    }

    // Yıkıcı: Tüm düğümleri serbest bırakır
    ~HashTable() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            Node* head = table[i];
            while (head) {
                Node* temp = head;
                head = head->next;
                delete temp; // Düğümü serbest bırak
            }
        }
    }
    
    void insert(const string &key, int value){
        int index = hash(key);
        Node* newNode = new Node(key,value);
        newNode->next = table[index];
        table[index] = newNode;
    }
    
    int search(const string &key){
        int index = hash(key);
        Node* current = table[index];
        while(current){
            if(current->key == key){
                return current-> value;
            }
            current = current->next;
        }
        return -1;
    }
    
    void erase(const string &key){
        int index = hash(key);
        Node *current = table[index];
        Node *prev = nullptr;
        while(current){
            if(current->key == key){
                if(prev){
                    prev->next = current->next;
                }
                else{
                    table[index] = current->next;
                }
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
    }
    
    void display(){
        for(int i = 0; i < TABLE_SIZE; i++){
            Node *current = table[i];
            if(current){
                cout << "Bucket" << i << endl;
                while(current){
                    cout << " " << current->key << ":" << current->value << endl;
                    current = current-> next;
                }
            }
        }
    }
};

int main(){
    HashTable ht;
    ht.insert("ali",20);
    ht.insert("veli",55);
    ht.insert("busra",11);
    ht.insert("abdullah",35);
    
    ht.display();
    return 0;
}
// GRAPH 
#include <iostream>
#include <vector>
using namespace std;

class Graph {
private:
    vector<vector<int>> adjList;

public:
    // Constructor
    Graph(int nodes) {
        adjList.resize(nodes);
    }

    // Graf’a yeni kenarların eklenmesi
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u); 
    }

    // Graf’a yeni düğümlerin eklenmesi
    void addNode() {
        adjList.push_back({});
    }

    
    void display() {
        for (int i = 0; i < adjList.size(); ++i) {
            cout << i << ": ";
            for (int neighbor : adjList[i]) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    // Üç elemanlı bir graf oluşturma
    Graph g(3);

    // Add edges
    g.addEdge(0, 1);
    g.addEdge(1, 2);

    cout << "Yeni bir düğüm eklenmeden önce Graf:\n";
    g.display();

    // Yeni bir düğüm ekle
    g.addNode();

    cout << "\nYeni bir düğüm ekledikten sonra graf:\n";
    g.display();

    return 0;
}
// BİNARY SEARCH TREE
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
// STACK 
#include<iostream>

using namespace std;


struct Node{
    int data;
    Node *next;
};

Node *top = new Node();
int stackSize=0;

void push(int n){
    Node *newElement = new Node();
    
    newElement->data = n;
    newElement->next = top;
    top= newElement;
    
    cout<<"Stack'e "<<n<<" eklendi."<<endl;
    stackSize++;
}

void pop(){
    if(stackSize !=0){
        cout<<"Eleman "<<top->data<<" silindi."<<endl;
        top=top->next;
        stackSize--;
    }
    else{
      cout<<"Stack boş."<<endl;}
}

void print(Node *ptr){
    for (int i=1; i<=stackSize; i++){
        cout<<ptr->data<<" "<<endl;
        ptr = ptr->next;
    }
}

int main(){
  push(15);     // Yığına 15 elemanını ekler
  push(22);     // Yığına 22 elemanını ekler
  pop();        // Yığından 22 elemanını çıkarır
  push(54);     // Yığına 54 elemanını ekler
  pop();        // Yığından 54 elemanını çıkarır
  push(65);     // Yığına 65 elemanını ekler
  pop();        // Yığından 65 elemanını çıkarır
  pop();        // Yığından 15 elemanını çıkarır
  print(top);
    
}
// QUEUE 
#include <iostream>
using namespace std;

#define SIZE 10 // Kuyruğun maksimum boyutu

class Queue {
private:
    int items[SIZE], front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    // Kuyruğa eleman ekleyen fonksiyon
    void enqueue(int value) {
        if (rear == SIZE - 1) {
            cout << "Kuyruk dolu! Eleman eklenemiyor." << endl;
        } else {
            if (front == -1) front = 0;
            rear++;
            items[rear] = value;
            cout << "Kuyruğa eklenen eleman: " << value << endl;
        }
    }

    // Kuyruktan eleman çıkaran fonksiyon
    void dequeue() {
        if (front == -1) {
            cout << "Kuyruk boş! Eleman çıkarılamıyor." << endl;
        } else {
            cout << "Kuyruktan çıkarılan eleman: " << items[front] << endl;
            front++;
            if (front > rear) {
                front = rear = -1; // Kuyruk boşsa sıfırla
            }
        }
    }

    // Kuyruğun içeriğini gösteren fonksiyon
    void display() {
        if (rear == -1) {
            cout << "Kuyruk boş!" << endl;
        } else {
            cout << "Kuyruk: ";
            for (int i = front; i <= rear; i++) {
                cout << items[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Queue q;

    q.enqueue(5);
    q.enqueue(10);
    q.enqueue(15);

    q.display();

    q.dequeue();
    q.display();

    return 0;
}
// TRAVERSE
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
