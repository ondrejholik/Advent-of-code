#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <numeric>
#include <algorithm>
#include <iterator>


using namespace std;


bool hasSum(long long unsigned int num, set<long long unsigned int> cnums, vector<long long unsigned int> vnums){
  for( auto x : cnums){
    if(num < x){
      continue;
    }

    if(cnums.contains(num - x)){
      return true;
    }
  }
  return false;
}

void printvec(auto vec){

  for(auto x : vec){
    cout << x << ' ';
  }
  cout << '\n';

}


bool findSum(auto allnums,long long unsigned int num){
  for(size_t from = 0; from < allnums.size(); ++from){
    for(size_t i = 2; i < allnums.size()-from; ++i){
      if( accumulate(allnums.begin()+from,
          allnums.begin()+from+i,0) == num){
        auto min = 0;
        auto max = 0;
        size_t count = 0;
        for(auto x = allnums.begin()+from; x != allnums.begin()+from+i; ++x){
          if( count == 0){
            min = *x;
            max = *x;
          }
          if(min > *x){
            min = *x;
          }
          if(max < *x){
            max = *x;
          }
          ++count;
        }
        cout << min << ' ' << max << '\n';
        cout << min + max << '\n';
        return true;
      }
    }
  }
  return false;
}



int main(){

  string line;
  int capacity = 25;
  set<long long unsigned int> cnums;
  vector<long long unsigned int> vnums;
  vector<long long unsigned int> allnums;
  long long unsigned int num = 0;
  size_t counter = 0;

  while(cin >> line){
    num = stoll(line);
    allnums.push_back(num);

    if(counter < capacity){
      cnums.insert(num);
      vnums.push_back(num);
    }
    else {
        printvec(cnums);
      if(hasSum(num, cnums, vnums)){
        long long unsigned int first = vnums[0];
        cnums.erase(first);
        vnums.erase(vnums.begin());

        cnums.insert(num);
        vnums.push_back(num);
      }

      else {
        cout << num << '\n';
        //pair<long long unsigned int, long long unsigned int> mm = minmax_element(vnums.begin(), vnums.end());
        //cout << *mm.first << ' ' << *mm.second << '\n';
        //cout << *cnums.begin() << ' ' << *cnums.end() << '\n';
        break;
      }
    }
    ++counter;
  }

  findSum(allnums, num);

}
