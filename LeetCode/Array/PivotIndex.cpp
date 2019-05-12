class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0, leftsum = 0;
        for (auto i : nums) sum += i;
        for (int i(0); i < nums.size(); ++i) {
            if (leftsum == sum - nums[i] - leftsum)
                return i;
            leftsum += nums[i];
        }
        return -1;
    }
};