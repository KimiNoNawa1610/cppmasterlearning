#ifndef SHAPE_H
#define SHAPE_H

class Shape{
public: // public access specifier
// can be accessed from outside the class

  static int numOfShape; // static variable ca be accessed without creating an object of the class
  Shape(); // default constructor
  Shape(double length);
  Shape(double height, double width);

  virtual ~Shape(); // destructor

  void SetHeight(double height);
  void SetWidth(double width);
  double GetHeight() const;
  double GetWidth() const;
  static int GetNumOfShape(); // static function can be accessed without creating an object of the class

  virtual double GetArea(); // will be overriden in derived classes

private: // private access specifier
// can be accessed only from inside the class

protected: // protected access specifier
// can be accessed from inside the class and by derived classes
  double height;
  double width;
};

#endif // SHAPE_H