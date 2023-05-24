#include<bits/stdc++.h>
using namespace std;

struct Node{
    int value;

    vector<Node*> neighbors;
    Node(int val): value(val){}
};

string bfs(Node* start, vector<bool> &vis, int key){
    if(start == NULL) return "Not Found";
    queue<Node*> q;
    q.push(start);

    while(!q.empty()){
        Node* curr = q.front();
        q.pop();
        if(curr->value == key) return "Found";
        for(Node* neighbor : curr->neighbors){
            if(!vis[neighbor->value]){
                vis[neighbor->value] = true;
                q.push(neighbor);
            }
        }
    }
    return bfs(NULL, vis, key);
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

    int key = 9;
    string res = bfs(n0, vis, key);
    cout << res << "\n";

    delete n0;
    delete n1;
    delete n2;
    delete n3;
    delete n4;

    return 0;
}