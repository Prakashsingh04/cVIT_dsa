#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL) 
        return createNode(data);
    
    if (data < root->data) 
        root->left = insert(root->left, data);
    else if (data > root->data) 
        root->right = insert(root->right, data);
    
    return root;
}

int search(struct Node* root, int key) {
    if (root == NULL) 
        return 0;
    
    if (root->data == key) 
        return 1;
    
    if (key < root->data) 
        return search(root->left, key);
    
    return search(root->right, key);
}

int main() {
    struct Node* root = NULL;
    int n, i, searchCount;

    printf("Enter the number of elements to insert in the BST: ");
    scanf("%d", &n);
    
    int values[n];
    printf("Enter %d elements:\n", n);
    
    for (i = 0; i < n; i++) {
        scanf("%d", &values[i]);
        root = insert(root, values[i]);
    }

    printf("Enter the number of elements to search for: ");
    scanf("%d", &searchCount);
    
    int keys[searchCount];
    printf("Enter %d elements to search:\n", searchCount);
    
    for (i = 0; i < searchCount; i++) {
        scanf("%d", &keys[i]);
    }

    for (i = 0; i < searchCount; i++) {
        if (search(root, keys[i])) {
            printf("Found %d\n", keys[i]);
        } else {
            printf("Not Found %d\n", keys[i]);
        }
    }

    return 0;
}

