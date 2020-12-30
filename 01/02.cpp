#include <iostream>
#include <set>
#include <fstream>
#include <string>

using namespace std;

int search_for(int num, set<int> nums){
  for(auto n : nums){
    if(nums.contains(num - n)){
      return (num-n)*n;
    }


  }
  return 0;

}

int main(){

  ifstream infile("01.txt");

  set<int> nums;

  string line;
  while (std::getline(infile, line)){
  int a = stoi(line);
  nums.insert(a);
  }


  for(auto a : nums){
    int b = 2020-a;
    int search = search_for(b, nums);
    if(search != 0){
      cout << a * search << '\n';
      break;
    }
  }


}
