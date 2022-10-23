#include <iostream>
#include "priority_queue.h"

int main(int argc, char* argv[]) {
    PriorityQueue<int> pQueue(16);

    pQueue.push(9);
    pQueue.push(1);
    pQueue.push(15);
    pQueue.push(5);
    pQueue.push(7);
    pQueue.push(2);

    int tam = pQueue.tamaño();
    std::cout << "tamano del arreglo: " << tam << "\n";

    std::cout << "Numero mas grande: "<<pQueue.top() << "\n";
    pQueue.pop();
    std::cout <<"Numero que va despues: "<< pQueue.top() << "\n";

    if(pQueue.empty()) {
        std::cout << "vacio\n";
    } else {
        std::cout << "no Vacio\n";
    }

    tam = pQueue.tamaño();
    std::cout << "tamano: " << tam << "\n";
  
  return 0;
}