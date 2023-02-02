#include<iostream>
#include<string>
#include <TGUI/TGUI.hpp>
#include "Object.h"
#include <math.h>
#include <cmath>
#include "StaticCircle.h"
#include "MovingCircle.h"
#include <vector>

//To do:
//When clicking the button which creates and renders a moving circle,
//an exception is thrown at the movingcircle.cpp Circle.move(Velocity) function

//Variables
float mass = 400;

float Size = mass / 15;

//position values
sf::Vector2f Testmovepos(750,750);
sf::Vector2f MoveaPos(250,250);
sf::Vector2f TestiPos(500,500);
sf::Vector2i Mosi(2,2);
sf::Vector2f mousePositionFloat(0,0);
sf::Vector2f Cursorpos;

//Whether or not i want the translucent circle to follow the mouse.
bool trackCursor = true;

float x = 0;

//Vector for testcircles
std::vector<sf::CircleShape> circleVector;

//Vector for the moving circles.
std::vector<MovingCircle> MovingVector;

//Creates a movingcircle and inserts it into the vector
void CreateMovingCircle()
{
    Cursorpos = sf::Vector2f(Cursorpos.x - 25, Cursorpos.y - 25);
    MovingCircle Circ(500, 0, 0);
    Circ.SetPosition(Cursorpos);
    MovingVector.push_back(Circ);
    trackCursor = true;
}

//makes a testing circle
void testero()
{
    sf::CircleShape Circ(50.f);
    Circ.setPosition(sf::Vector2f(Cursorpos.x - 25,Cursorpos.y - 25));
    x = x + 50;
    circleVector.push_back(Circ);
    trackCursor = true;
}

//removes the testing circle
void testremove() {

    if (circleVector.empty() == false)
    {
        circleVector.pop_back();
        x = x - 50;
    }
    trackCursor = true;
}


//Create a Button and call Createmovingcircle
void MakeButton (std::string ButtonText,tgui::GuiBase& gui)
{
    auto button = tgui::Button::create(ButtonText);
    button->setSize({ "50%", "16.67%" });
    button->setPosition({ "25%", "70%" });
    gui.add(button);

    button->onPress(CreateMovingCircle);
   
}

//button to remove the moving circles, currently used to remove the "test" circles
void MakeButton2(std::string ButtonText, tgui::GuiBase& gui)
{
    auto button = tgui::Button::create(ButtonText);
    button->setSize({ "10%", "10%" });
    button->setPosition({ "25%", "10%" });
    gui.add(button);

    button->onPress(testremove);

}


//For a easy debugging will show if a file counld not be opened in the console.
bool RunGUI(tgui::GuiBase& gui)
{
    try
    {
        MakeButton("Add circle", gui);
        MakeButton2("destroy circle", gui);
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

    //Background colour
    sf::RectangleShape BG(sf::Vector2f(2000, 2000));
    BG.setFillColor(sf::Color(156, 173, 206));

    //The circle cursor.
    sf::CircleShape Cursor(100.f);
    Cursor.setFillColor(sf::Color(0, 100, 100, 100));

    //The movingCircles in main, placed for testing purposes.
    StaticCircle teststatic(50);
    MovingCircle testmoving(800, -1.4, 0.3);
    MovingCircle Movea(350, 0.5, -0.5);
    Movea.SetPosition(MoveaPos);
    testmoving.SetPosition(Testmovepos);

    //testing if I can use a vector in the code, as opposed to runtime. (i cant, the circle stays still)
    MovingCircle Circ(500, 0.3, -0.3);
    Circ.SetPosition(MoveaPos);
    MovingVector.push_back(Circ);

    //I want "TestiPos" to be in the middle of the coordinate
    sf::Vector2f TestiPos(500 - teststatic.Size, 500 - teststatic.Size);
    teststatic.SetPosition(TestiPos);
    


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




 
        //Tracks cursor to mouse position
        if (trackCursor == true)
        {
            Cursor.setPosition(mousePositionFloat);
            mousePositionFloat = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));
            mousePositionFloat.x = mousePositionFloat.x - Cursor.getRadius();
            mousePositionFloat.y = mousePositionFloat.y - Cursor.getRadius();
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            Cursorpos = mousePositionFloat;
            trackCursor = false;
        }

        //Maybe I want to change the size in runtime??
        Cursor.setRadius(Size);


        window.clear();
        window.draw(BG);
        teststatic.Render(window);
        testmoving.Update(window, teststatic.Circle);
        Movea.Update(window, teststatic.Circle);

        //Try to call MovingCircle::Update on every MovingCircle in the vector, does NOT work
        for (size_t i = 0; i < MovingVector.size(); i++)
        {
            MovingVector[i].Update(window, teststatic.Circle);
        }

        //Moves and draws all testcircles in their vector, works
        for (size_t i = 0; i < circleVector.size(); i++)
        {
            circleVector[i].move(sf::Vector2f(2,2));
            window.draw(circleVector[i]);
        }


        gui.draw();
        window.draw(Cursor);
        window.display();
        //std::cout << mousePositionFloat.x << std::endl;
    }



    }
