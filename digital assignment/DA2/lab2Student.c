#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STACK_SIZE 100

struct Student {
    char stud_name[60];
    char reg_num[10];
    int mark1, mark2, mark3;
    int total;
    float average;
    char grade;
    struct Student *next;
};


int insCount = 0;
int delCount = 0;

struct Student* newNode(char *name, char *reg, int m1, int m2, int m3) {
    struct Student *node = (struct Student*)malloc(sizeof(struct Student));
    strcpy(node->stud_name, name);
    strcpy(node->reg_num, reg);
    node->mark1 = m1;
    node->mark2 = m2;
    node->mark3 = m3;
    node->total = m1 + m2 + m3;
    node->average = node->total / 3.0;

    if (m1 == -1 || m2 == -1 || m3 == -1) {
        node->grade = 'N';  
    } else if (node->average >= 91) {
        node->grade = 'S';
    } else if (node->average >= 81) {
        node->grade = 'A';
    } else if (node->average >= 71) {
        node->grade = 'B';
    } else if (node->average >= 61) {
        node->grade = 'C';
    } else if (node->average >= 51) {
        node->grade = 'D';
    } else if (node->average >= 41) {
        node->grade = 'E';
    } else {
        node->grade = 'F';  
    }

    node->next = NULL;
    return node;
}


int checkDup(struct Student *head, char *reg) {
    struct Student *temp = head;
    while (temp != NULL) {
        if (strcmp(temp->reg_num, reg) == 0) {
            return 1;  // Duplicate found
        }
        temp = temp->next;
    }
    return 0;  // No duplicate
}

void insertNode(struct Student **head, char *name, char *reg, int m1, int m2, int m3) {
    if (checkDup(*head, reg)) {
        printf("Duplicate registration number %s. Node not added.\n", reg);
        return;
    }

    struct Student *node = newNode(name, reg, m1, m2, m3);

    if (*head == NULL) {
        *head = node;
        insCount++;  
    } else {
        struct Student *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = node;
    }
     printf("%s inserted...\n", reg);
}

void displayList(struct Student *head) {
    if (head == NULL) {
        printf("No students in the list.\n");
        return;
    }

    struct Student *temp = head;
    while (temp != NULL) {
        printf("\nName: %s, \aReg Num: %s, \nMarks: %d, %d, %d, \nTotal: %d, \aAvg: %.2f, \aGrade: %c\n", 
               temp->stud_name, temp->reg_num, temp->mark1, temp->mark2, temp->mark3, 
               temp->total, temp->average, temp->grade);
        temp = temp->next;
    }
}

void printRev(struct Student *head) {
    struct Student *stack[STACK_SIZE];
    int top = -1;
    
    struct Student *temp = head;
    while (temp != NULL && top < STACK_SIZE - 1) {
        stack[++top] = temp;
        temp = temp->next;
    }

    printf("\nList from last to first:\n");
    while (top >= 0) {
        temp = stack[top--];
        printf("Name: %s, Reg Num: %s, \nAvg: %.2f, \aGrade: %c\n", 
               temp->stud_name, temp->reg_num, temp->average, temp->grade);
    }
}

void moveHighAvg(struct Student **head, struct Student **highList) {
    struct Student *temp = *head, *prev = NULL;

    while (temp != NULL) {
        if (temp->average > 90) {
            struct Student *toMove = temp;

            if (prev == NULL) {
                *head = temp->next;
                delCount++;  
            } else {
                prev->next = temp->next;
            }

            toMove->next = *highList;
            *highList = toMove;
            
            temp = (prev == NULL) ? *head : prev->next;
        } else {
            prev = temp;
            temp = temp->next;
        }
    }
}

int main() {
    struct Student *head = NULL, *highList = NULL;

 
    insertNode(&head, "PRAKASH", "24MCA0234", 92, 74, 91);
    insertNode(&head, "RAM", "24MCA0111", 60, 55, 65);
    insertNode(&head, "KISHAN", "24MCA0222", 94, 88, 95);
    insertNode(&head, "GOPAL", "24MCA0333", 30, 39, 40);

    printf("\nStudent Records:\n");
    displayList(head);

    printRev(head);

    moveHighAvg(&head, &highList);

    printf("\nHigh Scorers List:");
    displayList(highList);

    printf("\nRemaining Original List:\n");
    displayList(head);

    printf("\nHead updated during insertions: %d times\n", insCount);
    printf("Head updated during deletions: %d times\n", delCount);

    return 0;
}

