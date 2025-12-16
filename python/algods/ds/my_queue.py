class Queue:
    def __init__(self, capacity):
        self._data = [None] * capacity
        self._capacity = capacity
        self._size = 0
        self._front = 0
        self._rear = 0

    def enqueue(self, data):
        if self.is_full():
            print('The queue is full')
            return
        self._data[self._rear] = data 
        self._rear = (self._rear + 1) % self._capacity    
        self._size += 1

    def dequeue(self):
        if self.is_empty():
            print('The queue is already empty')
            return
        tempData = self._data[self._front]
        self._data[self._front] = None
        self._front = (self._front + 1) % self._capacity
        self._size -= 1
        return tempData

    def peek(self):
        if self.is_empty():
            print('The queue is empty')
            return 
        return self._data[self._front]

    def is_empty(self):
        return self._size == 0

    def is_full(self):
        return self._size == self._capacity

    def __len__(self):
        return self._size
    



