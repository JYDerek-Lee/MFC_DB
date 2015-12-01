
// Assignment2View.cpp : CAssignment2View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "Assignment2.h"
#endif

#include "Assignment2Set.h"
#include "Assignment2Doc.h"
#include "Assignment2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAssignment2View

IMPLEMENT_DYNCREATE(CAssignment2View, CRecordView)

BEGIN_MESSAGE_MAP(CAssignment2View, CRecordView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CRecordView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CAssignment2View ����/�Ҹ�

CAssignment2View::CAssignment2View()
	: CRecordView(CAssignment2View::IDD)
{
	m_pSet = NULL;
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CAssignment2View::~CAssignment2View()
{
}

void CAssignment2View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// ��Ʈ���� �����ͺ��̽� �ʵ忡 '����'�ϱ� ���� ���⿡ DDX_Field* �Լ��� ������ �� �ֽ��ϴ�. ��:
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// �ڼ��� ������ MSDN �� ODBC ������ �����Ͻʽÿ�.
}

BOOL CAssignment2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CRecordView::PreCreateWindow(cs);
}

void CAssignment2View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_Assignment2Set;
	CRecordView::OnInitialUpdate();

}


// CAssignment2View �μ�

BOOL CAssignment2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CAssignment2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CAssignment2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}


// CAssignment2View ����

#ifdef _DEBUG
void CAssignment2View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CAssignment2View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CAssignment2Doc* CAssignment2View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CAssignment2Doc)));
	return (CAssignment2Doc*)m_pDocument;
}
#endif //_DEBUG


// CAssignment2View �����ͺ��̽� ����
CRecordset* CAssignment2View::OnGetRecordset()
{
	return m_pSet;
}



// CAssignment2View �޽��� ó����
