
// Assignment2View.h : CAssignment2View 클래스의 인터페이스
//

#pragma once

class CAssignment2Set;

class CAssignment2View : public CRecordView
{
protected: // serialization에서만 만들어집니다.
	CAssignment2View();
	DECLARE_DYNCREATE(CAssignment2View)

public:
	enum{ IDD = IDD_ASSIGNMENT2_FORM };
	CAssignment2Set* m_pSet;

// 특성입니다.
public:
	CAssignment2Doc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.
	virtual void OnInitialUpdate(); // 생성 후 처음 호출되었습니다.
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CAssignment2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // Assignment2View.cpp의 디버그 버전
inline CAssignment2Doc* CAssignment2View::GetDocument() const
   { return reinterpret_cast<CAssignment2Doc*>(m_pDocument); }
#endif

