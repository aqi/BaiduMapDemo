// TestBaiDuMapDlg.h : ͷ�ļ�
//

#pragma once
#include "webbrowser2.h"
#include "afxcmn.h"


// CTestBaiDuMapDlg �Ի���
class CTestBaiDuMapDlg : public CDialog
{
// ����
public:
	CTestBaiDuMapDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_TESTBAIDUMAP_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
