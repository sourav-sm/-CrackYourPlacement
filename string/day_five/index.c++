// 1499. Max Value of Equation
// You are given an array points containing the coordinates of points on a 2D plane, sorted by the x-values, where points[i] = [xi, yi] such that xi < xj for all 1 <= i < j <= points.length. You are also given an integer k.
// Return the maximum value of the equation yi + yj + |xi - xj| where |xi - xj| <= k and 1 <= i < j <= points.length.
// It is guaranteed that there exists at least one pair of points that satisfy the constraint |xi - xj| <= k.

#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

class Solution {
public:
    int findMaxValueOfEquation(std::vector<std::vector<int>>& points, int k) {
        std::priority_queue<std::pair<int, int>> p; // max-heap
        int ans = INT_MIN;
        for (int i = 0; i < points.size(); ++i) {
            // Remove points that do not satisfy |xi - xj| <= k
            while (!p.empty() && (points[i][0] - p.top().second) > k) {
                p.pop();
            }
            // If the heap is not empty, calculate the potential maximum value
            if (!p.empty()) {
                ans = std::max(ans, points[i][1] + points[i][0] + p.top().first);
            }
            // Push the current point into the heap with (yi - xi) as the first element
            p.push({points[i][1] - points[i][0], points[i][0]});
        }
        return ans;
    }
};

// 84. Largest Rectangle in Histogram
// Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.
#include <vector>
#include <stack>
#include <algorithm>

class Solution {
public:
    int largestRectangleArea(std::vector<int>& heights) {
        int n = heights.size();
        std::stack<int> st;
        int maxArea = 0;
        int i = 0;
        
        while (i < n) {
            // Push current bar to stack if it's greater than the bar at stack's top
            if (st.empty() || heights[i] >= heights[st.top()]) {
                st.push(i);
                i++;
            } else {
                // Calculate area with heights[st.top()] as the smallest (or minimum height) bar 'h'
                int h = heights[st.top()];
                st.pop();
                // Calculate width
                int w = st.empty() ? i : i - st.top() - 1;
                maxArea = std::max(maxArea, h * w);
            }
        }
        
        // Remaining bars in stack
        while (!st.empty()) {
            int h = heights[st.top()];
            st.pop();
            int w = st.empty() ? i : i - st.top() - 1;
            maxArea = std::max(maxArea, h * w);
        }
        
        return maxArea;
    }
};

// 20. Valid Parentheses
// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
// An input string is valid if:
// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Every close bracket has a corresponding open bracket of the same type.
class Solution {
public:
    bool areparenthes(char opening, char closing) {
        if (opening == '(' && closing == ')') return true;
        else if (opening == '{' && closing == '}') return true;
        else if (opening == '[' && closing == ']') return true;
        else return false;
    }

    bool isValid(string s) {
        stack<char> stk;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                stk.push(s[i]);
            } else if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
                if (stk.empty() || !areparenthes(stk.top(), s[i])) {
                    return false;
                } else {
                    stk.pop();
                }
            }
        }
        return stk.empty();//to check whether all the opening prenthesis   have a closing parenthesis
    }
};
