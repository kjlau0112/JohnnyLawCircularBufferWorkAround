#include <stdio.h>
#include <stdlib.h>
 
typedef struct
{
    int *buf;
    int head, tail, numEntry, size;
}queue;
 
void init_q(queue *q, int size)
{
    q->size = size;
    q->buf = (int*)malloc(sizeof(int)*q->size);
    q->numEntry = 0;
    q->head = 0 ;
    q->tail = 0;
}
 
int q_isEmpty(queue *q)
{
    return (q->numEntry == 0);
}
 
int q_isFull(queue *q)
{
    return (q->numEntry == q->size) ;
}
 
void q_destroy(queue *q)
{
    free(q->buf);
}
 
int enqueue(queue* q, int value)
{
    q->buf[q->tail] = value;
    q->tail++;
    
    if (q_isFull(q) == 0)
    {
        q->numEntry++;
    }
 
    if(q->tail > q->size)
    {
        q->tail = 0;
    }
 
    if(q->tail == q->head)
    {
        q->head++;
 
        if(q->head > q->size)
        {
            q->head = 0;
        }
    }
 
    return 0;
}
 
int dequeue(queue *q)
{
    if(q->numEntry == 0)
    {
        return 0;
    }
    else
    {
        int result = q->buf[q->head];
        q->head++;
        q->numEntry--;
        
        if(q->head > q->size)
        {
            q->head = 0;
        }
 
        return result;  
    }
}
 
int main()
{
    queue oQueue;
    
    init_q(&oQueue, 4);
    
    enqueue(&oQueue, 1);
    enqueue(&oQueue, 2);
    enqueue(&oQueue, 3);
    enqueue(&oQueue, 4);
    enqueue(&oQueue, 5);
    // printf("deeeeeee 1 = %d \n", dequeue(&oQueue));
    // printf("deeeeeee 2 = %d \n", dequeue(&oQueue));
    // printf("deeeeeee 3 = %d \n", dequeue(&oQueue));
    // printf("deeeeeee 4 = %d \n", dequeue(&oQueue));
    // enqueue(&oQueue, 6);
    // enqueue(&oQueue, 7);
    // enqueue(&oQueue, 8);
    // printf("deeeeeee 5 = %d \n", dequeue(&oQueue));
    // printf("deeeeeee 6 = %d \n", dequeue(&oQueue));
    // enqueue(&oQueue, 9);
    // enqueue(&oQueue, 10);
    // enqueue(&oQueue, 11);
    // enqueue(&oQueue, 12);
    // enqueue(&oQueue, 13);
    // enqueue(&oQueue, 14);
    // printf("deeeeeee 7 = %d \n", dequeue(&oQueue));
    //     enqueue(&oQueue, 10);
    // enqueue(&oQueue, 15);
    // enqueue(&oQueue, 16);
    // enqueue(&oQueue, 17);
    // enqueue(&oQueue, 18);
    // enqueue(&oQueue, 19);


    
    
    while(q_isEmpty(&oQueue) == 0)
        printf("%d \n", dequeue(&oQueue));
    
    q_destroy(&oQueue);
    
    return 0;
}