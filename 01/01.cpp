#include <iostream>
#include <set>
#include <fstream>
#include <string>

using namespace std;

int main(){

  ifstream infile("01.txt");

  set<int> nums;

  string line;
  while (std::getline(infile, line)){
  int a = stoi(line);
  nums.insert(a);
  }


  for(auto a : nums){
    if(nums.contains(2020-a)){
      cout << a * (2020-a) << '\n';
      break;
    }
  }


}
