// GpsDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "TestBaiDuMap.h"
#include "GpsDlg.h"


// CGpsDlg 对话框

IMPLEMENT_DYNAMIC(CGpsDlg, CDialog)

CGpsDlg::CGpsDlg(double* lng, double* lat, TCHAR* time, CWnd* pParent)
: CDialog(CGpsDlg::IDD, pParent),
m_lng(lng),
m_lat(lat),
m_time(time)
{

}

CGpsDlg::~CGpsDlg()
{
}

void CGpsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CGpsDlg, CDialog)
	ON_BN_CLICKED(IDOK, &CGpsDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CGpsDlg 消息处理程序

void CGpsDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CString strLng(_T("")), strLat(_T("")), strTime(_T(""));
	GetDlgItem(IDC_EDIT_LNG)->GetWindowText(strLng);
	GetDlgItem(IDC_EDIT_LAT)->GetWindowText(strLat);
	GetDlgItem(IDC_EDIT_TIME)->GetWindowText(strTime);
	*m_lng = _tstof(strLng.GetString());
	*m_lat = _tstof(strLat.GetString());
	_tcscat_s(m_time, 256, strTime.GetString());
	OnOK();
}
