class Solution:
    def longestPalindrome(self, s: str) -> str:
        length = len(s)
        if length == 0:
            return ''
        else:
            answer = s[0]
            # use dp[i][j] to indicate whether s[i:j] is a palindromic string
            dp = []
            