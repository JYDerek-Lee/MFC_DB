
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
	ON_COMMAND(ID_RECORD_FIRST, &CAssignment2View::OnRecordFirst)
	ON_COMMAND(ID_RECORD_LAST, &CAssignment2View::OnRecordLast)
	ON_COMMAND(ID_RECORD_NEXT, &CAssignment2View::OnRecordNext)
	ON_COMMAND(ID_RECORD_PREV, &CAssignment2View::OnRecordPrev)
END_MESSAGE_MAP()

// CAssignment2View ����/�Ҹ�

CAssignment2View::CAssignment2View()
	: CRecordView(CAssignment2View::IDD)
{
	m_pSet = NULL;
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	currentPos = 1;
	recordCount = 0;
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

	DDX_Control(pDX, IDC_LIST1, m_List);

	DDX_Control(pDX, IDC_EDIT_NAME, m_EditName);
	DDX_Control(pDX, IDC_EDIT_EMAIL, m_EidtMail);
	DDX_Control(pDX, IDC_EDIT_PHONE, m_EditPhone);
	DDX_Control(pDX, IDC_EDIT_COMPANY, m_EditCompany);
	DDX_Control(pDX, IDC_EDIT_GROUP, m_EditGroup);

	DDX_Control(pDX, IDC_BUTTON_TOTAL, m_ButtonTotal);
	DDX_Control(pDX, IDC_BUTTON_ADD, m_ButtonAdd);
	DDX_Control(pDX, IDC_BUTTON_UPDATE, m_ButtonMod);
	DDX_Control(pDX, IDC_BUTTON_DELETE, m_ButtonDel);
	DDX_Control(pDX, IDC_BUTTON_SEARCH, m_ButtonSearch);

	// ��Ʈ���� ������ ���̽� �ʵ忡 ����
	DDX_FieldText(pDX, IDC_EDIT_NAME, m_pSet->m_name, m_pSet);
	DDX_FieldText(pDX, IDC_EDIT_EMAIL, m_pSet->m_email, m_pSet);
	DDX_FieldText(pDX, IDC_EDIT_PHONE, m_pSet->m_phone, m_pSet);
	DDX_FieldText(pDX, IDC_EDIT_COMPANY, m_pSet->m_company, m_pSet);
	DDX_FieldText(pDX, IDC_EDIT_GROUP, m_pSet->m_group, m_pSet);

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

	AddColumn();
	SetImageList();
	AddAllRecord();
	GetTotalRecordCount();
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
void CAssignment2View::AddColumn() {
	CRect rect;
	// ����Ʈ ��Ʈ���� ũ�⸦ ���´�.
	m_List.GetClientRect(&rect);
	// �÷��߰�
	m_List.InsertColumn(0, _T("�̸�"), LVCFMT_RIGHT, 100);
	m_List.InsertColumn(1, _T("�̸��� ����"), LVCFMT_LEFT, rect.Width() - 400);
	m_List.InsertColumn(2, _T("��ȭ��ȣ"), LVCFMT_LEFT, 100);
	m_List.InsertColumn(3, _T("�����"), LVCFMT_LEFT, 100);
	m_List.InsertColumn(4, _T("�׷�"), LVCFMT_LEFT, 100);
}


void CAssignment2View::SetImageList() {
	m_LargeImageList.Create(IDB_BITMAP_LARGE, 48, 1, RGB(0, 0, 0));
	m_SmallImageList.Create(IDB_BITMAP_SMALL, 16, 1, RGB(0, 0, 0));
	m_List.SetImageList(&m_LargeImageList, LVSIL_NORMAL);
	m_List.SetImageList(&m_SmallImageList, LVSIL_SMALL);
}


void CAssignment2View::AddAllRecord() {
	int i = 0;
	CString strTemp;
	
	CAssignment2Set rsSet(m_pSet->m_pDatabase);
	rsSet.Open(CRecordset::dynaset, _T("select * from address"));
	m_List.DeleteAllItems();

	while (rsSet.IsEOF() == FALSE) {
		strTemp.Format(_T("%4d"), rsSet.m_ID);
		m_List.InsertItem(i, strTemp, 0);
		m_List.SetItemText(i, 1, rsSet.m_name);
		m_List.SetItemText(i, 2, rsSet.m_email);
		m_List.SetItemText(i, 3, rsSet.m_phone);
		m_List.SetItemText(i, 4, rsSet.m_company);
		m_List.SetItemText(i, 5, rsSet.m_group);

		//strTemp.Format(_T("%4ld"), rsSet.m_price);
		//m_List.SetItemText(i, 3, strTemp);
		rsSet.MoveNext();
		i++;
	}
	rsSet.Close();
}



void CAssignment2View::GetTotalRecordCount() {
	CRecordset cntSet(m_pSet->m_pDatabase); 
	cntSet.Open(CRecordset::dynaset, _T("select count(*) from address")); // ��ü ���ڵ��� ������ ���� 
	CString strCount; 
	cntSet.GetFieldValue((short)0,strCount); 
	recordCount = atoi((char *)(const wchar_t *)strCount); 
	cntSet.Close();
}


void CAssignment2View::OnRecordFirst() {
	if (recordCount == 0) return; 
	currentPos = 1; // ���� ��ġ���� 1�� ���� 
	m_pSet->MoveFirst(); // ù ��° ���ڵ�� �̵� 
	UpdateData(FALSE); // Recordset ���� ���� ��Ʈ�ѿ� ���
}


void CAssignment2View::OnRecordLast() {
	if (recordCount == 0) return; 
	currentPos = recordCount; // ���� ��ġ ���� ��ü ���ڵ� �� ���� 
	m_pSet->MoveLast(); // ������ ���ڵ�� �̵� 
	UpdateData(FALSE);
}


void CAssignment2View::OnRecordNext() {
	if (recordCount == 0)return;
	currentPos++; // ���� ��ġ ���� 1������Ŵ
	m_pSet->MoveNext(); // ���� ���ڵ� ��ġ�� �̵�
	if (m_pSet->IsEOF()) {
		m_pSet->MoveLast();
		currentPos--;
	}
	UpdateData(FALSE);
}


void CAssignment2View::OnRecordPrev() {
	if (recordCount == 0) return;
	currentPos--; // ���� ��ġ ���� 1���ҽ�Ŵ
	m_pSet->MovePrev(); // ���� ���ڵ� ��ġ�� �̵�
	if (m_pSet->IsBOF()) {
		m_pSet->MoveFirst();
		currentPos = 1;
	}
	UpdateData(FALSE); // Recordset ���� ���� ��Ʈ�ѿ� ���
}
