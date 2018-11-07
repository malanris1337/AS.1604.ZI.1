
// demchak_l2.h : главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// Cdemchak_l2App:
// О реализации данного класса см. demchak_l2.cpp
//

class Cdemchak_l2App : public CWinApp
{
public:
	Cdemchak_l2App();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern Cdemchak_l2App theApp;
