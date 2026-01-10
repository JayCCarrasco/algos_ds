#pragma once
#include <cstddef>

template <typename T, typename Compare = std::less<T>>
class BinaryHeap {
public:
    BinaryHeap();

    bool empty() const;
    std::size_t size() const;
    const T& top() const;

    void push(const T& data);
    void pop();

private:
    std::vector<T> heap;
    Compare comp;

    void sift_up(std::size_t index);
    void sift_down(std::size_t index);
};

#include "binary_heap.tpp"