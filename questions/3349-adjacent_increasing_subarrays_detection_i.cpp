class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int i = 0, j = 0, size = 1, subarrays = 0;
        while(i < nums.size() - 1 and j < nums.size() - 1) {
            if(subarrays == 0) {
                if(k == 1) {
                    subarrays++;
                    j += i;
                } else {
                    if(size == k) {
                        subarrays++;
                        size = 1;
                        j = i + 1;
                    }
                    else if(nums[i + 1] - nums[i] > 0) {
                        i++;
                        size++;
                    } else {
                        i++;
                        size = 1;
                    }
                }
            } else if (subarrays == 1) {
                if(k == 1) {
                    return true;
                } else {
                    if(size == k) {
                        subarrays++;
                        return true;
                    }
                    if(nums[j + 1] - nums[j] > 0) {
                        size++;
                        j++;
                    } else {
                        size = 1;
                        subarrays = 0;
                        i = i - k + 2;
                    }
                }
            }
        }
        if(subarrays == 1 and size == k)
            return true;
        else
            return false;
    }
};
