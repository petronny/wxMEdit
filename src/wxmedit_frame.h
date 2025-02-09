///////////////////////////////////////////////////////////////////////////////
// vim:         ts=4 sw=4 expandtab
// Name:        wxmedit_frame.h
// Description: Main Frame of wxMEdit
// Copyright:   2013-2023  JiaYanwei   <wxmedit@gmail.com>
//              2005-2010  Alston Chen <madedit@gmail.com>
// License:     GPLv3
///////////////////////////////////////////////////////////////////////////////

#ifndef _WXMEDIT_FRAME_H_
#define _WXMEDIT_FRAME_H_

#include "wxm/def.h"
#include "xm/encoding/encoding_def.h"
#include "wxm/recent_list.h"
#include "wxm/status_bar.h"
#include "wxm/utils.h"
#include "wxm/edit/inframe.h"

#ifdef _MSC_VER
# pragma warning( push )
# pragma warning( disable : 4996 )
#endif
// disable 4996 {
# include <wx/wxprec.h>

#ifdef __BORLANDC__
# pragma hdrstop
#endif
#ifndef WX_PRECOMP
# include <wx/wx.h>
# include <wx/menu.h>
# include <wx/toolbar.h>
# include <wx/statusbr.h>
# include <wx/frame.h>
# include <wx/fileconf.h>
# include <wx/hashset.h>
# include <wx/imaglist.h>
# include <wx/event.h>
#endif
#include <wx/docview.h>
#include <wx/treectrl.h>
#include <wx/aui/aui.h>
// disable 4996 }
#ifdef _MSC_VER
# pragma warning( pop )
#endif

#include <map>
#include <list>

#undef MadEditFrame_STYLE
#define MadEditFrame_STYLE wxCAPTION | wxRESIZE_BORDER | wxSYSTEM_MENU | wxMINIMIZE_BOX | wxMAXIMIZE_BOX | wxCLOSE_BOX

class wxMadAuiNotebook;
class wxAuiNotebookEvent;
class MadEdit;

BEGIN_DECLARE_EVENT_TYPES()
    DECLARE_LOCAL_EVENT_TYPE( wxmEVT_RESULT_AUTOCHECKUPDATES, wxNewEventType() )
    DECLARE_LOCAL_EVENT_TYPE( wxmEVT_RESULT_MANUALCHECKUPDATES, wxNewEventType() )
END_DECLARE_EVENT_TYPES()

class MadEditFrame : public wxFrame
{
private:
    DECLARE_EVENT_TABLE()

    wxRect m_nml_rect;
public:
    MadEditFrame( wxWindow *parent, wxWindowID id = 1, const wxString &title = wxT("wxMEdit"),
        const wxPoint& pos = wxDefaultPosition,
        const wxSize& size = wxDefaultSize,
        long style = MadEditFrame_STYLE);
    virtual ~MadEditFrame();
public:
        wxMenuBar *WxMenuBar1;
        wxToolBar *WxToolBar1;
        wxm::WXMStatusBar m_wxmstatusbar;

public:
    enum {
        ID_WXTOOLBAR1 = 1005,
        ID_WXSTATUSBAR1 = 1003,

        ID_NOTEBOOK, // for wxAuiNotebook m_Notebook
        ID_OUTPUTNOTEBOOK,
        ID_FINDINFILESRESULTS,

        ID_DUMMY_VALUE_ //Dont Delete this DummyValue
    }; //End of Enum

public:
    wxMadAuiNotebook *m_Notebook;
    int           m_NewFileCount;
    wxConfigBase  *m_Config;
    wxImageList   *m_ImageList;
    wxFileHistory *m_RecentFiles;
	wxm::wxRecentList *m_RecentEncodings;
	wxm::wxRecentList *m_RecentFonts;

    wxAuiManager m_AuiManager; // wxAUI
    wxAuiNotebook *m_InfoNotebook; //
    wxTreeCtrl *m_FindInFilesResults;

    void OnUpdateUI_MenuFile_CheckCount(wxUpdateUIEvent& event);
    void OnUpdateUI_MenuFile_CheckNamed(wxUpdateUIEvent& event);
    void OnUpdateUI_MenuFileRecentFiles(wxUpdateUIEvent& event);

    void OnUpdateUI_MenuEditUndo(wxUpdateUIEvent& event);
    void OnUpdateUI_MenuEditRedo(wxUpdateUIEvent& event);
    void OnUpdateUI_MenuEdit_CheckSelection(wxUpdateUIEvent& event);
    void OnUpdateUI_MenuEdit_CheckSelSize(wxUpdateUIEvent& event);
    void OnUpdateUI_MenuEditCopy(wxUpdateUIEvent& event);
    void OnUpdateUI_MenuEditPaste(wxUpdateUIEvent& event);
    void OnUpdateUI_MenuEditPasteOvr(wxUpdateUIEvent& event);
    void OnUpdateUI_Menu_CheckSize(wxUpdateUIEvent& event);
    void OnUpdateUI_MenuEditDeleteLine(wxUpdateUIEvent& event);
    void OnUpdateUI_MenuEditInsertTabChar(wxUpdateUIEvent& event);
    void OnUpdateUI_MenuEditInsertDateTime(wxUpdateUIEvent& event);

    void OnUpdateUI_MenuEditToggleBookmark(wxUpdateUIEvent& event);
    void OnUpdateUI_MenuEditBookmarkExist(wxUpdateUIEvent& event);

    void OnUpdateUI_Menu_CheckTextFile(wxUpdateUIEvent& event);

    void OnUpdateUI_MenuEditCopyAsHexString(wxUpdateUIEvent& event);
    void OnUpdateUI_MenuEdit_InsertEnumeration(wxUpdateUIEvent& event);

    void OnUpdateUI_MenuEdit_Column(wxUpdateUIEvent& event);

    void OnUpdateUI_MenuIndent(wxUpdateUIEvent& event);
    void OnUpdateUI_MenuComment(wxUpdateUIEvent& event);

    void OnUpdateUI_MenuSearchGoTo(wxUpdateUIEvent& event);
    void OnUpdateUI_MenuSearchGoToBrace(wxUpdateUIEvent& event);

    void OnUpdateUI_MenuViewEncoding(wxUpdateUIEvent& event);
    void OnUpdateUI_MenuViewSyntax(wxUpdateUIEvent& event);
    void OnUpdateUI_MenuViewFontName(wxUpdateUIEvent& event);
    void OnUpdateUI_MenuViewFontSize(wxUpdateUIEvent& event);
    void OnUpdateUI_MenuViewSetFont(wxUpdateUIEvent& event);
    void OnUpdateUI_MenuViewFixedWidthMode(wxUpdateUIEvent& event);
    void OnUpdateUI_MenuViewTabColumn(wxUpdateUIEvent& event);
    void OnUpdateUI_MenuViewLineSpacing(wxUpdateUIEvent& event);
    void OnUpdateUI_MenuViewNoWrap(wxUpdateUIEvent& event);
    void OnUpdateUI_MenuViewWrapByWindow(wxUpdateUIEvent& event);
    void OnUpdateUI_MenuViewWrapByColumn(wxUpdateUIEvent& event);
    void OnUpdateUI_MenuViewDisplayBookmark(wxUpdateUIEvent& event);
    void OnUpdateUI_MenuViewDisplayLineNumber(wxUpdateUIEvent& event);
    void OnUpdateUI_MenuViewShowEndOfLine(wxUpdateUIEvent& event);
    void OnUpdateUI_MenuViewShowTabChar(wxUpdateUIEvent& event);
    void OnUpdateUI_MenuViewShowSpaceChar(wxUpdateUIEvent& event);
    void OnUpdateUI_MenuViewMarkActiveLine(wxUpdateUIEvent& event);
    void OnUpdateUI_MenuViewMarkBracePair(wxUpdateUIEvent& event);
    void OnUpdateUI_MenuViewTextMode(wxUpdateUIEvent& event);
    void OnUpdateUI_MenuViewColumnMode(wxUpdateUIEvent& event);
    void OnUpdateUI_MenuViewHexMode(wxUpdateUIEvent& event);

    void OnUpdateUI_MenuToolsByteOrderMark(wxUpdateUIEvent& event);
    void OnUpdateUI_MenuToolsNewLineChar(wxUpdateUIEvent& event);
    void OnUpdateUI_MenuToolsInsertNewLineChar(wxUpdateUIEvent& event);
    void OnUpdateUI_MenuToolsConvertNL(wxUpdateUIEvent& event);
    void OnUpdateUI_MenuToolsConvertEncoding(wxUpdateUIEvent& event);

    void OnUpdateUI_MenuWindow_CheckCount(wxUpdateUIEvent& event);

    void OnUpdateUI_MenuHelp_CheckUpdates(wxUpdateUIEvent& event);

    void OnFileNew(wxCommandEvent& event);
    void OnFileOpen(wxCommandEvent& event);
    void OnFileSave(wxCommandEvent& event);
    void OnFileSaveAs(wxCommandEvent& event);
    void OnFileSaveAll(wxCommandEvent& event);
    void OnFileReload(wxCommandEvent& event);
    void OnFileClose(wxCommandEvent& event);
    void OnFileCloseByPath(wxCommandEvent& event);
    void OnFileCloseAll(wxCommandEvent& event);
    void OnFileCloseAllButThis(wxCommandEvent& event);
    void OnFileCloseAllToTheLeft(wxCommandEvent& event);
    void OnFileCloseAllToTheRight(wxCommandEvent& event);
    void OnFileCopyFullPath(wxCommandEvent& event);
    void OnFileCopyFilename(wxCommandEvent& event);
    void OnFileCopyFileDir(wxCommandEvent& event);
    void OnFilePageSetup(wxCommandEvent& event);
    void OnFilePrintPreview(wxCommandEvent& event);
    void OnFilePrint(wxCommandEvent& event);
    void OnFileRecentFile(wxCommandEvent& event);
    void OnFileExit(wxCommandEvent& event);

    void OnEditUndo(wxCommandEvent& event);
    void OnEditRedo(wxCommandEvent& event);
    void OnEditCut(wxCommandEvent& event);
    void OnEditCopy(wxCommandEvent& event);
    void OnEditPaste(wxCommandEvent& event);
    void OnEditPasteOvr(wxCommandEvent& event);
    void OnEditDelete(wxCommandEvent& event);
    void OnEditCutLine(wxCommandEvent& event);
    void OnEditDeleteLine(wxCommandEvent& event);
    void OnEditSelectAll(wxCommandEvent& event);
    void OnEditInsertTabChar(wxCommandEvent& event);
    void OnEditInsertDateTime(wxCommandEvent& event);

    void OnEditSortAscending(wxCommandEvent& event);
    void OnEditSortDescending(wxCommandEvent& event);
    void OnEditSortAscendingCase(wxCommandEvent& event);
    void OnEditSortDescendingCase(wxCommandEvent& event);
    void OnEditSortByOptions(wxCommandEvent& event);
    void OnEditSortOptions(wxCommandEvent& event);

    void OnEditCopyAsHexString(wxCommandEvent& event);
    void OnEditCopyAsHexStringWithSpace(wxCommandEvent& event);
    void OnEditIncIndent(wxCommandEvent& event);
    void OnEditDecIndent(wxCommandEvent& event);
    void OnEditComment(wxCommandEvent& event);
    void OnEditUncomment(wxCommandEvent& event);
    void OnEditWordWrapToNewLine(wxCommandEvent& event);
    void OnEditNewLineToWordWrap(wxCommandEvent& event);
    void OnEditToUpperCase(wxCommandEvent& event);
    void OnEditToLowerCase(wxCommandEvent& event);
    void OnEditInvertCase(wxCommandEvent& event);
    void OnEditToHalfWidth(wxCommandEvent& event);
    void OnEditToHalfWidthByOptions(wxCommandEvent& event);
    void OnEditToFullWidth(wxCommandEvent& event);
    void OnEditToFullWidthByOptions(wxCommandEvent& event);
    void OnEditTabToSpace(wxCommandEvent& event);
    void OnEditSpaceToTab(wxCommandEvent& event);
    void OnEditTrimTrailingSpaces(wxCommandEvent& event);
    void OnEditInsertEnumeration(wxCommandEvent& event);
    void OnEditColumnAlign(wxCommandEvent& event);
    void OnEditColumnPaste(wxCommandEvent& event);

    void OnSearchFind(wxCommandEvent& event);
    void OnSearchFindNext(wxCommandEvent& event);
    void OnSearchFindPrevious(wxCommandEvent& event);
    void OnSearchReplace(wxCommandEvent& event);
    void OnSearchFindInFiles(wxCommandEvent& event);
    void OnSearchShowFindInFilesResults(wxCommandEvent& event);
    void OnSearchGoToLine(wxCommandEvent& event);
    void OnSearchGoToPosition(wxCommandEvent& event);
    void OnSearchGoToLeftBrace(wxCommandEvent& event);
    void OnSearchGoToRightBrace(wxCommandEvent& event);

    void OnSearchToggleBookmark(wxCommandEvent& event);
    void OnSearchGotoNextBookmark(wxCommandEvent& event);
    void OnSearchGotoPreviousBookmark(wxCommandEvent& event);
    void OnSearchClearAllBookmarks(wxCommandEvent& event);

    void OnViewEncoding(wxCommandEvent& event);
    void OnViewRecentEncoding(wxCommandEvent& event);
    void OnViewSyntax(wxCommandEvent& event);
    void OnViewFontName(wxCommandEvent& event);
    void OnViewRecentFont(wxCommandEvent& event);
    void OnViewFontSize(wxCommandEvent& event);
    void OnViewSetFont(wxCommandEvent& event);
    void OnViewFixedWidthMode(wxCommandEvent& event);
    void OnViewTabColumn(wxCommandEvent& event);
    void OnViewLineSpacing(wxCommandEvent& event);
    void OnViewNoWrap(wxCommandEvent& event);
    void OnViewWrapByWindow(wxCommandEvent& event);
    void OnViewWrapByColumn(wxCommandEvent& event);
    void OnViewDisplayBookmark(wxCommandEvent& event);
    void OnViewDisplayLineNumber(wxCommandEvent& event);
    void OnViewShowEndOfLine(wxCommandEvent& event);
    void OnViewShowTabChar(wxCommandEvent& event);
    void OnViewShowSpaceChar(wxCommandEvent& event);
    void OnViewMarkActiveLine(wxCommandEvent& event);
    void OnViewMarkBracePair(wxCommandEvent& event);
    void OnViewTextMode(wxCommandEvent& event);
    void OnViewColumnMode(wxCommandEvent& event);
    void OnViewHexMode(wxCommandEvent& event);

    void OnToolsOptions(wxCommandEvent& event);
    void OnToolsHighlighting(wxCommandEvent& event);
#ifdef __WXMSW__
    void OnToolsFileAssociation(wxCommandEvent& event);
#endif
    void OnToolsPurgeHistories(wxCommandEvent& event);
    void OnToolsToggleBOM(wxCommandEvent& event);
    void OnToolsConvertToDOS(wxCommandEvent& event);
    void OnToolsConvertToMAC(wxCommandEvent& event);
    void OnToolsConvertToUNIX(wxCommandEvent& event);
    void OnToolsInsertDOS(wxCommandEvent& event);
    void OnToolsInsertMAC(wxCommandEvent& event);
    void OnToolsInsertUNIX(wxCommandEvent& event);
    void OnToolsConvertEncoding(wxCommandEvent& event);
    void OnToolsSimp2TradChinese(wxCommandEvent& event);
    void OnToolsTrad2SimpChinese(wxCommandEvent& event);
    void OnToolsKanji2TradChinese(wxCommandEvent& event);
    void OnToolsKanji2SimpChinese(wxCommandEvent& event);
    void OnToolsChinese2Kanji(wxCommandEvent& event);
    void OnToolsSimp2TradClipboard(wxCommandEvent& event);
    void OnToolsTrad2SimpClipboard(wxCommandEvent& event);
    void OnToolsKanji2TradClipboard(wxCommandEvent& event);
    void OnToolsKanji2SimpClipboard(wxCommandEvent& event);
    void OnToolsChinese2KanjiClipboard(wxCommandEvent& event);
    void OnToolsWordCount(wxCommandEvent& event);

    void OnWindowToggleWindow(wxCommandEvent& event);
    void OnWindowPreviousWindow(wxCommandEvent& event);
    void OnWindowNextWindow(wxCommandEvent& event);

    void OnHelpCheckUpdates(wxCommandEvent& event);
    void OnHelpAbout(wxCommandEvent& event);

    void OnSize(wxSizeEvent& event);
private:
    bool m_PageClosing; // prevent from reentry of CloseFile(), OnNotebookPageClosing()

    typedef std::map<xm::EncodingGroupID, wxMenu*> EncGrps;
    EncGrps m_encgrps;

public:
    int OpenedFileCount();
    // if filename is empty, open a new file
    void OpenFile(const wxString &filename, bool mustExist, const LineNumberList& bmklns=LineNumberList());
    void CloseFile(int pageId);
    void CloseAllFiles(bool force);
    void MadEditFrameKeyDown(wxKeyEvent& event);
    void SetPageFocus(int pageId);
    wxm::InFrameWXMEdit* GetEditByFileName(const wxString &filename, int &id);
    void ResetAcceleratorTable();

protected:
    void MadEditFrameClose(wxCloseEvent& event);
    void EncodingGroupMenuAppend(ssize_t idx, const wxString& text, size_t rsv_cnt);
    size_t ReserveEncodingGrupMenus();
    void InitEncodingMenus();
    void CreateGUIControls();

    void OnNotebookPageChanging(wxAuiNotebookEvent& event);
    void OnNotebookPageChanged(wxAuiNotebookEvent& event);
    void OnNotebookPageClosing(wxAuiNotebookEvent& event);
    void OnNotebookPageClosed(bool bZeroPage=false);//wxAuiNotebookEvent& event); //wxAUI doesn't support this event
	void OnNotebookTabRightUp(wxAuiNotebookEvent& event);

    void OnSizeStatusBar(wxSizeEvent &evt);
    //void OnChar(wxKeyEvent& evt);
    void OnActivate(wxActivateEvent &evt);

    void OnResultAutoCheckUpdates(wxEvent &evt);
    void OnResultManualCheckUpdates(wxEvent &evt);

    bool QueryCloseFile(int idx);
    bool QueryCloseAllFiles();

    wxString GetMenuKey(const wxString &menu, const wxString &defaultkey);

    void OnInfoNotebookSize(wxSizeEvent &evt);
    void OnFindInFilesResultsDClick(wxMouseEvent& event);

#ifdef __WXMSW__
    WXLRESULT MSWWindowProc(WXUINT message, WXWPARAM wParam, WXLPARAM lParam);
#endif

public:
    void ResetFindInFilesResults();
    void AddItemToFindInFilesResults(const wxString &text, size_t index, const wxString &filename, int pageid, const wxFileOffset &begpos, wxFileOffset &endpos);

    void PurgeRecentFiles();
    void PurgeRecentFonts();
    void PurgeRecentEncodings();
    wxRect GetNormalRect();
};

enum { // menu id
    menuNew = wxID_NEW,
    menuOpen = wxID_OPEN,
    menuSave = wxID_SAVE,
    menuSaveAs = wxID_SAVEAS,
    menuClose = wxID_CLOSE,
    menuCloseAll = wxID_CLOSE_ALL,
    menuPageSetup = wxID_PRINT_SETUP,
    menuPrintPreview = wxID_PREVIEW,
    menuPrint = wxID_PRINT,
    menuExit = wxID_EXIT,
    menuUndo = wxID_UNDO,
    menuRedo = wxID_REDO,
    menuCut = wxID_CUT,
    menuCopy = wxID_COPY,
    menuPaste = wxID_PASTE,
    menuDelete = wxID_DELETE,
    menuSelectAll = wxID_SELECTALL,
    menuFind = wxID_FIND,
    menuReplace = wxID_REPLACE,
    menuAbout = wxID_ABOUT,

    // file
    menuSaveAll = 1100,
    menuCloseByPath,
    menuCloseMore,
    menuCloseAllButThis,
    menuCloseAllToTheLeft,
    menuCloseAllToTheRight,
    menuCopyFilePath,
    menuCopyFullPath,
    menuCopyFilename,
    menuCopyFileDir,
    menuReload,
    menuRecentFiles,

    // edit
    menuPasteOvr,
    menuCutLine,
    menuDeleteLine,
    menuInsertTabChar,
    menuInsertDateTime,
    menuToggleBookmark,
    menuGotoNextBookmark,
    menuGotoPreviousBookmark,
    menuClearAllBookmarks,
    menuColumn,
    menuColumnAlign,
    menuColumnPaste,
    menuSort,
    menuSortAscending,
    menuSortDescending,
    menuSortAscendingCase,
    menuSortDescendingCase,
    menuSortByOptions,
    menuSortOptions,
    menuAdvanced,
    menuCopyAsHexString,
    menuCopyAsHexStringWithSpace,
    menuIncreaseIndent,
    menuDecreaseIndent,
    menuComment,
    menuUncomment,
    menuWordWrapToNewLine,
    menuNewLineToWordWrap,
    menuToUpperCase,
    menuToLowerCase,
    menuInvertCase,
    menuToHalfWidth,
    menuToHalfWidthByOptions,
    menuToFullWidth,
    menuToFullWidthByOptions,
    menuTabToSpace,
    menuSpaceToTab,
    menuTrimTrailingSpaces,
    menuInsertEnumeration,

    // search
    menuFindNext,
    menuFindPrevious,
    menuFindInFiles,
    menuShowFindInFilesResults,
    menuGoToLine,
    menuGoToPosition,
    menuLeftBrace,
    menuRightBrace,

    // view
    menuEncoding,
    menuAllEncodings,
    menuEncodingGroup1,
    menuEncodingGroup99 = menuEncodingGroup1 + 98,

	menuEncoding1,
    menuEncoding99 = menuEncoding1 + 98,

    menuRecentEncoding1,
    menuRecentEncoding9 = menuRecentEncoding1 + 8,

    menuSyntax,
    menuSyntax1,
    menuSyntax199 = menuSyntax1 + 198,

    menuFontName,
    menuFontName1,
    menuFontName999 = menuFontName1 + 998,

    menuFont0, //[@]
    menuFont1, //[ABCDE]
    menuFont2, //[FGHIJ]
    menuFont3, //[KLMNO]
    menuFont4, //[PQRST]
    menuFont5, //[UVWXYZ]
    menuFont6, //[Other]

    menuRecentFonts,
    menuRecentFont1,
    menuRecentFont9 = menuRecentFont1 + 8,

    menuFontSize,
    menuFontSize1,
    menuFontSize99 = menuFontSize1 + 98,

    menuSetFont,
    menuFixedWidthMode,

    menuTabColumn,
    menuTabColumn1,
    menuTabColumn16 = menuTabColumn1 + 15,

    menuLineSpacing,
    menuLineSpacing100,
    menuLineSpacing250 = menuLineSpacing100 + 30,

    menuNoWrap,
    menuWrapByWindow,
    menuWrapByColumn,
    menuDisplayBookmark,
    menuDisplayLineNumber,
    menuShowEndOfLine,
    menuShowTabChar,
    menuShowSpaceChar,
    menuMarkActiveLine,
    menuMarkBracePair,
    menuTextMode,
    menuColumnMode,
    menuHexMode,

    // tools
    menuOptions,
    menuHighlighting,
#ifdef __WXMSW__
    menuFileAssociation,
#endif
    menuPurgeHistories,
    menuPlugins,
    menuByteOrderMark,
    menuToggleBOM,
    menuNewLineChar,
    menuConvertToDOS,
    menuConvertToMAC,
    menuConvertToUNIX,
    menuInsertNewLineChar,
    menuInsertDOS,
    menuInsertMAC,
    menuInsertUNIX,
    menuConvertEncoding,
    menuConvertChineseChar,
    menuSimp2TradChinese,
    menuTrad2SimpChinese,
    menuKanji2TradChinese,
    menuKanji2SimpChinese,
    menuChinese2Kanji,
    menuSimp2TradClipboard,
    menuTrad2SimpClipboard,
    menuKanji2TradClipboard,
    menuKanji2SimpClipboard,
    menuChinese2KanjiClipboard,
    menuWordCount,

    // window
    menuToggleWindow,
    menuPreviousWindow,
    menuNextWindow,

    // help
    menuCheckUpdates,
};

class wxMadAuiNotebook : public wxAuiNotebook
{
public:
    wxMadAuiNotebook() : wxAuiNotebook() {}

    wxMadAuiNotebook(wxWindow* parent,
        wxWindowID id = wxID_ANY,
        const wxPoint& pos = wxDefaultPosition,
        const wxSize& size = wxDefaultSize,
        long style = wxAUI_NB_DEFAULT_STYLE)
        : wxAuiNotebook(parent, id, pos, size, style)
    {
    }

    virtual ~wxMadAuiNotebook() {}

    struct PageData
    {
        int x, y, idx;
        wxm::InFrameWXMEdit* wxmedit;
        int pageid;
        PageData() {}
        PageData(int xx, int yy, int ii, wxm::InFrameWXMEdit* mm, int pgid)
            : x(xx), y(yy), idx(ii), wxmedit(mm), pageid(pgid)
        {}
    };

    std::list<PageData> GetPagesList();

    size_t GetFilesListForReload(wxm::FileList& filelist);

    struct FunctorA
    {
        wxm::InFrameWXMEdit* wxmedit;
        bool operator()(PageData &pd)
        {
            return wxmedit == pd.wxmedit;
        }
    };

    void AdvanceSelection(bool bForward);
    void ConnectMouseClick();

protected:
    void OnMouseClick(wxMouseEvent &evt);
};

extern MadEditFrame *g_MainFrame;
extern void OnReceiveMessage(const wchar_t *msg, size_t size);

inline int GetIdByEdit(wxWindow* edit)
{
    return g_MainFrame->m_Notebook->GetPageIndex(edit);
}

#endif // _WXMEDIT_FRAME_H_
