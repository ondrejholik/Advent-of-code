#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>



using namespace std;

int main(){

  
  string s;
  int sum = 0;

  std::ifstream infile("02.txt");

  while (getline(infile, s))
  {
    
    string delimiter = "-";
    int pos = s.find(delimiter);
    string token = s.substr(0, pos); 
    int from = stoi(token);

    delimiter = " ";
    int tmp = s.find(delimiter, pos+1);
    token = s.substr(pos+1, tmp); 
    pos = tmp;
    int to = stoi(token);

    delimiter = ":";
    tmp = s.find(delimiter, 0);
    token = s.substr(pos, tmp); 
    char letter = s[tmp-1];


    string rest = s.substr(tmp+2, s.size());

    bool val1 = letter == rest[from-1];
    bool val2 = letter == rest[to-1];

    string result = (val1 ^ val2)? "True":"False";

    cout << from << ' ' << to << ' ' <<  letter << ' ' << rest << '\n';
    cout << val1 << '^' << val2 << " = " <<  result  << '\n';
    cout << "---------------\n";
    if(val1 ^ val2){
      ++sum;
    }

  }

  cout << sum << '\n';


    


    


}
