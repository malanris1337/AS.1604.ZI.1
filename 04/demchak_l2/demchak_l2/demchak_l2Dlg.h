
// demchak_l2Dlg.h : ���� ���������
//

#pragma once
#include "afxwin.h"


// ���������� ���� Cdemchak_l2Dlg
class Cdemchak_l2Dlg : public CDialogEx
{
// ��������
public:
	Cdemchak_l2Dlg(CWnd* pParent = NULL);	// ����������� �����������

// ������ ����������� ����
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DEMCHAK_L2_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// ��������� DDX/DDV


// ����������
protected:
	HICON m_hIcon;

	// ��������� ������� ����� ���������
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	CEdit edit_fenc;
	afx_msg void OnEnChangeEdit2();
	CEdit edit_fdec;
	CString edit_enc;
	CString edit_dec;
	int edit_key;
};
