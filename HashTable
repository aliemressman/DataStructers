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


