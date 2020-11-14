// Over.cpp: 实现文件
//

#include "stdafx.h"
#include "test.h"
#include "Over.h"
#include "afxdialogex.h"


// Over 对话框

IMPLEMENT_DYNAMIC(Over, CDialogEx)

Over::Over(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Over, pParent)
{

}

Over::~Over()
{
}

void Over::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Over, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// Over 消息处理程序


void Over::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CDialogEx::OnPaint()
	CImage img_bg;
	if (img_bg.IsNull()) {
		img_bg.Load(_T("C:\\Users\\84166\\source\\repos\\test\\Game\\Over.jpg"));
		img_bg.Draw(GetDC()->m_hDC, CRect(0, -30, 450, 320));
	}


}


BOOL Over::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	over.SubclassDlgItem(IDOK, this);
	over.LoadBitmaps(IDB_BITMAP8, IDB_BITMAP9);
	over.SizeToContent();

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
