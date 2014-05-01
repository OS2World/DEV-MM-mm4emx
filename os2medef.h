/****************************************/
/* os2medef.h -- Multimedia for emx 1.0 */
/*                                      */
/*                                      */
/* Marc E.E. van Woerkom, 2/94          */
/*                                      */
/****************************************/


/* nested header management */
#ifndef _OS2MEDEF_H
#define _OS2MEDEF_H


/***************/
/* definitions */
/***************/

#define BPS_4    4
#define BPS_8    8
#define BPS_16  16

#define CF_RMID  10
#define CF_RIFF  11
#define CF_WAVE  12
#define CF_AVI   13

#define CH_1 1
#define CH_2 2
#define CH_4 4

#define HZ_8000    8000
#define HZ_11025  11025
#define HZ_14700  14700
#define HZ_18900  18900
#define HZ_22050  22050
#define HZ_37800  37800
#define HZ_44100  44100

#define RT_RMID  100
#define RT_RIFF  101
#define RT_WAVE  102
#define RT_AVI   103
#define RT_AVS   104


/************************/
/* multimedia filetypes */
/************************/

#define DATATYPE_NULL           0x0000L
#define DATATYPE_WAVEFORM       0x0001L
#define DATATYPE_DIGVIDEO       0x0002L
#define DATATYPE_RIFF_ALAW      0x0006L
#define DATATYPE_RIFF_MULAW     0x0007L
#define DATATYPE_MULAW          0x0101L
#define DATATYPE_ALAW           0x0102L
#define DATATYPE_ADPCM_AVC      0x0103L
#define DATATYPE_CT_ADPCM       0x0200L
#define DATATYPE_MIDI           0x0201L
#define DATATYPE_GENERIC        0x0202L
#define DATATYPE_SPV2           0x0203L
#define DATATYPE_CDXA_VIDEO     0x0204L
#define DATATYPE_CDXA_DATA      0x0205L
#define DATATYPE_CDXA_AUDIO     0x0206L
#define DATATYPE_CDXA_AUDIO_HD  0x0207L
#define DATATYPE_CDXA_HEADERS   0x0208L
#define DATATYPE_UNKNOWN        0xFFFFFFFFL

#define DATATYPE_DIGISPEECH     0x0208L  
#define DIGISPEECH_NATIVE       0x0001L

#define SUBTYPE_NONE  0x0000L

#define WAVE_FORMAT_1M08  0x0001L
#define WAVE_FORMAT_1S08  0x0002L
#define WAVE_FORMAT_1M16  0x0003L
#define WAVE_FORMAT_1S16  0x0004L
#define WAVE_FORMAT_2M08  0x0005L
#define WAVE_FORMAT_2S08  0x0006L
#define WAVE_FORMAT_2M16  0x0007L
#define WAVE_FORMAT_2S16  0x0008L
#define WAVE_FORMAT_4M08  0x0009L
#define WAVE_FORMAT_4S08  0x000aL
#define WAVE_FORMAT_4M16  0x000bL
#define WAVE_FORMAT_4S16  0x000cL
#define WAVE_FORMAT_8M08  0x000dL
#define WAVE_FORMAT_8S08  0x000eL
#define WAVE_FORMAT_8M16  0x000fL
#define WAVE_FORMAT_8S16  0x0010L

#define DIGVIDEO_PHOTOM  0x544F4850L
#define DIGVIDEO_ULTIM   0x49544c55L
#define DIGVIDEO_AVI     0x20495641L

#define MULAW_8B8KS   0x0001L
#define MULAW_8B11KS  0x0002L
#define MULAW_8B22KS  0x0003L
#define MULAW_8B44KS  0x0004L
#define MULAW_8B8KM   0x0005L
#define MULAW_8B11KM  0x0006L
#define MULAW_8B22KM  0x0007L
#define MULAW_8B44KM  0x0008L

#define ALAW_8B8KS   0x0001L
#define ALAW_8B11KS  0x0002L
#define ALAW_8B22KS  0x0003L
#define ALAW_8B44KS  0x0004L
#define ALAW_8B8KM   0x0005L
#define ALAW_8B11KM  0x0006L
#define ALAW_8B22KM  0x0007L
#define ALAW_8B44KM  0x0008L

#define ADPCM_AVC_VOICE   0x0001L
#define ADPCM_AVC_MUSIC   0x0002L
#define ADPCM_AVC_STEREO  0x0003L
#define ADPCM_AVC_HQ      0x0004L

#define CT_ADPCM_16B8KS   0x0001L
#define CT_ADPCM_16B11KS  0x0002L
#define CT_ADPCM_16B22KS  0x0003L
#define CT_ADPCM_16B44KS  0x0004L
#define CT_ADPCM_16B8KM   0x0005L
#define CT_ADPCM_16B11KM  0x0006L
#define CT_ADPCM_16B22KM  0x0007L
#define CT_ADPCM_16B44KM  0x0008L

#define SPV2_BPCM  0x0001L
#define SPV2_PCM   0x0002L
#define SPV2_NONE  0x0003L

#define CDXA_LEVELB       0x0000L
#define CDXA_LEVELC       0x0001L
#define CDXA_LEVELB_MONO  0x0002L
#define CDXA_LEVELC_MONO  0x0003L


/************/
/* typedefs */
/************/

#ifndef WORD
    typedef USHORT WORD;
#endif

#ifndef DWORD
    typedef ULONG DWORD;
#endif


typedef char SZ;

typedef WORD  VERSION;
typedef WORD* PW;
typedef WORD* PAW;
typedef WORD* PWORD;

typedef void* LPSTR;
typedef void* LPTR;
typedef void* LPRECT;

typedef DWORD (FNMCI)(LPTR, WORD, DWORD, DWORD, WORD);
typedef FNMCI* PFNMCI;

typedef HWND HANDLE;

typedef ULONG MMTIME;
typedef MMTIME* PMMTIME;

typedef ULONG HMMIO;
typedef HMMIO* PHMMIO;


typedef struct _SPCBKEY {
    ULONG ulDataType;
    ULONG ulDataSubType;
    ULONG ulIntKey;
} SPCBKEY;

typedef SPCBKEY* PSPCBKEY;

#define _SPCBKEY_DEFINED


typedef struct _MMTRACKINFO {
    ULONG ulTrackID;
    ULONG ulMediaType;
    ULONG ulCountry;
    ULONG ulCodePage;
    ULONG ulReserved1;
    ULONG ulReserved2;
} MMTRACKINFO;

typedef MMTRACKINFO* PMMTRACKINFO;


/* nested header management */
#endif

