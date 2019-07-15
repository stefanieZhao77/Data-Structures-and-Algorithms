#include<iostream>
using namespace std;

void sort(int a[], int n){
    if(n <=1) return;
    for (int i = 0; i < n; i++)
    {
        bool flag = false;
        for (int j = 0; j < n-i-1; j++)
        {
            if(a[j]>a[j+1]){
                int tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
                flag = true;
            }
        }
        if(!flag) break;
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