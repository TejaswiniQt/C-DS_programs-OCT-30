/* Implementation of stack using queue*/

#include <stdio.h>
#include <stdlib.h>
#define N 5 

int queue1[N];
int queue2[N];
int front1=-1, rear1=-1, front2=-1, rear2=-1;


void pop();
void push();
void enqueue1();
void enqueue2(int data);
int dequeue1();
int dequeue2();
void display();

int main()
{
    int option,data;
    while(1)
    {
        printf("Enter the option:\n1.push\n2.pop\n3.display\n4.exit\n");
        scanf("%d",&option);
        switch(option)
        {
            case 1: /*printf("Enter the data:");
            scanf("%d",&data);*/
            push();
            break;
            case 2: pop();
            break;
            case 3: display();
            break;
            case 4: exit(0);
        }
    }
    return 0;
}

void push()
{
    enqueue1();
}

void pop()
{
    int data = dequeue2();
    if(data > -1)
    printf("The popped element is: %d\n",data);
}

void enqueue1()
{
    int i,data;
    if(rear2 == N-1)
    printf("Stack is full\n");
    else
    {
        printf("Enter the data:");
        scanf("%d",&data);
        ++front1;
        ++rear1;
        queue1[rear1] = data;
        
        for(i=0; i<=rear2; i++)
        {
            data = dequeue2();
            queue1[++rear1] = data;
        }
        
        for(i=0; i<=rear1; i++)
        {
            data = dequeue1();
            enqueue2(data);
        }
        
    }
}

void enqueue2(int data)
{
    if(front2 == -1 && rear2 == -1)
    {
        ++front2;
        ++rear2;
        queue2[rear2] = data;
    }
    else
    {
        queue2[++rear2] = data;
    }
}

int dequeue1()
{
    int data;
    if(front1 == rear1)
    {
        data = queue1[front1];
        front1 = -1;
        rear1 = -1;
        return data;
    }
    else
    {
        data = queue1[front1];
        front1++;
        return data;
    }
}

int dequeue2()
{
    int data;
    if(front2 == -1 && rear2 == -1)
    {
        printf("Stack is empty\n");
        return -1;
    }
    else
    {
        if(front2 == rear2)
        {
            data = queue2[front2];
            front2=rear2=-1;
            return data;
        }
        else
        {
            data = queue2[front2++];
            return data;
        }
    }   
}

void display()
{
    int i;
    if(front2 == -1 && rear2 == -1)
    printf("Stack is empty\n");
    else
    {
        printf("Stack contains: ");
        for(i=front2; i<=rear2; i++)
        printf("%d ",queue2[i]);
    }
    printf("\n");
}
