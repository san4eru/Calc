﻿
// Calc.h: главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CCalcApp:
// Сведения о реализации этого класса: Calc.cpp
//

class CCalcApp : public CWinApp
{
public:
	CCalcApp();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CCalcApp theApp;
