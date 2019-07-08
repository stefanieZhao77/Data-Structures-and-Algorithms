//
//  LinkedListQueue.cpp
//  queue
//
//  Created by StefanieZhao on 2019/7/8.
//  Copyright © 2019 StefanieZhao. All rights reserved.
//

#include<iostream>
using namespace std;

struct node
{
    int val;
    node *next;
};

class linkedListQueue
{
private:
    node *head;
    node *tail;
public:
    linkedListQueue();
    ~linkedListQueue();
    bool enqueue(int item);
    int dequeue();
};

linkedListQueue::linkedListQueue()
{
};

linkedListQueue::~linkedListQueue()
{
};

bool linkedListQueue::enqueue(int item){
    node *newNode = new node;
    tail->next = newNode;
    newNode->val = item;
    tail = tail->next;
    return true;
}

int linkedListQueue::dequeue(){
    node *tmp = head;
    head = head->next;
    int res = tmp->val;
    delete tmp;
    return res;
};


int main(){
    
    return 0;
};
