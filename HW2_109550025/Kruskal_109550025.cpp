#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#define edge pair<int, int>

using namespace std;

bool sortbysec(const pair<edge,int> &a,const pair<edge,int> &b){
    return (a.second < b.second);
}

class graph{
public:
    int numvt;
    vector<pair<edge,int>> grvec;//graphvector
    graph();
    graph(int);
    void addedge(int,int,int);
    friend int find(int*,int);
    friend void unionset(int*,int,int);
    void kruskal();
};

graph::graph(){

}

graph::graph(int num){
    this->numvt=num;
}


void graph::addedge(int from, int to, int wt){
    if(from<to)
        grvec.push_back(make_pair(edge(from, to),wt));
    else
        grvec.push_back(make_pair(edge(to, from),wt));
}

int find(int *subset, int i){//find parent and return
    int rt; 
    for (rt = i; subset[rt] >= 0; rt = subset[rt]){//get the rt and return
    
    }
    return rt;
}

void unionset(int *sub, int xrt, int yrt){//union the subset
    if(xrt<yrt){
        sub[xrt] += sub[yrt];
        sub[yrt] = xrt;
    }
    else if(xrt>yrt){
        sub[yrt] += sub[xrt];
        sub[xrt] = yrt;
    }
    else{
        sub[xrt] += sub[yrt];
        sub[yrt] = xrt;        
    }
}

void graph::kruskal(){
    int subset[numvt], result[numvt-1];
    for(int i=0; i<numvt; i++){//O(v)
        subset[i]=-1;//all subset set to -1
    }
    sort(grvec.begin(),grvec.end(),sortbysec);//sort from small to large//O(eloge)
    
    int usedeg=0;
    int i=0;

    while(i<grvec.size()){//O(E)
        int x=find(subset,grvec[i].first.first);//find two's rt and check if circle
        int y=find(subset,grvec[i].first.second);

        if(x!=y){
            unionset(subset, x, y);//O(V)
            result[usedeg]=grvec[i].second;
            usedeg++;
        }
        i++;
    }

    int cost=0;
    
    for(int i=0;i<usedeg;i++){
        cost+=result[i];
    }
    cout<<cost;
}

int main() {
    
    int numvt,numeg; 
    cin>>numvt>>numeg;
    int fr, to, wt;
    graph gksk(numvt);
    for(int i=0; i<numeg; i++){
        cin>>fr>>to>>wt;
        gksk.addedge(fr,to,wt);
    }
    
    gksk.kruskal();
    //system("pause");
    return 0;
}