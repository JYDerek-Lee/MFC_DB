
// Assignment2Set.cpp : CAssignment2Set Ŭ������ ����
//

#include "stdafx.h"
#include "Assignment2.h"
#include "Assignment2Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAssignment2Set ����

// �ڵ� ���� ��ġ 2015�� 12�� 1�� ȭ����, ���� 6:57

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
//#error ���� ����: ���� ���ڿ��� ��ȣ�� ���ԵǾ� ���� �� �ֽ��ϴ�.
// �Ʒ� ���� ���ڿ��� �Ϲ� �ؽ�Ʈ ��ȣ ��/�Ǵ� 
// �ٸ� �߿��� ������ ���ԵǾ� ���� �� �ֽ��ϴ�.
// ���� ���� ������ �ִ��� ���� ���ڿ��� ������ �Ŀ� #error��(��) �����Ͻʽÿ�.
// �ٸ� �������� ��ȣ�� �����ϰų� �ٸ� ����� ������ ����Ͻʽÿ�.
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
// RFX_Text() �� RFX_Int() ���� ��ũ�δ� �����ͺ��̽��� �ʵ�
// ������ �ƴ϶� ��� ������ ���Ŀ� ���� �޶����ϴ�.
// ODBC������ �ڵ����� �� ���� ��û�� �������� ��ȯ�Ϸ��� �մϴ�
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[name]"), m_name);
	RFX_Text(pFX, _T("[email]"), m_email);
	RFX_Text(pFX, _T("[phone]"), m_phone);
	RFX_Text(pFX, _T("[company]"), m_company);
	RFX_Text(pFX, _T("[groups]"), m_groups);

}
/////////////////////////////////////////////////////////////////////////////
// CAssignment2Set ����

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

