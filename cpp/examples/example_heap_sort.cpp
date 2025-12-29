#include <iostream>
#include <vector>

#include "algorithms/heap.hpp"

int main() {
    std::vector<int> v = {4, 10, 3, 5, 1};

    // Max-heap → orden ascendente
    Heap<int> maxHeap;
    maxHeap.heap_sort(v);

    std::cout << "Orden ascendente: ";
    for (int x : v)
        std::cout << x << " ";
    std::cout << "\n";

    // Min-heap → orden descendente
    std::vector<int> w = {4, 10, 3, 5, 1};
    Heap<int, std::greater<int>> minHeap;
    minHeap.heap_sort(w);

    std::cout << "Orden descendente: ";
    for (int x : w)
        std::cout << x << " ";
    std::cout << "\n";

    return 0;
}
