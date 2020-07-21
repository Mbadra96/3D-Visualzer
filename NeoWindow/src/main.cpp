//#include "Window.h"
//#include "Model.h"
//#include "Line.h"
//#include "Floor.h"
//#include <math.h>
//#include <map>
//class Point
//{
//public:
//    float m_X,m_Y;
//    Point(float x ,float y)
//    {
//        m_X = x;
//        m_Y = y;
//    }
//};
//
//int main(void)
//{
//    Window window;
//    window.Init();
//
//
//  /*  std::vector<Point> points;
//
//    
//    for (int i = -100; i < 100; i++)
//    {
//        points.emplace_back(Point(i / 10.0f, sin(i / 10.0)));
//    }*/
//    std::map<int, Shape* > newModels;
//
//    
//    //std::vector<Shape*> models;
//    auto floor =  new Floor();
//    auto xline = new Line(-10.0, 0.0, 0.0, 10.0, 0.0, 0.0, 0.0, 0.0, 1.0);
//    auto yline = new Line(0.0, -10.0, 0.0, 0.0, 10.0, 0.0, 0.0, 1.0, 0.0);
//    auto zline = new Line(0.0, 0.0, 0.0, 0.0, 0.0, 10.0, 1.0, 0.0, 0.0);
//
//    newModels.emplace(std::pair<int, Shape*>(0, floor));
//    newModels.emplace(std::pair<int, Shape*>(1, xline));
//    newModels.emplace(std::pair<int, Shape*>(2, yline));
//    newModels.emplace(std::pair<int, Shape*>(3, zline));
//    //models.push_back(xline);
//    //models.push_back(yline);
//    //models.push_back(zline);
//    //models.push_back(floor);
//   /* for (int i = 0 ;i<points.size();i++)
//    {
//        if (i == 0)
//            continue;
//        models.emplace_back(new Line(points[i-1].m_X,points[i-1].m_Y,0.0f, points[i].m_X, points[i].m_Y,0.0f,0.0f,0.0f,0.0f,1.0f));
//
//    }*/
//    auto cube = new Model("res/textures/cylinder.STL");
//    //cube->SetPosition(1, 0, 0);
//    cube->SetRotation(90, 1, 0, 0);
//    //models.emplace_back(cube);
//
//    
//    
//    
//    while (!window.WindowClosed())
//    {
//        cube->Translate(0.01, 0, 0);
//        cube->Rotate(1, 0, 1, 0);
//        window.Draw(newModels);
//    }
//
//    //for (Shape * model : models)
//    //{
//    //    delete model;
//    //    
//    //}
//}

#include "Renderer.h"

int main()
{
	Renderer R;

	//int floor = R.AddFloor();
	int cylinder = R.AddModel("res/textures/cylinder.STL");
	R.DrawCoord(5);
	while (!R.Closed())
	{

		R.Rotate(cylinder, 1, 0, 1, 0);
		R.Update();
		
	}





	
}