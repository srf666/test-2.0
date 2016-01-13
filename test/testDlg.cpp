
// testDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "test.h"
#include "testDlg.h"
#include "afxdialogex.h"
#include "math.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CtestDlg 对话框




CtestDlg::CtestDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CtestDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	c=180;
	c1=174;
	c2=180;
	c3=174;
	c4=180;
	c5=174;
}

void CtestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CtestDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CtestDlg 消息处理程序

BOOL CtestDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);
	SetTimer(1,10,NULL);
	SetTimer(2,600,NULL);
	SetTimer(3,3600,NULL);
		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CtestDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CtestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CtestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CtestDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	int x,x1,y,y1,ox=200,oy=200;
	int x2,y2,x3,y3;
	int x4,y4,x5,y5;
if(nIDEvent==1)
  {
	int r=100;
	CDC *pDC;
	CPen newpen,*oldpen;
	newpen.CreatePen(PS_SOLID,1,RGB(240,240,240));
	pDC=GetDC();
	oldpen=pDC->SelectObject(&newpen);
	x=ox+r*sin(c*3.1415926/180);
	y=ox+r*cos(c*3.1415926/180);
	pDC->MoveTo(ox,oy);
	pDC->LineTo(x,y);
	c=c-6;
	if(c<=-180)
	{
		c==180;
	}
	CDC *pDC1;
	CPen newpen1,*oldpen1;
	newpen1.CreatePen(PS_SOLID,1,RGB(0,0,0));
	pDC1=GetDC();
	oldpen1=pDC1->SelectObject(&newpen1);
	x1=ox+r*sin(c1*3.1415926/180);
	y1=ox+r*cos(c1*3.1415926/180);
	pDC1->MoveTo(ox,oy);
	pDC1->LineTo(x1,y1);
	c1=c1-6;
	if(c1<=-174)
	{
		c1==174;
	}
	//CDialogEx::OnTimer(nIDEvent);
  }
if(nIDEvent==2)
  {
	int r=70;
	CDC *pDC2;
	CPen newpen2,*oldpen2;
	newpen2.CreatePen(PS_SOLID,3,RGB(240,240,240));
	pDC2=GetDC();
	oldpen2=pDC2->SelectObject(&newpen2);
	x2=ox+r*sin(c2*3.1415926/180);
	y2=ox+r*cos(c2*3.1415926/180);
	pDC2->MoveTo(ox,oy);
	pDC2->LineTo(x2,y2);
	c2=c2-6;
	if(c2<=-180)
	{
		c2<=180;
	}
	CDC *pDC3;
	CPen newpen3,*oldpen3;
	newpen3.CreatePen(PS_SOLID,3,RGB(255,0,0));
	pDC3=GetDC();
	oldpen3=pDC3->SelectObject(&newpen3);
	x3=ox+r*sin(c3*3.1415926/180);
	y3=ox+r*cos(c3*3.1415926/180);
	pDC3->MoveTo(ox,oy);
	pDC3->LineTo(x3,y3);
	c3=c3-6;
	if(c3<=-174)
	{
		c3==174;
	}
	CDialogEx::OnTimer(nIDEvent);
  }
if(nIDEvent==3)
  {
	int r=50;
	CDC *pDC4;
	CPen newpen4,*oldpen4;
	newpen4.CreatePen(PS_SOLID,5,RGB(240,240,240));
	pDC4=GetDC();
	oldpen4=pDC4->SelectObject(&newpen4);
	x4=ox+r*sin(c4*3.1415926/180);
	y4=ox+r*cos(c4*3.1415926/180);
	pDC4->MoveTo(ox,oy);
	pDC4->LineTo(x4,y4);
	c4=c4-6;
	if(c4<=-180)
	{
		c4<=180;
	}
	CDC *pDC5;
	CPen newpen5,*oldpen5;
	newpen5.CreatePen(PS_SOLID,5,RGB(0,255,0));
	pDC5=GetDC();
	oldpen5=pDC5->SelectObject(&newpen5);
	x5=ox+r*sin(c5*3.1415926/180);
	y5=ox+r*cos(c5*3.1415926/180);
	pDC5->MoveTo(ox,oy);
	pDC5->LineTo(x5,y5);
	c5=c5-6;
	if(c5<=-174)
	{
		c5==174;
	}
	CDialogEx::OnTimer(nIDEvent);
  }
  CDialogEx::OnTimer(nIDEvent);
}
