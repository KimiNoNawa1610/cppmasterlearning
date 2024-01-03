#include "../headers/Shape.h"

// constructors
Shape::Shape(double length){
  this->height = length; // pointer operator to access the height variable
  this->width = length;
}

Shape::Shape(double height, double width){
  this->height = height; // pointer operator to access the height variable
  this->width = width; 
}

Shape::Shape(){
  
}

// default destructor
Shape::~Shape() = default;

// setters and getters
void Shape::SetHeight(double height){
  this->height = height;
}

void Shape::SetWidth(double width){
  this->width = width;
}

double Shape::GetHeight() const{
  return this->height;
}

double Shape::GetWidth() const{
  return this->width;
}

int Shape::GetNumOfShape(){
  return numOfShape;
}

double Shape::GetArea(){
  return this->height * this->width;
} // poliymorphism

int Shape::numOfShape = 0;
