class Solution {
public:
    int minimumDeletions(vector<int>& nums) {

        int n = nums.size();

        int minIndex = 0;
        int maxIndex = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] < nums[minIndex])
                minIndex = i;

            if (nums[i] > nums[maxIndex])
                maxIndex = i;
        }

        int a = min(minIndex, maxIndex);
        int b = max(minIndex, maxIndex);

        int front = b + 1;

        int back = n - a;

        int both = (a + 1) + (n - b);
        return min({front, back, both});
    }
};