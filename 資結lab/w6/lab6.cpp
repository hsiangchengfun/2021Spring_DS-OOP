#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void trim(string &str){
	
    if(!str.empty()){
        str.erase(0,str.find_first_not_of(" "));
        str.erase(str.find_last_not_of(" ")+1);
    }
    //TODO 
}


void reverse(string &str){
	reverse(str.begin(),str.end());
    //TODO 
}

int main()
{
    string input_line;
  	//input_line=getline();
    getline(cin,input_line);
    trim(input_line);
    reverse(input_line);
    //TODO 
    cout << input_line;
    return 0;
}