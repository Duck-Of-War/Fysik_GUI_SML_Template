#include<iostream>
#include<string>
#include <TGUI/TGUI.hpp>
#include "Object.h"
#include <math.h>
#include <cmath>
#include "StaticCircle.h"
#include "MovingCircle.h"

//To do:


//Variables



sf::Vector2f Testmovepos(750,750);
sf::Vector2f MoveaPos(250,250);
sf::Vector2f TestiPos(500,500);

//Print Something on the Console
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

    sf::RenderWindow window{ {1000, 1000}, "TGUI window with SFML" };
    window.setKeyRepeatEnabled(false);
    //A Gui Object that works with Sfml window. 
    tgui::GuiSFML gui{ window };
    window.setFramerateLimit(60);
    sf::RectangleShape BG(sf::Vector2f(2000, 2000));
    BG.setFillColor(sf::Color(156,173,206));


    StaticCircle teststatic(50);
    MovingCircle testmoving(800,-1.4,0.3);
    MovingCircle Movea(350,0.5,-0.5);

    sf::Vector2f TestiPos(500 - teststatic.Size, 500 - teststatic.Size);

    teststatic.SetPosition(TestiPos);
    Movea.SetPosition(MoveaPos);
    testmoving.SetPosition(Testmovepos);
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

            }
        }


        teststatic.GetPosition();
        

        window.clear();
        //gui.draw();
        window.draw(BG);
        teststatic.Render(window);
        testmoving.Update(window, teststatic.Circle);
        Movea.Update(window, teststatic.Circle);
        window.display();
    }
}