// AttackDLL.h : AttackDLL DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CAttackDLLApp
// �йش���ʵ�ֵ���Ϣ������� AttackDLL.cpp
//

class CAttackDLLApp : public CWinApp
{
public:
	CAttackDLLApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};