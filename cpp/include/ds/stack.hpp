// stack.hpp
#pragma once
#include <cstddef>

template<typename T>
class Stack {
public:
    explicit Stack(std::size_t capacity);
    ~Stack();

    void push(const T& value);
    void pop();
    const T& peek() const;

    bool isEmpty() const;
    bool isFull() const;
    std::size_t size() const;

private:
    T* data_;
    std::size_t capacity_;
    std::size_t top_;
};

#include "stack.tpp"