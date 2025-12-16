from python.algods.ds.my_queue import Queue

def main():
    print("Creating queue with capacity 5")
    q = Queue(capacity=5)

    print("\nEnqueue elements:")
    q.enqueue(10)
    q.enqueue(20)
    q.enqueue(30)
    q.enqueue(40)

    print(f"Queue size: {len(q)}")
    print(f"Front element (peek): {q.peek()}")

    print("\nDequeue elements:")
    while not q.is_empty():
        value = q.dequeue()
        print(f"Dequeued: {value} | Size now: {len(q)}")

    print("\nTrying to dequeue from empty queue:")
    try:
        q.dequeue()
    except IndexError as e:
        print(f"Caught exception: {e}")

    print("\nEnqueue after emptying (wrap-around test):")
    q.enqueue(50)
    q.enqueue(60)

    print(f"Front element: {q.peek()}")
    print(f"Queue size: {len(q)}")

if __name__ == "__main__":
    main()
