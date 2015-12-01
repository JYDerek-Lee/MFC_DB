
// Assignment2Set.h: CAssignment2Set Ŭ������ �������̽�
//


#pragma once

// �ڵ� ���� ��ġ 2015�� 12�� 1�� ȭ����, ���� 6:57

class CAssignment2Set : public CRecordset
{
public:
	CAssignment2Set(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CAssignment2Set)

// �ʵ�/�Ű� ���� ������

// �Ʒ��� ���ڿ� ����(���� ���)�� �����ͺ��̽� �ʵ��� ���� ������ ������
// ��Ÿ���ϴ�(CStringA:
ANSI ������ ����, CStringW: �����ڵ� ������ ����).
// �̰��� ODBC ����̹����� ���ʿ��� ��ȯ�� ������ �� ������ �մϴ�.  // ���� ��� �̵� ����� CString �������� ��ȯ�� �� ������
// �׷� ��� ODBC ����̹����� ��� �ʿ��� ��ȯ�� �����մϴ�.
// (����: �����ڵ�� �̵� ��ȯ�� ��� �����Ϸ���  ODBC ����̹�
// ���� 3.5 �̻��� ����ؾ� �մϴ�).

	long	m_ID;	//�̸� ��ȣ
	CStringW	m_name;	//�̸�
	CStringW	m_email;	//�̸��� ����
	CStringW	m_phone;	//��ȭ��ȣ
	CStringW	m_company;	//�����
	CStringW	m_group;	//( ���� / ���� / �б� / ģ�� / ��Ÿ ) �� �ϳ�

// ������
	// �����翡�� ������ ���� �Լ� ������
	public:
	virtual CString GetDefaultConnect();	// �⺻ ���� ���ڿ�

	virtual CString GetDefaultSQL(); 	// ���ڵ� ������ �⺻ SQL
	virtual void DoFieldExchange(CFieldExchange* pFX);	// RFX ����

// ����
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

};

