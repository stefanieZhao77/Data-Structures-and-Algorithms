//
//  arrayQueue.cpp
//  queue
//
//  Created by StefanieZhao on 2019/7/8.
//  Copyright © 2019 StefanieZhao. All rights reserved.
//

#include<iostream>
using namespace std;

class arrayQueue
{
private:
    int *items;
    int head;
    int tail;
    int n;
public:
    arrayQueue(int x);
    ~arrayQueue();
    bool enqueue(int item);
    int dequeue();
};

arrayQueue::arrayQueue(int x)
{
    items = new int[x];
    n = x;
};

arrayQueue::~arrayQueue()
{
};
bool arrayQueue::enqueue(int item){
    if(tail == n){
        if(head == 0){
            return false;
        }else
        {
            for (int i = head; i < tail; i++)
            {
                items[i-head] = items[i];
            }
            tail -= head;
            head = 0;
            
        } 
    } 
    items[tail] = item;
    tail++;
    return true;
}

int arrayQueue::dequeue(){
    if(head == tail) return NULL;
    int res = items[head];
    head++;
    return res;
};


int main(){
    
    return 0;
};