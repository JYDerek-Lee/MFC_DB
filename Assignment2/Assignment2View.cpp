
// Assignment2View.cpp : CAssignment2View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
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
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CRecordView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CAssignment2View 생성/소멸

CAssignment2View::CAssignment2View()
	: CRecordView(CAssignment2View::IDD)
{
	m_pSet = NULL;
	// TODO: 여기에 생성 코드를 추가합니다.

}

CAssignment2View::~CAssignment2View()
{
}

void CAssignment2View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 컨트롤을 데이터베이스 필드에 '연결'하기 위해 여기에 DDX_Field* 함수를 삽입할 수 있습니다. 예:
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 자세한 내용은 MSDN 및 ODBC 샘플을 참조하십시오.

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

	// 컨트롤을 데이터 베이스 필드에 연결
	DDX_FieldText(pDX, IDC_EDIT_NAME, m_pSet->m_name, m_pSet);
	DDX_FieldText(pDX, IDC_EDIT_EMAIL, m_pSet->m_email, m_pSet);
	DDX_FieldText(pDX, IDC_EDIT_PHONE, m_pSet->m_phone, m_pSet);
	DDX_FieldText(pDX, IDC_EDIT_COMPANY, m_pSet->m_company, m_pSet);
	DDX_FieldText(pDX, IDC_EDIT_GROUP, m_pSet->m_group, m_pSet);

}

BOOL CAssignment2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CRecordView::PreCreateWindow(cs);
}

void CAssignment2View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_Assignment2Set;
	CRecordView::OnInitialUpdate();

	AddColumn();
	SetImageList();
	AddAllRecord();

}


// CAssignment2View 인쇄

BOOL CAssignment2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CAssignment2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CAssignment2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CAssignment2View 진단

#ifdef _DEBUG
void CAssignment2View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CAssignment2View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CAssignment2Doc* CAssignment2View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CAssignment2Doc)));
	return (CAssignment2Doc*)m_pDocument;
}
#endif //_DEBUG


// CAssignment2View 데이터베이스 지원
CRecordset* CAssignment2View::OnGetRecordset()
{
	return m_pSet;
}



// CAssignment2View 메시지 처리기
void CAssignment2View::AddColumn() {
	CRect rect;
	// 리스트 컨트롤의 크기를 얻어온다.
	m_List.GetClientRect(&rect);
	// 컬럼추가
	m_List.InsertColumn(0, _T("이름"), LVCFMT_RIGHT, 100);
	m_List.InsertColumn(1, _T("이메일 계정"), LVCFMT_LEFT, rect.Width() - 400);
	m_List.InsertColumn(2, _T("전화번호"), LVCFMT_LEFT, 100);
	m_List.InsertColumn(3, _T("직장명"), LVCFMT_LEFT, 100);
	m_List.InsertColumn(4, _T("그룹"), LVCFMT_LEFT, 100);
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

