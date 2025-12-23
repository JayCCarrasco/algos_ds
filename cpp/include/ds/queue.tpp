#include <stdexcept>

template<typename T>
Queue<T>::Queue(std::size_t capacity)
    : capacity_(capacity), size_(0), head_(0), tail_(0) 
{
    data_ = new T[capacity_];   
}

template<typename T>
Queue<T>::~Queue() {
    delete[] data_;
}

template<typename T>
void Queue<T>::push(const T& value){
    if (size_ == capacity_) {
        throw std::runtime_error("Queue full");
    }

    data_[tail_] = value;
    tail_ = (tail_ + 1) % capacity_;
    size_++;
}

template<typename T>
void Queue<T>::pop(){
    if(isEmpty()){
        throw std::runtime_error("Queue empty");
    }

    head_ = (head_ + 1) % capacity_;
    size_--;
}

template<typename T>
const T& Queue<T>::front() const{
    if(isEmpty()){
        throw std::runtime_error("Queue is empty");
    }

    return data_[head_];
}

template<typename T>
bool Queue<T>::isEmpty() const{
    return size_ == 0;
}

template<typename T>
std::size_t Queue<T>::size() const{
    return size_;
}