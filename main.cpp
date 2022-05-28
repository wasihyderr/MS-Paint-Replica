#include <iostream>
#include <cmath>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#pragma once

using namespace std;
using namespace sf;

struct Point
{
public:
    double x;
    double y;
};

class shapes
{
private:
    int color;
    int number_of_points;

public:
    int check;

    shapes()
    {
        check = 0;
    }

    virtual void draw(RenderWindow& window) = 0;
    virtual bool contains(Point p) = 0;
    virtual void fillColor(int color) = 0;
};

class text : public shapes
{
    Color color;
    Point P;
    Text myText;
    int id;
    string the_text;

public:

    text()
    {
        color = Color::Black;
        id = 0;
    }

    text(int id, Point text_point, string str)
    {
        this->id = id;
        P.x = text_point.x;
        P.y = text_point.y;
        the_text = str;

        Font font;
        font.loadFromFile("arial.ttf");

        myText.setFont(font);
        myText.setString(the_text);
        myText.setFillColor(Color::White);
        myText.setCharacterSize(18);
        myText.setPosition(Vector2f(P.x, P.y));
    }

    void draw(RenderWindow& window)
    {
        window.draw(myText);
    }

    bool contains(Point p)
    {
        return true;
    }

    void fillColor(int color)
    {

    }
};

class Circle : public shapes
{
private:

    float radius;
    Color color;
    int id;
    Point points[2];
    CircleShape myCirc;

public:

    Circle()
    {
        id = 0;
    }

    Circle(int id, Point circ_points[], Color circ_color = Color::White)
    {
        this->id = id;
        color = circ_color;
        points[0].x = circ_points[0].x;
        points[0].y = circ_points[0].y;
        points[1].x = circ_points[1].x;
        points[1].y = circ_points[1].y;

        radius = sqrt(pow((points[1].x - points[0].x), 2) + pow((points[1].y - points[0].y), 2));

        myCirc.setPosition(points[0].x, points[0].y);
        myCirc.setOrigin(Vector2f(radius, radius));
        myCirc.setRadius(radius);
        myCirc.setFillColor(Color::Black);
        myCirc.setOutlineThickness(2);
        myCirc.setOutlineColor(Color::White);
    }

    void draw(RenderWindow& window)
    {
        window.draw(myCirc);
    }

    bool contains(Point p)
    {
        return true;
    }

    void fillColor(int color)
    {
        //Red = 1, Blue = 2, Yellow = 3, Orange = 4, Green = 5, Black = 6, White = 7, Gold = 8, Pink = 9, LightBlue = 10, LightGreen = 11, Purple = 12
        if (color == 1) { myCirc.setFillColor(Color::Red); }
        if (color == 2) { myCirc.setFillColor(Color::Green); }
        if (color == 3) { myCirc.setFillColor(Color::Blue); }
        if (color == 4) { myCirc.setFillColor(Color::Yellow); }
        if (color == 5) { myCirc.setFillColor(Color(255, 165, 0)); }
        if (color == 6) { myCirc.setFillColor(Color::White); }
        if (color == 7) { myCirc.setFillColor(Color::Black); }
        if (color == 8) { myCirc.setFillColor(Color(255, 215, 0)); }

        if (color == 9) { myCirc.setFillColor(Color(255, 20, 147)); }
        if (color == 10) { myCirc.setFillColor(Color(176, 224, 230)); }
        if (color == 11) { myCirc.setFillColor(Color(154, 205, 50)); }
        if (color == 12) { myCirc.setFillColor(Color(148, 0, 211)); }

    }

    CircleShape getCircleShape()
    {
        return myCirc;
    }

};

class Polygon : public shapes
{
public:
    Point* points;
    int no_of_points;
    Color color;
    int id;
    ConvexShape myPolygon;

    Polygon()
    {
        points = nullptr;
    }

    Polygon(int id, Point* polypoints, int Noofpoints)
    {
        this->id = id;
        no_of_points = Noofpoints;
        color = Color::Black;

        points = new Point[no_of_points];

        for (int i = 0; i < no_of_points; i++)
        {
            points[i].x = polypoints[i].x;
            points[i].y = polypoints[i].y;
        }

        myPolygon.setOutlineThickness(5.f);
        myPolygon.setOutlineColor(Color::White);
        myPolygon.setFillColor(Color::Black);
    }

    Polygon(Polygon& obj)
    {
        id = obj.id;
        no_of_points = obj.no_of_points;
        points = new Point[no_of_points];

        for (int i = 0; i < no_of_points; i++)
        {
            points[i].x = obj.points[i].x;
            points[i].y = obj.points[i].y;
        }
        color = obj.color;
        id = obj.id;

        myPolygon.setOutlineThickness(5.f);
        myPolygon.setOutlineColor(Color::White);
        myPolygon.setFillColor(Color::Black);
    }

    void draw(RenderWindow& window)
    {
        myPolygon.setPointCount(no_of_points);
        for (int i = 0; i < no_of_points; i++)
        {
            myPolygon.setPoint(i, Vector2f(points[i].x, points[i].y));
        }

        window.draw(myPolygon);
    }

    bool contains(Point p)
    {
        return true;
    }
    void fillColor(int color)
    {
        if (color == 1) { myPolygon.setFillColor(Color::Red); }
        if (color == 2) { myPolygon.setFillColor(Color::Green); }
        if (color == 3) { myPolygon.setFillColor(Color::Blue); }
        if (color == 4) { myPolygon.setFillColor(Color::Yellow); }
        if (color == 5) { myPolygon.setFillColor(Color(255, 165, 0)); }
        if (color == 6) { myPolygon.setFillColor(Color::White); }
        if (color == 7) { myPolygon.setFillColor(Color::Black); }
        if (color == 8) { myPolygon.setFillColor(Color(255, 215, 0)); }

        if (color == 9) { myPolygon.setFillColor(Color(255, 20, 147)); }
        if (color == 10) { myPolygon.setFillColor(Color(176, 224, 230)); }
        if (color == 11) { myPolygon.setFillColor(Color(154, 205, 50)); }
        if (color == 12) { myPolygon.setFillColor(Color(148, 0, 211)); }
    }

};


class triangle : public Polygon {
private:
    Color color;
    int id;
    int no_of_points;
    Point pts[3];
    ConvexShape TriangleC;

public:

    triangle() {
        id = 0;
    }

    triangle(int id, Point tri_points[])
    {
        this->id = id;
        no_of_points = 3;

        for (int i = 0; i < 3; i++)
        {
            pts[i].x = tri_points[i].x;
            pts[i].y = tri_points[i].y;
        }

        TriangleC.setOutlineThickness(5.f);
        TriangleC.setOutlineColor(Color::White);
        TriangleC.setFillColor(Color::Black);
    }

    void draw(RenderWindow& window)
    {
        TriangleC.setPointCount(3);
        for (int i = 0; i < 3; i++)
        {
            TriangleC.setPoint(i, Vector2f(pts[i].x, pts[i].y));
        }

        window.draw(TriangleC);
    }

    bool contains(Point p)
    {
        return true;
    }
    void fillColor(int color)
    {
        if (color == 1) { TriangleC.setFillColor(Color::Red); }
        if (color == 2) { TriangleC.setFillColor(Color::Green); }
        if (color == 3) { TriangleC.setFillColor(Color::Blue); }
        if (color == 4) { TriangleC.setFillColor(Color::Yellow); }
        if (color == 5) { TriangleC.setFillColor(Color(255, 165, 0)); }
        if (color == 6) { TriangleC.setFillColor(Color::White); }
        if (color == 7) { TriangleC.setFillColor(Color::Black); }
        if (color == 8) { TriangleC.setFillColor(Color(255, 215, 0)); }

        if (color == 9) { TriangleC.setFillColor(Color(255, 20, 147)); }
        if (color == 10) { TriangleC.setFillColor(Color(176, 224, 230)); }
        if (color == 11) { TriangleC.setFillColor(Color(154, 205, 50)); }
        if (color == 12) { TriangleC.setFillColor(Color(148, 0, 211)); }
    }

};
class rectangle : public Polygon
{
private:
    Color color;
    int id;
    Point points[2];
    RectangleShape myRect;

public:

    rectangle()
    {
        id = 0;
    }

    rectangle(int id, Point rect_points[], Color rect_color = Color::White)
    {
        this->id = id;
        color = rect_color;

        for (int i = 0; i < 2; i++)
        {
            points[i].x = rect_points[i].x;
            points[i].y = rect_points[i].y;
        }
    }

    void draw(RenderWindow& window)
    {
        double l, w;
        myRect.setPosition(Vector2f(points[0].x, points[0].y));
        l = points[1].y - points[0].y;
        w = points[1].x - points[0].x;
        myRect.setFillColor(Color::Black);
        myRect.setSize(Vector2f(w, l));
        myRect.setOutlineColor(Color::White);
        myRect.setOutlineThickness(2.f);
        window.draw(myRect);
    }

    bool contains(Point p)
    {
        return true;
    }

    void fillColor(int color)
    {
        if (color == 1) { myRect.setFillColor(Color::Red); }
        if (color == 2) { myRect.setFillColor(Color::Green); }
        if (color == 3) { myRect.setFillColor(Color::Blue); }
        if (color == 4) { myRect.setFillColor(Color::Yellow); }
        if (color == 5) { myRect.setFillColor(Color(255, 165, 0)); }
        if (color == 6) { myRect.setFillColor(Color::White); }
        if (color == 7) { myRect.setFillColor(Color::Black); }
        if (color == 8) { myRect.setFillColor(Color(255, 215, 0)); }

        if (color == 9) { myRect.setFillColor(Color(255, 20, 147)); }
        if (color == 10) { myRect.setFillColor(Color(176, 224, 230)); }
        if (color == 11) { myRect.setFillColor(Color(154, 205, 50)); }
        if (color == 12) { myRect.setFillColor(Color(148, 0, 211)); }
    }
};

class Openshape : public shapes
{
    int style;
public:

    virtual void draw(RenderWindow& window) = 0;
    virtual void changeColor() = 0;
    virtual bool contains(Point p) = 0;
};

class Line : public Openshape
{
private:
    int id;
    Color color;
    Point points[2];
    Vertex myline[2];

public:

    Line()
    {
        id = 0;
        color = Color::White;
    }

    Line(int id, Point line_points[])
    {
        this->id = id;
        points[0].x = line_points[0].x;
        points[0].y = line_points[0].y;
        points[1].x = line_points[1].x;
        points[1].y = line_points[1].y;

        myline[0] = Vertex(Vector2f(points[0].x, points[0].y));
        myline[1] = Vertex(Vector2f(points[1].x, points[1].y));

    }

    void draw(RenderWindow& window)
    {
        window.draw(myline, 2, Lines);
    }

    bool contains(Point p)
    {
        return true;
    }
    void fillColor(int color)
    {

    }
    void changeColor()
    {

    }
};

class Curve : public Openshape
{
public:
    void draw(RenderWindow& window)
    {

    }
    bool contains(Point p)
    {
        return true;
    }
    void fillColor(int color)
    {

    }
    void changeColor()
    {

    }
};

template <typename type1, typename type2>
bool isMouseOver(type1& window, type2& entity)
{
    float mouseX = static_cast<float>(Mouse::getPosition(window).x);
    float mouseY = static_cast<float>(Mouse::getPosition(window).y);

    float entityX = entity.getPosition().x;
    float entityY = entity.getPosition().y;

    float entityWidth = entity.getPosition().x + entity.getLocalBounds().width;
    float entityHeight = entity.getPosition().y + entity.getLocalBounds().height;


    if (mouseX < entityWidth && mouseX>entityX && mouseY<entityHeight && mouseY > entityY)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//function to display boundry(cursor)
template <typename type1>
void displayCursor(type1& window, RectangleShape& block, Event event)
{
    if (isMouseOver(window, block))
    {
        block.setOutlineThickness(2.5f);
        block.setOutlineColor(Color::Magenta);
    }
}


void inc_shapes(shapes**& obj, int& present_s, int& capacity)
{
    if (present_s == capacity)
    {
        shapes** temp = new shapes * [capacity * 2];
        for (int i = 0; i < present_s; i++)
        {
            if (obj[i]->check == 1)
                temp[i] = new Polygon(*(Polygon*)obj[i]);
            else if (obj[i]->check == 2)
                temp[i] = new Circle(*(Circle*)obj[i]);
            else if (obj[i]->check == 3)
                temp[i] = new text(*(text*)obj[i]);
            else if (obj[i]->check == 4)
                temp[i] = new Line(*(Line*)obj[i]);
            else if (obj[i]->check == 5)
                temp[i] = new Curve(*(Curve*)obj[i]);
            else if (obj[i]->check == 6)
                temp[i] = new rectangle(*(rectangle*)obj[i]);
            else if (obj[i]->check == 7)
                temp[i] = new triangle(*(triangle*)obj[i]);

        }
        for (int i = 0; i < present_s; i++)
            delete obj[i];
        delete[] obj;
        obj = temp;
        capacity = capacity * 2;
        temp = nullptr;
    }
}


int main()
{
    ContextSettings settings;
    settings.antialiasingLevel = 4;

    // create the window
    RenderWindow window(VideoMode(1500, 800), "Paint", Style::Default, settings);

    //Textures
    Texture grid, texture1, texture2, texture3, texture4, texture5, texture6, texture7, texture8, texture9, texture10, texture11, texture12;

    grid.loadFromFile("GRID_MAIN.png");
    texture1.loadFromFile("line.png");
    texture2.loadFromFile("rectangle.png");
    texture3.loadFromFile("Circle1.png");
    texture4.loadFromFile("Polygon.png");
    texture5.loadFromFile("Curve.png");
    texture6.loadFromFile("text1.png");
    texture7.loadFromFile("bucket.png");
    texture8.loadFromFile("eraser.png");
    texture9.loadFromFile("dotted-line.png");
    texture10.loadFromFile("Triangle.png");
    texture11.loadFromFile("load-file.png");
    texture12.loadFromFile("save-file.png");

    //Sprite
    Sprite main_screen;
    main_screen.setTexture(grid);
    main_screen.setPosition(0.0f, 15.0f);

    //shapebuttons

    RectangleShape line;
    line.setTexture(&texture1);
    line.setSize(Vector2f(40.f, 68.f));
    line.setPosition(Vector2f(175.f, 68.f));

    RectangleShape dotted_line;
    dotted_line.setTexture(&texture9);
    dotted_line.setSize(Vector2f(40.f, 68.f));
    dotted_line.setPosition(Vector2f(37.f, 142.f));

    RectangleShape Rectangle;
    Rectangle.setTexture(&texture2);
    Rectangle.setSize(Vector2f(40.f, 68.f));
    Rectangle.setPosition(Vector2f(83.f, 142.f));

    RectangleShape circle1;
    circle1.setTexture(&texture3);
    circle1.setSize(Vector2f(40.f, 68.f));
    circle1.setPosition(Vector2f(129.f, 142.f));

    RectangleShape polygon;
    polygon.setTexture(&texture4);
    polygon.setSize(Vector2f(40.f, 68.f));
    polygon.setPosition(Vector2f(175.f, 142.f));

    RectangleShape Curve;
    Curve.setTexture(&texture5);
    Curve.setSize(Vector2f(40.f, 68.f));
    Curve.setPosition(Vector2f(37.5, 215.f));

    RectangleShape Triangle;
    Triangle.setTexture(&texture10);
    Triangle.setSize(Vector2f(40.f, 68.f));
    Triangle.setPosition(Vector2f(83.f, 215.f));

    RectangleShape Load;
    Load.setTexture(&texture11);
    Load.setSize(Vector2f(40.f, 68.f));
    Load.setPosition(Vector2f(129.f, 215.f));

    RectangleShape Save;
    Save.setTexture(&texture12);
    Save.setSize(Vector2f(40.f, 68.f));
    Save.setPosition(Vector2f(175.f, 215.f));

    Font font;
    font.loadFromFile("arial.ttf");

    Text texttemp;
    texttemp.setFont(font);
    texttemp.setString("Paint by Hiba & Wasi");
    texttemp.setFillColor(Color::White);
    texttemp.setCharacterSize(28);
    texttemp.setPosition(Vector2f(37, 2));


    RectangleShape text_button;
    text_button.setTexture(&texture6);
    text_button.setSize(Vector2f(40, 68));
    text_button.setPosition(Vector2f(129.f, 68.f));

    RectangleShape BucketTool;
    BucketTool.setTexture(&texture7);
    BucketTool.setSize(Vector2f(40, 68));
    BucketTool.setPosition(37.f, 68.f);

    RectangleShape Eraser;
    Eraser.setTexture(&texture8);
    Eraser.setSize(Vector2f(40, 68));
    Eraser.setPosition(83.f, 68.f);

    // All thhe colors
    RectangleShape RedColor;
    RedColor.setSize(Vector2f(40, 68));
    RedColor.setFillColor(Color::Red);
    RedColor.setPosition(37.f, 353.f);

    RectangleShape GreenColor;
    GreenColor.setSize(Vector2f(40, 68));
    GreenColor.setFillColor(Color::Green);
    GreenColor.setPosition(83.f, 353.f);

    RectangleShape BlueColor;
    BlueColor.setSize(Vector2f(40, 68));
    BlueColor.setFillColor(Color::Blue);
    BlueColor.setPosition(129.f, 353.f);

    RectangleShape YellowColor;
    YellowColor.setSize(Vector2f(40, 68));
    YellowColor.setFillColor(Color::Yellow);
    YellowColor.setPosition(175.f, 353.f);

    RectangleShape OrangeColor;
    OrangeColor.setSize(Vector2f(40, 68));
    OrangeColor.setFillColor(Color(255, 165, 0));
    OrangeColor.setPosition(37.f, 426.f);

    RectangleShape WhiteColor;
    WhiteColor.setSize(Vector2f(40, 68));
    WhiteColor.setFillColor(Color::White);
    WhiteColor.setPosition(83.f, 426.f);

    RectangleShape BlackColor;
    BlackColor.setSize(Vector2f(40, 68));
    BlackColor.setFillColor(Color(0, 0, 0));
    BlackColor.setPosition(129.f, 426.f);

    RectangleShape GoldColor;
    GoldColor.setSize(Vector2f(40, 68));
    GoldColor.setFillColor(Color(255, 215, 0));
    GoldColor.setPosition(175.f, 426.f);

    RectangleShape PinkColor;
    PinkColor.setSize(Vector2f(40, 68));
    PinkColor.setFillColor(Color(255, 20, 147));
    PinkColor.setPosition(37.f, 499.f);

    //
    RectangleShape LightBlueColor;
    LightBlueColor.setSize(Vector2f(40, 68));
    LightBlueColor.setFillColor(Color(176, 224, 230));
    LightBlueColor.setPosition(83.f, 499.f);

    /// 
    RectangleShape LightGreenColor;
    LightGreenColor.setSize(Vector2f(40, 68));
    LightGreenColor.setFillColor(Color(154, 205, 50));
    LightGreenColor.setPosition(129.f, 499.f);


    RectangleShape PurpleColor;
    PurpleColor.setSize(Vector2f(40, 68));
    PurpleColor.setFillColor(Color(148, 0, 211));
    PurpleColor.setPosition(174.f, 499.f);

    //Temperory Usage
    int currentColor = 0;
    Point those2points[2];
    int button_no = 0; int color_chosen = 0;
    int current_no_of_shapes = 0;
    int points_taken = 0;
    int no_of_circles = 0;
    int no_of_rectangles = 0;
    Point* poly_points = new Point[10];
    Point tri_points[3];
    // the Allshapes array
    //int all_shape_size;
    //shapes* Allshapes = nullptr;
    int capacity = 1;
    shapes** Allshapes = new shapes * [capacity];


    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();

            if (event.type == Event::KeyPressed)
            {
                if (event.key.code == Keyboard::Escape)
                {
                    window.close();
                }
            }

            if (event.type == Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == Mouse::Left)
                {
                    cout << "Mouse pressed." << endl;
                    cout << "mouse x: " << event.mouseButton.x << endl;
                    cout << "mouse y: " << event.mouseButton.y << endl;


                    BucketTool.setOutlineThickness(0.f);
                    line.setOutlineThickness(0.f);
                    dotted_line.setOutlineThickness(0.f);
                    text_button.setOutlineThickness(0.f);
                    Eraser.setOutlineThickness(0.f);
                    BlackColor.setOutlineThickness(0.f);
                    BlueColor.setOutlineThickness(0.f);
                    Rectangle.setOutlineThickness(0.f);
                    WhiteColor.setOutlineThickness(0.f);
                    RedColor.setOutlineThickness(0.f);
                    circle1.setOutlineThickness(0.f);
                    polygon.setOutlineThickness(0.f);
                    Curve.setOutlineThickness(0.f);
                    Load.setOutlineThickness(0.f);
                    Save.setOutlineThickness(0.f);
                    PurpleColor.setOutlineThickness(0.f);
                    PinkColor.setOutlineThickness(0.f);
                    GreenColor.setOutlineThickness(0.f);
                    LightBlueColor.setOutlineThickness(0.f);
                    LightGreenColor.setOutlineThickness(0.f);
                    OrangeColor.setOutlineThickness(0.f);
                    YellowColor.setOutlineThickness(0.f);
                    GoldColor.setOutlineThickness(0.f);
                    Triangle.setOutlineThickness(0.f);

                    if (isMouseOver(window, Rectangle))
                    {
                        cout << "Rectangle Button Clicked" << endl;
                        displayCursor(window, Rectangle, event);
                        button_no = 4;
                    }
                    if (isMouseOver(window, circle1))
                    {
                        cout << "Circle Button Clicked" << endl;
                        displayCursor(window, circle1, event);
                        button_no = 5;
                    }
                    if (isMouseOver(window, line))
                    {
                        cout << "Line Button Clicked" << endl;
                        displayCursor(window, line, event);
                        button_no = 6;
                    }
                    if (isMouseOver(window, polygon))
                    {
                        cout << "Polygon Button Clicked" << endl;
                        displayCursor(window, polygon, event);
                        button_no = 7;
                    }
                    if (isMouseOver(window, Triangle))
                    {
                        cout << "Triangle Button Clicked" << endl;
                        displayCursor(window, Triangle, event);
                        button_no = 8;
                    }
                    if (isMouseOver(window, text_button))
                    {
                        cout << "Text Button Clicked" << endl;
                        displayCursor(window, text_button, event);
                        button_no = 9;
                    }
                    if (isMouseOver(window, BucketTool))
                    {
                        cout << "Bucket Tool Clicked" << endl;
                        displayCursor(window, BucketTool, event);
                        button_no = 10;
                    }


                    displayCursor(window, dotted_line, event);
                    displayCursor(window, Eraser, event);
                    displayCursor(window, BlackColor, event);
                    displayCursor(window, BlueColor, event);
                    displayCursor(window, Curve, event);
                    displayCursor(window, Triangle, event);
                    displayCursor(window, Load, event);
                    displayCursor(window, Save, event);
                    displayCursor(window, GreenColor, event);
                    displayCursor(window, RedColor, event);
                    displayCursor(window, PinkColor, event);
                    displayCursor(window, PurpleColor, event);
                    displayCursor(window, WhiteColor, event);
                    displayCursor(window, LightBlueColor, event);
                    displayCursor(window, LightGreenColor, event);
                    displayCursor(window, YellowColor, event);
                    displayCursor(window, GoldColor, event);
                    displayCursor(window, OrangeColor, event);
                }


                if (!isMouseOver(window, main_screen))
                {
                    if (button_no == 4)
                    {
                        cout << "We in the LOOP" << endl;
                        if (points_taken < 2)
                        {
                            those2points[points_taken].x = event.mouseButton.x;
                            those2points[points_taken].y = event.mouseButton.y;
                            points_taken++;

                            if (points_taken == 2)
                            {
                                inc_shapes(Allshapes, current_no_of_shapes, capacity);
                                rectangle myRect(0, those2points);
                                Allshapes[current_no_of_shapes] = new rectangle(myRect);
                                Allshapes[current_no_of_shapes]->check = 6;
                                points_taken = 0;
                                button_no = 0;
                                current_no_of_shapes++;
                            }
                        }
                    }
                    else if (button_no == 5)
                    {
                        if (points_taken < 2)
                        {
                            those2points[points_taken].x = event.mouseButton.x;
                            those2points[points_taken].y = event.mouseButton.y;
                            points_taken++;

                            if (points_taken == 2)
                            {
                                inc_shapes(Allshapes, current_no_of_shapes, capacity);
                                Circle myCirc(0, those2points);
                                Allshapes[current_no_of_shapes] = new Circle(myCirc);
                                Allshapes[current_no_of_shapes]->check = 2;
                                points_taken = 0;
                                button_no = 0;
                                current_no_of_shapes++;
                            }
                        }
                    }
                    else if (button_no == 6)
                    {
                        if (points_taken < 2)
                        {
                            those2points[points_taken].x = event.mouseButton.x;
                            those2points[points_taken].y = event.mouseButton.y;
                            points_taken++;

                            if (points_taken == 2)
                            {
                                inc_shapes(Allshapes, current_no_of_shapes, capacity);
                                Line myLine(0, those2points);
                                Allshapes[current_no_of_shapes] = new Line(myLine);
                                Allshapes[current_no_of_shapes]->check = 4;
                                points_taken = 0;
                                button_no = 0;
                                current_no_of_shapes++;
                            }
                        }
                    }
                    else if (button_no == 7)
                    {
                        poly_points[points_taken].x = event.mouseButton.x;
                        poly_points[points_taken].y = event.mouseButton.y;
                        points_taken++;
                        cout << "Point Taken" << endl;

                        if (event.mouseButton.button == Mouse::Right && points_taken > 2)
                        {
                            inc_shapes(Allshapes, current_no_of_shapes, capacity);
                            cout << "Right Mouse Button Pressed" << endl;
                            Polygon myPoly(0, poly_points, points_taken - 1);
                            Allshapes[current_no_of_shapes] = new Polygon(myPoly);
                            Allshapes[current_no_of_shapes]->check = 1;
                            points_taken = 0;
                            button_no = 0;
                            current_no_of_shapes++;
                        }
                    }

                    else if (button_no == 8)
                    {
                        tri_points[points_taken].x = event.mouseButton.x;
                        tri_points[points_taken].y = event.mouseButton.y;
                        points_taken++;
                        cout << "Point Taken" << endl;

                        if (points_taken > 2)
                        {
                            inc_shapes(Allshapes, current_no_of_shapes, capacity);
                            cout << "Right Mouse Button Pressed" << endl;
                            triangle myTriangle(0, tri_points);
                            Allshapes[current_no_of_shapes] = new triangle(myTriangle);
                            Allshapes[current_no_of_shapes]->check = 7;
                            points_taken = 0;
                            button_no = 0;
                            current_no_of_shapes++;
                        }
                    }

                    else if (button_no == 9)
                    {
                        inc_shapes(Allshapes, current_no_of_shapes, capacity);
                        Point temp;
                        string str;
                        temp.x = event.mouseButton.x;
                        temp.y = event.mouseButton.y;
                        cout << "ENTER YOUR TEXT" << endl;
                        getline(cin, str);
                        text mytext(0, temp, str);
                        Allshapes[current_no_of_shapes] = new text(mytext);
                        Allshapes[current_no_of_shapes]->check = 4;
                        current_no_of_shapes++;
                        button_no = 0;
                    }

                    else if (button_no == 10)
                    {
                        int len = current_no_of_shapes;
                        Allshapes[len - 1]->fillColor(1);  //test colors 1 to 12 accorfing to the palette shown on paint window ; 1 for red, 2 for green , 3 for blue etc
                        button_no = 0;
                    }
                }
            }
        }

        window.clear(Color::Black);

        /*Vertex line2[] =
        {
            Vertex(Vector2f(300, 10)),
            Vertex(Vector2f(150, 150))
        };

        window.draw(line2, 2, Lines);*/
        /*ConvexShape lol;
        lol.setPointCount(4);
        lol.setPoint(0, Vector2f(500, 100));
        lol.setPoint(1, Vector2f(200, 200));
        lol.setPoint(2, Vector2f(100, 200));
        lol.setPoint(3, Vector2f(300, 350));
        lol.setOutlineThickness(5);
        lol.setOutlineColor(Color::White);
        lol.setFillColor(Color::Black);*/

        //window.draw(lol);
        window.draw(main_screen);
        window.draw(BucketTool);
        window.draw(Eraser);
        window.draw(text_button);
        window.draw(line);
        window.draw(dotted_line);
        window.draw(Rectangle);
        window.draw(circle1);
        window.draw(polygon);
        window.draw(Curve);
        window.draw(Triangle);
        window.draw(Load);
        window.draw(Save);
        window.draw(RedColor);
        window.draw(BlueColor);
        window.draw(YellowColor);
        window.draw(OrangeColor);
        window.draw(GreenColor);
        window.draw(BlackColor);
        window.draw(WhiteColor);
        window.draw(GoldColor);
        window.draw(PinkColor);
        window.draw(LightBlueColor);
        window.draw(LightGreenColor);
        window.draw(PurpleColor);
        window.draw(texttemp);

        if (Allshapes != nullptr)
        {
            for (int i = 0; i < current_no_of_shapes; i++)
            {
                Allshapes[i]->draw(window);
            }
        }
        // end the current frame

        window.display();
    }
    delete[] poly_points;
    poly_points = nullptr;

    //system("pause");
}