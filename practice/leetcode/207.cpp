class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
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

        for(int i=0; i<indeg.size(); i++){
            if(indeg[i] == 0){
                q.push(i);
            }
        }

        int res = 0;
        while(!q.empty()){
            auto e = q.front();
            q.pop();
            res++;
            for(auto f: graph[e]){
                if(--indeg[f] == 0){
                    q.push(f);
                }
            }
        }

        if(res != numCourses){
            return false;

        }
        return true;
    }
};