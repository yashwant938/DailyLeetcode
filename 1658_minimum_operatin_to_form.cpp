class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        int targetSum=accumulate(nums.begin(), nums.end(),0)-x;
        if (targetSum<0)
            return -1; 

        int left=0, currSum=0, minOps = INT_MAX;

        for (int right = 0; right < n; ++right) {
            currSum += nums[right];
            
            while (currSum > targetSum) {
                currSum -= nums[left];
                left++;
            }
            
            if (currSum == targetSum) {
                int ops = (n - (right - left + 1));
                minOps = min(minOps, ops);
            }
        }
        
        return minOps == INT_MAX ? -1 : minOps;
    }
};
