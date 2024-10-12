#include <stdio.h>
#include <stdlib.h>

// Function to merge two sorted subarrays
void merge(int arr[], int left[], int left_size, int right[], int right_size) {
    int i = 0, j = 0, k = 0;
    
    // Merge the two subarrays into arr[]
    while (i < left_size && j < right_size) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
        }
    }
    
    // Copy remaining elements of left[], if any
    while (i < left_size) {
        arr[k++] = left[i++];
    }
    
    // Copy remaining elements of right[], if any
    while (j < right_size) {
        arr[k++] = right[j++];
    }
}

// Function to perform Merge Sort recursively
void merge_sort(int arr[], int size) {
    if (size <= 1) {
        // Base case: Array of size 0 or 1 is already sorted
        return;
    }
    
    int mid = size / 2;
    
    // Create temporary arrays for left and right halves
    int left[mid];
    int right[size - mid];
    
    // Copy data to temporary arrays
    for (int i = 0; i < mid; i++) {
        left[i] = arr[i];
    }
    for (int j = mid; j < size; j++) {
        right[j - mid] = arr[j];
    }
    
    // Recursively sort the left and right halves
    merge_sort(left, mid);
    merge_sort(right, size - mid);
    
    // Merge the sorted left and right halves into arr[]
    merge(arr, left, mid, right, size - mid);
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    printf("Given array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    merge_sort(arr, size);
    
    printf("Sorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}