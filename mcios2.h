/**************************************/
/* mcios2.h -- Multimedia for emx 1.0 */
/*                                    */
/*                                    */
/* Marc E.E. van Woerkom, 2/94        */
/*                                    */
/**************************************/


/* nested header management */
#ifndef _MCIOS2_H
#define _MCIOS2_H

/* use 8-bit alignment */
#pragma pack(1)


/***************/
/* definitions */
/***************/

#define MCI_TRUE   1
#define MCI_FALSE  0


/**********/
/* limits */
/**********/

#define MAX_DEVICE_NAME      20
#define MAX_ALIAS_NAME       20
#define MAX_PRODINFO         40
#define MAX_EXTENSION_NAME    4
#define MAX_DEV_PARAMS      128
#define MAX_VERSION_NUMBER    6
#define MAX_PDD_NAME          9
#define MAX_DLL_NAME        260
#define MAX_CLASSES          10
#define MAX_CONNECTORS       10
#define MAX_EXTENSIONS       25
#define MAX_TYPEBUFFER      256


/************************/
/* MCI command messages */
/************************/

#define MCI_OPEN                  1
#define MCI_CLOSE                 2
#define MCI_ESCAPE                3
#define MCI_PLAY                  4
#define MCI_SEEK                  5
#define MCI_STOP                  6
#define MCI_PAUSE                 7
#define MCI_INFO                  8
#define MCI_GETDEVCAPS            9
#define MCI_STATUS               10
#define MCI_SPIN                 11
#define MCI_SET                  12
#define MCI_STEP                 13
#define MCI_RECORD               14
#define MCI_SYSINFO              15
#define MCI_SAVE                 16
#define MCI_CUE                  17
#define MCI_UPDATE               18
#define MCI_SET_CUEPOINT         19
#define MCI_SET_POSITION_ADVISE  20
#define MCI_SET_SYNC_OFFSET      21
#define MCI_LOAD                 22
#define MCI_ACQUIREDEVICE        23
#define MCI_RELEASEDEVICE        24
#define MCI_MASTERAUDIO          25
#define MCI_GETTOC               26
#define MCI_DEVICESETTINGS       27
#define MCI_CONNECTOR            28
#define MCI_RESUME               29
#define MCI_CONNECTORINFO        31
#define MCI_DEFAULT_CONNECTION   32
#define MCI_CONNECTION           33
#define MCI_GROUP                34
#define MCI_CAPTURE              40
#define MCI_FREEZE               41
#define MCI_GETIMAGEBUFFER       42
#define MCI_GETIMAGEPALETTE      43
#define MCI_PUT                  44
#define MCI_REALIZE              45
#define MCI_REWIND               46
#define MCI_RESTORE              47
#define MCI_SETIMAGEBUFFER       48
#define MCI_SETIMAGEPALETTE      49
#define MCI_UNFREEZE             50
#define MCI_WHERE                51
#define MCI_WINDOW               52
#define MCI_DELETE               53
#define MCI_CUT                  54
#define MCI_PASTE                55
#define MCI_COPY                 56
#define MCI_REDO                 57
#define MCI_UNDO                 58
/*#define MCI_MAX_COMMAND          58*/
#define MCI_USER_MESSAGES      2000

/*DART*/
#define MCI_BUFFER               62
#define MCI_MIXSETUP             63
#define MCI_MAX_COMMAND          64

/****************/
/* device stuff */
/****************/

#define MCI_ALL_DEVICE_ID  0xFFFF

#define MCI_DEVTYPE_VIDEOTAPE        1
#define MCI_DEVTYPE_VIDEODISC        2
#define MCI_DEVTYPE_CD_AUDIO         3
#define MCI_DEVTYPE_DAT              4
#define MCI_DEVTYPE_AUDIO_TAPE       5
#define MCI_DEVTYPE_OTHER            6
#define MCI_DEVTYPE_WAVEFORM_AUDIO   7
#define MCI_DEVTYPE_SEQUENCER        8
#define MCI_DEVTYPE_AUDIO_AMPMIX     9
#define MCI_DEVTYPE_OVERLAY         10
#define MCI_DEVTYPE_ANIMATION       11
#define MCI_DEVTYPE_DIGITAL_VIDEO   12
#define MCI_DEVTYPE_SPEAKER         13
#define MCI_DEVTYPE_HEADPHONE       14
#define MCI_DEVTYPE_MICROPHONE      15
#define MCI_DEVTYPE_MONITOR         16
#define MCI_DEVTYPE_CDXA            17

#define MCI_MAX_SYSTEM_DEVICE_NAMES  17

#define MCI_DEVTYPE_VIDEOTAPE_NAME       "Videotape"
#define MCI_DEVTYPE_VIDEODISC_NAME       "Videodisc"
#define MCI_DEVTYPE_CD_AUDIO_NAME        "CDaudio"
#define MCI_DEVTYPE_DAT_NAME             "DAT"
#define MCI_DEVTYPE_AUDIO_TAPE_NAME      "Audiotape"
#define MCI_DEVTYPE_OTHER_NAME           "Other"
#define MCI_DEVTYPE_WAVEFORM_AUDIO_NAME  "Waveaudio"
#define MCI_DEVTYPE_SEQUENCER_NAME       "Sequencer"
#define MCI_DEVTYPE_AUDIO_AMPMIX_NAME    "Ampmix"
#define MCI_DEVTYPE_OVERLAY_NAME         "Overlay"
#define MCI_DEVTYPE_ANIMATION_NAME       "Animation"
#define MCI_DEVTYPE_DIGITAL_VIDEO_NAME   "Digitalvideo"
#define MCI_DEVTYPE_SPEAKER_NAME         "Speaker"
#define MCI_DEVTYPE_HEADPHONE_NAME       "Headphone"
#define MCI_DEVTYPE_MICROPHONE_NAME      "Microphone"
#define MCI_DEVTYPE_MONITOR_NAME         "Monitor"
#define MCI_DEVTYPE_CDXA_NAME            "CDXA"


/********************/
/* item base values */
/********************/

#define MCI_AMP_ITEM_BASE   0x1000L
#define MCI_CD_ITEM_BASE    0x2000L
#define MCI_CDXA_ITEM_BASE  0x3000L
#define MCI_VD_ITEM_BASE    0x4000L
#define MCI_SEQ_ITEM_BASE   0x5000L
#define MCI_WAVE_ITEM_BASE  0x6000L
#define MCI_VID_ITEM_BASE   0x7000L
#define MCI_DGV_ITEM_BASE   0x8000L
#define MCI_OVLY_ITEM_BASE  0x9000L


/*********/
/* items */
/*********/

#define MCI_AMP_STATUS_PITCH     MCI_AMP_ITEM_BASE
#define MCI_AMP_STATUS_TREBLE   (MCI_AMP_ITEM_BASE+1)
#define MCI_AMP_STATUS_BASS     (MCI_AMP_ITEM_BASE+2)
#define MCI_AMP_STATUS_BALANCE  (MCI_AMP_ITEM_BASE+3)
#define MCI_AMP_STATUS_GAIN     (MCI_AMP_ITEM_BASE+4)
#define MCI_AMP_STATUS_MONITOR  (MCI_AMP_ITEM_BASE+5)

#define MCI_CD_STATUS_TRACK_TYPE            MCI_CD_ITEM_BASE
#define MCI_CD_STATUS_TRACK_COPYPERMITTED  (MCI_CD_ITEM_BASE+1)
#define MCI_CD_STATUS_TRACK_CHANNELS       (MCI_CD_ITEM_BASE+2)
#define MCI_CD_STATUS_TRACK_PREEMPHASIS    (MCI_CD_ITEM_BASE+3)

#define MCI_CDXA_STATUS_CHANNEL  MCI_CDXA_ITEM_BASE

#define MCI_VD_STATUS_SPEED       MCI_VD_ITEM_BASE
#define MCI_VD_STATUS_FORWARD    (MCI_VD_ITEM_BASE+1)
#define MCI_VD_MEDIA_TYPE        (MCI_VD_ITEM_BASE+2)
#define MCI_VD_STATUS_SIDE       (MCI_VD_ITEM_BASE+3)
#define MCI_VD_STATUS_DISC_SIZE  (MCI_VD_ITEM_BASE+4)

#define MCI_SEQ_STATUS_TEMPO     MCI_SEQ_ITEM_BASE
#define MCI_SEQ_STATUS_OFFSET   (MCI_SEQ_ITEM_BASE+1)
#define MCI_SEQ_STATUS_DIVTYPE  (MCI_SEQ_ITEM_BASE+2)
#define MCI_SEQ_STATUS_MASTER   (MCI_SEQ_ITEM_BASE+3)
#define MCI_SEQ_STATUS_PORT     (MCI_SEQ_ITEM_BASE+4)
#define MCI_SEQ_STATUS_SLAVE    (MCI_SEQ_ITEM_BASE+5)

#define MCI_WAVE_STATUS_LEVEL            MCI_WAVE_ITEM_BASE
#define MCI_WAVE_STATUS_SAMPLESPERSEC   (MCI_WAVE_ITEM_BASE+1)
#define MCI_WAVE_STATUS_AVGBYTESPERSEC  (MCI_WAVE_ITEM_BASE+2)
#define MCI_WAVE_STATUS_BLOCKALIGN      (MCI_WAVE_ITEM_BASE+3)
#define MCI_WAVE_STATUS_FORMATTAG       (MCI_WAVE_ITEM_BASE+4)
#define MCI_WAVE_STATUS_CHANNELS        (MCI_WAVE_ITEM_BASE+5)
#define MCI_WAVE_STATUS_BITSPERSAMPLE   (MCI_WAVE_ITEM_BASE+6)

#define MCI_VID_SET_VIDEO_COMPRESSION            MCI_VID_ITEM_BASE
#define MCI_VID_SET_IMAGE_COMPRESSION           (MCI_VID_ITEM_BASE+1)
#define MCI_VID_SET_IMAGE_BITSPERPEL            (MCI_VID_ITEM_BASE+2)
#define MCI_VID_SET_IMAGE_PELFORMAT             (MCI_VID_ITEM_BASE+3)
#define MCI_VID_SET_BRIGHTNESS                  (MCI_VID_ITEM_BASE+4)
#define MCI_VID_SET_CONTRAST                    (MCI_VID_ITEM_BASE+5)
#define MCI_VID_SET_HUE                         (MCI_VID_ITEM_BASE+6)
#define MCI_VID_SET_SATURATION                  (MCI_VID_ITEM_BASE+7)
#define MCI_VID_SET_SHARPNESS                   (MCI_VID_ITEM_BASE+8)
#define MCI_VID_SET_GREYSCALE                   (MCI_VID_ITEM_BASE+9)
#define MCI_VID_SET_IMAGE_QUALITY               (MCI_VID_ITEM_BASE+10)
#define MCI_VID_SET_VIDEO_QUALITY               (MCI_VID_ITEM_BASE+11)
#define MCI_VID_SET_IMAGE_COMPRESSION_METHOD    (MCI_VID_ITEM_BASE+12)
#define MCI_VID_SET_MINIMUM_VIDEO_REFRESH_RATE  (MCI_VID_ITEM_BASE+13)
#define MCI_VID_SET_IMAGE_FILE_FORMAT           (MCI_VID_ITEM_BASE+14)
#define MCI_VID_SET_REF_INTERVAL                (MCI_VID_ITEM_BASE+15)
#define MCI_VID_SET_MAXDATARATE                 (MCI_VID_ITEM_BASE+16)
#define MCI_VID_SET_VIDEO_FILE_FORMAT           (MCI_VID_ITEM_BASE+17)

#define MCI_VID_STATUS_HWND                MCI_VID_ITEM_BASE
#define MCI_VID_STATUS_AUDIO_COMPRESSION  (MCI_VID_ITEM_BASE+1)
#define MCI_VID_STATUS_VIDEO_COMPRESSION  (MCI_VID_ITEM_BASE+2)
#define MCI_VID_STATUS_IMAGE_COMPRESSION  (MCI_VID_ITEM_BASE+3)
#define MCI_VID_STATUS_AUDIO_QUALITY      (MCI_VID_ITEM_BASE+4)
#define MCI_VID_STATUS_VIDEO_QUALITY      (MCI_VID_ITEM_BASE+5)
#define MCI_VID_STATUS_IMAGE_QUALITY      (MCI_VID_ITEM_BASE+6)
#define MCI_VID_STATUS_IMAGE_BITSPERPEL   (MCI_VID_ITEM_BASE+7)
#define MCI_VID_STATUS_IMAGE_PELFORMAT    (MCI_VID_ITEM_BASE+8)
#define MCI_VID_STATUS_FORWARD            (MCI_VID_ITEM_BASE+9)
#define MCI_VID_STATUS_NORMAL_RATE        (MCI_VID_ITEM_BASE+10)
#define MCI_VID_STATUS_VIDEO_X_EXTENT     (MCI_VID_ITEM_BASE+11)
#define MCI_VID_STATUS_VIDEO_Y_EXTENT     (MCI_VID_ITEM_BASE+12)
#define MCI_VID_STATUS_IMAGE_X_EXTENT     (MCI_VID_ITEM_BASE+13)
#define MCI_VID_STATUS_IMAGE_Y_EXTENT     (MCI_VID_ITEM_BASE+14)
#define MCI_VID_STATUS_BRIGHTNESS         (MCI_VID_ITEM_BASE+15)
#define MCI_VID_STATUS_CONTRAST           (MCI_VID_ITEM_BASE+16)
#define MCI_VID_STATUS_HUE                (MCI_VID_ITEM_BASE+17)
#define MCI_VID_STATUS_SATURATION         (MCI_VID_ITEM_BASE+18)
#define MCI_VID_STATUS_GREYSCALE          (MCI_VID_ITEM_BASE+19)
#define MCI_VID_STATUS_SHARPNESS          (MCI_VID_ITEM_BASE+20)
#define MCI_VID_STATUS_SPEED              (MCI_VID_ITEM_BASE+21)
#define MCI_VID_STATUS_IMAGE_FILE_FORMAT  (MCI_VID_ITEM_BASE+22)
#define MCI_VID_STATUS_TRANSPARENT_TYPE   (MCI_VID_ITEM_BASE+23)
#define MCI_VID_STATUS_REF_INTERVAL       (MCI_VID_ITEM_BASE+24)
#define MCI_VID_STATUS_MAXDATARATE        (MCI_VID_ITEM_BASE+25)
#define MCI_VID_STATUS_VIDEO_FILE_FORMAT  (MCI_VID_ITEM_BASE+26)
#define MCI_VID_STATUS_TRANSPARENT_COLOR  (MCI_VID_ITEM_BASE+24)  /*???*/

#define MCI_DGV_SET_AUDIO_COMPRESSION   MCI_DGV_ITEM_BASE
#define MCI_DGV_SET_AUDIO_QUALITY      (MCI_DGV_ITEM_BASE+1)


/**************/
/* operations */
/**************/

#define MCI_NOTIFY          0x00000001L
#define MCI_WAIT            0x00000002L
#define MCI_FROM            0x00000004L
#define MCI_TO              0x00000008L
#define MCI_MILLISECONDS    0x00000010L
#define MCI_TRACK           0x00000020L
#define MCI_OVER            0x00000040L
#define MCI_TEST            0x00000080L
#define MCI_TO_BUFFER       0x00000100L
#define MCI_FROM_BUFFER     0x00000200L
#define MCI_CONVERT_FORMAT  0x00000400L


/*********************/
/* other definitions */
/*********************/

#define MCI_ACQUIRE_QUEUE                0x00000400L
#define MCI_AUD_COMP_ADPCM4              0x00000001L
#define MCI_AUD_COMP_PCM8                0x00000002L
#define MCI_AUD_QUALITY_HIGH             0x00000001L
#define MCI_AUD_QUALITY_MED              0x00000002L
#define MCI_AUD_QUALITY_LOW              0x00000003L

#define MCI_CAPTURE_RECT                 0x00000100L
#define MCI_CONVERT                      0x00001000L
#define MCI_CUE_INPUT                    0x00000100L
#define MCI_CUE_OUTPUT                   0x00000200L

#define MCI_ESCAPE_STRING                0x00000100L
#define MCI_EXCLUSIVE                    0x00000100L
#define MCI_EXCLUSIVE_INSTANCE           0x00000200L

#define MCI_FIND_BEST_REGISTERED         0x00000100L
#define MCI_FORMAT_MILLISECONDS          0x00000001L
#define MCI_FORMAT_MMTIME                0x00000002L
#define MCI_FORMAT_MSF                   0x00000005L
#define MCI_FORMAT_TMSF                  0x00000006L
#define MCI_FORMAT_CHAPTERS              0x00000007L
#define MCI_FORMAT_FRAMES                0x00000008L
#define MCI_FORMAT_HMS                   0x00000009L
#define MCI_FORMAT_TRACKS                0x0000000AL
#define MCI_FORMAT_BYTES                 0x0000000BL
#define MCI_FORMAT_SAMPLES               0x0000000CL
#define MCI_FORMAT_HMSF                  0x0000000DL
#define MCI_FORMAT_SET_SMPTE_24          0x0000000EL
#define MCI_FORMAT_SET_SMPTE_25          0x0000000FL
#define MCI_FORMAT_SET_SMPTE_30          0x00000010L
#define MCI_FORMAT_SET_SMPTE_30DROP      0x00000011L
#define MCI_FORMAT_SET_SONGPTR           0x00000012L
#define MCI_FORMAT_PERCENTAGE            0x00000003L
#define MCI_FORMAT_FPS                   0x00000004L

#define MCI_GAINING_USE                  0x00000002L
#define MCI_GET_HW_BUFFER_PTR            0x00000800L
#define MCI_GROUP_MAKE                   0x00000400L
#define MCI_GROUP_DELETE                 0x00000800L
#define MCI_GROUP_ALIAS                  0x00001000L
#define MCI_GROUP_MASTER                 0x00002000L

#define MCI_HEADPHONES                   0x00000400L

#define MCI_IMG_COMP_NONE                0x00000201L
#define MCI_IMG_COMP_PIC9_1_0            0x00000202L
#define MCI_IMG_COMP_PIC16_1_0           0x00000203L
#define MCI_IMG_COMP_JPEG9               0x00000204L
#define MCI_IMG_COMP_JPEG9_1_0           MCI_IMG_COMP_JPEG9
#define MCI_IMG_COMP_BMP_RLE4            0x00000205L
#define MCI_IMG_COMP_BMP_RLE8            0x00000206L
#define MCI_IMG_COMP_JPEGN               0x00000207L
#define MCI_IMG_PALETTE                  MCI_VID_PALETTE
#define MCI_IMG_RGB                      MCI_VID_RGB
#define MCI_IMG_YUV                      MCI_VID_YUV
#define MCI_IMG_QUALITY_HIGH             0x00000201L
#define MCI_IMG_QUALITY_MED              0x00000202L
#define MCI_IMG_QUALITY_LOW              0x00000203L
#define MCI_INFO_FILE                    0x00000200L
#define MCI_INFO_PRODUCT                 0x00000100L

#define MCI_LOSING_USE                   0x00000001L

#define MCI_MASTERVOL                    0x00001000L
#define MCI_MODE_NOT_READY               0x00000001L
#define MCI_MODE_PAUSE                   0x00000002L
#define MCI_MODE_PLAY                    0x00000003L
#define MCI_MODE_STOP                    0x00000004L
#define MCI_MODE_RECORD                  0x00000005L
#define MCI_MODE_SEEK                    0x00000006L

#define MCI_NOPIECEMEAL                  0x00000200L
#define MCI_NOTIFY_SUCCESSFUL            0x0000
#define MCI_NOTIFY_SUPERSEDED            0x0001
#define MCI_NOTIFY_ABORTED               0x0002
#define MCI_NOTIFY_ERROR                 0x0003

#define MCI_ON                           0x00000100L
#define MCI_OFF                          0x00000200L
#define MCI_OPEN_ELEMENT                 0x00000100L
#define MCI_OPEN_ALIAS                   0x00000200L
#define MCI_OPEN_ELEMENT_ID              0x00000400L
#define MCI_OPEN_PLAYLIST                0x00000800L
#define MCI_OPEN_TYPE_ID                 0x00001000L
#define MCI_OPEN_SHAREABLE               0x00002000L
#define MCI_OPEN_MMIO                    0x00004000L

#define MCI_PREROLL_NOTIFIED             0x00000001L
#define MCI_PREROLL_DETERMINISTIC        0x00000002L
#define MCI_PREROLL_NONE                 0x00000003L

#define MCI_QUERYSAVEDSETTING            0x00004000L
#define MCI_QUERYCURRENTSETTING          0x00008000L
#define MCI_QUERY_REGISTERED_MAP         0x00000200L
#define MCI_QUERY_REGISTERED_MAP_SIZE    0x00000400L

#define MCI_READONLY                     0x00008000L
#define MCI_RECORD_INSERT                0x00000100L
#define MCI_RECORD_OVERWRITE             0x00000200L
#define MCI_RESTORE_SRC_RECT             0x00000100L
#define MCI_RESTORE_DEST_RECT            0x00000200L
#define MCI_RETURN_RESOURCE              0x00000100L

#define MCI_SAVESETTING                  0x00002000L
#define MCI_SAVE_FILE                    0x00000100L
#define MCI_SET_ITEM                     0x00000100L
#define MCI_SET_ON                       0x00000200L
#define MCI_SET_OFF                      0x00000400L
#define MCI_SET_VIDEO                    0x00000800L
#define MCI_SET_AUDIO                    0x00001000L
#define MCI_SET_DOOR_OPEN                0x00002000L
#define MCI_SET_DOOR_CLOSED              0x00004000L
#define MCI_SET_SPEED_FORMAT             0x00008000L
#define MCI_SET_TIME_FORMAT              0x00010000L
#define MCI_SET_DOOR_LOCK                0x00020000L
#define MCI_SET_DOOR_UNLOCK              0x00040000L
#define MCI_SET_VOLUME                   0x00080000L
#define MCI_SET_ITEM_FOURCC              0x00100000L
#define MCI_SET_AUDIO_ALL                0x00000000L
#define MCI_SET_AUDIO_LEFT               0x00000001L
#define MCI_SET_AUDIO_RIGHT              0x00000002L
#define MCI_SET_MONITOR                  0x00000001L
#define MCI_SET_MONITOR_AUDIO            0x00000002L
#define MCI_SET_MONITOR_VIDEO            0x00000003L
#define MCI_SET_RECORD                   0x00000004L
#define MCI_SET_NONE                     0x10000000L
#define MCI_SET_POSITION_ADVISE_ON       0x00000100L
#define MCI_SET_POSITION_ADVISE_OFF      0x00000200L
#define MCI_SET_CUEPOINT_ON              0x00000100L
#define MCI_SET_CUEPOINT_OFF             0x00000200L
#define MCI_SET_REGISTERED               0x00000100L
#define MCI_SPEAKERS                     0x00000800L
#define MCI_SPIN_UP                      0x00000100L
#define MCI_SPIN_DOWN                    0x00000200L
#define MCI_STATUS_ITEM                  0x00000100L
#define MCI_STATUS_START                 0x00000200L
#define MCI_STATUS_CURRENT_TRACK         0x00000001L
#define MCI_STATUS_LENGTH                0x00000002L
#define MCI_STATUS_MODE                  0x00000003L
#define MCI_STATUS_NUMBER_OF_TRACKS      0x00000004L
#define MCI_STATUS_POSITION              0x00000005L
#define MCI_STATUS_POSITION_IN_TRACK     0x00000006L
#define MCI_STATUS_MEDIA_PRESENT         0x00000007L
#define MCI_STATUS_VOLUME                0x00000008L
#define MCI_STATUS_READY                 0x00000009L
#define MCI_STATUS_TIME_FORMAT           0x0000000AL
#define MCI_STATUS_SPEED_FORMAT          0x0000000BL
#define MCI_STATUS_MONITOR               0x0000000CL
#define MCI_STATUS_AUDIO                 0x0000000DL
#define MCI_STATUS_VIDEO                 0x0000000EL
#define MCI_STATUS_CLIPBOARD             0x0000000FL
#define MCI_STATUS_AUDIO_ALL             0x00000000L
#define MCI_STATUS_AUDIO_LEFT            0x00000001L
#define MCI_STATUS_AUDIO_RIGHT           0x00000002L
#define MCI_STEP_FRAMES                  0x00000100L
#define MCI_STEP_REVERSE                 0x00000200L
#define MCI_SYNCHRONIZE                  0x00000100L
#define MCI_SYSINFO_QUANTITY             0x00000100L
#define MCI_SYSINFO_OPEN                 0x00000200L
#define MCI_SYSINFO_NAME                 0x00000400L
#define MCI_SYSINFO_INSTALLNAME          0x00000800L
#define MCI_SYSINFO_ITEM                 0x00001000L
#define MCI_SYSINFO_INI_LOCK             0x00002000L
#define MCI_SYSINFO_DEV_CONTROLLABLE     0x00000001L
#define MCI_SYSINFO_DEV_NONCONTROLLABLE  0x00000002L
#define MCI_SYSINFO_DEVICESETTINGS       0x00000004L
#define MCI_SYSINFO_INSTALL_DRIVER       0x00000001L
#define MCI_SYSINFO_QUERY_DRIVER         0x00000002L
#define MCI_SYSINFO_DELETE_DRIVER        0x00000004L
#define MCI_SYSINFO_SET_PARAMS           0x00000008L
#define MCI_SYSINFO_QUERY_PARAMS         0x00000010L
#define MCI_SYSINFO_SET_CONNECTORS       0x00000020L
#define MCI_SYSINFO_QUERY_CONNECTORS     0x00000040L
#define MCI_SYSINFO_SET_EXTENSIONS       0x00000080L
#define MCI_SYSINFO_QUERY_EXTENSIONS     0x00000100L
#define MCI_SYSINFO_SET_ALIAS            0x00000200L
#define MCI_SYSINFO_QUERY_NAMES          0x00000400L
#define MCI_SYSINFO_SET_DEFAULT          0x00000800L
#define MCI_SYSINFO_QUERY_DEFAULT        0x00001000L
#define MCI_SYSINFO_SET_TYPES            0x00002000L
#define MCI_SYSINFO_QUERY_TYPES          0x00004000L

#define MCI_TO_START                     0x00000100L
#define MCI_TO_END                       0x00000200L

#define MCI_USE_HW_BUFFER                0x00000400L

/*Constants for DART Callbacks*/
#define MIX_STREAM_ERROR   0x00000080L
#define MIX_READ_COMPLETE  0x00000001L
#define MIX_WRITE_COMPLETE 0x00000002L
/*DART constants*/
#define MCI_MIXSETUP_INIT                0x00010000L
#define MCI_MIXSETUP_DEINIT              0x00020000L
#define MCI_MIXSETUP_QUERYMODE           0x00040000L

#define MCI_ALLOCATE_MEMORY              0x00040000L
#define MCI_DEALLOCATE_MEMORY            0x00080000L

/****************/
/* device stuff */
/****************/

#define MCI_AMP_SET_BALANCE                      0x00100000L
#define MCI_AMP_SET_PITCH                        0x00200000L
#define MCI_AMP_SET_TREBLE                       0x00400000L
#define MCI_AMP_SET_BASS                         0x00800000L
#define MCI_AMP_SET_GAIN                         0x01000000L
#define MCI_AMP_SET_MONITOR                      MCI_SET_MONITOR_AUDIO
                                                 
#define MCI_CD_INFO_ID                           0x00010000L
#define MCI_CD_INFO_UPC                          0x00020000L
#define MCI_CD_TRACK_AUDIO                       0x00000001L
#define MCI_CD_TRACK_DATA                        0x00000002L
#define MCI_CD_TRACK_OTHER                       0x00000003L
                                                 
#define MCI_CDXA_NONE                            0x00000000L
#define MCI_CDXA_SET_CHANNEL                     0x01000000L
#define MCI_CDXA_AUDIO_DEVICE                    0x10000000L
#define MCI_CDXA_AUDIO_BUFFER                    0x02000000L
#define MCI_CDXA_VIDEO_BUFFER                    0x04000000L
#define MCI_CDXA_DATA_BUFFER                     0x08000000L
                                                 
#define MCI_VD_INFO_LABEL                        0x00001000L
#define MCI_VD_MEDIA_CLV                         0x00000001L
#define MCI_VD_MEDIA_CAV                         0x00000002L
#define MCI_VD_MEDIA_OTHER                       0x00000003L
#define MCI_VD_PLAY_REVERSE                      0x00001000L
#define MCI_VD_PLAY_FAST                         0x00002000L
#define MCI_VD_PLAY_SPEED                        0x00004000L
#define MCI_VD_PLAY_SCAN                         0x00008000L
#define MCI_VD_PLAY_SLOW                         0x00010000L
#define MCI_VD_SEEK_REVERSE                      0x00001000L
#define MCI_VD_SET_CHANNEL                       0x00100000L
#define MCI_VD_SET_DISPLAY                       0x00200000L
#define MCI_VD_SET_ON                            MCI_SET_ON
#define MCI_VD_SET_OFF                           MCI_SET_OFF
#define MCI_VD_SET_VIDEO                         MCI_SET_VIDEO
#define MCI_VD_SPEED_NORMAL                      0x00000000L
#define MCI_VD_SPEED_FAST                        0x00000001L
#define MCI_VD_SPEED_SLOW                        0x00000002L
                                                 
#define MCI_SEQ_SET_TEMPO                        0x00100000L
#define MCI_SEQ_SET_PORT                         0x00200000L
#define MCI_SEQ_ENABLE_PORT_MAPPER               0x00400000L
#define MCI_SEQ_DISABLE_PORT_MAPPER              0x00800000L
#define MCI_SEQ_SET_OFFSET                       0x01000000L
#define MCI_SEQ_SET_MASTER                       0x02000000L
#define MCI_SEQ_SET_SLAVE                        0x04000000L
#define MCI_SEQ_SET_SMPTE_24                     0x00000100L
#define MCI_SEQ_SET_SMPTE_25                     0x00000200L
#define MCI_SEQ_SET_SMPTE_30                     0x00000300L
#define MCI_SEQ_SET_SMPTE_30DROP                 0x00000400L
#define MCI_SEQ_SET_SONGPTR                      0x00000500L
#define MCI_SEQ_MIDI                             0x00000001L
#define MCI_SEQ_SMPTE                            0x00000002L
#define MCI_SEQ_FILE                             0x00000003L
#define MCI_SEQ_NONE                             0x00000004L
#define MCI_SEQ_DIV_PPQN                         0x00000001L
#define MCI_SEQ_DIV_SMPTE_24                     0x00000002L
#define MCI_SEQ_DIV_SMPTE_25                     0x00000003L
#define MCI_SEQ_DIV_SMPTE_30DROP                 0x00000004L
#define MCI_SEQ_DIV_SMPTE_30                     0x00000005L
                                                 
#define MCI_WAVE_INPUT                           0x00001000L
#define MCI_WAVE_OUTPUT                          0x00002000L
#define MCI_WAVE_SET_SAMPLESPERSEC               0x01000000L
#define MCI_WAVE_SET_AVGBYTESPERSEC              0x02000000L
#define MCI_WAVE_SET_BLOCKALIGN                  0x04000000L
#define MCI_WAVE_SET_FORMATTAG                   0x08000000L
#define MCI_WAVE_SET_CHANNELS                    0x10000000L
#define MCI_WAVE_SET_BITSPERSAMPLE               0x80000000L
#define MCI_WAVE_FORMAT_PCM                      DATATYPE_WAVEFORM
#define MCI_WAVE_FORMAT_ADPCM                    0x0002L
#define MCI_WAVE_FORMAT_IBM_CVSD                 0x0005L
#define MCI_WAVE_FORMAT_ALAW                     DATATYPE_RIFF_ALAW
#define MCI_WAVE_FORMAT_MULAW                    DATATYPE_RIFF_MULAW
#define MCI_WAVE_FORMAT_OKI_ADPCM                0x0010L
#define MCI_WAVE_FORMAT_DVI_ADPCM                0x0011L
#define MCI_WAVE_FORMAT_DIGISTD                  0x0015L
#define MCI_WAVE_FORMAT_DIGIFIX                  0x0016L
#define MCI_WAVE_FORMAT_AVC_ADPCM                DATATYPE_ADPCM_AVC
#define MCI_WAVE_FORMAT_IBM_ADPCM                DATATYPE_ADPCM_AVC
#define MCI_WAVE_FORMAT_IBM_MULAW                DATATYPE_MULAW
#define MCI_WAVE_FORMAT_IBM_ALAW                 DATATYPE_ALAW
#define MCI_WAVE_FORMAT_CT_ADPCM                 DATATYPE_CT_ADPCM
                                                 
#define MCI_VID_COMP_RTV_2_0                     0x00000101L
#define MCI_VID_COMP_RTV_2_1                     0x00000102L
#define MCI_VID_COMP_ULTI                        0x49544C55L
#define MCI_VID_COMP_RT21                        0x31325452L
#define MCI_VID_FILE_FORMAT_AVI                  0x20495641L
#define MCI_VID_OPEN_PARENT                      0x01000000L
#define MCI_VID_PALETTE                          0x00000001L
#define MCI_VID_PUT_RECT                         0x00000100L
#define MCI_VID_PUT_DESTINATION                  0x00000200L
#define MCI_VID_PUT_SOURCE                       0x00000400L
#define MCI_VID_PUT_WINDOW_MOVE                  0x00000800L
#define MCI_VID_PUT_WINDOW_SIZE                  0x00001000L
#define MCI_VID_QUALITY_HIGH                     0x00000101L
#define MCI_VID_QUALITY_MED                      0x00000102L
#define MCI_VID_QUALITY_LOW                      0x00000103L
#define MCI_VID_QUALITY_BEST                     MCI_VID_QUALITY_HIGH
#define MCI_VID_QUALITY_CDROM                    MCI_VID_QUALITY_MED
#define MCI_VID_QUALITY_COMPACT                  MCI_VID_QUALITY_LOW
#define MCI_VID_QUALITY_BETTER                   MCI_VID_QUALITY_MED
#define MCI_VID_QUALITY_GOOD                     MCI_VID_QUALITY_LOW
#define MCI_VID_RGB                              0x00000002L
#define MCI_VID_WHERE_DESTINATION                0x00000100L
#define MCI_VID_WHERE_SOURCE                     0x00000200L
#define MCI_VID_WHERE_WINDOW                     0x00000400L
#define MCI_VID_WINDOW_HWND                      0x00000100L
#define MCI_VID_WINDOW_STATE                     0x00000200L
#define MCI_VID_WINDOW_TEXT                      0x00000400L
#define MCI_VID_WINDOW_DEFAULT                   0x00000800L
#define MCI_VID_YUV                              0x00000003L
                                                 
#define MCI_DGV_INFO_VIDEO_FILE                  0x00001000L
#define MCI_DGV_INFO_IMAGE_FILE                  0x00002000L
#define MCI_DGV_INFO_TEXT                        0x00010000L
#define MCI_DGV_OPEN_PARENT                      MCI_VID_OPEN_PARENT
#define MCI_DGV_PLAY_REVERSE                     0x00001000L
#define MCI_DGV_PLAY_FAST                        0x00002000L
#define MCI_DGV_PLAY_SPEED                       0x00004000L
#define MCI_DGV_PLAY_SCAN                        0x00008000L
#define MCI_DGV_PLAY_SLOW                        0x00010000L
#define MCI_DGV_PLAY_REPEAT                      0x00020000L
#define MCI_DGV_PUT_RECT                         MCI_VID_PUT_RECT
#define MCI_DGV_PUT_DESTINATION                  MCI_VID_PUT_DESTINATION
#define MCI_DGV_PUT_SOURCE                       MCI_VID_PUT_SOURCE
#define MCI_DGV_PUT_WINDOW_MOVE                  MCI_VID_PUT_WINDOW_MOVE
#define MCI_DGV_PUT_WINDOW_SIZE                  MCI_VID_PUT_WINDOW_SIZE
#define MCI_DGV_RECORD_RECT                      0x00000400L
#define MCI_DGV_SAVE_VIDEO_FILE                  0x00001000L
#define MCI_DGV_SAVE_IMAGE_FILE                  0x00002000L
#define MCI_DGV_SEEK_TO_NEAREST_IFRAME           0x00100000L
#define MCI_DGV_SET_VIDEO_COMPRESSION            MCI_VID_SET_VIDEO_COMPRESSION
#define MCI_DGV_SET_IMAGE_COMPRESSION            MCI_VID_SET_IMAGE_COMPRESSION
#define MCI_DGV_SET_IMAGE_BITSPERPEL             MCI_VID_SET_IMAGE_BITSPERPEL
#define MCI_DGV_SET_IMAGE_PELFORMAT              MCI_VID_SET_IMAGE_PELFORMAT
#define MCI_DGV_SET_BRIGHTNESS                   MCI_VID_SET_BRIGHTNESS
#define MCI_DGV_SET_CONTRAST                     MCI_VID_SET_CONTRAST
#define MCI_DGV_SET_HUE                          MCI_VID_SET_HUE
#define MCI_DGV_SET_SATURATION                   MCI_VID_SET_SATURATION
#define MCI_DGV_SET_SHARPNESS                    MCI_VID_SET_SHARPNESS
#define MCI_DGV_SET_GREYSCALE                    MCI_VID_SET_GREYSCALE
#define MCI_DGV_SET_IMAGE_QUALITY                MCI_VID_SET_IMAGE_QUALITY
#define MCI_DGV_SET_VIDEO_QUALITY                MCI_VID_SET_VIDEO_QUALITY
#define MCI_DGV_SET_IMAGE_COMPRESSION_METHOD     MCI_VID_SET_IMAGE_COMPRESSION_METHOD
#define MCI_DGV_SET_MONITOR                      MCI_SET_MONITOR
#define MCI_DGV_SET_MINIMUM_VIDEO_REFRESH_RATE   MCI_VID_SET_MINIMUM_VIDEO_REFRESH_RATE
#define MCI_DGV_SET_IMAGE_FILE_FORMAT            MCI_VID_SET_IMAGE_FILE_FORMAT
#define MCI_DGV_SET_REF_INTERVAL                 MCI_VID_SET_REF_INTERVAL
#define MCI_DGV_SET_MAXDATARATE                  MCI_VID_SET_MAXDATARATE
#define MCI_DGV_SET_VIDEO_FILE_FORMAT            MCI_VID_SET_VIDEO_FILE_FORMAT
#define MCI_DGV_STATUS_HWND                      MCI_VID_STATUS_HWND
#define MCI_DGV_STATUS_AUDIO_COMPRESSION         MCI_VID_STATUS_AUDIO_COMPRESSION
#define MCI_DGV_STATUS_VIDEO_COMPRESSION         MCI_VID_STATUS_VIDEO_COMPRESSION
#define MCI_DGV_STATUS_IMAGE_COMPRESSION         MCI_VID_STATUS_IMAGE_COMPRESSION
#define MCI_DGV_STATUS_AUDIO_QUALITY             MCI_VID_STATUS_AUDIO_QUALITY
#define MCI_DGV_STATUS_VIDEO_QUALITY             MCI_VID_STATUS_VIDEO_QUALITY
#define MCI_DGV_STATUS_IMAGE_QUALITY             MCI_VID_STATUS_IMAGE_QUALITY
#define MCI_DGV_STATUS_IMAGE_BITSPERPEL          MCI_VID_STATUS_IMAGE_BITSPERPEL
#define MCI_DGV_STATUS_IMAGE_PELFORMAT           MCI_VID_STATUS_IMAGE_PELFORMAT
#define MCI_DGV_STATUS_FORWARD                   MCI_VID_STATUS_FORWARD
#define MCI_DGV_STATUS_NORMAL_RATE               MCI_VID_STATUS_NORMAL_RATE
#define MCI_DGV_STATUS_VIDEO_X_EXTENT            MCI_VID_STATUS_VIDEO_X_EXTENT
#define MCI_DGV_STATUS_VIDEO_Y_EXTENT            MCI_VID_STATUS_VIDEO_Y_EXTENT
#define MCI_DGV_STATUS_IMAGE_X_EXTENT            MCI_VID_STATUS_IMAGE_X_EXTENT
#define MCI_DGV_STATUS_IMAGE_Y_EXTENT            MCI_VID_STATUS_IMAGE_Y_EXTENT
#define MCI_DGV_STATUS_BRIGHTNESS                MCI_VID_STATUS_BRIGHTNESS
#define MCI_DGV_STATUS_CONTRAST                  MCI_VID_STATUS_CONTRAST
#define MCI_DGV_STATUS_HUE                       MCI_VID_STATUS_HUE
#define MCI_DGV_STATUS_SATURATION                MCI_VID_STATUS_SATURATION
#define MCI_DGV_STATUS_SPEED                     MCI_VID_STATUS_SPEED
#define MCI_DGV_STATUS_SHARPNESS                 MCI_VID_STATUS_SHARPNESS
#define MCI_DGV_STATUS_REF_INTERVAL              MCI_VID_STATUS_REF_INTERVAL
#define MCI_DGV_STATUS_MAXDATARATE               MCI_VID_STATUS_MAXDATARATE
#define MCI_DGV_STATUS_VIDEO_FILE_FORMAT         MCI_VID_STATUS_VIDEO_FILE_FORMAT
#define MCI_DGV_WHERE_DESTINATION                MCI_VID_WHERE_DESTINATION
#define MCI_DGV_WHERE_SOURCE                     MCI_VID_WHERE_SOURCE
#define MCI_DGV_WHERE_WINDOW                     MCI_VID_WHERE_WINDOW
#define MCI_DGV_WINDOW_HWND                      MCI_VID_WINDOW_HWND
#define MCI_DGV_WINDOW_STATE                     MCI_VID_WINDOW_STATE
#define MCI_DGV_WINDOW_TEXT                      MCI_VID_WINDOW_TEXT
#define MCI_DGV_WINDOW_DEFAULT                   MCI_VID_WINDOW_DEFAULT

#define MCI_OVLY_FREEZE_RECT                     0x00000100L
#define MCI_OVLY_FREEZE_RECT_OUTSIDE             0x00000200L
#define MCI_OVLY_UNFREEZE_RECT                   0x00000100L
#define MCI_OVLY_UNFREEZE_RECT_OUTSIDE           0x00000200L
#define MCI_OVLY_INFO_TEXT                       0x00010000L
#define MCI_OVLY_OPEN_PARENT                     MCI_VID_OPEN_PARENT
#define MCI_OVLY_PUT_RECT                        MCI_VID_PUT_RECT
#define MCI_OVLY_PUT_DESTINATION                 MCI_VID_PUT_DESTINATION
#define MCI_OVLY_PUT_SOURCE                      MCI_VID_PUT_SOURCE
#define MCI_OVLY_PUT_WINDOW_MOVE                 MCI_VID_PUT_WINDOW_MOVE
#define MCI_OVLY_PUT_WINDOW_SIZE                 MCI_VID_PUT_WINDOW_SIZE
#define MCI_OVLY_SET_IMAGE_COMPRESSION           MCI_VID_SET_IMAGE_COMPRESSION
#define MCI_OVLY_SET_IMAGE_BITSPERPEL            MCI_VID_SET_IMAGE_BITSPERPEL
#define MCI_OVLY_SET_IMAGE_PELFORMAT             MCI_VID_SET_IMAGE_PELFORMAT
#define MCI_OVLY_SET_BRIGHTNESS                  MCI_VID_SET_BRIGHTNESS
#define MCI_OVLY_SET_CONTRAST                    MCI_VID_SET_CONTRAST
#define MCI_OVLY_SET_HUE                         MCI_VID_SET_HUE
#define MCI_OVLY_SET_SATURATION                  MCI_VID_SET_SATURATION
#define MCI_OVLY_SET_SHARPNESS                   MCI_VID_SET_SHARPNESS
#define MCI_OVLY_SET_GREYSCALE                   MCI_VID_SET_GREYSCALE
#define MCI_OVLY_SET_IMAGE_QUALITY               MCI_VID_SET_IMAGE_QUALITY
#define MCI_OVLY_SET_IMAGE_COMPRESSION_METHOD    MCI_VID_SET_IMAGE_COMPRESSION_METHOD
#define MCI_OVLY_SET_MINIMUM_VIDEO_REFRESH_RATE  MCI_VID_SET_MINIMUM_VIDEO_REFRESH_RATE
#define MCI_OVLY_SET_IMAGE_FILE_FORMAT           MCI_VID_SET_IMAGE_FILE_FORMAT
#define MCI_OVLY_STATUS_HWND                     MCI_VID_STATUS_HWND
#define MCI_OVLY_STATUS_IMAGE_COMPRESSION        MCI_VID_STATUS_IMAGE_COMPRESSION
#define MCI_OVLY_STATUS_IMAGE_BITSPERPEL         MCI_VID_STATUS_IMAGE_BITSPERPEL
#define MCI_OVLY_STATUS_IMAGE_PELFORMAT          MCI_VID_STATUS_IMAGE_PELFORMAT
#define MCI_OVLY_STATUS_IMAGE_X_EXTENT           MCI_VID_STATUS_IMAGE_X_EXTENT
#define MCI_OVLY_STATUS_IMAGE_Y_EXTENT           MCI_VID_STATUS_IMAGE_Y_EXTENT
#define MCI_OVLY_STATUS_BRIGHTNESS               MCI_VID_STATUS_BRIGHTNESS
#define MCI_OVLY_STATUS_CONTRAST                 MCI_VID_STATUS_CONTRAST
#define MCI_OVLY_STATUS_HUE                      MCI_VID_STATUS_HUE
#define MCI_OVLY_STATUS_SATURATION               MCI_VID_STATUS_SATURATION
#define MCI_OVLY_STATUS_GREYSCALE                MCI_VID_STATUS_GREYSCALE
#define MCI_OVLY_STATUS_IMAGE_QUALITY            MCI_VID_STATUS_IMAGE_QUALITY
#define MCI_OVLY_STATUS_SHARPNESS                MCI_VID_STATUS_SHARPNESS
#define MCI_OVLY_STATUS_IMAGE_FILE_FORMAT        MCI_VID_STATUS_IMAGE_FILE_FORMAT
#define MCI_OVLY_STATUS_TRANSPARENT_TYPE         MCI_VID_STATUS_TRANSPARENT_TYPE
#define MCI_OVLY_STATUS_TRANSPARENT_COLOR        MCI_VID_STATUS_TRANSPARENT_COLOR
#define MCI_OVLY_WHERE_DESTINATION               MCI_VID_WHERE_DESTINATION
#define MCI_OVLY_WHERE_SOURCE                    MCI_VID_WHERE_SOURCE
#define MCI_OVLY_WHERE_WINDOW                    MCI_VID_WHERE_WINDOW
#define MCI_OVLY_WINDOW_HWND                     MCI_VID_WINDOW_HWND
#define MCI_OVLY_WINDOW_STATE                    MCI_VID_WINDOW_STATE
#define MCI_OVLY_WINDOW_TEXT                     MCI_VID_WINDOW_TEXT
#define MCI_OVLY_WINDOW_DEFAULT                  MCI_VID_WINDOW_DEFAULT


/**************************/
/* get device capabilites */
/**************************/

#define MCI_GETDEVCAPS_MESSAGE                0x00000100L
#define MCI_GETDEVCAPS_ITEM                   0x00000200L
#define MCI_GETDEVCAPS_EXTENDED               0x00000400L
                                              
#define MCI_GETDEVCAPS_CAN_EJECT              0x00000001L
#define MCI_GETDEVCAPS_CAN_LOCKEJECT          0x00000002L
#define MCI_GETDEVCAPS_CAN_PLAY               0x00000003L
#define MCI_GETDEVCAPS_CAN_PROCESS_INTERNAL   0x00000004L
#define MCI_GETDEVCAPS_CAN_RECORD             0x00000005L
#define MCI_GETDEVCAPS_CAN_RECORD_INSERT      0x00000006L
#define MCI_GETDEVCAPS_CAN_SAVE               0x00000007L
#define MCI_GETDEVCAPS_CAN_SETVOLUME          0x00000008L
#define MCI_GETDEVCAPS_CAN_STREAM             0x00000009L
#define MCI_GETDEVCAPS_DEVICE_TYPE            0x0000000AL
#define MCI_GETDEVCAPS_HAS_AUDIO              0x0000000BL
#define MCI_GETDEVCAPS_HAS_VIDEO              0x0000000CL
#define MCI_GETDEVCAPS_PREROLL_TIME           0x0000000DL
#define MCI_GETDEVCAPS_PREROLL_TYPE           0x0000000EL
#define MCI_GETDEVCAPS_USES_FILES             0x0000000FL
#define MCI_GETDEVCAPS_HAS_IMAGE              0x00000010L
#define MCI_GETDEVCAPS_WAVE_FORMAT            0x00000011L

#define MCI_VID_GETDEVCAPS_CAN_STRETCH        MCI_VID_ITEM_BASE
#define MCI_VID_GETDEVCAPS_CAN_DISTORT       (MCI_VID_ITEM_BASE+1)
#define MCI_VID_GETDEVCAPS_VIDEO_X_EXTENT    (MCI_VID_ITEM_BASE+2)
#define MCI_VID_GETDEVCAPS_VIDEO_Y_EXTENT    (MCI_VID_ITEM_BASE+3)
#define MCI_VID_GETDEVCAPS_IMAGE_X_EXTENT    (MCI_VID_ITEM_BASE+4)
#define MCI_VID_GETDEVCAPS_IMAGE_Y_EXTENT    (MCI_VID_ITEM_BASE+5)
#define MCI_VID_GETDEVCAPS_MAX_WINDOWS       (MCI_VID_ITEM_BASE+6)
#define MCI_VID_GETDEVCAPS_CAN_FREEZE        (MCI_VID_ITEM_BASE+7)
#define MCI_VID_GETDEVCAPS_OVERLAY_GRAPHICS  (MCI_VID_ITEM_BASE+8)
#define MCI_VID_GETDEVCAPS_CAN_REVERSE       (MCI_VID_ITEM_BASE+9)
#define MCI_VID_GETDEVCAPS_FAST_RATE         (MCI_VID_ITEM_BASE+10)
#define MCI_VID_GETDEVCAPS_SLOW_RATE         (MCI_VID_ITEM_BASE+11)
#define MCI_VID_GETDEVCAPS_NORMAL_RATE       (MCI_VID_ITEM_BASE+12)
#define MCI_VID_GETDEVCAPS_MINIMUM_RATE      (MCI_VID_ITEM_BASE+13)
#define MCI_VID_GETDEVCAPS_MAXIMUM_RATE      (MCI_VID_ITEM_BASE+14)

#define MCI_VD_GETDEVCAPS_CLV                 0x00000400L
#define MCI_VD_GETDEVCAPS_CAV                 0x00000800L
#define MCI_VD_GETDEVCAPS_CAN_REVERSE         MCI_VID_GETDEVCAPS_CAN_REVERSE
#define MCI_VD_GETDEVCAPS_FAST_RATE           MCI_VID_GETDEVCAPS_FAST_RATE
#define MCI_VD_GETDEVCAPS_SLOW_RATE           MCI_VID_GETDEVCAPS_SLOW_RATE
#define MCI_VD_GETDEVCAPS_NORMAL_RATE         MCI_VID_GETDEVCAPS_NORMAL_RATE
#define MCI_VD_GETDEVCAPS_MINIMUM_RATE        MCI_VID_GETDEVCAPS_MINIMUM_RATE
#define MCI_VD_GETDEVCAPS_MAXIMUM_RATE        MCI_VID_GETDEVCAPS_MAXIMUM_RATE
                                              
#define MCI_DGV_GETDEVCAPS_CAN_STRETCH        MCI_VID_GETDEVCAPS_CAN_STRETCH
#define MCI_DGV_GETDEVCAPS_CAN_DISTORT        MCI_VID_GETDEVCAPS_CAN_DISTORT
#define MCI_DGV_GETDEVCAPS_VIDEO_X_EXTENT     MCI_VID_GETDEVCAPS_VIDEO_X_EXTENT
#define MCI_DGV_GETDEVCAPS_VIDEO_Y_EXTENT     MCI_VID_GETDEVCAPS_VIDEO_Y_EXTENT
#define MCI_DGV_GETDEVCAPS_IMAGE_X_EXTENT     MCI_VID_GETDEVCAPS_IMAGE_X_EXTENT
#define MCI_DGV_GETDEVCAPS_IMAGE_Y_EXTENT     MCI_VID_GETDEVCAPS_IMAGE_Y_EXTENT
#define MCI_DGV_GETDEVCAPS_MAX_WINDOWS        MCI_VID_GETDEVCAPS_MAX_WINDOWS
#define MCI_DGV_GETDEVCAPS_OVERLAY_GRAPHICS   MCI_VID_GETDEVCAPS_OVERLAY_GRAPHICS
#define MCI_DGV_GETDEVCAPS_CAN_REVERSE        MCI_VID_GETDEVCAPS_CAN_REVERSE
#define MCI_DGV_GETDEVCAPS_FAST_RATE          MCI_VID_GETDEVCAPS_FAST_RATE
#define MCI_DGV_GETDEVCAPS_SLOW_RATE          MCI_VID_GETDEVCAPS_SLOW_RATE
#define MCI_DGV_GETDEVCAPS_NORMAL_RATE        MCI_VID_GETDEVCAPS_NORMAL_RATE
#define MCI_DGV_GETDEVCAPS_MINIMUM_RATE       MCI_VID_GETDEVCAPS_MINIMUM_RATE
#define MCI_DGV_GETDEVCAPS_MAXIMUM_RATE       MCI_VID_GETDEVCAPS_MAXIMUM_RATE
                                              
#define MCI_OVLY_GETDEVCAPS_CAN_STRETCH       MCI_VID_GETDEVCAPS_CAN_STRETCH
#define MCI_OVLY_GETDEVCAPS_CAN_DISTORT       MCI_VID_GETDEVCAPS_CAN_DISTORT
#define MCI_OVLY_GETDEVCAPS_VIDEO_X_EXTENT    MCI_VID_GETDEVCAPS_VIDEO_X_EXTENT
#define MCI_OVLY_GETDEVCAPS_VIDEO_Y_EXTENT    MCI_VID_GETDEVCAPS_VIDEO_Y_EXTENT
#define MCI_OVLY_GETDEVCAPS_IMAGE_X_EXTENT    MCI_VID_GETDEVCAPS_IMAGE_X_EXTENT
#define MCI_OVLY_GETDEVCAPS_IMAGE_Y_EXTENT    MCI_VID_GETDEVCAPS_IMAGE_Y_EXTENT
#define MCI_OVLY_GETDEVCAPS_MAX_WINDOWS       MCI_VID_GETDEVCAPS_MAX_WINDOWS
#define MCI_OVLY_GETDEVCAPS_CAN_FREEZE        MCI_VID_GETDEVCAPS_CAN_FREEZE
#define MCI_OVLY_GETDEVCAPS_OVERLAY_GRAPHICS  MCI_VID_GETDEVCAPS_OVERLAY_GRAPHICS


/*******************/
/* connector stuff */
/*******************/

#define MCI_MIDI_STREAM_CONNECTOR   0x00000001L
#define MCI_CD_STREAM_CONNECTOR     0x00000002L
#define MCI_WAVE_STREAM_CONNECTOR   0x00000003L
#define MCI_AMP_STREAM_CONNECTOR    0x00000004L
#define MCI_XA_STREAM_CONNECTOR     0x00000005L
#define MCI_HEADPHONES_CONNECTOR    0x00000006L
#define MCI_SPEAKERS_CONNECTOR      0x00000007L
#define MCI_MICROPHONE_CONNECTOR    0x00000008L
#define MCI_LINE_IN_CONNECTOR       0x00000009L
#define MCI_LINE_OUT_CONNECTOR      0x0000000aL
#define MCI_VIDEO_IN_CONNECTOR      0x0000000bL
#define MCI_VIDEO_OUT_CONNECTOR     0x0000000cL
#define MCI_PHONE_SET_CONNECTOR     0x0000000dL
#define MCI_PHONE_LINE_CONNECTOR    0x0000000eL
#define MCI_AUDIO_IN_CONNECTOR      0x0000000fL
#define MCI_AUDIO_OUT_CONNECTOR     0x00000010L
#define MCI_UNIVERSAL_CONNECTOR     0x00000011L

#define MCI_ENABLE_CONNECTOR        0x00000100L
#define MCI_DISABLE_CONNECTOR       0x00000200L
#define MCI_QUERY_CONNECTOR_STATUS  0x00000400L
#define MCI_CONNECTOR_TYPE          0x00000800L
#define MCI_CONNECTOR_INDEX         0x00001000L
#define MCI_TO_CONNECTOR_INDEX      0x00002000L
#define MCI_TO_CONNECTOR_TYPE       0x00004000L
#define MCI_QUERY_CONNECTION        0x00008000L
#define MCI_MAKE_CONNECTION         0x00010000L
#define MCI_BREAK_CONNECTION        0x00020000L
#define MCI_ENUMERATE_CONNECTORS    0x00040000L
#define MCI_QUERY_CONNECTOR_TYPE    0x00080000L
#define MCI_QUERY_VALID_CONNECTION  0x00100000L
#define MCI_CONNECTOR_ALIAS         0x00200000L


/********/
/* misc */
/********/

#define MIDI_MAPPER      0x20000000L
#define MCI_MIDI_MAPPER  MIDI_MAPPER

#define MM_MCINOTIFY           0x0500
#define MM_MCIPASSDEVICE       0x0501
#define MM_MCIPOSITIONCHANGE   0x0502
#define MM_MCICUEPOINT         0x0503
#define MM_MCIPLAYLISTMESSAGE  0x0504
#define MM_MCIEVENT            0x0505
#define MM_MCISYNCH            0x0506

#define MSV_CLOSEDCAPTION    0
#define MSV_MASTERVOLUME     1
#define MSV_HEADPHONES       2
#define MSV_SPEAKERS         3
#define MSV_WORKPATH         4
#define MSV_SYSQOSVALUE      5
#define MSV_SYSQOSERRORFLAG  6
#define MSV_MAX              7

#define HDCT ULONG
#define RECT ULONG


/************************/
/* playlist definitions */
/************************/

#define DATA_OPERATION      0
#define BRANCH_OPERATION    1
#define LOOP_OPERATION      2
#define CALL_OPERATION      3
#define RETURN_OPERATION    4
#define EXIT_OPERATION      5
#define NOP_OPERATION       6
#define MESSAGE_OPERATION   7
#define CUEPOINT_OPERATION  8


/************/
/* typedefs */
/************/

typedef struct _CONNECT {
    USHORT usConnectType;
    CHAR   szToInstallName[MAX_DEVICE_NAME];
    USHORT usToConnectIndex;
} CONNECT;

typedef struct _MCI_AMP_OPEN_PARMS {
    HWND   hwndCallback;
    USHORT usDeviceID;
    USHORT usReserved0;
    PSZ    pszDeviceType;
    PSZ    pszElementName;
    PSZ    pszAlias;
    PVOID  pDevDataPtr;
} MCI_AMP_OPEN_PARMS;

typedef struct _MCI_CAPTURE_PARMS {
    HWND  hwndCallback;
    RECTL rect;
} MCI_CAPTURE_PARMS;

typedef struct _MCI_CDXA_SET_PARMS {
    HWND  hwndCallback;
    ULONG ulTimeFormat;
    ULONG ulSpeedFormat;
    ULONG ulAudio;
    ULONG ulLevel;
    ULONG ulOver;
    ULONG ulItem;
    ULONG ulValue;
    ULONG ulChannel;
    PVOID pPlayList;
    ULONG ulPlayListSize;
} MCI_CDXA_SET_PARMS;

typedef struct _MCI_CDXA_STATUS_PARMS {
    HWND  hwndCallback;
    ULONG ulReturn;
    ULONG ulItem;
    ULONG ulValue;
    ULONG ulChannel;
} MCI_CDXA_STATUS_PARMS;

typedef struct _MCI_CONNECTION_PARMS {
    HWND   hwndCallback;
    ULONG  ulConnectorType;
    ULONG  ulConnectorIndex;
    PSZ    pszAlias;
    USHORT usToDeviceID;
    USHORT usReserved0;
    ULONG  ulReserved1;
    ULONG  ulReserved2;
} MCI_CONNECTION_PARMS;

typedef struct _MCI_CONNECTORINFO_PARMS {
    HWND  hwndCallback;
    ULONG ulReturn;
    ULONG ulDeviceTypeID;
    ULONG ulConnectorType;
    ULONG ulConnectorIndex;
    ULONG ulToConnectorType;
} MCI_CONNECTORINFO_PARMS;

typedef struct _MCI_CONNECTOR_PARMS {
    HWND  hwndCallback;
    ULONG ulReturn;
    ULONG ulConnectorType;
    ULONG ulConnectorIndex;
} MCI_CONNECTOR_PARMS;

typedef struct _MCI_CUEPOINT_PARMS {
    HWND   hwndCallback;
    ULONG  ulCuepoint;
    USHORT usUserParm;
    USHORT usReserved0;
} MCI_CUEPOINT_PARMS;

typedef struct _MCI_DEFAULT_CONNECTION_PARMS {
    HWND  hwndCallback;
    PSZ   pszDevice;
    ULONG ulConnectorType;
    ULONG ulConnectorIndex;
    PSZ   pszToDevice;
    ULONG ulToConnectorType;
    ULONG ulToConnectorIndex;
} MCI_DEFAULT_CONNECTION_PARMS;

typedef struct _MCI_DEVICESETTINGS_PARMS {
    HWND   hwndCallback;
    HWND   hwndNotebook;
    USHORT usDeviceType;
    PSZ    pszDeviceName;
} MCI_DEVICESETTINGS_PARMS;

typedef struct _MCI_DGV_PLAY_PARMS {
    HWND  hwndCallback;
    ULONG ulFrom;
    ULONG ulTo;
    ULONG ulSpeed;
} MCI_DGV_PLAY_PARMS;

typedef struct _MCI_EDIT_PARMS {
    HWND   hwndCallback;
    ULONG  ulStructLen;
    ULONG  ulFrom;
    ULONG  ulTo;
    PVOID  pBuff;
    ULONG  ulBufLen;
    PVOID  pHeader;
} MCI_EDIT_PARMS;

typedef struct _MCI_ESCAPE_PARMS {
    HWND hwndCallback;
    PSZ  pszCommand;
} MCI_ESCAPE_PARMS;

typedef struct _MCI_GENERIC_PARMS {
    HWND hwndCallback;
} MCI_GENERIC_PARMS;

typedef struct _MCI_GETDEVCAPS_PARMS {
    HWND   hwndCallback;
    ULONG  ulReturn;
    ULONG  ulItem;
    USHORT usMessage;
    USHORT usReserved0;
} MCI_GETDEVCAPS_PARMS;

typedef struct _MCI_GROUP_PARMS {
    HWND   hwndCallback;
    USHORT usGroupID;
    USHORT usReserved0;
    ULONG  ulStructLength;
    USHORT usMasterID;
    USHORT usReserved1;
    PSZ    pszGroupAlias;
    ULONG  ulNumDevices;
    PULONG paulDeviceID;
} MCI_GROUP_PARMS;

typedef struct _MCI_IMAGE_PARMS {
    HWND   hwndCallback;
    ULONG  ulPelFormat;
    USHORT usBitCount;
    USHORT usReserved0;
    ULONG  ulImageCompression;
    RECTL  rect;
    PVOID  pPelBuffer;
    ULONG  ulPelBufferHeight;
    ULONG  ulPelBufferWidth;
    ULONG  ulBufLen;
} MCI_IMAGE_PARMS;

typedef struct _MCI_INFO_PARMS {
    HWND  hwndCallback;
    PSZ   pszReturn;
    ULONG ulRetSize;
} MCI_INFO_PARMS;

typedef struct _MCI_LOAD_PARMS {
    HWND hwndCallback;
    PSZ  pszElementName;
} MCI_LOAD_PARMS;

typedef struct _MCI_MASTERAUDIO_PARMS {
    HWND  hwndDummyCallback;
    ULONG ulReturn;
    ULONG ulMasterVolume;
} MCI_MASTERAUDIO_PARMS;

typedef struct _MCI_OPEN_PARMS {
    HWND   hwndCallback;
    USHORT usDeviceID;
    USHORT usReserved0;
    PSZ    pszDeviceType;
    PSZ    pszElementName;
    PSZ    pszAlias;
} MCI_OPEN_PARMS;

typedef struct _MCI_PALETTE_PARMS {
    HWND   hwndCallback;
    USHORT usRegisteredMap;
    USHORT usReserved0;
    ULONG  ulPalEntries;
    PVOID  pPalette;
} MCI_PALETTE_PARMS;

typedef struct _MCI_PLAY_PARMS {
    HWND  hwndCallback;
    ULONG ulFrom;
    ULONG ulTo;
} MCI_PLAY_PARMS;

typedef struct _MCI_POSITION_PARMS {
    HWND   hwndCallback;
    ULONG  ulUnits;
    USHORT usUserParm;
    USHORT Reserved0;
    ULONG  Reserved1;
} MCI_POSITION_PARMS;

typedef struct _MCI_RECORD_PARMS {
    HWND  hwndCallback;
    ULONG ulFrom;
    ULONG ulTo;
} MCI_RECORD_PARMS;

typedef struct _MCI_RESTORE_PARMS {
    HWND  hwndCallback;
    RECTL SrcRect;
    RECTL DestRect;
} MCI_RESTORE_PARMS;

typedef struct _MCI_SAVE_PARMS {
    HWND hwndCallback;
    PSZ  pszFileName;
} MCI_SAVE_PARMS;

typedef struct _MCI_SEEK_PARMS {
    HWND  hwndCallback;
    ULONG ulTo;        /* SEEK_SET, SEEK_CUR, SEEK_END are defined in os2.h! */
} MCI_SEEK_PARMS;

typedef struct _MCI_SET_PARMS {
    HWND  hwndCallback;
    ULONG ulTimeFormat;
    ULONG ulSpeedFormat;
    ULONG ulAudio;
    ULONG ulLevel;
    ULONG ulOver;
    ULONG ulItem;
    ULONG ulValue;
} MCI_SET_PARMS;

typedef struct _MCI_SEQ_SET_PARMS {
    HWND  hwndCallback;
    ULONG ulTimeFormat;
    ULONG ulSpeedFormat;
    ULONG ulAudio;
    ULONG ulLevel;
    ULONG ulOver;
    ULONG ulItem;
    ULONG ulValue;
    ULONG ulTempo;
    ULONG ulPort;
    ULONG ulSlave;
    ULONG ulMaster;
    ULONG ulOffset;
} MCI_SEQ_SET_PARMS;

typedef struct _MCI_STATUS_PARMS {
    HWND  hwndCallback;
    ULONG ulReturn;
    ULONG ulItem;
    ULONG ulValue;
} MCI_STATUS_PARMS;

typedef struct _MCI_STEP_PARMS {
    HWND  hwndCallback;
    ULONG ulStep;
} MCI_STEP_PARMS;

typedef struct _MCI_SYNC_OFFSET_PARMS {
    HWND  hwndCallback;
    ULONG ulOffset;
} MCI_SYNC_OFFSET_PARMS;

typedef struct _MCI_SYSINFO_ALIAS {
    CHAR szInstallName[MAX_DEVICE_NAME];
    CHAR szAliasName[MAX_ALIAS_NAME];
} MCI_SYSINFO_ALIAS;

typedef struct _MCI_SYSINFO_CONPARAMS {
    CHAR    szInstallName[MAX_DEVICE_NAME];
    USHORT  usNumConnectors;
    CONNECT ConnectorList[MAX_CONNECTORS];
} MCI_SYSINFO_CONPARAMS;

typedef struct _MCI_SYSINFO_DEFAULTDEVICE {
    CHAR   szInstallName[MAX_DEVICE_NAME];
    USHORT usDeviceType;
} MCI_SYSINFO_DEFAULTDEVICE;

typedef struct _MCI_SYSINFO_DEVPARAMS {
    CHAR szInstallName[MAX_DEVICE_NAME];
    CHAR szDevParams[MAX_DEV_PARAMS];
} MCI_SYSINFO_DEVPARAMS;

typedef struct _MCI_SYSINFO_EXTENSION {
    CHAR   szInstallName[MAX_DEVICE_NAME];
    USHORT usNumExtensions;
    CHAR   szExtension[MAX_EXTENSIONS][MAX_EXTENSION_NAME];
} MCI_SYSINFO_EXTENSION;

typedef struct _MCI_SYSINFO_LOGDEVICE {
    CHAR   szInstallName[MAX_DEVICE_NAME];
    USHORT usDeviceType;
    ULONG  ulDeviceFlag;
    CHAR   szVersionNumber[MAX_VERSION_NUMBER];
    CHAR   szProductInfo[MAX_PRODINFO];
    CHAR   szMCDDriver[MAX_DEVICE_NAME];
    CHAR   szVSDDriver[MAX_DEVICE_NAME];
    CHAR   szPDDName[MAX_PDD_NAME];
    CHAR   szMCDTable[MAX_DEVICE_NAME];
    CHAR   szVSDTable[MAX_DEVICE_NAME];
    USHORT usShareType;
    CHAR   szResourceName[MAX_DEVICE_NAME];
    USHORT usResourceUnits;
    USHORT usResourceClasses;
    USHORT ausClassArray[MAX_CLASSES];
    USHORT ausValidClassArray[MAX_CLASSES][MAX_CLASSES];
} MCI_SYSINFO_LOGDEVICE;

typedef struct _MCI_SYSINFO_PARMS {
    HWND   hwndDummyCallback;
    PSZ    pszReturn;
    ULONG  ulRetSize;
    ULONG  ulNumber;
    USHORT usDeviceType;
    USHORT usReserved0;
    ULONG  ulItem;
    PVOID  pSysInfoParm;
} MCI_SYSINFO_PARMS;

typedef struct _MCI_SYSINFO_QUERY_NAME {
    CHAR   szInstallName[MAX_DEVICE_NAME];
    CHAR   szLogicalName[MAX_DEVICE_NAME];
    CHAR   szAliasName[MAX_ALIAS_NAME];
    USHORT usDeviceType;
    USHORT usDeviceOrd;
} MCI_SYSINFO_QUERY_NAME;

typedef struct _MCI_SYSINFO_TYPES {
    CHAR szInstallName[MAX_DEVICE_NAME];
    CHAR szTypes[MAX_TYPEBUFFER+1];
} MCI_SYSINFO_TYPES;

typedef struct _MCI_TOC_REC {
    BYTE   TrackNum;
    ULONG  ulStartAddr;
    ULONG  ulEndAddr;
    BYTE   Control;
    USHORT usCountry;
    ULONG  ulOwner;
    ULONG  ulSerialNum;
} MCI_TOC_REC;

typedef MCI_TOC_REC* PTOCREC;

typedef struct _MCI_TOC_PARMS {
    HWND    hwndCallback;
    PTOCREC pBuf;
    ULONG   ulBufSize;
} MCI_TOC_PARMS;


typedef struct _MCI_VD_PLAY_PARMS {
    HWND  hwndCallback;
    ULONG ulFrom;
    ULONG ulTo;
    ULONG ulFactor;
} MCI_VD_PLAY_PARMS;

typedef struct _MCI_VD_SET_PARMS {
    HWND  hwndCallback;
    ULONG ulTimeFormat;
    ULONG ulSpeedFormat;
    ULONG ulAudio;
    ULONG ulLevel;
    ULONG ulOver;
    ULONG ulItem;
    ULONG ulValue;
    ULONG ulChannel;
} MCI_VD_SET_PARMS;

typedef struct _MCI_VID_OPEN_PARMS{
    HWND   hwndCallback;
    USHORT usDeviceID;
    USHORT usReserved0;
    PSZ    pszDeviceType;
    PSZ    pszElementName;
    PSZ    pszAlias;
    HWND   hwndParent;
} MCI_VID_OPEN_PARMS;

typedef struct _MCI_VID_RECT_PARMS {
    HWND  hwndCallback;
    RECTL rc;
} MCI_VID_RECT_PARMS;

typedef struct _MCI_VID_WINDOW_PARMS {
    HWND   hwndCallback;
    HWND   hwndDest;
    USHORT usCmdShow;
    USHORT usReserved1;
    PSZ    pszText;
    PSZ    pszAlias;
} MCI_VID_WINDOW_PARMS;

typedef struct _MCI_WAVE_GETDEVCAPS_PARMS {
    HWND   hwndCallback;
    ULONG  ulReturn;
    ULONG  ulItem;
    USHORT usMessage;
    USHORT usReserved0;
    ULONG  ulLength;
    ULONG  ulBitsPerSample;
    ULONG  ulFormatTag;
    ULONG  ulSamplesPerSec;
    ULONG  ulChannels;
    ULONG  ulFormatMode;
} MCI_WAVE_GETDEVCAPS_PARMS;

typedef struct _MCI_WAVE_SET_PARMS {
    HWND   hwndCallback;
    ULONG  ulTimeFormat;
    ULONG  ulSpeedFormat;
    ULONG  ulAudio;
    ULONG  ulLevel;
    ULONG  ulOver;
    ULONG  ulItem;
    ULONG  ulValue;
    USHORT usInput;
    USHORT usReserved0;
    USHORT usOutput;
    USHORT usReserved1;
    USHORT usFormatTag;
    USHORT usReserved2;
    USHORT usChannels;
    USHORT usReserved3;
    ULONG  ulSamplesPerSec;
    ULONG  ulAvgBytesPerSec;
    USHORT usBlockAlign;
    USHORT usReserved4;
    USHORT usBitsPerSample;
    USHORT usReserved5;
} MCI_WAVE_SET_PARMS;

typedef struct _MCI_MIX_BUFFER {
    ULONG ulStructLength;
    PVOID pBuffer;
    ULONG ulBufferLength;
    ULONG ulFlags;
    ULONG ulUserParm;
    ULONG ulTime;
    ULONG ulReserved1;
    ULONG ulReserved2;
} MCI_MIX_BUFFER;

typedef MCI_MIX_BUFFER*               PMCI_MIX_BUFFER;

/*DART Callbacks*/
typedef LONG MIXERPROC(ULONG ulHandle, PMCI_MIX_BUFFER pBuffer, ULONG ulFlags);
typedef MIXERPROC *PMIXERPROC;
typedef LONG MIXEREVENT(ULONG ulStatus, PMCI_MIX_BUFFER pBuffer, ULONG ulFlags);
typedef MIXEREVENT *PMIXEREVENT;

/*DART structures*/
typedef struct _MCI_MIXSETUP_PARMS {
    HWND        hwndCallback;
    ULONG       ulBitsPerSample;
    ULONG       ulFormatTag;
    ULONG       ulSamplesPerSec;
    ULONG       ulChannels;
    ULONG       ulFormatMode;
    ULONG       ulDeviceType;
    ULONG       ulMixHandle;
    PMIXERPROC  pmixWrite;
    PMIXERPROC  pmixRead;
    PMIXEREVENT pmixEvent;
    PVOID       pExtendedInfo;
    ULONG       ulBufferSize;
    ULONG       ulNumBuffers;
} MCI_MIXSETUP_PARMS;    

typedef struct _MCI_BUFFER_PARMS {
    HWND  hwndCallback;
    ULONG ulStructLength;
    ULONG ulNumBuffers;
    ULONG ulBufferSize;
    ULONG ulMinToStart;
    ULONG ulSrcStart;
    ULONG ulTgtStart;
    PVOID pBufList;
} MCI_BUFFER_PARMS;

typedef CONNECT*                      PCONNECT;
typedef MCI_SET_PARMS                 MCI_AMP_SET_PARMS;
typedef MCI_VID_OPEN_PARMS            MCI_DGV_OPEN_PARMS;
typedef MCI_VID_RECT_PARMS            MCI_DGV_RECT_PARMS;
typedef MCI_SET_PARMS                 MCI_DGV_SET_PARMS;
typedef MCI_VID_WINDOW_PARMS          MCI_DGV_WINDOW_PARMS;
typedef MCI_VID_OPEN_PARMS            MCI_OVLY_OPEN_PARMS;
typedef MCI_VID_RECT_PARMS            MCI_OVLY_RECT_PARMS;
typedef MCI_SET_PARMS                 MCI_OVLY_SET_PARMS;
typedef MCI_VID_WINDOW_PARMS          MCI_OVLY_WINDOW_PARMS;
typedef MCI_AMP_OPEN_PARMS*           PMCI_AMP_OPEN_PARMS;
typedef MCI_AMP_SET_PARMS*            PMCI_AMP_SET_PARMS;
typedef MCI_CAPTURE_PARMS*            PMCI_CAPTURE_PARMS;
typedef MCI_CDXA_SET_PARMS*           PMCI_CDXA_SET_PARMS;
typedef MCI_CDXA_STATUS_PARMS*        PMCI_CDXA_STATUS_PARMS;
typedef MCI_CONNECTION_PARMS*         PMCI_CONNECTION_PARMS;
typedef MCI_CONNECTORINFO_PARMS*      PMCI_CONNECTORINFO_PARMS;
typedef MCI_CONNECTOR_PARMS*          PMCI_CONNECTOR_PARMS;
typedef MCI_CUEPOINT_PARMS*           PMCI_CUEPOINT_PARMS;
typedef MCI_DEFAULT_CONNECTION_PARMS* PMCI_DEFAULT_CONNECTION_PARMS;
typedef MCI_DEVICESETTINGS_PARMS*     PMCI_DEVICESETTINGS_PARMS;
typedef MCI_DGV_OPEN_PARMS*           PMCI_DGV_OPEN_PARMS;
typedef MCI_DGV_PLAY_PARMS*           PMCI_DGV_PLAY_PARMS;
typedef MCI_DGV_RECT_PARMS*           PMCI_DGV_RECT_PARMS;
typedef MCI_DGV_SET_PARMS*            PMCI_DGV_SET_PARMS;
typedef MCI_DGV_WINDOW_PARMS*         PMCI_DGV_WINDOW_PARMS;
typedef MCI_EDIT_PARMS*               PMCI_EDIT_PARMS;
typedef MCI_ESCAPE_PARMS*             PMCI_ESCAPE_PARMS;
typedef MCI_GENERIC_PARMS*            PMCI_GENERIC_PARMS;
typedef MCI_GETDEVCAPS_PARMS*         PMCI_GETDEVCAPS_PARMS;
typedef MCI_GROUP_PARMS*              PMCI_GROUP_PARMS;
typedef MCI_IMAGE_PARMS*              PMCI_IMAGE_PARMS;
typedef MCI_INFO_PARMS*               PMCI_INFO_PARMS;
typedef MCI_LOAD_PARMS*               PMCI_LOAD_PARMS;
typedef MCI_MASTERAUDIO_PARMS*        PMCI_MASTERAUDIO_PARMS;
typedef MCI_OPEN_PARMS*               PMCI_OPEN_PARMS;
typedef MCI_OVLY_OPEN_PARMS*          PMCI_OVLY_OPEN_PARMS;
typedef MCI_OVLY_RECT_PARMS*          PMCI_OVLY_RECT_PARMS;
typedef MCI_OVLY_SET_PARMS*           PMCI_OVLY_SET_PARMS;
typedef MCI_OVLY_WINDOW_PARMS*        PMCI_OVLY_WINDOW_PARMS;
typedef MCI_PALETTE_PARMS*            PMCI_PALETTE_PARMS;
typedef MCI_PLAY_PARMS*               PMCI_PLAY_PARMS;
typedef MCI_POSITION_PARMS*           PMCI_POSITION_PARMS;
typedef MCI_RECORD_PARMS*             PMCI_RECORD_PARMS;
typedef MCI_RESTORE_PARMS*            PMCI_RESTORE_PARMS;
typedef MCI_SAVE_PARMS*               PMCI_SAVE_PARMS;
typedef MCI_SEEK_PARMS*               PMCI_SEEK_PARMS;
typedef MCI_SET_PARMS*                PMCI_SET_PARMS;
typedef MCI_SEQ_SET_PARMS*            PMCI_SEQ_SET_PARMS;
typedef MCI_STATUS_PARMS*             PMCI_STATUS_PARMS;
typedef MCI_STEP_PARMS*               PMCI_STEP_PARMS;
typedef MCI_SYNC_OFFSET_PARMS*        PMCI_SYNC_OFFSET_PARMS;
typedef MCI_SYSINFO_ALIAS*            PMCI_SYSINFO_ALIAS;
typedef MCI_SYSINFO_CONPARAMS*        PMCI_SYSINFO_CONPARAMS;
typedef MCI_SYSINFO_DEFAULTDEVICE*    PMCI_SYSINFO_DEFAULTDEVICE;
typedef MCI_SYSINFO_DEVPARAMS*        PMCI_SYSINFO_DEVPARAMS;
typedef MCI_SYSINFO_EXTENSION*        PMCI_SYSINFO_EXTENSION;
typedef MCI_SYSINFO_LOGDEVICE*        PMCI_SYSINFO_LOGDEVICE;
typedef MCI_SYSINFO_PARMS*            PMCI_SYSINFO_PARMS;
typedef MCI_SYSINFO_QUERY_NAME*       PMCI_SYSINFO_QUERY_NAME;
typedef MCI_SYSINFO_TYPES*            PMCI_SYSINFO_TYPES;
typedef MCI_TOC_PARMS*                PMCI_TOC_PARMS;
typedef MCI_VD_PLAY_PARMS*            PMCI_VD_PLAY_PARMS;
typedef MCI_VD_SET_PARMS*             PMCI_VD_SET_PARMS;
typedef MCI_WAVE_GETDEVCAPS_PARMS*    PMCI_WAVE_GETDEVCAPS_PARMS;
typedef MCI_WAVE_SET_PARMS*           PMCI_WAVE_SET_PARMS;
/*DART pointer types*/
typedef MCI_MIXSETUP_PARMS*            PMCI_MIXSETUP_PARMS;
typedef MCI_BUFFER_PARMS*             PMCI_BUFFER_PARMS;

/**********************/
/* BYTE--DWORD macros */
/**********************/

#define ULONG_LWLB(ul)  (*(BYTE *)((ULONG *)(&ul)))
#define ULONG_LWHB(ul)  (*((BYTE *)((ULONG *)(&ul))+1))
#define ULONG_HWLB(ul)  (*((BYTE *)((ULONG *)(&ul))+2))
#define ULONG_HWHB(ul)  (*((BYTE *)((ULONG *)(&ul))+3))
#define ULONG_LOWD(ul)  (*(USHORT *)((ULONG *)(&ul)))
#define ULONG_HIWD(ul)  (*((USHORT *)((ULONG *)(&ul))+1))


/**********************************/
/* time conversion macros (yuck!) */
/**********************************/

#define FPS24TOMM(value)  ((((value) & 0x000000FF) * 60 * 60 * 3000) + \
                           (((value) & 0x0000FF00) / 0x0000100 * 60 * 3000) + \
                           (((value) & 0x00FF0000) / 0x0010000 * 3000) + \
                           (((value) & 0xFF000000) / 0x1000000 * 3000/24))

#define FPS24FROMMM(value)  ((((value)+63) >= 0x100*60*60*3000) ? 0L : \
                         (((((((value)+63) % 3000)/(3000/24)) << 24) & 0xFF000000) | \
                          ((((((value)+63) / 3000) % 60) << 16) & 0x00FF0000)      | \
                         (((((((value)+63) / 3000) / 60) % 60) << 8) & 0x0000FF00) | \
                          ((((((value)+63) / 3000) / 60) / 60)  & 0x000000FF)))

#define FPS25TOMM(value)  ((((value) & 0x000000FF) * 60 * 60 * 3000) + \
                           (((value) & 0x0000FF00) / 0x0000100 * 60 * 3000) + \
                           (((value) & 0x00FF0000) / 0x0010000 * 3000) + \
                           (((value) & 0xFF000000) / 0x1000000 * 3000/25))

#define FPS25FROMMM(value)  ((((value)+60) >= 0x100*60*60*3000) ? 0L : \
                         (((((((value)+60) % 3000)/(3000/25)) << 24) & 0xFF000000) | \
                          ((((((value)+60) / 3000) % 60) << 16) & 0x00FF0000)      | \
                         (((((((value)+60) / 3000) / 60) % 60) << 8) & 0x0000FF00) | \
                          ((((((value)+60) / 3000) / 60) / 60)  & 0x000000FF)))

#define FPS30TOMM(value)  ((((value) & 0x000000FF) * 60 * 60 * 3000) + \
                           (((value) & 0x0000FF00) / 0x0000100 * 60 * 3000) + \
                           (((value) & 0x00FF0000) / 0x0010000 * 3000) + \
                           (((value) & 0xFF000000) / 0x1000000 * 3000/30))

#define FPS30FROMMM(value)  ((((value)+50) >= 0x100*60*60*3000) ? 0L : \
                         (((((((value)+50) % 3000)/(3000/30)) << 24) & 0xFF000000) | \
                          ((((((value)+50) / 3000) % 60) << 16) & 0x00FF0000)      | \
                         (((((((value)+50) / 3000) / 60) % 60) << 8) & 0x0000FF00) | \
                          ((((((value)+50) / 3000) / 60) / 60)  & 0x000000FF)))

#define HMSTOMM(value)  ((((value) & 0x000000FF) * 60 * 60 * 3000) + \
                         (((value) & 0x0000FF00) / 0x00100 * 60 * 3000) + \
                         (((value) & 0x00FF0000) / 0x10000 * 3000))

#define HMSFROMMM(value)  ((((value)+50) >= 0x100*60*60*3000) ? 0L : \
                       (((((((value)+50) / 3000) % 60) << 16) & 0x00FF0000)      | \
                       (((((((value)+50) / 3000) / 60) % 60) << 8) & 0x0000FF00) | \
                        ((((((value)+50) / 3000) / 60) / 60)  & 0x000000FF)))

#define MSECTOMM(value)  (((value) > (0xFFFFFFFF /3)) ? 0L : \
                          ((value) * 3))

#define MSECFROMMM(value)  (((value)+1) / 3)

#define REDBOOKTOMM(value)  ((((value) & 0x000000FF) * 60 * 3000) + \
                             (((value) & 0x0000FF00) / 0x00100 * 3000) + \
                             (((value) & 0x00FF0000) / 0x10000 * 3000/75))

#define REDBOOKFROMMM(value)  ((((value)+20) >= 0x100*60*3000) ? 0L : \
                               ((((value)+20) / (60*3000)) + \
                               (((value)+20) % (60*3000) / 3000 << 8) + \
                               (((value)+20) / (3000/75) % 75 << 16)))

#define MSF_FRAME(time)    (*((BYTE *)(&(time))+2))
#define MSF_MINUTE(time)   (*(BYTE *)(&(time)))
#define MSF_SECOND(time)   (*((BYTE *)(&(time))+1))

#define TMSF_FRAME(time)   (*((BYTE *)(&(time))+3))
#define TMSF_MINUTE(time)  (*((BYTE *)(&(time))+1))
#define TMSF_SECOND(time)  (*((BYTE *)(&(time))+2))
#define TMSF_TRACK(time)   (*(BYTE *)(&(time)))


/*************/
/* MCI API's */
/*************/

ULONG mciSendCommand(USHORT usDeviceID, USHORT usMessage, ULONG ulParam1,
                     PVOID pParam2, USHORT usUserParm);

ULONG mciSendString(PSZ pszCommandBuf, PSZ pszReturnString,
                    USHORT wReturnLength, HWND hwndCallBack,
                    USHORT usUserParm);

ULONG mciGetErrorString(ULONG ulError, PSZ pszBuffer, USHORT usLength);

ULONG mciMakeGroup(PUSHORT pusDeviceGroupID, USHORT usDeviceCount,
                   PUSHORT pausDeviceList, ULONG ulFlags, ULONG ulMMTime);

ULONG mciDeleteGroup(USHORT usGroupID);

BOOL  mciSetSysValue(USHORT iSysValue, PVOID pValue);

BOOL  mciQuerySysValue(USHORT iSysValue, PVOID pValue);

ULONG mciGetDeviceID(PSZ pszName);

/* set default alignment */
#pragma pack()

/* nested header management */
#endif
