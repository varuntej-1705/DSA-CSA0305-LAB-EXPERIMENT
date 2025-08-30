#include <stdio.h>

void heapify(int arr[], int n, int i){
    int largest=i, l=2*i+1, r=2*i+2;
    if(l<n && arr[l]>arr[largest]) largest=l;
    if(r<n && arr[r]>arr[largest]) largest=r;
    if(largest!=i){
        int t=arr[i]; arr[i]=arr[largest]; arr[largest]=t;
        heapify(arr,n,largest);
    }
}

void heapSort(int arr[], int n){
    for(int i=n/2-1;i>=0;i--) heapify(arr,n,i);
    for(int i=n-1;i>0;i--){
        int t=arr[0]; arr[0]=arr[i]; arr[i]=t;
        heapify(arr,i,0);
    }
}

int main(){
    int arr[]={12,11,13,5,6,7}, n=6;
    heapSort(arr,n);
    printf("Sorted: ");
    for(int i=0;i<n;i++) printf("%d ",arr[i]);
}
