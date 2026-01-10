#include <iostream>
#include <cassert>
#include <ds/binary_heap.hpp>

void test_min_heap() {
    BinaryHeap<int> heap;

    heap.push(5);
    heap.push(1);
    heap.push(8);
    heap.push(3);
    heap.push(2);

    assert(heap.top() == 1);

    heap.pop(); // 1
    assert(heap.top() == 2);

    heap.pop(); // 2
    assert(heap.top() == 3);

    heap.pop(); // 3
    heap.pop(); // 5
    assert(heap.top() == 8);

    heap.pop();
    assert(heap.empty());

    std::cout << "✓ Min-heap OK\n";
}

void test_max_heap() {
    BinaryHeap<int, std::greater<int>> heap;

    heap.push(5);
    heap.push(1);
    heap.push(8);
    heap.push(3);
    heap.push(2);

    assert(heap.top() == 8);

    heap.pop(); // 8
    assert(heap.top() == 5);

    heap.pop(); // 5
    assert(heap.top() == 3);

    heap.pop(); // 3
    heap.pop(); // 2
    assert(heap.top() == 1);

    heap.pop();
    assert(heap.empty());

    std::cout << "✓ Max-heap OK\n";
}

void test_exceptions() {
    BinaryHeap<int> heap;

    try {
        heap.pop();
        assert(false); // no debería llegar aquí
    } catch (const std::out_of_range&) {
        std::cout << "✓ pop() lanza excepción en heap vacío\n";
    }

    try {
        heap.top();
        assert(false);
    } catch (const std::out_of_range&) {
        std::cout << "✓ top() lanza excepción en heap vacío\n";
    }
}

int main() {
    test_min_heap();
    test_max_heap();
    test_exceptions();

    std::cout << "\nTodos los tests pasaron correctamente 🎉\n";
    return 0;
}
