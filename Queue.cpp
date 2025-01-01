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
