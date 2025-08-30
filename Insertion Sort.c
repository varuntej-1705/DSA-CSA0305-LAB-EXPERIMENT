#include <stdio.h>
void insertionSort(int arr[], int n){
    for(int i=1;i<n;i++){
        int key=arr[i], j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}
int main(){
    int arr[]={5,3,4,1,2}, n=5;
    insertionSort(arr,n);
    printf("Sorted: ");
    for(int i=0;i<n;i++) printf("%d ",arr[i]);
}
