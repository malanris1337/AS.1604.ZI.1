
// demchak_l2Dlg.h : файл заголовка
//

#pragma once
#include "afxwin.h"


// диалоговое окно Cdemchak_l2Dlg
class Cdemchak_l2Dlg : public CDialogEx
{
// Создание
public:
	Cdemchak_l2Dlg(CWnd* pParent = NULL);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DEMCHAK_L2_DIALOG };
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
	afx_msg void OnBnClickedButton1();
	CEdit edit_fenc;
	afx_msg void OnEnChangeEdit2();
	CEdit edit_fdec;
	CString edit_enc;
	CString edit_dec;
	int edit_key;
};
