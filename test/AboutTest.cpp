// AboutTest.cpp: 实现文件
//

#include "stdafx.h"
#include "test.h"
#include "AboutTest.h"
#include "afxdialogex.h"


// AboutTest 对话框

IMPLEMENT_DYNAMIC(AboutTest, CDialogEx)

AboutTest::AboutTest(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG3, pParent)
{

}

AboutTest::~AboutTest()
{
}

void AboutTest::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_Picture, Picture);
	DDX_Control(pDX, IDOK, button);
}


BEGIN_MESSAGE_MAP(AboutTest, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// AboutTest 消息处理程序


BOOL AboutTest::OnInitDialog()
{
	CDialogEx::OnInitDialog();
//----替换按钮
	/*button.SubclassDlgItem(IDOK, this);
	button.LoadBitmaps(IDB_BITMAP8, IDB_BITMAP9);
	button.SizeToContent();*/
	// TODO:  在此添加额外的初始化
	if (Picture.Load(MAKEINTRESOURCE(IDR_GIF3), _T("GIF")))  Picture.Draw();
	
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
	
}


void AboutTest::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CDialogEx::OnPaint()
	CImage img_bg;
	img_bg.Load(_T("..\\GIF\\Writer.jpg"));
	img_bg.Draw(GetDC()->m_hDC, CRect(0,70,380 ,185 ));
}
