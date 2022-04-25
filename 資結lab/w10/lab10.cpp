#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int num, cnct, visit_num = 0, cur;
    cin >> num;
    stack<int> S;
    vector<bool> visited(num, false);
    vector<int> vec[num]; 
    
    for(int i = 0; i < num; i++){
        for(int j = 0; j < num; j++){
            cin >> cnct;
            if(cnct == 1){
                vec[i].push_back(j);
            }
        }
    }
    
    while(visit_num != num){
        for(int i = 0; i < num; i++){
            if(visited[i] == false){
                S.push(i);
                break;
            }
        }
        
        while(!S.empty()){
            cur = S.top();
            S.pop();
            if(visited[cur] == false){
                visited[cur] = true;
                visit_num++;
                cout << cur << " ";
                for(int i = vec[cur].size(); i > 0; i--){
                    S.push(vec[cur][i-1]);
                }
            }
        }
        
        cout << endl;
    }
    return 0;
}