#pragma once
class Point
{

private:
	float x;
	float y;



public:

    Point(float , float);

    float getAngle(float, float);


    // Setter for x
    void setX(float value) {
        x = value;
    }

    // Getter for x
    float getX() const {
        return x;
    }

    // Setter for y
    void setY(float value) {
        y = value;
    }

    // Getter for y
    float getY() const {
        return y;
    }
};









