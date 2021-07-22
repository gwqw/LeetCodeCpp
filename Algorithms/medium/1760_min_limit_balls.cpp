/**
    1760. Minimum Limit of Balls in a Bag
You are given an integer array nums where the ith bag contains nums[i] balls. You are also given an integer maxOperations.
You can perform the following operation at most maxOperations times:
- Take any bag of balls and divide it into two new bags with a positive number of balls.
For example, a bag of 5 balls can become two new bags of 1 and 4 balls, or two new bags of 2 and 3 balls.
Your penalty is the maximum number of balls in a bag. You want to minimize your penalty after the operations.

Return the minimum possible penalty after performing the operations.

Example 1:
Input: nums = [9], maxOperations = 2
Output: 3
Explanation: 
- Divide the bag with 9 balls into two bags of sizes 6 and 3. [9] -> [6,3].
- Divide the bag with 6 balls into two bags of sizes 3 and 3. [6,3] -> [3,3,3].
The bag with the most number of balls has 3 balls, so your penalty is 3 and you should return 3.

Example 2:
Input: nums = [2,4,8,2], maxOperations = 4
Output: 2
Explanation:
- Divide the bag with 8 balls into two bags of sizes 4 and 4. [2,4,8,2] -> [2,4,4,4,2].
- Divide the bag with 4 balls into two bags of sizes 2 and 2. [2,4,4,4,2] -> [2,2,2,4,4,2].
- Divide the bag with 4 balls into two bags of sizes 2 and 2. [2,2,2,4,4,2] -> [2,2,2,2,2,4,2].
- Divide the bag with 4 balls into two bags of sizes 2 and 2. [2,2,2,2,2,4,2] -> [2,2,2,2,2,2,2,2].
The bag with the most number of balls has 2 balls, so your penalty is 2 an you should return 2.

Example 3:
Input: nums = [7,17], maxOperations = 2
Output: 7
 
Constraints:
1 <= nums.length <= 10^5
1 <= maxOperations, nums[i] <= 10^9

Algo: max heap (doesn't work :-( )
take cnt max from pq (all nums == max)
next = pq.top or 1
divides = min(max / next, oper / cnt) # cnt * divides <= oper => divides <= oper / cnt
divide max on next -> (n%k)(n / k+1 + 1)  +  (k+1-n%k) (n/k+1)
oper -= cnt*divides

Algo2: answer binary search
l = 0, r = 1e9
m = (l+r)/2
ops = ops_count:
    for n in nums:
        ops += n / m or n/m-1
if ops <= operations:
    r = m
else:
    l = m
*/

class Solution {
public:
    int minimumSize(const vector<int>& nums, int maxOperations) {
        int l = 0;
        int r = 1e9;
        while (l+1 < r) {
            int m = l + (r - l) / 2;
            int op = calcOperations(nums, m);
            if (op <= maxOperations) {
                r = m;
            } else {
                l = m;
            }
        }
        return r;
    }
    
private:
    int calcOperations(const vector<int>& nums, int cnt) {
        int ops = 0;
        for (int n : nums) {
            if (n > cnt) {
                ops += n % cnt == 0 ? n / cnt - 1: n / cnt;
            }
        }
        return ops;
    }
};