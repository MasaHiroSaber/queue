#include "stdio.h"
#include "stdlib.h"
#include "time.h"

#define MAX_LENGTH 100
typedef struct Sequential_queues
{
    int sq_data[MAX_LENGTH];
    int leader;
    int tail;
} sq;

void createQueue(sq *p)
{
    p->leader = 0;
    p->tail = 0;
}

int queueEmpty(sq *p)
{
    if (p->leader == p->tail) return 1;
    else return 0;
}


int queueFull(sq *p)
{
    if (p->tail == MAX_LENGTH) return 1;
    else return 0;
}

void enterData(sq *p, int data)
{
    if (queueFull(p)) return;
    p->sq_data[p->tail] = data;
    p->tail++;
}

void deleteData(sq *p, int *data)
{
    if (queueEmpty(p)) return;
    *data = p->sq_data[p->leader];
    p->leader++;
}

void printQueue(sq *p)
{
    int i = p->leader;
    while (i < p->tail) {
        printf("%d ", p->sq_data[i]);
        i++;
    }
    printf("\n");
}

int main()
{
    sq sq1;
    createQueue(&sq1);

    srand(time(0));


    for (int i = 0; i <= 10; i++) {
        int value = 1 + rand() % 10;
        enterData(&sq1, value);
        printf("Enter data%d\n", value);
        printQueue(&sq1);
    }

    for (int i = 0; i <= 5; i++) {
        int value;
        deleteData(&sq1, &value);
        printf("Delete data%d\n", value);
        printQueue(&sq1);
    }

    int value;
    do {
        printf("ENTER A NUMBER (1-10)/ENTER 0 TO QUIT:");
        scanf_s("%d", &value);
        enterData(&sq1, value);
        printf("Enter data%d\n", value);
        printQueue(&sq1);
    } while (value);
    //printQueue(&sq1);
}