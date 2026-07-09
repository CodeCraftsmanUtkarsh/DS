class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<bool>ans;
        vector<int>comp(n);
        int id=0;
        comp[0]=id;
        for(int i=1;i<n;i++){
            if(abs(nums[i]-nums[i-1])>maxDiff){
                id++;
            }
            comp[i]=id;
        }
        for(auto& q:queries){
            ans.push_back(comp[q[0]]==comp[q[1]]);
        }
        return ans;
    }
};