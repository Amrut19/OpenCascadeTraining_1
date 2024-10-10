#pragma once
#include<OpenGl_GraphicDriver.hxx>
#include<V3d_Viewer.hxx>
#include<AIS_InteractiveContext.hxx>
#include<V3d_View.hxx>
#include<Standard_Handle.hxx>
class MainViewer
{
	Handle(OpenGl_GraphicDriver) m_pGraphicsDriver;
	Handle(V3d_Viewer) m_pV3d_Viewer;
	Handle(AIS_InteractiveContext) m_pAISContext;
	Handle(V3d_View) m_pV3dView;
	Quantity_Color m_bgColor1, m_bgColor2;

public:
	MainViewer();
	~MainViewer();

	void setWindow(HWND hwnd);
	void displayBoxShape();

};

