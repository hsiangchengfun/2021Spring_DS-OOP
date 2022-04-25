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
};

class edge{
public:
    vertex* from;
    vertex *to;
    int wt;
};

class graph{
public:
    graph();
    graph(int,int);
    int numvt,numeg;
    vertex *vt;
    edge *eg;
    bool bellmanford(graph*,int);
};

graph::graph(){

}

graph::graph(int numvt,int numeg){
    this->numvt=numvt;
    this->numeg=numeg;
    this->vt=new vertex[this->numvt];
    this->eg=new edge[this->numeg];
    
}

bool graph::bellmanford(graph *bmfgph,int start){
    
    (bmfgph->vt+start)->dis=0;

    int detected=0;
    for(int v=0;v<numvt-1;v++){//O(V)
        for(int i=0;i<bmfgph->numeg;i++){//O(E)
            edge* cur=(bmfgph->eg+i);
            if(cur->from->dis + cur->wt < cur->to->dis && cur->from->dis!=infinity){
                cur->to->dis=cur->from->dis + cur->wt;
                cur->to->parent=cur->from;
            }
        }
    }

    for(int i=0;i<numeg;i++){//O(E)
        edge* cur=(bmfgph->eg+i);
        if(cur->from->dis + cur->wt < cur->to->dis && cur->from->dis!=infinity){
            detected=1;
            break;
        }
    }

    if(detected==1) return true;
    else return false;

}

int main(){

    int numvt,numeg,start,end; 
    cin>>numvt>>numeg;
    cin>>start>>end;

    graph* bmfgph=new graph(numvt,numeg);

    int from,to,wt;
    for(int i=0;i<numeg;i++){
        cin>>from>>to>>wt;
        (bmfgph->eg+i)->from=(bmfgph->vt+from);
        (bmfgph->eg+i)->to=(bmfgph->vt+to);
        (bmfgph->eg+i)->wt=wt;
    }
    bool u=bmfgph->bellmanford(bmfgph,start);

    if(u) cout<<"Negative loop detected!";
    else{
        int cost=(bmfgph->vt+end)->dis;
        cout<<cost;
    }
   
    //system("pause");
    return 0;
}
