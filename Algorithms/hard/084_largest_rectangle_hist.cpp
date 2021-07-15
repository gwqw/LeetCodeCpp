/**
    84. Largest Rectangle in Histogram
Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

Example 1:
Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.

Example 2:
Input: heights = [2,4]
Output: 4

Constraints:
1 <= heights.length <= 10^5
0 <= heights[i] <= 10^4

Algo1: divide and conquer (solve problem for left and right subarray and whole array with min_height) O(NlogN)ave and O(n^2)worse, O(height) mem recursion
calc_area
    if heights.empty: return 0
    if heights.size() == 1: return h[0]
    take min_h: h
    area = max(h * hist_size, calc_area(0, h_idx-1), calc_area(h_idx+1, heights.size())) 
    
Algo2: monotonic stack
stack with height and idx
for i,hcur in heights:
    check for all in stack with h <= h_cur:
        j,h = stack.pop() # calc area with this height: all indexes from prev (not inclusing) to current_idx (not inclusing)
        j = stack.top()+1
        update area = h * (i - j)
    st.push(i, hcur)
check areas for values in stack
*/

class Solution {
public:
    int largestRectangleArea(const vector<int>& heights) {
        return calcArea(heights, 0, heights.size());
    }
    
private:
    int calcArea(const vector<int>& heights, size_t from, size_t to) {
        if (from == to) return 0;
        if (from+1 == to) return heights[from];
        auto it = min_element(heights.begin() + from, heights.begin() + to);
        size_t mhi = it - heights.begin();
        int area = *it * (to - from);
        area = max(area, calcArea(heights, from, mhi));
        area = max(area, calcArea(heights, mhi+1, to));
        return area;
    }
};
class Solution {
    using Iterator = vector<int>::const_iterator;
public:
    int largestRectangleArea(const vector<int>& heights) {
        return calcArea(heights, heights.begin(), heights.end());
    }
    
private:
    int calcArea(const vector<int>& heights, Iterator from, Iterator to) {
        if (from == to) return 0;
        if (from+1 == to) return *from;
        auto it = min_element(from, to);
        int area = *it * (to - from);
        area = max(area, calcArea(heights, from, it));
        area = max(area, calcArea(heights, it+1, to));
        return area;
    }
};

class Solution {
public:
    int largestRectangleArea(const vector<int>& heights) {
        stack<pair<int, int>> st;
        int area = 0;
        for (int i = 0; i < (int)heights.size(); ++i) {
            area = max(area, heights[i]);
            while (!st.empty() && st.top().second >= heights[i]) {
                auto [j,h] = st.top();
                st.pop();
                j = st.empty() ? 0 : st.top().first+1;
                area = max(area, h * (i - j));
            }
            st.emplace(i, heights[i]);
        }
        int ei = (int)heights.size();
        while (!st.empty()) {
            auto [i, h] = st.top();
            st.pop();
            i = st.empty() ? 0 : st.top().first+1;
            area = max(area, h * (ei - i));
        }
        return area;
    }
};
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<size_t> st;
        int max_area = 0;
        for (size_t i = 0; i < heights.size(); ++i) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                int height = heights[st.top()];
                st.pop();
                size_t f = !st.empty() ? st.top()+1 : 0;
                max_area = max(max_area, int(i - f)*height);
            }
            st.push(i);
        }
        while (!st.empty()) {
            int height = heights[st.top()];
            st.pop();
            size_t f = !st.empty() ? st.top()+1 : 0;
            max_area = max(max_area, int(heights.size() - f)*height);
        }
        return max_area;
    }
};