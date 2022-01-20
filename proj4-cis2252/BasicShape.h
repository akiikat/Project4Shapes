/****************************************
CIS2252 - Dr. Prof. John P. Baugh, PhD
Oakland Community College
Project 2
Robyn Bernard                 ░
*****************************************/
#include <iostream>
#include <vector>
#include <string>
#ifndef _BASICSHAPE
#define _BASICSHAPE
#define PI 3.141

using namespace std;
 
//c++ version of interface 
class BasicShape
{
public:
	//virtual detrutor
	virtual ~BasicShape() {}; 

	//virtual copy constructor 
	//virtual DEFAULT constructor
	virtual BasicShape* clone() const = 0; 
	virtual BasicShape* create() const = 0; 

	//pure virtual funtion that returns the shape type 
	virtual string whatAmI() = 0;
	//pure virtual function that returns the area of shape type
	virtual double getArea() = 0; 
};//end BasicShape


//implement methods for circle object data
class Circle : public BasicShape
{
public:
	//clone constructor co-variannt
	//create default constructor co-variant
	Circle* create() const { return new Circle(); }
	Circle* clone() const { return new Circle(); }

	//getter / setters 
	void setCircumference(double radius);
	double getCircumference(void);

	//override to return Circle Type
	string whatAmI() override{ return "Circle"; }

	//Area logic from Radius to Circumfrence 
	double getArea() override { return getCircumference()*2*PI;}
	
private:
	double mradius; 
};//end Circle


//implements methods for rectangle object data 
class Rectangle : public BasicShape
{
public:
	//clone constructor co-variannt
	//create default constructor co-variant
	Rectangle* create() const { return new Rectangle(); }
	Rectangle* clone() const { return new Rectangle(); }
	//getter / setter 
	void setPerimeter(double mlength, double mwidth);
	double getPerimeter(void);

	//Override to return Rectangle Type
	string whatAmI() override { return "Rectangle"; }

	//Override and logic for Area from obtaining a Perimeter 
	double getArea() override { return getPerimeter()*2; }
private:
	double mlength;
	double mwidth;

};//end rectangle


//getter setters 
void Rectangle::setPerimeter(double length, double width)
{
	mlength = length;
	mwidth = width;
}
double Rectangle::getPerimeter(void)
{
	return (mlength + mwidth);
}
void Circle::setCircumference(double radius)
{
	mradius = radius;
}
double Circle::getCircumference(void)
{
	return mradius;
}
#endif //!= +BASICSHAPE


int main()
{
	//creates vector of pointers to BasicShape Class
	vector<BasicShape*> test;
	BasicShape* p = NULL;

	Circle circle1;
	circle1.setCircumference(10);
	test.push_back(&circle1);

	Circle circle2;
	circle2.setCircumference(12);
	test.push_back(&circle2);

	Circle circle3;
	circle3.setCircumference(1);
	test.push_back(&circle3);

	Rectangle rec1;
	rec1.setPerimeter(2, 3);
	test.push_back(&rec1);

	Rectangle rec2;
	rec2.setPerimeter(1, 1);
	test.push_back(&rec2);

	Rectangle rec3;
	rec3.setPerimeter(2, 2);
	test.push_back(&rec3);

	
	//itterates through pointer vector and prints out function calls 
	for (vector<BasicShape*>::iterator it = test.begin(); it != test.end(); ++it)
	{
		cout << "I am a " << (*it)->whatAmI() << endl;
		cout << "My Area is " << (*it)->getArea() << endl;

	}

	//clear contents 
	test.clear();
	
	return 0;
}//end main 
