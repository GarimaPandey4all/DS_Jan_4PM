#include <stdio.h>
#include <stdlib.h>
#define size 10

struct Dataset {
    int data;
    int key;
};

struct Dataset *hashArray[size];
struct Dataset *dummyItem;
struct Dataset *item;

int hashFunction(int key)
{
    return key % size; // return hashindex
}

void insert(int key, int data)
{
    struct Dataset *item;

    item = (struct Dataset *)malloc(sizeof(struct Dataset));

    item->data = data;
    item->key = key;

    int hashIndex = hashFunction(key);

    //Linear Probing: Collision Resolution
    while(hashArray[hashIndex] != NULL && hashArray[hashIndex]->key != -1)
    {
        ++hashIndex;

        hashIndex %= size; // correct index
    }

    hashArray[hashIndex] = item;

}

struct Dataset *search(int key)
{
    int hashIndex;

    hashIndex = hashFunction(key);

    while(hashArray[hashIndex] != NULL)
    {
        if(hashArray[hashIndex]->key == key)
        {
            return hashArray[hashIndex];
        }

        ++hashIndex;
        hashIndex %= size;
    }

    return NULL;
};

struct Dataset *delete(struct Dataset *item)
{
    struct Dataset *temp;
    int key;

    key = item->key;

    int hashIndex = hashFunction(key);

    while(hashArray[hashIndex] != NULL)
    {
        if(hashArray[hashIndex]->key == key)
        {
            temp = hashArray[hashIndex];
            hashArray[hashIndex] = dummyItem; // deleted item , data = -1, key = -1;
            return temp;
        }
    }
};

void display()
{
    int i;

    for(i = 0; i < size; i++)
    {
        if(hashArray[i] != NULL)
        {
            printf("(%d, %d)", hashArray[i]->key, hashArray[i]->data);
        }
        else {
            printf("__");
        }
    }

    printf("\n");
}

int main()
{
    dummyItem = (struct Dataset *)malloc(sizeof(struct Dataset));

    dummyItem->key = -1;
    dummyItem->data = -1;

    insert(1, 20);
    insert(3, 10);
    insert(4, 30);
    insert(2, 70);
    insert(5, 90);
    insert(7, 80);

    display();

    item = search(3);

    if(item != NULL)
    {
        printf("\nElement is found %d", item->data);
    }
    else {
        printf("\nElement is not found");
    }

    delete(item);

    item = search(3);

    if(item != NULL)
    {
        printf("\nElement is found %d\n", item->data);
    }
    else {
        printf("\nElement is not found\n");
    }

    display();

    return 0;
}
