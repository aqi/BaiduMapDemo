// GpsDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "TestBaiDuMap.h"
#include "GpsDlg.h"


// CGpsDlg �Ի���

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


// CGpsDlg ��Ϣ�������

void CGpsDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString strLng(_T("")), strLat(_T("")), strTime(_T(""));
	GetDlgItem(IDC_EDIT_LNG)->GetWindowText(strLng);
	GetDlgItem(IDC_EDIT_LAT)->GetWindowText(strLat);
	GetDlgItem(IDC_EDIT_TIME)->GetWindowText(strTime);
	*m_lng = _tstof(strLng.GetString());
	*m_lat = _tstof(strLat.GetString());
	_tcscat_s(m_time, 256, strTime.GetString());
	OnOK();
}
