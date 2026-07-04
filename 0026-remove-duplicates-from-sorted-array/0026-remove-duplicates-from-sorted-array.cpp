class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;

        int j = 0;  // Points to the position of the last unique element

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[j]) {
                j++;
                nums[j] = nums[i];
            }
        }

        return j + 1;
    }
};