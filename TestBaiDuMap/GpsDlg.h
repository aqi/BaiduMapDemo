#pragma once


// CGpsDlg �Ի���

class CGpsDlg : public CDialog
{
	DECLARE_DYNAMIC(CGpsDlg)

public:
	CGpsDlg(double* lng, double* lat, TCHAR* time, CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CGpsDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG_GPS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
private:
	double* m_lng;
	double* m_lat;
	TCHAR* m_time;
};
