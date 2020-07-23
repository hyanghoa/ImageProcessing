// CConstDlg.cpp: 구현 파일
//

#include "pch.h"
#include "ImageProcessing2_LDJ_20200721.h"
#include "CConstDlg.h"
#include "afxdialogex.h"


// CConstDlg 대화 상자

IMPLEMENT_DYNAMIC(CConstDlg, CDialog)

CConstDlg::CConstDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG4, pParent)
	, m_Const(0)
{

}

CConstDlg::~CConstDlg()
{
}

void CConstDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_Const);
	DDV_MinMaxDouble(pDX, m_Const, 0, 255);
}


BEGIN_MESSAGE_MAP(CConstDlg, CDialog)
END_MESSAGE_MAP()


// CConstDlg 메시지 처리기
