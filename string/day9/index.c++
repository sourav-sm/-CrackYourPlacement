// 151. Reverse Words in a String
// Given an input string s, reverse the order of the words.
// A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.
// Return a string of the words in reverse order concatenated by a single space.
// Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
        string reverseWords(string s){
            //1st reverse the entire string
            reverse(s.begin(),s.end());

            //2nd reverse evry word in thr reversed string and remove extra space
            int i=0;//for itertation 
            int l=0;//left bounday
            int r=0;//right boundary

            int n=s.length();
            while(i<n){
                //traverse the string untill we find a space or reached an end
                while(i<n && s[i]!=' '){
                    s[r++]=s[i++];//move the current charecter to the right position
                }
                //if we have a word boundary (l<r),reverse the current word
                if(l<r){
                    reverse(s.begin()+1,s.begin()+r);
                    //add a space after the current word
                    s[r]=' ';
                    r++;

                    //update the reft boundary
                    l=r;
                }
                i++;
            }
            s=s.substr(0,r-1);
            return s;
    }
};

//49. Group Anagrams
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();
        unordered_map<string,vector<string>>mpp;

        for(int i=0;i<n;i++){
            string temp=strs[i];
            sort(temp.begin(),temp.end());
            mpp[temp].push_back(strs[i]);//at index temp store strs[i] for example at aet store eat,tea,ate
        }
        

        vector<vector<string>>ans;
        for(auto it:mpp){
            ans.push_back(it.second);
        }
        return ans;
    }
};

// 227. Basic Calculator II
// Given a string s which represents an expression, evaluate this expression and return its value. 
// The integer division should truncate toward zero.
// You may assume that the given expression is always valid. All intermediate results will be in the range of [-231, 231 - 1].
// Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().

class Solution {
public:
    int calculate(string s) {
        stack<int>numstack;
        int num=0;
        char oprt='+';

        for(int i=0;i<s.size();i++){
            char charval=s[i];
            if(isdigit(charval)){
                num=num*10+(charval-'0');
            }

            if(!isdigit(charval) && !isspace(charval) || i==s.size()-1){
                if(oprt=='+'){
                    numstack.push(num);
                }else if(oprt=='-'){
                    numstack.push(-num);
                }else if(oprt=='*'){
                    int top=numstack.top();
                    numstack.pop();
                    numstack.push(top*num);
                }else if(oprt=='/'){
                    int top=numstack.top();
                    numstack.pop();
                    numstack.push(top/num);
                }
                oprt=charval;
                num=0;
            }
        }
        int ans=0;
        while(!numstack.empty()){
            ans+=numstack.top();
            numstack.pop();
        }
        return ans;
    }
};

// 273. Integer to English Words
// Convert a non-negative integer num to its English words representation.
class Solution {
public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";
        
        vector<string> thousands = {"", "Thousand", "Million", "Billion"};
        string result;
        
        int i = 0;
        while (num > 0) {
            if (num % 1000 != 0) {
                result = helper(num % 1000) + thousands[i] + " " + result;
            }
            num /= 1000;
            i++;
        }
        
        while (result.back() == ' ') result.pop_back();  // Remove trailing spaces
        return result;
    }
    
private:
    vector<string> lessThan20 = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> tens = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    
    string helper(int num) {
        if (num == 0) return "";
        else if (num < 20) return lessThan20[num] + " ";
        else if (num < 100) return tens[num / 10] + " " + helper(num % 10);
        else return lessThan20[num / 100] + " Hundred " + helper(num % 100);
    }
};
 