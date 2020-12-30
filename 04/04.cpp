#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <set>


using namespace std;

class Passport {

  private:
    int byr;
    int iyr;
    int eyr;
    bool hgt;
    string hcl;
    string ecl;
    string pid; 

  public:
    Passport(string data){
      byr = parse("byr", data);
      iyr = parse("iyr", data);
      eyr = parse("eyr", data);
      hgt = heightVal(data);
      hcl = sparse("hcl", data);
      ecl = sparse("ecl", data);
      pid = sparse("pid", data);
    }

    string sparse(string atr, string data){
      int b = data.find(atr+":") + atr.size()+1;
      int e = data.find(' ', b);
      return data.substr(b, e-b);

    }

    int parse(string atr, string data){
      return stoi(sparse(atr, data));
    }


    bool heightVal(string data){
      string height = sparse("hgt", data);
      if(height.find("in") != string::npos){
        height.pop_back();
        height.pop_back();
        int val = stoi(height);
        return val >= 59 && val <= 76;
      }

      else if (height.find("cm") != string::npos){
        height.pop_back();
        height.pop_back();
        int val = stoi(height);
        return val >= 150 && val <= 193;
      }

      return false;
    }

    bool isValid(){

      return yearCheck(byr, 1920, 2002) &&
             yearCheck(iyr, 2010, 2020) &&
             yearCheck(eyr, 2020, 2030) &&
             isColorValid(hcl) &&
             hgt && 
             isEyeValid(ecl) &&
             isPidValid(pid);
    }

    bool isPidValid(string pid){
      if(pid.size() != 9){
        return false;
      }

      for(auto a : pid){
        if(int(a) < 48 || int(a) > 57){
          return false;
        }
      }
      return true;
    }

    bool isEyeValid(string color){
      set<string> colors = {"amb", "blu", "brn", "gry", "grn", "hzl", "oth"};
      return colors.contains(color);
    }

    constexpr bool yearCheck(int year, int from, int to){
      return from <= year && year <= to;
    }

    bool isColorValid(string hex){
      if(hex[0] != '#' || hex.size() != 7){
        return false;
      }

      for(auto it = hex.begin()+1; it != hex.end(); ++it){
        if(!((int(*it) >= 97 && int(*it) <= 102) || (int(*it) >= 48 && int(*it) <= 57))){
          return false;
        }
      }
      return true;
    }

};

bool isValid(string text, vector<string> el){
  for(vector<string>::iterator e = el.begin(); e != el.end(); ++e){
    auto result = text.find(*e);
    if(result == string::npos){
      return false;
    }

  }

  Passport pass(text);
  return pass.isValid();
}

int main(){

  string line;
  string text;
  int sum = 0;
  vector<string> el = {"byr:", "iyr:", "eyr:", "hgt:", "hcl:", "ecl:", "pid:"};
  while (getline(cin, line)){
    if(line.size() < 2){
      sum += isValid(text, el) ? 1 : 0;
      text = "";
    }
    else {
      if(line.find('\n') != string::npos){
        line.erase('\n');
      }
      text += " " + line;
    }
  }

  cout << sum << '\n';


}
