
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
	ON_COMMAND(ID_CONST, &CImageProcessing2LDJ20200721View::OnConst)
	ON_COMMAND(ID_SUBCONST, &CImageProcessing2LDJ20200721View::OnSubconst)
	ON_COMMAND(ID_MULCONST, &CImageProcessing2LDJ20200721View::OnMulconst)
	ON_COMMAND(ID_DIVCONST, &CImageProcessing2LDJ20200721View::OnDivconst)
	ON_COMMAND(ID_AND_OPERATE, &CImageProcessing2LDJ20200721View::OnAndOperate)
	ON_COMMAND(ID_OR_OPERATE, &CImageProcessing2LDJ20200721View::OnOrOperate)
	ON_COMMAND(ID_XOR_OPERATE, &CImageProcessing2LDJ20200721View::OnXorOperate)
	ON_COMMAND(ID_NEGA_TRANSFORM, &CImageProcessing2LDJ20200721View::OnNegaTransform)
	ON_COMMAND(ID_GAMMA_CORRECTION, &CImageProcessing2LDJ20200721View::OnGammaCorrection)
	ON_COMMAND(ID_BINARIZATION, &CImageProcessing2LDJ20200721View::OnBinarization)
	ON_COMMAND(ID_RANGE_OF_STRESS, &CImageProcessing2LDJ20200721View::OnRangeOfStress)
	ON_COMMAND(ID_HIST_STRETCH, &CImageProcessing2LDJ20200721View::OnHistStretch)
	ON_COMMAND(ID_END_IN_SEARCH, &CImageProcessing2LDJ20200721View::OnEndInSearch)
	ON_COMMAND(ID_HISTOGRAM, &CImageProcessing2LDJ20200721View::OnHistogram)
	ON_COMMAND(ID_HISTO_EQUAL, &CImageProcessing2LDJ20200721View::OnHistoEqual)
	ON_COMMAND(ID_HISTO_SPEC, &CImageProcessing2LDJ20200721View::OnHistoSpec)

	ON_COMMAND(ID_EMBOSSING, &CImageProcessing2LDJ20200721View::OnEmbossing)
	ON_COMMAND(ID_BLURR, &CImageProcessing2LDJ20200721View::OnBlurr)
	ON_COMMAND(ID_GAUSSIAN_FILTER, &CImageProcessing2LDJ20200721View::OnGaussianFilter)
	ON_COMMAND(ID_HPF_SHARPENING, &CImageProcessing2LDJ20200721View::OnHpfSharpening)
	ON_COMMAND(ID_SHARPENING, &CImageProcessing2LDJ20200721View::OnSharpening)
	ON_COMMAND(ID_LPFSHARPENING, &CImageProcessing2LDJ20200721View::OnLpfsharpening)
	ON_COMMAND(ID_DIFF_OPERATOR_HOR, &CImageProcessing2LDJ20200721View::OnDiffOperatorHor)
	ON_COMMAND(ID_HOMOGEN_OPERATOR, &CImageProcessing2LDJ20200721View::OnHomogenOperator)
	ON_COMMAND(ID_LAPLACIAN, &CImageProcessing2LDJ20200721View::OnLaplacian)
	ON_COMMAND(ID_NEAREST, &CImageProcessing2LDJ20200721View::OnNearest)
	ON_COMMAND(ID_BILINEAR, &CImageProcessing2LDJ20200721View::OnBilinear)
	ON_COMMAND(ID_MEDIANSUB, &CImageProcessing2LDJ20200721View::OnMediansub)
	ON_COMMAND(ID_MEANSUB, &CImageProcessing2LDJ20200721View::OnMeansub)
	ON_COMMAND(ID_TRANSLATION, &CImageProcessing2LDJ20200721View::OnTranslation)
	ON_COMMAND(ID_MIRRORHOR, &CImageProcessing2LDJ20200721View::OnMirrorhor)
	ON_COMMAND(ID_MIRRORVER, &CImageProcessing2LDJ20200721View::OnMirrorver)
	ON_COMMAND(ID_ROTATION, &CImageProcessing2LDJ20200721View::OnRotation)
	ON_COMMAND(ID_MASK, &CImageProcessing2LDJ20200721View::OnMask)
	ON_COMMAND(ID_comb, &CImageProcessing2LDJ20200721View::OnComb)

END_MESSAGE_MAP()

// CImageProcessing2LDJ20200721View 생성/소멸

CImageProcessing2LDJ20200721View::CImageProcessing2LDJ20200721View() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.
	BmInfo = (BITMAPINFO*)malloc(sizeof(BITMAPINFO) + 256 * sizeof(RGBQUAD));
	for (int i = 0; i < 256; i++)
	{
		BmInfo->bmiColors[i].rgbRed = i;
		BmInfo->bmiColors[i].rgbGreen = i;
		BmInfo->bmiColors[i].rgbBlue = i;
			BmInfo->bmiColors[i].rgbReserved = 0;
	}


}

CImageProcessing2LDJ20200721View::~CImageProcessing2LDJ20200721View()
{
	free(BmInfo);
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
	#define WIDTHBYTES(bits)	(((bits)+31)/32*4);        //이미지 가로 바이트 길이는 4바이트의 배수
	//BmInfo;
	int height;
	int width;
	int rwsize;

	CImageProcessing2LDJ20200721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
	if (pDoc->m_InputImage == NULL)
		return;

	//24비트 비트맵 파일의 영상출력
	if (pDoc->dibHi.biBitCount == 8) {
		height = pDoc->dibHi.biHeight;
		width = pDoc->dibHi.biWidth;
		rwsize = WIDTHBYTES(pDoc->dibHi.biBitCount * pDoc->dibHi.biWidth);
		BmInfo->bmiHeader = pDoc->dibHi;
		SetDIBitsToDevice(pDC->GetSafeHdc(), 0, 0, width, height, 0, 0, 0, height, pDoc->m_InputImage, BmInfo, DIB_PAL_COLORS);
	}
	else	//8비트 컬러일 경우
	{
		int index;
		rwsize = WIDTHBYTES(pDoc->dibHi.biBitCount * pDoc->dibHi.biWidth);

		//팔레트를 읽어들이며 반복출력
		for (int i = 0; i < pDoc->dibHi.biHeight; i++){
			for (int j = 0; j < pDoc->dibHi.biWidth; j++) {
				index = pDoc->m_InputImage[i * rwsize + j];
				BYTE R = pDoc->palRGB[index].rgbRed;
				BYTE G = pDoc->palRGB[index].rgbGreen;
				BYTE B = pDoc->palRGB[index].rgbBlue;

			//영상 반전출력
				pDC->SetPixel(j, pDoc->dibHi.biHeight - i - 1, RGB(R, G, B));
			}
		}
	}

	// ===============================================
	
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


void CImageProcessing2LDJ20200721View::OnConst()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessing2LDJ20200721Doc* pDoc = GetDocument();
	// 도큐먼트 클래스 참조
	ASSERT_VALID(pDoc); // 인스턴스 주소를 가져옴
	pDoc->OnSumConst();
	Invalidate(TRUE);
}


void CImageProcessing2LDJ20200721View::OnSubconst()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessing2LDJ20200721Doc* pDoc = GetDocument();// 도큐먼트 클래스 참조
	ASSERT_VALID(pDoc); // 인스턴스 주소를 가져옴
	pDoc->OnSubConst();
	Invalidate(TRUE);
}


void CImageProcessing2LDJ20200721View::OnMulconst()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessing2LDJ20200721Doc* pDoc = GetDocument(); // 도큐먼트 클래스 참조
	ASSERT_VALID(pDoc); // 인스턴스 주소를 가져옴
	pDoc->OnMulConst();
	Invalidate(TRUE);
}


void CImageProcessing2LDJ20200721View::OnDivconst()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessing2LDJ20200721Doc* pDoc = GetDocument(); // 도큐먼트 클래스 참조
	ASSERT_VALID(pDoc); // 인스턴스 주소를 가져옴
	pDoc->OnDivConst();
	Invalidate(TRUE);
}


void CImageProcessing2LDJ20200721View::OnAndOperate()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessing2LDJ20200721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnAndOperate();
	Invalidate(TRUE);
}


void CImageProcessing2LDJ20200721View::OnOrOperate()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessing2LDJ20200721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnOrOperate();
	Invalidate(TRUE);
}


void CImageProcessing2LDJ20200721View::OnXorOperate()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessing2LDJ20200721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnXorOperate();
	Invalidate(TRUE);
}


void CImageProcessing2LDJ20200721View::OnNegaTransform()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessing2LDJ20200721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnNegaTransform();
	Invalidate(TRUE);

}


void CImageProcessing2LDJ20200721View::OnGammaCorrection()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessing2LDJ20200721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnGammaCorrection();
	Invalidate(TRUE);
}

void CImageProcessing2LDJ20200721View::OnBinarization()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessing2LDJ20200721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnBinarization();
	Invalidate(TRUE);
}


void CImageProcessing2LDJ20200721View::OnRangeOfStress()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessing2LDJ20200721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnRangeOfStress();
	Invalidate(TRUE);
}


void CImageProcessing2LDJ20200721View::OnHistStretch()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessing2LDJ20200721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnHistStretch();
	Invalidate(TRUE);
}


void CImageProcessing2LDJ20200721View::OnEndInSearch()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessing2LDJ20200721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnEndInSearch();
	Invalidate(TRUE);
}


void CImageProcessing2LDJ20200721View::OnHistogram()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessing2LDJ20200721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnHistogram();
	Invalidate(TRUE);

}


void CImageProcessing2LDJ20200721View::OnHistoEqual()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessing2LDJ20200721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnHistoEqual();
	Invalidate(TRUE);
}


void CImageProcessing2LDJ20200721View::OnHistoSpec()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessing2LDJ20200721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnHistoSpec();
		Invalidate(TRUE);

}


void CImageProcessing2LDJ20200721View::OnEmbossing()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessing2LDJ20200721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnEmbossing();
	Invalidate(TRUE);
}

void CImageProcessing2LDJ20200721View::OnBlurr()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessing2LDJ20200721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnBlurr();
	Invalidate(TRUE);
}


void CImageProcessing2LDJ20200721View::OnGaussianFilter()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessing2LDJ20200721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnGaussianFilter();
	Invalidate(TRUE);
}


void CImageProcessing2LDJ20200721View::OnSharpening()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessing2LDJ20200721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnSharpening();
	Invalidate(TRUE);
}



void CImageProcessing2LDJ20200721View::OnHpfSharpening()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessing2LDJ20200721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnHpfSharpening();
	Invalidate(TRUE);
}




void CImageProcessing2LDJ20200721View::OnLpfsharpening()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessing2LDJ20200721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnLpfsharpening();
	Invalidate(TRUE);
}


void CImageProcessing2LDJ20200721View::OnDiffOperatorHor()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessing2LDJ20200721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnDiffOperatorHor();
	Invalidate(TRUE);
}


void CImageProcessing2LDJ20200721View::OnHomogenOperator()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessing2LDJ20200721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnHomogenOperator();
	Invalidate(TRUE);

}


void CImageProcessing2LDJ20200721View::OnLaplacian()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessing2LDJ20200721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnLaplacian();
	Invalidate(TRUE);
}


void CImageProcessing2LDJ20200721View::OnNearest()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessing2LDJ20200721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnNearest();
	Invalidate(TRUE);

}


void CImageProcessing2LDJ20200721View::OnBilinear()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessing2LDJ20200721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnBilinear();
	Invalidate(TRUE);

}


void CImageProcessing2LDJ20200721View::OnMediansub()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessing2LDJ20200721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnMediansub();
	Invalidate(TRUE);
}


void CImageProcessing2LDJ20200721View::OnMeansub()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessing2LDJ20200721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnMeansub();
	Invalidate(TRUE);
}


void CImageProcessing2LDJ20200721View::OnTranslation()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessing2LDJ20200721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnTranslation();
	Invalidate(TRUE);
}


void CImageProcessing2LDJ20200721View::OnMirrorhor()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessing2LDJ20200721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnMirrorhor();
	Invalidate(TRUE);
}


void CImageProcessing2LDJ20200721View::OnMirrorver()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessing2LDJ20200721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnMirrorver();
	Invalidate(TRUE);
}


void CImageProcessing2LDJ20200721View::OnRotation()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessing2LDJ20200721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnRotation();
	Invalidate(TRUE);
}


void CImageProcessing2LDJ20200721View::OnMask()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다CImageProcessing2LDJ20200721
	CImageProcessing2LDJ20200721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnMask();
	Invalidate(TRUE);
}


void CImageProcessing2LDJ20200721View::OnComb()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessing2LDJ20200721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnComb();
	Invalidate(TRUE);


}

