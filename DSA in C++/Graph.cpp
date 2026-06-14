#include <iostream>
#include <bits/stdc++.h>


using namespace std;


vector<vector<int>> MakeGraphUsingMatrix (int node, int edge) {
    vector<vector<int>> matrix(node+1, vector<int>(node+1,0));        
    //vector<int>(nodes + 1, 0)  Tells us to make a vector of size node+1 and initialize all the values with 0. This is for the columns
    //vector<vector<int>> matrix(node+1, vector<int>(node+1,0));  Tells us to make a vector of size node+1 and initialize all the values with 0. This is for the rows as well as columns because we are making a vector of vector. So we are making a 2D vector of size node+1 x node+1 and initializing all the values with 0. 

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
vector<vector<int>> MakeGraphUsingAdjacencyList(int node, int edge) {
    vector<vector<int>> adj(node + 1);
    for (int i = 0; i < edge; i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);    //remove for directed graph
    }
    return adj;
}

// Converts an adjacency matrix to adjacency list.
// Works with both weighted unweighted matrices.
vector<vector<int>> ConvertMatrixToAdjacencyList(vector<vector<int>> &matrix) {
    int n = matrix.size();
    vector<vector<int>> adj(n);

    // This file mostly uses 1-based node indexing, so index 0 is skipped.
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (matrix[i][j] != 0) {
                adj[i].push_back(j);
            }
        }
    }

    return adj;
}

/*
Steps of bfs 
S1-> In function we need a adjacency list or matrix along with number of nodes ie V
S2-> We need a queue and 2 vector vis and bfs
S3 -> We need to loop form 1 to V
S4-> If visited then continue otherwise not visited then mark it as visited and push it into the queue
S5-> Loop until queue is empty, in the loop save the front, pop it, push into bfs,
S6-> then check for all the adjacent nodes of the popped node and if they are not visited then we will mark them as visited and push them into the queue
*/

vector<int> BreadthFirstSearchUsingMatrix(int V, vector<vector<int>> &matrix) {
    //If V is not given then we can find it by matrix.size() because the number of rows will be equal to the number of nodes or matrix[0].size() because the number of columns will also be equal to the number of nodes

    vector<int> vis(V + 1, 0);
    queue<int> q;
    vector<int> bfs;

    for (int i = 1; i <= V; i++) {
        if (vis[i] == 1) continue;

        vis[i] = 1;
        q.push(i);

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            bfs.push_back(node);

            for (int adjNode = 1; adjNode <= V; adjNode++) {
                if (matrix[node][adjNode] == 1 && !vis[adjNode]) {
                    vis[adjNode] = 1;
                    q.push(adjNode);
                }
            }
        }
    }

    return bfs;
}


/*Steps of DFS
S1-> In function we need a adjacency list or matrix along with number of nodes ie V
S2-> We need 2 vector vis and dfs
S3 -> We need to loop form 1 to V
S4-> If visited then leave it otherwise not visited then mark it as visited and run helper function for that node
S5-> In helper function  mark the node as visited and push into dfs, then check all the adjacent nodes of the node and if not visited then we will mark them as visited and run helper function for those nodes as well.
*/
void DepthFirstSearchMatrixHelper(int node, vector<vector<int>> &matrix, int V, vector<int> &vis, vector<int> &dfs) {
    vis[node] = 1;
    dfs.push_back(node);

    for (int adjNode = 1; adjNode <= V; adjNode++) {
        if (matrix[node][adjNode] == 1 && !vis[adjNode]) {
            DepthFirstSearchMatrixHelper(adjNode, matrix, V, vis, dfs);
        }
    }
}

vector<int> DepthFirstSearchUsingMatrix(int V, vector<vector<int>> &matrix) {
    vector<int> vis(V + 1, 0);
    vector<int> dfs;

    for (int i = 1; i <= V; i++) {
        if (!vis[i]) {
            DepthFirstSearchMatrixHelper(i, matrix, V, vis, dfs);
        }
    }

    return dfs;
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

vector<int> BreadthFirstSearchUsingAdjacencyList(int V, vector<vector<int>> &adj) {
    vector<int> vis(V + 1, 0);   //can use vector int as well like this -> vector<int> vis(V,0);   //VVV IMPORTANT WAY TO INITIALIZE VECTOR
    vis[1] = 1;
    queue <int> q;
    q.push(1);
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



void DepthFirstSearchAdjacencyListHelper (int node, vector<vector<int>> &adj, int V, vector<int> &vis, vector <int> &dfs) {
    vis[node] = 1;
    dfs.push_back(node);
    for (auto it: adj[node])
    {
       if(!vis[it]) {
        DepthFirstSearchAdjacencyListHelper(it, adj, V, vis, dfs);
       }
    }
    
}
vector<int> DepthFirstSearchUsingAdjacencyList(int V, vector<vector<int>> &adj) {
    vector<int> vis(V + 1, 0);
    vector<int> dfs;

    for(int i = 1; i <= V; i++) {
        if(!vis[i]) {
            DepthFirstSearchAdjacencyListHelper(i, adj,V,vis, dfs);
        }
    }
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



class IS_GRAPH_BIPARTITE {
private:
    bool dfs(int node, int col, vector<int> & color, vector<vector<int>>& graph) {
        color[node] = col;

        for (auto adjnode: graph[node])
        {
           if(color[adjnode] == -1) {
            if(dfs(adjnode, !col, color, graph) == false) return false;
           }
           else if (color[adjnode] == col) {
            return false;
           }
        }
        return true;
        }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> color (V,-1);

        for (int i = 0; i < V; i++)
        {
            if(color[i] == -1) {
                if(dfs(i,0,color,graph) == false) return false;
            }
        }
        return true;
    }
};


//TOPO SORT START FROM HERE
//What happens in dfs method is we do basic dfs but we keep on pushing on the node into stack but after recursion so that the deepest is into the stack first and at lowest and that will be the childrens while the parent's stack push is last due to 
//Not preferred as this does not take care of cycles
void TopoSortDfs(int node, vector<vector<int>> &adj, vector<int> &vis, stack<int> &st) {
    vis[node] = 1;
    
    for (int nextNode : adj[node])
    {
        if (!vis[nextNode]) {
            TopoSortDfs(nextNode, adj, vis, st);
        }
    }
    st.push(node);
    return;      //In dfs traversal stores as soon as visited but in topo sort -> Process after all children
}

vector <int> topoSort(int V, vector<vector<int>> &adj) {
    
    //Making a visited array and stack 
    vector <int> vis (V + 1,0); 
    stack <int> st;
    
    //Check if the node is visited or not(obviously not visited if starting for first time) and giving it to dfs function if not visited
    for (int i = 1; i <= V; i++)
    {
        if(!vis[i]) TopoSortDfs(i, adj, vis, st);
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


//Preferred as this does take care of cycles naturally
vector <int> Kahn_Algorithm_Topological_Sort (int V, vector<vector<int>> &adj) {
    //In this we see indegree of the nodes. If the indegree of node is zero it means that there is no edge directed towards them, so we can put them in the queue and the ans array(we won't be disobeying topo sort condition). The node with indegree zero is traversed and the nodes with which it is connected, there indegree is decreased by one. If anyone of these is found to be zero they are also put in ans array and continued
    
    //This is to assign indegrees to node
    vector<int> indegree(V + 1, 0);  //Can use vector as well
    for (int i = 1; i <= V; i++)
    {
        for (auto it: adj[i])
        {
            indegree[it]++;
        }
    }

    //This is to check which nodes have zero indegree and push it into the queue(there will be atleast one due to DAG)
    queue <int> q;
    for (int i = 1; i <= V; i++)
    {
        if(indegree[i] == 0) q.push(i);
    }

    //Take the queue, save front, pop and put into ans. Then iterate the node, reducing the indegree of nodes connected to parent node by one push the nodes whose indegree became zero, into the queue
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

//In this we are creating two vectors vis and dfsvis 
//dfsvis is to solve the problem which arises in undirected cycle detect algo by checking if the already visited node is visited in the same dfsvis cycle or not
//for that we are just adding an else if that if dfsvis[node] is already visited then we are visiting that same node in same recursion branch and
// we are making it unvisited again if no cycle is detected
class DETECT_CYCLE_IN_DIRECTED_GRAPH_USING_DFS {
    private:
    bool checkCycle(int node, vector<vector<int>> &adj, vector<int> &vis, vector<int> &dfsvis) {
        vis[node]=1;
        dfsvis[node]=1;

        for (auto it: adj[node])
        {
           if(!vis[it]) {
                if(checkCycle(it, adj, vis, dfsvis))  {
                    return true;
                }
           } 
           else if(dfsvis[it]) return true;
        }
        dfsvis[node] = 0;
        return false;
    }
    public:
    bool DetectCycleusingDFS(vector<vector<int>> &adj, int V) {
        vector<int> vis (V+1,0);
        vector<int> dfsvis (V+1,0);

        for (int i = 1; i <= V; i++)
        {
            if(!vis[i]) {
                if(checkCycle(i,adj,vis,dfsvis)) {
                    return true;
                }
            }
        }
    return false;   
    }
};


//In UNDIRECTED it is very simple visiting any node which is not the parent and is already visited then yes it is cycle
class DETECT_CYCLE_IN_UNDIRECTED_GRAPH_USING_BFS {
    private:
        bool detectbfs(int src, vector<vector<int>> &matrix, vector<int>& vis) {
                vis[src] = 1;
                queue<pair<int,int>> q;
                q.push({src,-1});
                while(!q.empty()) {
                    int node = q.front().first;
                    int parent = q.front().second;
                    q.pop();
    
                    for(auto adjnode : matrix[node]) {
                        if(!vis[adjnode]) {
                        vis[adjnode] =1; 
                        q.push({adjnode,node});
                        }
                        else if(parent != adjnode) return true;
                    }
                }
                return false;
            }

    public:
        bool DetectCycleUsingBFS(vector<vector<int>>& matrix) {
            int V = matrix.size();
            vector<int> vis(V,0);
            for(int i = 0; i<V; i++) {
                if(!vis[i]) {
                    if (detectbfs(i,matrix,vis)) return true;
                }
            }
            return false;
        }
    };



class DETECT_CYCLE_IN_UNDIRECTED_GRAPH_USING_DFS {
    private:
    bool detectdfs(int node, int parent,vector<int> &vis,vector<vector<int>> adj) {
        vis[node] = 1;
        for (auto adjnode: adj[node])
        {
           if(!vis[adjnode]) {
            if(detectdfs(adjnode,node,vis,adj)) return true;
           }
           else if(adjnode != parent) return true;
        }
    }

    public:
    bool DetectCycleUsingDFS(vector<vector<int>> matrix, int V) {
        int n = matrix.size();
    
        vector<vector<int>>adj(n);
        adj = ConvertMatrixToAdjacencyList(matrix);
    
        vector<int> vis(V,0);
    
        for (int i = 0; i < V; i++)
        {
            if(!vis[i]) {
                if(detectdfs(i,-1,vis,adj)) return true;
            }
        }
        return false;
    }
};





vector<int> ShortestPathInUndirectedGraphofUnitWeightUsingBFS (vector<vector<int>> &adj,int N, int M, int src) {
    vector<int> dist(N,1e9);
    dist[src] = 0;
    queue<int> q;
    q.push(src);
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        for(auto it: adj[node]) {
            if(dist[node] + 1 <dist[it]) {
                dist[it] = 1 + dist[node];
                q.push(it);
            }
        }
    }
    vector<int> ans(N,-1);
    for (int i = 0; i < N; i++)
    {
        if(dist[i] != INT_MAX) ans[i] = dist[i];
    }
    return ans;
}



class COURSE_SCHEDULE {
private:
    bool func(int course, vector<vector<int>>& adj,vector<int>& vis, vector<int>& dfsvis) {
        vis[course] = 1;
        dfsvis[course] = 1;

        for (auto it: adj[course])
        {
           if(!vis[it]) {
            //    if(func(it,numCourses,adj,vis,dfsvis)) return false;
               if(!func(it,adj,vis,dfsvis)) return false;    //cycle found
           }
           else if(dfsvis[it]) return false;    //back edge cycle found
        }
        dfsvis[course] = 0;
        return true;    //no cycle
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //way to think is by creating a direction and if it is a cycle then work cannot be done

        vector<vector<int>> adj(numCourses);

        for(auto &p : prerequisites) adj[p[1]].push_back(p[0]);

        vector<int> vis(numCourses, 0);
        vector<int> dfsvis(numCourses, 0);

        for (int i = 0; i < numCourses; i++)
        {
            if(!vis[i]) {
                if(!func(i,adj,vis,dfsvis)) return false;
            }
        }
        return true; 
    }
};



class REVERSING_GRAPH_IN_AND_OUT_DEGREE {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> adj(n);
        vector<int> indegree(n,0);

        // convert to adjacency list and reverse path as original graph gives us outdegree
        //To convert i -> it to it -> i
        for (int i = 0; i < n; i++)
        {
           for (auto it: graph[i])
           {
               adj[it].push_back(i);
               indegree[i]++;
           }
        }
    }
};



class SURROUND_REGION {
private:
    void dfs(vector<vector<char>>& board, vector<vector<int>> &vis, int delrow[], int delcol[], int row, int col) {
        vis[row][col] = 1;

        int m = board.size();
        int n = board[0].size();

        // int delrow[] = {-1,0,1,0};
        // int delcol[] = {0,1,0,-1};   putting it here is memory wastage as for every dfs new this is created

        for (int i = 0; i < 4; i++)
        {
            int r = row + delrow[i];
            int c = col + delcol[i];
 
            if(r >= 0 && r <= m && c >= 0 && c < n && !vis[r][c] && board[r][c] == 'O') dfs(board,vis,delrow,delcol, r, c);
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};

        vector<vector<int>> vis (m, vector <int>(n,0));

        for (int j = 0; j < n; j++)
        {
            if(!vis[0][j] && board[0][j] == 'O') dfs(board, vis,delrow,delcol,0,j);
            if(!vis[m-1][j] && board[m-1][j] == 'O') dfs(board, vis,delrow,delcol,m-1,j);
        }
        
        for (int i = 1; i < m-1; i++)
        {
            if(!vis[i][0] && board[i][0] == 'O') dfs(board, vis,delrow,delcol,i,0);
            if(!vis[i][n-1] && board[i][n-1] == 'O') dfs(board, vis,delrow,delcol,i,n-1);
        }

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(board[i][j] == 'O' && !vis[i][j])
                board[i][j] = 'X';
            }
        }
    }
};
int main() {
    
    return 0;
}