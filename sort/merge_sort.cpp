#include<iostream>
#include<climits>
using namespace std;


void merge_list(int a[],int low,int high,int mid){
    int leftList[mid-low+2];
    int rightList[high-mid+1];
    for(int i=0;i<=mid-low;i++){
        leftList[i] = a[low+i];
    }
    leftList[mid-low+1] = INT_MAX;
    for (int i = 0; i < high-mid; i++)
    {
        rightList[i] = a[mid+1+i];
    }
    rightList[high-mid] = INT_MAX;
    int i =0;
    int j =0;
    int k= low;
    while (k<=high)
    {
        if(leftList[i]<=rightList[j]){
            a[k++] = leftList[i++];
        }else{
            a[k++] = rightList[j++];
        }
    }
};

void merge_sort(int a[], int low, int high){
    if(low >= high) return;
    int mid = low+(high-low)/2;
    merge_sort(a, low, mid);
    merge_sort(a, mid+1, high);
    
    merge_list(a, low, high, mid);
};


int main(){
    int arr[] = {4,6,7,2,3,9};
    merge_sort(arr, 0, 5);
    for (int i = 0; i < 6; i++)
    {
        cout<<arr[i]<<endl;
    }
    
    return 0;
}