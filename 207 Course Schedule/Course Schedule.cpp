class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        unordered_set<int> temp;
        vector<unordered_set<int>> graph(numCourses,temp);
        vector<int> degree(numCourses,0);
        for(int i = 0;i<prerequisites.size();i++)
        {
            graph[prerequisites[i].second].insert(prerequisites[i].first);
            degree[prerequisites[i].first]+=1;
        }
        
        for(int i = 0;i<numCourses-1;i++)
        {
            int j;
            unordered_set<int>::iterator it;
            for(j = 0;j<numCourses;j++)
            {
                if(degree[j] == 0)
                {
                    degree[j] = -1;
                    break;
                }
            }
            if(j == numCourses)
                return false;
            for(it = graph[j].begin(); it != graph[j].end();it++)
            {
                degree[*it]--;
            }
        }
        return true;
    }
};