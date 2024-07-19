// Print all the duplicate characters in a string
// Given a string S, the task is to print all the duplicate characters with their occurrences in the given string.
#include <bits/stdc++.h>
using namespace std;

vector<pair<char, int>> solution(const string &s) {
    unordered_map<char, int> mpp;
    
    for (char c : s) {
        mpp[c]++;
    }
    
    vector<pair<char, int>> ans;
    for (const auto &it : mpp) {
        if (it.second > 1) {
            ans.push_back(it);
        }
    }
    
    return ans;
}

int main() {
    string input = "geeksforgeeks";
    vector<pair<char, int>> duplicates = solution(input);

    cout << "Duplicate characters with their occurrences:" << endl;
    for (const auto &p : duplicates) {
        cout << p.first << ": " << p.second << endl;
    }

    return 0;
}

// 12. Integer to Roman
// Seven different symbols represent Roman numerals with the following values:
class Solution {
public:
    string intToRoman(int num) {
        string ans="";
        while(num>=1000){
            ans+="M";
            num-=1000;
        }
        while(num>=900){
            ans+="CM";
            num-=900;
        }
        while(num>=500){
            ans+="D";
            num-=500;
        }
         while(num>=400){
            ans+="CD";
            num-=400;
         }
        while(num>=100){
            ans+="C";
            num-=100;
        }
         while(num>=90){
            ans+="XC";
            num-=90;
        }
        while(num>=50){
            ans+="L";
            num-=50;
        }
         while(num>=40){
            ans+="XL";
            num-=40;
        }
        while(num>=10){
            ans+="X";
            num-=10;
        }
        while(num>=9){
            ans+="IX";
            num-=9;
        }
        while(num>=5){
            ans+="V";
            num-=5;
        }
        while(num>=4){
            ans+="IV";
            num-=4;
        }
        while(num>=1){
            ans+="I";
            num-=1;
        }
      return ans;
    }
};

// 22. Generate Parentheses
// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string>result;
        generate(n,n,"",result);
        return result;
    }

    private:
      void generate(int open,int close,string current,vector<string>& result){
        if(open==0 && close==0){
            result.push_back(current);
            return;
        }

        if(open>0){
            generate(open-1,close,current+"(",result);
        }

        if(close>open){
            generate(open,close-1,current+")",result);
        }
      }
};

// 65. Valid Number
// Given a string s, return whether s is a valid number.
// For example, all the following are valid numbers: "2", "0089", "-0.1", "+3.14", "4.", "-.9", "2e10", "-90E3", "3e+7", "+6e-1", "53.5e93", "-123.456e789", while the following are not valid numbers: "abc", "1a", "1e", "e3", "99e2.5", "--6", "-+3", "95a54e53".
// Formally, a valid number is defined using one of the following definitions:
// An integer number followed by an optional exponent.
// A decimal number followed by an optional exponent.
// An integer number is defined with an optional sign '-' or '+' followed by digits.
// A decimal number is defined with an optional sign '-' or '+' followed by one of the following definitions:
// Digits followed by a dot '.'.
// Digits followed by a dot '.' followed by digits.
// A dot '.' followed by digits.
// An exponent is defined with an exponent notation 'e' or 'E' followed by an integer number.
// The digits are defined as one or more digits.

class Solution {
public:
    bool isNumber(string s) {
     bool num=false;
     bool dot=false;
     bool exp=false;

     for(int i=0;i<s.length();i++){
        char c = s[i];
        if(c>='0' && c<='9'){
            num=true;
        }else if(c=='e'|| c=='E'){
            if(exp || !num)
               return false;
            exp=true;
            num=false;
        }else if(c=='.'){
            if(dot || exp)
               return false;
            dot=true;
        }else if(c=='-' || c=='+'){
            if(i!=0 && s[i-1]!='e'&& s[i-1]!='E'){
                return false;
            }
        }else{
            return false;
        }
     }   
     return num;
    }
};
 