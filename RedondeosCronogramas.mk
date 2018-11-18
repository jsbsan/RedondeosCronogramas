##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=RedondeosCronogramas
ConfigurationName      :=Debug
WorkspacePath          := "/home/mint/jsbsanC"
ProjectPath            := "/home/mint/jsbsanC/RedondeosCronogramas"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=mintSSD
Date                   :=18/11/18
CodeLitePath           :="/home/mint/.codelite"
LinkerName             :=/usr/bin/g++
SharedObjectLinkerName :=/usr/bin/g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="RedondeosCronogramas.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++
CC       := /usr/bin/gcc
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/mainTest.c$(ObjectSuffix) $(IntermediateDirectory)/main.c$(ObjectSuffix) $(IntermediateDirectory)/busca.c$(ObjectSuffix) $(IntermediateDirectory)/sumatorio.c$(ObjectSuffix) $(IntermediateDirectory)/FuncionesComprobacion.c$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@test -d ./Debug || $(MakeDirCommand) ./Debug


$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/mainTest.c$(ObjectSuffix): mainTest.c $(IntermediateDirectory)/mainTest.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/mint/jsbsanC/RedondeosCronogramas/mainTest.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/mainTest.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/mainTest.c$(DependSuffix): mainTest.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/mainTest.c$(ObjectSuffix) -MF$(IntermediateDirectory)/mainTest.c$(DependSuffix) -MM "mainTest.c"

$(IntermediateDirectory)/mainTest.c$(PreprocessSuffix): mainTest.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/mainTest.c$(PreprocessSuffix) "mainTest.c"

$(IntermediateDirectory)/main.c$(ObjectSuffix): main.c $(IntermediateDirectory)/main.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/mint/jsbsanC/RedondeosCronogramas/main.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.c$(DependSuffix): main.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.c$(ObjectSuffix) -MF$(IntermediateDirectory)/main.c$(DependSuffix) -MM "main.c"

$(IntermediateDirectory)/main.c$(PreprocessSuffix): main.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.c$(PreprocessSuffix) "main.c"

$(IntermediateDirectory)/busca.c$(ObjectSuffix): busca.c $(IntermediateDirectory)/busca.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/mint/jsbsanC/RedondeosCronogramas/busca.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/busca.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/busca.c$(DependSuffix): busca.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/busca.c$(ObjectSuffix) -MF$(IntermediateDirectory)/busca.c$(DependSuffix) -MM "busca.c"

$(IntermediateDirectory)/busca.c$(PreprocessSuffix): busca.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/busca.c$(PreprocessSuffix) "busca.c"

$(IntermediateDirectory)/sumatorio.c$(ObjectSuffix): sumatorio.c $(IntermediateDirectory)/sumatorio.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/mint/jsbsanC/RedondeosCronogramas/sumatorio.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/sumatorio.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/sumatorio.c$(DependSuffix): sumatorio.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/sumatorio.c$(ObjectSuffix) -MF$(IntermediateDirectory)/sumatorio.c$(DependSuffix) -MM "sumatorio.c"

$(IntermediateDirectory)/sumatorio.c$(PreprocessSuffix): sumatorio.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/sumatorio.c$(PreprocessSuffix) "sumatorio.c"

$(IntermediateDirectory)/FuncionesComprobacion.c$(ObjectSuffix): FuncionesComprobacion.c $(IntermediateDirectory)/FuncionesComprobacion.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/mint/jsbsanC/RedondeosCronogramas/FuncionesComprobacion.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/FuncionesComprobacion.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/FuncionesComprobacion.c$(DependSuffix): FuncionesComprobacion.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/FuncionesComprobacion.c$(ObjectSuffix) -MF$(IntermediateDirectory)/FuncionesComprobacion.c$(DependSuffix) -MM "FuncionesComprobacion.c"

$(IntermediateDirectory)/FuncionesComprobacion.c$(PreprocessSuffix): FuncionesComprobacion.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/FuncionesComprobacion.c$(PreprocessSuffix) "FuncionesComprobacion.c"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


