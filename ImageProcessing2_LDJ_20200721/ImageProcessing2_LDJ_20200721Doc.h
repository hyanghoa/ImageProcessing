
// ImageProcessing2_LDJ_20200721Doc.h: CImageProcessing2LDJ20200721Doc 클래스의 인터페이스
//


#pragma once


class CImageProcessing2LDJ20200721Doc : public CDocument
{
protected: // serialization에서만 만들어집니다.
	CImageProcessing2LDJ20200721Doc() noexcept;
	DECLARE_DYNCREATE(CImageProcessing2LDJ20200721Doc)

// 특성입니다.
public:

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 구현입니다.
public:
	BITMAPFILEHEADER dibHf;    // 비트맵 파일헤드 구조체
	BITMAPINFOHEADER dibHi;    // 비트맵 영상헤드 구조체
	RGBQUAD palRGB[256];        // 팔레트 정보 구조체 배열
	virtual ~CImageProcessing2LDJ20200721Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 검색 처리기에 대한 검색 콘텐츠를 설정하는 도우미 함수
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	virtual BOOL OnSaveDocument(LPCTSTR lpszPathName);
	unsigned char* m_InputImage;
	int m_width;
	int m_height;
	int m_size;
	afx_msg void OnDownSampling();
	unsigned char* m_OutputImage;
	unsigned char* m_OutputImage_left;
	unsigned char* m_OutputImage_right;
	int m_Re_width;
	int m_Re_height;
	int m_Re_size;
	afx_msg void OnUpSampling();
	double m_HIST[256];
	double m_Sum_Of_HIST[256];
	unsigned char m_Scale_HIST[256];
	double** m_tempImage;

	afx_msg void OnQuantization();
//	afx_msg void OnConst();
//	afx_msg void OnSumConst();
//	afx_msg void OnSubconst();
	afx_msg void OnSumConst();
	afx_msg void OnSubConst();
	afx_msg void OnMulConst();
	afx_msg void OnDivConst();
	afx_msg void OnAndOperate();
	afx_msg void OnOrOperate();
	afx_msg void OnXorOperate();
	afx_msg void OnNegaTransform();
	afx_msg void OnGammaCorrection();
//	afx_msg void OnBinaryzation();
	afx_msg void OnBinarization();
	afx_msg void OnRangeOfStress();
	afx_msg void OnHistStretch();
	afx_msg void OnEndInSearch();
	afx_msg void OnHistogram();
	afx_msg void OnHistoEqual();
	afx_msg void OnHistoSpec();
//	afx_msg void OnEmbossing();
	afx_msg void OnEmbossing();
//	afx_msg void OnMaskProcess();
	double** OnMaskProcess(unsigned char* Target, double Mask[3][3]);
	double** OnScale(double** Target, int height, int width);
	double** Image2DMem(int height, int width);
	afx_msg void OnBlurr();
	afx_msg void OnGaussianFilter();
//	afx_msg void OnSharpning();
	afx_msg void OnHpfSharpening();
	afx_msg void OnSharpening();
	afx_msg void OnLpfsharpening();
	afx_msg void OnDiffOperatorHor();
	afx_msg void OnHomogenOperator();
	double DoubleABS(double X);
	afx_msg void OnLaplacian();
	afx_msg void OnNearest();
	afx_msg void OnBilinear();
	afx_msg void OnMediansub();
	void OnBubleSort(double* A, int MAX);
	void OnSwap(double* a, double* b);
	afx_msg void OnMeansub();
	afx_msg void OnTranslation();
	afx_msg void OnMirrorhor();
	afx_msg void OnMirrorver();
	afx_msg void OnRotation();
	afx_msg void OnMask();
	void OnComb();
	
};
