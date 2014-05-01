/*************************************/
/* os2me.h -- Multimedia for emx 1.0 */
/*                                   */
/*                                   */
/* Marc E.E. van Woerkom, 2/94       */
/*                                   */
/*************************************/


/* nested header management */
#ifndef _OS2ME_H
#define _OS2ME_H

/* enforce C linkage if used from C++ */
#ifdef __cplusplus
    extern "C" {
#endif


/********************/
/* emergency brakes */
/********************/

#ifndef INCL_OS2MM
    #error sorry, no old MMPM/2 naming! (use INCL_OS2MM)
#endif

#ifdef INCL_16
    #error sorry, no 16-bit support!
#endif


/***********/
/* defines */
/***********/

#define OS2ME_INCLUDED 
#define INCL_32
#define INCL_MCIOS2   
#define INCL_MMIOOS2


/************/
/* includes */
/************/

#include <os2medef.h>
#include <meerror.h>

#ifdef INCL_MACHDR
    #include <mciapi.h>
#endif

#include <ssm.h>
#include <mcios2.h>
#include <mmdrvos2.h>
#include <mmioos2.h>

#ifdef INCL_MMIO_CODEC
    #include <codec.h>
#endif

#ifdef INCL_SW
    #define INCL_SECONDARYWINDOW
    #define INCL_GRAPHICBUTTON
    #define INCL_CIRCULARSLIDER
    #include <sw.h>
#endif


/* enforce C linkage if used from C++ */
#ifdef __cplusplus
    }
#endif

/* nested header management */
#endif

