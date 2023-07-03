#include<iostream>

using namespace std;

class Solution {
public:
  string palindrome(string s, int l, int r){
    if(l >= 0 && r <s.length() && s[l] == s[r]){
      l--;
      r++;
    }
    // substr(起始位置，长度)
    return s.substr(l + 1, r - l - 1);
  }

  string longestPalindrome(string s){
    string res = "";
    for(int i = 0; i < s.length(); i++){
      string s1 = palindrome(s, i, i);
      string s2 = palindrome(s, i, i+1);
      res = res.length() > s1.length() ? res:s1;
      res = res.length() > s2.length() ? res:s2;
    }
    return res;
  }
};

int main(){
  Solution s;
  string str = "babad";
  cout << s.longestPalindrome(str) << endl;
}