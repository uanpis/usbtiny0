// ======================================================================
// Common definitions for the USB driver
//
// Copyright 2006-2010 Dick Streefland
//
// This is free software, licensed under the terms of the GNU General
// Public License as published by the Free Software Foundation.
// ======================================================================

#ifdef __ASSEMBLER__
#define	__SFR_OFFSET		0
#endif
#include <avr/io.h>
#include "usbtiny.h"

// Preprocessor magic
#define	CAT2(a,b)		CAT2EXP(a, b)
#define	CAT2EXP(a,b)		a ## b
#define	CAT3(a,b,c)		CAT3EXP(a, b, c)
#define	CAT3EXP(a,b,c)		a ## b ## c
#define	CAT4(a,b,c,d)		CAT4EXP(a, b, c, d)
#define	CAT4EXP(a,b,c,d)	a ## b ## c ## d
#define	CAT5(a,b,c,d,e)		CAT5EXP(a, b, c, d, e)
#define	CAT5EXP(a,b,c,d,e)	a ## b ## c ## d ## e

// I/O Ports for USB
#define	USB_IN			CAT3(VPORT, USBTINY_PORT, _IN)
#define	USB_OUT			CAT3(VPORT, USBTINY_PORT, _OUT)
#define	USB_DDR			CAT3(VPORT, USBTINY_PORT, _DIR)

// I/O bit masks for USB
#define	USB_MASK_DMINUS		(1 << (USBTINY_DMINUS))
#define	USB_MASK_DPLUS		(1 << (USBTINY_DPLUS))
#define	USB_MASK		(USB_MASK_DMINUS | USB_MASK_DPLUS)

// Interrupt configuration
#define USB_INT_CONFIG		CAT5(PORT, USBTINY_PORT, _PIN, USBTINY_DPLUS, CTRL)
#define	USB_INT_CONFIG_SET	PORT_ISC_RISING_gc
#define USB_INT_VECTOR		CAT3(PORT, USBTINY_PORT, _PORT_vect)

// Interrupt pending bit
#define	USB_INT_PENDING		CAT3(VPORT, USBTINY_PORT, _INTFLAGS)
#define	USB_INT_PENDING_BIT	CAT3(VPORT_INT, USBTINY_DPLUS, _bp)

// USB PID values
#define	USB_PID_SETUP		0x2d
#define	USB_PID_OUT		0xe1
#define	USB_PID_IN		0x69
#define	USB_PID_DATA0		0xc3
#define	USB_PID_DATA1		0x4b
#define	USB_PID_ACK		0xd2
#define	USB_PID_NAK		0x5a
#define	USB_PID_STALL		0x1e

// Various constants
#define	USB_BUFSIZE		11	// PID + data + CRC

// Bit manipulation macros
//#define	BIT_CLR(reg,bit)	{ (reg.OUTCLR) = _BV(bit); }
//#define	BIT_SET(reg,bit)	{ (reg.OUTSET) = _BV(bit); }
//#define	BIT_TST(reg,bit)	(((reg.IN) & _BV(bit)) != 0)

// I/O port manipulation macros
#define	DDR_CLR(p,b)		{ (PORT ## p).DIRCLR = _BV(b); }
#define	DDR_SET(p,b)		{ (PORT ## p).DIRSET = _BV(b); }
#define	PORT_CLR(p,b)		{ (PORT ## p).OUTCLR = _BV(b); }
#define	PORT_SET(p,b)		{ (PORT ## p).OUTSET = _BV(b); }
//#define	PORT_TST(p,b)		BIT_TST(PORT ## p, b)
//#define	PIN_TST(p,b)		BIT_TST(PIN  ## p, b)
//#define	PIN_SET(p,b)		BIT_SET(PIN  ## p, b)

// Macros that can be used with an argument of the form (port,bit)
#define	INPUT(bit)		DDR_CLR bit
#define	OUTPUT(bit)		DDR_SET bit
#define	CLR(bit)		PORT_CLR bit
#define	SET(bit)		PORT_SET bit
#define	ISSET(bit)		PORT_TST bit
#define	TST(bit)		PIN_TST bit
#define	TOGGLE(bit)		PIN_SET bit
