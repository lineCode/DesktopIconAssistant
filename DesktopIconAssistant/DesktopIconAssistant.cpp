// DesktopIconAssistant.cpp : ����Ӧ�ó��������Ϊ��
//

#include "stdafx.h"
#include "global.h"
#include "DesktopIconAssistant.h"
#include "DesktopIconAssistantDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDesktopIconAssistantApp

BEGIN_MESSAGE_MAP(CDesktopIconAssistantApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CDesktopIconAssistantApp ����

CDesktopIconAssistantApp::CDesktopIconAssistantApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CDesktopIconAssistantApp ����

CDesktopIconAssistantApp theApp;


// CDesktopIconAssistantApp ��ʼ��

BOOL CDesktopIconAssistantApp::InitInstance()
{
	// Run one application only
	HANDLE hRet = CreateMutex(NULL, TRUE, STR_APP_TITLE);
	if (GetLastError() == ERROR_ALREADY_EXISTS)
	{
		HWND hWnd = FindWindow(NULL, STR_APP_TITLE);
		ShowWindow(hWnd, SW_SHOWNORMAL);
		SetForegroundWindow(hWnd);
		return FALSE;
	}

	// ���һ�������� Windows XP �ϵ�Ӧ�ó����嵥ָ��Ҫ
	// ʹ�� ComCtl32.dll �汾 6 ����߰汾�����ÿ��ӻ���ʽ��
	//����Ҫ InitCommonControlsEx()�����򣬽��޷��������ڡ�
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// ��������Ϊ��������Ҫ��Ӧ�ó�����ʹ�õ�
	// �����ؼ��ࡣ
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();

	AfxEnableControlContainer();

	// ��׼��ʼ��
	// ���δʹ����Щ���ܲ�ϣ����С
	// ���տ�ִ���ļ��Ĵ�С����Ӧ�Ƴ�����
	// ����Ҫ���ض���ʼ������
	// �������ڴ洢���õ�ע�����
	// TODO: Ӧ�ʵ��޸ĸ��ַ�����
	// �����޸�Ϊ��˾����֯��
	SetRegistryKey(STR_APP_TITLE);

	CDesktopIconAssistantDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: �ڴ˷��ô����ʱ��
		//  ��ȷ�������رնԻ���Ĵ���
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: �ڴ˷��ô����ʱ��
		//  ��ȡ�������رնԻ���Ĵ���
	}

	// ���ڶԻ����ѹرգ����Խ����� FALSE �Ա��˳�Ӧ�ó���
	//  ����������Ӧ�ó������Ϣ�á�
	return FALSE;
}
