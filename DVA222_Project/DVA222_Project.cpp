// DVA222_Project.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Graphix.h"
#include "glut.h"
#include "MyButton.h"
#include "Label.h"
#include "Panel.h"
#include "ImageBox.h"

using namespace std;


int _tmain(int argc, char** argv)
{
    //A new object of Button type is create and passed to the InitOGL function. 
    //From that point the control is handed over to the OpenGL window and stays there until the user closes the Window.
    //This means after calling the InitOGL function no further lines of code in the main function are executed until we close the Window.
    //------------------------------------------------------------------------------------------------------------------------------------
    ControlBase* button = new MyButton(100,100,180,60);
	ControlBase* IM = new ImageBox("TestImage.bmp",100,100,156,187);
	panel->SetBackgroundColor(0, 0, 0);

	panel->AddControl(button);

	InitOGL(argc,argv,IM);

    delete panel;
	delete IM;
	return 0;
}

