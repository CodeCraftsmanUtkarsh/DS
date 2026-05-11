class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int>ans;
        int n=nums.size();
        for(int i=0;i<n;i++){
            string s=to_string(nums[i]);
            for(char ch:s){
                ans.push_back(ch-'0');
            }
        }
        return ans;
    }
};