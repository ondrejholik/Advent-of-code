#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>



using namespace std;

int main(){

  
  string s;
  int index = 0;
  const int mod = 31;

  std::ifstream infile("03_new.txt");

  int sum1 = 0;
  int sum2 = 0;
  int sum3 = 0;
  int sum4 = 0;
  int sum5 = 0;

  int index1 = 0;
  int index2 = 0;
  int index3 = 0;
  int index4 = 0;
  int index5 = 0;


  getline(infile, s);
  while (getline(infile, s)){
    index1 += 1;
    index2 += 3;
    index3 += 5;
    index4 += 7;
    index5 += index1 % 2 == 0? 1 : 0;

    int modIndex1 = s[index1%mod];
    int modIndex2 = s[index2%mod];
    int modIndex3 = s[index3%mod];
    int modIndex4 = s[index4%mod];
    int modIndex5 = s[index5%mod];
    if(modIndex1 == '#'){
      ++sum1;
    }
    if(modIndex2 == '#'){
      ++sum2;
    }

    if(modIndex3 == '#'){
      ++sum3;
    }

   if(modIndex4 == '#'){
      ++sum4;
    }

   if(modIndex5 == '#' && index1 % 2 == 0){
      ++sum5;
    }
  }

  cout << (long int)sum1*sum2*sum3*sum4*sum5<< '\n';


    


    


}
