#include <SFML/Graphics.hpp>
#include <cmath>
#include <Windows.h>
#include "Point.h"

double degrees = 0.0;
const double PI = 3.14159265358979323846;






Point pointTest(250.f, 300.f);




int main()
{
    // Create a window
    sf::RenderWindow window(sf::VideoMode({ 1200u, 900u }), "SFML3 Circle");

    // Create a circle with radius 50
    sf::CircleShape circle(10.f);
    sf::CircleShape circleRef(5.f);

    // Customize the circle
    circle.setFillColor(sf::Color::White);
    circle.setOutlineColor(sf::Color::White);
    circle.setOutlineThickness(3.f);
    circle.setOrigin({ 50.f, 50.f });                  // Origin is now set with a Vector2f
    //CircleRef
    circleRef.setFillColor(sf::Color::Red);
    circleRef.setOutlineColor(sf::Color::White);
    circleRef.setOutlineThickness(1.f);
    //circleRef.setOrigin({ 250.f, 300.f });


    float initX=300;

    float initY=200;

    float forceX=13;
    float forceY=-4;

    float realX = 0;

    float realY = 0;

    // Position uses Vector2f too

    // Main loop
    while (window.isOpen())
    {
        // SFML 3: use pollEvent with optional<Event>
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        

        
        //define Force
        

// Pass initX and initY into getAngle instead of realX and realY
        float angle = pointTest.getAngle(initX, initY);

        // Calculate the distance squared
        float distanceSq = std::pow(initX - pointTest.getX(), 2) + std::pow(initY - pointTest.getY(), 2);

        // Calculate the distance (careful to avoid division by zero if they perfectly overlap!)
        float distance = std::sqrt(distanceSq);
        float forceMagnitude = (1.0f / distance) * 100.0f;

        // Calculate final force components
        
        forceX += std::cos(angle) * forceMagnitude;
        forceY += std::sin(angle) * forceMagnitude;

        initX = initX + forceX;
        initY = initY + forceY;

        

        circle.setPosition({ initX, initY });

        circleRef.setPosition({ 250, 300 });
        window.clear(sf::Color::Black);
        window.draw(circle);
        window.draw(circleRef);
        window.display();
        Sleep(10);
    }

    return 0;
}