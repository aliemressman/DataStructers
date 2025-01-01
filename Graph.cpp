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
