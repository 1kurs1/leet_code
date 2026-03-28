#include <iostream>
#include <vector>

int max(int n, int m){
  return n > m ? n : m;
}

int longestSubarray(std::vector<int>& nums) {
  int left = 0;
  int zeroCount = 0;
  int maxRes = 0;

  for(int right = 0; right < nums.size(); ++right){
    if(nums[right] == 0) zeroCount++;

    while(zeroCount > 1){
      if(nums[left] == 0) zeroCount--;
      left++;
    }

    maxRes = max(maxRes, right - left);
  }

  return maxRes;
}

int main(){

  std::vector<int> testCase1 = {1, 1, 0, 1};
  std::cout << "test case 1: " << longestSubarray(testCase1) << '\n';

  std::vector<int> testCase2 = {0, 1, 1, 1, 0, 1, 1, 0, 1};
  std::cout << "test case 2: " << longestSubarray(testCase2) << '\n';

  return EXIT_SUCCESS;
}