/****************************************/
/* mmdrvos2.h -- Multimedia for emx 1.0 */
/*                                      */
/*                                      */
/* Marc E.E. van Woerkom, 2/94          */
/*                                      */
/****************************************/


/* nested header management */
#ifndef _MMDRVOS2_H
#define _MMDRVOS2_H

/* use 8-bit alignment */
#pragma pack(1)


/***********/
/* defines */
/***********/

#define FIXEDSINGLECONTEXT                   0x0001
#define DYNAMICSINGLECONTEXT                 0x0002
#define LIMITEDMULTIPLECONTEXT               0x0003
#define UNLIMITEDMULTIPLECONTEXT             0x0004

#define MCIDRV_SAVE                          900
#define MCIDRV_RESTORE                       901
#define MCIDRV_SYNC                          902
#define MCIDRV_CHANGERESOURCE                903

#define MCIDRV_SYNC_ENABLE                   0x0100L
#define MCIDRV_SYNC_DISABLE                  0x0200L
#define MCIDRV_SYNC_REC_PULSE                0x0400L
#define MCIDRV_SYNC_MASTER                   0x0800L
#define MCIDRV_SYNC_SET_MASTER               0x1000L

#define MCI_INTERNAL_MESSAGES_START          1000
#define MCI_INTERNAL_MESSAGES_END            1999

#define MCI_CLOSE_EXIT                       0x10000000L

#define MCI_COMMAND_HEAD                     0x0001L
#define MCI_END_COMMAND                      0x0002L
#define MCI_END_COMMAND_LIST                 0x0003L
#define MCI_RETURN                           0x0004L
#define MCI_STRING                           0x0005L
#define MCI_FLAG                             0x0006L
#define MCI_INTEGER                          0x0007L
#define MCI_CONSTANT                         0x0008L
#define MCI_CONSTANT_INTEGER                 0x0009L
#define MCI_CONSTANT_STRING                  0x000AL
#define MCI_END_CONSTANT                     0x000BL
#define MCI_DEFAULT_STRING                   0x000CL
#define MCI_DEFAULT_INTEGER                  0x000DL
#define MCI_RETURN_TYPE                      0x000EL
#define MCI_RETURN_TYPE_STRING               0x000FL
#define MCI_END_RETURN_TYPE                  0x0010L
#define MCI_CONSTANT_2                       0x0011L
#define MCI_END_CONSTANT_2                   0x0012L
#define MCI_CONSTANT_PAIR                    0x0013L
#define MCI_END_CONSTANT_PAIR                0x0014L
#define MCI_CONSTANT_INTEGER_PAIR            0x0015L
#define MCI_CONSTANT_STRING_PAIR             0x0016L
#define MCI_RECTL                            0x0017L
#define MCI_CONSTANT_4                       0x0018L
#define MCI_END_CONSTANT_4                   0x0019L
#define MCI_FOURCC                           0x001AL
#define MCI_OR                               0x001BL
#define MCI_END_OR                           0x001CL
#define MCI_STRING_LIST                      0x001DL

#define MCI_INTEGER_RETURNED                 0x1000
#define MCI_COLONIZED2_RETURN                0x2000
#define MCI_COLONIZED3_RETURN                0x3000
#define MCI_COLONIZED4_RETURN                0x4000
#define MCI_TRUE_FALSE_RETURN                0x5000
#define MCI_ON_OFF_RETURN                    0x6000
#define MCI_DEVICENAME_RETURN                0x7000
#define MCI_TIME_FORMAT_RETURN               0x8000
#define MCI_SPEED_FORMAT_RETURN              0x9000
#define MCI_MODE_RETURN                      0xA000
#define MCI_MEDIA_TYPE_RETURN                0xB000
#define MCI_TRACK_TYPE_RETURN                0xC000
#define MCI_CONNECTOR_TYPE_RETURN            0xD000
#define MCI_CDXA_CHANNEL_DESTINATION_RETURN  0xE000
#define MCI_PREROLL_TYPE_RETURN              0xF000
#define MCI_FORMAT_TAG_RETURN                0xF100
#define MCI_SEQ_SYNCHRONIZATION_RETURN       0xF200
#define MCI_VIDEO_QUALITY_RETURN             0xF300
#define MCI_AUDIO_QUALITY_RETURN             0xF400
#define MCI_IMAGE_QUALITY_RETURN             0xF500
#define MCI_VIDEO_COMPRESSION_RETURN         0xF600
#define MCI_AUDIO_COMPRESSION_RETURN         0xF700
#define MCI_IMAGE_COMPRESSION_RETURN         0xF800
#define MCI_RECTL_RETURN                     0xF900
#define MCI_FOURCC_RETURN                    0xFA00
#define MCI_USER_RETURN                      0xFF01

#define MCIERR_MSG_TABLE_END                 MCIERR_BASE + 7000

#define MMERROR_TABLE_BASE                   500


/************/
/* typedefs */
/************/

typedef struct _MCIDRV_CHANGERESOURCE_PARMS {
    PVOID  pInstance;
    USHORT usResourceUnits;
    USHORT usResourceClass;
    USHORT usResourcePriority;
} MCIDRV_CHANGERESOURCE_PARMS;

typedef struct _MCIDRV_SYNC_PARMS {
    HSTREAM*   hStreams;
    ULONG      ulNumStreams;
    MMTIME     mmTime;
    BOOL       NonStreamMaster;
    PSYNC_EVCB pevcbSyncPulse;
    HID        hidMaster;
    ULONG      ulReserved1;
    ULONG      ulReserved2;
} MCIDRV_SYNC_PARMS;

typedef struct __MMDRV_OPEN_PARMS {
    HWND   hwndCallback;
    USHORT usDeviceID;
    USHORT usDeviceType;
    USHORT usDeviceOrd;
    PVOID  pInstance;
    CHAR   szDevDLLName[260];
    PSZ    pszElementName;
    USHORT usDevParmLen;
    PVOID  pDevParm;
    PVOID  Reserved0;
    USHORT usResourceUnitsRequired;
    USHORT usResourceClass;
    USHORT usResourcePriority;
    ULONG  ulParam2;
} MMDRV_OPEN_PARMS;


typedef USHORT                       GID;
typedef MCIDRV_CHANGERESOURCE_PARMS* PMCIDRV_CHANGERESOURCE_PARMS;
typedef MCIDRV_SYNC_PARMS*           PMCIDRV_SYNC_PARMS;
typedef MMDRV_OPEN_PARMS*            PMMDRV_OPEN_PARMS;


/*******/
/* API */
/*******/

ULONG mdmDriverNotify(USHORT usDeviceID, HWND hwnd, USHORT usMsgType,
                      USHORT usUserParm, ULONG ulMsgParm);


/* set default alignment */
#pragma pack()

/* nested header management */
#endif

