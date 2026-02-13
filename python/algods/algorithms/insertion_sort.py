def insertion_sort(arr):
    for i in range(1, len(arr)-1):
        key = arr[i]
        j = i - 1
        while j >= 0 and key < arr[j]:
            arr[j+1] = arr[j]
            j-=1
        arr[j+1] = key
    return arr

def main():
    arr = [7, 6, 1, 9, 3, 11]
    print(arr)
    arr = insertion_sort(arr)
    print(arr)    

if __name__ == "__main__":
    main()
