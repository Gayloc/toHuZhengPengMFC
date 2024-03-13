
// toHuZhengPengMFCDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "toHuZhengPengMFC.h"
#include "toHuZhengPengMFCDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CtoHuZhengPengMFCDlg 对话框



CtoHuZhengPengMFCDlg::CtoHuZhengPengMFCDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TOHUZHENGPENGMFC_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON1);
}

void CtoHuZhengPengMFCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_PICTURE, m_PictureControl);
	//  DDX_Control(pDX, IDC_STATIC_TEXT, m_TextControl);
}

BEGIN_MESSAGE_MAP(CtoHuZhengPengMFCDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDCANCEL, &CtoHuZhengPengMFCDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDOK, &CtoHuZhengPengMFCDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CtoHuZhengPengMFCDlg 消息处理程序

BOOL CtoHuZhengPengMFCDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CtoHuZhengPengMFCDlg::OnPaint()
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
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CtoHuZhengPengMFCDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CtoHuZhengPengMFCDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}

void CtoHuZhengPengMFCDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_PictureControl.ShowWindow(SW_SHOW)) {
		CDialog::OnOK();
	}
	//CDialogEx::OnOK();
}
