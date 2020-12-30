#include <iostream>
#include <cmath>
#include <string>

using namespace std;

class Ship {
  int x;
  int y;
  int rotation;

  public:
    Ship(){
      x = 0;
      y = 0;
      rotation = 0;
    }

    double distanceFromStart(){
      //return sqrt(x*x + y*y);
      return abs(x) + abs(y);
    }

    int getX(){
      return x;
    }

    int getY(){
      return y;
    }

    void forward(Ship s, int value){
      int tmp_x = s.getX();
      int tmp_y = s.getY();

      x += value * tmp_x;
      y += value * tmp_y;
    }

    void north(int value){

      y += value;
    }

    void south(int value){
      y -= value;
    }

    void west(int value){
      x -= value;
    }

    void east(int value){
      x += value;
    }

    int getAngle(int value){
      return (360 + value) % 360;
    }

    double radian(int degrees){
      return (3.1415926535/180)*degrees;
    }

    void right(Ship ship, int value){
      int tmp_x = ship.getX();
      int tmp_y = ship.getY();

      int sol1 = tmp_x - x;
      int sol2 = tmp_y - y;

      int angle = getAngle(value);

      double rad = -radian(angle);

      x = x*cos(rad) + y*sin(rad);
      y = y*cos(rad) - x*sin(rad);

      x += tmp_x;
      y += tmp_y;
    }

};


    int main(){
      Ship ship;
      Ship way;
      way.east(10);
      way.north(1);
      string line;
      cout << "Ship [" << ship.getX() << ','<<  ship.getY() << "], Waypoint: [" << way.getX() << ',' << way.getY() << "]\n";

      while(cin >> line){
        char dir = line[0];
        line.erase(0,1);
        int value = stoi(line);

        if(dir == 'F'){
          ship.forward(way, value);
        }
         
        else if(dir == 'N'){
          way.north(value);
        }

        else if(dir == 'W'){
          way.west(value);
        }

        else if(dir == 'E'){
          way.east(value);
        }

        else if(dir == 'S'){
          way.south(value);
        }

        else if(dir == 'R'){
          way.right(ship, value);
        }

        else if(dir == 'L'){
          way.right(ship, -value);
        }

        else {
          cerr << "Error, when parsing input.";
          return -1;
        }
        cout << "Ship [" << ship.getX() << ','<<  ship.getY() << "], Waypoint: [" << way.getX() << ',' << way.getY() << "]\n";
      }
      cout << ship.distanceFromStart() << '\n';
    }
