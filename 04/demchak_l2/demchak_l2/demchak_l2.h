
// demchak_l2.h : ������� ���� ��������� ��� ���������� PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"		// �������� �������


// Cdemchak_l2App:
// � ���������� ������� ������ ��. demchak_l2.cpp
//

class Cdemchak_l2App : public CWinApp
{
public:
	Cdemchak_l2App();

// ���������������
public:
	virtual BOOL InitInstance();

// ����������

	DECLARE_MESSAGE_MAP()
};

extern Cdemchak_l2App theApp;
