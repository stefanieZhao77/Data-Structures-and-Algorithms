//
//  double_list.cpp
//  linked_list
//
//  Created by StefanieZhao on 2019/7/2.
//  Copyright © 2019 StefanieZhao. All rights reserved.
//

#include<iostream>
using namespace std;

struct DouNode
{
    int val;
    DouNode *next;
    DouNode *pre;
};

DouNode *start;

void insert(int x){
    DouNode *root = start;
    if(start == NULL){
        DouNode *newNode = new DouNode;
        newNode->val = x;
        newNode->next = NULL;
        newNode->pre = NULL;
        start = newNode;
    }else
    {
        while (root->next)
        {
            root= root->next;
        }
        DouNode *newNode = new DouNode;
        newNode->val = x;
        newNode->next = NULL;
        newNode->pre = root;
        root->next = newNode;
    }
    
};

void remove(int x){
    if (start == NULL)
    {
        cout<<"\n Linked list is empty \n";
        return;
    }else
    {
        DouNode *temp = start;
        while (temp!=NULL && temp->val!=x)
        {
            temp=temp->next;
        }
        temp->pre->next = temp->next;
        temp->next->pre = temp->pre;
        delete temp;
        if(temp == NULL){
            cout<<"not found";
            return;
        }
    }
    
    
};

void show(){
    DouNode *node = start;
    while (node)
    {
        cout<< node->val <<"\t";
        node = node->next;
    }
    
};

int main(){
    int i =0;
    while (i<8)
    {
        insert(i);
        i++;
    }
    remove(1);
    show();
    return 0;
};
