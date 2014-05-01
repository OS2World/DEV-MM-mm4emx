/***********************************/
/* ssm.h -- Multimedia for emx 1.0 */
/*                                 */
/*                                 */
/* Marc E.E. van Woerkom, 2/94     */
/*                                 */
/***********************************/


/* nested header management */
#ifndef _SSM_H
#define _SSM_H

/* use 32-bit alignment */
#pragma pack(4)


/***********/
/* defines */
/***********/

#define MAX_SPI_NAME            9
#define SPCB_MAX_BUF_SIZE       (384L*1024L)

#define SPCBBUF_USERPROVIDED     0x0001L
#define SPCBBUF_FIXEDBUF         0x0002L
#define SPCBBUF_NONCONTIGUOUS    0x0004L
#define SPCBBUF_INTERLEAVED      0x0008L
#define SPCBBUF_MAXSIZE          0x0010L
#define SPCBBUF_16MEG            0x0020L

#define SPCBDATA_CUETIME         0x0002L
#define SPCBDATA_CUEDATA         0x0004L
#define SPCBDATA_SEEK            0x0000L
#define SPCBDATA_NOSEEK          0x0008L

#define SPCBHAND_GENSYNC         0x0001L
#define SPCBHAND_RCVSYNC         0x0002L
#define SPCBHAND_TIMER           0x0004L
#define SPCBHAND_NONSTREAM       0x0008L
#define SPCBHAND_GENTIME         0x0010L
#define SPCBHAND_NOPREROLL       0x0020L
#define SPCBHAND_NOSYNC          0x0040L
#define SPCBHAND_PHYS_SEEK       0x0080L

#define EVENT_SYNC               1L
#define EVENT_RESERVED           2L
#define EVENT_IMPLICIT_TYPE      3L
#define EVENT_SYNCOVERRUN        4L
#define EVENT_CUE_TIME           5L
#define EVENT_CUE_DATA           6L
#define EVENT_DATAUNDERRUN       7L
#define EVENT_DATAOVERRUN        8L
#define EVENT_CUE_TIME_PAUSE     9L
                                 
#define EVENT_EOS                1L
#define EVENT_ERROR              2L
#define EVENT_STREAM_STOPPED     3L
#define EVENT_SYNC_PREROLLED     4L
#define EVENT_PLAYLISTMESSAGE    5L
#define EVENT_PLAYLISTCUEPOINT   6L
#define EVENT_QUEUE_OVERFLOW     7L
                                 
#define EVENT_SINGLE             0L
#define EVENT_RECURRING          1L
#define EVENT_DATAPTR            2L
                                 
#define SH_TYPE                  0x80000000L
                                 
#define SYNCOVERRUN              0x0001L
#define SYNCPOLLING              0x0002L


#define MAX_PORT_NAME            40
#define MAX_PORTS                16
                                 
#define ACBTYPE_MMIO             0x0001L
#define ACBTYPE_MEM_PLAYL        0x0003L
#define ACBTYPE_CDDA             0x0004L
#define ACBTYPE_MISH             0x0005L
#define ACBTYPE_SET              0x0006L
#define ACBTYPE_NULLSH           0x0007L
#define ACBTYPE_MTSH             0x0008L
#define ACBTYPE_CODECSH          0x0009L
                                 
#define MIDI_MAP_ON              0x0000L
#define MIDI_MAP_OFF             0x0001L
                                 
#define TRACK_ACTIVATE           0x0000L
#define TRACK_DEACTIVATE         0x0001L


#define FLUSH_START              0x0001L
#define IOCTL_FUNC_SMH_REGISTER  0x0040
#define SH_DLL_TYPE              0
#define SH_PDD_TYPE              1
#define SSMDD_CATEGORY           0x0081
#define SPCBSIZE                 72L
#define SPI_RESOURCE             1

#define BUF_GETEMPTY             0x00000001L
#define BUF_RETURNFULL           0x00000002L
#define BUF_GETFULL              0x00000004L
#define BUF_RETURNEMPTY          0x00000008L
#define BUF_GIVEBUF              0x00000010L
#define BUF_EOS                  0x00000100L
#define BUF_RECORDS              0x00004000L
#define BUF_LASTRECORD           0x00008000L
#define BUF_LINEAR               0x00010000L
#define BUF_PHYSICAL             0x00020000L
#define BUF_RESERVED             0x00040000L
#define BUF_EXTENDED             0x80000000L

#define REGISTER_TGT_HNDLR       0x0001L
#define REGISTER_SRC_HNDLR       0x0002L
#define REGISTER_NONSTREAMING    0x0004L

#define SHC_ASSOCIATE             0L
#define SHC_CLOSE                 1L
#define SHC_CREATE                2L
#define SHC_DESTROY               3L
#define SHC_START                 4L
#define SHC_STOP                  5L
#define SHC_SEEK                  6L
#define SHC_ENABLE_EVENT          7L
#define SHC_DISABLE_EVENT         8L
#define SHC_ENABLE_SYNC           9L
#define SHC_DISABLE_SYNC         10L
#define SHC_GET_TIME             11L
#define SHC_GET_PROTOCOL         12L
#define SHC_INSTALL_PROTOCOL     13L
#define SHC_ENUMERATE_PROTOCOLS  14L
#define SHC_NEGOTIATE_RESULT     15L
#define SHC_SENDMSG              16L

#define SMH_REGISTER             0L
#define SMH_DEREGISTER           1L
#define SMH_REPORTEVENT          2L
#define SMH_NOTIFY               3L
#define SMH_LOCKMEM              4L

#define SPI_INSTALL_PROTOCOL     0x0000L
#define SPI_DEINSTALL_PROTOCOL   0x0001L

#define SPI_SEEK_ABSOLUTE        0x0000L
#define SPI_SEEK_RELATIVE        0x0001L
#define SPI_SEEK_FROMEND         0x0002L
#define SPI_SEEK_SLAVES          0x0010L
#define SPI_SEEK_MMTIME          0x0000L
#define SPI_SEEK_BYTES           0x0100L
#define SPI_SEEK_IFRAME          0x1000L
                                 
#define SPI_START_STREAM         0x0000L
#define SPI_START_SLAVES         0x0001L
#define SPI_START_PREROLL        0x0002L
                                 
#define SPI_STOP_STREAM          0x0000L
#define SPI_STOP_SLAVES          0x0001L
#define SPI_STOP_FLUSH           0x0002L
#define SPI_STOP_DISCARD         0x0004L

#define SSM_LOCKMEM              0x0000L
#define SSM_UNLOCKMEM            0x0001L
#define SSM_CONTIGLOCK           0x0002L

#define SYNC_MASTER              0x0000L
#define SYNC_SLAVE               0x0001L


#define VALIDBUFFLAGS           (SPCBBUF_USERPROVIDED  | \
                                 SPCBBUF_FIXEDBUF      | \
                                 SPCBBUF_NONCONTIGUOUS | \
                                 SPCBBUF_INTERLEAVED   | \
                                 SPCBBUF_16MEG         | \
                                 SPCBBUF_MAXSIZE)

#define VALIDDATAFLAGS          (SPCBDATA_CUETIME | \
                                 SPCBDATA_CUEDATA | \
                                 SPCBDATA_NOSEEK)

#define VALIDHANDFLAGS          (SPCBHAND_GENSYNC   | \
                                 SPCBHAND_RCVSYNC   | \
                                 SPCBHAND_TIMER     | \
                                 SPCBHAND_NONSTREAM | \
                                 SPCBHAND_GENTIME   | \
                                 SPCBHAND_NOPREROLL | \
                                 SPCBHAND_NOSYNC    | \
                                 SPCBHAND_PHYS_SEEK)

#define VALIDSOURCEFLAGS        (BUF_RETURNFULL | \
                                 BUF_GETEMPTY   | \
                                 BUF_EOS        | \
                                 BUF_LASTRECORD | \
                                 BUF_PHYSICAL   | \
                                 BUF_LINEAR     | \
                                 BUF_RECORDS    | \
                                 BUF_GIVEBUF    | \
                                 BUF_EXTENDED)
                                
#define VALIDTARGETFLAGS        (BUF_RETURNEMPTY | \
                                 BUF_GETFULL     | \
                                 BUF_PHYSICAL    | \
                                 BUF_LINEAR      | \
                                 BUF_EOS|BUF_EXTENDED)
                                
#define VALIDREGISTERFLAGS      (REGISTER_TGT_HNDLR | \
                                 REGISTER_SRC_HNDLR | \
                                 REGISTER_NONSTREAMING)
                                
#define VALIDINSTALLFLAGS       (SPI_INSTALL_PROTOCOL | \
                                 SPI_DEINSTALL_PROTOCOL)
                                
#define VALIDSEEKFLAGS          (SPI_SEEK_RELATIVE | \
                                 SPI_SEEK_ABSOLUTE | \
                                 SPI_SEEK_FROMEND  | \
                                 SPI_SEEK_MMTIME   | \
                                 SPI_SEEK_SLAVES   | \
                                 SPI_SEEK_IFRAME   | \
                                 SPI_SEEK_BYTES)
                                
#define VALIDSTARTFLAGS         (SPI_START_STREAM | \
                                 SPI_START_SLAVES | \
                                 SPI_START_PREROLL)
                                
#define VALIDSTOPFLAGS          (SPI_STOP_STREAM | \
                                 SPI_STOP_SLAVES | \
                                 SPI_STOP_FLUSH  | \
                                 SPI_STOP_DISCARD )


/************/
/* typedefs */
/************/

typedef ULONG RC;

typedef ULONG    HSTREAM;
typedef HSTREAM* PHSTREAM;
typedef ULONG    HEVENT;
typedef HEVENT*  PHEVENT;
typedef ULONG    HID;


typedef struct  _EVCB {
    ULONG   ulType;
    ULONG   ulSubType;
    ULONG   ulFlags;
    HSTREAM hstream;
    HID     hid;
    ULONG   ulStatus;
    ULONG   ulEventParm1;
    ULONG   ulEventParm2;
    ULONG   ulEventParm3;
} EVCB;

typedef EVCB* PEVCB;


typedef struct _ACB {
    ULONG ulACBLen;
    ULONG ulObjType;
    ULONG ulParm1;
    ULONG ulParm2;
} ACB;

typedef ACB* PACB;


typedef struct  _SPCB {
    ULONG   ulSPCBLen;
    SPCBKEY spcbkey;
    ULONG   ulDataFlags;
    ULONG   ulNumRec;
    ULONG   ulBlockSize;
    ULONG   ulBufSize;
    ULONG   ulMinBuf;
    ULONG   ulMaxBuf;
    ULONG   ulSrcStart;
    ULONG   ulTgtStart;
    ULONG   ulBufFlags;
    ULONG   ulHandFlags;
    MMTIME  mmtimeTolerance;
    MMTIME  mmtimeSync;
    ULONG   ulBytesPerUnit;
    MMTIME  mmtimePerUnit;
} SPCB;

typedef SPCB* PSPCB;


/* use 8-bit alignment */
#pragma pack(1)

typedef struct _ACB_CDDA {
    ULONG ulACBLen;
    ULONG ulObjType;
    CHAR  bCDDrive;
} ACB_CDDA;

typedef ACB_CDDA* PACB_CDDA;


typedef struct _DCB {
    ULONG ulDCBLen;
    SZ    szDevName[MAX_SPI_NAME];
} DCB;

typedef DCB* PDCB;


typedef struct E_DCB {
    ULONG ulDCBLen;
    SZ    szDevName[MAX_SPI_NAME];
    ULONG ulSysFileNum;
} E_DCB, DCB_AUDIOSH;

typedef E_DCB* PE_DCB;
typedef E_DCB* PDCB_AUDIOSH;


typedef struct _HAND {
    SZ szHandlerClass[MAX_SPI_NAME];
    SZ szHandlerName[MAX_SPI_NAME];
} HAND;

typedef HAND* PHAND;

/* use 32-bit alignment again */
#pragma pack(4)


typedef struct _SYNC_EVCB {
    ULONG   ulType;
    ULONG   ulSubType;
    ULONG   ulSyncFlags;
    HSTREAM hstream;
    HID     hid;
    ULONG   ulStatus;
    MMTIME  mmtimeStart;
    MMTIME  mmtimeMaster;
    MMTIME  mmtimeSlave;
} SYNC_EVCB;

typedef SYNC_EVCB* PSYNC_EVCB;


typedef ULONG (EVFN)(PEVCB pevcb);
typedef EVFN  (*PEVFN);
typedef ULONG (SHCFN)(PVOID pParmIn);
typedef SHCFN (*PSHCFN);
typedef ULONG (SMHFN)(PVOID pParmIn);
typedef SMHFN (*PSMHFN);


typedef struct _LOCKH {
    BYTE lock[16];
} LOCKH;

typedef LOCKH* PLOCKH;


typedef struct _SLAVE {
    HSTREAM hstreamSlave;
    MMTIME  mmtimeStart;
} SLAVE;

typedef SLAVE* PSLAVE;


typedef struct _MASTER {
    HSTREAM hstreamMaster;
} MASTER;

typedef MASTER* PMASTER;


typedef struct _MSG_COMMON {
    ULONG ulMsgLen;
} MSG_COMMON;


typedef struct _SMH_COMMON {
    ULONG ulFunction;
    HID   hid;
} SMH_COMMON;

typedef SMH_COMMON* PSMH_COMMON;


typedef struct _PARM_REG {
    ULONG  ulFunction;
    PSZ    pszSHName;
    HID*   phidSrc;
    HID*   phidTgt;
    PSHCFN pshcfnEntry;
    ULONG  ulFlags;
    ULONG  ulMaxNumStreams;
    ULONG  ulMaxNumEvents;
} PARM_REG;

typedef PARM_REG* PPARM_REG;


typedef struct _PARM_DEREG {
    ULONG ulFunction;
    PSZ   pszSHName;
} PARM_DEREG;

typedef PARM_DEREG* PPARM_DEREG;


typedef struct _PARM_EVENT {
    ULONG  ulFunction;
    HID    hid;
    HEVENT hevent;
    PEVCB  pevcbEvent;
} PARM_EVENT;

typedef PARM_EVENT* PPARM_EVENT;


typedef struct _PARM_NOTIFY {
    ULONG   ulFunction;
    HID     hid;
    HSTREAM hstream;
    ULONG   ulFlags;
    ULONG   ulGetNumEntries;
    ULONG   ulRetNumEntries;
    PVOID   pGetBufTab;
    PVOID   pRetBufTab;
} PARM_NOTIFY;

typedef PARM_NOTIFY* PPARM_NOTIFY;


typedef struct _SRCBUFTAB {
    PVOID  pBuffer;
    PVOID  pRecord;
    ULONG  ulLength;
    ULONG  ulMessageParm;
    MMTIME mmtimeOffset;
} SRCBUFTAB;

typedef SRCBUFTAB* PSRCBUFTAB;


typedef struct _TGTBUFTAB {
    PVOID  pBuffer;
    ULONG  ulBufId;
    ULONG  ulLength;
    ULONG  ulMessageParm;
    MMTIME mmtimeOffset;
} TGTBUFTAB;

typedef TGTBUFTAB* PTGTBUFTAB;


typedef struct  _PARM_ENOTIFY {
    ULONG   ulFunction;
    HID     hid;
    HSTREAM hstream;
    ULONG   ulFlags;
    ULONG   ulGetNumEntries;
    ULONG   ulRetNumEntries;
    PVOID   pGetBufTab;
    PVOID   pRetBufTab;
    ULONG   ulParm1;
    ULONG   ulParm2;
} PARM_ENOTIFY;

typedef PARM_ENOTIFY* PPARM_ENOTIFY;


typedef struct _ESRCBUFTAB {
    PVOID  pBuffer;
    PVOID  pRecord;
    ULONG  ulLength;
    ULONG  ulMessageParm;
    MMTIME mmtimeOffset;
    ULONG  ulParm1;
    ULONG  ulParm2;
} ESRCBUFTAB;

typedef ESRCBUFTAB* PESRCBUFTAB;


typedef struct _ETGTBUFTAB {
    PVOID  pBuffer;
    ULONG  ulBufId;
    ULONG  ulLength;
    ULONG  ulMessageParm;
    MMTIME mmtimeOffset;
    ULONG  ulParm1;
    ULONG  ulParm2;
} ETGTBUFTAB;

typedef ETGTBUFTAB* PETGTBUFTAB;


typedef struct _PARM_LOCKM {
    ULONG  ulFunction;
    PVOID  pBuffer;
    ULONG  ulBufSize;
    PLOCKH plockh;
    ULONG  ulFlags;
} PARM_LOCKM;

typedef PARM_LOCKM* PPARM_LOCKM;


typedef struct _SHC_COMMON {
    ULONG ulFunction;
    HID   hid;
} SHC_COMMON;

typedef SHC_COMMON* PSHC_COMMON;


typedef struct _PARM_ASSOC {
    ULONG   ulFunction;
    HID     hid;
    HSTREAM hstream;
    PACB    pacb;
} PARM_ASSOC;

typedef PARM_ASSOC* PPARM_ASSOC;


typedef struct _PARM_CLOSE {
    ULONG ulFunction;
    HID   hid;
} PARM_CLOSE;

typedef PARM_CLOSE* PPARM_CLOSE;


typedef struct _PARM_CREATE {
    ULONG   ulFunction;
    HID     hid;
    HSTREAM hstream;
    SPCBKEY spcbkey;
    PSPCB   pspcb;
    HSTREAM hstreamBuf;
    PDCB    pdcb;
} PARM_CREATE;

typedef PARM_CREATE* PPARM_CREATE;


typedef struct _PARM_DESTROY {
     ULONG   ulFunction;
     HID     hid;       
     HSTREAM hstream;   
} PARM_DESTROY;

typedef PARM_DESTROY* PPARM_DESTROY;


typedef struct _PARM_START {
    ULONG   ulFunction;
    HID     hid;
    HSTREAM hstream;
    ULONG   ulFlags;
} PARM_START;

typedef PARM_START* PPARM_START;


typedef struct _PARM_STOP {
    ULONG   ulFunction;
    HID     hid;
    HSTREAM hstream;
    ULONG   ulFlags;
} PARM_STOP;

typedef PARM_STOP* PPARM_STOP;


typedef struct _PARM_SEEK {
    ULONG   ulFunction;
    HID     hid;
    HSTREAM hstream;
    ULONG   ulFlags;
    LONG    lSeekPoint;
} PARM_SEEK;

typedef PARM_SEEK* PPARM_SEEK;


typedef struct _PARM_ENEVENT {
    ULONG  ulFunction;
    HID    hid;
    HEVENT hevent;
    PEVCB  pevcbUser;
} PARM_ENEVENT;

typedef PARM_ENEVENT* PPARM_ENEVENT;


typedef struct _PARM_DISEVENT {
    ULONG   ulFunction;
    HID     hid;
    HSTREAM hstream;
    HEVENT  hevent;
} PARM_DISEVENT;

typedef PARM_DISEVENT* PPARM_DISEVENT;


typedef struct _PARM_ENSYNC { 
    ULONG      ulFunction;
    HID        hid;
    HSTREAM    hstream;
    ULONG      ulFlags;
    MMTIME     mmtimeSync;
    PSYNC_EVCB pevcbSyncPulse;
    ULONG      ulSyncPulseSem;
} PARM_ENSYNC;

typedef PARM_ENSYNC* PPARM_ENSYNC;


typedef struct _PARM_DISSYNC {
    ULONG   ulFunction;
    HID     hid;
    HSTREAM hstream;
} PARM_DISSYNC;

typedef PARM_DISSYNC* PPARM_DISSYNC;


typedef struct _PARM_GTIME {
    ULONG   ulFunction;
    HID     hid;
    HSTREAM hstream;
    MMTIME  mmtimeCurrent;
} PARM_GTIME;

typedef PARM_GTIME* PPARM_GTIME;


typedef struct _PARM_GPROT {
    ULONG   ulFunction;
    HID     hid;
    SPCBKEY spcbkey;
    PSPCB   pspcb;
} PARM_GPROT;

typedef PARM_GPROT* PPARM_GPROT;


typedef struct _PARM_INSTPROT {
    ULONG   ulFunction;
    HID     hid;
    SPCBKEY spcbkey;
    PSPCB   pspcb;
    ULONG   ulFlags;
} PARM_INSTPROT;

typedef PARM_INSTPROT* PPARM_INSTPROT;


typedef struct _PARM_ENUMPROT {
    ULONG  ulFunction;
    HID    hid;
    PVOID  paSPCBKeys;
    PULONG pulNumSPCBKeys;
} PARM_ENUMPROT;

typedef PARM_ENUMPROT* PPARM_ENUMPROT;


typedef struct _PARM_NEGOTIATE {
    ULONG   ulFunction;
    HID     hid;
    HSTREAM hstream;
    PSPCB   pspcb;
    ULONG   ulErrorStatus;
} PARM_NEGOTIATE;

typedef PARM_NEGOTIATE* PPARM_NEGOTIATE;


typedef struct _PARM_SNDMSG {
    ULONG    ulFunction;
    HID      hid;
    HSTREAM  hstream;
    ULONG    ulMsgType;
    PVOID    pMsg;
} PARM_SNDMSG;

typedef PARM_SNDMSG* PPARM_SNDMSG;


typedef struct _IMPL_EVCB {
    ULONG   ulType;
    ULONG   ulSubType;
    ULONG   ulFlags;
    HSTREAM hstream;
    HID     hid;
    ULONG   ulStatus;
    ULONG   unused1;
    ULONG   unused2;
    ULONG   unused3;
} IMPL_EVCB;

typedef IMPL_EVCB* PIMPL_EVCB;


typedef struct _PLAYL_EVCB {
    ULONG   ulType;
    ULONG   ulSubType;
    ULONG   ulFlags;
    HSTREAM hstream;
    HID     hid;
    ULONG   ulStatus;
    ULONG   ulMessageParm;
    ULONG   unused1;
    ULONG   unused2;
} PLAYL_EVCB;

typedef PLAYL_EVCB* PPLAYL_EVCB;


typedef struct _OVRU_EVCB {
    ULONG   ulType;
    ULONG   ulSubType;
    ULONG   ulFlags;
    HSTREAM hstream;
    HID     hid;
    ULONG   ulStatus;
    MMTIME  mmtimeSlave;
    MMTIME  mmtimeStart;
    MMTIME  mmtimeMaster;
} OVRU_EVCB;

typedef OVRU_EVCB* POVRU_EVCB;


typedef struct  _TIME_EVCB {
    ULONG   ulType;
    ULONG   ulSubType;
    ULONG   ulFlags;
    HSTREAM hstream;
    HID     hid;
    ULONG   ulStatus;
    MMTIME  mmtimeStream;
    ULONG   unused1;
    ULONG   unused2;
} TIME_EVCB;

typedef TIME_EVCB* PTIME_EVCB;


typedef struct _DATA_EVCB {
    ULONG   ulType;
    ULONG   ulSubType;
    ULONG   ulFlags;
    HSTREAM hstream;
    HID     hid;
    ULONG   ulStatus;
    MMTIME  mmtimeStream;
    ULONG   ulEventParm1;
    ULONG   ulEventParm2;
} DATA_EVCB;

typedef DATA_EVCB* PDATA_EVCB;


typedef struct _ACB_MMIO {
    ULONG ulACBLen;
    ULONG ulObjType;
    HMMIO hmmio;
} ACB_MMIO;

typedef ACB_MMIO* PACB_MMIO;


typedef struct _ACB_MEM_PLAYL {
    ULONG ulACBLen;
    ULONG ulObjType;
    PVOID pMemoryAddr;
} ACB_MEM_PLAYL;

typedef ACB_MEM_PLAYL* PACB_MEM_PLAYL;


typedef struct _ACB_MISH {
    ULONG   ulACBLen;
    ULONG   ulObjType;
    HSTREAM hstreamDefault;
    ULONG   ulDeviceTypeID;
    ULONG   ulpMapperPorts;
    ULONG   ulNumInStreams;
    HSTREAM hstreamIn[MAX_PORTS];
    ULONG   ulNumOutStreams;
    HSTREAM hstreamOut[MAX_PORTS];
} ACB_MISH;

typedef ACB_MISH* PACB_MISH;


typedef struct _ACB_SET {
    ULONG ulACBLen;
    ULONG ulObjType;
    ULONG ulFlags;
    ULONG ulReserved;
} ACB_SET;

typedef ACB_SET* PACB_SET;


typedef struct _ACB_NULLSH {
    ULONG ulACBLen;
    ULONG ulObjType;
    PFN   pfnEntry;
    ULONG ulReserved;
} ACB_NULLSH;

typedef ACB_NULLSH* PACB_NULLSH;


typedef struct _ACB_MTSH   {
    ULONG       ulACBLen;
    ULONG       ulObjType;
    HMMIO       hmmio;
    MMTRACKINFO mmtrackInfo;
    ULONG       ulFlags;
} ACB_MTSH;

typedef ACB_MTSH* PACB_MTSH;


typedef struct _ACB_CODECSH {
    ULONG   ulACBLen;
    ULONG   ulObjType;
    HSTREAM hstreamToPair;
    PVOID   pMmioInfo;
    ULONG   ulInfoLength;
    PVOID   pCodecControl;
    ULONG   ulControlLength;
} ACB_CODECSH;

typedef ACB_CODECSH* PACB_CODECSH;


/*************/
/* SSM API's */
/*************/

ULONG SpiAssociate(HSTREAM hstream, HID hid, PACB pacb);

ULONG SpiEnumerateHandlers(PHAND pahand, PULONG pulNumHand);

ULONG SpiGetHandler(PSZ pszHName, HID* phidSrc, HID* phidTgt);

ULONG SpiCreateStream(HID hidSrc, HID hidTgt, PSPCBKEY pspcbkey,
                      PDCB pdcbSrc, PDCB pdcbTgt, PIMPL_EVCB pevcb,
                      PEVFN EventEntry, HSTREAM hstreamBuf,
                      PHSTREAM phstream, PHEVENT phevent);

ULONG SpiSendMsg(HSTREAM hstream, HID hid, ULONG ulMsgType, PVOID pMsg);

ULONG SpiDestroyStream(HSTREAM hstream);

ULONG SpiGetTime(HSTREAM hstream, PMMTIME pmmtime);

ULONG SpiSeekStream(HSTREAM hstream, ULONG ulFlags, LONG lSeekPoint);

ULONG SpiStartStream(HSTREAM hstream, ULONG ulFlags);

ULONG SpiStopStream(HSTREAM hstream, ULONG ulFlags);

ULONG SpiDisableEvent(HEVENT hevent);

ULONG SpiEnableEvent(PEVCB pevcb, PHEVENT phevent);

ULONG SpiDisableSync(HSTREAM hstreamMaster);

ULONG SpiEnableSync(HSTREAM hstreamMaster, PSLAVE paslaveList,
                    ULONG ulNumSlaves, MMTIME mmtimeSync);

ULONG SpiDetermineSyncMaster(PHSTREAM phstreamMaster, PMASTER paMasterList,
                             ULONG ulNumMasters);

ULONG SpiGetProtocol(HID hid, PSPCBKEY pspcbkey, PSPCB pspcb);

ULONG SpiInstallProtocol(HID hid, PSPCBKEY pspcbkey,
                         PSPCB pspcb, ULONG ulFlags);

ULONG SpiEnumerateProtocols(HID hid, PVOID paSPCBKeys, PULONG pulNumSPCBKeys);

ULONG SMHEntryPoint(PVOID pParmIn);


/* set default alignment */
#pragma pack()

/* nested header management */
#endif

