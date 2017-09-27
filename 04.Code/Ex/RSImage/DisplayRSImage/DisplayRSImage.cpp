// DisplayRSImage.cpp : 定义应用程序的类行为。
//

#include "stdafx.h"
#include "DisplayRSImage.h"
#include "MainFrm.h"

#include "DisplayRSImageDoc.h"
#include "DisplayRSImageView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDisplayRSImageApp

BEGIN_MESSAGE_MAP(CDisplayRSImageApp, CWinApp)
	ON_COMMAND(ID_APP_ABOUT, &CDisplayRSImageApp::OnAppAbout)
	// 基于文件的标准文档命令
	ON_COMMAND(ID_FILE_NEW, &CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, &CDisplayRSImageApp::OnFileOpen)	//映射打开菜单的消息处理函数
	// 标准打印设置命令
	ON_COMMAND(ID_FILE_PRINT_SETUP, &CWinApp::OnFilePrintSetup)
END_MESSAGE_MAP()


// CDisplayRSImageApp 构造

CDisplayRSImageApp::CDisplayRSImageApp()
{
	// TODO: 在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}


// 唯一的一个 CDisplayRSImageApp 对象

CDisplayRSImageApp theApp;


// CDisplayRSImageApp 初始化

BOOL CDisplayRSImageApp::InitInstance()
{
	// 如果一个运行在 Windows XP 上的应用程序清单指定要
	// 使用 ComCtl32.dll 版本 6 或更高版本来启用可视化方式，
	//则需要 InitCommonControlsEx()。否则，将无法创建窗口。
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// 将它设置为包括所有要在应用程序中使用的
	// 公共控件类。
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();

	// 初始化 OLE 库
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}
	AfxEnableControlContainer();
	// 标准初始化
	// 如果未使用这些功能并希望减小
	// 最终可执行文件的大小，则应移除下列
	// 不需要的特定初始化例程
	// 更改用于存储设置的注册表项
	// TODO: 应适当修改该字符串，
	// 例如修改为公司或组织名
	SetRegistryKey(_T("应用程序向导生成的本地应用程序"));
	LoadStdProfileSettings(4);  // 加载标准 INI 文件选项(包括 MRU)
	// 注册应用程序的文档模板。文档模板
	// 将用作文档、框架窗口和视图之间的连接
	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(CDisplayRSImageDoc),
		RUNTIME_CLASS(CMainFrame),       // 主 SDI 框架窗口
		RUNTIME_CLASS(CDisplayRSImageView));
	if (!pDocTemplate)
		return FALSE;
	AddDocTemplate(pDocTemplate);

	// GDAL 使用的声明
	GDALAllRegister();

	// 分析标准外壳命令、DDE、打开文件操作的命令行
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);


	// 调度在命令行中指定的命令。如果
	// 用 /RegServer、/Register、/Unregserver 或 /Unregister 启动应用程序，则返回 FALSE。
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

	// 唯一的一个窗口已初始化，因此显示它并对其进行更新
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();
	// 仅当具有后缀时才调用 DragAcceptFiles
	//  在 SDI 应用程序中，这应在 ProcessShellCommand  之后发生
	return TRUE;
}

//-----------------------------------------------//
// 打开文件的消息处理函数
//-----------------------------------------------//
void CDisplayRSImageApp::OnFileOpen()
{
	/*	代码分析
	->1. CWinApp::OnFileOpen(); 
	ENSURE(m_pDocManager != NULL);
	m_pDocManager->OnFileOpen();

	->2.CDocManager::OnFileOpen();
	[打开文件对话框]
	// prompt the user (with all document templates)
	CString newName;
	if (!DoPromptFileName(newName, AFX_IDS_OPENFILE,
		OFN_HIDEREADONLY | OFN_FILEMUSTEXIST, TRUE, NULL))
		return; // open cancelled
	
	[调用OpenDocumentFile]
	AfxGetApp()->OpenDocumentFile(newName);
	// if returns NULL, the user has already been alerted
	*/

	//-------------------------------------------------------------//
	// 改写打开文件对话框
	CFileDialog dlgFile(TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, NULL, NULL, 0);

	dlgFile.m_ofn.lpstrFilter = "影像文件(*.tif;*.img;*.pix;*.jpg;*.bmp;*.png)\0*.tif;*.img;*.pix;*.jpg;*.bmp;*.png\0所有文件(*.*)\0*.*\0";
	dlgFile.m_ofn.lpstrTitle = _T("打开遥感影像文件...");

	if (dlgFile.DoModal() == IDOK)
	{
		OpenDocumentFile(dlgFile.GetPathName());	// 打开文档
	}

//	CWinApp::OnFileOpen();
}



// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()

// 用于运行对话框的应用程序命令
void CDisplayRSImageApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}


// CDisplayRSImageApp 消息处理程序

