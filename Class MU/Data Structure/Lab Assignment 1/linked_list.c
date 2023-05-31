#include <stdio.h>
#include <stdlib.h>

struct List
{
    int value;
    struct List *key;
};

struct List *createList(int val)
{
    struct List *root = malloc(sizeof(struct List));
    root->value = val;
    root->key = NULL;
};

void insert(struct List *root, int val)
{
    root->key = createList(val);
}

void printKoro(struct List *root)
{
    if (root != NULL)
    {
        printf("%d ", root->value);
        printKoro(root->key);
    }
}

void deleteKoro(struct List *root)
{
    if (root->key != NULL)
    {
        // printf("%d ", root->value);
        root->key = root;
        deleteKoro(root->key);
    }
}

int main()
{
    struct List *head = createList(1);
    insert(head, 2);
    insert(head->key, 3);

    struct List *temp = head;
    while (head->key->key != NULL)
    {
        head = head->key;
    }
    head->key = NULL;

    //head = head->key;

    printKoro(temp);
}