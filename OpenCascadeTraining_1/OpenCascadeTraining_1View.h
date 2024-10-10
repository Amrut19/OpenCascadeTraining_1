
// OpenCascadeTraining_1View.h : interface of the COpenCascadeTraining1View class
//

#pragma once
#include"MainViewer.h"

class COpenCascadeTraining1View : public CView
{
	MainViewer* m_pMainFrame = new MainViewer();
protected: // create from serialization only
	COpenCascadeTraining1View() noexcept;
	DECLARE_DYNCREATE(COpenCascadeTraining1View)

// Attributes
public:
	COpenCascadeTraining1Doc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

	void OnInitialUpdate();


protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~COpenCascadeTraining1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDemoBox();
	afx_msg void OnDemoBox32773();
	afx_msg void OnDemoPoint();
};

#ifndef _DEBUG  // debug version in OpenCascadeTraining_1View.cpp
inline COpenCascadeTraining1Doc* COpenCascadeTraining1View::GetDocument() const
   { return reinterpret_cast<COpenCascadeTraining1Doc*>(m_pDocument); }
#endif

