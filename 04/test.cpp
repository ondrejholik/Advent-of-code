#include <iostream>
#include <string>


using namespace std;

void parse(string atr, string data){
  int b = data.find(atr+":") + atr.size()+1;
  int e = data.find(' ', b);
  cout << atr << '\n';
  cout << data.substr(b, e-b) << '\n';
  cout << "------------\n";

}


int main(){

  string test = "hcl:5d90f0 cid:270 ecl:#66dc9c hgt:62cm byr:1945 pid:63201172 eyr:2026";

  parse("ecl", test);
  parse("byr", test);
  parse("pid", test);




}
