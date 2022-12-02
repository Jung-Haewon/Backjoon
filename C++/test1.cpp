#include <bits/stdc++.h>
using namespace std;
enum Command{
    ADD,
    SUB,
    DEPTH,
    LEAF,
    QUIT
};
struct node{
    string data;
    node* left;
    node* right;
};
map<string,int> command_map;
node* root = nullptr;

void add(){
    string value;
    cin>>value;
    if(root==nullptr){
        root = new node{value, nullptr, nullptr};
        return;
    }
    node* dest = root;
    while(true){
        if(value>dest->data){
            if(dest->right != nullptr) dest = (dest->right);
            else{
                dest->right = new node{value, nullptr, nullptr};
                break;
            }
        }
        else if(value==dest->data) return;
        else{
            if(dest->left != nullptr) dest = (dest->left);
            else{
                dest->left = new node{value, nullptr, nullptr};
                break;
            }
        }
    }
}

void recursive_sub(node* n){
    node* before = n;
    node* replacement = n;
    bool direction = true;
    if(n->left==nullptr){
        replacement = replacement->right;
        while(replacement->left!=nullptr){
            before = replacement;
            replacement = replacement->left;
            direction = false;
        }
    }
    else{
        replacement = replacement->left;
        direction = false;
        while(replacement->right!=nullptr){
            before = replacement;
            replacement = replacement->right;
            direction = true;
        }
    }
    if(replacement->right==nullptr&&replacement->left==nullptr){
        n->data = replacement->data;
        if(direction) before->right = nullptr;
        else before->left = nullptr;
        delete replacement;
        return;
    }
    else{
        string temp = n->data;
        n->data = replacement->data;
        replacement->data = temp;
        recursive_sub(replacement);
    }
    return;
}

void sub(){
    string value;
    cin>>value;
    if(root==nullptr) return;
    node* dest = root;
    vector<bool> direction; //true = right, false = left
    while(dest!= nullptr){
        if(value>dest->data){
            dest = dest->right;
            direction.push_back(true);
        }
        else if(value==dest->data)
            break;
        else{
            dest = dest->left;
            direction.push_back(false);
        }
    }
    if(dest==nullptr) return;
    node* before = root;
    if(dest->right==nullptr&&dest->left==nullptr){
        for(int i = 0;i<(int)direction.size()-1;i++){
            if(direction[i])    before = before->right;
            else                before = before->left;
        }
        if(dest == root) root = nullptr;
        else if(direction.back()) before->right = nullptr;
        else before->left = nullptr;
        delete dest;
        return;
    }
    recursive_sub(dest);
}

int recursive_depth(node* n,int depth, int goal){
    int sum = 0;
    if(depth==goal){
        cout<<n->data<<" ";
        return 1;
    }
    if(n->left!=nullptr) sum += recursive_depth(n->left,depth+1,goal);
    if(n->right!=nullptr) sum += recursive_depth(n->right,depth+1,goal);
    return sum;
}

void depth(){
    int input;
    cin>>input;
    if(root==nullptr){
        cout<<"NO"<<endl;
        return;
    }
    if(recursive_depth(root, 1, input)==0) cout<<"NO"<<endl;
    else cout<<endl;
}

void recursive_leaf(node* n){
    if(n==nullptr) return;
    if(n->right==nullptr&&n->left==nullptr){
        cout<<n->data<<" ";
    }
    if(n->left!=nullptr) recursive_leaf(n->left);
    if(n->right!=nullptr) recursive_leaf(n->right);
}

void input(){
    string cmd;
    while(true){
    cin>>cmd;
    switch(command_map[cmd]){
    case Command::ADD:
        add();
        break;
    case Command::SUB:
        sub();
        break;
    case Command::DEPTH:
        depth();
        break;
    case Command::LEAF:
        recursive_leaf(root);
        cout<<endl;
        break;
    case Command::QUIT:
        return;
    }
    }
}

int main(){
    command_map["+"] = Command::ADD;
    command_map["-"] = Command::SUB;
    command_map["depth"] = Command::DEPTH;
    command_map["leaf"] = Command::LEAF;
    command_map["quit"] = Command::QUIT;
    input();
}