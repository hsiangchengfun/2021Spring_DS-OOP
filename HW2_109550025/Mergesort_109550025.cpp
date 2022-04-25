#include<ctime>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>


using namespace std;


const int Max = 10001;

void merge(vector<int> &mervec, int start, int mid, int end){

    vector<int> lfspc(mervec.begin()+start, mervec.begin()+mid+1),
                rtspc(mervec.begin()+mid+1, mervec.begin()+end+1);
    //leftspace,rightspace
    lfspc.push_back(Max);
    rtspc.push_back(Max);    

    int lfid = 0, rtid = 0;

    for (int i = start; i <= end; i++) {

        if (lfspc[lfid] <= rtspc[rtid] ) {
            mervec[i] = lfspc[lfid];
            lfid++;
        }
        else{
            mervec[i] = rtspc[rtid];
            rtid++;
        }
    }
}

void mergesort(vector<int> &sortvec, int start, int end){
                                         
    if (start < end) {                   
        int mid = (start+end)/2;         
        mergesort(sortvec, start, mid);  
        mergesort(sortvec, mid+1, end);  
        merge(sortvec, start, mid, end); 
    }
}

void printvec(vector<int> vec,int n){
    for (int i = 0; i < n; i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

int main() {

    int arr[1001]={},n=0,ipt;
    vector<int> vec;
    clock_t start,stop;

    while(cin>>n){
        
        if(n==0) break;
        for(int i=0;i<n;i++){
            cin>>ipt;
            vec.push_back(ipt);
        }
        //start = clock();
        mergesort(vec,0,n-1);
        //stop = clock(); 

        double time=(stop-start);
        printvec(vec,n);
        //cout <<"time : "<< time /CLOCKS_PER_SEC <<endl;
        vec.clear();   
    }
    //system("pause");
    return 0;
}