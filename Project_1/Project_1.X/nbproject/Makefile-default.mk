#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/Project_1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/Project_1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=src/adc/adc.c src/timers/timers.c src/uart/uart_functions.c src/main.c src/aux_functions.c src/temperature.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/src/adc/adc.o ${OBJECTDIR}/src/timers/timers.o ${OBJECTDIR}/src/uart/uart_functions.o ${OBJECTDIR}/src/main.o ${OBJECTDIR}/src/aux_functions.o ${OBJECTDIR}/src/temperature.o
POSSIBLE_DEPFILES=${OBJECTDIR}/src/adc/adc.o.d ${OBJECTDIR}/src/timers/timers.o.d ${OBJECTDIR}/src/uart/uart_functions.o.d ${OBJECTDIR}/src/main.o.d ${OBJECTDIR}/src/aux_functions.o.d ${OBJECTDIR}/src/temperature.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/src/adc/adc.o ${OBJECTDIR}/src/timers/timers.o ${OBJECTDIR}/src/uart/uart_functions.o ${OBJECTDIR}/src/main.o ${OBJECTDIR}/src/aux_functions.o ${OBJECTDIR}/src/temperature.o

# Source Files
SOURCEFILES=src/adc/adc.c src/timers/timers.c src/uart/uart_functions.c src/main.c src/aux_functions.c src/temperature.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/Project_1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=32MX795F512L
MP_LINKER_FILE_OPTION=
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/src/adc/adc.o: src/adc/adc.c  .generated_files/flags/default/4ddef18059855cc93d8cca51be20de55e0cca75e .generated_files/flags/default/fa77e48c5d6b209b0dbc904325b3870195f7a677
	@${MKDIR} "${OBJECTDIR}/src/adc" 
	@${RM} ${OBJECTDIR}/src/adc/adc.o.d 
	@${RM} ${OBJECTDIR}/src/adc/adc.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"includes" -MP -MMD -MF "${OBJECTDIR}/src/adc/adc.o.d" -o ${OBJECTDIR}/src/adc/adc.o src/adc/adc.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -std=c99   
	
${OBJECTDIR}/src/timers/timers.o: src/timers/timers.c  .generated_files/flags/default/eaad2ce53c3ef624b0deff024c35fd42063a31b3 .generated_files/flags/default/fa77e48c5d6b209b0dbc904325b3870195f7a677
	@${MKDIR} "${OBJECTDIR}/src/timers" 
	@${RM} ${OBJECTDIR}/src/timers/timers.o.d 
	@${RM} ${OBJECTDIR}/src/timers/timers.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"includes" -MP -MMD -MF "${OBJECTDIR}/src/timers/timers.o.d" -o ${OBJECTDIR}/src/timers/timers.o src/timers/timers.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -std=c99   
	
${OBJECTDIR}/src/uart/uart_functions.o: src/uart/uart_functions.c  .generated_files/flags/default/1310126cc5435b45d0ee01d9bae279fa11d836a7 .generated_files/flags/default/fa77e48c5d6b209b0dbc904325b3870195f7a677
	@${MKDIR} "${OBJECTDIR}/src/uart" 
	@${RM} ${OBJECTDIR}/src/uart/uart_functions.o.d 
	@${RM} ${OBJECTDIR}/src/uart/uart_functions.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"includes" -MP -MMD -MF "${OBJECTDIR}/src/uart/uart_functions.o.d" -o ${OBJECTDIR}/src/uart/uart_functions.o src/uart/uart_functions.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -std=c99   
	
${OBJECTDIR}/src/main.o: src/main.c  .generated_files/flags/default/da5480ab107dbd0a9b7230e47efeafbc313fb81f .generated_files/flags/default/fa77e48c5d6b209b0dbc904325b3870195f7a677
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/main.o.d 
	@${RM} ${OBJECTDIR}/src/main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"includes" -MP -MMD -MF "${OBJECTDIR}/src/main.o.d" -o ${OBJECTDIR}/src/main.o src/main.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -std=c99   
	
${OBJECTDIR}/src/aux_functions.o: src/aux_functions.c  .generated_files/flags/default/369a0710f1ae7cf712302010fba0dd40549fa430 .generated_files/flags/default/fa77e48c5d6b209b0dbc904325b3870195f7a677
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/aux_functions.o.d 
	@${RM} ${OBJECTDIR}/src/aux_functions.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"includes" -MP -MMD -MF "${OBJECTDIR}/src/aux_functions.o.d" -o ${OBJECTDIR}/src/aux_functions.o src/aux_functions.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -std=c99   
	
${OBJECTDIR}/src/temperature.o: src/temperature.c  .generated_files/flags/default/54bd4d53d274946cea342ecfc8e16252a42a1125 .generated_files/flags/default/fa77e48c5d6b209b0dbc904325b3870195f7a677
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/temperature.o.d 
	@${RM} ${OBJECTDIR}/src/temperature.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"includes" -MP -MMD -MF "${OBJECTDIR}/src/temperature.o.d" -o ${OBJECTDIR}/src/temperature.o src/temperature.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -std=c99   
	
else
${OBJECTDIR}/src/adc/adc.o: src/adc/adc.c  .generated_files/flags/default/430749664346928afc9fbcb707c3f22666067447 .generated_files/flags/default/fa77e48c5d6b209b0dbc904325b3870195f7a677
	@${MKDIR} "${OBJECTDIR}/src/adc" 
	@${RM} ${OBJECTDIR}/src/adc/adc.o.d 
	@${RM} ${OBJECTDIR}/src/adc/adc.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"includes" -MP -MMD -MF "${OBJECTDIR}/src/adc/adc.o.d" -o ${OBJECTDIR}/src/adc/adc.o src/adc/adc.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -std=c99   
	
${OBJECTDIR}/src/timers/timers.o: src/timers/timers.c  .generated_files/flags/default/4c48eaf4e760bb8ed6c0e2db1ef5fc5ac41e28b4 .generated_files/flags/default/fa77e48c5d6b209b0dbc904325b3870195f7a677
	@${MKDIR} "${OBJECTDIR}/src/timers" 
	@${RM} ${OBJECTDIR}/src/timers/timers.o.d 
	@${RM} ${OBJECTDIR}/src/timers/timers.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"includes" -MP -MMD -MF "${OBJECTDIR}/src/timers/timers.o.d" -o ${OBJECTDIR}/src/timers/timers.o src/timers/timers.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -std=c99   
	
${OBJECTDIR}/src/uart/uart_functions.o: src/uart/uart_functions.c  .generated_files/flags/default/e31bb46fb790c66d3eb478b4c93c7674e62dec1c .generated_files/flags/default/fa77e48c5d6b209b0dbc904325b3870195f7a677
	@${MKDIR} "${OBJECTDIR}/src/uart" 
	@${RM} ${OBJECTDIR}/src/uart/uart_functions.o.d 
	@${RM} ${OBJECTDIR}/src/uart/uart_functions.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"includes" -MP -MMD -MF "${OBJECTDIR}/src/uart/uart_functions.o.d" -o ${OBJECTDIR}/src/uart/uart_functions.o src/uart/uart_functions.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -std=c99   
	
${OBJECTDIR}/src/main.o: src/main.c  .generated_files/flags/default/eca49de56827882efc72a28310e3e94f90f49482 .generated_files/flags/default/fa77e48c5d6b209b0dbc904325b3870195f7a677
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/main.o.d 
	@${RM} ${OBJECTDIR}/src/main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"includes" -MP -MMD -MF "${OBJECTDIR}/src/main.o.d" -o ${OBJECTDIR}/src/main.o src/main.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -std=c99   
	
${OBJECTDIR}/src/aux_functions.o: src/aux_functions.c  .generated_files/flags/default/4acd99e81fcd7358e92adf3f3af5c897c85978af .generated_files/flags/default/fa77e48c5d6b209b0dbc904325b3870195f7a677
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/aux_functions.o.d 
	@${RM} ${OBJECTDIR}/src/aux_functions.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"includes" -MP -MMD -MF "${OBJECTDIR}/src/aux_functions.o.d" -o ${OBJECTDIR}/src/aux_functions.o src/aux_functions.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -std=c99   
	
${OBJECTDIR}/src/temperature.o: src/temperature.c  .generated_files/flags/default/cb0cb6a64a3549057b55645585835e29c1ba4b3f .generated_files/flags/default/fa77e48c5d6b209b0dbc904325b3870195f7a677
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/temperature.o.d 
	@${RM} ${OBJECTDIR}/src/temperature.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"includes" -MP -MMD -MF "${OBJECTDIR}/src/temperature.o.d" -o ${OBJECTDIR}/src/temperature.o src/temperature.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -std=c99   
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/Project_1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -g -mdebugger -D__MPLAB_DEBUGGER_PK3=1 -mprocessor=$(MP_PROCESSOR_OPTION)  -o ${DISTDIR}/Project_1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)  -legacy-libc  -std=c99 $(COMPARISON_BUILD)   -mreserve=data@0x0:0x1FC -mreserve=boot@0x1FC02000:0x1FC02FEF -mreserve=boot@0x1FC02000:0x1FC024FF  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D=__DEBUG_D,--defsym=__MPLAB_DEBUGGER_PK3=1,--defsym=_min_heap_size=256,--defsym=_min_stack_size=256,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,${DISTDIR}/memoryfile.xml 
	
else
${DISTDIR}/Project_1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION)  -o ${DISTDIR}/Project_1.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)  -legacy-libc  -std=c99 $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=_min_heap_size=256,--defsym=_min_stack_size=256,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,${DISTDIR}/memoryfile.xml 
	${MP_CC_DIR}\\xc32-bin2hex ${DISTDIR}/Project_1.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
