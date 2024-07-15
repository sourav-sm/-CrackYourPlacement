//73. Set Matrix Zeroes
// Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.
// You must do it in place.

class Solution {
public:
    void makezerorow(vector<vector<int>>& matrix,int i,int m){
        for(int j=0;j<m;j++){
            if(matrix[i][j]!=0){
                matrix[i][j]=-(2147483647 - 1);
            }
        }
    }
    void makezerocol(vector<vector<int>>& matrix,int j,int n){
        for(int i=0;i<n;i++){
            if(matrix[i][j]!=0){
                matrix[i][j]=-(2147483647 - 1);
            }
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();

        for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                // mark ith index of row wih 1:
                makezerorow(matrix,i,m);
                makezerocol(matrix,j,n);
            }
        }
      }
        for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j]==-(2147483647 - 1)) {
                matrix[i][j] = 0;
            }
        }
    }
    }
};




// 283. Move Zeroes
// Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
// Note that you must do this in-place without making a copy of the array.
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
      int nonzeroindex=0;
      for(int i=0;i<nums.size();i++){
        if(nums[i]!=0){
            nums[nonzeroindex++]=nums[i];
        }
      }
      while(nonzeroindex<nums.size()){
        nums[nonzeroindex++]=0;
      }
    }
};

// 121. Best Time to Buy and Sell Stock
// You are given an array prices where prices[i] is the price of a given stock on the ith day.
// You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
// Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
 
 class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprice=INT_MAX;
        int maxprofit=0;
        for(int i=0;i<prices.size();i++){
            minprice=min(minprice,prices[i]);
            maxprofit=max(maxprofit,(prices[i]-minprice));
        }
        return maxprofit;
    }
};

