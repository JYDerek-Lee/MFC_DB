
// Assignment2.h : Assignment2 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CAssignment2App:
// �� Ŭ������ ������ ���ؼ��� Assignment2.cpp�� �����Ͻʽÿ�.
//

class CAssignment2App : public CWinApp
{
public:
	CAssignment2App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CAssignment2App theApp;
