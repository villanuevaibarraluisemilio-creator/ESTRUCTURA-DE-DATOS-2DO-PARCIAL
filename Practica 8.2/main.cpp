#include <iostream>
#include <stack>
using namespace std;

class Pila {
private:
    stack<int> pila;

public:
    void push(int val) {
        pila.push(val);
    }

    void pop() {
        pila.pop();
    }

    void mostrar() {
        stack<int> temp = pila;
        while (!temp.empty()) {
            cout << temp.top() << endl;
            temp.pop();
        }
    }
};

int main() {
    Pila p;
    p.push(1);
    p.push(2);
    p.push(3);
    p.mostrar();
}
