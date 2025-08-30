#include <stdio.h>
#define SIZE 10

int hashTable[SIZE];

void init(){
    for(int i=0;i<SIZE;i++) hashTable[i]=-1;
}

void insert(int key){
    int idx=key%SIZE;
    while(hashTable[idx]!=-1) idx=(idx+1)%SIZE;
    hashTable[idx]=key;
}

void display(){
    for(int i=0;i<SIZE;i++)
        printf("%d : %d\n",i,hashTable[i]);
}

int main(){
    int keys[]={23,43,13,27};
    int n=4;
    init();
    for(int i=0;i<n;i++) insert(keys[i]);
    printf("Hash Table:\n");
    display();
}
