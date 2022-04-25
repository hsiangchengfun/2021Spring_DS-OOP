#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;




int main() {
   
   int n,count=0,total=0,k;
   
   
   while(cin>>n){
       vector<int> vec;
       if(n==0) break;
       
       else{
           for(int i=0;i<n;i++){
                cin>>k;
                vec.push_back(k);
           }
           while(1){
                count=0;
                make_heap(vec.begin(),vec.end());
                sort_heap(vec.begin(),vec.end());
                count+=vec.front();
                reverse(vec.begin(),vec.end());
                vec.pop_back();
                
                make_heap(vec.begin(),vec.end());
                sort_heap(vec.begin(),vec.end());
                count+=vec.front();
                reverse(vec.begin(),vec.end());
                vec.pop_back();
                total+=count;
                if(vec.empty()) break;
                vec.push_back(count);
                
           }
           cout<<total<<endl;
           total=0;

       }
   }


   
   /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
