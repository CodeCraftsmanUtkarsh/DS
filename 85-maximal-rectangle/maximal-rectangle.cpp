class Solution {
public:
    int area(vector<int>&hist){
        int n=hist.size();
        if(n==0){
            return 0;
        }
        int maxArea=0;
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && hist[st.top()]>=hist[i]){
                int nse=i;
                int element=st.top();
                st.pop();
                int pse=(st.empty())?-1:st.top();
                maxArea=max(maxArea,(nse-pse-1)*hist[element]);
            }
            st.push(i);
        }
        while(!st.empty()){
            int nse=n;
            int element=st.top();
            st.pop();
            int pse=(st.empty())?-1:st.top();
            maxArea=max(maxArea,(nse-pse-1)*hist[element]);
        }
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    vector<int> hist(n, 0);
    int maxi = 0;

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(matrix[i][j] == '1') {
                hist[j]++;
            } else {
                hist[j] = 0; 
            }
        }
        maxi = max(maxi, area(hist));  
    }

    return maxi;
}
};