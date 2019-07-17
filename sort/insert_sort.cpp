#include<iostream>
using namespace std;


void sort(int a[], int n){
    if(n <=1) return;
    for (int i = 0; i < n; i++)
    {
        int val = a[i];
        int j = i-1;
        while (j>=0)
        {
            if(a[j]>val){
                a[j+1] = a[j]; 
            }else
            {
                break;
            }
            
            j--;
        }
        a[j+1]=val; 
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