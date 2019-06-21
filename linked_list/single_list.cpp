//
//  single_list.cpp
//  linked_list
//
//  Created by StefanieZhao on 2019/6/14.
//  Copyright © 2019 StefanieZhao. All rights reserved.
//

#include<iostream>
using namespace std;

struct nodeList{
    int val;
    nodeList *next;
};

nodeList *start;

void insert(int x){
    nodeList *root = start;
    if(start == NULL){
        nodeList *newNode = new nodeList;
        newNode->val = x;
        newNode->next = NULL;
        start = newNode; // actual root
    }else{
        while (root->next) {
            root=root->next;
        }
        nodeList *newNode = new nodeList;
        root->next = newNode;
        newNode->val = x;
        newNode->next = NULL;
    }
};

void remove(int x){
    if (start == NULL) {
        cout<<"\n Linked list is empty \n";
        return;
    }else{
        nodeList *temp = start, *node = start;
        while (temp!=NULL && temp->val!=x) {
            node = temp;
            temp = temp->next;
        }
        node->next=temp->next;
        delete temp;
        if(temp == NULL){
            cout<<"not found";
            return;
        }
    }
};

void replace(int x, int val){
    if (start == NULL) {
        cout<<"\n Linked list is empty \n";
        return;
    }else{
        nodeList *node = start;
        while (node !=NULL && node->val!=x) {
            node = node->next;
        }
        if (node==NULL) {
            cout<<"not found";
            return;
        }
        node->val = val;
        
    }
};

void search(int x){
    nodeList *node = start;
    bool found = false;
    int count = 0;
    while (node) {
        if(node->val==x){
            found = true;
            cout<<"\n Found the number in position:" + std::to_string(count);
            break;
        }else{
            node = node->next;
        }
        count++;
    }
    if(!found){
        cout<<"No item.";
    }
};

void show(){
    nodeList *node = start;
    while (node) {
        cout<< node->val <<"\t";
        node = node->next;
    }
};

int main(){
    int choice, x, value;
    
    
    do {
        cout<<"\n1. Insert";
        cout<<"\n2. Delete";
        cout<<"\n3. Search";
        cout<<"\n4. Print";
        cout<<"\n5. Replace";
        cout<<"\n0. Exit";
        cout<<"\n\nEnter you choice : ";
        cin>>choice;
        switch (choice)
        {
            case 1 :     cout<<"\nEnter the element to be inserted : ";
                cin>>x;;
                insert(x);    break;
            case 2 :     cout<<"\nEnter the element to be removed : ";
                cin>>x;
                remove(x);     break;
            case 3 :     cout<<"\nEnter the element to be searched : ";
                cin>>x;
                search(x);     break;
            case 4 :     show();
                cout<<"\n";    break;
            case 5 :     cout<<"\nEnter the element to be replaced and Enter the value to be replaced : " ;
                cin>>x>>value;
                replace(x, value);  break;
        }
    } while (choice!=0);
    return 0;
}

