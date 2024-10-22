#include <stdio.h>
#include <stdbool.h>
bool hasRepeated(int arr[], int n) {
	int i,j;
    for (i = 0; i < n; i++) {
        for ( j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                return true;
            }
        }
    }
    return false;
}
int findEvenDiv(int in[], int n, int res[]) {
    int idx = 0,i;
    for (i = 0; i < n; i++) {
        if (in[i] % 2 == 0) {
            res[idx++] = in[i];
        }
    }
    return idx; 
}
void findSecSmallLin(int arr[], int n) {
    if (n < 2) {
        printf("No second smallest element available.\n");
        return;
    }

    int first, second;
    first = second = __INT_MAX__;
    int i;
    for (i = 0; i < n; i++) {
        if (arr[i] < first) {
            second = first;
            first = arr[i];
        } else if (arr[i] < second && arr[i] != first) {
            second = arr[i];
        }
    }
    for (i = 0; i < n; i++) {
        if (arr[i] == second) {
            printf("Using Linear Search: Index is %d and corresponding number is %d.\n", i, second);
            return;
        }
    }
}

void findSecSmallBin(int arr[], int n) {
    if (n < 2) {
        printf("No second smallest element available.\n");
        return;
    }
    int i,j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
    printf("Using Binary Search: Index is 1 and corresponding number is %d.\n", arr[1]);
}

int main() {
    int in[100], n,i;
    do {
        printf("Enter the number of elements in the sequence: ");
        scanf("%d", &n);
        printf("Enter %d elements (unrepeated):\n", n);
        for (i = 0; i < n; i++) {
            scanf("%d", &in[i]);
        }
        if (hasRepeated(in, n)) {
            printf("The sequence has repeated values. Please enter a unique sequence.\n");
        }
    } while (hasRepeated(in, n));

    int res[100];
    int resSize = findEvenDiv(in, n, res);

    printf("Intermediate result (divisible by any even number): ");
    for ( i = 0; i < resSize; i++) {
        printf("%d ", res[i]);
    }
    printf("\n");
    findSecSmallLin(res, resSize);
    findSecSmallBin(res, resSize);
    return 0;
}

