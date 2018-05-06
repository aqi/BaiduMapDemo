#pragma once


// CGpsDlg 对话框

class CGpsDlg : public CDialog
{
	DECLARE_DYNAMIC(CGpsDlg)

public:
	CGpsDlg(double* lng, double* lat, TCHAR* time, CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CGpsDlg();

// 对话框数据
	enum { IDD = IDD_DIALOG_GPS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
private:
	double* m_lng;
	double* m_lat;
	TCHAR* m_time;
};
