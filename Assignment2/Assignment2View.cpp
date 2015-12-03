
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
	ON_BN_CLICKED(IDC_BUTTON_TOTAL, &CAssignment2View::OnBnClickedButtonTotal)
	ON_BN_CLICKED(IDC_BUTTON_ADD, &CAssignment2View::OnBnClickedButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_UPDATE, &CAssignment2View::OnBnClickedButtonUpdate)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, &CAssignment2View::OnBnClickedButtonDelete)
	ON_BN_CLICKED(IDC_BUTTON_SEARCH, &CAssignment2View::OnBnClickedButtonSearch)
	ON_BN_CLICKED(IDC_BUTTON_CANcEL, &CAssignment2View::OnBnClickedButtonCancel)
	ON_COMMAND(ID_ICON, &CAssignment2View::OnIcon)
	ON_COMMAND(ID_SMALL_ICON, &CAssignment2View::OnSmallIcon)
	ON_COMMAND(ID_LIST, &CAssignment2View::OnList)
	ON_COMMAND(ID_REPORT, &CAssignment2View::OnReport)
	ON_LBN_SELCHANGE(IDC_LIST2, &CAssignment2View::OnLbnSelchangeList2)
END_MESSAGE_MAP()

// CAssignment2View ����/�Ҹ�

CAssignment2View::CAssignment2View()
	: CRecordView(CAssignment2View::IDD)
{
	m_pSet = NULL;
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	currentPos = 1;
	recordCount = 0;

	bAdd = FALSE;
	bUpdate = FALSE;
	bSearch = FALSE;
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
	DDX_FieldText(pDX, IDC_EDIT_GROUP, m_pSet->m_groups, m_pSet);

	DDX_Control(pDX, IDC_LIST2, m_List2);
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

	m_List2.AddString(_T("����"));
	m_List2.AddString(_T("����"));
	m_List2.AddString(_T("�б�"));
	m_List2.AddString(_T("ģ��"));
	m_List2.AddString(_T("��Ÿ"));

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
	//m_List.InsertColumn(0, _T("��ȣ"), LVCFMT_RIGHT, 100);
	m_List.InsertColumn(0, _T("�̸�"), LVCFMT_RIGHT, 100);
	m_List.InsertColumn(1, _T("�̸��� ����"), LVCFMT_RIGHT, rect.Width() - 400);
	m_List.InsertColumn(2, _T("��ȭ��ȣ"), LVCFMT_RIGHT, 100);
	m_List.InsertColumn(3, _T("�����"), LVCFMT_RIGHT, 100);
	m_List.InsertColumn(4, _T("�׷�"), LVCFMT_RIGHT, 100);
}


void CAssignment2View::SetImageList() {
	m_LargeImageList.Create(IDB_BITMAP_LARGE, 48, 1, RGB(255, 255, 255));
	m_SmallImageList.Create(IDB_BITMAP_SMALL, 16, 1, RGB(255, 255, 255));
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
		//strTemp.Format(_T("%4d"), rsSet.m_ID);
		//m_List.InsertItem(i, strTemp, 0);
		//m_List.SetItemText(i, 1, rsSet.m_name);

		m_List.InsertItem(i, rsSet.m_name, 0);
		m_List.SetItemText(i, 1, rsSet.m_email);
		m_List.SetItemText(i, 2, rsSet.m_phone);
		m_List.SetItemText(i, 3, rsSet.m_company);
		m_List.SetItemText(i, 4, rsSet.m_groups);

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


void CAssignment2View::Init() {
	// ����Ʈ ��Ʈ���� �Է� �Ұ����� ���·� ����
	m_EditName.EnableWindow(0);
	m_EidtMail.EnableWindow(0);
	m_EditPhone.EnableWindow(0);
	m_EditCompany.EnableWindow(0);
	m_EditGroup.EnableWindow(0);

	// ��ư�� ���� ������ ���·� ����
	m_ButtonTotal.EnableWindow(1);
	m_ButtonAdd.EnableWindow(1);
	m_ButtonMod.EnableWindow(1);
	m_ButtonSearch.EnableWindow(1);
	m_ButtonDel.EnableWindow(1);
}


void CAssignment2View::Clear() {
	// ����Ʈ ��Ʈ���� �Է� ������ ���·� ����
	m_EditName.EnableWindow(1);
	m_EidtMail.EnableWindow(1);
	m_EditPhone.EnableWindow(1);
	m_EditCompany.EnableWindow(1);
	m_EditGroup.EnableWindow(1);

	// ��ư�� ���� �Ұ����� ���·� ����
	m_ButtonTotal.EnableWindow(0);
	m_ButtonAdd.EnableWindow(0);
	m_ButtonMod.EnableWindow(0);
	m_ButtonSearch.EnableWindow(0);
	m_ButtonDel.EnableWindow(0);
}


void CAssignment2View::OnBnClickedButtonTotal() {
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	Init();
	AddAllRecord();
}


void CAssignment2View::OnBnClickedButtonAdd() {
	bAdd = !bAdd; 
	if (bAdd == TRUE) { // �߰� �غ� 
		m_pSet->AddNew(); // �� ���ڵ� �߰� 
		m_pSet->SetFieldNull(NULL); // �ʱ�ȭ 
		UpdateData(FALSE); 
		Clear(); 
		m_ButtonAdd.EnableWindow(1); 
		m_EditName.SetFocus();
	} 
	else { //��� 
		UpdateData(TRUE); // ����Ʈ ��Ʈ��->Recordset ���� 
		m_pSet->Update(); // DB ���� 
		m_pSet->Requery(); // DB ���� 

		m_pSet->MoveLast(); 
		GetTotalRecordCount(); // ������ ���� ���� 
		UpdateData(FALSE); 
		Init(); 
		AddAllRecord();
	}
}


void CAssignment2View::OnBnClickedButtonUpdate() {
	bUpdate = !bUpdate;
	if (bUpdate == TRUE) { //���� �غ�
		//���� ���ڵ� ��ġ�� �̵�
		m_pSet->SetAbsolutePosition(currentPos);
		UpdateData(FALSE);
		Clear();
		m_ButtonMod.EnableWindow(1);
	}
	else { // ����
		m_pSet->Edit(); // �������� ����...
		UpdateData(TRUE); // ��Ʈ��->���ڵ� �� ������ ����
		m_pSet->Update(); // DB ����...
		m_pSet->Requery(); // DB ���ų��� ��������
		m_pSet->SetAbsolutePosition(currentPos);
		UpdateData(FALSE);
		Init();
		AddAllRecord();
	}
}


void CAssignment2View::OnBnClickedButtonDelete() {
	if (recordCount == 0) {
		MessageBox(_T("������ �����Ͱ� �����ϴ�!"));
		return;
	}
	m_pSet->Delete(); // ����
	m_pSet->Requery(); // ����
	GetTotalRecordCount();
	if (recordCount == 0) // �����Ͱ� �������� ������..
	{
		m_pSet->SetFieldNull(NULL);
		UpdateData(FALSE);
		currentPos = 0;
		return;
	}
	if (recordCount < currentPos) // ������ ������ ������
		currentPos--; // current_pos = record_count;
	m_pSet->SetAbsolutePosition(currentPos);
	UpdateData(FALSE);
	AddAllRecord();
}


void CAssignment2View::OnBnClickedButtonSearch() {
	bSearch = !bSearch; 
	if (bSearch) { //�˻� �غ� 
		m_EditName.SetWindowTextW(_T(""));
		m_EidtMail.SetWindowTextW(_T(""));
		m_EditPhone.SetWindowTextW(_T(""));
		m_EditCompany.SetWindowTextW(_T(""));
		m_EditGroup.SetWindowTextW(_T(""));
		Clear();

		m_EidtMail.EnableWindow(0);
		m_EditPhone.EnableWindow(0);
		m_EditCompany.EnableWindow(0);
		m_EditGroup.EnableWindow(0);
		m_ButtonSearch.EnableWindow(1);
		m_EditName.SetFocus(); 
	} 
	else { //�˻� 
		UpdateData(TRUE); 
		m_pSet->m_strFilter.Format(_T("name like '%%%s%%'"), m_pSet->m_name);
		if (m_pSet->m_name.IsEmpty() == false) {
			int i = 0;
			m_pSet->Requery(); m_pSet->m_strFilter.Empty();
			m_List.DeleteAllItems();

			while (m_pSet->IsEOF() == FALSE) {
				m_List.InsertItem(i, m_pSet->m_name, 0);
				m_List.SetItemText(i, 1, m_pSet->m_email);
				m_List.SetItemText(i, 2, m_pSet->m_phone);
				m_List.SetItemText(i, 3, m_pSet->m_company);
				m_List.SetItemText(i, 4, m_pSet->m_groups);
				m_pSet->MoveNext(); 
				i++;
			}
			// rsSet.Close();
			Init();
		}
	}
}


void CAssignment2View::OnBnClickedButtonCancel() {
	if (bAdd) { // ���, bAdd: �߰� ���θ� �Ǵ�
		//���� ���ڵ� ��ġ�� �̵�
		m_pSet->SetAbsolutePosition(currentPos);
		UpdateData(FALSE);
		bAdd = FALSE; //�ʱ���·� ����
	}
	if (bUpdate) { //bUpdate: ���� ���θ� �Ǵ�
		//���� ���ڵ� ��ġ�� �̵�
		m_pSet->SetAbsolutePosition(currentPos);
		UpdateData(FALSE);
		bUpdate = FALSE; //�ʱ���·� ����
	}
	if (bSearch) {
		//���� ���ڵ� ��ġ�� �̵�
		m_pSet->SetAbsolutePosition(currentPos);
		UpdateData(FALSE);
		bSearch = FALSE; //�ʱ���·� ����
	}
	Init();
}


void CAssignment2View::OnIcon() {
	m_List.ModifyStyle(LVS_TYPEMASK, LVS_ICON);
	//AddColumn();
	//SetImageList();
	//AddAllRecord();
	//GetTotalRecordCount();
}


void CAssignment2View::OnSmallIcon() {
	m_List.ModifyStyle(LVS_TYPEMASK, LVS_SMALLICON);
}


void CAssignment2View::OnList() {
	m_List.ModifyStyle(LVS_TYPEMASK, LVS_LIST);
}


void CAssignment2View::OnReport() {
	m_List.ModifyStyle(LVS_TYPEMASK, LVS_REPORT);
}


void CAssignment2View::OnLbnSelchangeList2() {
	CString Item;
	int nIndex = m_List2.GetCurSel();

	if (nIndex != LB_ERR) m_List2.GetText(nIndex, Item);

	UpdateData(TRUE);
	m_pSet->m_strFilter.Format(_T("groups like '%%%s%%'"), Item);
	//m_pSet->m_strFilter.Format(_T("group like '%s'"), Item);
	if (m_pSet->m_groups.IsEmpty() == false) {
		int i = 0;
		m_pSet->Requery(); 
		m_pSet->m_strFilter.Empty();
		m_List.DeleteAllItems();

		while (m_pSet->IsEOF() == FALSE) {
			m_List.InsertItem(i, m_pSet->m_name, 0);
			m_List.SetItemText(i, 1, m_pSet->m_email);
			m_List.SetItemText(i, 2, m_pSet->m_phone);
			m_List.SetItemText(i, 3, m_pSet->m_company);
			m_List.SetItemText(i, 4, m_pSet->m_groups);
			m_pSet->MoveNext();
			i++;
		}
		//Init();
	}
}
