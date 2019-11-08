/*
 * Phoenix-RTOS
 *
 * psd - Serial Download Protocol client
 *
 * HID support
 *
 * Copyright 2019 Phoenix Systems
 * Author: Bartosz Ciesla, Pawel Pisarczyk
 *
 * This file is part of Phoenix-RTOS.
 *
 * %LICENSE%
 */

#ifndef _HID_H_
#define _HID_H_

#include <usbclient.h>

enum { hidOK = 0, eReport1, eReport2, eReport3, eReport4, eErase, eControlBlock };


/* String descriptor */
typedef struct _usbclient_desc_str_t {
	uint8_t	len;
	uint8_t	desc_type;
	uint8_t string[256];
} __attribute__((packed)) usbclient_desc_str_t;


typedef struct _hid_dev_conf_t {
	usbclient_desc_dev_t ddev;
	usbclient_desc_str_t dstrman;
	usbclient_desc_str_t dstrprod;
} __attribute__((packed)) hid_dev_setup_t;


extern int hid_init(int (**rf)(int, char *, unsigned int, char **), int (**sf)(int, const char *, unsigned int), const hid_dev_setup_t* dev_setup);


extern void hid_destroy(void);

#endif
