#include <SFML/Graphics.hpp>
#include <cmath>
#include <Windows.h>

double degrees = 0.0;
const double PI = 3.14159265358979323846;
double result = std::cos(degrees * PI / 180.0); // Result is 0.5

const int masa = 1;
//F=m*a

int referenceX = 400;
int referenceY = 300;



int moveX = 0;

int moveY = 0;


int main()
{
    // Create a window
    sf::RenderWindow window(sf::VideoMode({ 800u, 600u }), "SFML3 Circle");

    // Create a circle with radius 50
    sf::CircleShape circle(10.f);
    sf::CircleShape circleRef(10.f);

    // Customize the circle
    circle.setFillColor(sf::Color::White);
    circle.setOutlineColor(sf::Color::White);
    circle.setOutlineThickness(3.f);
    circle.setOrigin({ 50.f, 50.f });                  // Origin is now set with a Vector2f
    //CircleRef
    circleRef.setFillColor(sf::Color::White);
    circleRef.setOutlineColor(sf::Color::White);
    circleRef.setOutlineThickness(3.f);
    circleRef.setOrigin({ 400.f, 300.f });
    
    
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
        degrees += 10;

        moveX = std::cos(degrees * PI / 180.0)*50;

        moveY = std::sin(degrees * PI / 180.0) * 50;


        circle.setPosition({ 400.f+moveX, 100.f+moveY});


        //window.clear(sf::Color::Black);
        window.draw(circle);
        window.display();
        Sleep(10);
    }

    return 0;
}