// DesktopIconAssistant.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CDesktopIconAssistantApp:
// �йش����ʵ�֣������ DesktopIconAssistant.cpp
//

class CDesktopIconAssistantApp : public CWinApp
{
public:
	CDesktopIconAssistantApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CDesktopIconAssistantApp theApp;