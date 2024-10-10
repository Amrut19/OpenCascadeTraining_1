#include "pch.h"
#include "MainViewer.h"
#include<WNT_Window.hxx>
#include<TopoDS_Shape.hxx>
#include<BRepPrimAPI_MakeBox.hxx>
#include <AIS_Shape.hxx>
#include <BRepPrimAPI_MakeSphere.hxx>
#include<BRepPrimAPI_MakeCylinder.hxx>
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

	/*m_bgColor1 = Quantity_NOC_RED;
	m_bgColor2 = Quantity_NOC_GRAY;

	m_pV3dView->SetBgGradientColors(m_bgColor1, m_bgColor2, Aspect_GFM_VER);*/

}

void MainViewer::displayBoxShape()
{

	m_pAISContext->RemoveAll(Standard_True);

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

	m_bgColor1 = Quantity_NOC_PURPLE;
	m_bgColor2 = Quantity_NOC_PINK;

	m_pV3dView->SetBgGradientColors(m_bgColor1, m_bgColor2, Aspect_GFM_VER);
}

void MainViewer::displayPoint()
{
	m_pAISContext->RemoveAll(Standard_True);
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

	m_bgColor1 = Quantity_NOC_BLACK;
	m_bgColor2 = Quantity_NOC_SKYBLUE;

	m_pV3dView->SetBgGradientColors(m_bgColor1, m_bgColor2, Aspect_GFM_VER);

}

void MainViewer::displayLine()
{

	m_pAISContext->RemoveAll(Standard_True);
	gp_Pnt p1(100,100,100);

	gp_Pnt p2(10, 10, 10);
	
	gp_Vec v1(p1, p2);
	
	BRepPrimAPI_MakeCylinder mk_cyclinder= BRepPrimAPI_MakeCylinder(100, v1.Magnitude());

	Handle(AIS_Shape) t1 =  new	AIS_Shape(mk_cyclinder);

	m_pAISContext->Display(t1, Standard_True); 

	m_pAISContext->SetDisplayMode(AIS_Shaded, Standard_True);


	m_pV3dView->MustBeResized();
	m_pAISContext->UpdateCurrentViewer();

	m_bgColor1 = Quantity_NOC_GREENYELLOW;
	m_bgColor2 = Quantity_NOC_ORANGE;

	m_pV3dView->SetBgGradientColors(m_bgColor1, m_bgColor2, Aspect_GFM_VER);

}
