#include "Point.h"
#include <SFML/Graphics.hpp>
#include <cmath>

Point::Point(float xInit, float yInit) {


	x = xInit;

	y = yInit;





}

float Point::getAngle(float otherX, float otherY) {


	float xSide = x - otherX;

	float ySide = y - otherY;

	float angle = atan2(ySide, xSide);

	return angle;





}

