#pragma once

#include "Window.h"
#include "Model.h"
#include "Line.h"
#include "Floor.h"
#include <math.h>
#include <map>

class Renderer
{
private:
    Window m_Window;
    int m_ModelCounter = 0;
    std::map<int,Shape*> m_Models;

public:
    Renderer();
    int AddModel(const std::string& filepath);
    int AddLine(float x1, float y1, float z1, float x2, float y2, float z2, float r = 1.0, float g = 1.0,float b = 1.0,float a = 1.0);
    int AddFloor();
    void SetPosition(int model_id, float x, float y, float z);
    void SetRotation(int model_id, float angle,float x, float y, float z);
    void Rotate(int model_id, float angle,float x, float y, float z);
    void Translate(int model_id, float x, float y, float z);
    void Remove(int id);
    void Update();
    void DrawCoord(float length = 1);
    int Closed();

    ~Renderer() {

        for (auto itr = m_Models.begin(); itr != m_Models.end(); ++itr)
        {
            delete itr->second;
        }
    }


};



//int main(void)
//{
//    Window window;
//    window.Init();
//
//
//
//    std::vector<Shape*> models;
//    auto floor = new Floor();
//    auto xline = new Line(-10.0, 0.0, 0.0, 10.0, 0.0, 0.0, 0.0, 0.0, 1.0);
//    auto yline = new Line(0.0, -10.0, 0.0, 0.0, 10.0, 0.0, 0.0, 1.0, 0.0);
//    auto zline = new Line(0.0, 0.0, 0.0, 0.0, 0.0, 10.0, 1.0, 0.0, 0.0);
//    models.push_back(xline);
//    models.push_back(yline);
//    models.push_back(zline);
//    models.push_back(floor);
//
//    auto cube = new Model("res/textures/cylinder.STL");
//    //cube->SetPosition(1, 0, 0);
//    cube->SetRotation(90, 1, 0, 0);
//    models.emplace_back(cube);
//
//
//
//
//    while (!window.WindowClosed())
//    {
//        cube->Translate(0.01, 0, 0);
//        cube->Rotate(1, 0, 1, 0);
//        //window.Draw(models);
//    }
//
//    
//}


