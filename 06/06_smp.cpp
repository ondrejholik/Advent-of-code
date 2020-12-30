#include <iostream>
#include <set>
#include <string>
#include <fstream>
#include <iterator>
#include <vector>




using namespace std;


void write(set<char> con){
  cout << '{';
  for(auto x : con){
    cout << x << ' ';
  }
  cout << "}\n";
}

int main(){

  //change to char...
  set<char> question;
  vector<set<char>> questions;
  vector<vector<set<char>>> dataset;
  bool tmp_changed = false;
  long int sum = 0;
  std::ifstream input( "./input.txt", ios::binary);

  bool writed = false;
  // copies all data into buffer
  vector<unsigned char> buffer(istreambuf_iterator<char>(input), {});

  for(auto a = buffer.begin(); a != buffer.end(); ++a){
    if(*a == '\n' && *(a+1) == '\n'){
      questions.push_back(question);
      write(question);

      dataset.push_back(questions);
      cout << questions.size() << '\n';
      cout << "\n---------------\n";
      question.clear();
      questions.clear();
      writed = false;
      ++a;
    }

    else if(*a != '\n'){
      writed = true;
      question.insert(*a);
      cout << *a << ' ';
    }

    else if(*a == '\n'){
      if(!writed){
        continue;
      }
      questions.push_back(question);
      write(question);
      question.clear();
      cout << '\n';
    }
  }

  cout << "#################\n";
  set<char> tmp;
  int index = 0;
  for(auto itd = dataset.begin(); itd != dataset.end(); ++itd){
    bool isFirst = true;
    cout << "----------------\n";
    for(auto it = itd->begin(); it != itd->end(); ++it){
      for(auto x: *it){
        cout << x << ' ';
      }
      cout << '\n';
      if(isFirst){
        tmp = *it;
        isFirst = false;
        continue;
      }
      set<char> intersect;
      set_intersection(tmp.begin(),tmp.end(), it->begin(), it->end(),
        inserter(intersect,intersect.begin()));
      tmp = intersect;
      intersect.clear();
    }

    cout << tmp.size() << '\n';
    sum += tmp.size();
    tmp.clear();
  }

  cout << "++++++++++++++++\n";
  cout << sum << '\n';
  ++index;
}
