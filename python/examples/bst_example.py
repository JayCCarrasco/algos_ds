from python.algods.ds.my_bst import BinarySearchTree

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

    height = bst1.get_height()

    print('Height is: ', height)

    min = bst1.get_min()

    print('Min is: ', min)

    max = bst1.get_max()

    print('Max is: ', max)

    is_tree = bst1.is_bst()

    print('Is it tree? ', is_tree)

    bst1.delete_node(100)

    result = bst1.bfs()

    print(result)

    successor = bst1.get_successor(20)

    print('The successor is: ', successor)

    

if __name__ == "__main__":
    print("Executing bst")
    main()