#include <stdio.h>

// Recursive binary search function
int binarySearch(int arr[], int left, int right, int target) {
    if (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if the target is at the middle
        if (arr[mid] == target)
            return mid;

        // If target is smaller, search the left subarray
        if (target < arr[mid])
            return binarySearch(arr, left, mid - 1, target);

        // If target is larger, search the right subarray
        return binarySearch(arr, mid + 1, right, target);
    }

    // Target is not present
    return -1;
}

int main() {
    int n, target;

    // Input array size
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];

    // Input sorted array elements
    printf("Enter %d sorted elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input target element
    printf("Enter the element to search: ");
    scanf("%d", &target);

    // Perform binary search
    int result = binarySearch(arr, 0, n - 1, target);

    // Output the result
    if (result != -1)
        printf("Element found at index %d.\n", result);
    else
        printf("Element not found in the array.\n");

    return 0;
}
