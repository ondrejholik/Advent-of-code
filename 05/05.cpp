#include <iostream>
#include <string>
#include <cmath>
#include <set>


using namespace std;

int row_replace(string row){
  int result = 0;
  int index = row.size()-1;
  for(auto r : row){
    result += r == 'F' ? 0 : pow(2,index);
    --index;
  }

  return result;
}

int column_replace(string column){
  int result = 0;
  int index = column.size()-1;
  for(auto c : column){
    result += c == 'L' ? 0 : pow(2,index);
    --index;
  }

  return result;

}



int main(){

  int max = 0;
  string line;
  set<int> ids;
  while(cin >> line){
    string row = line.substr(0, 7);
    string column = line.substr(7, 3);
    int rowval = row_replace(row);
    int colval = column_replace(column);
    ids.insert(rowval*8 + colval);
    if(rowval * 8 + colval > max){
      max = rowval*8 + colval;
    }
  }

  int prev = 0;
  for(auto x : ids){

    if(x != prev+1 && prev != 0){
      cout << '#' << x-1 << '\n';
    }
    prev = x;
  }
}
