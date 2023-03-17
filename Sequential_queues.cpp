#include <iostream>

#define MAX_LENGTH 100
typedef struct Sequential_queues
{
    int data[MAX_LENGTH];
    Sequential_queues *leader;
    Sequential_queues *tail;
} sq;

//初始化顺序队列