#include <iostream>
#include <set>
#include <string>
#include <fstream>
#include <iterator>
#include <vector>




using namespace std;

int main(){

  //change to char...
  set<char> questions;
  set<char> tmp;
  bool tmp_changed = false;
  long int sum = 0;
  std::ifstream input( "./input.txt", ios::binary);

  // copies all data into buffer
  vector<unsigned char> buffer(istreambuf_iterator<char>(input), {});

  for(auto a = buffer.begin(); a != buffer.end(); ++a){
    if(*a == '\n' && *(a+1) == '\n'){
      if(tmp.size() != 0 || tmp_changed){
        set<char> intersect;
        set_intersection(tmp.begin(),tmp.end(),questions.begin(),questions.end(),
        inserter(intersect,intersect.begin()));
        cout << intersect.size() ;
        cout << '\n';
        tmp = intersect;
        sum += tmp.size();
        intersect.clear();
        cout << tmp.size() << '\n';
        cout << "------------+\n";
        ++a;
      }

      else {
        sum += questions.size();
        cout << questions.size() << '\n';
        cout << "-------------\n";
      }

      questions.clear();
      tmp.clear();
      tmp_changed = false;
    }

    else if(*a != '\n'){
      questions.insert(*a);
    }

    else {
      if(tmp.size() == 0){
        tmp_changed = true;
        tmp = questions;
        questions.clear();
      }

      else {
        set<char> intersect;
        set_intersection(tmp.begin(),tmp.end(),questions.begin(),questions.end(),
                  std::inserter(intersect,intersect.begin()));
        tmp = intersect;
        questions.clear();
        intersect.clear();
      }
    }
  }

  cout << sum << '\n';
}
