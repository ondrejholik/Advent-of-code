#include <iostream>
#include <string>
#include <vector>


enum Type  { empty, occupied, floor};

class Seat {
  Type t;
  Type nt;
  public:
    Seat(char s){
      if(s == '#'){
        t = occupied;
      }
      else if(s == '.'){
        t = floor;
      }

      else {
        t = empty;
      }
    }

    Type getT(){
      return t;
    }

    void setNext(Type next){
      nt = next;
    }

    bool change(){
      if(t == nt){
        return false;
      }
      t = nt;
      return true;
    }

    char getSign(){
      return t == occupied ? '#' : t == floor ? '.' : 'L';
    }
};


class Seats {
  std::vector<std::vector<Seat>> seats;

  public:
    Seats(){
     seats.reserve(1000); 
    }

    void addRow(std::string line){
      seats.push_back(stovos(line));
    }

    std::vector<Seat> stovos(std::string line){
      std::vector<Seat> tmp;
      for(auto x : line){
        tmp.push_back(Seat(x));
      }
      return tmp;
    }

    bool seekOccupied(int x, int y, int dirX, int dirY){
      x += dirX;
      y += dirY;
      while(x >= 0 &&
            y >= 0 &&
            x < seats.size() &&
            y < seats[0].size()){
        if(seats[x][y].getT() == occupied){
          return true;
        }
        else if(seats[x][y].getT() == empty){
          return false;
        }
        x += dirX;
        y += dirY;
      }
      return false;
    }

    bool isOccupied(size_t x, size_t y){
      int sum = 0;
      for(int i = -1; i < 2; ++i){
        for(int j = -1; j < 2; ++j){
          if(x + i >= 0 &&
             x + i < seats.size() &&
             y + j >= 0 && y + j < seats[0].size() &&
             (i != 0 || j != 0)){
            if(seekOccupied(x,y,i,j)){
              ++sum;
            }
          }
        }
      }
      return sum >= 5;
    }

    bool isEmpty(size_t x, size_t y){
      for(int i = -1; i < 2; ++i){
        for(int j = -1; j < 2; ++j){
          if(x + i >= 0 &&
             x + i < seats.size() &&
             y + j >= 0 && y + j < seats[0].size() &&
             (i != 0 || j != 0)){
            if(seekOccupied(x,y,i,j)){
              return false;
            }
          }
        }
      }
      return true;
    }
    

    bool next(){
      bool same = true;
      for(size_t i = 0; i < seats.size(); ++i){
        for(size_t j = 0; j < seats[0].size(); ++j){
          if(seats[i][j].change()){
            same = false;
          }
        }
      }
      return same;
    }

    int occupiedCount(){
      int occ = 0;
      for(size_t i = 0; i < seats.size(); ++i){
        for(size_t j = 0; j < seats[0].size(); ++j){
          occ += (seats[i][j].getT() == occupied) ? 1 : 0;
        }
      }
      return occ;
    }

    void precountNext(){
      for(size_t i = 0; i < seats.size(); ++i){
        for(size_t j = 0; j < seats[0].size(); ++j){
          if(isOccupied(i,j) && seats[i][j].getT() == occupied){
            seats[i][j].setNext(empty);
          }
          else if(isEmpty(i,j) && seats[i][j].getT() == empty){
            seats[i][j].setNext(occupied);
          }
          else {
            seats[i][j].setNext(seats[i][j].getT());
          }
        }
      }
    }

    void printBoard(){
    for(size_t i = 0; i < seats.size(); ++i){
        for(size_t j = 0; j < seats[0].size(); ++j){
          std::cout << seats[i][j].getSign();
        }
        std::cout << '\n';
      }
    std::cout << "---------------\n";
   }
};

int main(){
  std::string line;
  Seats sts;
  bool next = false;

  while(std::cin >> line){
    sts.addRow(line);
  }

  do {
    sts.printBoard();
    sts.precountNext();
    next = sts.next();
  } while(!next);

  std::cout << sts.occupiedCount()<< '\n';

  return 0;
}
