#include "Window.h"

int main(void)
{
    Window window;
    window.Init();

    
    Shape shape1;
    Shape shape2;
    Shape shape3;
    Shape shape4;
    Shape shape5;
    Shape shape6;

    shape1.Translate(-1, -1, -1);
    shape2.Translate(-1, 1, -1);
    shape3.Translate(-1, 1, 1);
    shape4.Translate(1, -1, -1);
    shape5.Translate(1, 1, -1);
    shape6.Translate(1, 1, 1);
    std::vector<Shape*> shapes;
    shapes.push_back(&shape1);
    shapes.push_back(&shape2);
    shapes.push_back(&shape3);
    shapes.push_back(&shape4);
    shapes.push_back(&shape5);
    shapes.push_back(&shape6);

    

    while (!window.WindowClosed())
    {
        //shape1.Rotate(1.0f, 1.0f, 1.0f, 1.0f);
;        window.Draw(shapes);
    }



}
