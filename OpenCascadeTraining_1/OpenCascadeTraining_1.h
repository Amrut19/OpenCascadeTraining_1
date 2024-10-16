
// OpenCascadeTraining_1.h : main header file for the OpenCascadeTraining_1 application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// COpenCascadeTraining1App:
// See OpenCascadeTraining_1.cpp for the implementation of this class
//

class COpenCascadeTraining1App : public CWinAppEx
{
public:
	COpenCascadeTraining1App() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern COpenCascadeTraining1App theApp;
