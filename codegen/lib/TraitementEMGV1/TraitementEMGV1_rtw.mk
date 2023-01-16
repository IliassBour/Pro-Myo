###########################################################################
## Makefile generated for component 'TraitementEMGV1'. 
## 
## Makefile     : TraitementEMGV1_rtw.mk
## Generated on : Thu Jan 12 12:45:40 2023
## Final product: .\TraitementEMGV1.lib
## Product type : static-library
## 
###########################################################################

###########################################################################
## MACROS
###########################################################################

# Macro Descriptions:
# PRODUCT_NAME            Name of the system to build
# MAKEFILE                Name of this makefile
# COMPILER_COMMAND_FILE   Compiler command listing model reference header paths
# CMD_FILE                Command file
# MODELLIB                Static library target

PRODUCT_NAME              = TraitementEMGV1
MAKEFILE                  = TraitementEMGV1_rtw.mk
MATLAB_ROOT               = C:\PROGRA~1\MATLAB\R2020b
MATLAB_BIN                = C:\PROGRA~1\MATLAB\R2020b\bin
MATLAB_ARCH_BIN           = $(MATLAB_BIN)\win64
START_DIR                 = D:\TESTEMG\codegen\lib\TraitementEMGV1
TGT_FCN_LIB               = ISO_C
SOLVER_OBJ                = 
CLASSIC_INTERFACE         = 0
MODEL_HAS_DYNAMICALLY_LOADED_SFCNS = 
RELATIVE_PATH_TO_ANCHOR   = .
COMPILER_COMMAND_FILE     = TraitementEMGV1_rtw_comp.rsp
CMD_FILE                  = TraitementEMGV1_rtw.rsp
C_STANDARD_OPTS           = 
CPP_STANDARD_OPTS         = 
NODEBUG                   = 1
MODELLIB                  = TraitementEMGV1.lib

###########################################################################
## TOOLCHAIN SPECIFICATIONS
###########################################################################

# Toolchain Name:          Microsoft Visual C++ 2017 v15.0 | nmake (64-bit Windows)
# Supported Version(s):    15.0
# ToolchainInfo Version:   2020b
# Specification Revision:  1.0
# 
#-------------------------------------------
# Macros assumed to be defined elsewhere
#-------------------------------------------

# NODEBUG
# cvarsdll
# cvarsmt
# conlibsmt
# ldebug
# conflags
# cflags

#-----------
# MACROS
#-----------

MW_EXTERNLIB_DIR    = $(MATLAB_ROOT)\extern\lib\win64\microsoft
MW_LIB_DIR          = $(MATLAB_ROOT)\lib\win64
CPU                 = AMD64
APPVER              = 5.02
CVARSFLAG           = $(cvarsmt)
CFLAGS_ADDITIONAL   = -D_CRT_SECURE_NO_WARNINGS
CPPFLAGS_ADDITIONAL = -EHs -D_CRT_SECURE_NO_WARNINGS /wd4251
LIBS_TOOLCHAIN      = $(conlibs)

TOOLCHAIN_SRCS = 
TOOLCHAIN_INCS = 
TOOLCHAIN_LIBS = 

#------------------------
# BUILD TOOL COMMANDS
#------------------------

# C Compiler: Microsoft Visual C Compiler
CC = cl

# Linker: Microsoft Visual C Linker
LD = link

# C++ Compiler: Microsoft Visual C++ Compiler
CPP = cl

# C++ Linker: Microsoft Visual C++ Linker
CPP_LD = link

# Archiver: Microsoft Visual C/C++ Archiver
AR = lib

# MEX Tool: MEX Tool
MEX_PATH = $(MATLAB_ARCH_BIN)
MEX = "$(MEX_PATH)\mex"

# Download: Download
DOWNLOAD =

# Execute: Execute
EXECUTE = $(PRODUCT)

# Builder: NMAKE Utility
MAKE = nmake


#-------------------------
# Directives/Utilities
#-------------------------

CDEBUG              = -Zi
C_OUTPUT_FLAG       = -Fo
LDDEBUG             = /DEBUG
OUTPUT_FLAG         = -out:
CPPDEBUG            = -Zi
CPP_OUTPUT_FLAG     = -Fo
CPPLDDEBUG          = /DEBUG
OUTPUT_FLAG         = -out:
ARDEBUG             =
STATICLIB_OUTPUT_FLAG = -out:
MEX_DEBUG           = -g
RM                  = @del
ECHO                = @echo
MV                  = @ren
RUN                 = @cmd /C

#--------------------------------------
# "Faster Runs" Build Configuration
#--------------------------------------

ARFLAGS              = /nologo
CFLAGS               = $(cflags) $(CVARSFLAG) $(CFLAGS_ADDITIONAL) \
                       /O2 /Oy-
CPPFLAGS             = /TP $(cflags) $(CVARSFLAG) $(CPPFLAGS_ADDITIONAL) \
                       /O2 /Oy-
CPP_LDFLAGS          = $(ldebug) $(conflags) $(LIBS_TOOLCHAIN)
CPP_SHAREDLIB_LDFLAGS  = $(ldebug) $(conflags) $(LIBS_TOOLCHAIN) \
                         -dll -def:$(DEF_FILE)
DOWNLOAD_FLAGS       =
EXECUTE_FLAGS        =
LDFLAGS              = $(ldebug) $(conflags) $(LIBS_TOOLCHAIN)
MEX_CPPFLAGS         =
MEX_CPPLDFLAGS       =
MEX_CFLAGS           =
MEX_LDFLAGS          =
MAKE_FLAGS           = -f $(MAKEFILE)
SHAREDLIB_LDFLAGS    = $(ldebug) $(conflags) $(LIBS_TOOLCHAIN) \
                       -dll -def:$(DEF_FILE)



###########################################################################
## OUTPUT INFO
###########################################################################

PRODUCT = .\TraitementEMGV1.lib
PRODUCT_TYPE = "static-library"
BUILD_TYPE = "Static Library"

###########################################################################
## INCLUDE PATHS
###########################################################################

INCLUDES_BUILDINFO = 

INCLUDES = $(INCLUDES_BUILDINFO)

###########################################################################
## DEFINES
###########################################################################

DEFINES_CUSTOM = 
DEFINES_STANDARD = -DMODEL=TraitementEMGV1

DEFINES = $(DEFINES_CUSTOM) $(DEFINES_STANDARD)

###########################################################################
## SOURCE FILES
###########################################################################

SRCS = $(START_DIR)\CXSparse\Source\cs_add_ri.c $(START_DIR)\CXSparse\Source\cs_add_ci.c $(START_DIR)\CXSparse\Source\cs_amd_ri.c $(START_DIR)\CXSparse\Source\cs_amd_ci.c $(START_DIR)\CXSparse\Source\cs_chol_ri.c $(START_DIR)\CXSparse\Source\cs_chol_ci.c $(START_DIR)\CXSparse\Source\cs_cholsol_ri.c $(START_DIR)\CXSparse\Source\cs_cholsol_ci.c $(START_DIR)\CXSparse\Source\cs_counts_ri.c $(START_DIR)\CXSparse\Source\cs_counts_ci.c $(START_DIR)\CXSparse\Source\cs_cumsum_ri.c $(START_DIR)\CXSparse\Source\cs_cumsum_ci.c $(START_DIR)\CXSparse\Source\cs_dfs_ri.c $(START_DIR)\CXSparse\Source\cs_dfs_ci.c $(START_DIR)\CXSparse\Source\cs_dmperm_ri.c $(START_DIR)\CXSparse\Source\cs_dmperm_ci.c $(START_DIR)\CXSparse\Source\cs_droptol_ri.c $(START_DIR)\CXSparse\Source\cs_droptol_ci.c $(START_DIR)\CXSparse\Source\cs_dropzeros_ri.c $(START_DIR)\CXSparse\Source\cs_dropzeros_ci.c $(START_DIR)\CXSparse\Source\cs_dupl_ri.c $(START_DIR)\CXSparse\Source\cs_dupl_ci.c $(START_DIR)\CXSparse\Source\cs_entry_ri.c $(START_DIR)\CXSparse\Source\cs_entry_ci.c $(START_DIR)\CXSparse\Source\cs_etree_ri.c $(START_DIR)\CXSparse\Source\cs_etree_ci.c $(START_DIR)\CXSparse\Source\cs_fkeep_ri.c $(START_DIR)\CXSparse\Source\cs_fkeep_ci.c $(START_DIR)\CXSparse\Source\cs_gaxpy_ri.c $(START_DIR)\CXSparse\Source\cs_gaxpy_ci.c $(START_DIR)\CXSparse\Source\cs_happly_ri.c $(START_DIR)\CXSparse\Source\cs_happly_ci.c $(START_DIR)\CXSparse\Source\cs_house_ri.c $(START_DIR)\CXSparse\Source\cs_house_ci.c $(START_DIR)\CXSparse\Source\cs_ipvec_ri.c $(START_DIR)\CXSparse\Source\cs_ipvec_ci.c $(START_DIR)\CXSparse\Source\cs_load_ri.c $(START_DIR)\CXSparse\Source\cs_load_ci.c $(START_DIR)\CXSparse\Source\cs_lsolve_ri.c $(START_DIR)\CXSparse\Source\cs_lsolve_ci.c $(START_DIR)\CXSparse\Source\cs_ltsolve_ri.c $(START_DIR)\CXSparse\Source\cs_ltsolve_ci.c $(START_DIR)\CXSparse\Source\cs_lu_ri.c $(START_DIR)\CXSparse\Source\cs_lu_ci.c $(START_DIR)\CXSparse\Source\cs_lusol_ri.c $(START_DIR)\CXSparse\Source\cs_lusol_ci.c $(START_DIR)\CXSparse\Source\cs_malloc_ri.c $(START_DIR)\CXSparse\Source\cs_malloc_ci.c $(START_DIR)\CXSparse\Source\cs_maxtrans_ri.c $(START_DIR)\CXSparse\Source\cs_maxtrans_ci.c $(START_DIR)\CXSparse\Source\cs_multiply_ri.c $(START_DIR)\CXSparse\Source\cs_multiply_ci.c $(START_DIR)\CXSparse\Source\cs_norm_ri.c $(START_DIR)\CXSparse\Source\cs_norm_ci.c $(START_DIR)\CXSparse\Source\cs_permute_ri.c $(START_DIR)\CXSparse\Source\cs_permute_ci.c $(START_DIR)\CXSparse\Source\cs_pinv_ri.c $(START_DIR)\CXSparse\Source\cs_pinv_ci.c $(START_DIR)\CXSparse\Source\cs_post_ri.c $(START_DIR)\CXSparse\Source\cs_post_ci.c $(START_DIR)\CXSparse\Source\cs_print_ri.c $(START_DIR)\CXSparse\Source\cs_print_ci.c $(START_DIR)\CXSparse\Source\cs_pvec_ri.c $(START_DIR)\CXSparse\Source\cs_pvec_ci.c $(START_DIR)\CXSparse\Source\cs_qr_ri.c $(START_DIR)\CXSparse\Source\cs_qr_ci.c $(START_DIR)\CXSparse\Source\cs_qrsol_ri.c $(START_DIR)\CXSparse\Source\cs_qrsol_ci.c $(START_DIR)\CXSparse\Source\cs_scatter_ri.c $(START_DIR)\CXSparse\Source\cs_scatter_ci.c $(START_DIR)\CXSparse\Source\cs_scc_ri.c $(START_DIR)\CXSparse\Source\cs_scc_ci.c $(START_DIR)\CXSparse\Source\cs_schol_ri.c $(START_DIR)\CXSparse\Source\cs_schol_ci.c $(START_DIR)\CXSparse\Source\cs_sqr_ri.c $(START_DIR)\CXSparse\Source\cs_sqr_ci.c $(START_DIR)\CXSparse\Source\cs_symperm_ri.c $(START_DIR)\CXSparse\Source\cs_symperm_ci.c $(START_DIR)\CXSparse\Source\cs_tdfs_ri.c $(START_DIR)\CXSparse\Source\cs_tdfs_ci.c $(START_DIR)\CXSparse\Source\cs_transpose_ri.c $(START_DIR)\CXSparse\Source\cs_transpose_ci.c $(START_DIR)\CXSparse\Source\cs_compress_ri.c $(START_DIR)\CXSparse\Source\cs_compress_ci.c $(START_DIR)\CXSparse\Source\cs_updown_ri.c $(START_DIR)\CXSparse\Source\cs_updown_ci.c $(START_DIR)\CXSparse\Source\cs_usolve_ri.c $(START_DIR)\CXSparse\Source\cs_usolve_ci.c $(START_DIR)\CXSparse\Source\cs_utsolve_ri.c $(START_DIR)\CXSparse\Source\cs_utsolve_ci.c $(START_DIR)\CXSparse\Source\cs_util_ri.c $(START_DIR)\CXSparse\Source\cs_util_ci.c $(START_DIR)\CXSparse\Source\cs_reach_ri.c $(START_DIR)\CXSparse\Source\cs_reach_ci.c $(START_DIR)\CXSparse\Source\cs_spsolve_ri.c $(START_DIR)\CXSparse\Source\cs_spsolve_ci.c $(START_DIR)\CXSparse\Source\cs_ereach_ri.c $(START_DIR)\CXSparse\Source\cs_ereach_ci.c $(START_DIR)\CXSparse\Source\cs_leaf_ri.c $(START_DIR)\CXSparse\Source\cs_leaf_ci.c $(START_DIR)\CXSparse\Source\cs_randperm_ri.c $(START_DIR)\CXSparse\Source\cs_randperm_ci.c $(START_DIR)\CXSparse\Source\cs_operator_ri.c $(START_DIR)\CXSparse\Source\cs_operator_ci.c $(START_DIR)\CXSparse\CXSparseSupport\solve_from_lu.c $(START_DIR)\CXSparse\CXSparseSupport\solve_from_qr.c $(START_DIR)\CXSparse\CXSparseSupport\makeCXSparseMatrix.c $(START_DIR)\CXSparse\CXSparseSupport\unpackCXStruct.c $(START_DIR)\TraitementEMGV1_data.c $(START_DIR)\rt_nonfinite.c $(START_DIR)\rtGetNaN.c $(START_DIR)\rtGetInf.c $(START_DIR)\TraitementEMGV1_initialize.c $(START_DIR)\TraitementEMGV1_terminate.c $(START_DIR)\TraitementEMGV1.c $(START_DIR)\detrend.c $(START_DIR)\qr.c $(START_DIR)\xnrm2.c $(START_DIR)\pwelch.c $(START_DIR)\computeperiodogram.c $(START_DIR)\computepsd.c $(START_DIR)\welch.c $(START_DIR)\butter.c $(START_DIR)\poly.c $(START_DIR)\eigStandard.c $(START_DIR)\xzlartg.c $(START_DIR)\xzhgeqz.c $(START_DIR)\filter.c $(START_DIR)\movSumProdOrMean.c $(START_DIR)\xgeqrf.c $(START_DIR)\xgerc.c $(START_DIR)\xorgqr.c $(START_DIR)\trisolve.c $(START_DIR)\FFTImplementationCallback.c $(START_DIR)\useConstantDim.c $(START_DIR)\xhseqr.c $(START_DIR)\xzlarfg.c $(START_DIR)\xdlanv2.c $(START_DIR)\sqrt.c $(START_DIR)\filtfilt.c $(START_DIR)\insertionsort.c $(START_DIR)\introsort.c $(START_DIR)\TraitementEMGV1_emxutil.c $(START_DIR)\TraitementEMGV1_rtwutil.c

ALL_SRCS = $(SRCS)

###########################################################################
## OBJECTS
###########################################################################

OBJS = cs_add_ri.obj cs_add_ci.obj cs_amd_ri.obj cs_amd_ci.obj cs_chol_ri.obj cs_chol_ci.obj cs_cholsol_ri.obj cs_cholsol_ci.obj cs_counts_ri.obj cs_counts_ci.obj cs_cumsum_ri.obj cs_cumsum_ci.obj cs_dfs_ri.obj cs_dfs_ci.obj cs_dmperm_ri.obj cs_dmperm_ci.obj cs_droptol_ri.obj cs_droptol_ci.obj cs_dropzeros_ri.obj cs_dropzeros_ci.obj cs_dupl_ri.obj cs_dupl_ci.obj cs_entry_ri.obj cs_entry_ci.obj cs_etree_ri.obj cs_etree_ci.obj cs_fkeep_ri.obj cs_fkeep_ci.obj cs_gaxpy_ri.obj cs_gaxpy_ci.obj cs_happly_ri.obj cs_happly_ci.obj cs_house_ri.obj cs_house_ci.obj cs_ipvec_ri.obj cs_ipvec_ci.obj cs_load_ri.obj cs_load_ci.obj cs_lsolve_ri.obj cs_lsolve_ci.obj cs_ltsolve_ri.obj cs_ltsolve_ci.obj cs_lu_ri.obj cs_lu_ci.obj cs_lusol_ri.obj cs_lusol_ci.obj cs_malloc_ri.obj cs_malloc_ci.obj cs_maxtrans_ri.obj cs_maxtrans_ci.obj cs_multiply_ri.obj cs_multiply_ci.obj cs_norm_ri.obj cs_norm_ci.obj cs_permute_ri.obj cs_permute_ci.obj cs_pinv_ri.obj cs_pinv_ci.obj cs_post_ri.obj cs_post_ci.obj cs_print_ri.obj cs_print_ci.obj cs_pvec_ri.obj cs_pvec_ci.obj cs_qr_ri.obj cs_qr_ci.obj cs_qrsol_ri.obj cs_qrsol_ci.obj cs_scatter_ri.obj cs_scatter_ci.obj cs_scc_ri.obj cs_scc_ci.obj cs_schol_ri.obj cs_schol_ci.obj cs_sqr_ri.obj cs_sqr_ci.obj cs_symperm_ri.obj cs_symperm_ci.obj cs_tdfs_ri.obj cs_tdfs_ci.obj cs_transpose_ri.obj cs_transpose_ci.obj cs_compress_ri.obj cs_compress_ci.obj cs_updown_ri.obj cs_updown_ci.obj cs_usolve_ri.obj cs_usolve_ci.obj cs_utsolve_ri.obj cs_utsolve_ci.obj cs_util_ri.obj cs_util_ci.obj cs_reach_ri.obj cs_reach_ci.obj cs_spsolve_ri.obj cs_spsolve_ci.obj cs_ereach_ri.obj cs_ereach_ci.obj cs_leaf_ri.obj cs_leaf_ci.obj cs_randperm_ri.obj cs_randperm_ci.obj cs_operator_ri.obj cs_operator_ci.obj solve_from_lu.obj solve_from_qr.obj makeCXSparseMatrix.obj unpackCXStruct.obj TraitementEMGV1_data.obj rt_nonfinite.obj rtGetNaN.obj rtGetInf.obj TraitementEMGV1_initialize.obj TraitementEMGV1_terminate.obj TraitementEMGV1.obj detrend.obj qr.obj xnrm2.obj pwelch.obj computeperiodogram.obj computepsd.obj welch.obj butter.obj poly.obj eigStandard.obj xzlartg.obj xzhgeqz.obj filter.obj movSumProdOrMean.obj xgeqrf.obj xgerc.obj xorgqr.obj trisolve.obj FFTImplementationCallback.obj useConstantDim.obj xhseqr.obj xzlarfg.obj xdlanv2.obj sqrt.obj filtfilt.obj insertionsort.obj introsort.obj TraitementEMGV1_emxutil.obj TraitementEMGV1_rtwutil.obj

ALL_OBJS = $(OBJS)

###########################################################################
## PREBUILT OBJECT FILES
###########################################################################

PREBUILT_OBJS = 

###########################################################################
## LIBRARIES
###########################################################################

LIBS = 

###########################################################################
## SYSTEM LIBRARIES
###########################################################################

SYSTEM_LIBS =  /LIBPATH:"$(MATLAB_ROOT)\bin\win64" "$(MATLAB_ROOT)\bin\win64\libiomp5md.lib"

###########################################################################
## ADDITIONAL TOOLCHAIN FLAGS
###########################################################################

#---------------
# C Compiler
#---------------

CFLAGS_OPTS = /openmp /wd4101
CFLAGS_BASIC = $(DEFINES) @$(COMPILER_COMMAND_FILE)

CFLAGS = $(CFLAGS) $(CFLAGS_OPTS) $(CFLAGS_BASIC)

#-----------------
# C++ Compiler
#-----------------

CPPFLAGS_OPTS = /openmp /wd4101
CPPFLAGS_BASIC = $(DEFINES) @$(COMPILER_COMMAND_FILE)

CPPFLAGS = $(CPPFLAGS) $(CPPFLAGS_OPTS) $(CPPFLAGS_BASIC)

#---------------
# C++ Linker
#---------------

CPP_LDFLAGS_ = /nodefaultlib:vcomp  

CPP_LDFLAGS = $(CPP_LDFLAGS) $(CPP_LDFLAGS_)

#------------------------------
# C++ Shared Library Linker
#------------------------------

CPP_SHAREDLIB_LDFLAGS_ = /nodefaultlib:vcomp  

CPP_SHAREDLIB_LDFLAGS = $(CPP_SHAREDLIB_LDFLAGS) $(CPP_SHAREDLIB_LDFLAGS_)

#-----------
# Linker
#-----------

LDFLAGS_ = /nodefaultlib:vcomp  

LDFLAGS = $(LDFLAGS) $(LDFLAGS_)

#--------------------------
# Shared Library Linker
#--------------------------

SHAREDLIB_LDFLAGS_ = /nodefaultlib:vcomp  

SHAREDLIB_LDFLAGS = $(SHAREDLIB_LDFLAGS) $(SHAREDLIB_LDFLAGS_)

###########################################################################
## INLINED COMMANDS
###########################################################################


!include $(MATLAB_ROOT)\rtw\c\tools\vcdefs.mak


###########################################################################
## PHONY TARGETS
###########################################################################

.PHONY : all build clean info prebuild download execute set_environment_variables


all : build
	@cmd /C "@echo ### Successfully generated all binary outputs."


build : set_environment_variables prebuild $(PRODUCT)


prebuild : 


download : $(PRODUCT)


execute : download


set_environment_variables : 
	@set INCLUDE=$(INCLUDES);$(INCLUDE)
	@set LIB=$(LIB)


###########################################################################
## FINAL TARGET
###########################################################################

#---------------------------------
# Create a static library         
#---------------------------------

$(PRODUCT) : $(OBJS) $(PREBUILT_OBJS)
	@cmd /C "@echo ### Creating static library "$(PRODUCT)" ..."
	$(AR) $(ARFLAGS) -out:$(PRODUCT) @$(CMD_FILE)
	@cmd /C "@echo ### Created: $(PRODUCT)"


###########################################################################
## INTERMEDIATE TARGETS
###########################################################################

#---------------------
# SOURCE-TO-OBJECT
#---------------------

.c.obj :
	$(CC) $(CFLAGS) -Fo"$@" "$<"


.cpp.obj :
	$(CPP) $(CPPFLAGS) -Fo"$@" "$<"


{$(RELATIVE_PATH_TO_ANCHOR)}.c.obj :
	$(CC) $(CFLAGS) -Fo"$@" "$<"


{$(RELATIVE_PATH_TO_ANCHOR)}.cpp.obj :
	$(CPP) $(CPPFLAGS) -Fo"$@" "$<"


{$(START_DIR)}.c.obj :
	$(CC) $(CFLAGS) -Fo"$@" "$<"


{$(START_DIR)}.cpp.obj :
	$(CPP) $(CPPFLAGS) -Fo"$@" "$<"


{D:\TESTEMG}.c.obj :
	$(CC) $(CFLAGS) -Fo"$@" "$<"


{D:\TESTEMG}.cpp.obj :
	$(CPP) $(CPPFLAGS) -Fo"$@" "$<"


{$(START_DIR)\CXSparse\Source}.c.obj :
	$(CC) $(CFLAGS) -Fo"$@" "$<"


{$(START_DIR)\CXSparse\Source}.cpp.obj :
	$(CPP) $(CPPFLAGS) -Fo"$@" "$<"


{$(START_DIR)\CXSparse\CXSparseSupport}.c.obj :
	$(CC) $(CFLAGS) -Fo"$@" "$<"


{$(START_DIR)\CXSparse\CXSparseSupport}.cpp.obj :
	$(CPP) $(CPPFLAGS) -Fo"$@" "$<"


cs_add_ri.obj : $(START_DIR)\CXSparse\Source\cs_add_ri.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\CXSparse\Source\cs_add_ri.c


cs_add_ci.obj : $(START_DIR)\CXSparse\Source\cs_add_ci.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\CXSparse\Source\cs_add_ci.c


cs_amd_ri.obj : $(START_DIR)\CXSparse\Source\cs_amd_ri.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\CXSparse\Source\cs_amd_ri.c


cs_amd_ci.obj : $(START_DIR)\CXSparse\Source\cs_amd_ci.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\CXSparse\Source\cs_amd_ci.c


cs_chol_ri.obj : $(START_DIR)\CXSparse\Source\cs_chol_ri.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\CXSparse\Source\cs_chol_ri.c


cs_chol_ci.obj : $(START_DIR)\CXSparse\Source\cs_chol_ci.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\CXSparse\Source\cs_chol_ci.c


cs_cholsol_ri.obj : $(START_DIR)\CXSparse\Source\cs_cholsol_ri.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\CXSparse\Source\cs_cholsol_ri.c


cs_cholsol_ci.obj : $(START_DIR)\CXSparse\Source\cs_cholsol_ci.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\CXSparse\Source\cs_cholsol_ci.c


cs_counts_ri.obj : $(START_DIR)\CXSparse\Source\cs_counts_ri.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\CXSparse\Source\cs_counts_ri.c


cs_counts_ci.obj : $(START_DIR)\CXSparse\Source\cs_counts_ci.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\CXSparse\Source\cs_counts_ci.c


cs_cumsum_ri.obj : $(START_DIR)\CXSparse\Source\cs_cumsum_ri.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\CXSparse\Source\cs_cumsum_ri.c


cs_cumsum_ci.obj : $(START_DIR)\CXSparse\Source\cs_cumsum_ci.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\CXSparse\Source\cs_cumsum_ci.c


cs_dfs_ri.obj : $(START_DIR)\CXSparse\Source\cs_dfs_ri.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\CXSparse\Source\cs_dfs_ri.c


cs_dfs_ci.obj : $(START_DIR)\CXSparse\Source\cs_dfs_ci.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\CXSparse\Source\cs_dfs_ci.c


cs_dmperm_ri.obj : $(START_DIR)\CXSparse\Source\cs_dmperm_ri.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\CXSparse\Source\cs_dmperm_ri.c


cs_dmperm_ci.obj : $(START_DIR)\CXSparse\Source\cs_dmperm_ci.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\CXSparse\Source\cs_dmperm_ci.c


cs_droptol_ri.obj : $(START_DIR)\CXSparse\Source\cs_droptol_ri.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\CXSparse\Source\cs_droptol_ri.c


cs_droptol_ci.obj : $(START_DIR)\CXSparse\Source\cs_droptol_ci.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\CXSparse\Source\cs_droptol_ci.c


cs_dropzeros_ri.obj : $(START_DIR)\CXSparse\Source\cs_dropzeros_ri.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\CXSparse\Source\cs_dropzeros_ri.c


cs_dropzeros_ci.obj : $(START_DIR)\CXSparse\Source\cs_dropzeros_ci.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\CXSparse\Source\cs_dropzeros_ci.c


cs_dupl_ri.obj : $(START_DIR)\CXSparse\Source\cs_dupl_ri.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\CXSparse\Source\cs_dupl_ri.c


cs_dupl_ci.obj : $(START_DIR)\CXSparse\Source\cs_dupl_ci.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\CXSparse\Source\cs_dupl_ci.c


cs_entry_ri.obj : $(START_DIR)\CXSparse\Source\cs_entry_ri.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\CXSparse\Source\cs_entry_ri.c


cs_entry_ci.obj : $(START_DIR)\CXSparse\Source\cs_entry_ci.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\CXSparse\Source\cs_entry_ci.c


cs_etree_ri.obj : $(START_DIR)\CXSparse\Source\cs_etree_ri.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\CXSparse\Source\cs_etree_ri.c


cs_etree_ci.obj : $(START_DIR)\CXSparse\Source\cs_etree_ci.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\CXSparse\Source\cs_etree_ci.c


cs_fkeep_ri.obj : $(START_DIR)\CXSparse\Source\cs_fkeep_ri.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\CXSparse\Source\cs_fkeep_ri.c


cs_fkeep_ci.obj : $(START_DIR)\CXSparse\Source\cs_fkeep_ci.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\CXSparse\Source\cs_fkeep_ci.c


cs_gaxpy_ri.obj : $(START_DIR)\CXSparse\Source\cs_gaxpy_ri.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\CXSparse\Source\cs_gaxpy_ri.c


cs_gaxpy_ci.obj : $(START_DIR)\CXSparse\Source\cs_gaxpy_ci.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\CXSparse\Source\cs_gaxpy_ci.c


cs_happly_ri.obj : $(START_DIR)\CXSparse\Source\cs_happly_ri.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\CXSparse\Source\cs_happly_ri.c


cs_happly_ci.obj : $(START_DIR)\CXSparse\Source\cs_happly_ci.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\CXSparse\Source\cs_happly_ci.c


cs_house_ri.obj : $(START_DIR)\CXSparse\Source\cs_house_ri.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\CXSparse\Source\cs_house_ri.c


cs_house_ci.obj : $(START_DIR)\CXSparse\Source\cs_house_ci.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\CXSparse\Source\cs_house_ci.c


cs_ipvec_ri.obj : $(START_DIR)\CXSparse\Source\cs_ipvec_ri.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\CXSparse\Source\cs_ipvec_ri.c


cs_ipvec_ci.obj : $(START_DIR)\CXSparse\Source\cs_ipvec_ci.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\CXSparse\Source\cs_ipvec_ci.c


cs_load_ri.obj : $(START_DIR)\CXSparse\Source\cs_load_ri.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\CXSparse\Source\cs_load_ri.c


cs_load_ci.obj : $(START_DIR)\CXSparse\Source\cs_load_ci.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\CXSparse\Source\cs_load_ci.c


cs_lsolve_ri.obj : $(START_DIR)\CXSparse\Source\cs_lsolve_ri.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\CXSparse\Source\cs_lsolve_ri.c


cs_lsolve_ci.obj : $(START_DIR)\CXSparse\Source\cs_lsolve_ci.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\CXSparse\Source\cs_lsolve_ci.c


cs_ltsolve_ri.obj : $(START_DIR)\CXSparse\Source\cs_ltsolve_ri.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\CXSparse\Source\cs_ltsolve_ri.c


cs_ltsolve_ci.obj : $(START_DIR)\CXSparse\Source\cs_ltsolve_ci.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\CXSparse\Source\cs_ltsolve_ci.c


cs_lu_ri.obj : $(START_DIR)\CXSparse\Source\cs_lu_ri.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\CXSparse\Source\cs_lu_ri.c


cs_lu_ci.obj : $(START_DIR)\CXSparse\Source\cs_lu_ci.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\CXSparse\Source\cs_lu_ci.c


cs_lusol_ri.obj : $(START_DIR)\CXSparse\Source\cs_lusol_ri.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\CXSparse\Source\cs_lusol_ri.c


cs_lusol_ci.obj : $(START_DIR)\CXSparse\Source\cs_lusol_ci.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\CXSparse\Source\cs_lusol_ci.c


cs_malloc_ri.obj : $(START_DIR)\CXSparse\Source\cs_malloc_ri.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\CXSparse\Source\cs_malloc_ri.c


cs_malloc_ci.obj : $(START_DIR)\CXSparse\Source\cs_malloc_ci.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\CXSparse\Source\cs_malloc_ci.c


cs_maxtrans_ri.obj : $(START_DIR)\CXSparse\Source\cs_maxtrans_ri.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\CXSparse\Source\cs_maxtrans_ri.c


cs_maxtrans_ci.obj : $(START_DIR)\CXSparse\Source\cs_maxtrans_ci.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\CXSparse\Source\cs_maxtrans_ci.c


cs_multiply_ri.obj : $(START_DIR)\CXSparse\Source\cs_multiply_ri.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\CXSparse\Source\cs_multiply_ri.c


cs_multiply_ci.obj : $(START_DIR)\CXSparse\Source\cs_multiply_ci.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\CXSparse\Source\cs_multiply_ci.c


cs_norm_ri.obj : $(START_DIR)\CXSparse\Source\cs_norm_ri.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\CXSparse\Source\cs_norm_ri.c


cs_norm_ci.obj : $(START_DIR)\CXSparse\Source\cs_norm_ci.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\CXSparse\Source\cs_norm_ci.c


cs_permute_ri.obj : $(START_DIR)\CXSparse\Source\cs_permute_ri.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\CXSparse\Source\cs_permute_ri.c


cs_permute_ci.obj : $(START_DIR)\CXSparse\Source\cs_permute_ci.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\CXSparse\Source\cs_permute_ci.c


cs_pinv_ri.obj : $(START_DIR)\CXSparse\Source\cs_pinv_ri.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\CXSparse\Source\cs_pinv_ri.c


cs_pinv_ci.obj : $(START_DIR)\CXSparse\Source\cs_pinv_ci.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\CXSparse\Source\cs_pinv_ci.c


cs_post_ri.obj : $(START_DIR)\CXSparse\Source\cs_post_ri.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\CXSparse\Source\cs_post_ri.c


cs_post_ci.obj : $(START_DIR)\CXSparse\Source\cs_post_ci.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\CXSparse\Source\cs_post_ci.c


cs_print_ri.obj : $(START_DIR)\CXSparse\Source\cs_print_ri.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\CXSparse\Source\cs_print_ri.c


cs_print_ci.obj : $(START_DIR)\CXSparse\Source\cs_print_ci.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\CXSparse\Source\cs_print_ci.c


cs_pvec_ri.obj : $(START_DIR)\CXSparse\Source\cs_pvec_ri.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\CXSparse\Source\cs_pvec_ri.c


cs_pvec_ci.obj : $(START_DIR)\CXSparse\Source\cs_pvec_ci.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\CXSparse\Source\cs_pvec_ci.c


cs_qr_ri.obj : $(START_DIR)\CXSparse\Source\cs_qr_ri.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\CXSparse\Source\cs_qr_ri.c


cs_qr_ci.obj : $(START_DIR)\CXSparse\Source\cs_qr_ci.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\CXSparse\Source\cs_qr_ci.c


cs_qrsol_ri.obj : $(START_DIR)\CXSparse\Source\cs_qrsol_ri.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\CXSparse\Source\cs_qrsol_ri.c


cs_qrsol_ci.obj : $(START_DIR)\CXSparse\Source\cs_qrsol_ci.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\CXSparse\Source\cs_qrsol_ci.c


cs_scatter_ri.obj : $(START_DIR)\CXSparse\Source\cs_scatter_ri.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\CXSparse\Source\cs_scatter_ri.c


cs_scatter_ci.obj : $(START_DIR)\CXSparse\Source\cs_scatter_ci.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\CXSparse\Source\cs_scatter_ci.c


cs_scc_ri.obj : $(START_DIR)\CXSparse\Source\cs_scc_ri.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\CXSparse\Source\cs_scc_ri.c


cs_scc_ci.obj : $(START_DIR)\CXSparse\Source\cs_scc_ci.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\CXSparse\Source\cs_scc_ci.c


cs_schol_ri.obj : $(START_DIR)\CXSparse\Source\cs_schol_ri.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\CXSparse\Source\cs_schol_ri.c


cs_schol_ci.obj : $(START_DIR)\CXSparse\Source\cs_schol_ci.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\CXSparse\Source\cs_schol_ci.c


cs_sqr_ri.obj : $(START_DIR)\CXSparse\Source\cs_sqr_ri.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\CXSparse\Source\cs_sqr_ri.c


cs_sqr_ci.obj : $(START_DIR)\CXSparse\Source\cs_sqr_ci.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\CXSparse\Source\cs_sqr_ci.c


cs_symperm_ri.obj : $(START_DIR)\CXSparse\Source\cs_symperm_ri.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\CXSparse\Source\cs_symperm_ri.c


cs_symperm_ci.obj : $(START_DIR)\CXSparse\Source\cs_symperm_ci.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\CXSparse\Source\cs_symperm_ci.c


cs_tdfs_ri.obj : $(START_DIR)\CXSparse\Source\cs_tdfs_ri.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\CXSparse\Source\cs_tdfs_ri.c


cs_tdfs_ci.obj : $(START_DIR)\CXSparse\Source\cs_tdfs_ci.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\CXSparse\Source\cs_tdfs_ci.c


cs_transpose_ri.obj : $(START_DIR)\CXSparse\Source\cs_transpose_ri.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\CXSparse\Source\cs_transpose_ri.c


cs_transpose_ci.obj : $(START_DIR)\CXSparse\Source\cs_transpose_ci.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\CXSparse\Source\cs_transpose_ci.c


cs_compress_ri.obj : $(START_DIR)\CXSparse\Source\cs_compress_ri.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\CXSparse\Source\cs_compress_ri.c


cs_compress_ci.obj : $(START_DIR)\CXSparse\Source\cs_compress_ci.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\CXSparse\Source\cs_compress_ci.c


cs_updown_ri.obj : $(START_DIR)\CXSparse\Source\cs_updown_ri.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\CXSparse\Source\cs_updown_ri.c


cs_updown_ci.obj : $(START_DIR)\CXSparse\Source\cs_updown_ci.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\CXSparse\Source\cs_updown_ci.c


cs_usolve_ri.obj : $(START_DIR)\CXSparse\Source\cs_usolve_ri.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\CXSparse\Source\cs_usolve_ri.c


cs_usolve_ci.obj : $(START_DIR)\CXSparse\Source\cs_usolve_ci.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\CXSparse\Source\cs_usolve_ci.c


cs_utsolve_ri.obj : $(START_DIR)\CXSparse\Source\cs_utsolve_ri.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\CXSparse\Source\cs_utsolve_ri.c


cs_utsolve_ci.obj : $(START_DIR)\CXSparse\Source\cs_utsolve_ci.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\CXSparse\Source\cs_utsolve_ci.c


cs_util_ri.obj : $(START_DIR)\CXSparse\Source\cs_util_ri.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\CXSparse\Source\cs_util_ri.c


cs_util_ci.obj : $(START_DIR)\CXSparse\Source\cs_util_ci.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\CXSparse\Source\cs_util_ci.c


cs_reach_ri.obj : $(START_DIR)\CXSparse\Source\cs_reach_ri.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\CXSparse\Source\cs_reach_ri.c


cs_reach_ci.obj : $(START_DIR)\CXSparse\Source\cs_reach_ci.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\CXSparse\Source\cs_reach_ci.c


cs_spsolve_ri.obj : $(START_DIR)\CXSparse\Source\cs_spsolve_ri.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\CXSparse\Source\cs_spsolve_ri.c


cs_spsolve_ci.obj : $(START_DIR)\CXSparse\Source\cs_spsolve_ci.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\CXSparse\Source\cs_spsolve_ci.c


cs_ereach_ri.obj : $(START_DIR)\CXSparse\Source\cs_ereach_ri.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\CXSparse\Source\cs_ereach_ri.c


cs_ereach_ci.obj : $(START_DIR)\CXSparse\Source\cs_ereach_ci.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\CXSparse\Source\cs_ereach_ci.c


cs_leaf_ri.obj : $(START_DIR)\CXSparse\Source\cs_leaf_ri.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\CXSparse\Source\cs_leaf_ri.c


cs_leaf_ci.obj : $(START_DIR)\CXSparse\Source\cs_leaf_ci.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\CXSparse\Source\cs_leaf_ci.c


cs_randperm_ri.obj : $(START_DIR)\CXSparse\Source\cs_randperm_ri.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\CXSparse\Source\cs_randperm_ri.c


cs_randperm_ci.obj : $(START_DIR)\CXSparse\Source\cs_randperm_ci.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\CXSparse\Source\cs_randperm_ci.c


cs_operator_ri.obj : $(START_DIR)\CXSparse\Source\cs_operator_ri.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\CXSparse\Source\cs_operator_ri.c


cs_operator_ci.obj : $(START_DIR)\CXSparse\Source\cs_operator_ci.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\CXSparse\Source\cs_operator_ci.c


solve_from_lu.obj : $(START_DIR)\CXSparse\CXSparseSupport\solve_from_lu.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\CXSparse\CXSparseSupport\solve_from_lu.c


solve_from_qr.obj : $(START_DIR)\CXSparse\CXSparseSupport\solve_from_qr.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\CXSparse\CXSparseSupport\solve_from_qr.c


makeCXSparseMatrix.obj : $(START_DIR)\CXSparse\CXSparseSupport\makeCXSparseMatrix.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\CXSparse\CXSparseSupport\makeCXSparseMatrix.c


unpackCXStruct.obj : $(START_DIR)\CXSparse\CXSparseSupport\unpackCXStruct.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\CXSparse\CXSparseSupport\unpackCXStruct.c


TraitementEMGV1_data.obj : $(START_DIR)\TraitementEMGV1_data.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\TraitementEMGV1_data.c


rt_nonfinite.obj : $(START_DIR)\rt_nonfinite.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\rt_nonfinite.c


rtGetNaN.obj : $(START_DIR)\rtGetNaN.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\rtGetNaN.c


rtGetInf.obj : $(START_DIR)\rtGetInf.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\rtGetInf.c


TraitementEMGV1_initialize.obj : $(START_DIR)\TraitementEMGV1_initialize.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\TraitementEMGV1_initialize.c


TraitementEMGV1_terminate.obj : $(START_DIR)\TraitementEMGV1_terminate.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\TraitementEMGV1_terminate.c


TraitementEMGV1.obj : $(START_DIR)\TraitementEMGV1.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\TraitementEMGV1.c


detrend.obj : $(START_DIR)\detrend.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\detrend.c


qr.obj : $(START_DIR)\qr.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\qr.c


xnrm2.obj : $(START_DIR)\xnrm2.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\xnrm2.c


pwelch.obj : $(START_DIR)\pwelch.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\pwelch.c


computeperiodogram.obj : $(START_DIR)\computeperiodogram.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\computeperiodogram.c


computepsd.obj : $(START_DIR)\computepsd.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\computepsd.c


welch.obj : $(START_DIR)\welch.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\welch.c


butter.obj : $(START_DIR)\butter.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\butter.c


poly.obj : $(START_DIR)\poly.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\poly.c


eigStandard.obj : $(START_DIR)\eigStandard.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\eigStandard.c


xzlartg.obj : $(START_DIR)\xzlartg.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\xzlartg.c


xzhgeqz.obj : $(START_DIR)\xzhgeqz.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\xzhgeqz.c


filter.obj : $(START_DIR)\filter.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\filter.c


movSumProdOrMean.obj : $(START_DIR)\movSumProdOrMean.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\movSumProdOrMean.c


xgeqrf.obj : $(START_DIR)\xgeqrf.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\xgeqrf.c


xgerc.obj : $(START_DIR)\xgerc.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\xgerc.c


xorgqr.obj : $(START_DIR)\xorgqr.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\xorgqr.c


trisolve.obj : $(START_DIR)\trisolve.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\trisolve.c


FFTImplementationCallback.obj : $(START_DIR)\FFTImplementationCallback.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\FFTImplementationCallback.c


useConstantDim.obj : $(START_DIR)\useConstantDim.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\useConstantDim.c


xhseqr.obj : $(START_DIR)\xhseqr.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\xhseqr.c


xzlarfg.obj : $(START_DIR)\xzlarfg.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\xzlarfg.c


xdlanv2.obj : $(START_DIR)\xdlanv2.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\xdlanv2.c


sqrt.obj : $(START_DIR)\sqrt.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\sqrt.c


filtfilt.obj : $(START_DIR)\filtfilt.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\filtfilt.c


insertionsort.obj : $(START_DIR)\insertionsort.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\insertionsort.c


introsort.obj : $(START_DIR)\introsort.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\introsort.c


TraitementEMGV1_emxutil.obj : $(START_DIR)\TraitementEMGV1_emxutil.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\TraitementEMGV1_emxutil.c


TraitementEMGV1_rtwutil.obj : $(START_DIR)\TraitementEMGV1_rtwutil.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\TraitementEMGV1_rtwutil.c


###########################################################################
## DEPENDENCIES
###########################################################################

$(ALL_OBJS) : rtw_proj.tmw $(COMPILER_COMMAND_FILE) $(MAKEFILE)


###########################################################################
## MISCELLANEOUS TARGETS
###########################################################################

info : 
	@cmd /C "@echo ### PRODUCT = $(PRODUCT)"
	@cmd /C "@echo ### PRODUCT_TYPE = $(PRODUCT_TYPE)"
	@cmd /C "@echo ### BUILD_TYPE = $(BUILD_TYPE)"
	@cmd /C "@echo ### INCLUDES = $(INCLUDES)"
	@cmd /C "@echo ### DEFINES = $(DEFINES)"
	@cmd /C "@echo ### ALL_SRCS = $(ALL_SRCS)"
	@cmd /C "@echo ### ALL_OBJS = $(ALL_OBJS)"
	@cmd /C "@echo ### LIBS = $(LIBS)"
	@cmd /C "@echo ### MODELREF_LIBS = $(MODELREF_LIBS)"
	@cmd /C "@echo ### SYSTEM_LIBS = $(SYSTEM_LIBS)"
	@cmd /C "@echo ### TOOLCHAIN_LIBS = $(TOOLCHAIN_LIBS)"
	@cmd /C "@echo ### CFLAGS = $(CFLAGS)"
	@cmd /C "@echo ### LDFLAGS = $(LDFLAGS)"
	@cmd /C "@echo ### SHAREDLIB_LDFLAGS = $(SHAREDLIB_LDFLAGS)"
	@cmd /C "@echo ### CPPFLAGS = $(CPPFLAGS)"
	@cmd /C "@echo ### CPP_LDFLAGS = $(CPP_LDFLAGS)"
	@cmd /C "@echo ### CPP_SHAREDLIB_LDFLAGS = $(CPP_SHAREDLIB_LDFLAGS)"
	@cmd /C "@echo ### ARFLAGS = $(ARFLAGS)"
	@cmd /C "@echo ### MEX_CFLAGS = $(MEX_CFLAGS)"
	@cmd /C "@echo ### MEX_CPPFLAGS = $(MEX_CPPFLAGS)"
	@cmd /C "@echo ### MEX_LDFLAGS = $(MEX_LDFLAGS)"
	@cmd /C "@echo ### MEX_CPPLDFLAGS = $(MEX_CPPLDFLAGS)"
	@cmd /C "@echo ### DOWNLOAD_FLAGS = $(DOWNLOAD_FLAGS)"
	@cmd /C "@echo ### EXECUTE_FLAGS = $(EXECUTE_FLAGS)"
	@cmd /C "@echo ### MAKE_FLAGS = $(MAKE_FLAGS)"


clean : 
	$(ECHO) "### Deleting all derived files..."
	@if exist $(PRODUCT) $(RM) $(PRODUCT)
	$(RM) $(ALL_OBJS)
	$(ECHO) "### Deleted all derived files."


