// CRangeOfStressDlg.cpp: 구현 파일
//

#include "pch.h"
#include "ImageProcessing2_LDJ_20200721.h"
#include "CRangeOfStressDlg.h"
#include "afxdialogex.h"


// CRangeOfStressDlg 대화 상자

IMPLEMENT_DYNAMIC(CRangeOfStressDlg, CDialog)

CRangeOfStressDlg::CRangeOfStressDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG5, pParent)
	, m_StartPoint(0)
	, m_EndPoint(0)
{

}

CRangeOfStressDlg::~CRangeOfStressDlg()
{
}

void CRangeOfStressDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_StartPoint);
	DDV_MinMaxInt(pDX, m_StartPoint, 0, 255);
	DDX_Text(pDX, IDC_EDIT2, m_EndPoint);
	DDV_MinMaxInt(pDX, m_EndPoint, 0, 255);
}


BEGIN_MESSAGE_MAP(CRangeOfStressDlg, CDialog)
END_MESSAGE_MAP()


// CRangeOfStressDlg 메시지 처리기
