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
FINAL_IMAGE=${DISTDIR}/Project_2.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/Project_2.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
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
SOURCEFILES_QUOTED_IF_SPACED=src/adc/adc.c src/timers/timers.c src/uart/uart_functions.c src/aux_functions.c src/main.c includes/encoder.c includes/PI.c includes/motor_control.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/src/adc/adc.o ${OBJECTDIR}/src/timers/timers.o ${OBJECTDIR}/src/uart/uart_functions.o ${OBJECTDIR}/src/aux_functions.o ${OBJECTDIR}/src/main.o ${OBJECTDIR}/includes/encoder.o ${OBJECTDIR}/includes/PI.o ${OBJECTDIR}/includes/motor_control.o
POSSIBLE_DEPFILES=${OBJECTDIR}/src/adc/adc.o.d ${OBJECTDIR}/src/timers/timers.o.d ${OBJECTDIR}/src/uart/uart_functions.o.d ${OBJECTDIR}/src/aux_functions.o.d ${OBJECTDIR}/src/main.o.d ${OBJECTDIR}/includes/encoder.o.d ${OBJECTDIR}/includes/PI.o.d ${OBJECTDIR}/includes/motor_control.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/src/adc/adc.o ${OBJECTDIR}/src/timers/timers.o ${OBJECTDIR}/src/uart/uart_functions.o ${OBJECTDIR}/src/aux_functions.o ${OBJECTDIR}/src/main.o ${OBJECTDIR}/includes/encoder.o ${OBJECTDIR}/includes/PI.o ${OBJECTDIR}/includes/motor_control.o

# Source Files
SOURCEFILES=src/adc/adc.c src/timers/timers.c src/uart/uart_functions.c src/aux_functions.c src/main.c includes/encoder.c includes/PI.c includes/motor_control.c



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
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/Project_2.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

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
${OBJECTDIR}/src/adc/adc.o: src/adc/adc.c  .generated_files/flags/default/78691a8612f91ced2ed3eaf49ca7680ac54e7428 .generated_files/flags/default/fa77e48c5d6b209b0dbc904325b3870195f7a677
	@${MKDIR} "${OBJECTDIR}/src/adc" 
	@${RM} ${OBJECTDIR}/src/adc/adc.o.d 
	@${RM} ${OBJECTDIR}/src/adc/adc.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"includes" -MP -MMD -MF "${OBJECTDIR}/src/adc/adc.o.d" -o ${OBJECTDIR}/src/adc/adc.o src/adc/adc.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -std=c99   
	
${OBJECTDIR}/src/timers/timers.o: src/timers/timers.c  .generated_files/flags/default/3de44d8c6c9c866ada9480321ca81b99b428b5e4 .generated_files/flags/default/fa77e48c5d6b209b0dbc904325b3870195f7a677
	@${MKDIR} "${OBJECTDIR}/src/timers" 
	@${RM} ${OBJECTDIR}/src/timers/timers.o.d 
	@${RM} ${OBJECTDIR}/src/timers/timers.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"includes" -MP -MMD -MF "${OBJECTDIR}/src/timers/timers.o.d" -o ${OBJECTDIR}/src/timers/timers.o src/timers/timers.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -std=c99   
	
${OBJECTDIR}/src/uart/uart_functions.o: src/uart/uart_functions.c  .generated_files/flags/default/beafd2c63faf33eab675482b9fb5de6a95b8e116 .generated_files/flags/default/fa77e48c5d6b209b0dbc904325b3870195f7a677
	@${MKDIR} "${OBJECTDIR}/src/uart" 
	@${RM} ${OBJECTDIR}/src/uart/uart_functions.o.d 
	@${RM} ${OBJECTDIR}/src/uart/uart_functions.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"includes" -MP -MMD -MF "${OBJECTDIR}/src/uart/uart_functions.o.d" -o ${OBJECTDIR}/src/uart/uart_functions.o src/uart/uart_functions.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -std=c99   
	
${OBJECTDIR}/src/aux_functions.o: src/aux_functions.c  .generated_files/flags/default/fa67e01d2781f92dfe3eb89ddff0f7042df9078a .generated_files/flags/default/fa77e48c5d6b209b0dbc904325b3870195f7a677
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/aux_functions.o.d 
	@${RM} ${OBJECTDIR}/src/aux_functions.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"includes" -MP -MMD -MF "${OBJECTDIR}/src/aux_functions.o.d" -o ${OBJECTDIR}/src/aux_functions.o src/aux_functions.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -std=c99   
	
${OBJECTDIR}/src/main.o: src/main.c  .generated_files/flags/default/19b2da2b0965608cdd83022193de65b2516f53f1 .generated_files/flags/default/fa77e48c5d6b209b0dbc904325b3870195f7a677
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/main.o.d 
	@${RM} ${OBJECTDIR}/src/main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"includes" -MP -MMD -MF "${OBJECTDIR}/src/main.o.d" -o ${OBJECTDIR}/src/main.o src/main.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -std=c99   
	
${OBJECTDIR}/includes/encoder.o: includes/encoder.c  .generated_files/flags/default/2e5a12813ed2d828bee7a8aafa5ec9c3cdf9f685 .generated_files/flags/default/fa77e48c5d6b209b0dbc904325b3870195f7a677
	@${MKDIR} "${OBJECTDIR}/includes" 
	@${RM} ${OBJECTDIR}/includes/encoder.o.d 
	@${RM} ${OBJECTDIR}/includes/encoder.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"includes" -MP -MMD -MF "${OBJECTDIR}/includes/encoder.o.d" -o ${OBJECTDIR}/includes/encoder.o includes/encoder.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -std=c99   
	
${OBJECTDIR}/includes/PI.o: includes/PI.c  .generated_files/flags/default/9cfd96963398d1f7d1043b3d86492bedd4ea6430 .generated_files/flags/default/fa77e48c5d6b209b0dbc904325b3870195f7a677
	@${MKDIR} "${OBJECTDIR}/includes" 
	@${RM} ${OBJECTDIR}/includes/PI.o.d 
	@${RM} ${OBJECTDIR}/includes/PI.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"includes" -MP -MMD -MF "${OBJECTDIR}/includes/PI.o.d" -o ${OBJECTDIR}/includes/PI.o includes/PI.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -std=c99   
	
${OBJECTDIR}/includes/motor_control.o: includes/motor_control.c  .generated_files/flags/default/a6b63d15c67a1f1ad700979492b35c6044d67c46 .generated_files/flags/default/fa77e48c5d6b209b0dbc904325b3870195f7a677
	@${MKDIR} "${OBJECTDIR}/includes" 
	@${RM} ${OBJECTDIR}/includes/motor_control.o.d 
	@${RM} ${OBJECTDIR}/includes/motor_control.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"includes" -MP -MMD -MF "${OBJECTDIR}/includes/motor_control.o.d" -o ${OBJECTDIR}/includes/motor_control.o includes/motor_control.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -std=c99   
	
else
${OBJECTDIR}/src/adc/adc.o: src/adc/adc.c  .generated_files/flags/default/9733831638e95aa49ef089c6f98c3d96a68e8e01 .generated_files/flags/default/fa77e48c5d6b209b0dbc904325b3870195f7a677
	@${MKDIR} "${OBJECTDIR}/src/adc" 
	@${RM} ${OBJECTDIR}/src/adc/adc.o.d 
	@${RM} ${OBJECTDIR}/src/adc/adc.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"includes" -MP -MMD -MF "${OBJECTDIR}/src/adc/adc.o.d" -o ${OBJECTDIR}/src/adc/adc.o src/adc/adc.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -std=c99   
	
${OBJECTDIR}/src/timers/timers.o: src/timers/timers.c  .generated_files/flags/default/48eac2d19c9c9c292e49d1608b3fadf99439e35a .generated_files/flags/default/fa77e48c5d6b209b0dbc904325b3870195f7a677
	@${MKDIR} "${OBJECTDIR}/src/timers" 
	@${RM} ${OBJECTDIR}/src/timers/timers.o.d 
	@${RM} ${OBJECTDIR}/src/timers/timers.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"includes" -MP -MMD -MF "${OBJECTDIR}/src/timers/timers.o.d" -o ${OBJECTDIR}/src/timers/timers.o src/timers/timers.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -std=c99   
	
${OBJECTDIR}/src/uart/uart_functions.o: src/uart/uart_functions.c  .generated_files/flags/default/51797b3b9611dda191584a260eb670067d08fa38 .generated_files/flags/default/fa77e48c5d6b209b0dbc904325b3870195f7a677
	@${MKDIR} "${OBJECTDIR}/src/uart" 
	@${RM} ${OBJECTDIR}/src/uart/uart_functions.o.d 
	@${RM} ${OBJECTDIR}/src/uart/uart_functions.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"includes" -MP -MMD -MF "${OBJECTDIR}/src/uart/uart_functions.o.d" -o ${OBJECTDIR}/src/uart/uart_functions.o src/uart/uart_functions.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -std=c99   
	
${OBJECTDIR}/src/aux_functions.o: src/aux_functions.c  .generated_files/flags/default/42d4cd916fe18719968589096674952334790da .generated_files/flags/default/fa77e48c5d6b209b0dbc904325b3870195f7a677
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/aux_functions.o.d 
	@${RM} ${OBJECTDIR}/src/aux_functions.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"includes" -MP -MMD -MF "${OBJECTDIR}/src/aux_functions.o.d" -o ${OBJECTDIR}/src/aux_functions.o src/aux_functions.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -std=c99   
	
${OBJECTDIR}/src/main.o: src/main.c  .generated_files/flags/default/adf6e1c84067d2540541b8850b7c74ba4f2a69ea .generated_files/flags/default/fa77e48c5d6b209b0dbc904325b3870195f7a677
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/main.o.d 
	@${RM} ${OBJECTDIR}/src/main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"includes" -MP -MMD -MF "${OBJECTDIR}/src/main.o.d" -o ${OBJECTDIR}/src/main.o src/main.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -std=c99   
	
${OBJECTDIR}/includes/encoder.o: includes/encoder.c  .generated_files/flags/default/9da4dfbc74101dfd3d52e364bb0ffc339875bdc5 .generated_files/flags/default/fa77e48c5d6b209b0dbc904325b3870195f7a677
	@${MKDIR} "${OBJECTDIR}/includes" 
	@${RM} ${OBJECTDIR}/includes/encoder.o.d 
	@${RM} ${OBJECTDIR}/includes/encoder.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"includes" -MP -MMD -MF "${OBJECTDIR}/includes/encoder.o.d" -o ${OBJECTDIR}/includes/encoder.o includes/encoder.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -std=c99   
	
${OBJECTDIR}/includes/PI.o: includes/PI.c  .generated_files/flags/default/d3d444d1b16971a043e970382c5de00f7fa4530e .generated_files/flags/default/fa77e48c5d6b209b0dbc904325b3870195f7a677
	@${MKDIR} "${OBJECTDIR}/includes" 
	@${RM} ${OBJECTDIR}/includes/PI.o.d 
	@${RM} ${OBJECTDIR}/includes/PI.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"includes" -MP -MMD -MF "${OBJECTDIR}/includes/PI.o.d" -o ${OBJECTDIR}/includes/PI.o includes/PI.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -std=c99   
	
${OBJECTDIR}/includes/motor_control.o: includes/motor_control.c  .generated_files/flags/default/945eddcbe75e9d6339592a8febe77a1611432336 .generated_files/flags/default/fa77e48c5d6b209b0dbc904325b3870195f7a677
	@${MKDIR} "${OBJECTDIR}/includes" 
	@${RM} ${OBJECTDIR}/includes/motor_control.o.d 
	@${RM} ${OBJECTDIR}/includes/motor_control.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"includes" -MP -MMD -MF "${OBJECTDIR}/includes/motor_control.o.d" -o ${OBJECTDIR}/includes/motor_control.o includes/motor_control.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -std=c99   
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/Project_2.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -g -mdebugger -D__MPLAB_DEBUGGER_PK3=1 -mprocessor=$(MP_PROCESSOR_OPTION)  -o ${DISTDIR}/Project_2.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)  -legacy-libc  -std=c99 $(COMPARISON_BUILD)   -mreserve=data@0x0:0x1FC -mreserve=boot@0x1FC02000:0x1FC02FEF -mreserve=boot@0x1FC02000:0x1FC024FF  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D=__DEBUG_D,--defsym=__MPLAB_DEBUGGER_PK3=1,--defsym=_min_heap_size=512,--defsym=_min_stack_size=512,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,${DISTDIR}/memoryfile.xml 
	
else
${DISTDIR}/Project_2.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION)  -o ${DISTDIR}/Project_2.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)  -legacy-libc  -std=c99 $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=_min_heap_size=512,--defsym=_min_stack_size=512,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,${DISTDIR}/memoryfile.xml 
	${MP_CC_DIR}\\xc32-bin2hex ${DISTDIR}/Project_2.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}
