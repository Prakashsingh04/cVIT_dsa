#include <stdio.h>
#define DIGIT_RANGE 10 

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];

    for (i = 0; i < n1; i++) L[i] = arr[l + i];
    for (j = 0; j < n2; j++) R[j] = arr[m + 1 + j];
    i = 0;  
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        
        merge(arr, l, m, r);
    }
}

void printArray(int arr[], int size) {
	int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void reverseArray(int arr[], int size) {
    int temp,i;
    for ( i = 0; i < size / 2; i++) {
        temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }
}

int main() {
    int input[] = {7, 7, 5, 2, 5, 2, 8, 5, 6, 8, 8, 7, 4, 4, 7, 2, 3, 8, 9, 3, 2, 9, 7, 8, 3};
    int n = sizeof(input) / sizeof(input[0]);

    int count[DIGIT_RANGE] = {0};

	int i;
    for (i = 0; i < n; i++) {
        int digit = input[i];
        if (digit >= 2 && digit <= 9) {
            count[digit]++;
        }
    }

    int intermediate[] = {count[2], count[3], count[4], count[5], count[6], count[7], count[8], count[9]};
    int size = sizeof(intermediate) / sizeof(intermediate[0]);

    printf("Intermediate output (counts of digits 2 to 9):\n");
    printArray(intermediate, size);

    mergeSort(intermediate, 0, size - 1);

    printf("\nSorted array in ascending order:\n");
    printArray(intermediate, size);

    reverseArray(intermediate, size);

    printf("\nSorted array in descending order:\n");
    printArray(intermediate, size);

    return 0;
}

