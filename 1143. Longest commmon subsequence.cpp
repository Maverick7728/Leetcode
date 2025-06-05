// Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

// A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

// For example, "ace" is a subsequence of "abcde".
// A common subsequence of two strings is a subsequence that is common to both strings.



class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int a = text1.size();
        int b = text2.size();
        vector<vector<int>> tab( a+1 , vector<int>(b+1,0));

        for(int i=a-1;i>=0;i--){
            for(int j=b-1;j>=0;j--){
                if(text1[i] == text2[j]){
                    tab[i][j] = 1+ tab[i+1][j+1];
                }else{
                    tab[i][j] = max(tab[i+1][j], tab[i][j+1]);
                }
            }
        }
        return tab[0][0];
    }
};