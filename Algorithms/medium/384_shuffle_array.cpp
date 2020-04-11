/**
    384. Shuffle an Array
Shuffle a set of numbers without duplicates.

Example:
// Init an array with set 1, 2, and 3.
int[] nums = {1,2,3};
Solution solution = new Solution(nums);

// Shuffle the array [1,2,3] and return its result. Any permutation of [1,2,3] must equally likely to be returned.
solution.shuffle();

// Resets the array back to its original configuration [1,2,3].
solution.reset();

// Returns the random shuffling of array [1,2,3].
solution.shuffle();

Algo1: use next_permutation

Algo2: use n swaps


*/

class Solution {
public:
    Solution(const vector<int>& nums) 
        : data(nums), cur(data) 
    {}
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() const {
        return data;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        next_permutation(cur.begin(), cur.end());
        return cur;
    }
private:
    vector<int> data;
    vector<int> cur;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
 
class Solution {
public:
    Solution(const vector<int>& nums) 
        : data(nums)
    {}
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() const {
        return data;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        if (data.size() <= 1) return data;
        vector<int> res = data;
        for (size_t i = data.size()-1; i > 0; --i) {
            swap(res[i], res[rand() % (i+1)]);
        }       
        return res;
    }
private:
    vector<int> data;
};



