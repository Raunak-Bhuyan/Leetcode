#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isCycle(vector<vector<int>>& adj, vector<int>& vis, int id) {
        if (vis[id] == 1)
            return true;
        if (vis[id] == 0) {
            vis[id] = 1;
            for (auto edge : adj[id]) {
                if (isCycle(adj, vis, edge))
                    return true;
            }
        }
        vis[id] = 2;
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> vis(numCourses, 0);
        
        for (auto it : prerequisites) {
            adj[it[1]].push_back(it[0]);
        }
        
        for (int i = 0; i < numCourses; i++) {
            if (isCycle(adj, vis, i))
                return false;
        }
        
        return true;
    }
};


