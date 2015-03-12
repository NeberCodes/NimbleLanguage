#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-MacOSX
CND_DLIB_EXT=dylib
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/AssemblyAddress.o \
	${OBJECTDIR}/AssemblyFunction.o \
	${OBJECTDIR}/AssemblyInstruction.o \
	${OBJECTDIR}/AssemblyLibrary.o \
	${OBJECTDIR}/AssemblyStatement.o \
	${OBJECTDIR}/ExpressionNode.o \
	${OBJECTDIR}/ExpressionTree.o \
	${OBJECTDIR}/Nimble.o \
	${OBJECTDIR}/NimbleConverter.o \
	${OBJECTDIR}/NimbleError.o \
	${OBJECTDIR}/NimbleFunction.o \
	${OBJECTDIR}/NimbleLibrary.o \
	${OBJECTDIR}/NimbleSyntax.o \
	${OBJECTDIR}/NimbleTest.o \
	${OBJECTDIR}/ParseBlock.o \
	${OBJECTDIR}/ParseNode.o \
	${OBJECTDIR}/ParseTree.o \
	${OBJECTDIR}/Parser.o \
	${OBJECTDIR}/SyntaxParseBlock.o \
	${OBJECTDIR}/SyntaxParser.o \
	${OBJECTDIR}/SyntaxTree.o \
	${OBJECTDIR}/Variable.o \
	${OBJECTDIR}/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/nimble

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/nimble: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/nimble ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/AssemblyAddress.o: AssemblyAddress.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/AssemblyAddress.o AssemblyAddress.cpp

${OBJECTDIR}/AssemblyFunction.o: AssemblyFunction.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/AssemblyFunction.o AssemblyFunction.cpp

${OBJECTDIR}/AssemblyInstruction.o: AssemblyInstruction.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/AssemblyInstruction.o AssemblyInstruction.cpp

${OBJECTDIR}/AssemblyLibrary.o: AssemblyLibrary.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/AssemblyLibrary.o AssemblyLibrary.cpp

${OBJECTDIR}/AssemblyStatement.o: AssemblyStatement.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/AssemblyStatement.o AssemblyStatement.cpp

${OBJECTDIR}/ExpressionNode.o: ExpressionNode.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ExpressionNode.o ExpressionNode.cpp

${OBJECTDIR}/ExpressionTree.o: ExpressionTree.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ExpressionTree.o ExpressionTree.cpp

${OBJECTDIR}/Nimble.o: Nimble.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Nimble.o Nimble.cpp

${OBJECTDIR}/NimbleConverter.o: NimbleConverter.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/NimbleConverter.o NimbleConverter.cpp

${OBJECTDIR}/NimbleError.o: NimbleError.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/NimbleError.o NimbleError.cpp

${OBJECTDIR}/NimbleFunction.o: NimbleFunction.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/NimbleFunction.o NimbleFunction.cpp

${OBJECTDIR}/NimbleLibrary.o: NimbleLibrary.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/NimbleLibrary.o NimbleLibrary.cpp

${OBJECTDIR}/NimbleSyntax.o: NimbleSyntax.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/NimbleSyntax.o NimbleSyntax.cpp

${OBJECTDIR}/NimbleTest.o: NimbleTest.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/NimbleTest.o NimbleTest.cpp

${OBJECTDIR}/ParseBlock.o: ParseBlock.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ParseBlock.o ParseBlock.cpp

${OBJECTDIR}/ParseNode.o: ParseNode.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ParseNode.o ParseNode.cpp

${OBJECTDIR}/ParseTree.o: ParseTree.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ParseTree.o ParseTree.cpp

${OBJECTDIR}/Parser.o: Parser.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Parser.o Parser.cpp

${OBJECTDIR}/SyntaxParseBlock.o: SyntaxParseBlock.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/SyntaxParseBlock.o SyntaxParseBlock.cpp

${OBJECTDIR}/SyntaxParser.o: SyntaxParser.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/SyntaxParser.o SyntaxParser.cpp

${OBJECTDIR}/SyntaxTree.o: SyntaxTree.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/SyntaxTree.o SyntaxTree.cpp

${OBJECTDIR}/Variable.o: Variable.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Variable.o Variable.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/nimble

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
