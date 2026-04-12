#include <iostream>
#include <string>

int expandFromCenter(std::string s, int left, int right){
    while(left >= 0 && right <= s.length() && s[left] == s[right]){
        left--;
        right++;
    }
    
    return right-left-1;
}

int max(int n, int m){
    return n > m ? n : m;
}

std::string longestPalindrome(std::string s) {
    if(s.empty()) return "";

    int start = 0, end = 0;

    for(int i = 0; i < s.length(); i++){
        int odd = expandFromCenter(s, i, i);
        int even = expandFromCenter(s, i, i+1);
        int maxLen = max(odd, even);

        if(maxLen > end - start){
            start = i - (maxLen-1)/2;
            end = i + maxLen/2;
        }
    }

    return s.substr(start, end - start + 1);
}

int main(){
    std::cout << longestPalindrome("cbbd") << '\n';

    return 0;
}