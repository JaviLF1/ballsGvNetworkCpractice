
/*
Citas

Musica
    Cancion de fondo
        Fujii, S. (2014). Sweet Sweet Canyon [Song]. In Mario Kart 8 Original Soundtrack. Nintendo.

Efecto de sonido
    Sonido de moneda
        Kondo, K. (1985). Coin sound effect [Sound effect]. In Super Mario Bros. Nintendo.
*/






#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>

#include "Point.h"
#include <thread>


sf::SoundBuffer buffer;

int coinsColected = 0;

float ballSpeed = 1;
bool coinStatus1 = true;
bool coinStatus2 = true;
bool coinStatus3 = true;
bool coinStatus4 = true;
bool coinStatus5 = true;
bool coinStatus6 = true;


const double k = 9 * std::pow(10, 9);

const double carga = 1.602 * std::pow(10, -19);

void hitBox(float x1, float y1, Point coint, sf::CircleShape& visCoint,sf::Sound sdEffect, bool& coinSt) {



    if ((x1 >= coint.getX() - 20) and (x1 <= coint.getX() + 20) and (y1 >= coint.getY() - 25) and (y1 <= coint.getY() + 50)) {
        if (coinSt==true) {

            visCoint.setFillColor(sf::Color::Black);
            sdEffect.play();
            while (sdEffect.getStatus() == sf::Sound::Status::Playing)
                sf::sleep(sf::milliseconds(1));
            coinSt = false;
            coinsColected += 1;
        }
    }


}
void hitBoxSmall(float x1, float y1, Point coint, sf::CircleShape& visCoint, sf::Sound sdEffect, bool& coinSt) {



    if ((x1 >= coint.getX() - 15) and (x1 <= coint.getX() + 15) and (y1 >= coint.getY() - 20) and (y1 <= coint.getY() + 40)) {
        if (coinSt == true) {

            visCoint.setFillColor(sf::Color::Black);
            sdEffect.play();
            while (sdEffect.getStatus() == sf::Sound::Status::Playing)
                sf::sleep(sf::milliseconds(1));
            coinSt = false;
            coinsColected += 1;
        }
    }


}

void playMusic() {
    sf::Music music;
    if (!music.openFromFile("backMusic.mp3"))
        return;

    music.setLooping(true);
    music.setVolume(25.f);
    music.play();

    // Keep thread alive while music plays
    while (music.getStatus() == sf::Music::Status::Playing)
        sf::sleep(sf::milliseconds(100));
}

//Movable point
Point pointTest(400.f, 700.f);
//Static points
Point pointTest2(900.f, 700.f);

//Coins
Point golden(1500.f, 600.f);
Point golden2(1300.f, 300.f);
Point golden3(800.f, 100.f);

Point golden4(1100.f, 800.f);
Point golden5(900.f, 900.f);
Point golden6(700.f, 800.f);



int main()
{
    //Font/text
    sf::Font font;
    font.openFromFile("arial.ttf");
    sf::Text wasdInstructions(font);
    wasdInstructions.setString("WASD for Movement");
    wasdInstructions.setCharacterSize(20);           // in pixels
    wasdInstructions.setFillColor(sf::Color::White);
    wasdInstructions.setPosition({ 100.f, 70.f });
    sf::Text resetInstr(font);
    resetInstr.setString("Press R to reset ball");
    resetInstr.setCharacterSize(20);           // in pixels
    resetInstr.setFillColor(sf::Color::White);
    resetInstr.setPosition({ 100.f, 100.f });

    sf::Text numOfCoins(font);
    numOfCoins.setString("Coins collected " + std::to_string(coinsColected));
    numOfCoins.setCharacterSize(30);           // in pixels
    numOfCoins.setFillColor(sf::Color::White);
    numOfCoins.setPosition({ 1400.f, 80.f });

    sf::Text WinMessage(font);
    WinMessage.setString("You Win");
    WinMessage.setCharacterSize(200);           // in pixels
    WinMessage.setFillColor(sf::Color::White);
    WinMessage.setPosition({ 550.f, 350.f });


    //Music
    std::thread musicThread(playMusic);
    musicThread.detach();

    //Sound
    if (!buffer.loadFromFile("coinSd.mp3"))
        return -1;
    sf::Sound soundCoin(buffer);
    soundCoin.setVolume(10.f);       // 0–100
    soundCoin.setPitch(1.f);

    // Create a window
    sf::RenderWindow window(sf::VideoMode({ 1800u, 1080u }), "SFML3 Circle");

    // Create a circle with radius 50
    sf::CircleShape circle(10.f);
    sf::CircleShape circleRef(5.f);
    sf::CircleShape circleRef2(5.f);

    sf::CircleShape goldenView(20.f);
    sf::CircleShape goldenView2(20.f);
    sf::CircleShape goldenView3(15.f);

    sf::CircleShape goldenView4(20.f);
    sf::CircleShape goldenView5(15.f);
    sf::CircleShape goldenView6(20.f);


    // Customize the circle
    circle.setFillColor(sf::Color::White);
    circle.setOutlineColor(sf::Color::White);
    circle.setOutlineThickness(3.f);
    //circle.setOrigin({ 50.f, 50.f });                  // Origin is now set with a Vector2f
    //CircleRef
    circleRef.setFillColor(sf::Color::Red);
    circleRef.setOutlineColor(sf::Color::White);
    circleRef.setOutlineThickness(2.f);
    //circleRef.setOrigin({ 250.f, 300.f });


    circleRef2.setFillColor(sf::Color::Red);
    circleRef2.setOutlineColor(sf::Color::White);
    circleRef2.setOutlineThickness(1.f);

    goldenView.setOutlineColor(sf::Color::White);
    goldenView.setOutlineThickness(1.f); 
    goldenView.setFillColor(sf::Color::Yellow);
    goldenView.setPosition({ golden.getX(), golden.getY() });

    goldenView2 = goldenView;
    goldenView3 = goldenView;
    goldenView4 = goldenView;
    //goldenView5 = goldenView;
    goldenView6 = goldenView;
    /*
    goldenView2.setOutlineColor(sf::Color::White);
    goldenView2.setOutlineThickness(1.f);
    goldenView2.setFillColor(sf::Color::Yellow);*/
    goldenView2.setPosition({ golden2.getX(), golden2.getY() });
    
    goldenView3.setPosition({ golden3.getX(), golden3.getY() });

    goldenView4.setPosition({ golden4.getX() - 10, golden4.getY() });

    goldenView5.setOutlineColor(sf::Color::White);
    goldenView5.setOutlineThickness(1.f);
    goldenView5.setFillColor(sf::Color::Yellow);
    goldenView5.setPosition({ golden5.getX() - 10, golden5.getY() });

    goldenView6.setPosition({ golden6.getX() - 10, golden6.getY() });


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
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::R))
        {
            initX = 100;
            initY = 400;
            forceX = 0;
            forceY = 0;
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

        hitBox(initX, initY, golden, goldenView,soundCoin, coinStatus1);
        hitBox(initX, initY, golden2, goldenView2, soundCoin, coinStatus2);
        hitBoxSmall(initX, initY, golden3, goldenView3, soundCoin, coinStatus3);
        if (coinsColected >= 3) {

            hitBox(initX, initY, golden4, goldenView4, soundCoin, coinStatus4);
            hitBoxSmall(initX, initY, golden5, goldenView5, soundCoin, coinStatus5);
            hitBox(initX, initY, golden6, goldenView6, soundCoin, coinStatus6);

        }


        circle.setPosition({ initX-5, initY-5 });

        circleRef.setPosition({ pointTest.getX(), pointTest.getY() });
        circleRef2.setPosition({ pointTest2.getX(), pointTest2.getY() });
        window.clear(sf::Color::Black);
        window.draw(circle);
        window.draw(circleRef);
        window.draw(circleRef2);
        window.draw(goldenView);
        window.draw(goldenView2);
        window.draw(goldenView3);
        window.draw(wasdInstructions);
        window.draw(resetInstr);
        numOfCoins.setString("Coins collected " + std::to_string(coinsColected));
        window.draw(numOfCoins);
        if (coinsColected >= 3) {
            goldenView.setOutlineColor(sf::Color::Black);
            goldenView2.setOutlineColor(sf::Color::Black);
            goldenView3.setOutlineColor(sf::Color::Black);
            window.draw(goldenView4);
            window.draw(goldenView5);
            window.draw(goldenView6);
        }
        if (coinsColected >= 6) {
            window.clear(sf::Color::Black);
            window.draw(WinMessage);
            window.display();
            sf::sleep(sf::seconds(6));
            break;
            
        }
        window.display();
        sf::sleep(sf::milliseconds(10));

    }

    return 0;
}