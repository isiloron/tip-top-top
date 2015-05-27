// DVA222_Project.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Graphix.h"
#include "glut.h"
#include "MyButton.h"
#include "Label.h"
#include "Panel.h"

using namespace std;


int _tmain(int argc, char** argv)
{
    //A new object of Button type is create and passed to the InitOGL function. 
    //From that point the control is handed over to the OpenGL window and stays there until the user closes the Window.
    //This means after calling the InitOGL function no further lines of code in the main function are executed until we close the Window.
    //------------------------------------------------------------------------------------------------------------------------------------
	Panel *panel = new Panel(50, 50, 200, 200);
	panel->SetBackgroundColor(0, 0, 0);

    ControlBase* button = new MyButton(10,10,190,60);

	InitOGL(argc, argv, button);
	InitOGL(argc, argv, mylabel);
	//hejhejhej
    delete button;
	delete mylabel;
	return 0;
}

