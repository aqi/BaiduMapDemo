// TestBaiDuMapDlg.h : 头文件
//

#pragma once
#include "webbrowser2.h"
#include "afxcmn.h"


// CTestBaiDuMapDlg 对话框
class CTestBaiDuMapDlg : public CDialog
{
// 构造
public:
	CTestBaiDuMapDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_TESTBAIDUMAP_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	CWebBrowser2 m_myWeb;
	afx_msg void OnBnClickedCancel();
	DECLARE_EVENTSINK_MAP()
	void DownloadCompleteExplorerMap();
	afx_msg void OnBnClickedButtonRefresh();
	CListCtrl m_listGps;
	afx_msg void OnNMRClickListGps(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnMenuAdd();
	afx_msg void OnMenuInsert();
	afx_msg void OnMenuDel();
	afx_msg void OnBnClickedButtonImport();
};
