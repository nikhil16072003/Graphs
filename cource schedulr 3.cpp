class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        vector<pair<int,int>> v;
        for (auto& course : courses)
        {
            v.push_back({course[1],course[0]});
        } 
        sort(v.begin(),v.end());
        priority_queue<int> q;

        int count = 0; 
        int sum=0;
        for(auto& [p1,p2] : v)
        {
            if(p1 < p2 )
                continue;

            if(q.empty() || (p1 >= (sum+p2)))
            {
                sum += p2;
                q.push(p2);
            }
            else
            {
               if(q.top()>p2)
                {
                    sum = sum + p2 - q.top();
                    q.pop();
                    q.push(p2);
                }
            }
            count = max<int>(count, q.size());
        }
        return count;
    }
};
