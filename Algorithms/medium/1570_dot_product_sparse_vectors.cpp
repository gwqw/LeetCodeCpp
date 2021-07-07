/**
    1570. Dot Product of Two Sparse Vectors
Given two sparse vectors, compute their dot product.

Implement class SparseVector:
SparseVector(nums) Initializes the object with the vector nums
dotProduct(vec) Compute the dot product between the instance of SparseVector and vec
A sparse vector is a vector that has mostly zero values, you should store the sparse vector efficiently and compute the dot product between two SparseVector.

Follow up: What if only one of the vectors is sparse?

Example 1:
Input: nums1 = [1,0,0,2,3], nums2 = [0,3,0,4,0]
Output: 8
Explanation: v1 = SparseVector(nums1) , v2 = SparseVector(nums2)
v1.dotProduct(v2) = 1*0 + 0*3 + 0*0 + 2*4 + 3*0 = 8

Example 2:
Input: nums1 = [0,1,0,0,0], nums2 = [0,0,0,0,2]
Output: 0
Explanation: v1 = SparseVector(nums1) , v2 = SparseVector(nums2)
v1.dotProduct(v2) = 0*0 + 1*0 + 0*0 + 0*0 + 0*2 = 0

Example 3:
Input: nums1 = [0,1,0,0,2,0,0], nums2 = [1,0,0,0,3,0,4]
Output: 6

Constraints:
n == nums1.length == nums2.length
1 <= n <= 10^5
0 <= nums1[i], nums2[i] <= 100

Algo: 
sparse: list of idx,value
*/

class SparseVector {
	struct Item {
		size_t idx = 0;
		int value = 0;
	};
public:
    
    SparseVector(vector<int> &nums) {
        for (size_t i = 0; i < nums.size(); ++i) {
			if (nums[i] != 0) {
				data.push_back(Item{i, nums[i]});
			}
		}
		size = nums.size();
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(const SparseVector& vec) {
		int res = 0;
		for (size_t i = 0, j = 0; i < data.size() && j < vec.data.size(); ) {
			const auto& item1 = data[i];
			const auto& item2 = vec.data[j];
			if (item1.idx == item2.idx) {
				res += item1.value * item2.value;
				++i;
				++j;
			} else if (item1.idx < item2.idx) {
				++i;
			} else {
				++j;
			}
		}
		return res;
    }
	
private:
	vector<Item> data;
	size_t size = 0;
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);
