//
//  linked_list_stack.cpp
//  stack
//
//  Created by StefanieZhao on 2019/7/3.
//  Copyright © 2019 StefanieZhao. All rights reserved.
//

#include<iostream>
using namespace std;

struct node
{
    int val;
    node *next;
};


class linked_list_stack
{
private:
    node *start;    
public:
    linked_list_stack();
    ~linked_list_stack(); 
    void push(int x);
    int pop();
};

linked_list_stack::linked_list_stack()
{  
}

linked_list_stack::~linked_list_stack()
{
}
void linked_list_stack::push(int x){
    node *newNode = new node;
    newNode->val = x;
    newNode->next = start;
    start= newNode;  
};

int linked_list_stack::pop(){
    int val = start->val;
    if(start == NULL){
        cout<<"no item"<<"\n";
    }else
    {
        node *n = start;
        start = start->next;
        delete n;
    }
    return val;
};

int main(){
    linked_list_stack newstack;
    int i =0;
    while (i<5)
    {
        newstack.push(i);
        i++;
    }
    cout<<newstack.pop()<<"\n";
    return 0;
}