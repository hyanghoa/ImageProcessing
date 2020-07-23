#pragma once


// CConstDlg 대화 상자

class CConstDlg : public CDialog
{
	DECLARE_DYNAMIC(CConstDlg)

public:
	CConstDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CConstDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG4 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	double m_Const;
};
