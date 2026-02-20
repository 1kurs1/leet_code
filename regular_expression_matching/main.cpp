#include <iostream>
#include <string>
#include <cstring>

bool isMatch(std::string s, std::string p){
    int n = s.length(), m = p.length();
    bool dTable[n+1][m+1];
    memset(dTable, false, sizeof(dTable));
    dTable[0][0] = true;

    for(size_t i = 0; i <= n; ++i){
      for(size_t j = 1; j <= m; ++j){
        if(p[j-1] == '*') 
          dTable[i][j] = dTable[i][j-2] || (i > 0 && (s[i-1] == p[j-2] || p[j-2] == '.') && dTable[i-1][j]);
        else
          dTable[i][j] = i > 0 && dTable[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '.');
      }
    }
    
    return dTable[n][m];
  }

int main(){
  std::cout << isMatch("aab", "c*a*b") << '\n';

  return EXIT_SUCCESS;
}