/**********************************/
/* sw.h -- Multimedia for emx 1.0 */
/*                                */
/*                                */
/* Marc E.E. van Woerkom, 2/94    */
/*                                */
/**********************************/


/* nested header management */
#ifndef _SW_H
#define _SW_H

/* use 32-bit alignment */
#pragma pack(4)


/********************/
/* secondary window */
/********************/

#ifdef INCL_SECONDARYWINDOW

    #define MAX_SMBDTEXT            35
    #define MB_ICONCUSTOM           1
    #define QS_FRAME                1
    #define QS_DIALOG               2
    #define SC_DEFAULTSIZE          0xc000
    #define WM_INITSECONDARYWINDOW  0x0519

    typedef struct _SMBD {
        CHAR  achText[MAX_SMBDTEXT + 1]; 
        ULONG idButton;
        LONG  flStyle;
    } SMBD;

    typedef SMBD* PSMBD;

    typedef struct _SMBINFO {
        HPOINTER hIcon;
        ULONG    cButtons;
        ULONG    flStyle;
        HWND     hwndNotify;
        PSMBD    psmbd;
    } SMBINFO;

    typedef SMBINFO* PSMBINFO;

    ULONG   WinSecondaryWindow(HWND hwndParent, HWND hwndOwner,
                               PFNWP pfnDlgProc, HMODULE hmod, ULONG idDlg,
                               PVOID pCreateParams);

    HWND    WinLoadSecondaryWindow(HWND hwndParent, HWND hwndOwner,
                                   PFNWP pfnDlgProc, HMODULE hmod,
                                   ULONG idDlg, PVOID pCreateParams);

    ULONG   WinProcessSecondaryWindow(HWND hwndSW);

    HWND    WinCreateSecondaryWindow(HWND hwndParent, HWND hwndOwner,
                                     PFNWP pfnDlgProc, PDLGTEMPLATE pdlgt,
                                     PVOID pCreateParams);

    BOOL    WinDefaultSize(HWND hwnd);

    BOOL    WinInsertDefaultSize(HWND hwnd, PSZ pszDefaultSize);

    HWND    WinQuerySecondaryHWND(HWND hwnd, ULONG ulFlag);

    ULONG   WinSecondaryMessageBox(HWND hwndParent, HWND hwndOwner,
                                   PSZ pszText, PSZ pszCaption,
                                   ULONG idWindow, PSMBINFO psmbinfo);

    BOOL    WinDismissSecondaryWindow(HWND hwndDlg, ULONG ulResult);

    BOOL    WinDestroySecondaryWindow(HWND hwnd);

    MRESULT WinDefSecondaryWindowProc(HWND hwnd, ULONG msg, MPARAM mp1,
                                      MPARAM mp2);

#endif


/******************/
/* graphic button */
/******************/

#ifdef INCL_GRAPHICBUTTON

    #define GB_ERROR           -1
    #define GB_UP               1
    #define GB_DOWN             2
    #define GB_DISABLE          3
    #define GB_HILITE           4
    #define GB_OUTOFHILITE      5
    #define GB_TOGGLE          10
    #define GB_CURRENTSTATE    11
    #define GB_ANIMATIONBEGIN  12
    #define GB_ANIMATIONEND    13
    #define GB_MAXINDEX        14
    #define GB_TEXTBELOW        1
    #define GB_TEXTABOVE        2
    #define GB_INDEX_FORWARD   -1
    #define GB_INDEX_BACKWARD  -2
    #define GB_INDEX_FIRST     -3
    #define GB_INDEX_LAST      -4
    #define GB_RESOURCE         1
    #define GB_STRUCTURE        0

    #define GBM_SETGRAPHICDATA        0x052A
    #define GBM_ANIMATE               0x052B
    #define GBM_SETANIMATIONRATE      0x052C
    #define GBM_QUERYANIMATIONACTIVE  0x052D
    #define GBM_QUERYANIMATIONRATE    0x052E
    #define GBM_SETBITMAPINDEX        0x052F
    #define GBM_QUERYBITMAPINDEX      0x0530
    #define GBM_SETSTATE              0x0531
    #define GBM_QUERYSTATE            0x0532
    #define GBM_SETTEXTPOSITION       0x0533
    #define GBM_QUERYTEXTPOSITION     0x0534

    #define GBN_BUTTONUP      0x0524
    #define GBN_BUTTONDOWN    0x0525
    #define GBN_BUTTONHILITE  0x0526

    #define GBS_TWOSTATE         0x1000
    #define GBS_AUTOTWOSTATE     0X2000
    #define GBS_ANIMATION        0x4000
    #define GBS_AUTOANIMATION    0x8000
    #define GBS_DISABLEBITMAP    0x0010
    #define GBS_HILITEBITMAP     0x0020
    #define GBS_3D_TEXTRECESSED  0x0040
    #define GBS_3D_TEXTRAISED    0x0080

    #define WC_GRAPHICBUTTON ((PSZ)0xffff0040L)

    /* use 8-bit alignment */
    #pragma pack(1)

    typedef struct _GBTNCDATA {
        USHORT  usReserved;
        PSZ     pszText;
        HMODULE hmod;
        USHORT  cBitmaps;
        USHORT  aidBitmap[1];
    } GBTNCDATA;

    typedef GBTNCDATA* PGBTNCDATA;

    /* use 32-bit alignment again */
    #pragma pack(4)

    BOOL WinRegisterGraphicButton(VOID);

#endif


/*******************/
/* circular slider */
/*******************/

#ifdef INCL_STPMPAGE
    #define MM_TABHELP  0x054C
#endif

#ifdef INCL_DIAL
    #define INCL_CIRCULARSLIDER
#endif

#ifdef INCL_CIRCULARSLIDER

    #define CSM_QUERYRANGE      0x053D         
    #define CSM_SETRANGE        0x053E
    #define CSM_QUERYVALUE      0x053F
    #define CSM_SETVALUE        0x0540
    #define CSM_QUERYRADIUS     0x0541
    #define CSM_SETINCREMENT    0x0542
    #define CSM_QUERYINCREMENT  0x0543
    #define CSM_SETBITMAPDATA   0x0544

    #define CSN_SETFOCUS              0x0548
    #define CSN_CHANGED               0x0549
    #define CSN_TRACKING              0x054A
    #define CSN_QUERYBACKGROUNDCOLOR  0x054B

    #define CSS_NOBUTTON           WS_NOBUTTON
    #define CSS_NOTEXT             WS_NOTEXT
    #define CSS_NONUMBER           WS_NONUMBER
    #define CSS_POINTSELECT        WS_POINTSELECT
    #define CSS_360                WS_360
    #define CSS_MIDPOINT           WS_MIDPOINT
    #define CSS_PROPORTIONALTICKS  64

    #define WC_CIRCULARSLIDER  ((PSZ)0xffff0041L)

    #define WS_NOBUTTON      1
    #define WS_NOTEXT        2
    #define WS_NONUMBER      4
    #define WS_POINTSELECT   8
    #define WS_360          16
    #define WS_MIDPOINT     32

    typedef struct _CSBITMAPDATA {
        HBITMAP hbmLeftUp;
        HBITMAP hbmLeftDown;
        HBITMAP hbmRightUp;
        HBITMAP hbmRightDown;
    } CSBITMAPDATA;

    typedef CSBITMAPDATA* PCSBITMAPDATA;

    BOOL WinRegisterCircularSlider(VOID);

#endif


/* use default alignment */
#pragma pack()

/* nested header management */
#endif

