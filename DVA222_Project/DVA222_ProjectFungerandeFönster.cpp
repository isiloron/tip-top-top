// DVA222_Project.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Graphix.h"
#include "glut.h"
#include "MyButton.h"
#include "Window.h"
#include "CheckBoxGroup.h"
#include "RadioButtonGroup.h"
#include "Panel.h"
using namespace std;


int _tmain(int argc, char** argv)
{
    //A new object of Button type is create and passed to the InitOGL function. 
    //From that point the control is handed over to the OpenGL window and stays there until the user closes the Window.
    //This means after calling the InitOGL function no further lines of code in the main function are executed until we close the Window.
    //------------------------------------------------------------------------------------------------------------------------------------
    ControlBase* button = new MyButton(10,10,190,60);
	Window* Win = new Window(20,20,700,700,"massa tittel");
	CheckBoxGroup* CBG = new CheckBoxGroup("CheckBoxGrop",40,40,180,100);
	CBG->AddToggleButton("test1");
	CBG->AddToggleButton("test2");
	CBG->AddToggleButton("test3");

	RadioButtonGroup* RBG = new RadioButtonGroup("RadioButtonGroup",240,40,180,100);
	RBG->AddToggleButton("radio test1");
	RBG->AddToggleButton("radio test2");
	RBG->AddToggleButton("radio test3");


	Label* alabel = new Label("check all this labeling",40,190);
	CheckBox* enbox = new CheckBox(40,200,12,12);
	RadioButton* enradio = new RadioButton(40,220,12,12);
	ImageBox* enbild = new ImageBox("TestImage.bmp",40,240,100,100);
	Panel* enkelpanel = new Panel(200,200,300,100);
	enkelpanel->SetZ(-1);
	Label* paneltext = new Label("massa text i en panel",10,10);

	Panel* lessSimplePanel = new Panel(250,250,400,150);
	lessSimplePanel->SetBackgroundColor(100,100,255);
	Label* superLabel = new Label("a lot of even more text, do not lissen to the panel behind me",20,20);
	Button* mybutton = new Button(20,50,190,60);
	mybutton->LoadBitmaps("ButtonNorm.bmp","ButtonHover.bmp","ButtonPressed.bmp");

	lessSimplePanel->AddControl(superLabel);
	lessSimplePanel->AddControl(mybutton);

	enkelpanel->AddControl(paneltext);

	Win->AddControl(enbild);
	Win->AddControl(enradio);
	Win->AddControl(enbox);
	Win->AddControl(CBG);
	Win->AddControl(RBG);
	Win->AddControl(alabel);
	Win->AddControl(enkelpanel);
	Win->AddControl(lessSimplePanel);
	InitOGL(argc, argv, Win);

    delete button;
	return 0;
}

