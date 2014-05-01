/*************************************/
/* codec.h -- Multimedia for emx 1.0 */
/*                                   */
/*                                   */
/* Marc E.E. van Woerkom, 2/94       */
/*                                   */
/*************************************/


/* nested header management */
#ifndef _CODEC_H
#define _CODEC_H

/* use 32-bit alignment */
#pragma pack(4)


/***********/
/* defines */
/***********/

#define FOURCC_ULTI                   mmioFOURCC('U', 'L', 'T', 'I')
#define FOURCC_RT21                   mmioFOURCC('R', 'T', '2', '1')
                                      
#define HEX_FOURCC_ULTI               0x49544C55L
#define HEX_FOURCC_RT21               0x31325452L
                                      
#define MMIO_RGB_5_6_5                0x0001L
#define MMIO_RGB_24                   0x0002L
#define MMIO_YUV_4_1_1                0x0004L
#define MMIO_COMPRESSED               0x0008L
#define MMIO_YUV_24                   0x0010L
#define MMIO_PALETTIZED               0x0020L
#define MMIO_DROP_DELTA_FRAME         0x0001L
#define MMIO_IS_KEY_FRAME             0x0002L
#define MMIO_IS_PALETTE               0x0004L
#define MMIO_PALETTE_CHANGE           0x0008L
#define MMIO_ORIGIN_LOWERLEFT         0x0010L
#define MMIO_RECTL_CHANGE             0x0020L
#define MMIO_ORIGIN_UPPERLEFT         0x0040L
#define MMIO_DROP_FRAME_DECODE        0x0080L
#define MMIO_INVISIBLE_FRAME          0x1000L
#define MMIO_VIDEO_UNKNOWN            0x0000L
#define MMIO_VIDEO_DATA               0x0001L
                                      
#define MOVIE_HAS_VIDEO               0x0001L
#define MOVIE_HAS_AUDIO               0x0002L
#define MOVIE_CAN_SEEK                0x0004L
#define MOVIE_CAN_SCAN                0x0008L
#define MOVIE_HAS_COPYRIGHT           0x0010L
#define MOVIE_WAS_CAPTUREFILE         0x0020L
                                      
#define MULTITRACKREAD_NOTDONE        0x0001L
#define MULTITRACKREAD_EOF            0x0002L

#define VALID_CODECOPEN_INPUTFLAGS   (CODEC_DECOMPRESS       | \
                                      CODEC_WINDOW_CLIPPING  | \
                                      CODEC_PALETTE_TRANS    | \
                                      CODEC_SELFHEAL         | \
                                      CODEC_SCALE_PEL_DOUBLE | \
                                      CODEC_SCALE_PEL_HALVED | \
                                      CODEC_SCALE_CONTINUOUS | \
                                      CODEC_MULAPERTURE      | \
                                      CODEC_HARDWARE         | \
                                      CODEC_DIRECT_DISPLAY)

#define VALID_DECOMPRESS_INPUTFLAGS  (MMIO_DROP_DELTA_FRAME  | \
                                      MMIO_PALETTE_CHANGE    | \
                                      MMIO_ORIGIN_LOWERLEFT  | \
                                      MMIO_RECTL_CHANGE      | \
                                      MMIO_DROP_FRAME_DECODE | \
                                      MMIO_ORIGIN_UPPERLEFT)


/************/
/* typedefs */
/************/

typedef struct _GENPAL {
    ULONG ulStartIndex;
    ULONG ulNumColors;
    PRGB2 prgb2Entries;
} GENPAL;

typedef struct _RECTL1 {
    LONG xLeft;
    LONG yBottom;
    LONG xRight;
    LONG yTop;
} RECTL1;

typedef RECTL1* PRECTL1;

typedef struct _CODECVIDEOHEADER {
    ULONG  ulStructLen;
    ULONG  cx;
    ULONG  cy;
    USHORT cPlanes;
    USHORT cBitCount;
    ULONG  ulColorEncoding;
    GENPAL genpal;
} CODECVIDEOHEADER;

typedef struct _CODECOPEN {
    ULONG ulFlags;
    PVOID pControlHdr;
    PVOID pSrcHdr;
    PVOID pDstHdr;
    PVOID pOtherInfo;
} CODECOPEN;

typedef struct _MMCOMPRESS {
    ULONG ulStructLen;
    ULONG ulFlags;
    ULONG ulSrcBufLen;
    PVOID pSrcBuf;
    ULONG ulDstBufLen;
    PVOID pDstBuf;
    PVOID pRunTimeInfo;
} MMCOMPRESS;

typedef struct _MMDECOMPRESS {
    ULONG ulStructLen;
    ULONG ulFlags;
    ULONG ulSrcBufLen;
    PVOID pSrcBuf;
    ULONG ulDstBufLen;
    PVOID pDstBuf;
    PVOID pRunTimeInfo;
} MMDECOMPRESS;

typedef struct _MMVIDEOCOMPRESS {
    ULONG  ulStructLen;
    GENPAL genpalVideo;
    PVOID  pControlHdr;
} MMVIDEOCOMPRESS;

typedef struct _MMVIDEODECOMPRESS {
    ULONG   ulStructLen;
    ULONG   ulRectlCount;
    PRECTL1 prectl;
    ULONG   ulSkipLength;
    ULONG   ulDecodeLines;
    GENPAL  genpalPhysical;
    GENPAL  genpalVideo;
    RECTL1  rectlSrc;
    RECTL1  rectlDst;
} MMVIDEODECOMPRESS;

typedef struct _MMVIDEOOPEN {
    ULONG ulStructLen;
    ULONG ulQuality;
    ULONG ulKeyFrameRate;
    ULONG ulScale;
    ULONG ulRate;
    ULONG ulDataConstraint;
    ULONG ulConstraintInterval;
} MMVIDEOOPEN;

typedef struct _RECORDTAB {
    ULONG ulReserved1;
    PVOID pRecord;
    ULONG ulLength;
    ULONG ulReserved2;
    ULONG ulReserved3;
    ULONG ulParm1;
    ULONG ulParm2;
} RECORDTAB;

typedef RECORDTAB* PRECORDTAB;

typedef struct _TRACKMAP {
    ULONG      ulTrackID;
    ULONG      ulNumEntries;
    PRECORDTAB pRecordTabList;
} TRACKMAP;

typedef TRACKMAP* PTRACKMAP;

typedef struct _MMMULTITRACKREAD {
    ULONG     ulLength;
    PVOID     pBuffer;
    ULONG     ulFlags;
    ULONG     ulNumTracks;
    PTRACKMAP pTrackMapList;
} MMMULTITRACKREAD;

typedef struct _MMMULTITRACKWRITE {
    ULONG     ulNumTracks;
    PTRACKMAP pTrackMapList;
} MMMULTITRACKWRITE;

typedef struct _MMMOVIEHEADER {
    ULONG        ulStructLen;
    ULONG        ulReserved;
    ULONG        ulMediaType;
    ULONG        ulMovieCapsFlags;
    ULONG        ulMaxBytesPerSec;
    ULONG        ulPaddingGranularity;
    ULONG        ulSuggestedBufferSize;
    ULONG        ulStart;
    ULONG        ulLength;
    ULONG        ulNextTrackID;
    ULONG        ulNumEntries;
    PMMTRACKINFO pmmTrackInfoList;
    PSZ          pszMovieTitle;
    ULONG        ulCountry;
    ULONG        ulCodePage;
} MMMOVIEHEADER;



#ifdef INCL_GPI  /* ensure definition of PMMXDIBHEADER */

    typedef struct _MMVIDEOHEADER {
        ULONG  ulStructLen;
        ULONG  ulContentType;
        ULONG  ulMediaType;
        ULONG  ulVideoCapsFlags;
        ULONG  ulWidth;
        ULONG  ulHeight;
        ULONG  ulScale;
        ULONG  ulRate;
        ULONG  ulStart;
        ULONG  ulLength;
        ULONG  ulTotalFrames;
        ULONG  ulInitialFrames;
        MMTIME mmtimePerFrame;
        ULONG  ulSuggestedBufferSize;
        GENPAL genpalVideo;
        PMMXDIBHEADER pmmXDIBHeader;
    } MMVIDEOHEADER;
    
    typedef MMVIDEOHEADER* PMMVIDEOHEADER;

#endif


typedef GENPAL*             PGENPAL;
typedef CODECOPEN*          PCODECOPEN;
typedef CODECVIDEOHEADER*   PCODECVIDEOHEADER;
typedef MMCOMPRESS*         PMMCOMPRESS;
typedef MMDECOMPRESS*       PMMDECOMPRESS;
typedef MMMOVIEHEADER*      PMMMOVIEHEADER;
typedef MMMULTITRACKREAD*   PMMMULTITRACKREAD;
typedef MMMULTITRACKWRITE*  PMMMULTITRACKWRITE;
typedef MMVIDEOCOMPRESS*    PMMVIDEOCOMPRESS;
typedef MMVIDEODECOMPRESS*  PMMVIDEODECOMPRESS;
typedef MMVIDEOOPEN*        PMMVIDEOOPEN;


/* set default alignment */
#pragma pack()

/* nested header management */
#endif

