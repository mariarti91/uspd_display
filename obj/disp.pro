QT += core
QT -= gui

TEMPLATE = app

OBJECTS_DIR = ../obj
DESTDIR = ../
TARGET = disp.bin

SOURCES = ../src/main.cpp\
	  ../src/UspdPin.cpp\
	  ../src/MyDisplay.cpp

HEADERS = ../src/UspdPin.h\
	  ../src/MyDisplay.h
