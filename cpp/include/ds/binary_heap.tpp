#include <vector>
#include <stdexcept>
#include <functional>

template <typename T, typename Compare>
BinaryHeap<T, Compare>::BinaryHeap() {}

template <typename T, typename Compare>
bool BinaryHeap<T, Compare>::empty() const {
    return heap.empty();
}

template <typename T, typename Compare>
size_t BinaryHeap<T, Compare>::size() const {
    return heap.size();
}

template <typename T, typename Compare>
const T& BinaryHeap<T, Compare>::top() const {
    if (empty())
        throw std::out_of_range("Heap is empty");
    return heap[0];
}

template <typename T, typename Compare>
const T& BinaryHeap<T, Compare>::sift_up(std::size_t index){
    while(index > 0){
        std::size_t parent = (index - 1) / 2;

        if(!comp(heap[index], heap[parent])){
            break;
        }
        std::swap(heap[index], heap[parent]);
        index = parent;
    }
}


template <typename T, typename Compare>
const T& BinaryHeap<T, Compare>::sift_down(std::size_t index){
    std::size_t n = heap.size();
    std::size_t right = 2 * index + 2;
    std::size_t left = 2 * index + 1;
    std::size_t best = index;

    if(left < n && comp(heap[left], heap[best])){
        best = left;
    }
    if(right < n && comp(heap[right], heap[best])){
        best = right;
    }

    if(index != best){
        std::swap(heap[index], heap[best]);
        sift_down(best);
    }
}

