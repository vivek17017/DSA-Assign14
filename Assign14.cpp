#include<iostream>
using namespace std;
#define DUPLICATE_ELEMENT 1;

struct node
{
    node* left;
    int item;
    node* right;

};
class BST{
    private:
        static node* root;
    protected:
        void preorderrec(node*);
        void inorderrec(node*);
        void postorderrec(node*);
        node* deleteNode(node*,int);
        
    public:
        BST();
        bool isEmpty();
        void insert(int);
        void preorder();
        void inorder();
        void postorder();
        node* searchItem(int);
        void del(int data);
        ~BST();

       

};



bool BST::isEmpty(){
    return root==nullptr;
}
BST::BST(){
    root=nullptr;
}
void BST::insert(int element){
    node *temp=new node;
    temp->left=nullptr;
    temp->right=nullptr;
    temp->item=element;
    if(isEmpty()){
        root=temp;
    }
    else{
        node* t=root;
        while (t!=nullptr)
        {
            if(t->item==element)
            {
                delete temp;
                throw DUPLICATE_ELEMENT;
            }
            if(t->item>element){
                if(t->left==nullptr){
                    t->left=temp;
                    t=nullptr;
                }
                else{
                    t=t->left;
                }
            }
            else{
                if(t->right==nullptr){
                    t->right=temp;
                    t=nullptr;
                }
                else{
                    t=t->right;
                }
            }
        }
        
    }
}
void BST::preorder(){
    preorderrec(root);
}
void BST::preorderrec(node* temp){
    if(temp!=nullptr)
        {
            cout<<temp->item;
            cout<<endl;
            if(temp->left!=nullptr){
                preorderrec(temp->left);
            }
            if(temp->right!=nullptr){
                preorderrec(temp->right);
            }
            
        }
    
}

void BST::inorder(){
    inorderrec(root);
}
void BST::inorderrec(node* temp){
    if(temp!=nullptr)
    {
        inorderrec(temp->left);
        cout<<temp->item<<endl;
        inorderrec(temp->right);
    }
}
void BST::postorder(){
    postorderrec(root);
}
void BST::postorderrec(node* temp){
    if(temp!=nullptr)
    {
        postorderrec(temp->left);
        postorderrec(temp->right);
        cout<<temp->item;

    }
}
node* BST::searchItem(int element){
    node* temp=root;
    while (temp!=nullptr)
    {
        if(temp->item==element)
        return temp;
        if(element<temp->item){
            temp=temp->left;
        }
        else
        temp=temp->right;
    }
    return nullptr;
    

}

void BST::del(int data){
    root=deleteNode(root,data);
}

node* BST::deleteNode(node* ptr,int data){
    if(ptr==nullptr)
        return nullptr;
    if(ptr->item==data){
        node* pptr=ptr;
        delete ptr;
        
    }
    return ptr;
}

int main(){
    BST b;  
    b.insert(50);
    b.insert(80);
    b.insert(30);
    b.insert(40);
    b.insert(70);
    b.insert(100);
    b.insert(10);
    b.postorder();
    cout<<b.searchItem(30);
}