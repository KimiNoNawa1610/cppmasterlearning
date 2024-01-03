#include "../headers/Circle.h"
#include <cmath>

Circle::Circle(double radius) : Shape(radius) {}// call shape constructor

Circle::~Circle() = default;

double Circle::GetArea() {
  return M_PI * this->width * this->width;
}

