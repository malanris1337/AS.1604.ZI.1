
// demchak_l2Dlg.cpp : ���� ����������
//

#include "stdafx.h"
#include "demchak_l2.h"
#include "demchak_l2Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���������� ���� CAboutDlg ������������ ��� �������� �������� � ����������

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ������ ����������� ����
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // ��������� DDX/DDV

// ����������
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


// ���������� ���� Cdemchak_l2Dlg



Cdemchak_l2Dlg::Cdemchak_l2Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DEMCHAK_L2_DIALOG, pParent)
	, edit_enc(_T(""))
	, edit_dec(_T(""))
	, edit_key(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Cdemchak_l2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, edit_fenc);
	DDX_Control(pDX, IDC_EDIT2, edit_fdec);
	DDX_Text(pDX, IDC_EDIT1, edit_enc);
	DDX_Text(pDX, IDC_EDIT2, edit_dec);
	DDX_Text(pDX, IDC_EDIT3, edit_key);
}

BEGIN_MESSAGE_MAP(Cdemchak_l2Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &Cdemchak_l2Dlg::OnBnClickedButton1)
	ON_EN_CHANGE(IDC_EDIT2, &Cdemchak_l2Dlg::OnEnChangeEdit2)
END_MESSAGE_MAP()


// ����������� ��������� Cdemchak_l2Dlg

BOOL Cdemchak_l2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���������� ������ "� ���������..." � ��������� ����.

	// IDM_ABOUTBOX ������ ���� � �������� ��������� �������.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

	// ������ ������ ��� ����� ����������� ����.  ����� ������ ��� �������������,
	//  ���� ������� ���� ���������� �� �������� ����������
	SetIcon(m_hIcon, TRUE);			// ������� ������
	SetIcon(m_hIcon, FALSE);		// ������ ������

	// TODO: �������� �������������� �������������

	return TRUE;  // ������� �������� TRUE, ���� ����� �� ������� �������� ����������
}

void Cdemchak_l2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// ��� ���������� ������ ����������� � ���������� ���� ����� ��������������� ����������� ���� �����,
//  ����� ���������� ������.  ��� ���������� MFC, ������������ ������ ���������� ��� �������������,
//  ��� ������������� ����������� ������� ��������.

void Cdemchak_l2Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �������� ���������� ��� ���������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ������������ ������ �� ������ ����������� ��������������
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ��������� ������
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ������� �������� ��� ������� ��� ��������� ����������� ������� ��� �����������
//  ���������� ����.
HCURSOR Cdemchak_l2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void Cdemchak_l2Dlg::OnBnClickedButton1()
{
	vector < unsigned  char > sid, snew, key; 
	vector < int > h_ideal(256); 

	UpdateData(1);

	CString s1 = edit_enc;
	CString s2 = edit_dec;
	int key_length = edit_key;

	UpdateData(0);

	ifstream f1(s1, ios::binary);
	ifstream f2(s2, ios::binary);

	if (f1.is_open() && f2.is_open())
	{
		read(f1, sid);
		read(f2, snew);
		pcnt(sid, h_ideal);

		vector < vector < unsigned char > > parts(key_length);
		vector < vector < int > > h_parts(key_length);
		unsigned char c;

		int p = 0;
		for (auto it : snew)
		{
			if (p == key_length)
				p = 0;

			parts[p].push_back(it);
			p++;
		}

		p = 0; 
		for (auto it : parts) 
		{
			h_parts[p].resize(256);

			pcnt(it, h_parts[p]);
			key.push_back(getkey(h_ideal, h_parts[p]));

			p++;
		}

		decode(key, snew, "out_text.txt");
		ofstream fout("out_key.txt");
		for (auto it : key) 
			fout << it;
	
		fout.close();
		f1.close();
		f2.close();
	}	
}


void Cdemchak_l2Dlg::OnEnChangeEdit2()
{
	// TODO:  ���� ��� ������� ���������� RICHEDIT, �� ������� ���������� �� �����
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  �������� ��� �������� ����������
}
