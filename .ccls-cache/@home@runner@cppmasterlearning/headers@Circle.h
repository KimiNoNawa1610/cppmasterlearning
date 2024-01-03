#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"

class Circle: public Shape{

public:
  Circle();
  Circle(const Circle& orig);
  Circle(double radius);
  double GetArea();
  virtual ~Circle();

private:

};


#endif // CIRCLE_H