#include "point.h"
#include <math.h>

Point::Point(double x, double y):x(x),y(y){}

double Point::get_x() const { return this->x; };
double Point::get_y() const { return this->y; };
void Point::set_x(double m_x) { this->x = m_x; };
void Point::set_y(double m_y) { this->y = m_y; };
double Point::radius() const { return (sqrt(x * x + y * y)); };