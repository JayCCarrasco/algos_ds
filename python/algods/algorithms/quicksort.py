def quicksort(arr, low, high):
    if low < high:
        pi = partition(arr, low, high)

        quicksort(arr, low, pi-1)
        quicksort(arr, pi, high)

def partition(arr, low, high):
    pivot = arr[high]
    i = low - 1

    for j in range(low, high):
        if arr[j] < pivot:
            i+=1
            arr[i], arr[j] = arr[j], arr[i]

    arr[i+1], arr[high] = arr[high], arr[i+1]

    return i + 1

def main():
    arr = [34, 5, 8, 100, 10, 0, 1, 55, 4, 63]
    n = len(arr)

    quicksort(arr, 0, n-1)

    print(arr)

if __name__ == "__main__":
    main()
