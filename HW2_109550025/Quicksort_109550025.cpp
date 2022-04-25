#include <cmath>
#include <ctime>
#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;



void swap(int *a,int *b){
        
    int t=*b;
    *b=*a;
    *a=t;
}

int partition(int arr[],int start,int end){
    
    int pivot=arr[end];
    int i=start-1;
    int j;
    for( j=start;j<end;j++){
       if(arr[j]<=pivot){
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    i++;
    swap(&arr[i],&arr[j]);
    return i;
}


void quicksort(int arr[],int start,int end){
    
    if(start<end){
        int pivot=partition(arr,start,end);
        quicksort(arr,start,pivot-1);
        quicksort(arr,pivot+1,end);
    }
}
void printarr(int arr[],int size){
        
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){

    //clock_t start, stop;
    int aveq,n,pivot,ipt,arr[2000];
    
    while(cin>>n){
        
        if(n==0) break;
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
       // start = clock();
        quicksort(arr,0,n-1);
        //stop = clock(); 

       // double time=(stop-start);
        printarr(arr,n);
        //cout <<"time : "<< time /CLOCKS_PER_SEC <<endl;
        
    }
    
    //system("pause");
    return 0;
}


