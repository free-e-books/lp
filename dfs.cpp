#include<bits/stdc++.h>
using namespace std;

struct Node{
    int value;

    vector<Node*> neighbors;
    Node(int val): value(val){}
};
int flag = 0;
void dfs(Node* start, vector<bool> &vis, int key){
    if(start == NULL){
        cout << "Not Found" << "\n";
        return;
    }
    vis[start->value] = 1;
    for(auto neighbor : start->neighbors){
        if(neighbor->value == key){
            cout << "Found" << "\n";
            flag = 1;
            return;
        }
        if(!vis[neighbor->value]){
            dfs(neighbor, vis, key);
        }
    }
}

int main(){

    Node* n0 = new Node(0);
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);

    n0->neighbors.push_back(n1);
    n0->neighbors.push_back(n2);
    n1->neighbors.push_back(n3);
    n2->neighbors.push_back(n4);

    vector<bool> vis(5, false);

    int key = 4;
    dfs(n0, vis, key);

    if(flag == 0)
        cout << "Not Found" << "\n";
    
    delete n0;
    delete n1;
    delete n2;
    delete n3;
    delete n4;

    return 0;
}