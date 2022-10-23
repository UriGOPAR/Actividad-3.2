//Uri Jared Gopar Morales-A01709413
#include <iostream>
#include "priority_queue.h"
using namespace std;
int main(int argc, char* argv[]) {
    PriorityQueue<int> Queue(16);

    Queue.push(9);
    Queue.push(1);
    Queue.push(15);
    Queue.push(5);
    Queue.push(7);
    Queue.push(2);

    int tam = Queue.tamaño();
    cout << "tamano del arreglo: " << tam << "\n";

    cout << "Numero mas grande: "<<Queue.top() << "\n";
    Queue.pop();
    cout <<"Numero que va despues: "<< Queue.top() << "\n";

    if(Queue.empty()) {
        cout << "vacio\n";
    } else {
        cout << "no Vacio\n";
    }

    tam = Queue.tamaño();
    cout << "tamano: " << tam << "\n";
  
  return 0;
}