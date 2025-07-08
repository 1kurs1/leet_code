#include <iostream>
#include <vector>

// unsigned long long factorial(unsigned long long num){
//   if(num == 0 || num == 1) return 1;
//   return factorial(num-1) * num;
// }

// int combination(unsigned long long n, unsigned long long k){
//   int r = (factorial(n))/((factorial(k))*(factorial(n-k)));
//   return r;
// }

std::vector<int> getRow(int rowIndex) {
  std::vector<int> row(1, 1);

  for (int i = 0; i < rowIndex; i++) {
      std::vector<int> newRow;
      newRow.push_back(1);
      for (int j = 1; j < row.size(); j++) {
          newRow.push_back(row[j - 1] + row[j]);
      }
      newRow.push_back(1);
      row = newRow;
  }

  return row;   
}

int main(){
  std::vector<int> g = getRow(3);
  for(int i = 0; i < g.size(); i++){
    std::cout << g[i] << ' ';
  }
  std::cout << '\n';
  return EXIT_SUCCESS;
}