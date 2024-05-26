# ======================================================================
# Makefile for USBtinyISP AVR programmer
#
# Copyright 2006-2010 Dick Streefland
#
# This is free software, licensed under the terms of the GNU General
# Public License as published by the Free Software Foundation.
# ======================================================================

USBTINY		= ../usbtiny
TARGET_ARCH	= -mmcu=attiny404
OBJECTS		= main.o
FLASH_CMD	= avrdude -pt404 -c serialupdi -P /dev/ttyUSB0 -b 100000 -U flash:w:main.elf:e
FUSES_CMD	= avrdude -pt404 -c serialupdi -P /dev/ttyUSB0 -b 100000 -U hfuse:w:0xdf:m -U lfuse:w:0xef:m
STACK		= 32
FLASH		= 2048
SRAM		= 128
SCHEM		= 

include $(USBTINY)/common.mk
