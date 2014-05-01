/***************************************/
/* mmioos2.h -- Multimedia for emx 1.0 */
/*                                     */
/*                                     */
/* Marc E.E. van Woerkom, 2/94         */
/*                                     */
/***************************************/


/* nested header management */
#ifndef _MMIOOS2_H
#define _MMIOOS2_H

/* use 32-bit alignment */
#pragma pack(4)


/***********/
/* defines */
/***********/

#define CODEC_INFO_SIZE                       8
#define CODEC_HW_NAME_SIZE                   32

#define CTOC_HF_SEQUENTIAL                   0x00000001L
#define CTOC_HF_MEDSUBTYPE                   0x00000002L
#define CTOC_EFU_UNUSED                      0x00000000L
#define CTOC_EFU_LASTMODTIME                 0x00000001L
#define CTOC_EFU_CODEPAGE                    0x00000002L
#define CTOC_EFU_LANGUAGE                    0x00000003L
#define CTOC_EFU_COMPRESSPARAM0              0x00000005L
#define CTOC_EFU_COMPRESSPARAM1              0x00000006L
#define CTOC_EFU_COMPRESSPARAM2              0x00000007L
#define CTOC_EFU_COMPRESSPARAM3              0x00000008L
#define CTOC_EFU_COMPRESSPARAM4              0x00000009L
#define CTOC_EFU_COMPRESSPARAM5              0x0000000AL
#define CTOC_EFU_COMPRESSPARAM6              0x0000000BL
#define CTOC_EFU_COMPRESSPARAM7              0x0000000CL
#define CTOC_EFU_COMPRESSPARAM8              0x0000000DL
#define CTOC_EFU_COMPRESSPARAM9              0x0000000EL
#define CTOC_CHARSET_STANDARD                0x00000000L

#define DLLNAME_SIZE                         CCHMAXPATH
#define PROCNAME_SIZE                        32
#define MAX_EXTENSION_NAME                    4

#define MMIO_AUDIO_UNKNOWN                   0x00000000L
#define MMIO_AUDIO_VOICE                     0x00000001L
#define MMIO_AUDIO_MUSIC                     0x00000002L
#define MMIO_AUDIO_HIFI                      0x00000004L

#define MMIO_CANREADTRANSLATED               0x00000001L
#define MMIO_CANWRITETRANSLATED              0x00000002L
#define MMIO_CANREADWRITETRANSLATED          0x00000004L
#define MMIO_CANREADUNTRANSLATED             0x00000008L
#define MMIO_CANWRITEUNTRANSLATED            0x00000010L
#define MMIO_CANREADWRITEUNTRANSLATED        0x00000020L
#define MMIO_CANSEEKTRANSLATED               0x00000040L
#define MMIO_CANSEEKUNTRANSLATED             0x00000080L
#define MMIO_CANINSERTUNTRANSLATED           0x00000100L
#define MMIO_CANSAVEUNTRANSLATED             0x00000200L
#define MMIO_CANINSERTTRANSLATED             0x00000400L
#define MMIO_CANSAVETRANSLATED               0x00000800L
#define MMIO_CANMULTITRACKREADTRANSLATED     0x00001000L
#define MMIO_CANMULTITRACKREADUNTRANSLATED   0x00002000L
#define MMIO_CANMULTITRACKWRITETRANSLATED    0x00004000L
#define MMIO_CANMULTITRACKWRITEUNTRANSLATED  0x00008000L
#define MMIO_CANTRACKSEEKTRANSLATED          0x00010000L
#define MMIO_CANTRACKSEEKUNTRANSLATED        0x00020000L
#define MMIO_CANTRACKREADTRANSLATED          0x00040000L
#define MMIO_CANTRACKREADUNTRANSLATED        0x00080000L
#define MMIO_CANTRACKWRITETRANSLATED         0x00100000L
#define MMIO_CANTRACKWRITEUNTRANSLATED       0x00200000L

#define MMIO_IOPROC_STORAGESYSTEM            0x00000001L
#define MMIO_IOPROC_FILEFORMAT               0x00000002L
#define MMIO_IOPROC_DATAFORMAT               0x00000004L

#define MMIO_IMAGE_UNKNOWN                   0x00000000L
#define MMIO_IMAGE_DRAWING                   0x00000001L
#define MMIO_IMAGE_GRAPH                     0x00000002L
#define MMIO_IMAGE_PHOTO                     0x00000004L

#define MMIO_MEDIATYPE_IMAGE                 0x00000001L
#define MMIO_MEDIATYPE_AUDIO                 0x00000002L
#define MMIO_MEDIATYPE_MIDI                  0x00000004L
#define MMIO_MEDIATYPE_COMPOUND              0x00000008L
#define MMIO_MEDIATYPE_OTHER                 0x00000010L
#define MMIO_MEDIATYPE_UNKNOWN               0x00000020L
#define MMIO_MEDIATYPE_DIGITALVIDEO          0x00000040L
#define MMIO_MEDIATYPE_ANIMATION             0x00000080L
#define MMIO_MEDIATYPE_MOVIE                 0x00000100L

#define MMIO_MIDI_UNKNOWN                    0x00000000L
#define MMIO_MIDI_VOICE                      0x00000001L
#define MMIO_MIDI_MUSIC                      0x00000002L
#define MMIO_MIDI_HIFI                       0x00000004L

#define MMIO_CREATE                          0x00000001L       
#define MMIO_CTOCFIRST                       0x00000002L       
#define MMIO_READ                            0x00000004L       
#define MMIO_WRITE                           0x00000008L       
#define MMIO_READWRITE                       0x00000010L       
#define MMIO_COMPAT                          0x00000020L       
#define MMIO_EXCLUSIVE                       0x00000040L       
#define MMIO_DENYWRITE                       0x00000080L       
#define MMIO_DENYREAD                        0x00000100L       
#define MMIO_DENYNONE                        0x00000200L       
#define MMIO_ALLOCBUF                        0x00000400L       
#define MMIO_DELETE                          0x00000800L       
#define MMIO_USE_TEMP                        0x00001000L       
#define MMIO_INSERTON                        0x00000001L       
#define MMIO_INSERTOFF                       0x00000002L       
#define MMIO_RWMODE                          0x00001000L       
#define MMIO_SHAREMODE                       0x00002000L       
#define MMIO_DIRTY                           0x00004000L       
#define MMIO_VERTBAR                         0x00008000L      
#define MMIO_BUFSHARED                       0x00010000L      
#define MMIO_APPEND                          0x00020000L      
#define MMIO_NOIDENTIFY                      0x00040000L      
#define MMIO_FINDFIRST                       0x00000001L      
#define MMIO_FINDNEXT                        0x00000002L      
#define MMIO_FINDUNUSED                      0x00000004L      
#define MMIO_FINDDELETED                     0x00000008L
#define MMIO_CHANGEDELETED                   0x0001
#define MMIO_CF_FQNAME                       0x0001
#define MMIO_FHOPEN                          0x0001
#define MMIO_EMPTYBUF                        0x0001
#define MMIO_CREATERIFF                      0x0001
#define MMIO_CREATELIST                      0x0002
#define MMIO_FINDCHUNK                       0x0004
#define MMIO_FINDRIFF                        0x0008
#define MMIO_FINDLIST                        0x0010
#define MMIO_INSTALLPROC                     0x00000001L
#define MMIO_REMOVEPROC                      0x00000002L
#define MMIO_FINDPROC                        0x00000004L
#define MMIO_MATCHFIRST                      0x00000010L
#define MMIO_MATCHNEXT                       0x00000020L
#define MMIO_MATCHFOURCC                     0x00000040L
#define MMIO_MATCHDLL                        0x00000080L
#define MMIO_MATCHPROCEDURENAME              0x00000100L
#define MMIO_FULLPATH                        0x00000200L
#define MMIO_NOVERIFY                        0x00000400L
#define MMIO_MATCHCOMPRESSTYPE               0x00000800L
#define MMIO_EXTENDED_STRUCT                 0x00001000L
#define MMIO_MATCHCOMPRESSSUBTYPE            0x00002000L
#define MMIO_MATCHHWID                       0x00004000L
#define MMIO_MATCHCAPSFLAGS                  0x00008000L
#define MMIO_SKIPMATCH                       0x00010000L
#define MMIO_TOUPPER                         0x0001
#define MMIO_CF_ENTRY_EXISTS                 0x00000001L
#define MMIO_FORCE_IDENTIFY_SS               0x00000001L
#define MMIO_FORCE_IDENTIFY_FF               0x00000002L
#define MMIO_NOTRANSLATE                     0x00000000L
#define MMIO_TRANSLATEDATA                   0x00000001L
#define MMIO_TRANSLATEHEADER                 0x00000002L
#define MMIO_DECOMPRESS                      0x00000004L
#define MMIO_DEFAULTBUFFER                   8192
#define MMIO_SEEK_IFRAME                     0x00010000L

#define MMIOM_START                          0x0E00
#define MMIOM_END                            0x0EFF
#define MMIOM_GETCF                          MMIOM_START +  1
#define MMIOM_GETCFENTRY                     MMIOM_START +  2
#define MMIOM_CLOSE                          MMIOM_START +  3
#define MMIOM_OPEN                           MMIOM_START +  4
#define MMIOM_READ                           MMIOM_START +  5
#define MMIOM_SEEK                           MMIOM_START +  6
#define MMIOM_WRITE                          MMIOM_START +  7
#define MMIOM_IDENTIFYFILE                   MMIOM_START +  8
#define MMIOM_GETHEADER                      MMIOM_START +  9
#define MMIOM_SETHEADER                      MMIOM_START + 10
#define MMIOM_QUERYHEADERLENGTH              MMIOM_START + 11
#define MMIOM_GETFORMATNAME                  MMIOM_START + 12
#define MMIOM_GETFORMATINFO                  MMIOM_START + 13
#define MMIOM_SEEKBYTIME                     MMIOM_START + 14
#define MMIOM_TEMPCHANGE                     MMIOM_START + 15
#define MMIOM_BEGININSERT                    MMIOM_START + 16
#define MMIOM_ENDINSERT                      MMIOM_START + 17
#define MMIOM_SAVE                           MMIOM_START + 18
#define MMIOM_SET                            MMIOM_START + 19
#define MMIOM_COMPRESS                       MMIOM_START + 20
#define MMIOM_DECOMPRESS                     MMIOM_START + 21
#define MMIOM_MULTITRACKREAD                 MMIOM_START + 22
#define MMIOM_MULTITRACKWRITE                MMIOM_START + 23
#define MMIOM_DELETE                         MMIOM_START + 24
#define MMIOM_BEGINGROUP                     MMIOM_START + 25
#define MMIOM_ENDGROUP                       MMIOM_START + 26
#define MMIOM_UNDO                           MMIOM_START + 27
#define MMIOM_REDO                           MMIOM_START + 28
#define MMIOM_BEGINSTREAM                    MMIOM_START + 29
#define MMIOM_ENDSTREAM                      MMIOM_START + 30
#define MMIOM_USER                           0x0F00
#define MMIOM_USER_END                       0x0FFF

#define MMIO_SUCCESS                         0L
#define MMIO_WARNING                         2L
#define MMIO_ERROR                          -1L
#define MMIOERR_UNSUPPORTED_MESSAGE         -2L
                                            
#define MMIO_CF_SUCCESS                      0L
#define MMIO_CF_FAILURE                      1L

#define MMIO_NLS_CHARSET_INFO                8000
#define MMIO_IOPROC_NAME_TABLE               8500
#define MMIO_CODEC_NAME_TABLE                9000

#define MMIO_DEFAULT_CODE_PAGE               437
                                             
#define MMIO_CC_NONE                         000
#define MMIO_CC_USA                          001
#define MMIO_CC_CANADA                       002
#define MMIO_CC_LATIN_AMERICA                003
#define MMIO_CC_GREECE                       030
#define MMIO_CC_NETHERLANDS                  031
#define MMIO_CC_BELGIUM                      032
#define MMIO_CC_FRANCE                       033
#define MMIO_CC_SPAIN                        034
#define MMIO_CC_ITALY                        039
#define MMIO_CC_SWITZERLAND                  041
#define MMIO_CC_AUSTRIA                      043
#define MMIO_CC_UNITED_KINGDOM               044
#define MMIO_CC_DENMARK                      045
#define MMIO_CC_SWEDEN                       046
#define MMIO_CC_NORWAY                       047
#define MMIO_CC_WEST_GERMANY                 049
#define MMIO_CC_MEXICO                       052
#define MMIO_CC_BRAZIL                       055
#define MMIO_CC_AUSTRALIA                    061
#define MMIO_CC_NEW_ZEALAND                  064
#define MMIO_CC_JAPAN                        081
#define MMIO_CC_KOREA                        082
#define MMIO_CC_CHINA                        086
#define MMIO_CC_TAIWAN                       088
#define MMIO_CC_TURKEY                       090
#define MMIO_CC_PORTUGAL                     351
#define MMIO_CC_LUXEMBOURG                   352
#define MMIO_CC_ICELAND                      354
#define MMIO_CC_FINLAND                      358

#define MMIO_LC_NONE                          0
#define MMIO_DC_NONE                          0
#define MMIO_LC_ARABIC                        1
#define MMIO_DC_ARABIC                        1
#define MMIO_LC_BULGARIAN                     2
#define MMIO_DC_BULGARIAN                     1
#define MMIO_LC_CATALAN                       3
#define MMIO_DC_CATALAN                       1
#define MMIO_LC_TRADITIONAL_CHINESE           4
#define MMIO_DC_TRADITIONAL_CHINESE           1
#define MMIO_LC_SIMPLE_CHINESE                4
#define MMIO_DC_SIMPLE_CHINESE                2
#define MMIO_LC_CZECH                         5
#define MMIO_DC_CZECH                         1
#define MMIO_LC_DANISH                        6
#define MMIO_DC_DANISH                        1
#define MMIO_LC_GERMAN                        7
#define MMIO_DC_GERMAN                        1
#define MMIO_LC_SWISS_GERMAN                  7
#define MMIO_DC_SWISS_GERMAN                  2
#define MMIO_LC_GREEK                         8
#define MMIO_DC_GREEK                         1
#define MMIO_LC_US_ENGLISH                    9
#define MMIO_DC_US_ENGLISH                    1
#define MMIO_LC_UK_ENGLISH                    9
#define MMIO_DC_UK_ENGLISH                    2
#define MMIO_LC_SPANISH                      10
#define MMIO_DC_SPANISH                       1
#define MMIO_LC_SPANISH_MEXICAN              10
#define MMIO_DC_SPANISH_MEXICAN               2
#define MMIO_LC_FINNISH                      11
#define MMIO_DC_FINNISH                       1
#define MMIO_LC_FRENCH                       12
#define MMIO_DC_FRENCH                        1
#define MMIO_LC_BELGIAN_FRENCH               12
#define MMIO_DC_BELGIAN_FRENCH                2
#define MMIO_LC_CANADIAN_FRENCH              12
#define MMIO_DC_CANADIAN_FRENCH               3
#define MMIO_LC_SWISS_FRENCH                 12
#define MMIO_DC_SWISS_FRENCH                  4
#define MMIO_LC_HEBREW                       13
#define MMIO_DC_HEBREW                        1
#define MMIO_LC_HUNGARIAN                    14
#define MMIO_DC_HUNGARIAN                     1
#define MMIO_LC_ICELANDIC                    15
#define MMIO_DC_ICELANDIC                     1
#define MMIO_LC_ITALIAN                      16
#define MMIO_DC_ITALIAN                       1
#define MMIO_LC_SWISS_ITALIAN                16
#define MMIO_DC_SWISS_ITALIAN                 2
#define MMIO_LC_JAPANESE                     17
#define MMIO_DC_JAPANESE                      1
#define MMIO_LC_KOREAN                       18
#define MMIO_DC_KOREAN                        1
#define MMIO_LC_DUTCH                        19
#define MMIO_DC_DUTCH                         1
#define MMIO_LC_BELGIAN_DUTCH                19
#define MMIO_DC_BELGIAN_DUTCH                 2
#define MMIO_LC_NORWEGIAN_BOKMAL             20
#define MMIO_DC_NORWEGIAN_BOKMAL              1
#define MMIO_LC_NORWEGIAN_NYNORSK            20
#define MMIO_DC_NORWEGIAN_NYNORSK             2
#define MMIO_LC_POLISH                       21
#define MMIO_DC_POLISH                        1
#define MMIO_LC_BRAZILIAN_PORTUGUESE         22
#define MMIO_DC_BRAZILIAN_PORTUGUESE          1
#define MMIO_LC_PORTUGUESE                   22
#define MMIO_DC_PORTUGUESE                    2
#define MMIO_LC_RHAETO_ROMANIC               23
#define MMIO_DC_RHAETO_ROMANIC                1
#define MMIO_LC_ROMANIAN                     24
#define MMIO_DC_ROMANIAN                      1
#define MMIO_LC_RUSSIAN                      25
#define MMIO_DC_RUSSIAN                       1
#define MMIO_LC_SERBO_CROATIAN_LATIN         26
#define MMIO_DC_SERBO_CROATIAN_LATIN          1
#define MMIO_LC_SERBO_CROATIAN_CYRILLIC      26
#define MMIO_DC_SERBO_CROATIAN_CYRILLIC       2
#define MMIO_LC_SLOVAK                       27
#define MMIO_DC_SLOVAK                        1
#define MMIO_LC_ALBANIAN                     28
#define MMIO_DC_ALBANIAN                      1
#define MMIO_LC_SWEDISH                      29
#define MMIO_DC_SWEDISH                       1
#define MMIO_LC_THAI                         30
#define MMIO_DC_THAI                          1
#define MMIO_LC_TURKISH                      31
#define MMIO_DC_TURKISH                       1
#define MMIO_LC_URDU                         32
#define MMIO_DC_URDU                          1
#define MMIO_LC_BAHASA                       33
#define MMIO_DC_BAHASA                        1


#define mmioFOURCC      (ch0, ch1, ch2, ch3) \
                        ((ULONG)(BYTE)(ch0)|((ULONG)(BYTE)(ch1)<<8)| \
                        ((ULONG)(BYTE)(ch2)<<16)|((ULONG)(BYTE)(ch3)<<24))

#define FOURCC_RIFF     mmioFOURCC( 'R', 'I', 'F', 'F' )
#define FOURCC_LIST     mmioFOURCC( 'L', 'I', 'S', 'T' )
#define FOURCC_MEM      mmioFOURCC( 'M', 'E', 'M', ' ' )
#define FOURCC_DOS      mmioFOURCC( 'D', 'O', 'S', ' ' )
#define FOURCC_BND      mmioFOURCC( 'B', 'N', 'D', ' ' )
#define FOURCC_FREE     mmioFOURCC( 'F', 'R', 'E', 'E' )
#define FOURCC_DEL      mmioFOURCC( 'D', 'E', 'L', ' ' )
#define FOURCC_CTOC     mmioFOURCC( 'C', 'T', 'O', 'C' )
#define FOURCC_CGRP     mmioFOURCC( 'C', 'G', 'R', 'P' )
#define FOURCC_CF       mmioFOURCC( 'C', 'F', ' ', ' ' )

#define HEX_FOURCC_DOS  0x20534f44L
#define HEX_FOURCC_MEM  0x204d454dL
#define HEX_FOURCC_BND  0x20444e42L
#define HEX_FOURCC_CF   0x20204643L


#ifndef _MEERROR_H_
    #define INCL_MMIO_ERRORS
    #include <meerror.h>
#endif


/************/
/* typedefs */
/************/

#ifndef _OS2MEDEF_H
    typedef ULONG HMMIO;
#endif

typedef HMMIO HMMCF;
typedef ULONG    FOURCC;
typedef FOURCC* PFOURCC;
typedef PSZ HPSTR;

typedef LONG (MMIOPROC)(PVOID pmmioinfo, USHORT usMsg,
                        LONG lParam1, LONG lParam2);
typedef MMIOPROC*   PMMIOPROC;
typedef MMIOPROC** PPMMIOPROC;


#ifdef INCL_GPI

    #ifdef INCL_GPIBITMAPS

        #define MAX_PALETTE  256

        typedef struct _XDIBHDR_PREFIX {
            ULONG  ulMemSize;
            ULONG  ulPelFormat;
            USHORT usTransType;
            ULONG  ulTransVal;
        } XDIBHDR_PREFIX;


        typedef struct _MMXDIBHEADER {
            XDIBHDR_PREFIX    XDIBHeaderPrefix;
            BITMAPINFOHEADER2 BMPInfoHeader2;
        } MMXDIBHEADER;

        typedef MMXDIBHEADER* PMMXDIBHEADER;

        typedef struct _MMIMAGEHEADER {
           ULONG        ulHeaderLength;
           ULONG        ulContentType;
           ULONG        ulMediaType;
           MMXDIBHEADER mmXDIBHeader;
           RGB2         bmiColors[MAX_PALETTE];
        } MMIMAGEHEADER;

        typedef MMIMAGEHEADER* PMMIMAGEHEADER;

    #endif

#endif


typedef struct _MMCKINFO {
    FOURCC ckid;
    ULONG  ckSize;
    FOURCC fccType;
    ULONG  ulDataOffset;
    ULONG  ulFlags;
} MMCKINFO;

typedef MMCKINFO* PMMCKINFO;


typedef struct _MMIOINFO {
    ULONG     ulFlags;
    FOURCC    fccIOProc;
    PMMIOPROC pIOProc;
    ULONG     ulErrorRet;
    LONG      cchBuffer;
    PCHAR     pchBuffer;
    PCHAR     pchNext;
    PCHAR     pchEndRead;
    PCHAR     pchEndWrite;
    LONG      lBufOffset;
    LONG      lDiskOffset;
    ULONG     aulInfo[4];
    LONG      lLogicalFilePos;
    ULONG     ulTranslate;
    FOURCC    fccChildIOProc;
    PVOID     pExtraInfoStruct;
    HMMIO     hmmio;
} MMIOINFO;

typedef MMIOINFO* PMMIOINFO;


typedef struct _MMCFINFO {
    ULONG  ulHeaderSize;
    ULONG  ulEntriesTotal;
    ULONG  ulEntriesDeleted;
    ULONG  ulEntriesUnused;
    ULONG  ulBytesTotal;
    ULONG  ulBytesDeleted;
    ULONG  ulHeaderFlags;
    USHORT usEntrySize;
    USHORT usNameSize;
    USHORT usExHdrFields;
    USHORT usExEntFields;
} MMCFINFO;

typedef MMCFINFO* PMMCFINFO;


typedef struct _MMCTOCENTRY {
    ULONG ulOffset;
    ULONG ulSize;
    ULONG ulMedType;
    ULONG ulMedUsage;
    ULONG ulCompressTech;
    ULONG ulUncompressBytes;
} MMCTOCENTRY;

typedef MMCTOCENTRY* PMMCTOCENTRY;


typedef struct _MMFORMATINFO {
    ULONG  ulStructLen;
    FOURCC fccIOProc;
    ULONG  ulIOProcType;
    ULONG  ulMediaType;
    ULONG  ulFlags;
    CHAR   szDefaultFormatExt[sizeof(FOURCC) + 1];
    ULONG  ulCodePage;
    ULONG  ulLanguage;
    LONG   lNameLength;
} MMFORMATINFO;

typedef MMFORMATINFO* PMMFORMATINFO;


typedef struct _WAVE_HEADER {
    USHORT usFormatTag;
    USHORT usChannels;
    ULONG  ulSamplesPerSec;
    ULONG  ulAvgBytesPerSec;
    USHORT usBlockAlign;
    USHORT usBitsPerSample;
} WAVE_HEADER;


typedef struct _XWAV_HEADERINFO {
    ULONG ulAudioLengthInMS;
    ULONG ulAudioLengthInBytes;
    ULONG ulReserved;
} XWAV_HEADERINFO;


typedef struct _MMXWAV_HEADER {         
    WAVE_HEADER     WAVEHeader;
    XWAV_HEADERINFO XWAVHeaderInfo;
} MMXWAV_HEADER;


typedef struct _MMAUDIOHEADER {
    ULONG         ulHeaderLength;
    ULONG         ulContentType;
    ULONG         ulMediaType;
    MMXWAV_HEADER mmXWAVHeader;
} MMAUDIOHEADER;

typedef MMAUDIOHEADER* PMMAUDIOHEADER;


typedef struct _MMINIFILEINFO {
    FOURCC fccIOProc;
    CHAR   szDLLName[DLLNAME_SIZE];
    CHAR   szProcName[PROCNAME_SIZE];
    ULONG  ulFlags;
    ULONG  ulExtendLen;
    ULONG  ulMediaType;
    ULONG  ulIOProcType;
    CHAR   szDefExt[sizeof(MAX_EXTENSION_NAME)];
} MMINIFILEINFO;

typedef MMINIFILEINFO* PMMINIFILEINFO;


#ifdef INCL_MMIO_CODEC

    typedef MMIOPROC* PCODECPROC;

    typedef struct _CODECINIFILEINFO {
        ULONG  ulStructLen;
        FOURCC fcc;
        CHAR   szDLLName[DLLNAME_SIZE];
        CHAR   szProcName[PROCNAME_SIZE];
        ULONG  ulCompressType;
        ULONG  ulCompressSubType;
        ULONG  ulMediaType;
        ULONG  ulCapsFlags;
        ULONG  ulFlags;
        CHAR   szHWID[CODEC_HW_NAME_SIZE];
        ULONG  ulMaxSrcBufLen;
        ULONG  ulSyncMethod;
        ULONG  ulReserved1;
        ULONG  ulXalignment;
        ULONG  ulYalignment;
        ULONG  ulSpecInfo[CODEC_INFO_SIZE];
    } CODECINIFILEINFO;

    typedef CODECINIFILEINFO* PCODECINIFILEINFO;


    #define CODEC_SYNC_METHOD_NO_DROP_FRAMES             0
    #define CODEC_SYNC_METHOD_DROP_FRAMES_IMMEDIATELY    1
    #define CODEC_SYNC_METHOD_DROP_FRAMES_PRECEDING_KEY  2

    #define CODEC_COMPRESS                               0x00000001
    #define CODEC_DECOMPRESS                             0x00000002
    #define CODEC_WINDOW_CLIPPING                        0x00000004
    #define CODEC_PALETTE_TRANS                          0x00000008
    #define CODEC_SELFHEAL                               0x00000010
    #define CODEC_SCALE_PEL_DOUBLE                       0x00000020
    #define CODEC_SCALE_PEL_HALVED                       0x00000040
    #define CODEC_SCALE_CONTINUOUS                       0x00000080
    #define CODEC_MULAPERTURE                            0x00000100
    #define CODEC_4_BIT_COLOR                            0x00000200
    #define CODEC_8_BIT_COLOR                            0x00000400
    #define CODEC_16_BIT_COLOR                           0x00000800
    #define CODEC_24_BIT_COLOR                           0x00001000
    #define CODEC_HARDWARE                               0x00002000
    #define CODEC_SYMMETRIC                              0x00004000
    #define CODEC_ASYMMETRIC                             0x00008000
    #define CODEC_DIRECT_DISPLAY                         0x00010000
    #define CODEC_DEFAULT                                0x00020000
    #define CODEC_ORIGIN_LOWERLEFT                       0x00040000
    #define CODEC_ORIGIN_UPPERLEFT                       0x00080000
    #define CODEC_SET_QUALITY                            0x00100000
    #define CODEC_DATA_CONSTRAINT                        0x00200000

    #define MMIO_SET_EXTENDEDINFO                        0X0001
    #define MMIO_QUERY_EXTENDEDINFO_BASE                 0x0002
    #define MMIO_QUERY_EXTENDEDINFO_ALL                  0x0004

    typedef struct _CODECASSOC {
        PVOID             pCodecOpen;
        PCODECINIFILEINFO pCODECIniFileInfo;
    } CODECASSOC;

    typedef CODECASSOC* PCODECASSOC;


    typedef struct _MMEXTENDINFO {
        ULONG       ulStructLen;
        ULONG       ulBufSize;
        ULONG       ulFlags;
        ULONG       ulTrackID;
        ULONG       ulNumCODECs;
        PCODECASSOC pCODECAssoc;
    } MMEXTENDINFO;

    typedef MMEXTENDINFO* PMMEXTENDINFO;


    #define MMIO_TRACK                                   0x00000001
    #define MMIO_NORMAL_READ                             0x00000002
    #define MMIO_SCAN_READ                               0x00000004
    #define MMIO_REVERSE_READ                            0x00000008
    #define MMIO_CODEC_ASSOC                             0x00000100

    #define MMIO_RESETTRACKS                             -1

    #define CODEC_START                                  0x0EC0
    #define CODEC_END                                    0x0EFF

    #define MMIOM_CODEC_CLOSE                            CODEC_START + 1
    #define MMIOM_CODEC_OPEN                             CODEC_START + 2
    #define MMIOM_CODEC_QUERYNAME                        CODEC_START + 3
    #define MMIOM_CODEC_QUERYNAMELENGTH                  CODEC_START + 4
    #define MMIOM_CODEC_COMPRESS                         CODEC_START + 5
    #define MMIOM_CODEC_DECOMPRESS                       CODEC_START + 6

#endif


/**************/
/* MMIO API's */
/**************/

USHORT mmioAdvance(HMMIO hmmio, PMMIOINFO pmmioinfo, USHORT usFlags);

USHORT mmioAscend(HMMIO hmmio, PMMCKINFO pckinfo, USHORT usFlags);

USHORT mmioClose(HMMIO hmmio, USHORT usFlags);

USHORT mmioCreateChunk(HMMIO hmmio, PMMCKINFO pckinfo, SHORT usFlags);

USHORT mmioDescend(HMMIO hmmio, PMMCKINFO pckinfo, PMMCKINFO pckinfoParent,
                   USHORT usFlags);

USHORT mmioFlush(HMMIO hmmio, USHORT usFlags);

USHORT mmioGetInfo(HMMIO hmmio, PMMIOINFO pmmioinfo, USHORT usFlags);

ULONG mmioGetLastError(HMMIO hmmio);

PMMIOPROC mmioInstallIOProc(FOURCC fccIOProc, PMMIOPROC pIOProc,
                            ULONG ulFlags);

LONG mmioIOProc(PMMIOINFO pmmioinfo, USHORT usMsg,
                LONG lParam1, LONG lParam2);

HMMIO mmioOpen(PSZ pszFileName, PMMIOINFO pmmioinfo, ULONG ulOpenFlags);

LONG mmioRead(HMMIO hmmio, PCHAR pchBuffer, LONG cBytes);

LONG mmioSeek(HMMIO hmmio, LONG lOffset, LONG lOrigin);

LONG mmioSendMessage(HMMIO hmmio, USHORT usMsg, LONG lParam1, LONG lParam2);

USHORT mmioSetBuffer(HMMIO hmmio, PCHAR pchBuffer, LONG cBytes,
                     USHORT usFlags);

USHORT mmioSetInfo(HMMIO hmmio, PMMIOINFO pmmioinfo, USHORT usFlags);

FOURCC mmioStringToFOURCC(PSZ pszString, USHORT usFlags);

LONG mmioWrite(HMMIO hmmio, PCHAR pchBuffer, LONG cBytes);

HMMCF mmioCFOpen(PSZ pszFileName, PMMCFINFO pmmcfinfo, PMMIOINFO pmmioinfo,
                 ULONG ulFlags);

ULONG mmioCFClose(HMMCF hmmcf, ULONG ulFlags);

ULONG mmioCFGetInfo(HMMCF hmmcf, PMMCFINFO pmmcfinfo, ULONG cBytes);

ULONG mmioCFSetInfo(HMMCF hmmcf, PMMCFINFO pmmcfinfo, ULONG cBytes);

ULONG mmioCFFindEntry(HMMCF hmmcf, PMMCTOCENTRY pmmctocentry, ULONG ulFlags);

ULONG mmioCFAddEntry(HMMCF hmmcf, PMMCTOCENTRY pmmctocentry, ULONG ulFlags);

ULONG mmioCFChangeEntry(HMMCF hmmcf, PMMCTOCENTRY pmmctocentry,
                        ULONG ulFlags);

ULONG mmioCFDeleteEntry(HMMCF hmmcf, PMMCTOCENTRY pmmctocentry,
                        ULONG ulFlags);

ULONG mmioCFAddElement(HMMCF hmmcf, PSZ pszElementName, FOURCC fccType,
                       PCHAR pchBuffer, LONG cchBytes, ULONG ulFlags);

ULONG mmioCFCopy(HMMCF hmmcfSource, PSZ pszDestFileName, ULONG ulFlags);

ULONG mmioQueryFormatCount(PMMFORMATINFO pmmformatinfo, PLONG plNumFormats,
                           ULONG ulReserved, ULONG ulFlags);

ULONG mmioGetFormats(PMMFORMATINFO pmmformatinfo, LONG lNumFormats,
                     PVOID pFormatInfoList, PLONG plFormatsRead,
                     ULONG ulReserved, ULONG ulFlags);

ULONG mmioGetFormatName(PMMFORMATINFO pmmformatinfo, PSZ pszFormatName,
                        PLONG plBytesRead, ULONG ulReserved, ULONG ulFlags);

ULONG mmioIdentifyFile(PSZ pszFileName, PMMIOINFO pmmioinfo,
                       PMMFORMATINFO pmmformatinfo, PFOURCC pfccStorageSystem,
                       ULONG ulReserved, ULONG ulFlags);

ULONG mmioQueryHeaderLength(HMMIO hmmio, PLONG plHeaderLength,
                            ULONG ulReserved, ULONG ulFlags);

ULONG mmioGetHeader(HMMIO hmmio, PVOID pHeader, LONG lHeaderLength,
                    PLONG plBytesRead, ULONG ulReserved, ULONG ulFlags);

ULONG mmioSetHeader(HMMIO hmmio, PVOID pHeader, LONG lHeaderLength,
                    PLONG plBytesWritten, ULONG ulReserved, ULONG ulFlags);

ULONG mmioIniFileHandler(PMMINIFILEINFO pmminifileinfo, ULONG ulFlags);

ULONG mmioIdentifyStorageSystem(PSZ pszFileName, PMMIOINFO pmmioinfo,
                                PFOURCC pfccStorageSystem);

ULONG mmioDetermineSSIOProc(PSZ pszFileName, PMMIOINFO pmmioinfo,
                            PFOURCC pfccStorageSystem,
                            PSZ pszParsedRemainder);

ULONG mmioQueryIOProcModuleHandle(PMMIOPROC pIOProc, PHMODULE phmodIOProc);

ULONG mmioCFCompact(PSZ pszFileName, ULONG ulFlags);

ULONG mmioMigrateIniFile(ULONG ulFlags);


#ifdef INCL_MMIO_CODEC
    ULONG mmioIniFileCODEC(PCODECINIFILEINFO pCODECIniFileInfo,
                           ULONG ulFlags);

    ULONG mmioSet(HMMIO hmmio, PMMEXTENDINFO pUserExtendmminfo,
                  ULONG ulFlags);

    ULONG mmioQueryCODECName(PCODECINIFILEINFO pCODECIniFileinfo,
                             PSZ pszCODECName, PULONG pulBytesRead);

    ULONG mmioQueryCODECNameLength(PCODECINIFILEINFO pCODECIniFileinfo,
                                   PULONG pulNameLength);
 
    PCODECPROC mmioLoadCODECProc(PCODECINIFILEINFO pCODECIniFileInfo,
                                 PHMODULE phMod, ULONG ulFlags);

    USHORT mmioGetData(HMMIO hmmio, PMMIOINFO pmmioinfo, USHORT usFlags);
#endif


/* set default alignment */
#pragma pack()

/* nested header management */
#endif

