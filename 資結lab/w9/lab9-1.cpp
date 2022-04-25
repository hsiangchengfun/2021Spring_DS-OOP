#include <iostream>
using namespace std;
 
class BST
{
    int data;
    BST *left, *right;
 
public:
    
    BST();
 
    
    BST(int);
 
    
    BST* Insert(BST*, int);
 
    
    void Inorder(BST*);
};
 

BST ::BST()
    : data(0), left(NULL), right(NULL)
{
}
 

BST ::BST(int value)
{
    data = value;
    left = right = NULL;
}

BST* BST ::Insert(BST* root, int value)
{
    if (!root)
    {
        return new BST(value);
    }
 
   
    if (value > root->data)
    {
        root->right = Insert(root->right, value);
    }
    else
    {
        root->left = Insert(root->left, value);
    }
 
    return root;
}
 

void BST ::Inorder(BST* root)
{
    if (!root) {
        return;
    }
    
    Inorder(root->left);
    
    Inorder(root->right);
    cout << root->data << endl;
}
 
int main()
{
    BST b, *root = NULL;
    int num;
    cin>>num;
    root = b.Insert(root, num);

    while(cin>>num){
        b.Insert(root,num);
    }


 
    b.Inorder(root);
    return 0;
}