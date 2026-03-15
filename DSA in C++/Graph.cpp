#include <iostream>
#include <bits/stdc++.h>


using namespace std;

// Fails 
// vector <int,int> MakeGraphUsingMatrix(int node, int edge)  {
//     vector<int,int> matrix[node+1][edge+1] = {0};
//     for (int i = 0; i < edge; i++)
//     {
//         int u,v;
//         cin >> u >> v;      //(u,v) cordinates as (node,edge)
//         matrix[u][v].push_back = 1;
//         matrix[v][u].push_back = 1;
//     }
// return matrix;
// }


vector<vector<int>> MakeGraphUsingMatrix (int node, int edge) {
    vector<vector<int>> matrix(node+1, vector<int>(node+1,0));        //vector<int>(nodes + 1, 0)  Creates a single row of size row+1 basically tells to use column size with every element valued 0.
    //node+1 tells us the number of rows we need

    for (int i = 0; i < edge; i++)
    {
        int u,v;
        cin >> u >> v;
        matrix[u][v] = 1;
        matrix[v][u] = 1;
    }
    return matrix;
}
//Adjacency List is better than Matrix method because of no unnecessary usage for storing 0's
void MakeGraphUSingAdjacencyList(int node, int edge, vector<int> adj[]) {
    for (int i = 0; i < edge; i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);    //remove for directed graph
    }
}
/*
Reason for edge over loop
Nodes = 4
Edges = 3
Edges given as input:
1 2
1 3
3 4

*/

vector<int> BreadthFirstSearch(int V, vector<int> adj[]) {
    int vis[V] = {0};   //can use vector int as well like this -> vector<int> vis(V,0);   //VVV IMPORTANT WAY TO INITIALIZE VECTOR
    vis[0] = 1;
    queue <int> q;
    q.push(0);
    vector<int> bfs;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        bfs.push_back(node);
        for(auto it :adj[node]) {     //main node ko liya aur nikaal diya phir jo node hai uska vector ko (eg 1->{3,2,6} ko iterate kara diya jisme saaro ko visited kara ke push and pop kara denge)
        if(!vis[it]) {
            vis[it] = 1;
            q.push(it);
        }
        }
    }
    return bfs;
}
void Dfs (int node, vector<int> adj[],  vector<int> &vis, vector <int> &dfs) {
    vis[node] = 1;
    dfs.push_back(node);
    for (auto it: adj[node])
    {
       if(!vis[it]) {
        Dfs(it,adj,vis,dfs);
       }
    }
    
}
vector<int> DepthFirstSearch (int V, vector <int> adj[]) {
    vector<int> vis (V,0);  //vector initialization baar baar galat ho raha hai
    int start = 0;
    vector<int> dfs;
    Dfs(start,adj,vis,dfs);
    return dfs;
}
/*MIND MAP OF HOW BFS AND DFS WORKS*/
/*
V = 6
Edges:(0 - 1) (0 - 2) (1 - 3) (1 - 4) (2 - 5)

0 → {1, 2}
1 → {0, 3, 4}
2 → {0, 5}
3 → {1}
4 → {1}
5 → {2}

vis[0] = 1;
q.push(0);

_______BFS_______
queue = [0]
vis   = [1,0,0,0,0,0]
bfs   = []

Iteration 1:-
pop 0
add to bfs
bfs = [0]

Neighbors of 0 → {1,2}
Both unvisited → mark + push
queue = [1,2]
vis   = [1,1,1,0,0,0]

Iteration 2:-
pop 1
add to bfs
bfs = [0,1]

Neighbors of 1 → {0,3,4}
0 already visited → skip
3, 4 → mark + push
queue = [2,3,4]
vis   = [1,1,1,1,1,0]

Then do same till all visited 
Final BFS -> 0 1 2 3 4 5


_______DFS_______
Dfs(0)
dfs = [0]
vis = [1,0,0,0,0,0]

Go to first neighbor of 0 → 1
Dfs(1)
dfs = [0,1]
vis = [1,1,0,0,0,0]

Go to first unvisited neighbor of 1 → 3
Dfs(3)
dfs = [0,1,3]
vis = [1,1,0,1,0,0]
3 has no unvisited neighbors
→ return

Then do the same again
*/
/*For better understanding go to Screenshots*/




void dfs (int node, vector <int> &vis, stack <int> &st, vector <int> adj[]) {
    //This function does nothing takes the node make it visited and then takes all the connected node and make them visited as well. The speacial thing is that the node which is at the top means the one that was passed first is pushed last
    vis[node] = 1;
    for (auto it: adj[node])
    {
        if(!vis[it]) dfs(it, vis, st, adj);
    }       
    st.push(node);
}

//TOPO SORT START FROM HERE
vector <int> topoSort(int V, vector <int> adj[]) {
    
    //Making a visited array and stack 
    vector <int> vis (V,0); 
    stack <int> st;

    //Check if the node is visited or not(obviously not visited if starting for first time) and giving it to dfs function if not visited
    for (int i = 0; i < V; i++)
    {
        if(!vis[i]) dfs(i, vis, st, adj);
    }
    //Making an answer array
    vector <int> ans;
    //Keep on pushing array into answer until stack is gone
    //In this there was reversal as well
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;  
}



vector <int> Kahn_Algorithm_Topological_Sort (int V, vector <int> adj[]) {
    //In this we see indegree of the nodes. If the indegree of node is zero it means that there is no edge directed towards them, so we can put them in the queue and the ans array(we won't be disobeying topo sort condition). The node with indegree zero is traversed and the nodes with which it is connected, there indegree is decreased by one. If anyone of these is found to be zero they are also put in ans array and continued

    //This is to assign indegrees to node
    int indegree[V] = {0};  //Can use vector as well
    for (int i = 0; i < V; i++)
    {
        for (auto it: adj[i])
        {
           indegree[it]++;
        }
    }

    //This is to check which nodes have zero indegree and push it into the queue(there will be atleast one due to DAG)
    queue <int> q;
    for (int i = 0; i < V; i++)
    {
        if(indegree[i] == 0) q.push(i);
    }

    //Iterating the node which had zero indegree, reducing the indegree by one of the nodes which were connected to the main node and push the nodes which became zero into the queue
    vector <int> topo;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        topo.push_back(node);

        for (auto it: adj[node])
        {
           indegree[it]--;
           if(indegree[it] == 0) q.push(it);
        }
    }
    return topo;
}

int main() {
    
    return 0;
}