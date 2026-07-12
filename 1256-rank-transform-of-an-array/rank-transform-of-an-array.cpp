class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        unordered_map<int,int>mp;
        vector<int>ans=arr;
        int rank=1;
        int n=arr.size();
        sort(ans.begin(),ans.end());
        for(int i=0;i<n;i++){
            if(i>0 && ans[i]==ans[i-1]){
                continue;
            }
            mp[ans[i]]=rank++;
        }
        for(int i=0;i<n;i++){
            ans[i]=mp[arr[i]];
        }
        return ans;
    }
};