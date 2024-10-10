
// OpenCascadeTraining_1View.cpp : implementation of the COpenCascadeTraining1View class

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "OpenCascadeTraining_1.h"
#endif

#include "OpenCascadeTraining_1Doc.h"
#include "OpenCascadeTraining_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// COpenCascadeTraining1View

IMPLEMENT_DYNCREATE(COpenCascadeTraining1View, CView)

BEGIN_MESSAGE_MAP(COpenCascadeTraining1View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &COpenCascadeTraining1View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	
	ON_COMMAND(ID_DEMO_BOX32773, &COpenCascadeTraining1View::OnDemoBox32773)
END_MESSAGE_MAP()

// COpenCascadeTraining1View construction/destruction

COpenCascadeTraining1View::COpenCascadeTraining1View() noexcept
{
	// TODO: add construction code here

}

COpenCascadeTraining1View::~COpenCascadeTraining1View()
{
}

BOOL COpenCascadeTraining1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

void COpenCascadeTraining1View::OnInitialUpdate()
{

	CView::OnInitialUpdate();

	m_pMainFrame->setWindow(GetSafeHwnd());



}

// COpenCascadeTraining1View drawing

void COpenCascadeTraining1View::OnDraw(CDC* /*pDC*/)
{
	COpenCascadeTraining1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// COpenCascadeTraining1View printing


void COpenCascadeTraining1View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL COpenCascadeTraining1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void COpenCascadeTraining1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void COpenCascadeTraining1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void COpenCascadeTraining1View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void COpenCascadeTraining1View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// COpenCascadeTraining1View diagnostics

#ifdef _DEBUG
void COpenCascadeTraining1View::AssertValid() const
{
	CView::AssertValid();
}

void COpenCascadeTraining1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

COpenCascadeTraining1Doc* COpenCascadeTraining1View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(COpenCascadeTraining1Doc)));
	return (COpenCascadeTraining1Doc*)m_pDocument;
}
#endif //_DEBUG


// COpenCascadeTraining1View message handlers


void COpenCascadeTraining1View::OnDemoBox()
{
	// TODO: Add your command handler code here
	m_pMainFrame->displayBoxShape();
}


void COpenCascadeTraining1View::OnDemoBox32773()
{
	// TODO: Add your command handler code here
	m_pMainFrame->displayBoxShape();
}
