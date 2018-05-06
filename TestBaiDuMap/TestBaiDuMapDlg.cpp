// TestBaiDuMapDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "TestBaiDuMap.h"
#include "TestBaiDuMapDlg.h"
#include "WebPage.h"
#include "GpsDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


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


// CTestBaiDuMapDlg 对话框




CTestBaiDuMapDlg::CTestBaiDuMapDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTestBaiDuMapDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTestBaiDuMapDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EXPLORER_MAP, m_myWeb);
	DDX_Control(pDX, IDC_LIST_GPS, m_listGps);
}

BEGIN_MESSAGE_MAP(CTestBaiDuMapDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDOK, &CTestBaiDuMapDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CTestBaiDuMapDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BUTTON_REFRESH, &CTestBaiDuMapDlg::OnBnClickedButtonRefresh)
	ON_NOTIFY(NM_RCLICK, IDC_LIST_GPS, &CTestBaiDuMapDlg::OnNMRClickListGps)
	ON_COMMAND(ID_MENU_ADD, &CTestBaiDuMapDlg::OnMenuAdd)
	ON_COMMAND(ID_MENU_INSERT, &CTestBaiDuMapDlg::OnMenuInsert)
	ON_COMMAND(ID_MENU_DEL, &CTestBaiDuMapDlg::OnMenuDel)
	ON_BN_CLICKED(IDC_BUTTON_IMPORT, &CTestBaiDuMapDlg::OnBnClickedButtonImport)
END_MESSAGE_MAP()


// CTestBaiDuMapDlg 消息处理程序

BOOL CTestBaiDuMapDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	int width = GetSystemMetrics(SM_CXFULLSCREEN);
	int height = GetSystemMetrics(SM_CYFULLSCREEN);
	CRect rect(0, 0, width, height);
	SetWindowPos(NULL, 0, 0, rect.Width(), rect.Height(), SWP_NOZORDER);
	m_myWeb.SetWindowPos(NULL, 0, 0, rect.Width() - 300, rect.Height(), SWP_NOZORDER );
	GetDlgItem(IDC_BUTTON_IMPORT)->SetWindowPos(NULL, rect.Width() - 290, 10, 0, 0, SWP_NOZORDER | SWP_NOSIZE);
	//GetDlgItem(IDC_EDIT_WD)->SetWindowPos(NULL, rect.Width() - 290, 40, 0, 0, SWP_NOZORDER | SWP_NOSIZE);
	GetDlgItem(IDC_LIST_GPS)->SetWindowPos(NULL, rect.Width() - 290, 50, 280, rect.Height() - 140, SWP_NOZORDER);
	GetDlgItem(IDOK)->SetWindowPos(NULL, rect.Width() - 200, rect.Height() - 70, 0, 0, SWP_NOZORDER | SWP_NOSIZE);
	GetDlgItem(IDCANCEL)->SetWindowPos(NULL, rect.Width() - 110, rect.Height() - 70, 0, 0, SWP_NOZORDER | SWP_NOSIZE);
	GetDlgItem(IDC_BUTTON_REFRESH)->SetWindowPos(NULL, rect.Width() - 290, rect.Height() - 70, 0, 0, SWP_NOZORDER | SWP_NOSIZE);
	CRect listRect;
	m_listGps.SetExtendedStyle(m_listGps.GetExtendedStyle() | LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);
	m_listGps.GetClientRect(listRect);
	m_listGps.InsertColumn(0, "经度");
	m_listGps.InsertColumn(1, "维度");
	m_listGps.InsertColumn(2, "时间");
	m_listGps.SetColumnWidth(0, listRect.Width() / 3 - 5);    
	m_listGps.SetColumnWidth(1, listRect.Width() / 3 - 5);
	m_listGps.SetColumnWidth(2, listRect.Width() / 3);
	m_myWeb.Init();
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CTestBaiDuMapDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CTestBaiDuMapDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CTestBaiDuMapDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CTestBaiDuMapDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	for (int i = 0; i < m_listGps.GetItemCount(); ++i)
	{
		CString strLng = m_listGps.GetItemText(i, 0);
		CString strLat = m_listGps.GetItemText(i, 1);
		double lng = _tstof(strLng.GetString());
		double lat = _tstof(strLat.GetString());
		m_myWeb.PutPiont(lng, lat);
	}
}

void CTestBaiDuMapDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	//m_myWeb.Refresh();
	OnCancel();
}
BEGIN_EVENTSINK_MAP(CTestBaiDuMapDlg, CDialog)
	ON_EVENT(CTestBaiDuMapDlg, IDC_EXPLORER_MAP, 104, CTestBaiDuMapDlg::DownloadCompleteExplorerMap, VTS_NONE)
END_EVENTSINK_MAP()

void CTestBaiDuMapDlg::DownloadCompleteExplorerMap()
{
	// TODO: 在此处添加消息处理程序代码
	//OnBnClickedOk();
}

void CTestBaiDuMapDlg::OnBnClickedButtonRefresh()
{
	// TODO: 在此添加控件通知处理程序代码
	m_myWeb.Refresh();
}

void CTestBaiDuMapDlg::OnNMRClickListGps(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码

	//if (pNMItemActivate->iItem != -1)  
	{  
		DWORD dwPos = GetMessagePos();  
		CPoint point(LOWORD(dwPos), HIWORD(dwPos));  
		CMenu menu;  
		//添加线程操作  
		VERIFY(menu.LoadMenu(IDR_MENU_LISTGPS));           //这里是我们在1中定义的MENU的文件名称  
		CMenu* popup = menu.GetSubMenu(0);  

		popup->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x, point.y, this);  

 
	}  

	*pResult = 0;
}

void CTestBaiDuMapDlg::OnMenuAdd()
{
	// TODO: 在此添加命令处理程序代码
	POSITION pstion = m_listGps.GetFirstSelectedItemPosition();  
	int nIndex = m_listGps.GetNextSelectedItem(pstion); 
	double lng = 0.0f, lat = 0.0f;
	TCHAR time[256] = { 0 };
	CGpsDlg dlg(&lng, &lat, time);

	if (IDOK == dlg.DoModal())
	{
		CString strLng(_T("")), strLat(_T(""));
		strLng.Format(_T("%f"), lng);
		strLat.Format(_T("%f"), lat);
		
		int ni = m_listGps.InsertItem(nIndex == -1 ? m_listGps.GetItemCount() + 1 : nIndex + 1, strLng.GetString());
		m_listGps.SetItemText(ni, 1, strLat.GetString());
		m_listGps.SetItemText(ni, 2, time);

	}
}

void CTestBaiDuMapDlg::OnMenuInsert()
{
	// TODO: 在此添加命令处理程序代码
	POSITION pstion = m_listGps.GetFirstSelectedItemPosition();  
	int nIndex = m_listGps.GetNextSelectedItem(pstion); 
	double lng = 0.0f, lat = 0.0f;
	TCHAR time[256] = { 0 };
	CGpsDlg dlg(&lng, &lat, time);

	if (IDOK == dlg.DoModal())
	{
		CString strLng(_T("")), strLat(_T(""));
		strLng.Format(_T("%f"), lng);
		strLat.Format(_T("%f"), lat);

		int ni = m_listGps.InsertItem(nIndex == -1 ? 0 : nIndex, strLng.GetString());
		m_listGps.SetItemText(ni, 1, strLat.GetString());
		m_listGps.SetItemText(ni, 2, time);

	}
}

void CTestBaiDuMapDlg::OnMenuDel()
{
	// TODO: 在此添加命令处理程序代码
	POSITION pstion = m_listGps.GetFirstSelectedItemPosition();  
	int nIndex = m_listGps.GetNextSelectedItem(pstion); 
	if (nIndex != -1)
	{
		m_listGps.DeleteItem(nIndex);
	}
}

void CTestBaiDuMapDlg::OnBnClickedButtonImport()
{
	// TODO: 在此添加控件通知处理程序代码
	double lng = 123.442518;
	double lat = 41.825545;
	CTime time = CTime::GetCurrentTime();
	for (int i = 0; i < 100; ++i)
	{
		CTimeSpan ts(0, 0, 1,0);
		time += ts;
		CString strTime(time.Format(_T("%Y-%m-%d %H:%M:%S")));
		int ran = rand() % 10;
		double dran = ran / 10.0f;
		lng -= dran;
		lat -= dran;
		CString strLng(_T("")), strLat(_T(""));
		strLng.Format(_T("%.6f"), lng);
		strLat.Format(_T("%.6f"), lat);
		m_listGps.InsertItem(i, strLng.GetString());
		m_listGps.SetItemText(i, 1, strLat.GetString());
		m_listGps.SetItemText(i, 2, strTime.GetString());

	}


}
