
// Assignment2Doc.h : CAssignment2Doc Ŭ������ �������̽�
//


#pragma once
#include "Assignment2Set.h"


class CAssignment2Doc : public CDocument
{
protected: // serialization������ ��������ϴ�.
	CAssignment2Doc();
	DECLARE_DYNCREATE(CAssignment2Doc)

// Ư���Դϴ�.
public:
	CAssignment2Set m_Assignment2Set;

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual BOOL OnNewDocument();
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// �����Դϴ�.
public:
	virtual ~CAssignment2Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// �˻� ó���⿡ ���� �˻� �������� �����ϴ� ����� �Լ�
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
