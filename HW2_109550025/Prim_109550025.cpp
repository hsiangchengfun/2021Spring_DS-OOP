#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<queue>
#define intpr pair<int,int>

using namespace std;
const int infinite=10001;
class graph{
private:
    int numvt;
    vector<intpr> *adjmtx;//first==vertex,second==weight

public:
    graph();
    graph(int numvt);
    void addedge(int from,int to,int wt);
    void prim();

};
graph::graph(int numvt){
    this->numvt=numvt;
    adjmtx=new vector<intpr>[numvt];
}
void graph::addedge(int from,int to,int wt){
    adjmtx[from].push_back(make_pair(to,wt));
    adjmtx[to].push_back(make_pair(from,wt));
}
void graph::prim(){
    priority_queue<intpr,vector<intpr>,greater<intpr>> myqueue;//myqueue.first is key,second is vertex
    int start=0;
    vector<int> key(numvt,infinite);
    vector<bool> used(numvt,false);

    myqueue.push(make_pair(0,start));//O(1)
    key[start]=0;

    while(!myqueue.empty()){//O(v)
        int go=myqueue.top().second;
        myqueue.pop();

        if(used[go]==true) continue;
        used[go]=true;
        vector<intpr>::iterator get;

        for(get=adjmtx[go].begin();get!=adjmtx[go].end();++get){//O(v)
            
            int vt=(*get).first;
            int wt=(*get).second;

            if(used[vt]==false && wt<key[vt]){//O(1)
                used[vt]==true;
                key[vt]=wt;
                myqueue.push(make_pair(key[vt],vt));//O(logv)
            }
        }
    }
    int cost=0;
    for(int i=0;i<numvt;i++){
        cost+=key[i];
    }
    cout<<cost;
}
int main() {

    int numvt,numeg; 
    cin>>numvt>>numeg;
    
    graph gpm(numvt);
    for(int i=0; i<numeg; i++){
        int fr, to, wt;
        cin>>fr>>to>>wt;
        gpm.addedge(fr,to,wt);
    }
    
    gpm.prim();
    //system("pause");
    return 0;
    
  
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}