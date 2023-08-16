
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //brute force
        // vector<int> arr;
        // int n=nums.size();
        // for(int i = 0; i<=n - k; i++) {
        //     int maxVal=INT_MIN;
        //     for (int j=i; j<i + k; j++) {
        //         if (nums[j]>maxVal) {
        //             maxVal=nums[j];
        //         }
        //     }
        //     arr.push_back(maxVal);
        // }
        // return arr;

        deque<int>q;
        vector<int>res;
        for(int i=0;i<nums.size();i++){
            while(!q.empty()&&nums[q.back()]<=nums[i]){
                    q.pop_back();
            }
            q.push_back(i);

            if(q.front()==i-k){
                q.pop_front();
            }
            if(i>=k-1){
                res.push_back(nums[q.front()]);
            }
        }
        return res;


    }
};
