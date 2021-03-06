// App.cpp : Defines the entry point for the application.
//
#include "stdafx.h"
#include "resource.h"
#include "MainWnd.h"


//#include <windows.h>
//#include <objbase.h>
//#include <shellapi.h>
//#include "QMFileSqlite.h"
//#include "RegUserInfo.h"
//#include "log.h"
//#include "SettingConfig.h"
//
//#include "THFaceImage_i.h"
//#include "THFeature_i.h"
#include "AppInitialize.h"
#include <Poco/Logger.h>

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE /*hPrevInstance*/, LPSTR /*lpCmdLine*/, int nCmdShow)
{
	CPaintManagerUI::SetInstance(hInstance);
	CPaintManagerUI::SetResourcePath(CPaintManagerUI::GetInstancePath() + _T("skin"));

	CAppInitialize  initial;
	
	/*HRESULT Hr = ::CoInitialize(NULL);
	if (FAILED(Hr)) return 0;*/

	Poco::Logger::get("FileLogger").information("Start App message");

	std::auto_ptr<CMainWnd> pFrame(new CMainWnd);
	assert(pFrame.get());
	pFrame->Create(NULL, NULL, UI_WNDSTYLE_DIALOG, WS_EX_WINDOWEDGE | WS_EX_ACCEPTFILES);
	pFrame->SetIcon(IDI_ICON1);
	pFrame->CenterWindow();
	pFrame->ShowWindow(true);

	CPaintManagerUI::MessageLoop();

	//::CoUninitialize();

	return 0;
}