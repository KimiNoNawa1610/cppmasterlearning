#ifndef BOX_H
#define BOX_H

#include<string>
#include<iostream>
#include<sstream> // Include the header for stringstream

using namespace std;

class Box{

public:
  double length, width, height;
  string boxString;
  Box();
  Box(double l, double w, double h);
  virtual ~Box();
  Box& operator ++(){ // this is the prefix increment operator 
    length++;
    width++;
    height++;
    return *this;
  }
  // operator std::string(){
  //   ostringstream boxStream;
  //   boxStream<< "Box: "<<length<<", " <<width<<", " <<height;
  //   return boxStream.str();
  // }
};

#endif// BOX_H