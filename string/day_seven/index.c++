// 28. Find the Index of the First Occurrence in a String
// Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
class Solution {
public:
    int strStr(string haystack, string needle) {
        int m=haystack.size();
        int n=needle.size();

        if(n==0){
            return 0;
        }
        for(int i=0;i<=m-n;i++){
            bool found=true;
            for(int j=0;j<n;j++){
                if(haystack[i+j]!=needle[j]){
                    found=false;
                    break;
                }
            }
            if(found){
                return i;
            }
        }
        return -1;
    }
};

// Write a function to find the longest common prefix string amongst an array of strings.
// If there is no common prefix, return an empty string "".
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        int a=strs.size();
        string n=strs[0],m=strs[a-1],ans="";
        for(int i=0;i<n.size();i++){
            if(n[i]==m[i]){ans+=n[i];}
            else break;
        }
        return ans;
        
    }
};
