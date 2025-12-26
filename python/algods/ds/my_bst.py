from .my_queue import Queue

class Node:
    def __init__(self, data):
        self.data = data
        self.visited = False
        self.left = None
        self.right = None
    
class BinarySearchTree:
    def __init__(self):
        self.root = None

    def insert(self, data):
        self.root = self._insert(self.root, data)

    def dfs(self, mode):
        result = []
        self._dfs(self.root, mode, result)
        return result

    def bfs(self):
        result = []
        self._bfs(self.root, result)
        return result

    def _insert(self, node, data):
        if node is None:
            return Node(data)
        
        if data < node.data:
            node.left = self._insert(node.left, data)
        elif data > node.data:
            node.right = self._insert(node.right, data)

        return node

    def _dfs(self, node, mode, result):
        if node is None: return None
        if mode == 0: result.append(node.data)
        self._dfs(node.left, mode, result)
        if mode == 1: result.append(node.data)
        self._dfs(node.right, mode, result)
        if mode == 2:result.append(node.data)

    def _bfs(self, node, result):
        if node is None: return None

        q1 = Queue(20)
        q1.enqueue(node)

        while q1:
            current = q1.dequeue()
            result.append(current.data)

            if current.left: q1.enqueue(current.left)
            if current.right: q1.enqueue(current.right)


def main():

    bst1 = BinarySearchTree()

    bst1.insert(10)
    bst1.insert(100)
    bst1.insert(20)
    bst1.insert(40)
    bst1.insert(80)
    bst1.insert(800)
    bst1.insert(1)
    bst1.insert(33)
    bst1.insert(5)

    result = bst1.dfs(2)

    print(result)

    result = bst1.bfs()

    print(result)

if __name__ == "__main__":
    print("Executing bst")
    main()


