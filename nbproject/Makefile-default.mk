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
OUTPUT_SUFFIX=cof
DEBUGGABLE_SUFFIX=cof
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/SmartDoor.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=cof
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/SmartDoor.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=
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
SOURCEFILES_QUOTED_IF_SPACED=adc/adc.c lcd/lcd.c interrupt/interrupt.c timer/timer.c button_matrix/button.c uart/uart.c fsm_door/fsm_door.c global/global.c rfid/rfid.c password/password.c peripheral/peripheral.c main/main.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/adc/adc.o ${OBJECTDIR}/lcd/lcd.o ${OBJECTDIR}/interrupt/interrupt.o ${OBJECTDIR}/timer/timer.o ${OBJECTDIR}/button_matrix/button.o ${OBJECTDIR}/uart/uart.o ${OBJECTDIR}/fsm_door/fsm_door.o ${OBJECTDIR}/global/global.o ${OBJECTDIR}/rfid/rfid.o ${OBJECTDIR}/password/password.o ${OBJECTDIR}/peripheral/peripheral.o ${OBJECTDIR}/main/main.o
POSSIBLE_DEPFILES=${OBJECTDIR}/adc/adc.o.d ${OBJECTDIR}/lcd/lcd.o.d ${OBJECTDIR}/interrupt/interrupt.o.d ${OBJECTDIR}/timer/timer.o.d ${OBJECTDIR}/button_matrix/button.o.d ${OBJECTDIR}/uart/uart.o.d ${OBJECTDIR}/fsm_door/fsm_door.o.d ${OBJECTDIR}/global/global.o.d ${OBJECTDIR}/rfid/rfid.o.d ${OBJECTDIR}/password/password.o.d ${OBJECTDIR}/peripheral/peripheral.o.d ${OBJECTDIR}/main/main.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/adc/adc.o ${OBJECTDIR}/lcd/lcd.o ${OBJECTDIR}/interrupt/interrupt.o ${OBJECTDIR}/timer/timer.o ${OBJECTDIR}/button_matrix/button.o ${OBJECTDIR}/uart/uart.o ${OBJECTDIR}/fsm_door/fsm_door.o ${OBJECTDIR}/global/global.o ${OBJECTDIR}/rfid/rfid.o ${OBJECTDIR}/password/password.o ${OBJECTDIR}/peripheral/peripheral.o ${OBJECTDIR}/main/main.o

# Source Files
SOURCEFILES=adc/adc.c lcd/lcd.c interrupt/interrupt.c timer/timer.c button_matrix/button.c uart/uart.c fsm_door/fsm_door.c global/global.c rfid/rfid.c password/password.c peripheral/peripheral.c main/main.c


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
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/SmartDoor.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=18F4620
MP_PROCESSOR_OPTION_LD=18f4620
MP_LINKER_DEBUG_OPTION= -u_DEBUGCODESTART=0xfdc0 -u_DEBUGCODELEN=0x240 -u_DEBUGDATASTART=0xef4 -u_DEBUGDATALEN=0xb
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/adc/adc.o: adc/adc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/adc" 
	@${RM} ${OBJECTDIR}/adc/adc.o.d 
	@${RM} ${OBJECTDIR}/adc/adc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/adc/adc.o   adc/adc.c 
	@${DEP_GEN} -d ${OBJECTDIR}/adc/adc.o 
	@${FIXDEPS} "${OBJECTDIR}/adc/adc.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/lcd/lcd.o: lcd/lcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/lcd" 
	@${RM} ${OBJECTDIR}/lcd/lcd.o.d 
	@${RM} ${OBJECTDIR}/lcd/lcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/lcd/lcd.o   lcd/lcd.c 
	@${DEP_GEN} -d ${OBJECTDIR}/lcd/lcd.o 
	@${FIXDEPS} "${OBJECTDIR}/lcd/lcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/interrupt/interrupt.o: interrupt/interrupt.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/interrupt" 
	@${RM} ${OBJECTDIR}/interrupt/interrupt.o.d 
	@${RM} ${OBJECTDIR}/interrupt/interrupt.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/interrupt/interrupt.o   interrupt/interrupt.c 
	@${DEP_GEN} -d ${OBJECTDIR}/interrupt/interrupt.o 
	@${FIXDEPS} "${OBJECTDIR}/interrupt/interrupt.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/timer/timer.o: timer/timer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/timer" 
	@${RM} ${OBJECTDIR}/timer/timer.o.d 
	@${RM} ${OBJECTDIR}/timer/timer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/timer/timer.o   timer/timer.c 
	@${DEP_GEN} -d ${OBJECTDIR}/timer/timer.o 
	@${FIXDEPS} "${OBJECTDIR}/timer/timer.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/button_matrix/button.o: button_matrix/button.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/button_matrix" 
	@${RM} ${OBJECTDIR}/button_matrix/button.o.d 
	@${RM} ${OBJECTDIR}/button_matrix/button.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/button_matrix/button.o   button_matrix/button.c 
	@${DEP_GEN} -d ${OBJECTDIR}/button_matrix/button.o 
	@${FIXDEPS} "${OBJECTDIR}/button_matrix/button.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/uart/uart.o: uart/uart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/uart" 
	@${RM} ${OBJECTDIR}/uart/uart.o.d 
	@${RM} ${OBJECTDIR}/uart/uart.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/uart/uart.o   uart/uart.c 
	@${DEP_GEN} -d ${OBJECTDIR}/uart/uart.o 
	@${FIXDEPS} "${OBJECTDIR}/uart/uart.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/fsm_door/fsm_door.o: fsm_door/fsm_door.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/fsm_door" 
	@${RM} ${OBJECTDIR}/fsm_door/fsm_door.o.d 
	@${RM} ${OBJECTDIR}/fsm_door/fsm_door.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/fsm_door/fsm_door.o   fsm_door/fsm_door.c 
	@${DEP_GEN} -d ${OBJECTDIR}/fsm_door/fsm_door.o 
	@${FIXDEPS} "${OBJECTDIR}/fsm_door/fsm_door.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/global/global.o: global/global.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/global" 
	@${RM} ${OBJECTDIR}/global/global.o.d 
	@${RM} ${OBJECTDIR}/global/global.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/global/global.o   global/global.c 
	@${DEP_GEN} -d ${OBJECTDIR}/global/global.o 
	@${FIXDEPS} "${OBJECTDIR}/global/global.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/rfid/rfid.o: rfid/rfid.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/rfid" 
	@${RM} ${OBJECTDIR}/rfid/rfid.o.d 
	@${RM} ${OBJECTDIR}/rfid/rfid.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/rfid/rfid.o   rfid/rfid.c 
	@${DEP_GEN} -d ${OBJECTDIR}/rfid/rfid.o 
	@${FIXDEPS} "${OBJECTDIR}/rfid/rfid.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/password/password.o: password/password.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/password" 
	@${RM} ${OBJECTDIR}/password/password.o.d 
	@${RM} ${OBJECTDIR}/password/password.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/password/password.o   password/password.c 
	@${DEP_GEN} -d ${OBJECTDIR}/password/password.o 
	@${FIXDEPS} "${OBJECTDIR}/password/password.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/peripheral/peripheral.o: peripheral/peripheral.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/peripheral" 
	@${RM} ${OBJECTDIR}/peripheral/peripheral.o.d 
	@${RM} ${OBJECTDIR}/peripheral/peripheral.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/peripheral/peripheral.o   peripheral/peripheral.c 
	@${DEP_GEN} -d ${OBJECTDIR}/peripheral/peripheral.o 
	@${FIXDEPS} "${OBJECTDIR}/peripheral/peripheral.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/main/main.o: main/main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/main" 
	@${RM} ${OBJECTDIR}/main/main.o.d 
	@${RM} ${OBJECTDIR}/main/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/main/main.o   main/main.c 
	@${DEP_GEN} -d ${OBJECTDIR}/main/main.o 
	@${FIXDEPS} "${OBJECTDIR}/main/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
else
${OBJECTDIR}/adc/adc.o: adc/adc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/adc" 
	@${RM} ${OBJECTDIR}/adc/adc.o.d 
	@${RM} ${OBJECTDIR}/adc/adc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/adc/adc.o   adc/adc.c 
	@${DEP_GEN} -d ${OBJECTDIR}/adc/adc.o 
	@${FIXDEPS} "${OBJECTDIR}/adc/adc.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/lcd/lcd.o: lcd/lcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/lcd" 
	@${RM} ${OBJECTDIR}/lcd/lcd.o.d 
	@${RM} ${OBJECTDIR}/lcd/lcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/lcd/lcd.o   lcd/lcd.c 
	@${DEP_GEN} -d ${OBJECTDIR}/lcd/lcd.o 
	@${FIXDEPS} "${OBJECTDIR}/lcd/lcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/interrupt/interrupt.o: interrupt/interrupt.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/interrupt" 
	@${RM} ${OBJECTDIR}/interrupt/interrupt.o.d 
	@${RM} ${OBJECTDIR}/interrupt/interrupt.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/interrupt/interrupt.o   interrupt/interrupt.c 
	@${DEP_GEN} -d ${OBJECTDIR}/interrupt/interrupt.o 
	@${FIXDEPS} "${OBJECTDIR}/interrupt/interrupt.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/timer/timer.o: timer/timer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/timer" 
	@${RM} ${OBJECTDIR}/timer/timer.o.d 
	@${RM} ${OBJECTDIR}/timer/timer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/timer/timer.o   timer/timer.c 
	@${DEP_GEN} -d ${OBJECTDIR}/timer/timer.o 
	@${FIXDEPS} "${OBJECTDIR}/timer/timer.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/button_matrix/button.o: button_matrix/button.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/button_matrix" 
	@${RM} ${OBJECTDIR}/button_matrix/button.o.d 
	@${RM} ${OBJECTDIR}/button_matrix/button.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/button_matrix/button.o   button_matrix/button.c 
	@${DEP_GEN} -d ${OBJECTDIR}/button_matrix/button.o 
	@${FIXDEPS} "${OBJECTDIR}/button_matrix/button.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/uart/uart.o: uart/uart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/uart" 
	@${RM} ${OBJECTDIR}/uart/uart.o.d 
	@${RM} ${OBJECTDIR}/uart/uart.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/uart/uart.o   uart/uart.c 
	@${DEP_GEN} -d ${OBJECTDIR}/uart/uart.o 
	@${FIXDEPS} "${OBJECTDIR}/uart/uart.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/fsm_door/fsm_door.o: fsm_door/fsm_door.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/fsm_door" 
	@${RM} ${OBJECTDIR}/fsm_door/fsm_door.o.d 
	@${RM} ${OBJECTDIR}/fsm_door/fsm_door.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/fsm_door/fsm_door.o   fsm_door/fsm_door.c 
	@${DEP_GEN} -d ${OBJECTDIR}/fsm_door/fsm_door.o 
	@${FIXDEPS} "${OBJECTDIR}/fsm_door/fsm_door.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/global/global.o: global/global.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/global" 
	@${RM} ${OBJECTDIR}/global/global.o.d 
	@${RM} ${OBJECTDIR}/global/global.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/global/global.o   global/global.c 
	@${DEP_GEN} -d ${OBJECTDIR}/global/global.o 
	@${FIXDEPS} "${OBJECTDIR}/global/global.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/rfid/rfid.o: rfid/rfid.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/rfid" 
	@${RM} ${OBJECTDIR}/rfid/rfid.o.d 
	@${RM} ${OBJECTDIR}/rfid/rfid.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/rfid/rfid.o   rfid/rfid.c 
	@${DEP_GEN} -d ${OBJECTDIR}/rfid/rfid.o 
	@${FIXDEPS} "${OBJECTDIR}/rfid/rfid.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/password/password.o: password/password.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/password" 
	@${RM} ${OBJECTDIR}/password/password.o.d 
	@${RM} ${OBJECTDIR}/password/password.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/password/password.o   password/password.c 
	@${DEP_GEN} -d ${OBJECTDIR}/password/password.o 
	@${FIXDEPS} "${OBJECTDIR}/password/password.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/peripheral/peripheral.o: peripheral/peripheral.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/peripheral" 
	@${RM} ${OBJECTDIR}/peripheral/peripheral.o.d 
	@${RM} ${OBJECTDIR}/peripheral/peripheral.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/peripheral/peripheral.o   peripheral/peripheral.c 
	@${DEP_GEN} -d ${OBJECTDIR}/peripheral/peripheral.o 
	@${FIXDEPS} "${OBJECTDIR}/peripheral/peripheral.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/main/main.o: main/main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/main" 
	@${RM} ${OBJECTDIR}/main/main.o.d 
	@${RM} ${OBJECTDIR}/main/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/main/main.o   main/main.c 
	@${DEP_GEN} -d ${OBJECTDIR}/main/main.o 
	@${FIXDEPS} "${OBJECTDIR}/main/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/SmartDoor.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_LD} $(MP_EXTRA_LD_PRE)   -p$(MP_PROCESSOR_OPTION_LD)  -w -x -u_DEBUG -m"${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map"  -z__MPLAB_BUILD=1  -u_CRUNTIME -z__MPLAB_DEBUG=1 -z__MPLAB_DEBUGGER_PICKIT2=1 $(MP_LINKER_DEBUG_OPTION) -l ${MP_CC_DIR}\\..\\lib  -o dist/${CND_CONF}/${IMAGE_TYPE}/SmartDoor.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}   
else
dist/${CND_CONF}/${IMAGE_TYPE}/SmartDoor.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_LD} $(MP_EXTRA_LD_PRE)   -p$(MP_PROCESSOR_OPTION_LD)  -w  -m"${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map"  -z__MPLAB_BUILD=1  -u_CRUNTIME -l ${MP_CC_DIR}\\..\\lib  -o dist/${CND_CONF}/${IMAGE_TYPE}/SmartDoor.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}   
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
