from .my_queue import Queue
import sys

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

    def get_height(self):
        return self._get_height(self.root)
    
    def get_min(self):
        return self._get_min(self.root)

    def get_max(self):
        return self._get_max(self.root)

    def is_bst(self):
        return self._is_bst(self.root, -sys.maxsize, sys.maxsize)

    def delete_node(self, data):
        self._delete_node(self.root, data)

    def get_successor(self, data):
        return self._get_successor(self.root, data)

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

    def _get_height(self, root):
        if root is None: return 0

        l_height = self._get_height(root.left)
        r_height = self._get_height(root.right)

        if l_height > r_height:
            return l_height + 1
        else:
            return r_height + 1

    def _get_min(self, root):
        if root.left is None: return root.data

        min = self._get_min(root.left) 

        return min  

    def _get_max(self, root):
        if root.right is None: return root.data

        max = self._get_max(root.right) 

        return max  
    
    def _is_bst(self, root, min, max):
        if root is None: return True

        if(root.data >= max or root.data <= min):
            return False

        return (self._is_bst(root.left, min, root.data) and
               self._is_bst(root.right, root.data, max))    

    def _delete_node(self, root, data):
        if root is None: return None
        if data < root.data: root.left = self._delete_node(root.left, data)
        elif data > root.data: root.right = self._delete_node(root.right, data)
        else:
            if root.left is None and root.right is None:
                del(root)
                root = None
            elif root.left is None:
                temp = root
                root = root.right
                del(temp)
            elif root.right is None:
                temp = root
                root = root.left
                del(temp)
            else:
                temp =self._get_min(root.right)
                root.data = temp
                root.right = self._delete_node(root.right, temp)
        return root

    def _get_successor(self, root, data):
        if root is None: return None

        if (data == root.data): return self._get_min(root.right)

        curr = root
        succ = None

        while curr != None:
            if data < curr.data:
                succ = curr.data
                curr = curr.left
            else:
                curr = curr.right
        if succ is None:
            return 

        return succ




