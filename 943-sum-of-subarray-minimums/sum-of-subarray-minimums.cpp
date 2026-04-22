#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        
        vector<int> nse(n, -1); // next smaller element index
        vector<int> pse(n, -1); // previous smaller element index
        
        stack<int> st, st2;

        // Next Smaller Element (right side)
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            if(!st.empty()) {
                nse[i] = st.top();
            }
            st.push(i);
        }

        // Previous Smaller Element (left side)
        for(int i = 0; i < n; i++) {
            while(!st2.empty() && arr[st2.top()] >= arr[i]) {
                st2.pop();
            }
            if(!st2.empty()) {
                pse[i] = st2.top();
            }
            st2.push(i);
        }

        // Calculate result
        long long sum = 0;
        const int MOD = 1e9 + 7;

        for(int i = 0; i < n; i++) {
            int right = (nse[i] == -1) ? (n - i) : (nse[i] - i);
            int left  = (pse[i] == -1) ? (i + 1) : (i - pse[i]);

            long long prod = (1LL * left * right * arr[i]) % MOD;
            sum = (sum + prod) % MOD;
        }

        return (int)sum;
    }
};