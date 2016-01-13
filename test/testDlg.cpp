
// testDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "test.h"
#include "testDlg.h"
#include "afxdialogex.h"
#include "math.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CtestDlg �Ի���




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


// CtestDlg ��Ϣ�������

BOOL CtestDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);
	SetTimer(1,10,NULL);
	SetTimer(2,600,NULL);
	SetTimer(3,3600,NULL);
		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CtestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

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
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CtestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CtestDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
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
