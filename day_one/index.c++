//PROBLEM STATEMENT-
// 287. Find the Duplicate Number
// Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
// There is only one repeated number in nums, return this repeated number.
// You must solve the problem without modifying the array nums and uses only constant extra space.

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
       int n=nums.size();
            map<int,int>mpp;
            for(int i=0;i<n;i++){
                mpp[nums[i]]++;
            }
    
            for(auto it:mpp){
                if(it.second>=2){
                    return it.first;
                }
            }
            return -1;
    }
};

///75. Sort Colors
// Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
// We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
// You must solve this problem without using the library's sort function.

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int lo=0,hi=nums.size()-1;
        int i=0;
        while(i<=hi){
            if(nums[i]==0){
                swap(nums[lo],nums[i]);
                i++;
                lo++;
            }else if(nums[i]==2){
                swap(nums[i],nums[hi]);
                // i++;it will create error for shifting 0 from 1 position to 0 position for this example [1,2,0] 
                hi--;
            }else{
                i++;
            }
        }
    }
};

//26. Remove Duplicates from Sorted Array
// Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same. Then return the number of unique elements in nums.
// Consider the number of unique elements of nums to be k, to get accepted, you need to do the following things:
// Change the array nums such that the first k elements of nums contain the unique elements in the order they were present in nums initially. The remaining elements of nums are not important as well as the size of nums.
// Return k.

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
      set<int>s;
      for(int i=0;i<nums.size();i++){
        s.insert(nums[i]);
      }
      int k= s.size();
      int j=0;
      for(int x:s){
        nums[j++]=x;
      }
      return k;
    }
};