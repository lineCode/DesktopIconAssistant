// DesktopIconAssistantDlg.h : ͷ�ļ�
// Created by Ben
// 2008-2-18

#pragma once
#include "global.h"
#include "bitbuttonnl.h"
#include "DesktopIcon.h"
#include "afxwin.h"
#include "afxcmn.h"


// CDesktopIconAssistantDlg �Ի���
class CDesktopIconAssistantDlg : public CDialog
{
// ����
public:
	CDesktopIconAssistantDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_DESKTOPICONASSISTANT_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��

// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	virtual BOOL PreTranslateMessage(MSG* pMsg);	// ����ToolTip
	DECLARE_MESSAGE_MAP()

	virtual void OnOK();
	virtual void OnCancel();
public:
	///////////////////////////////////////////////////////////////
	// �����Ϣ

	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);	// ����϶�����
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);	
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);	// ���˫����С����������

	///////////////////////////////////////////////////////////////
	// ��ť��Ϣ
	//

	// ϵͳ��ť
	afx_msg void OnBnClickedButtonClose();	// �ر�
	afx_msg void OnBnClickedButtonMin();	// ��С��
	
	// ���й��߰�ť
	afx_msg void OnBnClickedButtonLine();		// ֱ�߹���
	afx_msg void OnBnClickedButtonHollowRect();	// ���ľ��ι���
	afx_msg void OnBnClickedButtonFillRect();	// ʵ�ľ��ι���
	afx_msg void OnBnClickedButtonHeart();		// ���ι��� 
	afx_msg void OnBnClickedButtonOval();		// ��Բ�ι���
	afx_msg void OnBnClickedButtonBezier();		// Bezier���߹���

	// ���빤�߰�ť
	afx_msg void OnBnClickedButtonUp();			// ��
	afx_msg void OnBnClickedButtonDown();		// ��
	afx_msg void OnBnClickedButtonLeft();		// ��
	afx_msg void OnBnClickedButtonRight();		// ��

	// ���ѡ��ť
	afx_msg void OnBnClickedButtonBig();		// ��
	afx_msg void OnBnClickedButtonMid();		// ��
	afx_msg void OnBnClickedButtonSmall();		// С
	afx_msg void OnBnClickedButtonAuto();		// �Զ�
	afx_msg void OnBnClickedButtonCustom();		// �Զ���
	
	// ������ť
	afx_msg void OnBnClickedButtonSave();		// ����
	afx_msg void OnBnClickedButtonLoad();		// ��ȡ
	afx_msg void OnBnClickedButtonUndo();		// ����
	afx_msg void OnBnClickedButtonRedo();		// �ظ�
	afx_msg void OnBnClickedButtonHideText();	// ��������ͼ������
	afx_msg void OnBnClickedButtonExchange();	// ��������ͼ���λ��

	///////////////////////////////////////////////////////////////
	// ���̲˵���Ϣ
	//

	// ϵͳ�˵�
	afx_msg void OnExit();			// �˳�
	afx_msg void OnShow();			// ��ʾ������
	afx_msg void OnAbout();			// ����

	// ���й��߲˵�	
	afx_msg void OnLine();			// ֱ�߹���
	afx_msg void OnFillrect();		// ʵ�ľ��ι���
	afx_msg void OnHollowrect();	// ���ľ��ι���
	afx_msg void OnHeart();			// ���ι���
	afx_msg void OnOval();			// ��Բ�ι���
	afx_msg void OnBezier();		// Bezier���߹���

	// ���빤�߲˵�
	afx_msg void OnAlignUp();		// ��
	afx_msg void OnAlignDown();		// ��
	afx_msg void OnAlignLeft();		// ��
	afx_msg void OnAlignRight();	// ��

	// ���ѡ��˵�
	afx_msg void OnSpaceBig();		// ��
	afx_msg void OnSpaceMid();		// ��
	afx_msg void OnSpaceSmall();	// С
	afx_msg void OnSpaceAuto();		// �Զ�
	afx_msg void OnSpaceCustom();	// �Զ���

	// �����˵�
	afx_msg void OnSave();			// ����
	afx_msg void OnLoad();			// ��ȡ
	afx_msg void OnRedo();			// ����
	afx_msg void OnUndo();			// �ظ�
	afx_msg void OnHideText();		// ��������ͼ������
	afx_msg void OnExchange();		// ��������ͼ���λ��

	///////////////////////////////////////////////////////////////
	// ����ͼ����Ϣ
	//

	afx_msg HRESULT OnNotifyIcon(WPARAM wParam , LPARAM lParam);
public:
	///////////////////////////////////////////////////////////////
	// �ؼ�����
	//

	// ϵͳ��ť
	CBitButtonNL m_btnClose;		// �ر�
	CBitButtonNL m_btnMin;			// ��С��

	// ���й��߲˵�	
	CBitButtonNL m_btnLine;			// ֱ�߹���	
	CBitButtonNL m_btnHollowRect;	// ���ľ��ι���
	CBitButtonNL m_btnFillRect;		// ʵ�ľ��ι���
	CBitButtonNL m_btnHeart;		// ���ι��� 
	CBitButtonNL m_btnOval;			// ��Բ�ι���
	CBitButtonNL m_btnBezier;		// Bezier���߹���


	// ���빤�߰�ť
	CBitButtonNL m_btnUp;			// ��
	CBitButtonNL m_btnDown;			// ��
	CBitButtonNL m_btnLeft;			// ��
	CBitButtonNL m_btnRight;		// ��	
	
	// ���ѡ��ť
	CBitButtonNL m_btnBig;			// ��
	CBitButtonNL m_btnMid;			// ��
	CBitButtonNL m_btnSmall;		// С
	CBitButtonNL m_btnAuto;			// �Զ�
	CBitButtonNL m_btnCustom;		// �Զ���

	// ������ť
	CBitButtonNL m_btnSave;			// ����
	CBitButtonNL m_btnLoad;			// ��ȡ
	CBitButtonNL m_btnUndo;			// ����
	CBitButtonNL m_btnRedo;			// �ظ�
	CBitButtonNL m_btnHideText;		// ��������ͼ������
	CBitButtonNL m_btnExchange;		// ��������ͼ���λ��
	
	CToolTipCtrl m_toolTip;			// Tip�ؼ�
	
	// �Զ�����༭��
	CEdit m_edtSpace;				
	int m_iEdtSpace;

private:
	CBitmap m_bmpBg;				// ����ͼƬ
	BOOL m_bHideText;				// �Ƿ���������ͼ������
	BOOL m_bShowTrayMenu;			// �Ƿ���ʾ�������˵�(ʹ�����й��ߵĹ����в���ʾ�������˵�)
	int *m_aIndices;				// ������������ͼ����±�����
	int m_n;						// ������������ͼ�����Ŀ
	int m_iSpaceType;				// ͼ��ļ������(��ΪSPACE_BIG, SPACE_MID, SPACE_SMALL, SPACE_AUTO, SPACE_CUSTOM)
	CDesktopIcon m_desktopIcon;		// ��ͼͼ����Ʊ���
private:

	// ȡͼ����ĺ���
	int getAlignSpace(void);		// ʹ�ö��빤��ʱͼ��ļ��(�������Ϊ�Զ�ʱ, ʹ���еȼ��)
	int getSpace(void);				// ȡ���ֵ(�������Ϊ�Զ�ʱ������)

	void getIconIndices(void);		// ȡ�ô�����������ͼ��(��ѡ���ͼ�������ͼ��)

	void align(int dir);			// ������ͼ�꿿�߶���, dirΪ���򣬿�ȡ UP, DOWN, LEFT, RIGHT

	BOOL load(const TCHAR *szFileName);	// ��������ͼ��λ�õ��ļ�
	BOOL save(const TCHAR *szFileName);	// ���ļ���������ͼ��λ��

	void showAllIconText(BOOL bShow);	// ��ʾ/��������ͼ������
	
	void setFace(void);				// ��ʼ��������ʾ
	void setupRegion(void);			// ���������򴰿�

	void addTrayIcon(void);			// �������ͼ��
	void removeTrayIcon(void);		// ɾ������ͼ��

	void hideSpaceEdit(void);		// �����Զ�����༭��
	
	// �趨���ѡ��ť��״̬(�����ѡ��ťģ��Ϊһ�鵥ѡ��), index - �������((��ΪSPACE_BIG, SPACE_MID, SPACE_SMALL, SPACE_AUTO, SPACE_CUSTOM))
	void setCheck(int index);		

	void displayDesktopDlg(int type);	// ��ʾ���й��ߵĻ�ͼ����(����CDesktopDlg)
public:
	void toggleDesktop(void);	// ����Win+D��ݼ���Ϣ, ��ʾ/��������

	// ʹ�����й�����������ͼ��, �����й��ߵĻ�ͼ����(����CDesktopDlg)����
	// ����:
	//		ptBegin - �����������ʼ��
	//		ptEnd	- �����������ֹ��
	//		type	- ���й�������(��ΪLINE, FILLRECT, HOLLOWRECT, OVAL, HEART)
	void toolSort(POINT ptBegin, POINT ptEnd, int type);	
	
	void bezierSort(LPPOINT aPoits);

	int getSelectedIconCount(void); // ȡ����ѡ���ͼ����, �����й��ߵĻ�ͼ����(����CDesktopDlg)����
};
