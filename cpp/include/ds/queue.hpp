//queue.hpp
#pragma once
#include <cstddef>

template<typename T>
class Queue {
public:
    explicit Queue(std::size_t capacity);
    ~Queue();

    void push(const T& value);
    void pop();
    const T& front() const;

    bool isEmpty() const;
    std::size_t size() const;

private:
    T* data_;
    std::size_t capacity_;
    std::size_t size_;
    std::size_t head_;
    std::size_t tail_;
};

#include "queue.tpp"