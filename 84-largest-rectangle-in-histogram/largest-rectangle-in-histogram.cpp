class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        vector<int> nse(n, -1);
        vector<int> pse(n, -1);

        // NSE
        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(!st.empty()){
                nse[i] = st.top();
            } else {
                nse[i] = n;
            }
            st.push(i);
        }

        // clear stack
        while(!st.empty()) st.pop();

        // PSE
        for(int i = 0; i < n; i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(!st.empty()){
                pse[i] = st.top();
            } else {
                pse[i] = -1;
            }
            st.push(i);
        }

        int ans = 0;

        for(int i = 0; i < n; i++){
            int width = nse[i] - pse[i] - 1;
            ans = max(ans, width * heights[i]);
        }

        return ans;
    }
};