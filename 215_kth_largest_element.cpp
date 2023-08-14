#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int count = 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = n; i >= 1; i--) {
            count++;
            if (count == k) {
                return nums[i - 1];
            }
        }
        return -1;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {3, 2, 1, 5, 6, 4}; // Example input
    int k = 2; // Example value of k

    int result = solution.findKthLargest(nums, k);
    cout << "The " << k << "th largest element is: " << result << endl;

    return 0;
}
