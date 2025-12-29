#pragma once

#include <vector>
#include <functional>

template <typename T, typename Compare = std::less<T>>
class Heap{
public:
    void heap_sort(std::vector<T> &arr);

private:
    Compare comp;
    void heapify(std::vector<T> &arr, std::size_t n, std::size_t i);   
};

#include "heap.tpp"