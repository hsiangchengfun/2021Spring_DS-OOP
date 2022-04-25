#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Student {
public:
	Student( ) { }
	string generate_address(){
        
        string retn="";
        retn += "1001 University Road, Hsinchu, Taiwan 300, ROC, dorm ";
        retn += dormitory + ", (";
        retn += ID + ") ";
        retn += first_name + " " + last_name;
        return retn;
    	//TODO        
    }

    void setFirstName(string _firstname){
        first_name=_firstname;
    }
    void setLastName(string _lastname){
        last_name=_lastname;
    }
    void setDormitory(string _dormitory){
        dormitory=_dormitory;
    }
    void setID(string _ID){
        ID=_ID;
    }
    
  	//Please implement the remain class
private:
	string first_name;
    string last_name;
	string dormitory;
	string ID;
};


int main() {
  	Student mStudent;
    /* Enter your code here. Read input from STDIN */
    
    string first_name,last_name,dormitory,ID;
    
    cin>>first_name>>last_name>>dormitory>>ID;
    
  	mStudent.setFirstName(first_name);
    mStudent.setLastName(last_name);
    mStudent.setDormitory(dormitory);
    mStudent.setID(ID);
    
    cout << mStudent.generate_address() << endl;
    return 0;
}