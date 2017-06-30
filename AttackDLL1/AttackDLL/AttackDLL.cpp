// AttackDLL.cpp : 定义 DLL 的初始化例程。
//

#include "stdafx.h"
#include "AttackDLL.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//
//TODO:  如果此 DLL 相对于 MFC DLL 是动态链接的，
//		则从此 DLL 导出的任何调入
//		MFC 的函数必须将 AFX_MANAGE_STATE 宏添加到
//		该函数的最前面。
//
//		例如: 
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// 此处为普通函数体
//		}
//
//		此宏先于任何 MFC 调用
//		出现在每个函数中十分重要。  这意味着
//		它必须作为函数中的第一个语句
//		出现，甚至先于所有对象变量声明，
//		这是因为它们的构造函数可能生成 MFC
//		DLL 调用。
//
//		有关其他详细信息，
//		请参阅 MFC 技术说明 33 和 58。


// CAttackDLLApp

BEGIN_MESSAGE_MAP(CAttackDLLApp, CWinApp)
END_MESSAGE_MAP()


// CAttackDLLApp 构造

CAttackDLLApp::CAttackDLLApp()
{
	// TODO:  在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}


// 唯一的一个 CAttackDLLApp 对象

CAttackDLLApp theApp;


// CAttackDLLApp 初始化

BOOL CAttackDLLApp::InitInstance()
{
	CWinApp::InitInstance();
	AfxMessageBox(123);
	return TRUE;
}

//cscapi.dll
typedef int _CscNetApiGetInterface(int a1, int a2, int a3, int a4);//void showdlg(void)包含导出的函数
typedef int _CscSearchApiGetInterface(int a1, int a2, int a3);//void showdlg(void)包含导出的函数
typedef int _OfflineFilesEnable(int a1, int a2);//void showdlg(void)包含导出的函数
typedef int _OfflineFilesQueryStatus(int a1, int a2);//void showdlg(void)包含导出的函数
extern "C" __declspec(dllexport) int CscNetApiGetInterface(int a1, int a2, int a3, int a4)
{


	HMODULE hdll = LoadLibrary(_T("..\\SysWOW64\\cscapi.dll"));//..\\SysWOW64\\cscapi.dll
	if (hdll)
	{
		_CscNetApiGetInterface* showdlg = (_CscNetApiGetInterface*)GetProcAddress(hdll, "CscNetApiGetInterface");//取得函数在DLL中的地址；
		return showdlg(a1, a2, a3, a4);
	}
	else {
		hdll = LoadLibrary(_T("..\\System32\\cscapi.dll"));//
		_CscNetApiGetInterface* showdlg = (_CscNetApiGetInterface*)GetProcAddress(hdll, "CscNetApiGetInterface");//取得函数在DLL中的地址；
		return showdlg(a1, a2, a3, a4);
	}


}
extern "C" __declspec(dllexport) int CscSearchApiGetInterface(int a1, int a2, int a3)
{
	HMODULE hdll = LoadLibrary(_T("..\\SysWOW64\\cscapi.dll"));//
	if (hdll) {
		_CscSearchApiGetInterface* showdlg = (_CscSearchApiGetInterface*)GetProcAddress(hdll, "CscSearchApiGetInterface");//取得函数在DLL中的地址；
		return showdlg(a1, a2, a3);
	}
	else {
		hdll = LoadLibrary(_T("..\\System32\\cscapi.dll"));//
		_CscSearchApiGetInterface* showdlg = (_CscSearchApiGetInterface*)GetProcAddress(hdll, "CscSearchApiGetInterface");//取得函数在DLL中的地址；
		return showdlg(a1, a2, a3);
	}


}
extern "C" __declspec(dllexport) int OfflineFilesEnable(int a1, int a2)
{
	HMODULE hdll = LoadLibrary(_T("..\\SysWOW64\\cscapi.dll"));//


	if (hdll)
	{
		_OfflineFilesEnable* showdlg = (_OfflineFilesEnable*)GetProcAddress(hdll, "OfflineFilesEnable");//取得函数在DLL中的地址；
		return showdlg(a1, a2);
	}
	else {
		hdll = LoadLibrary(_T("..\\System32\\cscapi.dll"));//
		_OfflineFilesEnable* showdlg = (_OfflineFilesEnable*)GetProcAddress(hdll, "OfflineFilesEnable");//取得函数在DLL中的地址；
		return showdlg(a1, a2);
	}


}
extern "C" __declspec(dllexport) int OfflineFilesQueryStatus(int a1, int a2)
{
	HMODULE hdll = LoadLibrary(_T("..\\SysWOW64\\cscapi.dll"));//
	if (hdll)
	{
		_OfflineFilesQueryStatus* showdlg = (_OfflineFilesQueryStatus*)GetProcAddress(hdll, "OfflineFilesQueryStatus");//取得函数在DLL中的地址；
		return showdlg(a1, a2);
	}
	else
	{
		hdll = LoadLibrary(_T("..\\System32\\cscapi.dll"));//
		_OfflineFilesQueryStatus* showdlg = (_OfflineFilesQueryStatus*)GetProcAddress(hdll, "OfflineFilesQueryStatus");//取得函数在DLL中的地址；
		return showdlg(a1, a2);
	}


}