class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int operations = 0;

        // Keep performing the operation until the array is sorted
        while (!is_sorted(nums.begin(), nums.end())) {
            int minSum = INT_MAX;
            int index = 0;

            // Find the leftmost adjacent pair with the minimum sum
            for (int i = 0; i < nums.size() - 1; ++i) {
                int currSum = nums[i] + nums[i + 1];
                if (currSum < minSum) {
                    minSum = currSum;
                    index = i;
                }
            }

            // Replace the adjacent pair at 'index' with their sum
            nums[index] = nums[index] + nums[index + 1];
            nums.erase(nums.begin() + index + 1);

            operations++;
        }

        return operations;
    }
};
