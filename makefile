###############################
# makefile of mm4emx10
#
# using emx 0.8h, dmake 3.8
#
#
# Marc E.E. van Woerkom, 2/94
#

#
# makro definitions
#

# Multimedia for emx 1.0
PACKAGE = mm4emx10

# OS/2 multimedia extensions library
OS2ME     = os2me
OS2ME_A   = $(OS2ME).a
OS2ME_LIB = $(OS2ME).lib

# emx paths
EMX     = c:\emx
EMX_INC = $(EMX)\include
EMX_LIB = $(EMX)\lib

# compiler stuff
CC=gcc
CFLAGS = -Wall -Zomf -O
LFLAGS = -Zomf -Zsys -l$(OS2ME) -s

# import lib stuff
AR=ar
IMP=emximp
IMPORTS = mdm.imp ssm.imp mmio.imp sw.imp mciapi.imp

# header files
INCLUDES = os2me.h os2medef.h meerror.h  mciapi.h ssm.h \
           mcios2.h mmdrvos2.h mmioos2.h codec.h sw.h


#
# dependency rules
#

# give hints
usage:
    @+type makefile.use


all: $(OS2ME)


$(OS2ME): $(OS2ME_A) $(OS2ME_LIB)

$(OS2ME_A): $(IMPORTS)
    $(IMP) -o $(OS2ME_A) $(IMPORTS)
    $(AR) r $(OS2ME_A)
    $(AR) s $(OS2ME_A)


# convert UNIX style libraries to the Intel OMF
.a.lib:
    emxomf -s -l $*.a


# install files (+: use shell to execute)
inst: inst_h
    +copy $(OS2ME_A)   $(EMX_LIB)
    +copy $(OS2ME_LIB) $(EMX_LIB)

# repeat copy 
inst_h:! $(INCLUDES)
    +copy $? $(EMX_INC)


# deinstall files (-: ignore possible errors)
deinst: deinst_h
    -+del $(EMX_LIB)\$(OS2ME_A)
    -+del $(EMX_LIB)\$(OS2ME_LIB)

# repeat delete
deinst_h:! $(INCLUDES)
    -+del $(EMX_INC)\$?


# clean up
clean:
    -+del $(OS2ME_A)
    -+del $(OS2ME_LIB)


# create distribution
dist: all
    -+del $(PACKAGE).zip
    zip -9r $(PACKAGE) *
    unzip -t $(PACKAGE)

