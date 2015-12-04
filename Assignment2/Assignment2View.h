
// Assignment2View.h : CAssignment2View Ŭ������ �������̽�
//

#pragma once
#include "afxcmn.h"
#include "afxwin.h"

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

#ifndef _DEBUG  // Assignment2View.cpp�� ����� ����
inline CAssignment2Doc* CAssignment2View::GetDocument() const
   { return reinterpret_cast<CAssignment2Doc*>(m_pDocument); }
#endif

