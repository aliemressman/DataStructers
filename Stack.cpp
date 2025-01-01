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
