##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Tanky
ConfigurationName      :=Debug
WorkspacePath          := "/Users/hamidfzm/Library/Application Support/codelite/SDL"
ProjectPath            := "/Users/hamidfzm/Desktop/Tanky"
IntermediateDirectory  :=./bin
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Hamid Feizabadi
Date                   :=2015-04-11
CodeLitePath           :="/Users/hamidfzm/Library/Application Support/codelite"
LinkerName             :=/usr/bin/g++
SharedObjectLinkerName :=/usr/bin/g++ -dynamiclib -fPIC
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
ObjectsFileList        :="Tanky.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch)include 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)SDL2 $(LibrarySwitch)SDL2_image $(LibrarySwitch)SDL2_ttf $(LibrarySwitch)SDL2_mixer 
ArLibs                 :=  "SDL2" "SDL2_image" "SDL2_ttf" "SDL2_mixer" 
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
CodeLiteDir:=/Applications/codelite.app/Contents/SharedSupport/
Objects0=$(IntermediateDirectory)/src_main.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_Game.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_Timer.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_Tank.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_User.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_Enemy.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

$(IntermediateDirectory)/.d:
	@test -d ./bin || $(MakeDirCommand) ./bin

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/src_main.cpp$(ObjectSuffix): src/main.cpp $(IntermediateDirectory)/src_main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/hamidfzm/Desktop/Tanky/src/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_main.cpp$(DependSuffix): src/main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_main.cpp$(DependSuffix) -MM "src/main.cpp"

$(IntermediateDirectory)/src_main.cpp$(PreprocessSuffix): src/main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_main.cpp$(PreprocessSuffix) "src/main.cpp"

$(IntermediateDirectory)/src_Game.cpp$(ObjectSuffix): src/Game.cpp $(IntermediateDirectory)/src_Game.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/hamidfzm/Desktop/Tanky/src/Game.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_Game.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_Game.cpp$(DependSuffix): src/Game.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_Game.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_Game.cpp$(DependSuffix) -MM "src/Game.cpp"

$(IntermediateDirectory)/src_Game.cpp$(PreprocessSuffix): src/Game.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_Game.cpp$(PreprocessSuffix) "src/Game.cpp"

$(IntermediateDirectory)/src_Timer.cpp$(ObjectSuffix): src/Timer.cpp $(IntermediateDirectory)/src_Timer.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/hamidfzm/Desktop/Tanky/src/Timer.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_Timer.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_Timer.cpp$(DependSuffix): src/Timer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_Timer.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_Timer.cpp$(DependSuffix) -MM "src/Timer.cpp"

$(IntermediateDirectory)/src_Timer.cpp$(PreprocessSuffix): src/Timer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_Timer.cpp$(PreprocessSuffix) "src/Timer.cpp"

$(IntermediateDirectory)/src_Tank.cpp$(ObjectSuffix): src/Tank.cpp $(IntermediateDirectory)/src_Tank.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/hamidfzm/Desktop/Tanky/src/Tank.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_Tank.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_Tank.cpp$(DependSuffix): src/Tank.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_Tank.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_Tank.cpp$(DependSuffix) -MM "src/Tank.cpp"

$(IntermediateDirectory)/src_Tank.cpp$(PreprocessSuffix): src/Tank.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_Tank.cpp$(PreprocessSuffix) "src/Tank.cpp"

$(IntermediateDirectory)/src_User.cpp$(ObjectSuffix): src/User.cpp $(IntermediateDirectory)/src_User.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/hamidfzm/Desktop/Tanky/src/User.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_User.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_User.cpp$(DependSuffix): src/User.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_User.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_User.cpp$(DependSuffix) -MM "src/User.cpp"

$(IntermediateDirectory)/src_User.cpp$(PreprocessSuffix): src/User.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_User.cpp$(PreprocessSuffix) "src/User.cpp"

$(IntermediateDirectory)/src_Enemy.cpp$(ObjectSuffix): src/Enemy.cpp $(IntermediateDirectory)/src_Enemy.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/hamidfzm/Desktop/Tanky/src/Enemy.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_Enemy.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_Enemy.cpp$(DependSuffix): src/Enemy.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_Enemy.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_Enemy.cpp$(DependSuffix) -MM "src/Enemy.cpp"

$(IntermediateDirectory)/src_Enemy.cpp$(PreprocessSuffix): src/Enemy.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_Enemy.cpp$(PreprocessSuffix) "src/Enemy.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./bin/


