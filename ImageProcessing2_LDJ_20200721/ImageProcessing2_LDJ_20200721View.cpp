
// ImageProcessing2_LDJ_20200721View.cpp: CImageProcessing2LDJ20200721View 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "ImageProcessing2_LDJ_20200721.h"
#endif

#include "ImageProcessing2_LDJ_20200721Doc.h"
#include "ImageProcessing2_LDJ_20200721View.h"
 
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CImageProcessing2LDJ20200721View

IMPLEMENT_DYNCREATE(CImageProcessing2LDJ20200721View, CView)

BEGIN_MESSAGE_MAP(CImageProcessing2LDJ20200721View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CImageProcessing2LDJ20200721View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_DOWN_SAMPLE, &CImageProcessing2LDJ20200721View::OnDownSample)
	ON_COMMAND(ID_UP_SAMPLE, &CImageProcessing2LDJ20200721View::OnUpSample)
	ON_COMMAND(ID_QUANTIZATION, &CImageProcessing2LDJ20200721View::OnQuantization)
END_MESSAGE_MAP()

// CImageProcessing2LDJ20200721View 생성/소멸

CImageProcessing2LDJ20200721View::CImageProcessing2LDJ20200721View() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CImageProcessing2LDJ20200721View::~CImageProcessing2LDJ20200721View()
{
}

BOOL CImageProcessing2LDJ20200721View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CImageProcessing2LDJ20200721View 그리기

void CImageProcessing2LDJ20200721View::OnDraw(CDC* pDC)
{
	CImageProcessing2LDJ20200721Doc* pDoc = GetDocument(); // Doc 클래스 참조
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	int i, j;
	unsigned char R, G, B;
	// 입력 영상 출력
	for (i = 0; i < pDoc->m_height; i++) {
		for (j = 0; j < pDoc->m_width; j++) {
			R = pDoc->m_InputImage[i * pDoc->m_width + j];
			G = B = R;
			pDC->SetPixel(j + 5, i + 5, RGB(R, G, B));
		}
	}
	// 축소된 영상 출력
	for (i = 0; i < pDoc->m_Re_height; i++) {
		for (j = 0; j < pDoc->m_Re_width; j++) {
			R = pDoc->m_OutputImage[i * pDoc->m_Re_width + j];
			G = B = R;
			pDC->SetPixel(j + pDoc->m_width + 10, i + 5, RGB(R, G, B));
		}
	}


}
 

// CImageProcessing2LDJ20200721View 인쇄


void CImageProcessing2LDJ20200721View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CImageProcessing2LDJ20200721View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CImageProcessing2LDJ20200721View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CImageProcessing2LDJ20200721View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void CImageProcessing2LDJ20200721View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CImageProcessing2LDJ20200721View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CImageProcessing2LDJ20200721View 진단

#ifdef _DEBUG
void CImageProcessing2LDJ20200721View::AssertValid() const
{
	CView::AssertValid();
}

void CImageProcessing2LDJ20200721View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CImageProcessing2LDJ20200721Doc* CImageProcessing2LDJ20200721View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CImageProcessing2LDJ20200721Doc)));
	return (CImageProcessing2LDJ20200721Doc*)m_pDocument;
}
#endif //_DEBUG


// CImageProcessing2LDJ20200721View 메시지 처리기


void CImageProcessing2LDJ20200721View::OnDownSample()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessing2LDJ20200721Doc* pDoc = GetDocument(); // Doc 클래스 참조
	ASSERT_VALID(pDoc);
	pDoc->OnDownSampling(); // Doc 클래스에 OnDownSampling 함수 호출
	Invalidate(TRUE); // 화면 갱신
}


void CImageProcessing2LDJ20200721View::OnUpSample()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessing2LDJ20200721Doc* pDoc = GetDocument(); // Doc 클래스 참조
	ASSERT_VALID(pDoc);
	pDoc->OnUpSampling(); // Doc 클래스에 OnUpSampling 함수 호출
	Invalidate(TRUE); // 화면 갱신

}


void CImageProcessing2LDJ20200721View::OnQuantization()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessing2LDJ20200721Doc* pDoc = GetDocument(); // Doc 클래스 참조
	ASSERT_VALID(pDoc);
	pDoc->OnQuantization(); // Doc 클래스에 OnQuantization 함수 호출
	Invalidate(TRUE); // 화면 갱신
}
