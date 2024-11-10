/*

You are given an array, and you need to choose a contiguous subarray of length ‘k’. For each subarray, find the maximum element and return the minimum of those maximums.

Sample Input:

2 → Length of segment k = 2
6 → Size of array n = 6
3 → Array elements = [3, 1, 4, 1, 5, 9]
1
4
1
5
9


Sample Output:

4

Explanation: 
The subarrays of size \( k = 2 \) are:
[3, 1] with maximum 3
[1, 4] with maximum 4
[4, 1] with maximum 4
[1, 5] with maximum 5
[5, 9] with maximum 9

The minimum of these maximums is 4. Therefore, the answer is 4.

*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        deque<int> dq;

        // Edge case: if the array is empty or k is non-positive
        if (nums.empty() || k <= 0) return result;

        for (int i = 0; i < nums.size(); ++i) {
            // Remove indices of elements not in the sliding window
            if (!dq.empty() && dq.front() < i - k + 1) {
                dq.pop_front();
            }

            // Remove indices of elements smaller than the current element from the back of the deque
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }

            // Add the current element index to the deque
            dq.push_back(i);

            // The first element of the deque is the largest element in the window
            // Start adding the results to the output after we've processed the first window
            if (i >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }

        return result;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    vector<int> result = solution.maxSlidingWindow(nums, k);

    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
