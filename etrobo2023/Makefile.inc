mkfile_path := $(dir $(lastword $(MAKEFILE_LIST)))

APPL_COBJS +=

APPL_CXXOBJS += \
util.o \
Process.o \
ProcessSetup.o \
Scene.o \
DivergentScene.o \
Env.o \
Device.o \
Action.o \
WheelAction.o \
LineTraceAction.o \
ArmAction.o \
Monitor.o \
ArmMonitor.o \
DistanceMonitor.o \
AngleMonitor.o \
BlackLineMonitor.o \
BlueLineMonitor.o \
RedLineMonitor.o \
RedBlockMonitor.o \
GreenLineMonitor.o \
YellowLineMonitor.o
SRCLANG := c++

ifdef CONFIG_EV3RT_APPLICATION

# Include libraries
include $(EV3RT_SDK_LIB_DIR)/libcpp-ev3/Makefile

endif

APPL_DIRS += $(mkfile_path)action $(mkfile_path)env $(mkfile_path)strategy $(mkfile_path)monitor

INCLUDES += \
	-I$(mkfile_path)action \
	-I$(mkfile_path)env \
	-I$(mkfile_path)monitor \
	-I$(mkfile_path)strategy \

#COPTS += -fno-use-cxa-atexit
