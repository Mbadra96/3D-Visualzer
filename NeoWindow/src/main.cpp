#include "Window.h"
#include "Model.h"
#include "Line.h"
#include "Floor.h"
int main(void)
{
    Window window;
    window.Init();

    
    auto cylinder1 = new Model("res/textures/cylinder.stl",1.0f,0.0f,0.0f);

    auto xline = new Line(0.0, 0.0, 0.0, 10.0, 0.0, 0.0,0.0,0.0,1.0);
    auto yline = new Line(0.0, 0.0, 0.0, 0.0, 10.0, 0.0,0.0,1.0,0.0);
    auto zline = new Line(0.0, 0.0, 0.0, 0.0, 0.0, 10.0,1.0,0.0,0.0);
    auto floor = new Floor();
    std::vector<Shape*> models;
    
    models.push_back(cylinder1);
    models.push_back(xline);
    models.push_back(yline);
    models.push_back(zline);
    models.push_back(floor);
    
    while (!window.WindowClosed())
    {
        window.Draw(models);
    }

    delete xline;
    delete yline;
    delete zline;
    delete floor;
    delete cylinder1;



}
