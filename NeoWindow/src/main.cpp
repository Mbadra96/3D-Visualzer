#include "Window.h"

int main(void)
{
    Window window;
    window.Init();

    Shape shape1;

    std::vector<Shape*> shapes;
    shapes.push_back(&shape1);
    

    while (!window.WindowClosed())
    {
        //shape1.Rotate(1.0f, 1.0f, 1.0f, 1.0f);
;        window.Draw(shapes);
    }



}
