class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        vector<int> freq(value, 0);
        for(int i = 0; i < nums.size(); i++) {
            nums[i] = nums[i] % value;
            if(nums[i] < 0)
                nums[i] += value;
            freq[nums[i]]++;
        }
        vector<int>::iterator minIterator = min_element(freq.begin(), freq.end());
        int minIndex = distance(freq.begin(), minIterator);
        return (*minIterator) * value + minIndex;
    }
};
