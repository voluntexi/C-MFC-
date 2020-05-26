#pragma once
#include"PictureEx.h";

// AboutTest 对话框

class AboutTest : public CDialogEx
{
	DECLARE_DYNAMIC(AboutTest)

public:
	AboutTest(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~AboutTest();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CPictureEx Picture;
	afx_msg void OnPaint();
	CBitmapButton button;
};
