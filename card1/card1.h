
// card1.h: PROJECT_NAME 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含 'pch.h' 以生成 PCH"
#endif

#include "resource.h"		// 主符号


// Ccard1App:
// 有关此类的实现，请参阅 card1.cpp
//

class Ccard1App : public CWinApp
{
public:
	Ccard1App();

// 重写
public:
	virtual BOOL InitInstance();

// 实现

	DECLARE_MESSAGE_MAP()
};

extern Ccard1App theApp;
