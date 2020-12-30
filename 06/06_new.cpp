#include <vector>
#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char * argv[]){
    ifstream infile;
    string filename = "questions.txt";//manually set for testing.

    //cout<<"Enter the questions file: ";
    //cin>>filename;

    infile.open(filename.c_str());

    if (!infile){
            cout<<"error"<<endl;
            return 0;
    }
    else {
            cout<<"file opened!"<<endl;
    }
    vector<string> myVec;

    string line;
    string comboLine="";

    while(!infile.eof()){
            getline(infile,line);

            if (line == "" || line == "\0")  {
                    //cout<<"->BLANK LINE DETECTED<-"<<endl;
                    myVec.push_back(comboLine);
                    comboLine="";
            }else {
                    comboLine = comboLine + line;
                    //cout<<"comb: "<<comboLine<<endl;
            }

            line = "";

    }
    infile.close();

    //TESTING
    cout<<"Question: "<<endl;
    cout<<myVec[0]<<endl;
    cout<<"Answer: "<<endl;
    cout<<myVec[1]<<endl;
    cout<<"Question 2: "<<endl<<myVec[2]<<endl;
    cout<<"Answer 2: "<<endl<<myVec[3]<<endl;
    return 0;

