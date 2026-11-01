#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
private:

public:

    int shortestPath(int n, vector<vector<int>> &edges, string labels, int k)
    {
        vector<vector<pair<int,int>>> adj(n);
        
        
        
        for (auto x : edges)
        {
            int u = x[0], v = x[1], w = x[2];
            adj[u].push_back({v,w});
        }
        
        priority_queue <pair<pair<int, int>, int>, vector< pair<pair<int, int>, int>>, greater <pair<pair<int, int>, int> >> pq;
        //Instead of basic dijkstra with 2 states ie current node and adjacent node we now need 3 states *(wrong)current identical left* current consecutive cnt
        
        vector<vector<int>> dist(n,vector<int> (k+1,1e9));
        dist[0][1] = 0;
        // Consider these two paths reaching the same node:
        // Path Distance identical left
        //  Path_A 10 2 
        // Path_B 8 0

        //     Your dist[node] stores only 8,
        //     so Path A gets discarded, even though it has more remaining allowance and might lead to a better final answer.
        
        pq.push({{0,0},1});     //first is distance second is node and third is consecutive cnt

        while (!pq.empty())
        {
            int currdist = pq.top().first.first;
            int node = pq.top().first.second;
            int cnscnt = pq.top().second;
            char ch1 = labels[node];
            pq.pop();

            if(currdist > dist[node][cnscnt]) continue;

            for(auto it: adj[node]) {
                int adjnode = it.first;
                int edgeweight = it.second;
                char ch2 = labels[adjnode];

                // I was using idenleft for everyone correct method is newidenleft but that is also wrong
                // We need consecutive count
                int newcnscnt = 1;
                if(ch2 == ch1) newcnscnt = cnscnt +1;

                if (newcnscnt <= k && currdist + edgeweight < dist[adjnode][newcnscnt])
                {
                    dist[adjnode][newcnscnt] = currdist + edgeweight;
                    pq.push({{dist[adjnode][newcnscnt] ,adjnode},newcnscnt});
                }
            }
        }
        // return dist[n-1];
        int ans = INT_MAX;
        for(auto it: dist[n-1]) {
            ans = min(ans,it);
        }

        return ans == 1e9 ? -1 : ans;
    }
};

int main() {

    

    return 0;
}