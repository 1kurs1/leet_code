#include <iostream>
#include <vector>
#include <unordered_map>

int abs(int n){
  return n >= 0 ? n : -n;
}

class Solution{
public:
  std::vector<int> shortestDistanceAfterQueries(int n, std::vector<std::vector<int>>& queries){
    std::unordered_map<int, int> dict;
    for(int i = 0; i < n-1; ++i){
      dict[i] = i+1;
    }

    std::vector<int> answer;
    for(const auto& q: queries){
      int i = q[0], j = q[1];
      if(dict.find(i) != dict.end() && dict[i] < j){
        for(int v1 = i, v2; v1 < j; v1 = v2){
          v2 = dict[v1];
          dict.erase(v1);
        }
        dict[i] = j;
      }
      answer.push_back(dict.size());
    }

    return answer;
  }
};

int main(){
  Solution sol;
  std::vector<std::vector<int>> input = {{2, 4}, {0, 2}, {0, 4}};
  std::vector<int> answer = sol.shortestDistanceAfterQueries(5, input);

  for(auto& a : answer){
    std::cout << a << ' ';
  }
  std::cout << '\n';

  return EXIT_SUCCESS;
}