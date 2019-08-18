#include<iostream>
using namespace std;

int bsearch(int arr[],int n, int val){
    int high = n-1;
    int low = 0;
    while (low<=high)
    {
        int mid = (high+low)/2;
        if(arr[mid] == val){
            return mid;
        }else if (arr[mid]>val)
        {
            high = mid-1;
        }else if(arr[mid]<val){
            low = mid+1;
        }
        
    }
    
    return -1;
};

int bsearchL(int arr[], int low, int high, int val){
    if(low>high) return -1;
    int mid = low + ((high - low)>>1);
    if(arr[mid] == val){
        return mid;
    }else if(arr[mid]<val)
    {
        return bsearchL(arr, mid+1, high, val);
    }else
    {
        return bsearchL(arr, low, mid-1, val);    
    }
     
};
// search the first repeated element
int bsearch_first(int arr[], int n, int val){
    int low =0;
    int high = n-1;
    while (low<=high)
    {
        int mid = low + ((high-low)>>1);
        if(arr[mid]> val){
            high = mid-1;
        }else if(arr[mid]<val){
            low = mid+1;
        }else{
            if((arr[mid]-1!=val) || (mid ==0)) return mid;
            else high = mid-1;
        }
    }
    return -1;
}
// search the first value which is higher than the goal value
int bsearchFirstHigh(int arr[], int n, int val){
    int low =0;
    int high = n-1;
    while (low <= high)
    {
        int mid = low + ((high-low)>>1);
        if(arr[mid]>=val){
            if ((arr[mid-1]<val) || (mid == 0)) return mid;
            else high = mid-1;
        }else
        {
            low = mid+1;
        }
        
    }
    
    return -1;
}

int main(){
    int arr[] = {2,3,4,5,5,5,5,5,6,7,8,9,12,16,19,25,38};
    int n = sizeof(arr)/sizeof(arr[0]);
    int pos = bsearch(arr,n,4);
    int posL = bsearchL(arr, 0, n-1, 19);
    int posfirst = bsearch_first(arr,n,5);
    int firsthigh = bsearchFirstHigh(arr, n, 17);
    cout<<pos<<endl;
    cout<<posL<< endl;
    cout<<posfirst<<endl;  
    cout<<firsthigh<<endl;  
    return 0;
};