class Solution{
    public:
        vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites){
            vector<int> adj(numCourses);
            for(auto it: prerequisites){
                adj[it[1]].push_back(it[0]);
            }

            int inDegree[numCourses];
            for(int i=0; i<numCourses; i++){
                inDegree[i] = 0;
            }
            for(int i=0; i<numCourses; i++){
                for(auto it: adj[i]){
                    inDegree[it]++;
                }
            }
            queue<int> q;
            for(int i=0; i<numCourses; i++){
                if(inDegree[i] == 0){
                    q.push(i);
                }
            }
            vector<int> ans;
            while(!q.empty()){
                int node = q.front();
                q.pop();
                for(auto it: adj[node]){
                    inDegree[it]--;
                    if(inDegree[it] == 0){
                        q.push(it);
                    }
                }
            }
            if(ans.size() == numCourses) return ans;
            else return {};
        } 
};