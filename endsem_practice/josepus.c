#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// Function to create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to perform the Josephus elimination
void josephus(int n, int m)
{

    struct Node *head = NULL;
    struct Node *temp = NULL;
    struct Node *prev = NULL;

    for (int i = 1; i <= n; i++)
    {
        temp = createNode(i);
        if (head == NULL)
        {
            head = temp;
        }
        else
        {
            prev->next = temp;
        }
        prev = temp;
    }
    temp->next = head;

    struct Node *current = head;
    struct Node *toDelete = NULL;

    while (n > 1)
    {
        for (int i = 0; i < m - 2; i++)
        {
            current = current->next;
        }
        toDelete = current->next;
        current->next = toDelete->next;

        printf("%d ", toDelete->data);
        free(toDelete);
        current = current->next;
        n--;
    }
}

int main()
{
    int n, m;

    // Read the number of students and the skip count
    printf("Enter the number of persons in the circle: ");
    scanf("%d", &n);

    printf("Enter the number of persons to be skipped: ");
    scanf("%d", &m);

    // Call the josephus function to determine the order and the leader
    josephus(n, m);

    return 0;
}
