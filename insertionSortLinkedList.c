//Algorithm for sorting using insertion sort

//Example 1:

//Input: 4->2->1->3
//Output: 1->2->3->4
//Example 2:

//Input: 4->3->2->10->12->1->5->6
//Output: 1->2->3->4->5->6->10->12
//Algorithm:
//1.Traverse through the list from the second element, i.e., current = head->next.
//2. Compare the current element with the previous element.
//3. If the current element is smaller than the previous element, then compare it with the elements before.
//4. Move the greater elements one position up to make space for the swapped element.
//Time Complexity: O(n^2)
//Auxiliary Space: O(1)


// C program for implementation of above algorithm ie, insertion sort on linked list

#include <stdio.h>
#include <stdlib.h>

// A linked list node
struct Node
{
    int data;
    struct Node *next;
};

// Function to sort the singly linked list using insertion sort
void insertionSort(struct Node **head_ref)
{
    // Initialize sorted linked list
    struct Node *sorted = NULL;

    // Traverse the given linked list and insert every
    // node to sorted
    struct Node *current = *head_ref;
    while (current != NULL)
    {
        // Store next for next iteration
        struct Node *next = current->next;

        // insert current in sorted linked list
        sortedInsert(&sorted, current);

        // Update current
        current = next;
    }

    // Update head_ref to point to sorted linked list
    *head_ref = sorted;
}

// function to insert a new_node in a list

void sortedInsert(struct Node** head_ref, struct Node* new_node)
{
    struct Node* current;
    /* Special case for the head end */
    if (*head_ref == NULL || (*head_ref)->data >= new_node->data)
    {
        new_node->next = *head_ref;
        *head_ref = new_node;
    }
    else
    {
        /* Locate the node before the point of insertion */
        current = *head_ref;
        while (current->next!=NULL &&
               current->next->data < new_node->data)
        {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}

// A utility function to print a given linked list
void printList(struct Node *head)
{
    struct Node *temp = head;
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

// Driver program to test above functions

int main()
{
    struct Node *a = NULL;
    struct Node *new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = 5;
    sortedInsert(&a, new_node);
    new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = 20;
    sortedInsert(&a, new_node);
    new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = 4;
    sortedInsert(&a, new_node);
    new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = 3;
    sortedInsert(&a, new_node);
    new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = 30;
    sortedInsert(&a, new_node);
    printf("Linked List before sorting");
    printList(a);
    insertionSort(&a);
    printf("Linked List after sorting");
    printList(a);
    return 0;
}
