#include<stdio.h>
#include<stdlib.h>
#define max 50

struct Dequeue {
    int data[max];
    int f,r,count;
}dq;

void initialize() {
    dq.f=-1;
    dq.r=-1;
    dq.count=0;
}

int isFull() {
    if (dq.count==max) {
        return 1;
    } else {
        return 0;
    }
}

int isEmpty() {
    if (dq.count==0) {
        return 1;
    } else {
        return 0;
    }
}

void insert_front(int ele) {
    if (isFull()) {
        printf("Overflow!\n");
    } else if (isEmpty()) {
        dq.f=0;
        dq.r=0;
        dq.data[dq.f]=ele;
        dq.count++;
    } else {
        dq.f=(dq.f-1+max)%max;
        dq.data[dq.f]=ele;
        dq.count++;
    }
}

void insert_rear(int ele) {
    if (isFull()) {
        printf("Overflow!\n");
    } else if (isEmpty()) {
        dq.f=0;
        dq.r=0;
        dq.data[dq.r]=ele;
        dq.count++;
    } else {
        dq.r=(dq.r+1)%max;
        dq.data[dq.r]=ele;
        dq.count++;
    }
}

int remove_front() {
    int x;
    if (isEmpty()) {
        printf("Underflow!\n");
    } else if (dq.count==1) {
        x=dq.data[dq.f];
        dq.f=-1;
        dq.r=-1;
        dq.count=0;
        return x;
    } else {
        x=dq.data[dq.f];
        dq.f=(dq.f+1)%max;
        dq.count--;
        return x;
    }
}

int remove_rear() {
    int x;
    if (isEmpty()) {
        printf("Underflow!\n");
    } else if (dq.count==1) {
        x=dq.data[dq.r];
        dq.f=-1;
        dq.r=-1;
        dq.count=0;
        return x;
    } else {
        x=dq.data[dq.r];
        dq.r=(dq.r-1+max)%max;
        dq.count--;
        return x;
    }
}

void display() {
    int i;
    for (i = dq.f; i != dq.r; i=(i+1)%max) {
        printf("%d ",dq.data[i]);
    }
    printf("%d\n", dq.data[i]);
}

void main() {
    int ele,x,opt;
    initialize();
    while (1) {
        printf("Enter choice:\n1.Insert Front\t2.Insert Rear\t3.Remove Front\t4.Remove Rear\t5.Display\t6.Exit\n");
        scanf("%d",&opt);
        switch (opt) {
            case 1 : printf("Enter Element: ");
                     scanf("%d",&ele);
                     insert_front(ele);
                     break;
            case 2 : printf("Enter Element: ");
                     scanf("%d",&ele);
                     insert_rear(ele);
                     break;
            case 3 : remove_front();
                     break;
            case 4 : remove_rear();
                     break;
            case 5 : display();
                     break;
            case 6 : exit(0);
        default: printf("Invalid\n");
        }
    }
}