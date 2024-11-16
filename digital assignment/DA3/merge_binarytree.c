#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void mergeTrees(int *tree1, int n1, int *tree2, int n2, int *result, int *res_size) {
    int max_size = fmax(n1, n2);
    *res_size = max_size;
	int i;
    for (i = 0; i < max_size; i++) {
        int val1 = (i < n1 && tree1[i] != 0) ? tree1[i] : 0;
        int val2 = (i < n2 && tree2[i] != 0) ? tree2[i] : 0;
        result[i] = val1 + val2;
    }
}

void printArray(int *arr, int size) {
	int i;
	for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
}

int main() {
    int n1, n2;
    printf("Enter number of nodes for the first tree: ");
    scanf("%d", &n1);
    int tree1[n1];
    printf("Enter the elements (0 for null) of the first tree (level-order): ");
    int i;
    for (i = 0; i < n1; i++) {
        scanf("%d", &tree1[i]);
    }

    printf("Enter number of nodes for the second tree: ");
    scanf("%d", &n2);
    int tree2[n2];
    printf("Enter the elements (0 for null) of the second tree (level-order): ");
    for (i = 0; i < n2; i++) {
        scanf("%d", &tree2[i]);
    }

    int max_size = fmax(n1, n2);
    int result[max_size];
    int res_size;

    mergeTrees(tree1, n1, tree2, n2, result, &res_size);

    printf("\nMerged Tree: ");
    printArray(result, res_size);
    printf("\n");

    return 0;
}

