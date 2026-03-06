//#ifndef CIRCLE_H
//#define CIRCLE_H

class Circle {
public:
	int radius; 

	Circle(); 
	Circle(int r); 
	~Circle(); // 소멸자
	double getArea();
};

//#endif
