#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
/*
void reverse(vector &vec){
	reverse(vec.begin(),vec.end());
    //TODO 
}*/


int main() {
  	vector<int> v;
    int n,num;
    char query;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>query;
        if(query=='a'){
            cin>>num;
            v.push_back(num);
        }
        else if(query=='e'){
            cin>>num;
            for(int j=0;j<v.size();j++){
                if(v[j]==num){
                    v.erase(v.begin()+j);
                }
            }
        }
        else if(query=='r'){
            reverse(v.begin(),v.end());
        }
        else if(query=='d'){
            v.pop_back();
        }
        else if(query=='s'){
            cout<<v.size()<<" ";
        }
        else if(query=='p'){
            for(int j=0;j<v.size();j++){
                cout<<v[j]<<" ";
            }
        }



    }
    
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}