//
//  circleQueue.cpp
//  queue
//
//  Created by StefanieZhao on 2019/7/8.
//  Copyright © 2019 StefanieZhao. All rights reserved.
//

#include<iostream>
using namespace std;

class circleQueue
{
private:
    int *items;
    int n, head, tail, size;
public:
    circleQueue(int x);
    ~circleQueue();
    bool enqueue(int item);
    int dequeue();
};

circleQueue::circleQueue(int x)
{
    items = new int[x];
    n = x;
};

circleQueue::~circleQueue()
{
};

bool circleQueue::enqueue(int item){
    if (size == n) return false;
    items[tail] = item;
    if(size != n && tail == n-1) {
        tail = 0;
    }else
    {
        tail = (tail+1)%n;
    }
    size++;
    return true;
}

int circleQueue::dequeue(){
    if(head == tail) return NULL;
    int res = items[head];
    head = (head +1)%n;
    size--;
    return res;
};

int main(){
    return 0;
}