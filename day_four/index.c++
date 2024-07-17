 //55. Jump Game
// You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.
// Return true if you can reach the last index, or false otherwise.
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i = 0;
        int n = nums.size();
        
        while (i < n - 1) {
            if (nums[i] == 0) {
                // If we encounter 0, it means we can't move forward.
                return false;
            }

            int maxJump = 0;
            int nextIndex = i;

            // Find the maximum jump from the current position.
            for (int j = 1; j <= nums[i]; ++j) {
                if (i + j >= n - 1) {
                    // If we can reach the last index, return true.
                    return true;
                }

                if (nums[i + j] + j > maxJump) {
                    maxJump = nums[i + j] + j;
                    nextIndex = i + j;
                }
            }

            // Move to the next index with the maximum jump.
            i = nextIndex;
        }

        return i >= n - 1;
    }
};

//169. Majority Element
// Given an array nums of size n, return the majority element.
// The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.
 //    TC--O(N)
// SC-O(N)+O(NLOGN)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
    unordered_map<int,int>mpp;
    int n=nums.size();
    for(int i=0;i<n;i++){
        mpp[nums[i]]++;
    }
    for(auto it:mpp){
        if(it.second>n/2){
            return it.first;
        }
    }
    return -1;
    }
};
// 493. Reverse Pairs
// Given an integer array nums, return the number of reverse pairs in the array.
// A reverse pair is a pair (i, j) where:
// 0 <= i < j < nums.length and
// nums[i] > 2 * nums[j].

class Solution {
public:
    int merge(vector<int>& nums, int left, int mid, int right) {
        int count = 0;
        int j = mid + 1;
        
        // Count reverse pairs
        for (int i = left; i <= mid; ++i) {
            while (j <= right && nums[i] > 2LL * nums[j]) {
                ++j;
            }
            count += (j - (mid + 1));
        }
        
        // Merge the two halves
        vector<int> temp;
        int i = left, k = mid + 1;
        while (i <= mid && k <= right) {
            if (nums[i] <= nums[k]) {
                temp.push_back(nums[i++]);
            } else {
                temp.push_back(nums[k++]);
            }
        }
        
        while (i <= mid) {
            temp.push_back(nums[i++]);
        }
        
        while (k <= right) {
            temp.push_back(nums[k++]);
        }
        
        for (int i = left; i <= right; ++i) {
            nums[i] = temp[i - left];
        }
        
        return count;
    }
    
    int mergeSort(vector<int>& nums, int left, int right) {
        if (left >= right) return 0;
        
        int mid = left + (right - left) / 2;
        int count = mergeSort(nums, left, mid);
        count += mergeSort(nums, mid + 1, right);
        count += merge(nums, left, mid, right);
        
        return count;
    }
    int reversePairs(vector<int>& nums) {
      return mergeSort(nums,0,nums.size()-1);   
    }
};



// 289. Game of Life
// According to Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."
// The board is made up of an m x n grid of cells, where each cell has an initial state: live (represented by a 1) or dead (represented by a 0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):
// Any live cell with fewer than two live neighbors dies as if caused by under-population.
// Any live cell with two or three live neighbors lives on to the next generation.
// Any live cell with more than three live neighbors dies, as if by over-population.
// Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
// The next state is created by applying the above rules simultaneously to every cell in the current state, where births and deaths occur simultaneously. Given the current state of the m x n grid board, return the next state.
class Solution {
public:
    //  funcion to check validility of neighbor
    bool isValidNeighbor(int x, int y, vector<vector<int>>& board) {
        return (x >= 0 && x < board.size() && y >= 0 && y < board[0].size());
    }
    
    void gameOfLife(vector<vector<int>>& board) { 
        vector<int> dx = {0, 0, 1, 1, 1, -1, -1, -1}; //8 coordinated for neighbours
        vector<int> dy = {1, -1, 1, -1, 0, 0, 1, -1};
        
        for (int row = 0; row < board.size(); row++) {
            for (int col = 0; col < board[0].size(); col++) {
                
                int count_live_neighbors = 0;
                
                for (int i = 0; i < 8; i++) {
                    int curr_x = row + dx[i], curr_y = col +dy[i];
                    if (isValidNeighbor(curr_x, curr_y, board) && abs(board[curr_x][curr_y]) == 1)
                        count_live_neighbors++;
                }
                
                if (board[row][col] == 1 && (count_live_neighbors < 2 || count_live_neighbors > 3))
                    board[row][col] = -1;
                
                if (board[row][col] == 0 && count_live_neighbors == 3)
                    board[row][col] = 2;
            }
        }
        
        for (int row = 0; row < board.size(); row++) {
            for (int col = 0; col < board[0].size(); col++) {
                if (board[row][col] >= 1)
                    board[row][col] = 1;
                else
                    board[row][col] = 0;
            }
        }
    }
};
// GFG--Given an array arr[] of length n. Find all possible unique permutations of the array in sorted order. A sequence A is greater than sequence B if there is an index i for which Aj = Bj for all j<i and Ai > Bi.

#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
    void backtrack(vector<int>& arr, vector<int>& perm, vector<bool>& visited, set<vector<int>>& result) {
        if (perm.size() == arr.size()) {
            result.insert(perm);
            return;
        }

        for (int i = 0; i < arr.size(); ++i) {
            if (visited[i] || (i > 0 && arr[i] == arr[i - 1] && !visited[i - 1])) {
                continue;
            }
            visited[i] = true;
            perm.push_back(arr[i]);
            backtrack(arr, perm, visited, result);
            perm.pop_back();
            visited[i] = false;
        }
    }

    vector<vector<int>> uniquePerms(vector<int>& arr, int n) {
        sort(arr.begin(), arr.end());
        set<vector<int>> result;
        vector<int> perm;
        vector<bool> visited(n, false);
        backtrack(arr, perm, visited, result);
        return vector<vector<int>>(result.begin(), result.end());
    }
};
