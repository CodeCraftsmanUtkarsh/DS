class Solution {
public:
    int minElement(vector<int>& nums) {
        int ans=INT_MAX;
        for(int i=0;i<nums.size();i++){
            int sum=0;
            while(nums[i]>0){
                int n=nums[i]%10;
                sum+=n;
                nums[i]=nums[i]/10;
            }   
            if(sum<ans){
                ans=sum;
            }
        }
        return ans;
    }
};