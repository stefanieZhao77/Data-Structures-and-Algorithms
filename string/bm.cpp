//
//  bm.cpp
//  string
//
//  Created by StefanieZhao on 2019/10/22.
//  Copyright © 2019 StefanieZhao. All rights reserved.
//

#include<iostream>
using namespace std;
#define SIZE 256

void generateBC(string pattern, int size, int bc[SIZE]){
    for (int i = 0; i < SIZE; i++){
        bc[i] = -1; //initial list
    }
    for (int i = 0; i < size; i++){
        int ascii =(int) pattern[i];
        bc[ascii] = i ;
    }
};

void generateGS(string pattern, int size, int suffix[], bool prefix[]){
    for (int i = 0; i < size; i++){
        suffix[i] = -1 ;
        prefix[i] = false ;
    }
    for (int i = 0; i < size-1; i++){
        int j = i;
        int k  = 0; //length
        while(j>=0 && pattern[j] == pattern[size-1-k]){
            j--;
            k++;
            suffix[k] = j+1; //+1 because j--
        }
        if (j == -1) prefix[k] = true ;
    };
}

int moveByGS(int pos, int size, int suffix[], bool prefix[]){
    int k = size-1-pos;
    if (suffix[k] !=-1) return pos - suffix[k] +1;
    for (int i = pos+1; i <= size-1;i++){
        if (prefix[size-i] == true){
            return i;
        }
    }
    return size;
}

int search(string text, string pattern){
    int m = pattern.size();
    int n = text.size();
    int bc[SIZE];
    generateBC(pattern,m,bc); // generate hash table for bad chars
    int i = 0; // the first character which matches the text
    int suffix[m];
    bool prefix[m];
    generateGS(pattern,m,suffix,prefix);
    while(i <= n-m){
        int j = m-1;
        while(j >= 0 && pattern[j] == text[i+j]){  // from back to front to check the bad char
            j--;
        }
        if(j<0){ // fully matched
            return i;
        };
        int x = j- bc[(int)text[i+j]];
        int y = 0; 
        if(j < m-1){
            y = moveByGS(j,m,suffix,prefix);
        }

        i = i + std::max(x, y);

    }
    return -1;

};

int main(){
    string text = "abaaabcd";
    string pattern = "abc";
    int position = search(text, pattern);
    cout << position << endl;
    return 0;
}