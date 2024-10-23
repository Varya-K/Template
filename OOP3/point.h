#pragma once
class Point
{
private:
	double x;
	double y;
public:
	Point(double x, double y);
	~Point() {};

	double get_x() const;
	double get_y() const;
	void set_x(double m_x);
	void set_y(double m_x);
	double radius() const; //Возвращает значение расстояния точки от центра координат
};
