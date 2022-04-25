#include <iostream>

using namespace std;

struct Node {
    int val;
    Node *next;
    Node() : val(0), next(nullptr) {}
    Node(int x) : val(x), next(nullptr) {}
};

class LinkedList {
public:
    Node *root;
    int len;
    Node *cur;
    LinkedList() : root(nullptr), len(0) {}
    void push(int);
    void insert(int, int);
    int find(int);
    void remove(int);
    void print();
};

void LinkedList::push(int x){
	cur=root;
    if(root!=nullptr){
        cur->next=new Node;
        cur->next->val=x;
        cur=cur->next;

    }
    else{
        root=new Node;
        root->val=x;
    }
    
    // your implementation
}

void LinkedList::insert(int pos, int x){
	
    cur = root;
    
    
    if(pos>len){
        cout<<"insert fail"<<endl;
        return ;
    }

    
    
    Node *insert=new Node(x);
    if(root!=nullptr){
        for(int i=0;i<pos-1;i++){
            cur=cur->next;
        }

        insert->next=cur->next;
        cur->next=insert;

        for(int i=pos;cur->next!=nullptr;i++){
            cur=cur->next;
        }
        len++;

    }
    else{
        
        root=new Node;
        insert->next=root->next;
        root=insert;
        len++;
    }
    
    // your implementation
}

int LinkedList::find(int x){
	cur=root;
    int j=-1;
    for(int i=0;cur->next!=nullptr;i++){
        if(cur->val==x){
            j=i;
        }
        cur=cur->next;
    }
    if(j!=-1) return j;
    else return -1;
    
    // your implementation
    return 1;
}

void LinkedList::remove(int pos){
	
    cur=root;
    
    
    if(pos < len){
        // cout << "debug\n";
        for(int i=0;i<pos-1;i++){
            cur=cur->next;
            // cout << cur -> val << " ";
        }
        // cout << "-----\n";
        /*Node *temp=cur->next;
        temp=cur->next->next;
        cur=temp;
        //cur->next=cur->next->next;
        //cur=cur->next;
        */
        if (pos == 0) {
            root = (root -> next);
        }
        else if (pos == len - 1) {
            cur -> next = NULL;
        }
        else {
            cur -> next = (cur -> next) -> next;
            // cout << (cur -> next) -> val << "\n";
        }
        len--;

    }
    else{
        
        cout<<"remove fail"<<endl;
    }
    
    // your implementation
}

void LinkedList::print(){
    if(root == nullptr)
        return;

    Node *cur = root;
    while(cur->next != nullptr){
        cout << cur->val << ", ";
        cur = cur->next;
    }
    cout << cur->val << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    LinkedList mylist;
    
    int n, a, b;
    cin >> n;
    char c;
    for(int i = 0; i < n; i++){
        cin >> c;
        if(c == 'p'){
            cin >> a;
            mylist.push(a);
            mylist.len++;
        }else if(c == 'i'){
            cin >> a >> b;
            mylist.insert(a, b);
        }else if(c == 'r'){
            cin >> a;
            mylist.remove(a);
        }else if(c == 'f'){
            cin >> a;
            cout << mylist.find(a) << endl;
        }else if(c == '?'){
            mylist.print();
        }
    }
    return 0;
}