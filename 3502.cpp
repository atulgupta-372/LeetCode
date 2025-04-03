class Solution {
    public:
        vector<int> minCosts(vector<int>& cost) {
            vector<int>ans;
            ans.push_back(cost[0]);
            int mini=cost[0];
            for(int i=1;i<cost.size();i++){
                mini=min(mini,cost[i]);
                ans.push_back(mini);
            }
            return ans;
        }
    };