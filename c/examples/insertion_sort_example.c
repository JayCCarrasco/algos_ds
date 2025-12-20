#include <stdio.h>
#include "algorithms/insertion_sort.h"

int main() {
    int arr[] = {5, 2, 9, 1, 5, 6};
    size_t n = sizeof(arr) / sizeof(arr[0]);

    printf("Antes: ");
    for (size_t i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    insertion_sort(arr, n, sizeof(int), cmp_int);

    printf("Después: ");
    for (size_t i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
