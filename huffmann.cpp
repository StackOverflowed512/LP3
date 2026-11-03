#include<bits/stdc++.h>
using namespace std;

struct Node{
    char ch;
    int freq;
    Node* left;
    Node* right;

    Node(char character, int frequency){
        ch=character;
        freq = frequency;

        left = right = nullptr;
    }
};

struct Compare{
     bool operator()(Node* first, Node* second){
         return first->freq > second->freq;
     }   
};


void printCodes(Node* root, string code){
    if(root == nullptr){
        return;
    }

    if(root->left == nullptr && root->right == nullptr){
        if(code == ""){
            code = "0";
        }

        cout<<root->ch<<" : "<<code;
        return;
    }
    printCodes(root->left, code+"0");
    printCodes(root->right, code+"1");
}

int main(){
    int n;
    cout<<"Enter number of characters: ";
    cin>>n;

    vector<int> frequencies(n);
    vector<char> characters(n);
    priority_queue<Node*, vector<Node*>, Compare> pq;

    for(int i = 0;i<n; i++){
        cin>> characters[i]>>frequencies[i];

        pq.push(new Node(characters[i], frequencies[i]));
    }

    while(pq.size() > 1){
        Node* left = pq.top();
        pq.pop();

        Node* right = pq.top();

        pq.pop();

        Node* parent = new Node('$', left->freq + right->freq);
        parent->left = left;
        parent->right = right;
        pq.push(parent);
    }

    cout<<"Codes: "<<endl;
    printCodes(pq.top(), "");
    



    
}
