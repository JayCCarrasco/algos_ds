class Node():
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList():
    def __init__(self):
        self.head = None
        self.size = 0

    def push_front(self, data):
        node = Node(data)

        if self.head:
            node.next = self.head

        self.head = node
        self.size += 1

        return

    def push_back(self, data):
        node = Node(data)

        if self.head is None:
            self.head = node
            self.size += 1
            return

        temp = self.head
        
        while temp.next is not None:
            temp = temp.next
        
        temp.next = node

        self.size+=1

        return

    def pop_front(self):
        if self.head is None:
            print('Linked list is empty')
            return
        
        temp = self.head
        self.head = temp.next
        del(temp)

        self.size-=1

        return

    def get_size(self):
        print('The size is: ', self.size)

    def print_list(self):
        temp = self.head

        while temp:
            print(temp.data, " ")
            temp = temp.next

        return

        

    

    
        

        
        





