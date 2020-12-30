#include <iostream>
#include <set>
#include <string>
#include <vector>


using namespace std;

enum I {
  jmp,
  acc,
  nop
};

class Instruction{
  private:
    int value; 
    I instruction;
  public:
    Instruction(string _inst){
      string i = _inst.substr(0, 3);
      value = stoi(_inst.substr(4, _inst.size()-4));
      if(i == "acc"){
        instruction = acc;
      }
      else if(i == "jmp"){
        instruction = jmp;
      }
      else{
        instruction = nop;
      }
    }

    int getValue(){
      if(instruction != acc){
        return 0;
      }
      return value;
    }

    bool isJump(){
      return instruction == jmp;

    }

    int getJump(){
      return value;
    }
};

void vecprint(auto acc_sum, bool end){

  long long int sum = 0;
  for(auto x : acc_sum){
    sum += x;
  }

  cout << "--------------";
  end ? cout << '+' : cout << '-' ;
  cout << '\n';
  cout << sum << '\n';
}



int main(){

  vector<Instruction> instructions;
  set<int> done_instructions;
  vector<int> acc_sum;
  string line;
  while(cin >> line){
    Instruction i(line);
    instructions.push_back(i);
  }

  for(int x = 0; x < instructions.size(); ++x){
    done_instructions.insert(x);
    acc_sum.push_back(instructions[x].getValue());
    if(instructions[x].isJump()){
      x = x + instructions[x].getJump()-1;
      if(done_instructions.contains(x+1)){
        vecprint(acc_sum, false);
        return 1;
      }
    }
  }
  vecprint(acc_sum, true);

}
