#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

struct List
{
    int data;
    struct List *next;
};

typedef struct List *node;

node CreateNode(int value){
    node temp;
    temp = (node)malloc(sizeof(struct List));
    temp->data = value;
    temp->next = NULL;
    return temp;
}

node head;

void Push_back(int value){
    node temp, p;
    temp = CreateNode(value);
    if (head == NULL){
        head = temp;
    }else
    {
        p = head;
        while (p->next != NULL)
        {
            p=p->next;
        }
        p->next = temp;
    }
}

node Pop_back(node head){
    if(head == NULL || head->next == NULL){
        head = NULL;
    }

    node p = head;
    while (p->next->next != NULL)
    {
        p = p->next;
    }

    free(p->next);
    p->next = NULL;

    return head;
    
}

int getData(int index){
    int i = 0;
    node p = head;
    while (p->next != NULL && i!= index)
    {
        p = p->next;
        i++;
    }
    return p->data;
}

typedef struct
{
    void (*Push_back)(int);
    int (*Get_data)(int);
    
} vector;

void Vector_Init(vector *p){
    head = NULL;
    p->Push_back = Push_back;
    p->Get_data = getData;
}

#define Vector(type_name)   \
vector type_name;           \
Vector_Init(&type_name);


int main(int argc, char const *argv[])
{
    
   Vector(arr);

   arr.Push_back(10);
   arr.Push_back(15);
   arr.Push_back(20);
    

    printf("%d\n", arr.Get_data(1));


   
    return 0;
}
