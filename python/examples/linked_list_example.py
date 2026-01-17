from python.algods.ds.my_linked_list import LinkedList

def menu():
    l1 = LinkedList()

    while(True):
        print('SINGLY LINKED LIST MEU:')
        print('1: Push front')
        print('2: Push back')
        print('3: Pop front')
        print('4: Get size')
        print('5: Print')
        print('6: Exit')

        option = input("Select an option: ")

        if (option == '1'):
            val = input("Insert data: ")
            l1.push_front(val)
        elif (option == '2'):
            val = input("Insert data: ")
            l1.push_back(val)
        elif (option == '3'):
            l1.pop_front()
        elif (option == '4'):
            l1.get_size()
        elif (option == '5'):
            l1.print_list()
        else:
            print('Insert a correct number')

if __name__ == '__main__':
    menu()