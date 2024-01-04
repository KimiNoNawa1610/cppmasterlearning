#include <iostream>
#include <cstdlib>
#include <string>
#include <limits>
#include <sstream>
#include <numeric>
#include <ctime>
#include <cmath>
#include <vector>
#include <array> 
#include <algorithm>
#include <fstream>
#include <functional>
#include "headers/Shape.h"
#include "headers/Circle.h"
#include "headers/Box.h"

using namespace std;

int imGlobal = 0; // Global variable

const double PI = 3.14159265358979323846; // Constant value that cannot be changed

double addNumbers(double num1,double num2);// function declaration

void assignAge(int* age); // function declaration with pointer
                          // pointer is a variable that stores the address of another variable

void ShowArea(Shape& shape);

double addNumbers(double num1 = 0,double num2 = 0){ // function definition
  return num1+num2;
}

void doubleArray(int *arr, int size){ // we can pass an array to a function
  for(int i = 0; i < size; i++){ // pointer arithmetic
    arr[i] = arr[i] * 2;
  }
}

void assignAge(int* age){
  *age = 23;
}

// different from a class, struct are default at public
// we can still make a private attribute in struct like a class
struct sShape{
  double length, width;
  sShape(double l=1,double w=1){
    length = l;
    width = w;
  }

  double area(){
    return length * width;
  }

};

// struct are also able to inherit each other
struct sCircle: sShape{
  sCircle(double r=1):sShape(r){
    this->width = r;
  }
  double Area(){
    return PI * this->width * this->width;
  }
};

vector<int> GenerateRandVect(int numOfNums,int min, int max); // this is a function that generates a vector of random numbers

double MultBy2(double num){
  return num * 2;
}

// function as a parameter of another function
double DoMath(function<double(double)> func,double num){ 
  // syntax to pass a function as a parameter of other function
  // function<returnType(parameterType)> funcName
  return func(num);
}

#define Pi 3.14159
// defind a macro
// the macro will be replaced by the value 3.14159

#define CIRCLE_AREA(r) (Pi*r*r)
// macro function
// the macro will be replaced by the value Pi*r*r

// Template
// template is different from function overloading
// template is a way to create a function that can be used to do a same task with different data types (objects)
// function overloading is a way to create a function that can do similar thing with different object

template <typename T> // T is a generic type
void Times2(T val){ // T is a template parameter
  cout<< val<< " * 2 = "<< val*2<<endl;
}

int main() {
  cout << "Hello World!"<<endl;
  cout << "\n---BASIC TYPES---\n"<<endl;

  printf("Pi number is %f\n", PI);

  bool married = true; // true or false

  printf("Is Married = %d\n",married);

  char myGrade = 'A'; // single character

  printf("My Grade = %c\n",myGrade);

  float f1 = 1.11111111; // float only accurate to 6 digits

  printf("Sum = %.7f\n", f1); // prints 7 digits

  auto whatAmI = true; // auto detects the type

  cout<<"\n---SIZE OF TYPES---\n" <<endl;

  cout << "Size of bool = " << sizeof(bool) << " bytes" << endl;
  cout << "Size of char = " << sizeof(char) << " bytes" << endl;
  cout << "Size of int = " << sizeof(int) << " bytes" << endl;
  cout << "Size of float = " << sizeof(float) << endl;
  cout << "Size of double = " << sizeof(double) << endl;
  cout << "Size of auto depending on the variable = "<< sizeof(whatAmI) << endl;

  cout<<"\n---BASIC MATHEMATICAL OPERATION---\n"<<endl;

  string q1 = "Enter a Number: ";
  string num1,num2;
  cout << q1;
  cin >> num1;
  cout << "Enter another Number: ";
  cin >> num2;

  // %d is for int
  // %f is for float
  // to format decimal for float use %.[num]f
  // %s is for string
  // %c is for char
  // %lf is for double
  // %Lf is for long double
  // %p is for pointer
  // %x is for hexadecimal
  // %o is for octal
  
  printf("%d+%d=%d\n" , stoi(num1),stoi(num2),stoi(num1)+stoi(num2)); // addition
  printf("%d-%d=%d\n" , stoi(num1),stoi(num2),stoi(num1)-stoi(num2)); // subtraction
  printf("%d*%d=%d\n" , stoi(num1),stoi(num2),stoi(num1)*stoi(num2)); // multiplication
  printf("%f/%f=%f\n" , stof(num1),stof(num2),stof(num1)/stof(num2)); // division with float
  printf("%d%%%d=%d\n" , stoi(num1),stoi(num2),stoi(num1)%stoi(num2)); // modulus

  cout<<"\n---LOGICAL OPERATOR---\n"<<endl;

  string sAge;
  cout<<"Enter your age: ";
  cin>>sAge;
  int nAge = stoi(sAge);

  if(nAge>=1 and nAge<18){
    cout<<"Important Birthday"<<endl;
  }
  else if(nAge>=21){
    cout<<"Important Birthday"<<endl;
    cout<<"You can drink"<<endl;
  }
  else if (nAge==65){
    cout<<"You are retired"<<endl;
  }
  else{
    cout<<"Not Important Birthday"<<endl;
  }

  bool canVote = (nAge>=18) ? true : false; // Ternary operator
  string scanVote = (canVote) ? "can" : "cannot";
  // instead of creating string scanVote, 
  // we can directly use cout<< (canVote) ? "can" : "cannot";
  // or we can use cout.setf(ios::boolalpha); to print out true or false instead of 0 and 1
  cout<<"Can I vote: "<<scanVote<<endl;

  cout<<"\n---ARRAY---\n"<<endl;

  // Array is a collection of elements of the same type
  // The elements are stored in a contiguous block of memory
  // Array index start from 0
  // The size of an array is the number of elements in the array
  // Array size is immutable, cannot be changed (cannot add or remove elements)
  // but the elements can be changed
  
  int arrNums[10] = {1,2,3,4,5,6,7,8,9,10}; // array of 10

  cout<<arrNums<<endl; // this will only give the address of the first element
  cout<<"Array Size = "<<sizeof(arrNums)/sizeof(arrNums[0])<<endl; // this will give the size of the array
  // to get the acutal value of the array, we need to use a loop
  for(int i=0;i<10;i++){
    cout<<arrNums[i]<<endl;
  }

  // two dimensional array
  // the first number is the number of rows
  // the second number is the number of columns
  int arr2D[3][3] = {{1,2,3},{4,5,6}};
  cout<<"2D Array Elements = "<<sizeof(arr2D)/sizeof(arr2D[0])<<endl; // this will give the size of the array"
  
  cout<<"\n---VECTOR---\n"<<endl;

  // Vector is a dynamic array
  // The size of a vector is the number of elements in the vector
  // Vector is mutable, we can add or remove elements
  
  vector<int> vecNums; // empty vector
  vector<int> vecNums2(2); // vector with 2 elements
  vecNums.push_back(1);
  vecNums.push_back(2);
  vecNums.push_back(3);

  vecNums2[0] = 4;
  vecNums2[1] = 5;

  cout<<"Vector Size = "<<vecNums.size()<<endl; // size of the vector

  cout<<"Vector Size = "<<vecNums2.size()<<endl; // size of the vector

  // to get the acutal value of the vector, we need to use a loop

  cout<<"\n---LOOPING---\n"<<endl;

  int i = 1;
  while(i<=20){ // this is while loop
    cout<<i<<endl; // execute while the condition is true
    i++;
    // becareful not to create an infinite loop
  }

  for(int j=1;j<=20;j++){ // this is for loop
    cout<<j<<endl;
  }

  vector<string> words;
  stringstream ss("Some Random Words");
  string word;
  
  while(getline(ss,word,' ')){
    words.push_back(word);
  }

  for(int i=0;i<words.size();i++){
    cout<<words[i]<<endl;
  }

  for(auto x: words){// this is for each loop, similar to Python for i in array
    cout<<x<<endl; 
  }

  cout<<"\n---STRING---\n"<<endl;

  string str1 = "I'm a string"; // double quotes for string
  cout<< "1st: "<<str1[0]<<endl;
  cout<< "last: "<<str1.back()<<endl;
  cout<< "length: "<<str1.length()<<endl;
  string str2 = str1; // string copy
  string str3 = str1.substr(0,3); // substring
  string str4  = str1.append(str2); // string append
  cout<<str4<<endl;
  str4.erase(0,3); // erase string from position to position
  cout<<str4<<endl;
  str4.insert(0,"Hello "); // insert string at position
  cout<<str4<<endl;
  cout<<str4.find("string")<<endl;

  char letterZ = 'z'; // use single quotes for char
  char letterA = 'a';
  char aSpace = ' '; 
  cout<<letterZ-letterA<<endl; // this will give the ASCII value of the character
  cout<<isalpha(aSpace)<<endl; // check if a character is alphabetic
  cout<<isalnum(aSpace)<<endl; // check if a character is alphanumeric
  cout<<isdigit(aSpace)<<endl; // check if a character is a digit
  cout<<islower(aSpace)<<endl; // check if a character is lowercase
  cout<<isupper(aSpace)<<endl; // check if a character is uppercase
  cout<<isspace(aSpace)<<endl; // check if a character is whitespace

  // convert function 
  cout<<toupper(letterA)<<endl; // convert a character to uppercase
  cout<<tolower(letterZ)<<endl; // convert a character to lowercase

  // stringstream
  stringstream ss1; // create a stringstream
  // stringstream is used to convert a string to a number
  ss1<<"123"; // add a number to the stringstream
  int nums1;
  ss1>>nums1; // convert the stringstream to a number
  cout<<nums1<<endl;
  
  // stringstream can also be used to convert a string to a character
  stringstream ss2;
  ss2<<"A";
  char letter;
  ss2>>letter;
  cout<<letter<<endl;
  
  // stringstream can also be used to convert a string to a boolean
  stringstream ss3;
  ss3<<"true";
  bool bool1;
  ss3>>bool1;
  cout<<bool1<<endl;

  // overall stringstream is used to convert a string to a number, character, boolean

  cout<<"\n---MATH---\n"<<endl;

  // math functions
  
  // abs() returns the absolute value of a number
  cout<<abs(-10)<<endl;
  
  // acos() returns the arc cosine of a number
  cout<<acos(0.5)<<endl;

  // asin() returns the arc sine of a number
  cout<<asin(0.5)<<endl;

  // atan() returns the arc tangent of a number
  cout<<atan(0.5)<<endl;

  // sqrt() returns the square root of a number
  cout<<sqrt(4)<<endl;

  // cbrt() returns the cube root of a number
  cout<<cbrt(8)<<endl;

  // ceil() returns the smallest integer value not less than x
  cout<<ceil(2.5)<<endl;

  // sin() returns the sine of a number
  cout<<sin(0.5)<<endl;

  // cos() returns the cosine of a number
  cout<<cos(0)<<endl;

  // cosh() returns the hyperbolic cosine of a number
  cout<<cosh(0)<<endl;

  // exp() returns the value of e raised to the power of x
  cout<<exp(0)<<endl;

  // exp2() returns the value of 2 raised to the power of x
  cout<<exp2(0)<<endl;

  // max() returns the largest of two numbers
  cout<<max(10,20)<<endl;

  // min() returns the smallest
  cout<<min(10,20)<<endl;

  // pow() returns the value of x raised to the power of y
  cout<<pow(2,3)<<endl;

  // floor() returns the largest integer value not greater than x
  cout<<floor(2.5)<<endl;

  // fma() returns the value of x*y+z
  cout<<fma(2,3,4)<<endl;

  // fmax() returns the largest of two numbers
  // fmax() is different from max() that it used floaing point numbers instruction
  cout<<fmax(10,20)<<endl;

  // fmin() returns the smallest of two numbers
  cout<<fmin(10,20)<<endl;

  // log() returns the natural logarithm of x
  cout<<log(2)<<endl;

  cout<<"\n---FUNCTIONS---\n"<<endl;

  // function is a block of code that performs a specific task
  // function can be called anywhere in the program
  // function can be called multiple times
  // function can be called with different parameters
  // function can return a value
  // function can return multiple values
  // function can be overloaded
  // we can pass a value or a reference to a function

  printf("%.2f\n" , addNumbers(2.5,3.5)); // function call
  int age = 14;
  cout<<age<<endl;
  assignAge(&age); // to pass a reference to a function we use the ampersand
  cout<<age<<endl;

  cout<<"\n---POINTERS---\n"<<endl;
  int* age2 = NULL;
  cout << age2<<endl; // this will give the address of the variable
  cout << *age2<<endl; // this will give the value of the variable
  int* age3 = &age; // this will make age3 point to the address of age
  cout<<age3 <<endl;

  int intArr[] = {1,2,3,4,5,6};
  int * pArr = intArr;
  cout<<pArr<<endl; // this will give the address of the first element of the array
  pArr++; // this will move the pointer to the next element
  cout<<pArr<<endl; // this will give the address of the second element of the array
  cout<<*pArr<<endl; // this will give the value of the second element of the array
  doubleArray(intArr,6); // this will double the values of the array
  for (int i=0;i<6;i++){
    cout<<intArr[i]<<endl;
  }

  cout<<"\n---EXCEPTIONS HANDLING---\n"<<endl;
  double num3 = 10.12, num4 = 0.00;

  try{
    if (num4 ==0){
      throw "Division by zero";
    }
    else{
      printf("The divison result of %.2f and %.2f  is: %.2f\n", num3, num4, num3/num4);
    }
    
  } catch(const char* exp){
    cout<<"ERROR: "<<exp<<endl;
  }

  cout<<"\n---OBJECTS/CLASSES---\n"<<endl;

  // object is a variable that contains data and functions

  Shape regtangle(10,5);
  Circle circle(10);
  ShowArea(regtangle);
  ShowArea(circle);

  cout<<"\n---STRUCT---\n"<<endl;

  // struct is a data type that can be used to group related variables into one place
  // struct is used to create a new data type
  sShape sph1(10,10);
  cout<<sph1.area()<<endl;
  sCircle scor(5);
  cout<<scor.area()<<endl;

  cout<<"\n---OPERATOR OVERLOAD---\n"<<endl;
  
  Box box(10,10,10);
  ++box;

  cout<<"\n---LAMBDA EXPRESSION---\n"<<endl;

  // lambda expression is a way to create a function without defining a function
  // lambda expression is a function without a name
  // lambda expression is a function that can be passed as a parameter to another function
  // make it easy to perform list operations in one line of code

  vector<int> vecVals = GenerateRandVect(10,1,100);

  // sort the vector
  sort(vecVals.begin(),vecVals.end(),[](int x, int y){return x<y;});// sort the vector in ascending order 
  // [] will indicate a lambda expression
  // (x,y) will be the parameters of the lambda expression
  // {return x<y;} will be the body of the lambda expression
  // the body of the lambda expression will return true if x is less than y
  // the body of the lambda expression will return false if x is greater than y
  for (int i=0;i<vecVals.size();i++){
    cout<<vecVals[i]<<endl;
  }

  vector<int> evenVecVals;
  copy_if(vecVals.begin(),vecVals.end(),back_inserter(evenVecVals),[](int x){return (x%2==0);});
  // copy_if() will copy the elements of the vector that meet the condition

  int sum = 0;
  for_each(vecVals.begin(),vecVals.end(),[&](int x){sum+=x;});
  // for_each() will iterate through the vector and perform the operation on each element
  // [&] will pass the variable by reference
  // [=] will pass the variable by value
  // [x] will pass the variable by value
  cout<<sum<<endl;

  cout<<"\n---FILE---\n"<<endl;

  ofstream writeToFile;
  ifstream readFromFile;
  string txtToWrite = "";
  string txtFromFile = "";

  writeToFile.open("files/test.txt",ios_base::out |ios_base::trunc); 
  // open the file in write mode
  // app will append the text to the file
  // ate wil overwrite the file
  // trunc will delete the file and create a new one
  // nocreate will not create the file if it does not exist

  if(writeToFile.is_open()){
    writeToFile<<"Begining of the file\n Hello World";
    writeToFile.close(); // close the file
  }

  readFromFile.open("files/test.txt",ios_base::in); // open the file in read mode

  if(readFromFile.is_open()){
    while(readFromFile){
      getline(readFromFile,txtFromFile);
      cout<<txtFromFile<<endl;
    }
    readFromFile.close();
  }

  cout<<"\n---FUNCTION AS A PARAMETER---\n"<<endl;

  auto times2 = MultBy2; // auto will determine the type of the variable
  // MultBy2 is a function that takes an integer as a parameter and returns an integer

  cout<< "5 * 2 = "<<times2(5)<<endl;
  cout<< "6 * 2 = "<<DoMath(times2,6)<<endl; // DoMath() will call the function times2() and pass the value 5 to it

  //store function inside vector

  vector<function<double(double)>> funcs(2); // vector of function pointers
  funcs[0] = MultBy2;
  funcs[1] = times2;
  cout<<funcs[0](5)<<endl; // call the function MultBy2() and pass the value 5 to it
  cout<<funcs[1](2)<<endl; // call the function times2() and pass the value 2 to it
  
  cout<<"\n---MACRO---\n"<<endl;

  cout<<CIRCLE_AREA(10)<<endl; // CIRCLE_AREA() will be replaced by the value of the macro

  cout<<"\n---TEMPLATE FUNCTION---\n"<<endl;

  Times2(2);
  Times2(2.454);
  Times2(-0.1231231);
  
  
  return 0;
}

vector<int> GenerateRandVect(int numOfNums,int min, int max){
  vector<int> vecValues;
  srand(time(NULL));// seed the random number generator
  int i = 0, randVal =0;
  while (i<numOfNums){
    randVal = rand()%(max-min+1)+min;
    vecValues.push_back(randVal);
    i++;}
  return vecValues;
}

void ShowArea(Shape& shape){
  cout<<"Area: "<<shape.GetArea()<<endl;
}


