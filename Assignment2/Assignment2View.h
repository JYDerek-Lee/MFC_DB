
// Assignment2View.h : CAssignment2View Ŭ������ �������̽�
//

#pragma once

class CAssignment2Set;

class CAssignment2View : public CRecordView
{
protected: // serialization������ ��������ϴ�.
	CAssignment2View();
	DECLARE_DYNCREATE(CAssignment2View)

public:
	enum{ IDD = IDD_ASSIGNMENT2_FORM };
	CAssignment2Set* m_pSet;

// Ư���Դϴ�.
public:
	CAssignment2Doc* GetDocument() const;

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.
	virtual void OnInitialUpdate(); // ���� �� ó�� ȣ��Ǿ����ϴ�.
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// �����Դϴ�.
public:
	virtual ~CAssignment2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // Assignment2View.cpp�� ����� ����
inline CAssignment2Doc* CAssignment2View::GetDocument() const
   { return reinterpret_cast<CAssignment2Doc*>(m_pDocument); }
#endif

