#include <stdio.h>

// Recursive function for linear search
int linearSearch(int arr[], int size, int key, int index) {
    if (index >= size) {
        return -1; // Not found
    }
    if (arr[index] == key) {
        return index; // Found at index
    }
    return linearSearch(arr, size, key, index + 1); // Recursive call
}

int main() {
    int size, key;

    // Take size of array from user
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size]; // Declare array

    // Input elements
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Input key to search
    printf("Enter the element to search: ");
    scanf("%d", &key);

    // Call recursive linear search
    int result = linearSearch(arr, size, key, 0);

    // Print result
    if (result != -1) {
        printf("Element found at index %d.\n", result);
    } else {
        printf("Element not found in the array.\n");
    }

    return 0;
}
