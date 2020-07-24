
// ImageProcessing2_LDJ_20200721View.h: CImageProcessing2LDJ20200721View 클래스의 인터페이스
//

#pragma once


class CImageProcessing2LDJ20200721View : public CView
{
protected: // serialization에서만 만들어집니다.
	CImageProcessing2LDJ20200721View() noexcept;
	DECLARE_DYNCREATE(CImageProcessing2LDJ20200721View)

// 특성입니다.
public:
	CImageProcessing2LDJ20200721Doc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CImageProcessing2LDJ20200721View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDownSample();
	afx_msg void OnUpSample();
	afx_msg void OnQuantization();
	afx_msg void OnConst();
	afx_msg void OnSubconst();
	afx_msg void OnMulconst();
	afx_msg void OnDivconst();
	afx_msg void OnAndOperate();
	afx_msg void OnOrOperate();
	afx_msg void OnXorOperate();
	afx_msg void OnNegaTransform();
	afx_msg void OnGammaCorrection();
	//afx_msg void OnBinaryzation();
	afx_msg void OnBinarization();
	afx_msg void OnRangeOfStress();
	afx_msg void OnHistStretch();
	afx_msg void OnEndInSearch();
	afx_msg void OnHistogram();
	afx_msg void OnHistoEqual();
	afx_msg void OnHistoSpec();
//	afx_msg void OnEmbossing();
//	afx_msg void OnEmbossingOnmaskprocess();
//	afx_msg void OnMaskProcess();
	afx_msg void OnEmbossing();
	afx_msg void OnBlurr();
	afx_msg void OnGaussianFilter();
//	afx_msg void OnSharpning();
	afx_msg void OnHpfSharpening();
	afx_msg void OnSharpening();
	afx_msg void OnLpfsharpening();
	afx_msg void OnDiffOperatorHor();
	afx_msg void OnHomogenOperator();
	afx_msg void OnLaplacian();
	afx_msg void OnNearest();
	afx_msg void OnBilinear();
	afx_msg void OnMediansub();
	afx_msg void OnMeansub();
	afx_msg void OnTranslation();
	afx_msg void OnMirrorhor();
	afx_msg void OnMirrorver();
	afx_msg void OnRotation();
	afx_msg void OnMask();
};

#ifndef _DEBUG  // ImageProcessing2_LDJ_20200721View.cpp의 디버그 버전
inline CImageProcessing2LDJ20200721Doc* CImageProcessing2LDJ20200721View::GetDocument() const
   { return reinterpret_cast<CImageProcessing2LDJ20200721Doc*>(m_pDocument); }
#endif

