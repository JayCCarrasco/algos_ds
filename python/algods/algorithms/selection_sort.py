def selection_sort(arr):
    n = len(arr)
    for i in range(0, n-1):
        min = i
        for j in range(i, n-1):
            if (arr[j] < arr[min]):
                min = j
        arr[i], arr[min] = arr[min], arr[i]
    return arr

def main():
    arr = [7, 6, 1, 9, 3, 11]
    print(arr)
    arr = selection_sort(arr)
    print(arr)   

if __name__ == "__main__":
    main()
        