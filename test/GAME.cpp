// GAME.cpp: 实现文件
//

#include "stdafx.h"
#include "test.h"
#include "GAME.h"
#include "afxdialogex.h"
#include"testDlg.h"
#include"Over.h"
// GAME 对话框
#include "windows.h"
#include "mmsystem.h" 
#pragma comment(lib, "WINMM.LIB")
IMPLEMENT_DYNAMIC(GAME, CDialogEx)

GAME::GAME(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_GAME, pParent)
{

}

GAME::~GAME()
{
}

void GAME::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(GAME, CDialogEx)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_BUTTON6, &GAME::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON4, &GAME::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON2, &GAME::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &GAME::OnBnClickedButton1)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON5, &GAME::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON7, &GAME::OnBnClickedButton7)
END_MESSAGE_MAP()


// GAME 消息处理程序
void GAME::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CDialogEx::OnPaint()
	CImage img_bg;
	img_bg.Load(_T("C:\\Users\\84166\\source\\repos\\test\\Game\\GameBg.jpg"));
	img_bg.Draw(GetDC()->m_hDC, CRect(-5, 0, 647, 450));
}
BOOL GAME::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	OnTime();
	// TODO:  在此添加额外的初始化
	
	
	//----替换按钮
	bt1.SubclassDlgItem(IDC_BUTTON1, this);
	bt1.LoadBitmaps(IDB_BITMAP6, IDB_BITMAP7);
	bt1.SizeToContent();
	bt2.SubclassDlgItem(IDC_BUTTON2, this);
	bt2.LoadBitmaps(IDB_BITMAP6, IDB_BITMAP7);
	bt2.SizeToContent();
	bt3.SubclassDlgItem(IDC_BUTTON4, this);
	bt3.LoadBitmaps(IDB_BITMAP6, IDB_BITMAP7);
	bt3.SizeToContent();
	//---------添加GIF
	
	fileOpen();
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}

void GAME::OnTime()
{
	// TODO: 在此添加命令处理程序代码

	if (TimerOn == false)
	{
		TimerOn = true;
		ShowDigit = 0;
		SetTimer(1, 1000, NULL);
	}


}

void GAME::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
}


void GAME::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	//PlaySound(MAKEINTRESOURCE(IDR_WAVE2), AfxGetResourceHandle(), SND_SYNC | SND_RESOURCE | SND_NODEFAULT); 播放音乐
	mciSendString(_T("open C:\\Users\\84166\\source\\repos\\test\\music\\water.wav alias aa"), NULL, 0, NULL);
	mciSendString(_T("play aa wait"), NULL, 0, NULL);
	mciSendString(_T("close aa"), NULL, 0, m_hWnd);
	//===============================================================================================================
	//逻辑判断-----------------------------------
	CString str;
	GetDlgItemText(IDC_BUTTON7, str);
	if (str == "8L")
	{
		GetDlgItem(IDC_BUTTON7)->SetWindowText(_T("3L"));

		GetDlgItem(IDC_BUTTON6)->SetWindowText(_T("5L"));
		/*CFile file;
		file.Open(L"C:\\Users\\84166\\source\\repos\\the water bottle algorithm\\步骤.txt", CFile::modeWrite, NULL);*/
		char crlf[] = "\r\n";
		file.Write("----**开始统计步骤**----", strlen("----**开始统计步骤**----"));
		file.Write(crlf, sizeof(crlf));
		file.Write("----8L水壶全满，将水倒入 5L水壶中------8L水壶剩余：3L，5L水壶全满", strlen("----8L水壶全满，将水倒入 5L水壶中------8L水壶剩余：3L，5L水壶全满"));
		file.Write(crlf, sizeof(crlf));
		Invalidate();
		CImage img_bg1;
		img_bg1.Load(_T("C:\\Users\\84166\\source\\repos\\test\\Game\\bg8to5.jpg"));
		img_bg1.Draw(GetDC()->m_hDC, CRect(-5, 0, 647, 460));
		
		Sleep(500);
		CImage img_bg2;
		img_bg2.Load(_T("C:\\Users\\84166\\source\\repos\\test\\Game\\GameBg.jpg"));
		img_bg2.Draw(GetDC()->m_hDC, CRect(-5, 0, 647, 450));
	}
	if (str == "6L")
	{
		GetDlgItem(IDC_BUTTON7)->SetWindowTextW(_T("1L"));
		GetDlgItem(IDC_BUTTON6)->SetWindowTextW(_T("5L"));
		/*CFile file;
		file.Open(L"C:\\Users\\84166\\source\\repos\\the water bottle algorithm\\步骤.txt", CFile::modeWrite, NULL);*/
		char crlf[] = "\r\n";
		file.Write("----8L水壶6L水，将水倒入 5L水壶中------8L水壶剩余：1L，5L水壶全满", strlen("----8L水壶6L水，将水倒入 5L水壶中------8L水壶剩余：1L，5L水壶全满"));
		file.Write(crlf, sizeof(crlf));
		Invalidate();
		CImage img_bg1;
		img_bg1.Load(_T("C:\\Users\\84166\\source\\repos\\test\\Game\\bg8to5.jpg"));
		img_bg1.Draw(GetDC()->m_hDC, CRect(-5, 0, 647, 460));

		Sleep(500);
		CImage img_bg2;
		img_bg2.Load(_T("C:\\Users\\84166\\source\\repos\\test\\Game\\GameBg.jpg"));
		img_bg2.Draw(GetDC()->m_hDC, CRect(-5, 0, 647, 450));
	}
	//逻辑判断------------------------------------------------------
}


void GAME::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码

	mciSendString(_T("open C:\\Users\\84166\\source\\repos\\test\\music\\water.wav alias aa"), NULL, 0, NULL);
	mciSendString(_T("play aa wait"), NULL, 0, NULL);
	mciSendString(_T("close aa"), NULL, 0, m_hWnd);
	//===============================================================================================================
	CString str1;
	CString str2;
	GetDlgItemText(IDC_BUTTON6, str1);
	GetDlgItemText(IDC_BUTTON7, str2);
	static int i = 1;
	if (str1 == "5L"&&str2 == "3L")
	{
		GetDlgItem(IDC_BUTTON5)->SetWindowTextW(_T("3L"));
		GetDlgItem(IDC_BUTTON6)->SetWindowTextW(_T("2L"));
		i++;
		/*CFile file;
		file.Open(L"C:\\Users\\84166\\source\\repos\\the water bottle algorithm\\步骤.txt", CFile::modeWrite, NULL);*/
		char crlf[] = "\r\n";
		file.Write("----5L水壶全满，将水倒入 3L水壶中------5L水壶剩余：2L，3L水壶全满", strlen("----5L水壶全满，将水倒入 3L水壶中------5L水壶剩余：2L，3L水壶全满"));
		file.Write(crlf, sizeof(crlf));
		Invalidate();
		CImage img_bg1;
		img_bg1.Load(_T("C:\\Users\\84166\\source\\repos\\test\\Game\\bg5to3.jpg"));
		img_bg1.Draw(GetDC()->m_hDC, CRect(-5, 0, 647, 460));

		Sleep(500);
		CImage img_bg2;
		img_bg2.Load(_T("C:\\Users\\84166\\source\\repos\\test\\Game\\GameBg.jpg"));
		img_bg2.Draw(GetDC()->m_hDC, CRect(-5, 0, 647, 450));
	}

	if (str1 == "2L")
	{
		GetDlgItem(IDC_BUTTON5)->SetWindowTextW(_T("2L"));
		GetDlgItem(IDC_BUTTON6)->SetWindowTextW(_T("0L"));
		/*CFile file;
		file.Open(L"C:\\Users\\84166\\source\\repos\\the water bottle algorithm\\步骤.txt", CFile::modeWrite, NULL);*/
		char crlf[] = "\r\n";
		file.Write("----5L水壶2L水，将水倒入 3L水壶中------5L水壶剩余：0L，3L水壶2L水", strlen("----5L水壶2L水，将水倒入 3L水壶中------5L水壶剩余：0L，3L水壶2L水"));
		file.Write(crlf, sizeof(crlf));
		Invalidate();
		CImage img_bg1;
		img_bg1.Load(_T("C:\\Users\\84166\\source\\repos\\test\\Game\\bg5to3.jpg"));
		img_bg1.Draw(GetDC()->m_hDC, CRect(-5, 0, 647, 460));

		Sleep(500);
		CImage img_bg2;
		img_bg2.Load(_T("C:\\Users\\84166\\source\\repos\\test\\Game\\GameBg.jpg"));
		img_bg2.Draw(GetDC()->m_hDC, CRect(-5, 0, 647, 450));

	}
	if (str1 == "5L"&&str2 == "1L")
	{
		GetDlgItem(IDC_BUTTON5)->SetWindowTextW(_T("3L"));
		GetDlgItem(IDC_BUTTON6)->SetWindowTextW(_T("4L"));
		/*CFile file;
		file.Open(L"C:\\Users\\84166\\source\\repos\\the water bottle algorithm\\步骤.txt", CFile::modeWrite, NULL);*/
		char crlf[] = "\r\n";
		file.Write("----5L水壶全满，8L水壶1L水，将5L水壶水倒入 3L水壶中------3L水壶剩余：全满，5L水壶4L水", strlen("----5L水壶全满，8L水壶1L水，将5L水壶水倒入 3L水壶中------3L水壶剩余：全满，5L水壶4L水"));
		file.Write(crlf, sizeof(crlf));
		file.Write("----**步骤统计结束**----", strlen("----**步骤统计结束**----"));
		file.Close();
		Invalidate();
		CImage img_bg1;
		img_bg1.Load(_T("C:\\Users\\84166\\source\\repos\\test\\Game\\bg5to3.jpg"));
		img_bg1.Draw(GetDC()->m_hDC, CRect(-5, 0, 647, 460));

		Sleep(500);
		CImage img_bg2;
		img_bg2.Load(_T("C:\\Users\\84166\\source\\repos\\test\\Game\\GameBg.jpg"));
		img_bg2.Draw(GetDC()->m_hDC, CRect(-5, 0, 647, 450));
		Sleep(800);
		TimerOn = false;
		KillTimer(1);
		 Over dlg;
		dlg.DoModal();
	}
}


void GAME::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	//PlaySound(MAKEINTRESOURCE(IDR_WAVE2), AfxGetResourceHandle(), SND_SYNC | SND_RESOURCE | SND_NODEFAULT); 播放音乐
	mciSendString(_T("open C:\\Users\\84166\\source\\repos\\test\\music\\water.wav alias aa"), NULL, 0, NULL);
	mciSendString(_T("play aa wait"), NULL, 0, NULL);
	mciSendString(_T("close aa"), NULL, 0, m_hWnd);
	//===============================================================================================================
	CString str;
	GetDlgItemText(IDC_BUTTON5, str);
	if (str == "3L")
	{
		GetDlgItem(IDC_BUTTON5)->SetWindowTextW(_T("0L"));
		GetDlgItem(IDC_BUTTON7)->SetWindowTextW(_T("6L"));
		GetDlgItem(IDC_BUTTON6)->SetWindowTextW(_T("2L"));
		/*CFile file;
		file.Open(L"C:\\Users\\84166\\source\\repos\\the water bottle algorithm\\步骤.txt", CFile::modeWrite, NULL);*/
		char crlf[] = "\r\n";
		file.Write("----3L水壶全满，将水倒入 8L水壶中------3L水壶剩余：0L，8L水壶6L水", strlen("----3L水壶全满，将水倒入 8L水壶中------3L水壶剩余：0L，8L水壶6L水"));
		file.Write(crlf, sizeof(crlf));
		Invalidate();
		CImage img_bg1;
		img_bg1.Load(_T("C:\\Users\\84166\\source\\repos\\test\\Game\\bg3to8.jpg"));
		img_bg1.Draw(GetDC()->m_hDC, CRect(-5, 0, 647, 460));

		Sleep(500);
		CImage img_bg2;
		img_bg2.Load(_T("C:\\Users\\84166\\source\\repos\\test\\Game\\GameBg.jpg"));
		img_bg2.Draw(GetDC()->m_hDC, CRect(-5, 0, 647, 450));
	}
}





void GAME::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	ShowDigit++;
	char ch[3];
	_itoa_s(ShowDigit, ch, 10);
	CString text(ch);
	SetDlgItemTextW(IDC_BUTTON8, text);
	CDialogEx::OnTimer(nIDEvent);
}


void GAME::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
}


void GAME::OnBnClickedButton7()
{
	// TODO: 在此添加控件通知处理程序代码
}
