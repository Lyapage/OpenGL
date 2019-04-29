#ifndef _WX_CUBE_H
#define _WX_CUBE_H

#include"wx/glcanvas.h"


class MyContext :public wxGLContext 
{
public:
		MyContext(wxGLCanvas* canvas);
	    void Render(float xangle, float yangle);
                                                                                          
};

class MyApp :public wxApp 
{
public:
	
	MyContext& GetContext(wxGLCanvas *canvas);

	virtual bool OnInit();
	virtual int  OnExit();

private:						
	MyContext *glcontext;

};

class MyFrame :public wxFrame 
{
public:
	MyFrame(bool stereoWindow = false);

private:
	void OnClose(wxCommandEvent& event);
	void OnNewWindow(wxCommandEvent& event);
	void OnAbout(wxCommandEvent& event);
	wxDECLARE_EVENT_TABLE();
};

class MyCanvas :public wxGLCanvas 
{
public:
	MyCanvas(wxWindow*parent, int *attribList = NULL);

private:
	void OnPaint(wxPaintEvent& event);
	void Spin(float xangle, float yangle);
	void OnKey(wxKeyEvent& event);
	void OnSpinTimer(wxTimerEvent& WXUNUSED(event));

	float mxangle, myangle;
	wxTimer mspinTimer;
	wxDECLARE_EVENT_TABLE();
};
#endif
