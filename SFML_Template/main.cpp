#include<iostream>
#include<string>
#include <TGUI/TGUI.hpp>
#include "Object.h"
#include <math.h>
#include <cmath>
#include "StaticCircle.h"
#include "MovingCircle.h"
#include <vector>


//Variables
float mass = 400;
float Size = mass / 15;

//position values
sf::Vector2f StaticPos(500,500);
sf::Vector2f mousePositionFloat(0,0);
sf::Vector2f Cursorpos;

//pointer to the staticcircle
StaticCircle* PS;

//Whether or not i want the translucent circle to follow the mouse.
bool trackCursor = true;

//Vector for testcircles
std::vector<sf::CircleShape> circleVector;

//Vector for the moving circles.
std::vector<MovingCircle> MovingVector;

//Creates a movingcircle and inserts it into the vector
//TBX, TBY and TBM are the editboxes for velocity and mass.
void CreateMovingCircle(tgui::EditBox::Ptr TBX, tgui::EditBox::Ptr TBY, tgui::EditBox::Ptr TBM)
{

    //fetch the string from the editboxes and convert them into respective number variables.
    tgui::String Xstring = TBX->getText();
    tgui::String Ystring = TBY->getText();
    tgui::String Mstring = TBM->getText();

    float XFloat = Xstring.toFloat();
    float YFloat = Ystring.toFloat();
    int MInt = Mstring.toInt();

    //changes the input to make it more understandable for user.
    //e.g I reverse the Y variable simply because to the average user, it makes sense that a positive y value means "up"
    //e.g2 i multiply and divide by 10 to avoid users having to use decimal (in the case of mass not even possible)
    MInt = MInt * 10;
    XFloat = XFloat / 10;
    YFloat = -1 * YFloat / 10;

    //Mass defaults to 500 if there is no value, or ig 0. I am scared the program will brick if it tries to divide by 0, so I play it safe
    if (MInt <= 0)
    {
        MInt = 500;
    }
    MovingCircle Circ(MInt, XFloat, YFloat);
    Circ.SetPosition(Cursorpos);
    //puts the object in my vector
    MovingVector.push_back(Circ);
    
    //we dont want to lock the cursor when the user clicks a button
    trackCursor = true;
}

//removes the latest circle added to the vector
void RemoveMovingCircle()
{
    //prevents trying to pop back nothing, which crashes the program
    if (MovingVector.empty() == false)
    {
            MovingVector.pop_back();
    }
    //we dont want to set the cursor when the user clicks a button
    trackCursor = true;
}

//resets everything
void Reset(tgui::EditBox::Ptr TBX, tgui::EditBox::Ptr TBY, tgui::EditBox::Ptr TBM)
{
    if (MovingVector.empty() == false)
    {
        MovingVector.clear();
    }
    PS->SetPosition(StaticPos);
    TBX->setText("");
    TBY->setText("");
    TBM->setText("");
    //we dont want to set the cursor when the user clicks a button
    trackCursor = true;
}

//sets the position of the staticcircle to the cursor location
void SetStatic()
{

    Cursorpos = sf::Vector2f(Cursorpos.x - 25, Cursorpos.y - 25);
    PS->SetPosition(Cursorpos);

    //we dont want to set the cursor when the user clicks a button
    trackCursor = true;

}


//For a easy debugging will show if a file counld not be opened in the console.
bool RunGUI(tgui::GuiBase& gui)
{
    try
    {
        //There is likely a cleaner way to do this, but here is where the TGUI widgets are defined.

        //Theme
        tgui::Theme cooltheme{ "C:/Users/te20jl5/OneDrive - Curt Nicolin Gymnasiet AB/Dokument/GUI_SFML/TGUI-0.9/themes/BabyBlue.txt"};
        //Tooltips
        auto toolTipX = tgui::Label::create("Set starting velocity of X axis, Default = 0");
        auto toolTipY = tgui::Label::create("Set starting velocity of Y axis, Default = 0");
        auto toolTipM = tgui::Label::create("Set Mass of Object, Default = 50");
        auto toolTip1 = tgui::Label::create("Add a physics objects with specified paramaters at cursor");
        auto toolTip2 = tgui::Label::create("Move the static object to the cursor");
        auto toolTip3 = tgui::Label::create("Remove last placed Object");
        auto toolTip4 = tgui::Label::create("Reset everything");


        toolTipX->setRenderer(cooltheme.getRenderer("Tooltip"));
        toolTipY->setRenderer(cooltheme.getRenderer("Tooltip"));
        toolTipM->setRenderer(cooltheme.getRenderer("Tooltip"));
        toolTip1->setRenderer(cooltheme.getRenderer("Tooltip"));
        toolTip2->setRenderer(cooltheme.getRenderer("Tooltip"));
        toolTip3->setRenderer(cooltheme.getRenderer("Tooltip"));
        toolTip4->setRenderer(cooltheme.getRenderer("Tooltip"));

        //Textboxes
        auto textbox = tgui::EditBox::create();
        auto textbox2 = tgui::EditBox::create();
        auto textboxM = tgui::EditBox::create();


        textbox->setSize({ "5%","5%" });
        textbox->setPosition({ "5%","62%" });
        textbox->setDefaultText({ "X Vel" });
        textbox->setRenderer(cooltheme.getRenderer("EditBox"));
        textbox->setToolTip(toolTipX);

        textbox2->setSize({ "5%","5%" });
        textbox2->setPosition({ "5%","67%" });
        textbox2->setDefaultText({ "Y Vel" });
        textbox2->setRenderer(cooltheme.getRenderer("EditBox"));
        textbox2->setToolTip(toolTipY);

        textboxM->setSize({ "5%","5%" });
        textboxM->setPosition({ "5%","72%" });
        textboxM->setDefaultText({ "Mass" });
        textboxM->setRenderer(cooltheme.getRenderer("EditBox"));
        textboxM->setToolTip(toolTipM);

        //Add Circle Button
        auto button = tgui::Button::create("Add Object");
        button->setSize({ "14%", "8%" });
        button->setPosition({ "10%", "62%" });
        button->onPress(CreateMovingCircle,textbox,textbox2,textboxM);
        button->setRenderer(cooltheme.getRenderer("Button"));
        button->setToolTip(toolTip1);


        //Remove circle Button
        auto button2 = tgui::Button::create("Remove Object");
        button2->setSize({ "14%", "8%" });
        button2->setPosition({ "70%", "62%" });
        button2->onPress(RemoveMovingCircle);
        button2->setRenderer(cooltheme.getRenderer("Button"));
        button2->setToolTip(toolTip3);

        //Remove all circle button
        auto button3 = tgui::Button::create("Reset");
        button3->setSize({ "14%", "8%" });
        button3->setPosition({ "70%", "70%" });
        button3->onPress(Reset, textbox, textbox2, textboxM);
        button3->setRenderer(cooltheme.getRenderer("Button"));
        button3->setToolTip(toolTip4);
        
        //set static
        auto button4 = tgui::Button::create("Set Static Position");
        button4->setSize({ "14%", "8%" });
        button4->setPosition({ "10%", "70%" });
        button4->onPress(SetStatic);
        button4->setRenderer(cooltheme.getRenderer("Button"));
        button4->setToolTip(toolTip2);


        //gui add
        gui.add(textbox);
        gui.add(textbox2);
        gui.add(textboxM);
        gui.add(button);
        gui.add(button2);
        gui.add(button3);
        gui.add(button4);

       // MakeButton("Add Circle", gui);
        //MakeButton2("Remove Circle", gui);
        //MakeTextBox(gui);
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

    //I set the frameratelimit to the refresh rate of the pc i am working on, I wanted to restrict the framerate so the math:
    //which is based on frames, is consistant and doesn't use too much power.
    //In other words, it's for stability.
    window.setFramerateLimit(60);

    //Background colour
    sf::RectangleShape BG(sf::Vector2f(2000, 2000));
    BG.setFillColor(sf::Color(156, 173, 206));

    //The circle cursor.
    sf::CircleShape Cursor(100.f);
    Cursor.setFillColor(sf::Color(0, 100, 100, 100));

    //The movingCircles in main, placed for testing purposes.
    StaticCircle Static(50);

    Cursor.setRadius(Size);

    //I want the StaticCircle to be in the middle of the coordinates, not the corner
    StaticPos = sf::Vector2f(500 - Static.Size, 500 - Static.Size);
    Static.SetPosition(StaticPos);
    PS = &Static;


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

        //Locks the cursor to the point you pressed it to.
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            Cursorpos = mousePositionFloat;
            trackCursor = false;
        }


        window.clear();

        //Renders everything in the order you want.
        window.draw(BG);
        window.draw(Cursor);

        gui.draw();
       
        //Try to call MovingCircle::Update on every MovingCircle in the vector
        for (size_t i = 0; i < MovingVector.size(); i++)
        {
            MovingVector[i].Update(window,Static.Circle);
        }
        
        Static.Render(window);

        window.display();
    }



    }
