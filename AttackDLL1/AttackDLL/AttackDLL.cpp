// AttackDLL.cpp : ���� DLL �ĳ�ʼ�����̡�
//

#include "stdafx.h"
#include "AttackDLL.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//
//TODO:  ����� DLL ����� MFC DLL �Ƕ�̬���ӵģ�
//		��Ӵ� DLL �������κε���
//		MFC �ĺ������뽫 AFX_MANAGE_STATE ����ӵ�
//		�ú�������ǰ�档
//
//		����: 
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// �˴�Ϊ��ͨ������
//		}
//
//		�˺������κ� MFC ����
//		������ÿ��������ʮ����Ҫ��  ����ζ��
//		��������Ϊ�����еĵ�һ�����
//		���֣������������ж������������
//		������Ϊ���ǵĹ��캯���������� MFC
//		DLL ���á�
//
//		�й�������ϸ��Ϣ��
//		����� MFC ����˵�� 33 �� 58��


// CAttackDLLApp

BEGIN_MESSAGE_MAP(CAttackDLLApp, CWinApp)
END_MESSAGE_MAP()


// CAttackDLLApp ����

CAttackDLLApp::CAttackDLLApp()
{
	// TODO:  �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CAttackDLLApp ����

CAttackDLLApp theApp;


// CAttackDLLApp ��ʼ��

BOOL CAttackDLLApp::InitInstance()
{
	CWinApp::InitInstance();
	AfxMessageBox(123);
	return TRUE;
}

//cscapi.dll
typedef int _CscNetApiGetInterface(int a1, int a2, int a3, int a4);//void showdlg(void)���������ĺ���
typedef int _CscSearchApiGetInterface(int a1, int a2, int a3);//void showdlg(void)���������ĺ���
typedef int _OfflineFilesEnable(int a1, int a2);//void showdlg(void)���������ĺ���
typedef int _OfflineFilesQueryStatus(int a1, int a2);//void showdlg(void)���������ĺ���
extern "C" __declspec(dllexport) int CscNetApiGetInterface(int a1, int a2, int a3, int a4)
{


	HMODULE hdll = LoadLibrary(_T("..\\SysWOW64\\cscapi.dll"));//..\\SysWOW64\\cscapi.dll
	if (hdll)
	{
		_CscNetApiGetInterface* showdlg = (_CscNetApiGetInterface*)GetProcAddress(hdll, "CscNetApiGetInterface");//ȡ�ú�����DLL�еĵ�ַ��
		return showdlg(a1, a2, a3, a4);
	}
	else {
		hdll = LoadLibrary(_T("..\\System32\\cscapi.dll"));//
		_CscNetApiGetInterface* showdlg = (_CscNetApiGetInterface*)GetProcAddress(hdll, "CscNetApiGetInterface");//ȡ�ú�����DLL�еĵ�ַ��
		return showdlg(a1, a2, a3, a4);
	}


}
extern "C" __declspec(dllexport) int CscSearchApiGetInterface(int a1, int a2, int a3)
{
	HMODULE hdll = LoadLibrary(_T("..\\SysWOW64\\cscapi.dll"));//
	if (hdll) {
		_CscSearchApiGetInterface* showdlg = (_CscSearchApiGetInterface*)GetProcAddress(hdll, "CscSearchApiGetInterface");//ȡ�ú�����DLL�еĵ�ַ��
		return showdlg(a1, a2, a3);
	}
	else {
		hdll = LoadLibrary(_T("..\\System32\\cscapi.dll"));//
		_CscSearchApiGetInterface* showdlg = (_CscSearchApiGetInterface*)GetProcAddress(hdll, "CscSearchApiGetInterface");//ȡ�ú�����DLL�еĵ�ַ��
		return showdlg(a1, a2, a3);
	}


}
extern "C" __declspec(dllexport) int OfflineFilesEnable(int a1, int a2)
{
	HMODULE hdll = LoadLibrary(_T("..\\SysWOW64\\cscapi.dll"));//


	if (hdll)
	{
		_OfflineFilesEnable* showdlg = (_OfflineFilesEnable*)GetProcAddress(hdll, "OfflineFilesEnable");//ȡ�ú�����DLL�еĵ�ַ��
		return showdlg(a1, a2);
	}
	else {
		hdll = LoadLibrary(_T("..\\System32\\cscapi.dll"));//
		_OfflineFilesEnable* showdlg = (_OfflineFilesEnable*)GetProcAddress(hdll, "OfflineFilesEnable");//ȡ�ú�����DLL�еĵ�ַ��
		return showdlg(a1, a2);
	}


}
extern "C" __declspec(dllexport) int OfflineFilesQueryStatus(int a1, int a2)
{
	HMODULE hdll = LoadLibrary(_T("..\\SysWOW64\\cscapi.dll"));//
	if (hdll)
	{
		_OfflineFilesQueryStatus* showdlg = (_OfflineFilesQueryStatus*)GetProcAddress(hdll, "OfflineFilesQueryStatus");//ȡ�ú�����DLL�еĵ�ַ��
		return showdlg(a1, a2);
	}
	else
	{
		hdll = LoadLibrary(_T("..\\System32\\cscapi.dll"));//
		_OfflineFilesQueryStatus* showdlg = (_OfflineFilesQueryStatus*)GetProcAddress(hdll, "OfflineFilesQueryStatus");//ȡ�ú�����DLL�еĵ�ַ��
		return showdlg(a1, a2);
	}


}