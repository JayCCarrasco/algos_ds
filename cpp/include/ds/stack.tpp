#include <stdexcept>

template<typename T>
Stack<T>::Stack(std::size_t capacity)
    : capacity_(capacity), top_(0)
{
    data_ = new T[capacity_];
}

template<typename T>
Stack<T>::~Stack()
{
    delete[] data_;
}

template<typename T>
void Stack<T>::push(const T& value)
{
    if (isFull())
        throw std::overflow_error("Stack is full");

    data_[top_++] = value;
}

template<typename T>
void Stack<T>::pop()
{
    if (isEmpty())
        throw std::underflow_error("Stack is empty");

    --top_;
}

template<typename T>
const T& Stack<T>::peek() const
{
    if (isEmpty())
        throw std::underflow_error("Stack is empty");

    return data_[top_ - 1];
}

template<typename T>
bool Stack<T>::isEmpty() const
{
    return top_ == 0;
}

template<typename T>
bool Stack<T>::isFull() const
{
    return top_ == capacity_;
}

template<typename T>
std::size_t Stack<T>::size() const
{
    return top_;
}
