class Solution {
public:
    bool helper(string &s, int left, int right){
        while(left<right){
        if(s[left] != s[right]){
            return false;
        }
            left++;
            right--;
        
        }
        return true;

    }
    bool validPalindrome(string s) {
        int left =0;
        int right = s.size()-1;

        while(left <right){
            if(s[left] == s[right]){
                left++;
                right--;
            }
            else{
                return helper(s,left+1,right) || helper(s,left,right-1);
            }
        }
        return true;
    }
};