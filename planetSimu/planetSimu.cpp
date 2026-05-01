#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
#include <Windows.h>
#include "Point.h"


sf::SoundBuffer buffer;



float ballSpeed = 1;


const double k = 9 * std::pow(10, 9);

const double carga = 1.602 * std::pow(10, -19);

void hitBox(float x1, float y1, Point coint, sf::CircleShape& visCoint) {



    if ((x1 >= coint.getX() - 15) and (x1 <= coint.getX() + 15) and (y1 >= coint.getY() - 15) and (y1 <= coint.getY() + 15)) {

        visCoint.setFillColor(sf::Color::Black);

    }


}



Point pointTest(400.f, 700.f);
Point pointTest2(900.f, 700.f);


Point golden(1500.f, 600.f);



int main()
{
    //Sound
    if (!buffer.loadFromFile("amar.mp3"))
        return -1;
    sf::Sound sound(buffer);

    // Create a window
    sf::RenderWindow window(sf::VideoMode({ 1800u, 1080u }), "SFML3 Circle");

    // Create a circle with radius 50
    sf::CircleShape circle(10.f);
    sf::CircleShape circleRef(5.f);
    sf::CircleShape circleRef2(5.f);

    sf::CircleShape goldenView(20.f);

    // Customize the circle
    circle.setFillColor(sf::Color::White);
    circle.setOutlineColor(sf::Color::White);
    circle.setOutlineThickness(3.f);
    //circle.setOrigin({ 50.f, 50.f });                  // Origin is now set with a Vector2f
    //CircleRef
    circleRef.setFillColor(sf::Color::Red);
    circleRef.setOutlineColor(sf::Color::White);
    circleRef.setOutlineThickness(1.f);
    //circleRef.setOrigin({ 250.f, 300.f });


    circleRef2.setFillColor(sf::Color::Red);
    circleRef2.setOutlineColor(sf::Color::White);
    circleRef2.setOutlineThickness(1.f);

    goldenView.setOutlineColor(sf::Color::White);
    goldenView.setOutlineThickness(1.f);
    goldenView.setFillColor(sf::Color::Yellow);
    goldenView.setPosition({ golden.getX(), golden.getY() });



    float initX = 100;

    float initY = 400;

    float forceX = 0;
    float forceY = 0;

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

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
        {
            pointTest.setY(pointTest.getY() - 3);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
        {
            pointTest.setY(pointTest.getY() + 3);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
        {
            pointTest.setX(pointTest.getX() - 3);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
        {
            pointTest.setX(pointTest.getX() + 3);
        }


        //Here we are detecting the coin state

        
        
        //define Force
        

// Pass initX and initY into getAngle instead of realX and realY
        float angle = pointTest.getAngle(initX, initY);
        float angle2 = pointTest2.getAngle(initX, initY);

        // Calculate the distance squared
        float distanceSq = std::pow(initX - pointTest.getX(), 2) + std::pow(initY - pointTest.getY(), 2);
        float distanceSq2 = std::pow(initX - pointTest2.getX(), 2) + std::pow(initY - pointTest2.getY(), 2);


        // Calculate the distance (careful to avoid division by zero if they perfectly overlap!)
        float distance = std::sqrt(distanceSq);
        float distance2 = std::sqrt(distanceSq2);

        float forceMagnitude = k*(carga*carga / (distance*std::pow(10,-29)));
        float forceMagnitude2 = k*(carga * carga / (distance2* std::pow(10, -29)));

        // Calculate final force components
        
        forceX += std::cos(angle) * forceMagnitude*2;
        forceY += std::sin(angle) * forceMagnitude*2;

        forceX += std::cos(angle2) * forceMagnitude2;
        forceY += std::sin(angle2) * forceMagnitude2;

        initX = initX + forceX;
        initY = initY + forceY;

        hitBox(initX, initY, golden, goldenView);

        circle.setPosition({ initX-5, initY-5 });

        circleRef.setPosition({ pointTest.getX(), pointTest.getY() });
        circleRef2.setPosition({ pointTest2.getX(), pointTest2.getY() });
        window.clear(sf::Color::Black);
        window.draw(circle);
        window.draw(circleRef);
        window.draw(circleRef2);
        window.draw(goldenView);
        window.display();
        Sleep(10);
    }

    return 0;
}