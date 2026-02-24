#include <iostream>
#include <string>
#include <unordered_set>

int max(int n, int m){
  return n > m ? n : m;
}

int lengthOfLongestSubstring(std::string s) {
  int left = 0;
  int maxLength = 0;
  std::unordered_set<char> charSet;

  for(int right = 0; right < s.length(); right++){
    while(charSet.find(s[right]) != charSet.end()){
      charSet.erase(s[left]);
      left++;
    }
    
    charSet.insert(s[right]);
    maxLength = max(maxLength, right-left + 1);
  }

  return maxLength;
}

int main(){
  std::string a = "dvdf";
  std::cout << lengthOfLongestSubstring(a) << '\n';

  return EXIT_SUCCESS;
}