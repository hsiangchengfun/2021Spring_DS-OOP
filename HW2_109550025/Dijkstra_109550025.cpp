#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

const int infinity=100000000;

class vertex{
public:
    int dis=infinity;
    vertex* parent;
    vector<pair<vertex*,int>> adjlist;//pair<to,weight>
};

bool mycompare(vertex* vt1,vertex* vt2){
    return vt1->dis>vt2->dis;
}

class graph{
public:
    graph();
    graph(int);
    int numvt;
    vertex *vt;
    void dijkstra(int);
};

graph::graph(){

}

graph::graph(int numvt){
    this->numvt=numvt;
    this->vt=new vertex[this->numvt];
    
}

void graph::dijkstra(int start){
    (this->vt+start)->dis=0;

    vector<vertex*> minheap;
    for(int i=0;i<numvt;i++){//O(V)
        minheap.push_back(vt+i);
    }
    while(!minheap.empty()){//O(V)

        make_heap(minheap.begin(),minheap.end(),mycompare);
        pop_heap(minheap.begin(),minheap.end(),mycompare);
        vertex* minvt=minheap.back();//O(V)

        if(minvt->adjlist.empty())continue;

        for(int i=0;i<minvt->adjlist.size();i++){//O(V)
            pair<vertex*,int> cur = minvt->adjlist[i];

            if(minvt->dis + cur.second < cur.first->dis && minvt->dis!=infinity){
                cur.first->dis=minvt->dis+cur.second;
                cur.first->parent=cur.first;
            }
        }
        minheap.pop_back();
    }
}

int main(){

    int numvt,numeg,start,end; 
    cin>>numvt>>numeg;
    cin>>start>>end;
    graph* dksgph=new graph(numvt);

    int from,to,wt;
    for(int i=0;i<numeg;i++){
        cin>>from>>to>>wt;
        (dksgph->vt+from)->adjlist.push_back(make_pair(dksgph->vt+to,wt));
    }

    dksgph->dijkstra(start);
    int cost=(dksgph->vt+end)->dis;
    cout<<cost;
   
    //system("pause");
    return 0;
}
