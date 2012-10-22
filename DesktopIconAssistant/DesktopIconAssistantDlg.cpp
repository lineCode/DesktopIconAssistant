// DesktopIconAssistantDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "global.h"
#include "DesktopIconAssistant.h"
#include "DesktopIconAssistantDlg.h"
#include "DesktopDlg.h"
#include "OS.h"

using namespace Utils;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);// DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CDesktopIconAssistantDlg �Ի���




CDesktopIconAssistantDlg::CDesktopIconAssistantDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDesktopIconAssistantDlg::IDD, pParent)
	, m_iEdtSpace(20)
	, m_aIndices(NULL)
	, m_n(0)
	, m_iSpaceType(0)
	, m_bShowTrayMenu(FALSE)
	, m_bHideText(FALSE)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_bmpBg.LoadBitmap(IDB_BG);
}

void CDesktopIconAssistantDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON_CLOSE, m_btnClose);
	DDX_Control(pDX, IDC_BUTTON_MIN, m_btnMin);
	DDX_Control(pDX, IDC_BUTTON_RIGHT, m_btnRight);
	DDX_Control(pDX, IDC_BUTTON_LEFT, m_btnLeft);
	DDX_Control(pDX, IDC_BUTTON_UP, m_btnUp);
	DDX_Control(pDX, IDC_BUTTON_DOWN, m_btnDown);
	DDX_Control(pDX, IDC_BUTTON_HEART, m_btnHeart);
	DDX_Control(pDX, IDC_BUTTON_OVAL, m_btnOval);
	DDX_Control(pDX, IDC_BUTTON_FILL_RECT, m_btnFillRect);
	DDX_Control(pDX, IDC_BUTTON_HOLLOW_RECT, m_btnHollowRect);
	DDX_Control(pDX, IDC_BUTTON_LINE, m_btnLine);
	DDX_Control(pDX, IDC_BUTTON_BIG, m_btnBig);
	DDX_Control(pDX, IDC_BUTTON_MID, m_btnMid);
	DDX_Control(pDX, IDC_BUTTON_SMALL, m_btnSmall);
	DDX_Control(pDX, IDC_BUTTON_AUTO, m_btnAuto);
	DDX_Control(pDX, IDC_BUTTON_CUSTOM, m_btnCustom);
	DDX_Control(pDX, IDC_EDIT_SPACE, m_edtSpace);
	DDX_Text(pDX, IDC_EDIT_SPACE, m_iEdtSpace);
	DDV_MinMaxInt(pDX, m_iEdtSpace, 1, 200);
	DDX_Control(pDX, IDC_BUTTON_UNDO, m_btnUndo);
	DDX_Control(pDX, IDC_BUTTON_REDO, m_btnRedo);
	DDX_Control(pDX, IDC_BUTTON_SAVE, m_btnSave);
	DDX_Control(pDX, IDC_BUTTON_LOAD, m_btnLoad);
	DDX_Control(pDX, IDC_BUTTON_EXCHANGE, m_btnExchange);
	DDX_Control(pDX, IDC_BUTTON_HIDE_TEXT, m_btnHideText);
	DDX_Control(pDX, IDC_BUTTON_BEZIER, m_btnBezier);
}

BEGIN_MESSAGE_MAP(CDesktopIconAssistantDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	ON_BN_CLICKED(IDC_BUTTON_CLOSE, &CDesktopIconAssistantDlg::OnBnClickedButtonClose)
	ON_BN_CLICKED(IDC_BUTTON_MIN, &CDesktopIconAssistantDlg::OnBnClickedButtonMin)
	ON_BN_CLICKED(IDC_BUTTON_LINE, &CDesktopIconAssistantDlg::OnBnClickedButtonLine)
	ON_BN_CLICKED(IDC_BUTTON_BIG, &CDesktopIconAssistantDlg::OnBnClickedButtonBig)
	ON_BN_CLICKED(IDC_BUTTON_MID, &CDesktopIconAssistantDlg::OnBnClickedButtonMid)
	ON_BN_CLICKED(IDC_BUTTON_SMALL, &CDesktopIconAssistantDlg::OnBnClickedButtonSmall)
	ON_BN_CLICKED(IDC_BUTTON_AUTO, &CDesktopIconAssistantDlg::OnBnClickedButtonAuto)
	ON_BN_CLICKED(IDC_BUTTON_CUSTOM, &CDesktopIconAssistantDlg::OnBnClickedButtonCustom)
	ON_BN_CLICKED(IDC_BUTTON_UP, &CDesktopIconAssistantDlg::OnBnClickedButtonUp)
	ON_BN_CLICKED(IDC_BUTTON_LEFT, &CDesktopIconAssistantDlg::OnBnClickedButtonLeft)
	ON_BN_CLICKED(IDC_BUTTON_RIGHT, &CDesktopIconAssistantDlg::OnBnClickedButtonRight)
	ON_BN_CLICKED(IDC_BUTTON_DOWN, &CDesktopIconAssistantDlg::OnBnClickedButtonDown)
	ON_BN_CLICKED(IDC_BUTTON_HEART, &CDesktopIconAssistantDlg::OnBnClickedButtonHeart)
	ON_BN_CLICKED(IDC_BUTTON_HOLLOW_RECT, &CDesktopIconAssistantDlg::OnBnClickedButtonHollowRect)
	ON_BN_CLICKED(IDC_BUTTON_OVAL, &CDesktopIconAssistantDlg::OnBnClickedButtonOval)
	ON_BN_CLICKED(IDC_BUTTON_FILL_RECT, &CDesktopIconAssistantDlg::OnBnClickedButtonFillRect)
	ON_BN_CLICKED(IDC_BUTTON_UNDO, &CDesktopIconAssistantDlg::OnBnClickedButtonUndo)
	ON_BN_CLICKED(IDC_BUTTON_REDO, &CDesktopIconAssistantDlg::OnBnClickedButtonRedo)
	ON_BN_CLICKED(IDC_BUTTON_SAVE, &CDesktopIconAssistantDlg::OnBnClickedButtonSave)
	ON_BN_CLICKED(IDC_BUTTON_LOAD, &CDesktopIconAssistantDlg::OnBnClickedButtonLoad)
	ON_COMMAND(ID_EXIT, &CDesktopIconAssistantDlg::OnExit)
	ON_COMMAND(ID_LOAD, &CDesktopIconAssistantDlg::OnLoad)
	ON_COMMAND(ID_SAVE, &CDesktopIconAssistantDlg::OnSave)
	ON_COMMAND(ID_REDO, &CDesktopIconAssistantDlg::OnRedo)
	ON_COMMAND(ID_UNDO, &CDesktopIconAssistantDlg::OnUndo)
	ON_COMMAND(ID_ALIGN_LEFT, &CDesktopIconAssistantDlg::OnAlignLeft)
	ON_COMMAND(ID_ALIGN_RIGHT, &CDesktopIconAssistantDlg::OnAlignRight)
	ON_COMMAND(ID_ALIGN_UP, &CDesktopIconAssistantDlg::OnAlignUp)
	ON_COMMAND(ID_ALIGN_DOWN, &CDesktopIconAssistantDlg::OnAlignDown)
	ON_COMMAND(ID_POPUP_SHOW, &CDesktopIconAssistantDlg::OnShow)
	ON_COMMAND(ID_SPACE_AUTO, &CDesktopIconAssistantDlg::OnSpaceAuto)
	ON_COMMAND(ID_SPACE_BIG, &CDesktopIconAssistantDlg::OnSpaceBig)
	ON_COMMAND(ID_SPACE_MID, &CDesktopIconAssistantDlg::OnSpaceMid)
	ON_COMMAND(ID_SPACE_SMALL, &CDesktopIconAssistantDlg::OnSpaceSmall)
	ON_COMMAND(ID_SPACE_CUSTOM, &CDesktopIconAssistantDlg::OnSpaceCustom)
	ON_COMMAND(ID_LINE, &CDesktopIconAssistantDlg::OnLine)
	ON_COMMAND(ID_FILLRECT, &CDesktopIconAssistantDlg::OnFillrect)
	ON_COMMAND(ID_HOLLOWRECT, &CDesktopIconAssistantDlg::OnHollowrect)
	ON_COMMAND(ID_OVAL, &CDesktopIconAssistantDlg::OnOval)
	ON_COMMAND(ID_HEART, &CDesktopIconAssistantDlg::OnHeart)
	ON_MESSAGE(WM_NOTIFYICON, OnNotifyIcon)
	ON_WM_LBUTTONDBLCLK()
	ON_COMMAND(ID_ABOUT, &CDesktopIconAssistantDlg::OnAbout)
	ON_BN_CLICKED(IDC_BUTTON_EXCHANGE, &CDesktopIconAssistantDlg::OnBnClickedButtonExchange)
	ON_COMMAND(ID_EXCHANGE, &CDesktopIconAssistantDlg::OnExchange)
	ON_BN_CLICKED(IDC_BUTTON_HIDE_TEXT, &CDesktopIconAssistantDlg::OnBnClickedButtonHideText)
	ON_WM_TIMER()
	ON_COMMAND(ID_HIDE_TEXT, &CDesktopIconAssistantDlg::OnHideText)
	ON_BN_CLICKED(IDC_BUTTON_BEZIER, &CDesktopIconAssistantDlg::OnBnClickedButtonBezier)
	ON_COMMAND(ID_BEZIER, &CDesktopIconAssistantDlg::OnBezier)
END_MESSAGE_MAP()


// CDesktopIconAssistantDlg ��Ϣ�������

BOOL CDesktopIconAssistantDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	EnableToolTips(TRUE);

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	// ��ʼ����ͼͼ����Ʊ���
	if (!m_desktopIcon.init() || m_desktopIcon.getIconCount() == 0)
	{
		CString sMsg, sError;
		sMsg.LoadString(IDS_FAIL_INIT);
		sError.LoadString(IDS_ERROR);
		MessageBox(sMsg, sError);
		EndDialog(0);
		return FALSE;
	}

	// ���ý���
	setFace();

	// �������ͼ��
	addTrayIcon();

	// �ı�������
	CString sTitle;
	sTitle.LoadString(IDS_APP_NAME);
	SetWindowText(sTitle);

	// ��ʼ������
	m_desktopIcon.saveUndo();	// ��ʼ��������������
	m_aIndices = new int[m_desktopIcon.getIconCount()];
	m_bShowTrayMenu = TRUE;

	// �򿪶�ʱ�����������Ƿ��ƶ�������ͼ����
	SetTimer(TIMER_ID_CHECK_HOT, 100, NULL);

	return TRUE;// ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CDesktopIconAssistantDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else if (SC_CLOSE == nID)
	{
		OnCancel();
	}
	else if (SC_MINIMIZE == nID)	// ��С����������
	{
		ShowWindow(SW_HIDE);
	}
	else if (SC_MAXIMIZE == nID)
	{
		return;
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//�����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//�⽫�ɿ���Զ���ɡ�

void CDesktopIconAssistantDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ�DC

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CPaintDC dc(this);
		CDC memDC;
		BITMAP bit;

		// ���Ʊ���ͼƬ
		m_bmpBg.GetBitmap(&bit);
		memDC.CreateCompatibleDC(&dc);
		memDC.SelectObject(&m_bmpBg);
		dc.BitBlt(0, 0, bit.bmWidth, bit.bmHeight, &memDC, 0, 0, SRCCOPY);

		CDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CDesktopIconAssistantDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CDesktopIconAssistantDlg::setupRegion(void)
{
	CClientDC dc(this);
	COLORREF cTrans = RGB(0, 0, 255);	// ָ��͸��ɫ(��ɫ)

	if (NULL == dc.m_hDC)
		return;

	// �õ�����ͼ�ĳߴ�
	BITMAP bit;
	m_bmpBg.GetBitmap(&bit);

	// ������ͼ������ʱDC
	CDC dcMem;
	dcMem.CreateCompatibleDC(&dc);
	dcMem.SelectObject(&m_bmpBg);

	// �ñ���ͼ���β����򴰿�
	CRgn wndRgn;
	CRgn rgnTemp;
	wndRgn.CreateRectRgn(0,0,0,0);
	for(int y=0; y<bit.bmHeight; y++)
	{
		for (int x=0; x < bit.bmWidth; x++)
		{
			//����͸��ɫ�ҵ���һ����͸��ɫ�ĵ�.
			while (x < bit.bmWidth && dcMem.GetPixel(x, y) == cTrans)
				x++;
			//��ס�����ʼ��
			int iLeftX = x;
			//Ѱ���¸�͸��ɫ�ĵ�
			while (x < bit.bmWidth && dcMem.GetPixel(x, y) != cTrans)
				x++;
			//����һ������������ص���Ϊ1���ص���ʱ��region��
			rgnTemp.CreateRectRgn(iLeftX, y, x, y+1);
			//�ϲ�����"region".
			wndRgn.CombineRgn(&wndRgn, &rgnTemp, RGN_OR);
			//ɾ����ʱ"region",�����´δ���ʱ�ͳ���
			rgnTemp.DeleteObject();
		} 
	}
	// ���ô��ڲ���������
	SetWindowRgn(wndRgn,TRUE);

	// ���ݲ���������Ĵ�С���ı䴰�ڳߴ�
	SetWindowPos(NULL, 0, 0, bit.bmWidth, bit.bmHeight, SWP_NOMOVE | SWP_NOZORDER);
}

void CDesktopIconAssistantDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// ����϶�����
	PostMessage(WM_NCLBUTTONDOWN, HTCAPTION, MAKELPARAM(point.x, point.y));

	// �����Զ�����༭��
	hideSpaceEdit();

	CDialog::OnLButtonDown(nFlags, point);
}

void CDesktopIconAssistantDlg::OnRButtonDown(UINT nFlags, CPoint point)
{
	// �����Զ�����༭��
	hideSpaceEdit();

	CDialog::OnRButtonDown(nFlags, point);
}

void CDesktopIconAssistantDlg::setFace(void)
{
	// ����Tip�ؼ�
	m_toolTip.Create(this);
	m_toolTip.Activate(TRUE);
	m_toolTip.SetTipTextColor(RGB(0, 0, 0));	// ��ʾ������ɫ���Ǳ���
	m_toolTip.SetDelayTime(150);				// ������ʾǰ���ӳ�ʱ�䣬�Ǳ���

	setupRegion();	// ���������򴰿�

	CString sTip;

	// ���ùرհ�ť
	m_btnClose.SetBitmaps(IDB_SYSTEM_NORMAL, IDB_SYSTEM_DOWN, IDB_SYSTEM_OVER, 0, RGB(0, 0, 255));
	m_btnClose.SizeToContent();
	m_btnClose.SetFontSize(7);
	m_btnClose.SetFontBold(TRUE);
	m_btnClose.SetForceColor(RGB(255, 255, 255), RGB(64, 0, 128), RGB(255, 255, 0));
	m_btnClose.SetDrawText();
	m_btnClose.SetWindowPos(NULL, 270, 18, 0, 0, SWP_NOSIZE | SWP_NOZORDER);

	// ����Tip
	sTip.LoadString(IDS_TIP_CLOSE);
	m_toolTip.AddTool(&m_btnClose, sTip);

	// ������С����ť
	m_btnMin.SetBitmaps(IDB_SYSTEM_NORMAL, IDB_SYSTEM_DOWN, IDB_SYSTEM_OVER, 0, RGB(0, 0, 255));
	m_btnMin.SetFontSize(8);
	m_btnMin.SetFontBold(TRUE);
	m_btnMin.SetForceColor(RGB(255, 255, 255), RGB(64, 0, 128), RGB(255, 255, 0));
	m_btnMin.SetDrawText();
	m_btnMin.SizeToContent();
	m_btnMin.SetWindowPos(NULL, 250, 18, 0, 0, SWP_NOSIZE | SWP_NOZORDER);

	// ����Tip
	sTip.LoadString(IDS_TIP_MIN);
	m_toolTip.AddTool(&m_btnMin, sTip);

	// ���ó�����ť
	m_btnUndo.SetBitmaps(IDB_SYSTEM_NORMAL, IDB_SYSTEM_DOWN, IDB_SYSTEM_OVER, 0, RGB(0, 0, 255));
	m_btnUndo.SizeToContent();
	m_btnUndo.SetFontSize(8);
	m_btnUndo.SetFontBold(TRUE);
	m_btnUndo.SetForceColor(RGB(255, 255, 255), RGB(64, 0, 128), RGB(255, 255, 0));
	m_btnUndo.SetDrawText();
	m_btnUndo.SetWindowPos(NULL, 200, 18, 0, 0, SWP_NOSIZE | SWP_NOZORDER);

	// ����Tip
	sTip.LoadString(IDS_TIP_UNDO);
	m_toolTip.AddTool(&m_btnUndo, sTip);

	// �����ظ���ť
	m_btnRedo.SetBitmaps(IDB_SYSTEM_NORMAL, IDB_SYSTEM_DOWN, IDB_SYSTEM_OVER, 0, RGB(0, 0, 255));
	m_btnRedo.SetFontSize(8);
	m_btnRedo.SetFontBold(TRUE);
	m_btnRedo.SetForceColor(RGB(255, 255, 255), RGB(64, 0, 128), RGB(255, 255, 0));
	m_btnRedo.SetDrawText();
	m_btnRedo.SizeToContent();
	m_btnRedo.SetWindowPos(NULL, 220, 18, 0, 0, SWP_NOSIZE | SWP_NOZORDER);

	// ����Tip
	sTip.LoadString(IDS_TIP_REDO);
	m_toolTip.AddTool(&m_btnRedo, sTip);

	// ���ý���ͼ��λ�ð�ť
	m_btnExchange.SetBitmaps(IDB_SYSTEM_NORMAL, IDB_SYSTEM_DOWN, IDB_SYSTEM_OVER, 0, RGB(0, 0, 255));
	m_btnExchange.SetFontSize(8);
	m_btnExchange.SetFontBold(TRUE);
	m_btnExchange.SetForceColor(RGB(255, 255, 255), RGB(64, 0, 128), RGB(255, 255, 0));
	m_btnExchange.SetDrawText();
	m_btnExchange.SizeToContent();
	m_btnExchange.SetWindowPos(NULL, 170, 18, 0, 0, SWP_NOSIZE | SWP_NOZORDER);

	// ����Tip
	sTip.LoadString(IDS_TIP_EXCHANGE);
	m_toolTip.AddTool(&m_btnExchange, sTip);

	// ������������ͼ�����ְ�ť
	if (OS::GetVersion() >= OS::VISTA)
	{
		m_btnHideText.ShowWindow(SW_HIDE);
	}
	else
	{
		m_btnHideText.SetBitmaps(IDB_SYSTEM_NORMAL, IDB_SYSTEM_DOWN, IDB_SYSTEM_OVER, 0, RGB(0, 0, 255));
		m_btnHideText.SetFontSize(8);
		m_btnHideText.SetFontBold(TRUE);
		m_btnHideText.SetForceColor(RGB(255, 255, 255), RGB(64, 0, 128), RGB(255, 255, 0));
		m_btnHideText.SetDrawText();
		m_btnHideText.SizeToContent();
		m_btnHideText.SetWindowPos(NULL, 150, 18, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
	}

	// ����Tip
	sTip.LoadString(IDS_TIP_HIDE);
	m_toolTip.AddTool(&m_btnHideText, sTip);

	// ��������밴ť
	m_btnLeft.SetBitmaps(IDB_LEFT_NORMAL, 0, IDB_LEFT_OVER, 0, RGB(0, 0, 255));
	m_btnLeft.SizeToContent();
	m_btnLeft.SetWindowPos(NULL, 175, 85, 0, 0, SWP_NOSIZE | SWP_NOZORDER);

	// ����Tip
	sTip.LoadString(IDS_TIP_LEFT);
	m_toolTip.AddTool(&m_btnLeft, sTip);

	// ��������밴ť
	m_btnRight.SetBitmaps(IDB_RIGHT_NORMAL, 0, IDB_RIGHT_OVER, 0, RGB(0, 0, 255));
	m_btnRight.SizeToContent();
	m_btnRight.SetWindowPos(NULL, 245, 85, 0, 0, SWP_NOSIZE | SWP_NOZORDER);

	// ����Tip
	sTip.LoadString(IDS_TIP_RIGHT);
	m_toolTip.AddTool(&m_btnRight, sTip);


	// �����϶��밴ť
	m_btnUp.SetBitmaps(IDB_UP_NORMAL, 0, IDB_UP_OVER, 0, RGB(0, 0, 255));
	m_btnUp.SizeToContent();
	m_btnUp.SetWindowPos(NULL, 215, 70, 0, 0, SWP_NOSIZE | SWP_NOZORDER);

	// ����Tip
	sTip.LoadString(IDS_TIP_UP);
	m_toolTip.AddTool(&m_btnUp, sTip);

	// �����¶��밴ť
	m_btnDown.SetBitmaps(IDB_DOWN_NORMAL, 0, IDB_DOWN_OVER, 0, RGB(0, 0, 255));
	m_btnDown.SizeToContent();
	m_btnDown.SetWindowPos(NULL, 215, 105, 0, 0, SWP_NOSIZE | SWP_NOZORDER);

	// ����Tip
	sTip.LoadString(IDS_TIP_DOWN);
	m_toolTip.AddTool(&m_btnDown, sTip);

	// �������ι��߰�ť
	m_btnHeart.SetBitmaps(IDB_HEART_NORMAL, 0, IDB_HEART_OVER, 0, RGB(0, 0, 255));
	m_btnHeart.SizeToContent();
	m_btnHeart.SetWindowPos(NULL, 153, 178, 0, 0, SWP_NOSIZE | SWP_NOZORDER);

	// ����Tip
	sTip.LoadString(IDS_TIP_HEART);
	m_toolTip.AddTool(&m_btnHeart, sTip);

	// ������Բ�ι��߰�ť
	m_btnOval.SetBitmaps(IDB_OVAL_NORMAL, 0, IDB_OVAL_OVER, 0, RGB(0, 0, 255));
	m_btnOval.SizeToContent();
	m_btnOval.SetWindowPos(NULL, 185, 207, 0, 0, SWP_NOSIZE | SWP_NOZORDER);

	// ����Tip
	sTip.LoadString(IDS_TIP_OVAL);
	m_toolTip.AddTool(&m_btnOval, sTip);

	// ���þ��ι��߰�ť
	m_btnFillRect.SetBitmaps(IDB_FILLRECT_NORMAL, 0, IDB_FILLRECT_OVER, 0, RGB(0, 0, 255));
	m_btnFillRect.SizeToContent();
	m_btnFillRect.SetWindowPos(NULL, 152, 245, 0, 0, SWP_NOSIZE | SWP_NOZORDER);

	// ����Tip
	sTip.LoadString(IDS_TIP_FILLRECT);
	m_toolTip.AddTool(&m_btnFillRect, sTip);

	// ���ÿ��ľ��ι��߰�ť
	m_btnHollowRect.SetBitmaps(IDB_HOLLOWRECT_NORMAL, 0, IDB_HOLLOWRECT_OVER, 0, RGB(0, 0, 255));
	m_btnHollowRect.SizeToContent();
	m_btnHollowRect.SetWindowPos(NULL, 118, 245, 0, 0, SWP_NOSIZE | SWP_NOZORDER);

	// ����Tip
	sTip.LoadString(IDS_TIP_HOLLOWRECT);
	m_toolTip.AddTool(&m_btnHollowRect, sTip);

	// ����Bezier���߹��߰�ť
	m_btnBezier.SetBitmaps(IDB_BEZIER_NORMAL, 0, IDB_BEZIER_OVER, 0, RGB(0, 0, 255));
	m_btnBezier.SizeToContent();
	m_btnBezier.SetWindowPos(NULL, 133, 237, 0, 0, SWP_NOSIZE | SWP_NOZORDER);

	// ����Tip
	sTip.LoadString(IDS_TIP_BEZIER);
	m_toolTip.AddTool(&m_btnBezier, sTip);

	// ����ֱ�߹��߰�ť
	m_btnLine.SetBitmaps(IDB_LINE_NORMAL, 0, IDB_LINE_OVER, 0, RGB(0, 0, 255));
	m_btnLine.SizeToContent();
	m_btnLine.SetWindowPos(NULL, 182, 223, 0, 0, SWP_NOSIZE | SWP_NOZORDER);

	// ����Tip
	sTip.LoadString(IDS_TIP_LINE);
	m_toolTip.AddTool(&m_btnLine, sTip);
	// ���ô��ఴť
	m_btnBig.SetBitmaps(IDB_BIG_NORMAL, IDB_BIG_DOWN, IDB_BIG_OVER, 0, RGB(0, 0, 255));
	m_btnBig.SizeToContent();
	m_btnBig.SetWindowPos(NULL, 212, 258, 0, 0, SWP_NOSIZE | SWP_NOZORDER);

	// ����Tip
	sTip.LoadString(IDS_TIP_BIG);
	m_toolTip.AddTool(&m_btnBig, sTip);

	// �����еȼ�ఴť
	m_btnMid.SetBitmaps(IDB_MID_NORMAL, IDB_MID_DOWN, IDB_MID_OVER, 0, RGB(0, 0, 255));
	m_btnMid.SizeToContent();
	m_btnMid.SetWindowPos(NULL, 223, 275, 0, 0, SWP_NOSIZE | SWP_NOZORDER);

	// ����Tip
	sTip.LoadString(IDS_TIP_MID);
	m_toolTip.AddTool(&m_btnMid, sTip);

	// ����С��ఴť
	m_btnSmall.SetBitmaps(IDB_SMALL_NORMAL, IDB_SMALL_DOWN, IDB_SMALL_OVER, 0, RGB(0, 0, 255));
	m_btnSmall.SizeToContent();
	m_btnSmall.SetWindowPos(NULL, 230, 285, 0, 0, SWP_NOSIZE | SWP_NOZORDER);

	// ����Tip
	sTip.LoadString(IDS_TIP_SMALL);
	m_toolTip.AddTool(&m_btnSmall, sTip);

	// �����Զ���ఴť
	m_btnAuto.SetBitmaps(IDB_AUTO_NORMAL, IDB_AUTO_DOWN, IDB_AUTO_OVER, 0, RGB(0, 0, 255));
	m_btnAuto.SizeToContent();
	m_btnAuto.SetWindowPos(NULL, 245, 255, 0, 0, SWP_NOSIZE | SWP_NOZORDER);

	// ����Tip
	sTip.LoadString(IDS_TIP_AUTO);
	m_toolTip.AddTool(&m_btnAuto, sTip);

	// �����Զ����ఴť
	m_btnCustom.SetBitmaps(IDB_CUSTOM_NORMAL, IDB_CUSTOM_DOWN, IDB_CUSTOM_OVER, 0, RGB(0, 0, 255));
	m_btnCustom.SizeToContent();
	m_btnCustom.SetWindowPos(NULL, 247, 275, 0, 0, SWP_NOSIZE | SWP_NOZORDER);

	// ����Tip
	sTip.LoadString(IDS_TIP_CUSTOM);
	m_toolTip.AddTool(&m_btnCustom, sTip);

	// ���ñ��水ť
	m_btnSave.SetBitmaps(IDB_SAVE_NORMAL, IDB_SAVE_NORMAL, IDB_SAVE_OVER, 0, RGB(0, 0, 255));
	m_btnSave.SizeToContent();
	m_btnSave.SetWindowPos(NULL, 55, 322, 0, 0, SWP_NOSIZE | SWP_NOZORDER);

	// ����Tip
	sTip.LoadString(IDS_TIP_SAVE);
	m_toolTip.AddTool(&m_btnSave, sTip);

	// ���ü�ȡ��ť
	m_btnLoad.SetBitmaps(IDB_LOAD_NORMAL, IDB_LOAD_NORMAL, IDB_LOAD_OVER, 0, RGB(0, 0, 255));
	m_btnLoad.SizeToContent();
	m_btnLoad.SetWindowPos(NULL, 55, 362, 0, 0, SWP_NOSIZE | SWP_NOZORDER);

	// ����Tip
	sTip.LoadString(IDS_TIP_LOAD);	
	m_toolTip.AddTool(&m_btnLoad, sTip);

	// �����Զ�����༭��
	CButton *pEdtSpace =(CButton *)GetDlgItem(IDC_EDIT_SPACE);
	pEdtSpace->SetWindowPos(NULL, 265, 247, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
	m_iEdtSpace = 20;
	m_edtSpace.ShowWindow(FALSE);

	// ���ü�ఴť״̬
	setCheck(SPACE_AUTO);

	UpdateData(FALSE);
}

void CDesktopIconAssistantDlg::OnBnClickedButtonClose()
{
	SendMessage(WM_CLOSE);
}

void CDesktopIconAssistantDlg::OnBnClickedButtonMin()
{
	ShowWindow(SW_HIDE);
}

void CDesktopIconAssistantDlg::OnBnClickedButtonLine()
{
	displayDesktopDlg(LINE);
}

void CDesktopIconAssistantDlg::OnBnClickedButtonBig()
{
	setCheck(SPACE_BIG);
}

void CDesktopIconAssistantDlg::OnBnClickedButtonMid()
{
	setCheck(SPACE_MID);
}

void CDesktopIconAssistantDlg::OnBnClickedButtonSmall()
{
	setCheck(SPACE_SMALL);
}

void CDesktopIconAssistantDlg::OnBnClickedButtonAuto()
{
	setCheck(SPACE_AUTO);
}

void CDesktopIconAssistantDlg::OnBnClickedButtonCustom()
{
	setCheck(SPACE_CUSTOM);
}


void CDesktopIconAssistantDlg::setCheck(int index)
{
	CBitButtonNL *aBtn[5] = {&m_btnBig, &m_btnMid, &m_btnSmall, &m_btnAuto, &m_btnCustom};

	// ���ѡ��״̬
	for (int i=0; i<5; i++)
	{
		aBtn[i]->setChecked(FALSE);
	}

	aBtn[index]->setChecked(TRUE);	// ��Ϊѡ��״̬

	// ���ѡ��״̬Ϊ�Զ��壬��ʾ�Զ�����༭��
	if (index == SPACE_CUSTOM)
	{
		m_edtSpace.ShowWindow(TRUE);
	}
	else
	{
		hideSpaceEdit();
	}
	m_iSpaceType = index;
}

void CDesktopIconAssistantDlg::hideSpaceEdit(void)
{
	if (UpdateData())
		m_edtSpace.ShowWindow(FALSE);
}

void CDesktopIconAssistantDlg::toggleDesktop(void)
{
	// ģ��Win + D ��ݼ�
	keybd_event(VK_LWIN,0,0,0);
	keybd_event('D',0,0,0);               
	keybd_event(VK_LWIN,0,KEYEVENTF_KEYUP,0);               
	keybd_event('D',0,KEYEVENTF_KEYUP,0);       
	Sleep(200);
}

int CDesktopIconAssistantDlg::getAlignSpace(void)
{
	int space = getSpace();
	// ����������Ϊ�Զ���ȡ�еȼ��
	if (0 == space)
	{
		space =  m_desktopIcon.getIconWidth() / 2;
	}
	return space;
}

int CDesktopIconAssistantDlg::getSpace(void)
{
	UpdateData();
	int width = m_desktopIcon.getIconWidth();
	int iSpace = 0;
	switch (m_iSpaceType) 
	{
	case SPACE_SMALL:	// С���
		iSpace = width / 4;
		break;
	case SPACE_MID:		// �еȼ��
		iSpace = width / 2;
		break;	
	case SPACE_BIG:		// ����
		iSpace = width;
		break;
	case SPACE_AUTO:	// �Զ����
		iSpace = 0;
		break;
	case SPACE_CUSTOM:	// �Զ�����
		if (m_iEdtSpace > 0 && m_iEdtSpace < 200)
		{
			iSpace = m_iEdtSpace;
		}
		else
		{
			iSpace = 0;
		}
		break;
	default:
		iSpace = 0;
	}
	return iSpace;
}

void CDesktopIconAssistantDlg::toolSort(POINT ptBegin, POINT ptEnd, int type)
{
	UpdateData();

	getIconIndices();	// �õ�������������ͼ��

	int space = getSpace();

	// ��������������ͼ��
	switch (type)
	{
	case LINE:
		m_desktopIcon.line(m_aIndices, m_n, space, ptBegin, ptEnd);
		break;
	case OVAL:
		m_desktopIcon.oval(m_aIndices, m_n, space, ptBegin, ptEnd);
		break;
	case FILLRECT:
		m_desktopIcon.fillRectangle(m_aIndices, m_n, space, ptBegin, ptEnd);
		break;
	case HOLLOWRECT:
		m_desktopIcon.hollowRectangle(m_aIndices, m_n, space, ptBegin, ptEnd);
		break;
	case HEART:
		m_desktopIcon.heart(m_aIndices, m_n, space, ptBegin, ptEnd);
	default:
		break;
	}
}

void CDesktopIconAssistantDlg::bezierSort(LPPOINT aPoints)
{
	UpdateData();

	getIconIndices();	// �õ�������������ͼ��

	int space = getSpace();

	m_desktopIcon.bezier(m_aIndices, m_n, space, aPoints);

}


void CDesktopIconAssistantDlg::getIconIndices(void)
{
		m_n = m_desktopIcon.getSelectedIconCount(); // ѡ�е�ͼ������

		if (m_n > 0)
		{
			// �õ�ѡ�е�ͼ��
			m_desktopIcon.getSelectedIconIndices(m_aIndices);
		}
		else
		{
			// û��ѡ�е�ͼ�꣬�͵õ����е�ͼ��
			m_n = m_desktopIcon.getIconCount();
			for (int i=0; i<m_n; i++)
			{
				m_aIndices[i] = i;
			}
		}
}

void CDesktopIconAssistantDlg::align(int dir)
{
	getIconIndices();
	m_desktopIcon.align(m_aIndices, m_n, dir, getSpace());
	m_desktopIcon.saveUndo();
}

void CDesktopIconAssistantDlg::OnOK()
{
}

void CDesktopIconAssistantDlg::OnCancel()
{
	if (m_aIndices)
	{
		delete[] m_aIndices;
		m_aIndices = NULL;
	}

	KillTimer(TIMER_ID_CHECK_HOT);

	removeTrayIcon();

	if (OS::GetVersion() < OS::VISTA)
	{
		CString sMsg, sTitle;
		sTitle.LoadString(IDS_ALERT);

		sMsg.LoadString(IDS_FIX_ICON);
		if(IDYES == MessageBox(sMsg, sTitle, MB_YESNO))
		{
			ShowWindow(SW_HIDE);
			toggleDesktop();

			// ģ������ƶ�����ͼ��	
			POINT pos;
			m_desktopIcon.getIconPosition(0, &pos);
			int dx = (pos.x > 200) ? -5 : 5;
			m_desktopIcon.dragIcon(0, 0, 0);
			for (int i=1; i<=4; i++)
				m_desktopIcon.dragIcon(0, i * dx, 0);
			m_desktopIcon.moveIcon(0, pos.x, pos.y);

			toggleDesktop();
			ShowWindow(SW_SHOWNORMAL);
			sMsg.LoadString(IDS_ICON_FIXED);
			MessageBox(sMsg, sTitle, MB_OK);

		}
	}

	CDialog::OnCancel();
}

void CDesktopIconAssistantDlg::OnBnClickedButtonUp()
{
	align(UP);
}

void CDesktopIconAssistantDlg::OnBnClickedButtonLeft()
{
	align(LEFT);
}

void CDesktopIconAssistantDlg::OnBnClickedButtonRight()
{
	align(RIGHT);
}

void CDesktopIconAssistantDlg::OnBnClickedButtonDown()
{
	align(DOWN);
}

void CDesktopIconAssistantDlg::OnBnClickedButtonHeart()
{
	displayDesktopDlg(HEART);
}

void CDesktopIconAssistantDlg::OnBnClickedButtonHollowRect()
{
	displayDesktopDlg(HOLLOWRECT);
}

void CDesktopIconAssistantDlg::OnBnClickedButtonOval()
{
	displayDesktopDlg(OVAL);
}

void CDesktopIconAssistantDlg::OnBnClickedButtonFillRect()
{
	displayDesktopDlg(FILLRECT);
}

void CDesktopIconAssistantDlg::OnBnClickedButtonBezier()
{
	displayDesktopDlg(BEZIER);
}


void CDesktopIconAssistantDlg::OnBnClickedButtonUndo()
{
	if (!m_desktopIcon.undo())
	{
		CString sMsg, sTitle;
		sMsg.LoadString(IDS_CANNOT_UNDO);
		sTitle.LoadString(IDS_ALERT);
		MessageBox(sMsg, sTitle);
	}
}

void CDesktopIconAssistantDlg::OnBnClickedButtonRedo()
{
	if (!m_desktopIcon.redo())
	{
		CString sMsg, sTitle;
		sMsg.LoadString(IDS_CANNOT_REDO);
		sTitle.LoadString(IDS_ALERT);
		MessageBox(sMsg, sTitle);
	}
}

void CDesktopIconAssistantDlg::displayDesktopDlg(int type)
{
	m_bShowTrayMenu = FALSE;
	CDesktopDlg dlgDesktop;
	dlgDesktop.setToolType(type);
	BOOL bIsShown = IsWindowVisible();
	
	if (bIsShown)
		ShowWindow(SW_HIDE);
	
	if (IDOK == dlgDesktop.DoModal()) 
	{
		m_desktopIcon.saveUndo();
	}
	else
	{
		m_desktopIcon.saveUndo();
		m_desktopIcon.undo();
	}
	
	if (bIsShown)
		ShowWindow(SW_SHOWNORMAL);
	m_bShowTrayMenu = TRUE;
}

int CDesktopIconAssistantDlg::getSelectedIconCount(void)
{
	return m_desktopIcon.getSelectedIconCount();
}

BOOL CDesktopIconAssistantDlg::PreTranslateMessage(MSG* pMsg)
{
	m_toolTip.RelayEvent(pMsg);
	return CDialog::PreTranslateMessage(pMsg);
}

BOOL CDesktopIconAssistantDlg::load(const TCHAR* szFileName)
{
	CFile file;
	int n = 0;			// number of icons to be moved
	int index = 0;
	POINT pos = {0};	// the icon's position
	TCHAR szHeader[sizeof(STR_FILE_HEADER)/sizeof(TCHAR)];

	if (!file.Open(szFileName, CFile::modeRead))
	{
		return FALSE;
	}

	// Check the header
	if (file.Read(&szHeader, sizeof(STR_FILE_HEADER)) != sizeof(STR_FILE_HEADER))
	{
		file.Close();
		return FALSE;
	}
	if (_tcscmp(szHeader, STR_FILE_HEADER) != 0)
	{
		file.Close();
		return FALSE;
	}

	// Get the total number of icons
	if (file.Read(&n, sizeof(int)) != sizeof(int))
	{
		file.Close();
		return FALSE;
	}

	// The number of icons to be sorted cannot exceed the number of icons available.
	n = min(m_desktopIcon.getIconCount(), n);

	// Move each icon
	for (int i=0; i<n; i++)
	{
		// Get the index
		if (file.Read(&index, sizeof(int)) != sizeof(int))
		{
			file.Close();
			return FALSE;
		}
		// Get the position
		if (file.Read(&pos, sizeof(POINT)) != sizeof(POINT))
		{
			file.Close();
			return FALSE;
		}
		// Move it
		m_desktopIcon.moveIcon(index, pos.x, pos.y);
	}

	file.Close();

	m_desktopIcon.saveUndo();

	return TRUE;
}

BOOL CDesktopIconAssistantDlg::save(const TCHAR* szFileName)
{
	CFile file;
	int n = m_desktopIcon.getIconCount();			// number of icons
	POINT pos = {0};	// the icon's position

	if (!file.Open(szFileName, CFile::modeWrite | CFile::modeCreate))
	{
		return FALSE;
	}

	// Write the header
	file.Write(STR_FILE_HEADER, sizeof(STR_FILE_HEADER));

	// Write the total number of icons
	file.Write(&n, sizeof(int));

	// Write each icon's index and position
	for (int i=0; i<n; i++)
	{
		// Write the index
		file.Write(&i, sizeof(int));

		// Write the position
		m_desktopIcon.getIconPosition(i, &pos);
		file.Write(&pos, sizeof(POINT));
	}

	file.Close();

	return TRUE;
}

void CDesktopIconAssistantDlg::OnBnClickedButtonSave()
{
	CFileDialog dlgFile(FALSE);
	TCHAR szFileName[MAX_PATH + 1];
	dlgFile.GetOFN().lpstrFilter = _T("*.pos\0*.pos\0");;
	GetCurrentDirectory(MAX_PATH + 1, szFileName);
	if (szFileName[_tcslen(szFileName)-1] != _T('\\'))
		_tcscat_s(szFileName, MAX_PATH + 1, _T("\\"));
	_tcscat_s(szFileName, MAX_PATH + 1, _T("love.pos"));
	dlgFile.GetOFN().lpstrFile = szFileName;
	dlgFile.GetOFN().nMaxFile =MAX_PATH + 1;

	if (dlgFile.DoModal() == IDOK)
	{
		if (save(dlgFile.GetPathName()))
		{
			CString sMsg, sTitle;
			sMsg.LoadString(IDS_SAVED);
			sTitle.LoadStringW(IDS_ALERT);
			MessageBox(sMsg, sTitle);
		}
	}
}

void CDesktopIconAssistantDlg::OnBnClickedButtonLoad()
{
	CFileDialog dlgFile(TRUE, _T("pos"));
	TCHAR szInitDir[MAX_PATH + 1];
	dlgFile.GetOFN().lpstrFilter = _T("*.pos\0*.pos\0");;
	GetCurrentDirectory(MAX_PATH + 1, szInitDir);
	dlgFile.GetOFN().lpstrInitialDir = szInitDir;
	dlgFile.GetOFN().nMaxFile =MAX_PATH + 1;
	
	if (dlgFile.DoModal() == IDOK)
	{
		if (load(dlgFile.GetPathName()))
		{
			CString sMsg, sTitle;
			sMsg.LoadString(IDS_LOADED);
			sTitle.LoadStringW(IDS_ALERT);
			MessageBox(sMsg, sTitle);
		}		
	}
}

void CDesktopIconAssistantDlg::OnExit()
{
	OnCancel();
}

void CDesktopIconAssistantDlg::OnLoad()
{
	OnBnClickedButtonLoad();
}

void CDesktopIconAssistantDlg::OnSave()
{
	OnBnClickedButtonSave();
}

void CDesktopIconAssistantDlg::OnRedo()
{
	OnBnClickedButtonRedo();
}

void CDesktopIconAssistantDlg::OnUndo()
{
	OnBnClickedButtonUndo();
}

void CDesktopIconAssistantDlg::OnAlignLeft()
{
	OnBnClickedButtonLeft();
}


void CDesktopIconAssistantDlg::OnAlignRight()
{
	OnBnClickedButtonRight();
}

void CDesktopIconAssistantDlg::OnAlignUp()
{
	OnBnClickedButtonUp();
}

void CDesktopIconAssistantDlg::OnAlignDown()
{
	OnBnClickedButtonDown();
}

void CDesktopIconAssistantDlg::OnShow()
{
	ShowWindow(SW_SHOWNORMAL);
}

void CDesktopIconAssistantDlg::OnSpaceAuto()
{
	OnBnClickedButtonAuto();
}

void CDesktopIconAssistantDlg::OnSpaceBig()
{
	OnBnClickedButtonBig();
}

void CDesktopIconAssistantDlg::OnSpaceMid()
{
	OnBnClickedButtonMid();
}

void CDesktopIconAssistantDlg::OnSpaceSmall()
{
	OnBnClickedButtonSmall();
}

void CDesktopIconAssistantDlg::OnLine()
{
	OnBnClickedButtonLine();
}

void CDesktopIconAssistantDlg::OnFillrect()
{
	OnBnClickedButtonHollowRect();
}

void CDesktopIconAssistantDlg::OnHollowrect()
{
	OnBnClickedButtonHollowRect();
}

void CDesktopIconAssistantDlg::OnOval()
{
	OnBnClickedButtonOval();
}

void CDesktopIconAssistantDlg::OnHeart()
{
	OnBnClickedButtonHeart();
}

void CDesktopIconAssistantDlg::addTrayIcon(void)
{
	CString szTip;
	NOTIFYICONDATA nid = {0};
	nid.cbSize	= sizeof(NOTIFYICONDATA);
	nid.hWnd	= m_hWnd;
	nid.uID	= IDR_MAINFRAME;
	nid.uFlags	= NIF_ICON|NIF_MESSAGE|NIF_TIP;
	nid.uCallbackMessage= WM_NOTIFYICON;
	nid.hIcon	= m_hIcon;
	szTip.LoadStringW(IDS_APP_NAME);
	_tcscpy_s(nid.szTip, szTip);
	Shell_NotifyIcon(NIM_ADD, &nid);
}

void CDesktopIconAssistantDlg::removeTrayIcon(void)
{
	// ɾ������
	NOTIFYICONDATA nid;
	nid.cbSize	= sizeof (NOTIFYICONDATA);
	nid.hWnd	= m_hWnd;
	nid.uID		= IDR_MAINFRAME;
	Shell_NotifyIcon(NIM_DELETE, &nid);
}

HRESULT CDesktopIconAssistantDlg::OnNotifyIcon(WPARAM wParam , LPARAM lParam)
{
	if (IDR_MAINFRAME != wParam)
		return E_NOTIMPL;

	if (!m_bShowTrayMenu)
		return E_NOTIMPL;

	// ���������ʾ/����ͼ������
	if (WM_LBUTTONDOWN == lParam)
	{
		OnBnClickedButtonHideText();
	}

	// �Ҽ�������ʾ�˵�
	if(WM_RBUTTONDOWN == lParam)
	{
		SetForegroundWindow(); 
		CMenu* menu = new CMenu();
		menu->LoadMenu(IDR_MENU_POPUP);// �˵���Ҫ��ǰ���õ�
		CMenu* pPopup=menu->GetSubMenu(0);
		::SetMenuDefaultItem(pPopup->m_hMenu,0,TRUE); //����Ĭ����

		switch (m_iSpaceType)
		{
		case SPACE_BIG:
			menu->CheckMenuItem(ID_SPACE_BIG, MF_CHECKED); 
			break;
		case SPACE_MID:
			menu->CheckMenuItem(ID_SPACE_MID, MF_CHECKED);
			break;
		case SPACE_SMALL:
			menu->CheckMenuItem(ID_SPACE_SMALL, MF_CHECKED);
			break;
		case SPACE_AUTO:
			menu->CheckMenuItem(ID_SPACE_AUTO, MF_CHECKED);
			break;
		case SPACE_CUSTOM:
			menu->CheckMenuItem(ID_SPACE_CUSTOM, MF_CHECKED);
			break;
		default:
			break;
		}

		if (m_bHideText)
			menu->CheckMenuItem(ID_HIDE_TEXT, MF_CHECKED);

		CPoint Point;
		GetCursorPos(&Point);
		pPopup->TrackPopupMenu(TPM_LEFTALIGN,Point.x,Point.y,AfxGetMainWnd(),NULL);

		menu->DestroyMenu();
		delete menu;
	}

	return E_NOTIMPL;
}
void CDesktopIconAssistantDlg::OnSpaceCustom()
{
	OnBnClickedButtonCustom();
}

void CDesktopIconAssistantDlg::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	ShowWindow(SW_HIDE);
	CDialog::OnLButtonDblClk(nFlags, point);
}

void CDesktopIconAssistantDlg::OnAbout()
{
	CAboutDlg dlgAbout;
	dlgAbout.DoModal();
}

void CDesktopIconAssistantDlg::OnBnClickedButtonExchange()
{
	if (m_desktopIcon.getSelectedIconCount() != 2)
	{
		CString sMsg, sTitle;
		sMsg.LoadString(IDS_SELECT_TWO_ICONS);
		sTitle.LoadString(IDS_ALERT);
		MessageBox(sMsg, sTitle);
		return;
	}

	POINT pos[2];

	getIconIndices();

	for (int i=0; i<2; i++)
	{
		m_desktopIcon.getIconPosition(m_aIndices[i], &pos[i]);
	}

	m_desktopIcon.moveIcon(m_aIndices[0], pos[1].x, pos[1].y);
	m_desktopIcon.moveIcon(m_aIndices[1], pos[0].x, pos[0].y);
	m_desktopIcon.saveUndo();
}

void CDesktopIconAssistantDlg::OnExchange()
{
	OnBnClickedButtonExchange();
}

void CDesktopIconAssistantDlg::OnBnClickedButtonHideText()
{
	CString sTip;
	if (m_bHideText)
	{
		// Show the icon text
		showAllIconText(TRUE);
		m_btnHideText.setChecked(FALSE);
		sTip.LoadString(IDS_TIP_HIDE);
		m_toolTip.AddTool(&m_btnHideText, sTip);
	}
	else
	{
		// Hide the icon text
		showAllIconText(FALSE);
		m_btnHideText.setChecked(TRUE);
		sTip.LoadString(IDS_TIP_SHOW);
		m_toolTip.AddTool(&m_btnHideText, sTip);
	}
	m_bHideText = !m_bHideText;
}

void CDesktopIconAssistantDlg::showAllIconText(BOOL bShow)
{
	int n = m_desktopIcon.getIconCount();
	int i;
	if (bShow)
	{
		for (i=0; i<n; i++)
		{
			m_desktopIcon.restoreIconText(i);
		}
	}
	else
	{
		for (i=0; i<n; i++)
		{
			m_desktopIcon.setIconText(i, _T(""));
		}
	}
}

void CDesktopIconAssistantDlg::OnTimer(UINT_PTR nIDEvent)
{
	static int preHot = -1;
	// TODO: Add your message handler code here and/or call default
	if (nIDEvent == TIMER_ID_CHECK_HOT)
	{
		int hot = m_desktopIcon.getHotIcon();
		// Show the icon text of the hot icon
		if (m_bHideText)
		{	
			int n = m_desktopIcon.getIconCount();
			for (int i=0; i<n; i++)
			{
				if (i != hot)
					m_desktopIcon.setIconText(i, _T(""));
				else
					m_desktopIcon.restoreIconText(hot);
			}
		}

		if (hot != -1)
		{
			// To swing
			if (preHot != hot)
			{
				if (hot >= 0 && hot < m_desktopIcon.getIconCount())
					m_desktopIcon.swing(hot);
			}
		}

		preHot = hot;
	}

	CDialog::OnTimer(nIDEvent);
}

void CDesktopIconAssistantDlg::OnHideText()
{
	OnBnClickedButtonHideText();
}

void CDesktopIconAssistantDlg::OnBezier()
{
	OnBnClickedButtonBezier();
}
