#include <iostream>
#include <queue>
using namespace std;

class Cola {
private:
    queue<int> cola;

public:
    void enqueue(int val) {
        cola.push(val);
    }

    void dequeue() {
        cola.pop();
    }

    void mostrar() {
        queue<int> temp = cola;
        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << endl;
    }
};

int main() {
    Cola c;
    c.enqueue(10);
    c.enqueue(20);
    c.enqueue(30);
    c.mostrar();
}
