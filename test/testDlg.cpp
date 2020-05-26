
// testDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "test.h"
#include "testDlg.h"
#include "afxdialogex.h"
#include"CPage2.h"
#include"GAME.h"
#include"AboutTest.h"
//#ifdef _DEBUG
//#define new DEBUG_NEW
//#endif
#include "windows.h"
#include "mmsystem.h" 
#pragma comment(lib, "WINMM.LIB")

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框
static int i = 1;
class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	CStatic Picture;
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_About)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_Picture, Picture);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_WM_CREATE()
END_MESSAGE_MAP()


// CtestDlg 对话框



CtestDlg::CtestDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TEST_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	
}

void CtestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	
}

BEGIN_MESSAGE_MAP(CtestDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_STN_CLICKED(IDC_Pic, &CtestDlg::OnStnClickedPic)
	ON_BN_CLICKED(IDC_BUTTON1, &CtestDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CtestDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CtestDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CtestDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CtestDlg::OnBnClickedButton5)
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
	if (pSysMenu != nullptr)
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	//初始化GDI+
	CRect rect;
	picDC = GetDlgItem(IDC_Pic)->GetDC();
	GetDlgItem(IDC_Pic)->GetClientRect(&rect);
	picClient_H = rect.Height();
	picClient_W = rect.Width();
	graph =Graphics::FromHDC(picDC->m_hDC);
	//-----------------------------------------
	//按钮覆盖图片
	start.SubclassDlgItem(IDC_BUTTON1,this);
	start.LoadBitmaps(IDB_BITMAP2, IDB_BITMAP1);
	start.SizeToContent();
	about.SubclassDlgItem(IDC_BUTTON3, this);
	about.LoadBitmaps(IDB_BITMAP3, IDB_BITMAP4);
	about.SizeToContent();
	music.SubclassDlgItem(IDC_BUTTON4, this);
	music.LoadBitmaps(IDB_MUSIC, IDB_MUSIC);
	music.SizeToContent();
	W.SubclassDlgItem(IDC_BUTTON5, this);
	W.LoadBitmaps(IDB_BITMAP10, IDB_BITMAP11);
	W.SizeToContent();
	//翻页效果

	
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
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
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
	{    Image img(L"Toptest.png");
	     Image img2(L"bg.jpg");
	     graph->DrawImage(&img2, PointF(0, 0));
		graph->DrawImage(&img, PointF(20, 40));
		CDialogEx::OnPaint();
	}
		
		
		
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CtestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CtestDlg::OnStnClickedPic()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CtestDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	this->ShowWindow(SW_HIDE);
	GAME dlg;
	dlg.DoModal();
	this->ShowWindow(SW_SHOW);
}



void CtestDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	this->ShowWindow(SW_HIDE);
	CPage2 dlg;
	dlg.DoModal();
	this->ShowWindow(SW_SHOW);
}




void CtestDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码

	
}

//BOOL PlaySound(LPCSTR lpszSound, HMODULE hmod, UINT fuSound);
int CAboutDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialogEx::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码
	//PlaySound((LPCTSTR)IDR_WAVE1, AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
	return 0;
}

void CtestDlg::OpenMUsic()
{
	UpdateData();
	PlaySound((LPCTSTR)IDR_WAVE1, NULL, SND_RESOURCE | SND_LOOP | SND_ASYNC); //提示音	
}
void CtestDlg::CloseMusic()
{
	PlaySound(NULL, NULL, SND_FILENAME); // 停止播放。
}
void CtestDlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	i++;
	if (i%2==0)
	{
		OpenMUsic();
	}
	else
	{
		CloseMusic();
	}
		
	
		
	
}


void CtestDlg::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码

	AboutTest a;
	a.DoModal();
}
