
// CalcDlg.cpp: файл реализации
//

#include "pch.h"
#include "framework.h"
#include "Calc.h"
#include "CalcDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Диалоговое окно CAboutDlg используется для описания сведений о приложении

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

// Реализация
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Диалоговое окно CCalcDlg



CCalcDlg::CCalcDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CALC_DIALOG, pParent)
	, histor(_T(""))
	, Result(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCalcDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON_MC, m_mc);
	DDX_Control(pDX, IDC_BUTTON_MR, m_mr);
	DDX_Text(pDX, IDC_EDIT_HIST, histor);
	DDX_Text(pDX, IDC_EDIT_RESULT, Result);
}

BEGIN_MESSAGE_MAP(CCalcDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_MC, &CCalcDlg::OnBnClickedButtonMc)
	ON_BN_CLICKED(IDC_BUTTON_MR, &CCalcDlg::OnBnClickedButtonMr)
	ON_BN_CLICKED(IDC_BUTTON_MP, &CCalcDlg::OnBnClickedButtonMp)
	ON_BN_CLICKED(IDC_BUTTON_MM, &CCalcDlg::OnBnClickedButtonMm)
	ON_BN_CLICKED(IDC_BUTTON_MS, &CCalcDlg::OnBnClickedButtonMs)
	ON_BN_CLICKED(IDC_BUTTON_PROC, &CCalcDlg::OnBnClickedButtonProc)
	ON_BN_CLICKED(IDC_BUTTON_CE, &CCalcDlg::OnBnClickedButtonCe)
	ON_BN_CLICKED(IDC_BUTTON_C, &CCalcDlg::OnBnClickedButtonC)
	ON_BN_CLICKED(IDC_BUTTON_BACKSPACE, &CCalcDlg::OnBnClickedButtonBackspace)
	ON_BN_CLICKED(IDC_BUTTON_DROP, &CCalcDlg::OnBnClickedButtonDrop)
	ON_BN_CLICKED(IDC_BUTTON_SQ, &CCalcDlg::OnBnClickedButtonSq)
	ON_BN_CLICKED(IDC_BUTTON_SQRT, &CCalcDlg::OnBnClickedButtonSqrt)
	ON_BN_CLICKED(IDC_BUTTON_DEL, &CCalcDlg::OnBnClickedButtonDel)
	ON_BN_CLICKED(IDC_BUTTON7, &CCalcDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CCalcDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CCalcDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON_YMN, &CCalcDlg::OnBnClickedButtonYmn)
	ON_BN_CLICKED(IDC_BUTTON_MIN, &CCalcDlg::OnBnClickedButtonMin)
	ON_BN_CLICKED(IDC_BUTTON_PLUS, &CCalcDlg::OnBnClickedButtonPlus)
	ON_BN_CLICKED(IDC_BUTTON_RAVNO, &CCalcDlg::OnBnClickedButtonRavno)
	ON_BN_CLICKED(IDC_BUTTON_ZAP, &CCalcDlg::OnBnClickedButtonZap)
	ON_BN_CLICKED(IDC_BUTTON_PM, &CCalcDlg::OnBnClickedButtonPm)
	ON_BN_CLICKED(IDC_BUTTON6, &CCalcDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON5, &CCalcDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON4, &CCalcDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON3, &CCalcDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON2, &CCalcDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &CCalcDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON0, &CCalcDlg::OnBnClickedButton0)
END_MESSAGE_MAP()


// Обработчики сообщений CCalcDlg

BOOL CCalcDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Добавление пункта "О программе..." в системное меню.

	// IDM_ABOUTBOX должен быть в пределах системной команды.
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

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию

	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

void CCalcDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CCalcDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CCalcDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


bool flag = false, flag2 = false, is_num = false, next_num = false;
double num1, num2, memory;
CString prev_op;


void CCalcDlg::Operation(CString n_op) 
{
	UpdateData();

	if (flag && prev_op == n_op) {
		flag = false;
		is_num = false;
	}

	if (Result == L"Ошибка")
		Result = L"0";
	
	if (is_num)
	{
		if (next_num) 
		{
			histor = histor + n_op;
			flag = true;
			next_num = false;
		}
		else {
			histor = histor + Result + n_op;
			flag = true;
		}
	}
	else if (prev_op != L"=" && next_num != true) {
		histor.Delete(histor.GetLength() - 1, 1);
		histor = histor + n_op;
		prev_op = n_op;
	}

	if (flag && prev_op != L"") {
		if (prev_op == L"=") {
			num1 = _ttof(Result);
			flag = true;
			prev_op = n_op;
			is_num = false;
			flag2 = true;
		}
		else if (is_num) {
			num2 = _ttof(Result);
			if (prev_op == L"-") {
				Result.Format(L"%0.2f", num1 - num2);
				num1 -= num2;

			}
			else if (prev_op == L"+") {
				Result.Format(L"%0.2f", num1 + num2);
				num1 += num2;

			}
			else if (prev_op == L"%") {
				Result.Format(L"%0.2f", num1 * num2 / 100);
				num1 = num1 * num2 / 100;

			}
			else if (prev_op == L"*") {
				Result.Format(L"%0.2f", num1 * num2);
				num1 *= num2;

			}
			else if (prev_op == L"/") {
				if (num2 == 0)
				{
					Result.Format(L"Ошибка");
					num1 = 0;
					histor = "";

				}
				else {
					Result.Format(L"%0.2f", num1 / num2);
					num1 /= num2;
				}

			}
			else if (prev_op == L"=") {
				histor = Result + n_op;

			}
			else if (prev_op == L"1/x") {
				Result.Format(L"%0.2f", 1 / _ttof(Result));

			}

			is_num = false;
		}

		prev_op = n_op;
	}
	else {

		num1 = _ttof(Result);
		flag = true;
		prev_op = n_op;
		is_num = false;
		flag2 = true;

	}
	UpdateData(false);
}


void CCalcDlg::OnBnClickedButtonMc()
{
	UpdateData();
	m_mr.EnableWindow(FALSE);
	m_mc.EnableWindow(FALSE);
	UpdateData(false);
}


void CCalcDlg::OnBnClickedButtonMr()
{
	UpdateData();
	Result.Format(L"%0.2f", memory);
	UpdateData(false);
}


void CCalcDlg::OnBnClickedButtonMp()
{
	UpdateData();
	memory = memory + _ttof(Result);
	UpdateData(false);
}


void CCalcDlg::OnBnClickedButtonMm()
{
	UpdateData();
	memory = memory - _ttof(Result);
	UpdateData(false);
}


void CCalcDlg::OnBnClickedButtonMs()
{
	UpdateData();
	memory = _ttof(Result);
	m_mr.EnableWindow(TRUE);
	m_mc.EnableWindow(TRUE);
	UpdateData(false);
}


void CCalcDlg::OnBnClickedButtonProc()
{
	Operation(L"%");
}


void CCalcDlg::OnBnClickedButtonCe()
{
	UpdateData();
	Result.Format(L"0");
	UpdateData(false);
}


void CCalcDlg::OnBnClickedButtonC()
{
	UpdateData();
	Result.Format(L"0");
	flag = false;
	is_num = false;
	next_num = false;
	prev_op = L"";
	histor = L"";
	UpdateData(false);
}


void CCalcDlg::OnBnClickedButtonBackspace()
{
	UpdateData();
	if (Result != L"0")
		Result.Delete(Result.GetLength() - 1, 1);
	UpdateData(false);
}

void CCalcDlg::Single_Op(CString n_op)
{
	UpdateData();

	if (prev_op == L"=")
		histor = L"";

	if (n_op == L"1/x")
	{
		histor = histor + L"1/(" + Result + L")";
		Result.Format(L"%0.2f", 1 / _ttof(Result));
		
		if (flag2)
			num2 = _ttof(Result);
		else
			num1 = _ttof(Result);

		next_num = true;
	}
	else if (n_op == L"x^2") {
		histor = histor + Result + L"^2";
		Result.Format(L"%0.2f", _ttof(Result) * _ttof(Result));
		if (flag2) {
			num2 = _ttof(Result);
		}
		else {
			num1 = _ttof(Result);
		}
		next_num = true;
	}
	else if (n_op == L"sqrt(x)") {
		if (Result[0] == '-') {
			Result.Format(L"Ошибка");
			num1 = 0;
			histor = "";
		}
		else {
			histor = histor + L"sqrt(" + Result + L")";
			Result.Format(L"%0.2f", sqrt(_ttof(Result)));
			if (flag2) {
				num2 = _ttof(Result);
			}
			else {
				num1 = _ttof(Result);
			}
			next_num = true;
		}
	}
	UpdateData(false);
}

void CCalcDlg::OnBnClickedButtonDrop()
{
	Single_Op(L"1/x");
}


void CCalcDlg::OnBnClickedButtonSq()
{
	Single_Op(L"x^2");
}


void CCalcDlg::OnBnClickedButtonSqrt()
{
	Single_Op(L"sqrt(x)");
}


void CCalcDlg::OnBnClickedButtonDel()
{
	Operation(L"/");
}


void CCalcDlg::OnBnClickedButtonYmn()
{
	Operation(L"*");
}


void CCalcDlg::OnBnClickedButtonMin()
{
	Operation(L"-");
}


void CCalcDlg::OnBnClickedButtonPlus()
{
	Operation(L"+");
}


void CCalcDlg::OnBnClickedButtonRavno()
{
	Operation(L"=");
}


void CCalcDlg::OnBnClickedButtonZap()
{
	UpdateData();
	if (Result.Find(L".") == -1) {
		Result = Result + L".";
		is_num = true;
	}
	UpdateData(false);
}


void CCalcDlg::OnBnClickedButtonPm()
{
	UpdateData();
	if (Result != L"0") 
	{
		num1 = -num1;
		if (Result.Find(L"-") == -1)
			Result = L"-" + Result;
		else
			Result.Delete(0, 1);
	}
	UpdateData(false);
}


void CCalcDlg::GetNum(CString num)
{
	UpdateData();
	if (Result == L"Ошибка")
		Result = L"0";

	is_num = true;

	if (Result == L"0" || flag)
	{
		Result = num;
		flag = false;
	}
	else
		Result += num;
	UpdateData(false);
}


void CCalcDlg::OnBnClickedButton9()
{
	GetNum(L"9");
}


void CCalcDlg::OnBnClickedButton8()
{
	GetNum(L"8");
}


void CCalcDlg::OnBnClickedButton7()
{
	GetNum(L"7");
}


void CCalcDlg::OnBnClickedButton6()
{
	GetNum(L"6");
}


void CCalcDlg::OnBnClickedButton5()
{
	GetNum(L"5");
}


void CCalcDlg::OnBnClickedButton4()
{
	GetNum(L"4");
}


void CCalcDlg::OnBnClickedButton3()
{
	GetNum(L"3");
}


void CCalcDlg::OnBnClickedButton2()
{
	GetNum(L"2");
}


void CCalcDlg::OnBnClickedButton1()
{
	GetNum(L"1");
}


void CCalcDlg::OnBnClickedButton0()
{
	GetNum(L"0");
}
