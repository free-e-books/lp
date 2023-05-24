void prim(int graph[V][V]){
    int parent[V];
    int key[V];
    bool mstSet[V];

    for(int i = 0; i < V; i++){
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    for(int count = 0; count < V - 1; count++){
        int u = minKey(key, mstSet);
        mstSet[u] = true;
        for(int v = 0; v < V; v++){
            if(graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]){
                parent[v] = u, key[v] = graph[u][v];
            }
        }
        printMST(parent, graph);
    }

    key[0] = 0;
    mstSet[0] = -1;
}