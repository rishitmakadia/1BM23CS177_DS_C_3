#include <stdio.h>
#include <stdbool.h>

#define MAX 100  

typedef struct 
{
    int s1[MAX];  
    int s2[MAX];  
    int top1;         
    int top2;         
} MyQueue;

// Function to create and initialize a queue
MyQueue myQueueCreate() {
    MyQueue queue;
    queue.top1 = -1;  
    queue.top2 = -1;
    return queue;
}

// Push in s1
void myQueuePush(MyQueue* obj, int x) {
    if ((*obj).top1 == MAX - 1) {
        printf("Queue is full\n");
        // return;
    }
    else
        (*obj).s1[++((*obj).top1)] = x;  
}

int myQueuePop(MyQueue* obj) 
{
    int val;
    // s1 to s2
    if ((*obj).top2 == -1) 
    {
        while ((*obj).top1 != -1) 
        {
            (*obj).s2[++((*obj).top2)] = (*obj).s1[((*obj).top1)--];
        }
        (*obj).top1 = -1;
    }

    // Pop and S2 to back to s1
    if ((*obj).top2 == -1) 
    {
        printf("Queue is empty\n");
        return -1;
    }
    else
    {
        val = (*obj).s2[((*obj).top2)--];
        while ((*obj).top2 != -1)
        {
            (*obj).s1[++((*obj).top1)] = (*obj).s2[((*obj).top2)--];
        }
        (*obj).top2 = -1;
    }
    return val;
}

// Function to peek the front element of the queue
int myQueuePeek(MyQueue* obj) 
{
    int i = (*obj).top1;
    if ((*obj).top2 == -1)
    {
        while ((*obj).top1 != -1) 
        {
            (*obj).s2[++((*obj).top2)] = (*obj).s1[((*obj).top1)--];
        }
        (*obj).top1 = i;
    }

    if ((*obj).top2 == -1) 
    {
        printf("Queue is empty\n");
        return -1;
    }
    else
    {
        while ((*obj).top2 != -1)
        {
            return (*obj).s2[(*obj).top2];
        }
        (*obj).top2 = -1;
    }
}

// Queue Status
bool myQueueEmpty(MyQueue* obj) {
    return ((*obj).top1 == -1 && (*obj).top2 == -1);
}


// void myQueueFree(MyQueue* obj) {
//     // No memory to free since we are not using dynamic allocation
// }

