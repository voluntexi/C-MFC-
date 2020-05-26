#pragma once

// GAME 对话框

class GAME : public CDialogEx
{
	DECLARE_DYNAMIC(GAME)

public:
	GAME(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~GAME();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_GAME };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	bool TimerOn;
	int ShowDigit;
	DECLARE_MESSAGE_MAP()
public:
	afx_msg
	CBitmapButton bt1, bt2, bt3;
	void child();
	void OnPaint();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton1();
	CFile file;
	void fileOpen()
	{
		file.Open(L"C:\\Users\\84166\\source\\repos\\test\\步骤.txt", CFile::modeWrite, NULL);
	}
	virtual BOOL OnInitDialog();
	void OnTime();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton7();
};
