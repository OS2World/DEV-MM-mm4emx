/**************************************/
/* mciapi.h -- Multimedia for emx 1.0 */
/*                                    */
/*                                    */
/* Marc E.E. van Woerkom, 2/94        */
/*                                    */
/**************************************/


/* nested header management */
#ifndef _MCIAPI_H
#define _MCIAPI_H


/**************/
/* play flags */
/**************/

#define MCI_OWNERISPARENT    0x0001
#define MCI_STOPACTIVE       0x0002
#define MCI_ASYNCRENDEZVOUS  0x0004
#define MCI_RENDEZVOUS       0x0008
#define MCI_ASYNC            0x0010

#define MMIO_FE_FINDFIRST    1
#define MMIO_FE_FINDNEXT     2
#define MMIO_FE_FINDEND      3
#define MMIO_FE_FINDELEMENT  4

#define MMIO_RE_COMPACT  1


/*********/
/* API's */
/*********/

ULONG mciPlayFile(HWND hwndOwner, PSZ pszFile, ULONG ulFlags,
                  PSZ pszTitle, HWND hwndViewport);

ULONG mciPlayResource(HWND hwndOwner, HMODULE hmod, ULONG resType,
                      ULONG resID, ULONG ulFlags, PSZ  pszTitle,
                      HWND hwndViewport);

ULONG mciRecordAudioFile(HWND hwndOwner, PSZ pszFile, PSZ pszTitle,
                         ULONG ulFlags);

ULONG mmioRemoveElement(PSZ pszFileElement, ULONG ulFlag);

ULONG mmioFindElement(ULONG ulCode, PSZ pszElement, ULONG ulElementLen,
                      PSZ pszFile, ULONG ulReserved);


/* nested header management */
#endif

