#include<iostream>
using namespace std;

void swap(int a[], int i, int j){
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

int partion(int a[], int low, int high){
    int pivot = a[high];
    int i= low;
    for (int j=low; j < high; j++)
    {
        if(a[j]<pivot){
            swap(a,i,j);
            i++;
        }
    }
    swap(a,i,high);
    return i;
}

void quick_sort(int a[], int low, int high){
    if (low>=high) return;
    int pivot = partion(a, low, high);
    quick_sort(a, low, pivot-1);
    quick_sort(a, pivot+1, high);
}

int main(){
    int arr[] = {4,6,7,2,3,9};
    quick_sort(arr, 0, 5);
    for (int i = 0; i < 6; i++)
    {
        cout<<arr[i]<<endl;
    }
    
    return 0;
}