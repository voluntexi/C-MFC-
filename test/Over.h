#pragma once


// Over 对话框

class Over : public CDialogEx
{
	DECLARE_DYNAMIC(Over)

public:
	Over(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Over();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Over1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	CBitmapButton over;
	virtual BOOL OnInitDialog();
};
