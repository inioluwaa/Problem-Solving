class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int MaxIndex = 0;
        for (int i(0); i < nums.size(); ++i) {
            if (nums[i] > nums[MaxIndex])
                MaxIndex = i;
        }
        for (int i(0); i < nums.size(); ++i) {
            if (MaxIndex != i && nums[MaxIndex] < 2 * nums[i])
                return -1;
        }
        return MaxIndex;
    }
};