#pragma once

#include <iostream>
#include <vector>

using namespace std;

namespace SortLibrary {

template<typename T>
void BubbleSort(std::vector<T>& data)
{
    size_t rem_size = data.size();
    size_t last_seen = rem_size;
    bool swapped = true;

    while (swapped) {
        swapped = false;
        for (size_t i = 1; i < rem_size; i++) {
            if (data[i-1] > data[i]) {
                std::swap(data[i-1], data[i]);
                swapped = true;
                last_seen = i;
            }
        }
//        rem_size = rem_size - 1;
        rem_size = last_seen;
    }
}

template <typename T>
void Heapify(std::vector<T>& arr, int n, int i) {
    int largest = i;          // Initialize largest as root
    int left = 2 * i + 1;     // left child
    int right = 2 * i + 2;    // right child

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != i) {
        std::swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        Heapify(arr, n, largest);
    }
}

template <typename T>
void HeapSort(std::vector<T>& arr) {
    int n = arr.size();

    // Build heap (rearrange vector)
    for (int i = n / 2 - 1; i >= 0; i--)
        Heapify(arr, n, i);

    // One by one extract elements from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        std::swap(arr[0], arr[i]);

        // Call max heapify on the reduced heap
        Heapify(arr, i, 0);
    }
}


}


