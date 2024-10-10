#include "pch.h"
#include "MainViewer.h"
#include<WNT_Window.hxx>
#include<TopoDS_Shape.hxx>
#include<BRepPrimAPI_MakeBox.hxx>
#include <AIS_Shape.hxx>
#include <BRepPrimAPI_MakeSphere.hxx>
MainViewer::MainViewer()
{
	
	/*Handle(OpenGl_GraphicDriver) m_pGraphicsDriver;
	Handle(V3d_Viewer) m_pV3d_Viewer;
	Handle(AIS_InteractiveContext) m_pAISContext;
	Handle(V3d_View) m_pV3dView;
	Quantity_Color m_bgColor1, m_bgColor2;*/

	m_pGraphicsDriver = new OpenGl_GraphicDriver(new Aspect_DisplayConnection());

	m_pV3d_Viewer = new V3d_Viewer(m_pGraphicsDriver);

	m_pV3dView = new V3d_View(m_pV3d_Viewer);

	m_pAISContext = new AIS_InteractiveContext(m_pV3d_Viewer);

	m_pV3dView->ActiveLights();

	m_pV3d_Viewer->SetDefaultLights();
	m_pV3d_Viewer->SetLightOn();
	m_pV3dView = m_pV3d_Viewer->CreateView();




}

MainViewer::~MainViewer()
{
}

void MainViewer::setWindow(HWND hwnd)
{
	Handle(WNT_Window) aWNT_Window = new WNT_Window(hwnd);

	if (aWNT_Window.IsNull())
	{
		return;
		//aWNT_Window->Map();
	}
	m_pV3dView->Redraw();
	m_pV3dView->SetWindow(aWNT_Window);

	if (aWNT_Window->IsMapped())
	{
		aWNT_Window->Map();
	}

	Graphic3d_RenderingParams& aParams = m_pV3dView->ChangeRenderingParams();
	aParams.IsAntialiasingEnabled = Standard_True;
	aParams.NbMsaaSamples=8;

	m_bgColor1 = Quantity_NOC_RED;
	m_bgColor2 = Quantity_NOC_GRAY;

	m_pV3dView->SetBgGradientColors(m_bgColor1, m_bgColor2, Aspect_GFM_VER);

}

void MainViewer::displayBoxShape()
{
	TopoDS_Shape shape =  BRepPrimAPI_MakeBox(300, 300, 300);

	//check if shape is valid 
	if (shape.IsNull())
	{
		std::cout << "box not created ";
	}

	Handle(AIS_Shape) aisShape = new AIS_Shape(shape);

	
	
	m_pAISContext->Display(aisShape, Standard_True);
	m_pAISContext->SetDisplayMode(AIS_Shaded, Standard_True);

	m_pV3dView->MustBeResized();
	m_pAISContext->UpdateCurrentViewer();

	

	std::cout << "Displaying shape..." << std::endl;


}

void MainViewer::displayPoint()
{
	gp_Pnt m_center(5, 5, 5);
	Standard_Real radius(100);
	TopoDS_Shape m_mkSphere = BRepPrimAPI_MakeSphere(m_center, radius);

	

	if (m_mkSphere.IsNull())
	{
		std::cout << "sphere not created";
	}
	Handle(AIS_Shape) pt_mkSphere = new AIS_Shape(m_mkSphere);

	m_pAISContext->Display(pt_mkSphere, Standard_True);
	m_pAISContext->SetDisplayMode(AIS_Shaded, Standard_True);


	m_pV3dView->MustBeResized();

	m_pAISContext->UpdateCurrentViewer();
	std::cout << "Displaying shape..." << std::endl;



}
