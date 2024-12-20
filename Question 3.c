#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Qnode
{
    int data;
    struct Qnode *next;
}qnode;

typedef struct
{
    qnode *front, *rear;
}queue;

typedef struct
{
    queue *q1;
}MyStack;

queue *createQueue();
void enQueue(queue *q, int data);
int deQueue(queue *q);
void show(queue *q);
bool isEmpty(queue *q);
MyStack *myStackCreate();
void myStackPush(MyStack* obj, int x);
int myStackPop(MyStack* obj);
int myStackTop(MyStack* obj);
bool myStackEmpty(MyStack* obj);
void myStackFree(MyStack* obj);

queue *createQueue()
{
    queue *q = malloc(sizeof(queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}
void enQueue(queue *q, int data)
{
    qnode *new_q = malloc(sizeof(qnode));
    new_q->data = data;
    new_q->next = NULL;

    if(q->rear == NULL)
    {
        q->front = new_q;
        q->rear = new_q;
        return;
    }
    q->rear->next = new_q;
    q->rear = new_q;
}
int deQueue(queue *q)
{
    if(q->front == NULL)
        return -9999;

    int rmv = q->front->data;
    qnode *tmp = q->front;
    q->front = q->front->next;

    if(q->front == NULL)
        q->rear = NULL;
    free(tmp);
    return rmv;
}
void show(queue *q)
{
    if(q->front == NULL)
        return;
    while(q->front != NULL)
    {
        printf("%d ", q->front->data);
        q->front = q->front->next;
    }
    printf("\n");
}
bool isEmpty(queue *q)
{
    return (q->front == NULL && q->rear == NULL);
}

MyStack *myStackCreate()
{
    MyStack *stack = malloc(sizeof(MyStack));
    stack->q1 = createQueue();
    return stack;
}

void myStackPush(MyStack* obj, int x)
{
    if(isEmpty(obj->q1))
    {
        enQueue(obj->q1, x);
        return;
    }
    enQueue(obj->q1, x);
    qnode *tmp = obj->q1->rear;
    while(obj->q1->front != tmp)
    {
        enQueue(obj->q1, deQueue(obj->q1));
    }
}

int myStackPop(MyStack* obj)
{
    if(isEmpty(obj->q1))
        return -9999;
    return deQueue(obj->q1);
}

int myStackTop(MyStack* obj)
{
    if(isEmpty(obj->q1))
        return -9999;
    return obj->q1->front->data;
}

bool myStackEmpty(MyStack* obj)
{
    return isEmpty(obj->q1);
}

void myStackFree(MyStack* obj)
{
    free(obj);
}
