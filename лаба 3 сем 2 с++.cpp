/*

Общее задание:
Использовать protected, private переменные и методы.

Индивидуальные задачи.
 Создать абстрактный класс фигура. Создать класс окружность (наследник абстрактного класса),
 имеющий название, координаты, площадь. Определить конструкторы,
 деструктор и функцию вывода. 
 Создать public-производный класс – прямоугольник (от окружность), имеющий дополнительные
 координаты. 
 Определить конструкторы по умолчанию и с разным числом параметров, деструкторы,
 функцию вывода. 
 Определить функции переназначения координат и площади. Использовать статическую переменную 
 для хранения количества созданных объектов классов наследников и константы для хранения 
 идентификационных номеров в абстрактном классе, в классах наследниках.


#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class Figure
{
protected:
	string name;
public:
	virtual int getArea() const = 0;
	virtual void display() const = 0;
};
class Circle : public Figure
{
protected:
	unsigned int x, y, radius;
public:
	Circle(const string& name, unsigned int x, unsigned int y, unsigned int radius)
		: x(x), y(y), radius(radius)
	{
		this->name = name;
	}
	int getArea() const override
	{
		return 3.14 * radius * radius;
	}
	inline void display() const override
	{
		cout << "Circle: " << name << ", Center: (" << x << ", " << y << "), Radius: "
			<< radius << ", Area: " << getArea() << endl;
	}
};

class Rectangle : public Circle
{
private:
	unsigned int x2, y2;
public:
	Rectangle(const string& name, unsigned int x, unsigned int y, unsigned int x2, unsigned int y2)
		: Circle(name, x, y, 0), x2(x2), y2(y2)
	{
		this->name = name;
		calculateRadius();
	}
	void calculateRadius()
	{
		radius = sqrt((x2 - Circle::x) * (x2 - Circle::x) + (y2 - Circle::y) * (y2 - Circle::y));
	}
	void display() const override
	{
		cout << "Rectangle: " << name << ", Center: (" << Circle::x << ", " << Circle::y << "), Coordinates: (" << x2 << ", " << y2 << "), Area: "
			<< getArea() << endl;
	}
	
};
int main()
{
	Circle c("Circle 1", 0, 0, 5);
	c.display();

	Rectangle r("Rectangle 1", 0, 0, 10, 5);
	r.display();

	return 0;
}
*/