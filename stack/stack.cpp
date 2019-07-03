//
//  stack.cpp
//  stack
//
//  Created by StefanieZhao on 2019/7/3.
//  Copyright © 2019 StefanieZhao. All rights reserved.
//

#include<iostream>
using namespace std;

class stack
{
private:
    int *items;
    int count;
    int n;
public:
    stack(int x);
    ~stack();
    bool push(int item);
    int pop();

};

stack::stack(int x)
{
    items = new int[x];
    n = x;
    count = 0;
}

stack::~stack()
{
};
bool stack::push(int item){
    if (count == n)
    {
        return false;
    };
    items[count]=item;
    count++;
    return true;
    
};
int stack::pop(){
    if (count == 0)
    {
        cout<<"this stack is null"<<"\n";
    }
    int tmp = items[count-1];
    count--;
    return tmp;
    
};


int main(){
    stack newstack(5);
    int i =0;
    while (i<5)
    {
        newstack.push(i);
        i++;
    }
    cout<<newstack.pop()<<"\n";
    return 0;
}