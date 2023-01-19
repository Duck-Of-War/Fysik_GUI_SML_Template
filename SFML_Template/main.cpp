#include<iostream>
#include<string>
#include <TGUI/TGUI.hpp>
#include "Object.h"
#include <math.h>
#include <cmath>
#include "StaticCircle.h"

//To do:
// FIX RENDER FOR STATIC CIRCLE
// make into physics object class and splinter into circle and square???
// 
// maybe splinter into static and moving physics object class.
//
//Variables
bool A_Pressed = false;
bool D_Pressed = false;
bool W_Pressed = false;
bool S_Pressed = false;
float x;
float y;
float FDistance;
float a2;
float b2;

sf::Vector2f Velocity;
sf::Vector2f Acceleration;
sf::Vector2f Distance;
sf::Vector2f MaxPos;
sf::Vector2f SamPos;
sf::Vector2f StaticPos;
float mass = 400;
//Print Something on the Concole
void print_Someting(std::string text) 
{
    std::cout << text;
};

//Create a Button and Call the print_Something function.
void MakeButton (std::string ButtonText,tgui::GuiBase& gui)
{
    auto button = tgui::Button::create(ButtonText);
    button->setSize({ "50%", "16.67%" });
    button->setPosition({ "25%", "70%" });
    gui.add(button);

    button->onPress(print_Someting,"Hello World\n");
   
}


//For a easy debugging will show if a file counld not be opened in the console.
bool RunGUI(tgui::GuiBase& gui)
{
    try
    {
        MakeButton("Click Me", gui);
        return true;
    }
    catch (const tgui::Exception& e)
    {
        std::cerr << "Failed to load TGUI widgets: " << e.what() << std::endl;
        return false;
    }
}



//main entry
int main()
{
    Velocity.x = 1;
    Velocity.y = -0.5;

    sf::RenderWindow window{ {800, 600}, "TGUI window with SFML" };
    window.setKeyRepeatEnabled(false);
    //A Gui Object that works with Sfml window. 
    tgui::GuiSFML gui{ window };
    window.setFramerateLimit(600);
    sf::CircleShape Sam(50.f);
    sf::CircleShape Max(10.f);
    sf::CircleShape Static(10.f);
    StaticCircle testi(200);
    //Static.setPosition(250, 250);
    Static.setPosition(250, 250);
    Max.setPosition(80, 80);
    Max.setFillColor(sf::Color(100, 25, 50));
    Static.setFillColor(sf::Color(155,0,0));
    RunGUI(gui);


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            gui.handleEvent(event);

            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
            case sf::Event::KeyPressed:
                switch (event.key.code)
                {
                case sf::Keyboard::A:
                    A_Pressed = true;
                    break;
                case sf::Keyboard::D:
                    D_Pressed = true;
                    break;
                case sf::Keyboard::W:
                    W_Pressed = true;
                    break;
                case sf::Keyboard::S:
                    S_Pressed = true;
                    break;
                default:
                    break;
                }
                break;
            case sf::Event::KeyReleased:
                switch (event.key.code)
                {
                case sf::Keyboard::A:
                    A_Pressed = false;
                    break;
                case sf::Keyboard::D:
                    D_Pressed = false;
                    break;
                case sf::Keyboard::W:
                    W_Pressed = false;
                    break;
                case sf::Keyboard::S:
                    S_Pressed = false;
                    break;
                default:
                    break;
                }
            }
        }
        if (D_Pressed == true)
        {
            Sam.move(0.5, 0);
        }
        if (A_Pressed == true)
        {
            Sam.move(-0.5, 0);
        }
        if (W_Pressed == true)
        {
            Sam.move(0, -0.5);

        }
        if (S_Pressed == true)
        {
            Sam.move(0, 0.5);
        }
        
        MaxPos = Max.getPosition();
        SamPos = Sam.getPosition();
        StaticPos = Static.getPosition();
        Sam.setFillColor(sf::Color(122*sin(x)+122, 122 * sin(2*x) + 122, 122 * sin(0.5*x) + 122));
        //Max.move(0.01 * (SamPos.x - MaxPos.x), 0.01 * (SamPos.y - MaxPos.y));

        a2 = pow(fabs(StaticPos.x - MaxPos.x), 2);
        b2 = pow(fabs(StaticPos.y - MaxPos.y), 2);
        FDistance = sqrt(a2 + b2);

        Distance.y = StaticPos.y - MaxPos.y;
        Distance.x = StaticPos.x - MaxPos.x;
        if (Distance.x >= 0)
        {
            Acceleration.x = mass / pow(FDistance, 2);

        }
        else
        {
            Acceleration.x = mass / pow(FDistance, 2) * -1;

        }
        if (Distance.y >= 0)
        {
            Acceleration.y = mass / pow(FDistance, 2);

        }
        else
        {
            Acceleration.y = mass / pow(FDistance, 2) * -1;

        }



        Velocity += Acceleration;
        Max.move(Velocity);
        //std::cout << SamPos.x << std::endl;
        window.clear();
        //gui.draw();
        window.draw(Max);
       // window.draw(Sam);
        testi.Render(window);
        window.draw(Static);
        x = x + 0.01;
        std::cout << Velocity.x;
        std::cout << "  ", Velocity.y;
        std::cout << "Accel ", Acceleration.x;
        std::cout << Acceleration.y;
        std::cout << "posi  ", MaxPos.x;
        std::cout << " ";
        std::cout << MaxPos.y << std::endl;
        window.display();
    }
}