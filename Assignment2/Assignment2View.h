
// Assignment2View.h : CAssignment2View 클래스의 인터페이스
//

#pragma once
#include "afxcmn.h"
#include "afxwin.h"

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
public:
	CImageList m_LargeImageList;
	CImageList m_SmallImageList;

	CListCtrl m_List;

	CEdit m_EditName;
	CEdit m_EidtMail;
	CEdit m_EditPhone;
	CEdit m_EditCompany;
	CEdit m_EditGroup;

	CButton m_ButtonTotal;
	CButton m_ButtonAdd;
	CButton m_ButtonMod;
	CButton m_ButtonDel;
	CButton m_ButtonSearch;

	int currentPos;
	int recordCount;

	BOOL bAdd;
	BOOL bUpdate;
	BOOL bSearch;

	void AddColumn();
	void SetImageList();
	void AddAllRecord();
	void GetTotalRecordCount();
	afx_msg void OnRecordFirst();
	afx_msg void OnRecordLast();
	afx_msg void OnRecordNext();
	afx_msg void OnRecordPrev();

	void Init();
	void Clear();
	afx_msg void OnBnClickedButtonTotal();
	afx_msg void OnBnClickedButtonAdd();
	afx_msg void OnBnClickedButtonUpdate();
	afx_msg void OnBnClickedButtonDelete();
	afx_msg void OnBnClickedButtonSearch();
	afx_msg void OnBnClickedButtonCancel();
	afx_msg void OnIcon();
	afx_msg void OnSmallIcon();
	afx_msg void OnList();
	afx_msg void OnReport();
	afx_msg void OnLbnSelchangeList2();
	CListBox m_List2;
	afx_msg void OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult);
};

#ifndef _DEBUG  // Assignment2View.cpp의 디버그 버전
inline CAssignment2Doc* CAssignment2View::GetDocument() const
   { return reinterpret_cast<CAssignment2Doc*>(m_pDocument); }
#endif

