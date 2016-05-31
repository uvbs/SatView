// DIALOGS.H : Dialogs Related Interface Declaration.
//
// This is a part of the SatView(TM) spacecraft operating system.
// Copyrightę 1992-2016 by BINARY SPACE, Switzerland.
// All rights reserved.
//
// This source code contains the dialogs related interface declaration
// and macros.
//
/**********************************************************************
* Modifications:                                                     *
*====================================================================*
* Date       | Release | Comments                                    *
*------------|---------|---------------------------------------------*
* 2012/08/29 | 1.00.00 | Initial creation. [AW]                      *
**********************************************************************/

#ifndef __DIALOGS_H__
#define __DIALOGS_H__


/////////////////////////////////////////////////////////////////////////////
// CDatabaseTablesDialog dialog

class CDatabaseTablesDialog : public CLocaleDialog
{
	DECLARE_DYNCREATE(CDatabaseTablesDialog)

	// Construction
public:
	CDatabaseTablesDialog(CDatabaseEngine *pDatabaseEngine = NULL);

	// Attributes
private:
	CDatabaseEngine  *m_pDatabaseEngine;

	// Operations
public:
	BOOL ShowMessage(CONST EVENT_DESCRIPTOR nMessageID);
	BOOL ShowHelp(LPCTSTR pszTopic);

protected:
	HGLOBAL LoadLocaleDialogTemplate(UINT nDialogID) CONST;
	HGLOBAL LoadLocaleDialogTemplate(LPCTSTR pszDialogName) CONST;

	// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDatabaseTablesDialog)
protected:
	virtual void DoDataExchange(CDataExchange *pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

	// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDatabaseTablesDialog)
	// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
// CDatabaseTablesImportDialog dialog

#define IDC_DATABASE_TABLES_IMPORT_DETAILS   1001
#define IDC_DATABASE_TABLES_IMPORT_FILENAME_STATIC   1002
#define IDC_DATABASE_TABLES_IMPORT_FILENAME   1003
#define IDC_DATABASE_TABLES_IMPORT_BROWSE   1004
#define IDC_DATABASE_TABLES_IMPORT_DIRECTORY   1005
#define IDC_DATABASE_TABLES_IMPORT_TYPE   1006
#define IDC_DATABASE_TABLES_IMPORT_TYPE_DEFAULT   1007
#define IDC_DATABASE_TABLES_IMPORT_TYPE_CUSTOM   1008
#define IDC_DATABASE_TABLES_IMPORT_TYPE_CUSTOM_NAME   1009
#define IDC_DATABASE_TABLES_IMPORT_TYPE_CUSTOM_NAME_STATIC   1010
#define IDC_DATABASE_TABLES_IMPORT_TYPE_CUSTOM_DESCRIPTION_STATIC   1011
#define IDC_DATABASE_TABLES_IMPORT_TYPE_CUSTOM_DESCRIPTION    1012
#define IDC_DATABASE_TABLES_IMPORT_HELP   1013

class CDatabaseTablesImportDialog : public CDatabaseTablesDialog
{
	DECLARE_DYNCREATE(CDatabaseTablesImportDialog)

	// Construction
public:
	CDatabaseTablesImportDialog(CWnd *pParentWnd = NULL, CDatabaseEngine *pDatabaseEngine = NULL);   // standard constructor

	// Attributes
private:
	ULONGLONG  m_nComponent;
	CDatabaseTCPackets  m_pDatabaseTCPackets[2];
	CDatabaseTMNumCalTables  m_pDatabaseTMNumCalTables[2];
	CDatabaseTMTxtCalTables  m_pDatabaseTMTxtCalTables[2];
	CDatabaseTMNumOolTables  m_pDatabaseTMNumOolTables[2];
	CDatabaseTMTxtOolTables  m_pDatabaseTMTxtOolTables[2];
	CDatabaseTCNumCalTables  m_pDatabaseTCNumCalTables[2];
	CDatabaseTCTxtCalTables  m_pDatabaseTCTxtCalTables[2];
	CDatabaseTCNumOolTables  m_pDatabaseTCNumOolTables[2];
	CDatabaseTCTxtOolTables  m_pDatabaseTCTxtOolTables[2];
	CDatabaseTCPreExeGroups  m_pDatabaseTCPreExeGroups[2];
	CDatabaseTCExeVerGroups  m_pDatabaseTCExeVerGroups[2];
	CDatabaseTMPacketHeaders  m_pDatabaseTMPacketHeaders[2];
	CDatabaseTMPacketStreams  m_pDatabaseTMPacketStreams[2];
	CDatabaseTCParameterSets  m_pDatabaseTCParameterSets[2];
	CDatabaseTCFunctionBlocks  m_pDatabaseTCFunctionBlocks[2];
	CDatabaseOBProcessorMemoryImages  m_pDatabaseOBProcessorMemoryImages[2];
private:
	CStringArray  m_szColumns;

	// Dialog Data
	//{{AFX_DATA(CDatabaseTablesImportDialog)
	enum { IDD = IDD_DATABASE_TABLES_IMPORT_DIALOG };
	// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// Operations
private:
	VOID EnumDatabaseTables();

	VOID EnumTCPackets(CONST CByteArray &nData);
	VOID EnumTMNumCalTables(CONST CByteArray &nData);
	VOID EnumTMTxtCalTables(CONST CByteArray &nData);
	VOID EnumTMNumOolTables(CONST CByteArray &nData);
	VOID EnumTMTxtOolTables(CONST CByteArray &nData);
	VOID EnumTCNumCalTables(CONST CByteArray &nData);
	VOID EnumTCTxtCalTables(CONST CByteArray &nData);
	VOID EnumTCNumOolTables(CONST CByteArray &nData);
	VOID EnumTCTxtOolTables(CONST CByteArray &nData);
	VOID EnumTCPreExeGroups(CONST CByteArray &nData);
	VOID EnumTCExeVerGroups(CONST CByteArray &nData);
	VOID EnumTMPacketHeaders(CONST CByteArray &nData);
	VOID EnumTMPacketStreams(CONST CByteArray &nData);
	VOID EnumTCParameterSets(CONST CByteArray &nData);
	VOID EnumTCFunctionBlocks(CONST CByteArray &nData);
	VOID EnumOBProcessorMemoryImages(CONST CByteArray &nData);

	// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDatabaseTablesImportDialog)
public:
	virtual INT_PTR DoModal(CDatabaseTCPackets &pDatabaseTCPackets);
	virtual INT_PTR DoModal(CDatabaseTMNumCalTables &pDatabaseTMNumCalTables);
	virtual INT_PTR DoModal(CDatabaseTMTxtCalTables &pDatabaseTMTxtCalTables);
	virtual INT_PTR DoModal(CDatabaseTMNumOolTables &pDatabaseTMNumOolTables);
	virtual INT_PTR DoModal(CDatabaseTMTxtOolTables &pDatabaseTMTxtOolTables);
	virtual INT_PTR DoModal(CDatabaseTCNumCalTables &pDatabaseTCNumCalTables);
	virtual INT_PTR DoModal(CDatabaseTCTxtCalTables &pDatabaseTCTxtCalTables);
	virtual INT_PTR DoModal(CDatabaseTCNumOolTables &pDatabaseTCNumOolTables);
	virtual INT_PTR DoModal(CDatabaseTCTxtOolTables &pDatabaseTCTxtOolTables);
	virtual INT_PTR DoModal(CDatabaseTCPreExeGroups &pDatabaseTCPreExeGroups);
	virtual INT_PTR DoModal(CDatabaseTCExeVerGroups &pDatabaseTCExeVerGroups);
	virtual INT_PTR DoModal(CDatabaseTMPacketHeaders &pDatabaseTMPacketHeaders);
	virtual INT_PTR DoModal(CDatabaseTMPacketStreams &pDatabaseTMPacketStreams);
	virtual INT_PTR DoModal(CDatabaseTCParameterSets &pDatabaseTCParameterSets);
	virtual INT_PTR DoModal(CDatabaseTCFunctionBlocks &pDatabaseTCFunctionBlocks);
	virtual INT_PTR DoModal(CDatabaseOBProcessorMemoryImages &pDatabaseOBProcessorMemoryImages);
	virtual BOOL Check(BOOL bModified = TRUE) CONST;
protected:
	virtual void DoDataExchange(CDataExchange *pDX);    // DDX/DDV support
	virtual BOOL OnNotify(WPARAM wParam, LPARAM lParam, LRESULT *pResult);
	virtual void PostNcDestroy();
	//}}AFX_VIRTUAL

	// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDatabaseTablesImportDialog)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnBrowse();
	afx_msg void OnDefault();
	afx_msg void OnCustom();
	afx_msg void OnEditchangeFileName();
	afx_msg void OnEditchangeName();
	afx_msg void OnEditchangeDescription();
	afx_msg BOOL OnHelpInfo(HELPINFO *pHelpInfo);
	afx_msg void OnHelp();
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
// CDatabaseTablesExportDialog dialog

#define IDC_DATABASE_TABLES_EXPORT_DETAILS   1001
#define IDC_DATABASE_TABLES_EXPORT_DIRECTORY_STATIC   1002
#define IDC_DATABASE_TABLES_EXPORT_DIRECTORY   1003
#define IDC_DATABASE_TABLES_EXPORT_FILENAME_STATIC   1004
#define IDC_DATABASE_TABLES_EXPORT_FILENAME   1005
#define IDC_DATABASE_TABLES_EXPORT_BROWSE   1006
#define IDC_DATABASE_TABLES_EXPORT_TYPE   1007
#define IDC_DATABASE_TABLES_EXPORT_TYPE_DEFAULT   1008
#define IDC_DATABASE_TABLES_EXPORT_TYPE_CUSTOM   1009
#define IDC_DATABASE_TABLES_EXPORT_TYPE_CUSTOM_NAME   1010
#define IDC_DATABASE_TABLES_EXPORT_TYPE_CUSTOM_NAME_STATIC   1011
#define IDC_DATABASE_TABLES_EXPORT_TYPE_CUSTOM_DESCRIPTION_STATIC   1012
#define IDC_DATABASE_TABLES_EXPORT_TYPE_CUSTOM_DESCRIPTION   1013
#define IDC_DATABASE_TABLES_EXPORT_HELP   1014

class CDatabaseTablesExportDialog : public CDatabaseTablesDialog
{
	DECLARE_DYNCREATE(CDatabaseTablesExportDialog)

	// Construction
public:
	CDatabaseTablesExportDialog(CWnd *pParentWnd = NULL, CDatabaseEngine *pDatabaseEngine = NULL);   // standard constructor

	// Attributes
private:
	ULONGLONG  m_nComponent;
	CDatabaseTCPackets  m_pDatabaseTCPackets;
	CDatabaseTMNumCalTables  m_pDatabaseTMNumCalTables;
	CDatabaseTMTxtCalTables  m_pDatabaseTMTxtCalTables;
	CDatabaseTMNumOolTables  m_pDatabaseTMNumOolTables;
	CDatabaseTMTxtOolTables  m_pDatabaseTMTxtOolTables;
	CDatabaseTCNumCalTables  m_pDatabaseTCNumCalTables;
	CDatabaseTCTxtCalTables  m_pDatabaseTCTxtCalTables;
	CDatabaseTCNumOolTables  m_pDatabaseTCNumOolTables;
	CDatabaseTCTxtOolTables  m_pDatabaseTCTxtOolTables;
	CDatabaseTCPreExeGroups  m_pDatabaseTCPreExeGroups;
	CDatabaseTCExeVerGroups  m_pDatabaseTCExeVerGroups;
	CDatabaseTMPacketHeaders  m_pDatabaseTMPacketHeaders;
	CDatabaseTMPacketStreams  m_pDatabaseTMPacketStreams;
	CDatabaseTCParameterSets  m_pDatabaseTCParameterSets;
	CDatabaseTCFunctionBlocks  m_pDatabaseTCFunctionBlocks;
	CDatabaseOBProcessorMemoryImages  m_pDatabaseOBProcessorMemoryImages;
private:
	CStringArray  m_szColumns;

	// Dialog Data
	//{{AFX_DATA(CDatabaseTablesExportDialog)
	enum { IDD = IDD_DATABASE_TABLES_EXPORT_DIALOG };
	// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// Operations
private:
	BOOL EnumDatabaseTables();

	BOOL EnumTCPackets();
	BOOL EnumTMNumCalTables();
	BOOL EnumTMTxtCalTables();
	BOOL EnumTMNumOolTables();
	BOOL EnumTMTxtOolTables();
	BOOL EnumTCNumCalTables();
	BOOL EnumTCTxtCalTables();
	BOOL EnumTCNumOolTables();
	BOOL EnumTCTxtOolTables();
	BOOL EnumTCPreExeGroups();
	BOOL EnumTCExeVerGroups();
	BOOL EnumTMPacketHeaders();
	BOOL EnumTMPacketStreams();
	BOOL EnumTCParameterSets();
	BOOL EnumTCFunctionBlocks();
	BOOL EnumOBProcessorMemoryImages();

	// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDatabaseTablesExportDialog)
public:
	virtual INT_PTR DoModal(CONST CDatabaseTCPackets &pDatabaseTCPackets);
	virtual INT_PTR DoModal(CONST CDatabaseTMNumCalTables &pDatabaseTMNumCalTables);
	virtual INT_PTR DoModal(CONST CDatabaseTMTxtCalTables &pDatabaseTMTxtCalTables);
	virtual INT_PTR DoModal(CONST CDatabaseTMNumOolTables &pDatabaseTMNumOolTables);
	virtual INT_PTR DoModal(CONST CDatabaseTMTxtOolTables &pDatabaseTMTxtOolTables);
	virtual INT_PTR DoModal(CONST CDatabaseTCNumCalTables &pDatabaseTCNumCalTables);
	virtual INT_PTR DoModal(CONST CDatabaseTCTxtCalTables &pDatabaseTCTxtCalTables);
	virtual INT_PTR DoModal(CONST CDatabaseTCNumOolTables &pDatabaseTCNumOolTables);
	virtual INT_PTR DoModal(CONST CDatabaseTCTxtOolTables &pDatabaseTCTxtOolTables);
	virtual INT_PTR DoModal(CONST CDatabaseTCPreExeGroups &pDatabaseTCPreExeGroups);
	virtual INT_PTR DoModal(CONST CDatabaseTCExeVerGroups &pDatabaseTCExeVerGroups);
	virtual INT_PTR DoModal(CONST CDatabaseTMPacketHeaders &pDatabaseTMPacketHeaders);
	virtual INT_PTR DoModal(CONST CDatabaseTMPacketStreams &pDatabaseTMPacketStreams);
	virtual INT_PTR DoModal(CONST CDatabaseTCParameterSets &pDatabaseTCParameterSets);
	virtual INT_PTR DoModal(CONST CDatabaseTCFunctionBlocks &pDatabaseTCFunctionBlocks);
	virtual INT_PTR DoModal(CONST CDatabaseOBProcessorMemoryImages &pDatabaseOBProcessorMemoryImages);
	virtual BOOL Check(BOOL bModified = TRUE) CONST;
protected:
	virtual void DoDataExchange(CDataExchange *pDX);    // DDX/DDV support
	virtual BOOL OnNotify(WPARAM wParam, LPARAM lParam, LRESULT *pResult);
	virtual void PostNcDestroy();
	//}}AFX_VIRTUAL

	// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDatabaseTablesExportDialog)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnBrowse();
	afx_msg void OnDefault();
	afx_msg void OnCustom();
	afx_msg void OnEditchangeFileName();
	afx_msg void OnEditchangeName();
	afx_msg void OnEditchangeDescription();
	afx_msg BOOL OnHelpInfo(HELPINFO *pHelpInfo);
	afx_msg void OnHelp();
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
// CDatabaseTablesFileBrowseDialog dialog

class CDatabaseTablesFileBrowseDialog : public CFileDialog
{
	DECLARE_DYNCREATE(CDatabaseTablesFileBrowseDialog)

	// Construction
public:
	CDatabaseTablesFileBrowseDialog(CWnd *pParentWnd = NULL, LPCTSTR pszFileName = NULL, LPCTSTR pszDefaultExtension = NULL, LPCTSTR pszFilter = NULL, DWORD dwFlags = OFN_EXPLORER | OFN_HIDEREADONLY);
	CDatabaseTablesFileBrowseDialog(CWnd *pParentWnd, UINT nCtrlID, LPCTSTR pszDefaultExtension = NULL, LPCTSTR pszFilter = NULL, DWORD dwFlags = OFN_EXPLORER | OFN_HIDEREADONLY);

	// Attributes
private:
	TCHAR  m_szDirectory[MAX_PATH];

	// Operations
public:

	// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDatabaseTablesFileBrowseDialog)
protected:
	virtual void PostNcDestroy();
	//}}AFX_VIRTUAL

protected:
	//{{AFX_MSG(CDatabaseTablesFileBrowseDialog)
	// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////


#endif // __DIALOGS_H__
