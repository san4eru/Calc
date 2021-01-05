
// CalcDlg.h: файл заголовка
//

#pragma once


// Диалоговое окно CCalcDlg
class CCalcDlg : public CDialogEx
{
// Создание
public:
	CCalcDlg(CWnd* pParent = nullptr);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CALC_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CButton m_mc;
	CButton m_mr;
	CString histor;
	CString Result;
	afx_msg void OnBnClickedButtonMc();
	afx_msg void OnBnClickedButtonMr();
	afx_msg void OnBnClickedButtonMp();
	afx_msg void OnBnClickedButtonMm();
	afx_msg void OnBnClickedButtonMs();
	afx_msg void OnBnClickedButtonProc();
	afx_msg void OnBnClickedButtonCe();
	afx_msg void OnBnClickedButtonC();
	afx_msg void OnBnClickedButtonBackspace();
	afx_msg void OnBnClickedButtonDrop();
	afx_msg void OnBnClickedButtonSq();
	afx_msg void OnBnClickedButtonSqrt();
	afx_msg void OnBnClickedButtonDel();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButtonYmn();
	afx_msg void OnBnClickedButtonMin();
	afx_msg void OnBnClickedButtonPlus();
	afx_msg void OnBnClickedButtonRavno();
	afx_msg void OnBnClickedButtonZap();
	afx_msg void OnBnClickedButtonPm();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton0();
	void Operation(CString n_op);
	void Single_Op(CString n_op);
	void GetNum(CString num);	
};
