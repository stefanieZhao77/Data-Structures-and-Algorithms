#include<iostream>
using namespace std;


void sort(int a[], int n){
    if(n <=1) return;
    int min_idx;
    for (int i = 0; i < n; i++)
    {
        min_idx=i;
        for (int j = i+1; j < n; j++)
        {
            if(a[j]<a[min_idx]){
                min_idx = j;
            }
        }
        int tmp = a[i];
        a[i] = a[min_idx];
        a[min_idx] = tmp;
        
    }
    
}

int main(){
    int arr[] = {4,6,7,2,3,9};
    sort(arr, 6);
    for (int i = 0; i < 6; i++)
    {
        cout<<arr[i]<<endl;
    }
    
    return 0;
}