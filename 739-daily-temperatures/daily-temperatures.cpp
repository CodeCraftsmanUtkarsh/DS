class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int>ans(n,0);
        stack<pair<int,int>>st;
        st.push({temperatures[0],0});
        int i=1;
        for(int i=1;i<n;i++){
            while(!st.empty() && temperatures[i]>st.top().first){
                ans[st.top().second]=i-st.top().second;
                st.pop();
            }
            st.push({temperatures[i],i});
        }
        return ans;

    }
};