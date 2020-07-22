// CQUANTIZATIONDlg.cpp: 구현 파일
//

#include "pch.h"
#include "ImageProcessing2_LDJ_20200721.h"
#include "CQUANTIZATIONDlg.h"
#include "afxdialogex.h"


// CQUANTIZATIONDlg 대화 상자

IMPLEMENT_DYNAMIC(CQuantizationDlg, CDialog)

CQuantizationDlg::CQuantizationDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG3, pParent)
	, m_QuantizationBits(0)
{

}

CQuantizationDlg::~CQuantizationDlg()
{
}

void CQuantizationDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_QuantizationBits);
	DDV_MinMaxInt(pDX, m_QuantizationBits, 1, 8);
}


BEGIN_MESSAGE_MAP(CQuantizationDlg, CDialog)
END_MESSAGE_MAP()


// CQUANTIZATIONDlg 메시지 처리기
