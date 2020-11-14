
// testDlg.h: 头文件
//

#pragma once

// CtestDlg 对话框
class CtestDlg : public CDialogEx
{
// 构造
public:
	CtestDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TEST_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
protected:   //手动添加
	CDC* picDC;       //图片控件类CDC
	int picClient_W;  //客户区宽度：图片控件
	int picClient_H;   //客户区高度：图片控件
	int CenterX, CenterY;  //客户区中心：图片控件
	Graphics* graph;	     //图形对象(指针)，执行绘制(要绑定DC)
	Color BkColor;	     //客户区背景色（重绘客户区，清除）
	Bitmap* src;	     //原图像，Bitmap 对象指针
	Bitmap* dest;	     //结果图像
	int w, h;		     //结果图像宽和高
	BYTE*  R_val;	     //图像R分量值指针（new分配）
	BYTE*  G_val;	     //图像G分量值指针
	BYTE*  B_val;	     //图像B分量值指针

public:
	CBitmapButton start,about,music,W;
	afx_msg void OnStnClickedPic();
	afx_msg void OnBnClickedButton1();
	BOOL PlaySound(LPCSTR pszSound, HMODULE hmod, DWORD fdwSound);
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg
		void OpenMUsic();
	void CloseMusic();
	void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();

};
