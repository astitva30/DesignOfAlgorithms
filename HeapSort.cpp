#include<bits/stdc++.h>
using namespace std;

class Array{
    public:
        int a[10];
        int size;
        int length;
};

void display(Array arr){
    // cout<<"Elements are: ";
    for(int i=0;i<arr.length;i++){
        cout<<arr.a[i]<<"\t";
    }
}

void swap(int *x, int *y){
    int temp=*x;
    *x=*y;
    *y=temp;
}

//hepify a subtree with root index i and number of elements n
void Heapify(Array* arr, int n, int i){

    int largest=i;
    int leftChild=2*i+1;
    int rightChild=2*i+2;

    if(leftChild<n && arr->a[leftChild]>arr->a[largest]){
        largest=leftChild;
    }
    if(rightChild<n && arr->a[rightChild]>arr->a[largest]){
        largest=rightChild;
    }
    if(largest!=i){
        swap(&arr->a[largest],&arr->a[i]);
        
        Heapify(arr, n, largest);
    }
}

//main function to do heap sort
void HeapSort(Array* arr, int n){
    //making heap
    for(int i=n/2-1;i>=0;i--){
        Heapify(arr,n,i);
    }
    //now deleting the elements one by one
    for(int i=n-1;i>=0;i--){
        swap(&arr->a[i],&arr->a[0]);

        Heapify(arr,i,0);
    }
}

int main(){
    Array arr1 = {{22, 19, 3, 25, 26, 7 },10,6};
    HeapSort(&arr1,arr1.length);
    cout<<"Sorted Array is: ";
    display(arr1);
}