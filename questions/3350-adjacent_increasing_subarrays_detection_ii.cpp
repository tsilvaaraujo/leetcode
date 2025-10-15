class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int i = 0, j = 0, max = 1, size = 1, subarray = 0, temporary = -1;
        while(i < nums.size() - 1 and j < nums.size() - 1) {
            if(subarray == 0) {
                if(nums[i+1] - nums[i] > 0) {
                    i++;
                    size++;
                }
                else {
                    if(size > max) {
                        j = i + 1;
                        temporary = size;
                        size = 1;
                        subarray++;
                    } else {
                        i++;
                        size = 1;
                    }
                }
            } else if (subarray == 1) {
                if(nums[j+1] - nums[j] > 0) {
                    j++;
                    size++;
                    if(j == nums.size() - 1) {
                        if(size <= temporary && size > max)
                            max = size;
                        if(size > temporary && temporary > max)
                            max = temporary;
                        if(temporary / 2 > max)
                            max = temporary / 2;
                        if(size / 2 > max)
                            max = size / 2;
                        size = 1;
                        subarray--;
                        i++;
                    }
                } else {
                    if(size <= temporary && size > max)
                        max = size;
                    if(size > temporary && temporary > max)
                        max = temporary;
                    if(temporary / 2 > max)
                        max = temporary / 2;
                    if(size / 2 > max)
                        max = size / 2;
                    size = 1;
                    subarray--;
                    i = i - temporary + 2;
                }
            }        
        }
        if(size / 2 > max)
            max = size / 2;
        if(temporary / 2 > max)
            max = temporary / 2;
        if(nums.size() == 2)
            max = 1;
        return max;
    }
};
