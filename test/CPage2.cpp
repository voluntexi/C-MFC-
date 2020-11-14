// CPage2.cpp: 实现文件
//

#include "stdafx.h"
#include "test.h"
#include "CPage2.h"
#include "afxdialogex.h"
#include"testDlg.h"

// CPage2 对话框

IMPLEMENT_DYNAMIC(CPage2, CDialogEx)

CPage2::CPage2(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

CPage2::~CPage2()
{
}

void CPage2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CPage2, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CPage2 消息处理程序


void CPage2::OnPaint()
{
	CPaintDC dc(this); // device context for painting
			   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 

	CImage img1;
	img1.Load(_T(".\\ABOUTbg.jpg"));
	img1.Draw(GetDC()->m_hDC, CRect(-30, 0, 650, 500));
}
