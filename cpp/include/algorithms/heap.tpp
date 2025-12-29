#include <utility>

template <typename T, typename Compare>
void Heap<T, Compare>::heapify(std::vector<T>& arr, std::size_t n, std::size_t i){
    std::size_t best = i;
    std::size_t l = 2 * i + 1;
    std::size_t r = 2 * i + 2;

    if (l < n && comp(arr[best], arr[l]))
        best = l;

    if (r < n && comp(arr[best], arr[r]))
        best = r;

    if (best != i){
        std::swap(arr[i], arr[best]);
        heapify(arr, n, best);
    }
}

template <typename T, typename Compare>
void Heap<T, Compare>::heap_sort(std::vector<T>& arr){
    std::size_t n = arr.size();

    for(int i = static_cast<int>(n / 2) - 1; i >= 0; i--){
        heapify(arr, n, i);
    }

    for(std::size_t i = n; i > 0; i--){
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
