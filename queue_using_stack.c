/*Implementation of queue using stack*/

#include <stdio.h>
#include <stdlib.h>
#define N 5

int stack1[N];
int stack2[N];
int top1 = -1, top2 = -1,count = 0;

void enqueue(int data);
void dequeue();
void display();
void push1(int data);
void push2(int data);
int pop1();
int pop2();

int main()
{
    int option, data;
    while(1)
    {
        printf("Enter the option:\n1.enqueue\n2.deueue\n3.display\n4.exit\n");
        scanf("%d",&option);
        switch(option)
        {
            case 1: printf("Enter the data: ");
            scanf("%d",&data);
            enqueue(data);
            break;
            case 2: dequeue();
            break;
            case 3:display();
            break;
            case 4: exit(0);
        }
    }
    return 0;
}

void enqueue(int data)
{
    push1(data);
}

void dequeue()
{
    int i,data;
    if(top1 == -1)
    printf("Queue is empty\n");
    else
    {
        for(i=0; i<count; i++)
        {
            data = pop1();
            push2(data);
        }
        data = pop2();
        printf("The dequeued element is: %d\n",data);
        count--;
        for(i=0; i<count; i++)
        {
            data = pop2();
            stack1[++top1] = data;
        }
    }
    
}

void push1(int data)
{
    if(top1 == N-1)
    printf("Queue is full\n");
    else
    {
        stack1[++top1] = data;
        count++;
    }
}

void push2(int data)
{
    stack2[++top2] = data;
}

int pop1()
{
    int data = stack1[top1--];
    return data;
}

int pop2()
{
    int data = stack2[top2--];
    return data;
}

void display()
{
    int i;
    if(top1 == -1)
    printf("Queue is empty");
    else
    {
        printf("Queue contains: ");
        for(i=0; i<count; i++)
        printf("%d ",stack1[i]);
    }
    printf("\n");
}
