#---------
#
# CppUTest Examples Makefile
#
#----------

#Set this to @ to keep the makefile quiet
ifndef SILENCE
	SILENCE = @
endif

#--- Inputs ----#
COMPONENT_NAME = lightschedulerTDD
CPPUTEST_HOME = ~/ext4local/cpputest-3.7.1

CPPUTEST_USE_EXTENSIONS = Y
CPP_PLATFORM = Gcc

# This line is overriding the default new macros.  This is helpful
# when using std library includes like <list> and other containers
# so that memory leak detection does not conflict with stl.
#CPPUTEST_MEMLEAK_DETECTOR_NEW_MACRO_FILE = -include ApplicationLib/ExamplesNewOverrides.h
SRC_DIRS = \
	src

TEST_SRC_DIRS = \
	test

INCLUDE_DIRS =\
  include\
  src\
  $(CPPUTEST_HOME)/include\

include $(CPPUTEST_HOME)/build/MakefileWorker.mk


