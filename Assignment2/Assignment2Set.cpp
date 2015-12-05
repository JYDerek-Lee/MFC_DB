
// Assignment2Set.cpp : CAssignment2Set 클래스의 구현
//

#include "stdafx.h"
#include "Assignment2.h"
#include "Assignment2Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAssignment2Set 구현

// 코드 생성 위치 2015년 12월 1일 화요일, 오후 6:57

IMPLEMENT_DYNAMIC(CAssignment2Set, CRecordset)

CAssignment2Set::CAssignment2Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ID = 0;
	m_name = L"";
	m_email = L"";
	m_phone = L"";
	m_company = L"";
	m_groups = L"";
	m_nFields = 6;
	m_nDefaultType = dynaset;
}
//#error 보안 문제: 연결 문자열에 암호가 포함되어 있을 수 있습니다.
// 아래 연결 문자열에 일반 텍스트 암호 및/또는 
// 다른 중요한 정보가 포함되어 있을 수 있습니다.
// 보안 관련 문제가 있는지 연결 문자열을 검토한 후에 #error을(를) 제거하십시오.
// 다른 형식으로 암호를 저장하거나 다른 사용자 인증을 사용하십시오.
CString CAssignment2Set::GetDefaultConnect()
{
	return _T("DSN=addressDSN;DBQ=C:\\address.mdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString CAssignment2Set::GetDefaultSQL()
{
	return _T("[address]");
}

void CAssignment2Set::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() 및 RFX_Int() 같은 매크로는 데이터베이스의 필드
// 형식이 아니라 멤버 변수의 형식에 따라 달라집니다.
// ODBC에서는 자동으로 열 값을 요청된 형식으로 변환하려고 합니다
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[name]"), m_name);
	RFX_Text(pFX, _T("[email]"), m_email);
	RFX_Text(pFX, _T("[phone]"), m_phone);
	RFX_Text(pFX, _T("[company]"), m_company);
	RFX_Text(pFX, _T("[groups]"), m_groups);

}
/////////////////////////////////////////////////////////////////////////////
// CAssignment2Set 진단

#ifdef _DEBUG
void CAssignment2Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void CAssignment2Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

