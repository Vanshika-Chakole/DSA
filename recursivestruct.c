#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
    int roll;
    char name[50];
    struct Student* next; // Pointer to the next Student structure
} Student;

void printStudentList(Student* student) {
    if (student == NULL) {
        return; // Base case: end of the list
    }

    printf("Roll: %d, Name: %s\n", student->roll, student->name);
    printStudentList(student->next); // Recursive call to the next node
}

int main() {
    // Create a linked list of Student structures
    Student* head = NULL;
    Student* current = NULL;
    Student* newNode = NULL;

    // Create and add the first student
    newNode = (Student*)malloc(sizeof(Student));
    if (newNode == NULL) {
        perror("Memory allocation failed");
        return 1;
    }
    newNode->roll = 101;
    strcpy(newNode->name, "Alice");
    newNode->next = NULL;
    head = newNode;
    current = newNode;

    // Create and add the second student
    newNode = (Student*)malloc(sizeof(Student));
    if (newNode == NULL) {
        perror("Memory allocation failed");
        return 1;
    }
    newNode->roll = 102;
    strcpy(newNode->name, "Bob");
    newNode->next = NULL;
    current->next = newNode;
    current = newNode;

    // Create and add the third student
    newNode = (Student*)malloc(sizeof(Student));
    if (newNode == NULL) {
        perror("Memory allocation failed");
        return 1;
    }
    newNode->roll = 103;
    strcpy(newNode->name, "Charlie");
    newNode->next = NULL;
    current->next = newNode;

    // Print the linked list using the recursive function
    printf("Student List:\n");
    printStudentList(head);

    // Free the allocated memory (important to avoid memory leaks)
    current = head;
    while (current != NULL) {
        Student* temp = current;
        current = current->next;
        free(temp);
    }
    head = NULL; //set head to null after freeing

    return 0;
}