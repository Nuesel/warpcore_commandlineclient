##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=client
ConfigurationName      :=Debug
WorkspacePath          := "/home/daniel/warpkern2"
ProjectPath            := "/home/daniel/warpkern2/client"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=root
Date                   :=08/09/17
CodeLitePath           :="/root/.codelite"
LinkerName             :=g++
SharedObjectLinkerName :=g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.o.i
DebugSwitch            :=-gstab
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
ObjectsFileList        :="client.txt"
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
AR       := ar rcus
CXX      := g++
CC       := gcc
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/commandline.cpp$(ObjectSuffix) $(IntermediateDirectory)/jsoncpp.cpp$(ObjectSuffix) 



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
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/daniel/warpkern2/client/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM "main.cpp"

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) "main.cpp"

$(IntermediateDirectory)/commandline.cpp$(ObjectSuffix): commandline.cpp $(IntermediateDirectory)/commandline.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/daniel/warpkern2/client/commandline.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/commandline.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/commandline.cpp$(DependSuffix): commandline.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/commandline.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/commandline.cpp$(DependSuffix) -MM "commandline.cpp"

$(IntermediateDirectory)/commandline.cpp$(PreprocessSuffix): commandline.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/commandline.cpp$(PreprocessSuffix) "commandline.cpp"

$(IntermediateDirectory)/jsoncpp.cpp$(ObjectSuffix): jsoncpp.cpp $(IntermediateDirectory)/jsoncpp.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/daniel/warpkern2/client/jsoncpp.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/jsoncpp.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/jsoncpp.cpp$(DependSuffix): jsoncpp.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/jsoncpp.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/jsoncpp.cpp$(DependSuffix) -MM "jsoncpp.cpp"

$(IntermediateDirectory)/jsoncpp.cpp$(PreprocessSuffix): jsoncpp.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/jsoncpp.cpp$(PreprocessSuffix) "jsoncpp.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


