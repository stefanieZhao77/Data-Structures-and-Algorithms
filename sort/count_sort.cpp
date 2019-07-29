#include<iostream>
using namespace std;

void sort(int a[], int n){
    if (n<=1) return;
    int max =a[0];
    for (int i = 0; i < n; i++)
    {
        if(max<a[i]){
            max = a[i];
        }
    }
    int c[max];
    for (int i = 0; i <= max; i++)
    {
        c[i] = 0;
    }
    
    for (int i = 0; i < n; i++)
    {
        c[a[i]]++;
    }
    for (int i = 1; i <=max; i++)
    {
        c[i] = c[i-1]+c[i];
    }
    int r[n];
     for (int i = 0; i <= max; i++)
    {
        r[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        int index = c[a[i]]-1;
        r[index] = a[i];
        c[a[i]]--;
    }
    for (int i = 0; i < n; i++)
    {
        a[i] = r[i];
    }  
}


int main(){
    int arr[] = {4,6,7,2,3,9,5,7,3,5,2,1,1,0,3};
    sort(arr, 15);
    for (int i = 0; i < 15; i++)
    {
        cout<<arr[i]<<endl;
    }
    
    return 0;
}