class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);

        for(auto e: prerequisites){
            graph[e[1]].push_back(e[0]);
        }

        queue<int> q;
        vector<int> indeg(numCourses, 0);

        for(auto e: graph){
            for(auto f: e){
                indeg[f]++;
            }
        }

        for(int i=0; i<numCourses; i++){
            if(indeg[i] == 0){
                q.push(i);
            }
        }

        vector<int> topo;
        while(!q.empty()){
            auto e = q.front();
            q.pop();
            topo.push_back(e);
            for(auto f: graph[e]){
                if(--indeg[f] == 0){
                    q.push(f);
                }
            }
        }

        if(topo.size() != numCourses){
            return {};
        } else {
            return topo;
        }

    }
};