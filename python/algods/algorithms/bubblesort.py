def bubblesort(arr):
    n = len(arr)
    for i in range(0, n-1):
        swapped = False
        for j in range(0, n-i-1):
            if(arr[j+1] < arr[j]):
                arr[j+1], arr[j] = arr[j], arr[j+1]
                swapped = True
        if (swapped == False): 
            break
    return arr

def main():
    arr = [7, 6, 1, 9, 3, 11]
    print(arr)
    arr = bubblesort(arr)
    print(arr)

if __name__ == "__main__":
    main()


        

