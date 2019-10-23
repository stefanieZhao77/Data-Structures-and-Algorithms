//
//  kmp.cpp
//  string
//
//  Created by StefanieZhao on 2019/10/23.
//  Copyright © 2019 StefanieZhao. All rights reserved.
//

#include<iostream>
using namespace std;

void getNext(string pattern, int length, int next[]){
    next[0] = -1;
    int k = -1;
    for(int i =1; i < length;i++){
        while(k !=-1 && pattern[k+1] != pattern[i]){
            k = next[k]; // change k to the last matched place
        }
        if(pattern[k+1] == pattern[i]){
            k++;
        }
        next[i]= k;
    } 
}

int search(string text, string pattern){
    int n = text.size();
    int m = pattern.size();
    int next[m];
    getNext(pattern,m,next);
    int j = 0; 
    for(int i = 0; i <n; i++){
        while(j >= 0 && text[i] != pattern[j]){
            j= next[j-1]+1;
        }
        if(text[i] == pattern[j]){
            j++;
        }
        if(j == m){
            return i - m + 1;
        }
    }

    return -1;
}

int main(){
    string text = "abaaabcd";
    string pattern = "abc";
    int position = search(text, pattern);
    cout << position << endl;
    return 0;
}