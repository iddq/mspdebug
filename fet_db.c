/* MSPDebug - debugging tool for MSP430 MCUs
 * Copyright (C) 2009, 2010 Daniel Beer
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include <string.h>
#include "fet_db.h"
#include "util.h"

static const struct fet_db_record fet_db[] = {
	{
		.name = "MSP430F47197",
		.msg28_data = {
			0xf4, 0x7f, 0x00, 0x30, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x02, 0x13, 0x01, 0x07, 0xf7, 0x5b, 
			0x80, 0x00
			/* extra bytes: 89 00 00 00 00 00 00 00 */
		},
		.msg29_params = {0x00, 0x8b, 0x83},
		.msg29_data = {
			0x00, 0x21, 0xff, 0xff, 0x01, 0x00, 0x00, 0x10,
			0xff, 0x10, 0x40, 0x00, 0x00, 0x11, 0xff, 0x20,
			0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x07, 0x00,
			0x02, 0x00, 0x1f, 0x04, 0x00, 0x00, 0x00, 0x00,
			0x08, 0x07, 0x10, 0x0e, 0xc4, 0x09, 0x70, 0x17,
			0x58, 0x1b, 0x01, 0x00, 0x03, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x01, 0x00,
			0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
			0xff, 0xff
		},
		.msg2b_len = 0x4a,
		.msg2b_data = {
			0x00, 0x10, 0xff, 0x17, 0x00, 0x02, 0x02, 0x00,
			0x0a, 0x00, 0x20, 0x00, 0x0a, 0x91, 0x8e, 0x8f,
			0x9d, 0x40, 0x28, 0x29, 0x2a, 0x2b, 0x8a, 0xd8,
			0xa8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1c,
			0xff, 0x23, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00,
			0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00,
			0x01, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00
		}
	},
	{
		.name = "MSP430F147",
		.msg28_data = {
			0xf1, 0x49, 0x00, 0x43, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x01, 0x10, 0x00, 0x00, 0xf0, 0x1a,
			0x12, 0x00
		},
		.msg29_params = {0x00, 0x05, 0x05},
		.msg29_data = {
			0x00, 0x80, 0xff, 0xff, 0x00, 0x00, 0x00, 0x10,
			0xff, 0x10, 0x80, 0x00, 0x00, 0x02, 0xff, 0x05,
			0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x02, 0x00,
			0x00, 0x00, 0xd7, 0x60, 0x00, 0x00, 0x00, 0x00,
			0x08, 0x07, 0x10, 0x0e, 0xc4, 0x09, 0x70, 0x17,
			0x58, 0x1b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0xf3, 0x30, 0xd3, 0x30,
			0xc0, 0x30,
		},
		.msg2b_len = 0x4a,
		.msg2b_data = {
			0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00,
		},
	},
	{
		.name = "MSP430F148",
		.msg28_data = {
			0xf1, 0x49, 0x00, 0x60, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x01, 0x10, 0x00, 0x00, 0xf0, 0x39,
			0x11, 0x00
		},
		.msg29_params = {0x00, 0x06, 0x06},
		.msg29_data = {
			0x00, 0x40, 0xff, 0xff, 0x00, 0x00, 0x00, 0x10,
			0xff, 0x10, 0x80, 0x00, 0x00, 0x02, 0xff, 0x09,
			0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x02, 0x00,
			0x00, 0x00, 0xd7, 0x60, 0x00, 0x00, 0x00, 0x00,
			0x08, 0x07, 0x10, 0x0e, 0xc4, 0x09, 0x70, 0x17,
			0x58, 0x1b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0xf3, 0x30, 0xd3, 0x30,
			0xc0, 0x30
		},
		.msg2b_len = 0x4a,
		.msg2b_data = {
			0x00, 0x0c, 0xff, 0x0f, 0x00, 0x02, 0x00, 0x00,
			0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00,
		}
	},
	{
		.name = "MSP430F149",
		.msg28_data = {
			0xF1, 0x49, 0x00, 0x43, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x01, 0x10, 0x00, 0x00, 0xF0, 0x1A,
			0x10, 0x00
		},
		.msg29_params = {0x00, 0x07, 0x07},
		.msg29_data = {
			0x00, 0x11, 0xff, 0xff, 0x00, 0x00, 0x00, 0x10,
			0xff, 0x10, 0x80, 0x00, 0x00, 0x02, 0xff, 0x09,
			0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x02, 0x00,
			0x00, 0x00, 0xd7, 0x60, 0x00, 0x00, 0x00, 0x00,
			0x08, 0x07, 0x10, 0x0e, 0xc4, 0x09, 0x70, 0x17,
			0x58, 0x1b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0xf3, 0x30, 0xd3, 0x30,
			0xc0, 0x30
		},
		.msg2b_len = 0x4a,
		.msg2b_data = {
			0x00, 0x0c, 0xff, 0x0f, 0x00, 0x02, 0x00, 0x00,
			0x03, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00
		},
	},
	{ /* copied from MSP430F1611 */
		.name = "MSP430F1612",
		.msg28_data = {
			0xf1, 0x6c, 0x20, 0x40, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x01, 0x61, 0x01, 0x00, 0xd1, 0x4d,
			0x86, 0x00
			/* extra: 89 00 00 00 00 00 00 00 */
		},
		.msg29_params = {0x00, 0x2a, 0x23},
		.msg29_data = {
			0x00, 0x25, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x10,
			0xFF, 0x10, 0x80, 0x00, 0x00, 0x02, 0xFF, 0x09,
			0x00, 0x11, 0xFF, 0x24, 0x08, 0x00, 0x03, 0x00,
			0x02, 0x00, 0xD7, 0x60, 0x00, 0x00, 0x00, 0x00,
			0x08, 0x07, 0x10, 0x0E, 0xC4, 0x09, 0x70, 0x17,
			0x58, 0x1B, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0xF3, 0x30, 0xD3, 0x30,
			0xC0, 0x30
		},
		.msg2b_len = 0x4a,
		.msg2b_data = {
			0x00, 0x0C, 0xFF, 0x0F, 0x00, 0x02, 0x02, 0x00,
			0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00
		}
	},
	{
		.name = "MSP430F1611",
		.msg28_data = {
			0xF1, 0x6C, 0x20, 0x40, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x01, 0x61, 0x01, 0x00, 0xD1, 0x4D,
			0x80, 0x00
		},
		.msg29_params = {0x00, 0x2a, 0x23},
		.msg29_data = {
			0x00, 0x40, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x10,
			0xFF, 0x10, 0x80, 0x00, 0x00, 0x02, 0xFF, 0x09,
			0x00, 0x11, 0xFF, 0x38, 0x08, 0x00, 0x03, 0x00,
			0x02, 0x00, 0xD7, 0x60, 0x00, 0x00, 0x00, 0x00,
			0x08, 0x07, 0x10, 0x0E, 0xC4, 0x09, 0x70, 0x17,
			0x58, 0x1B, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0xF3, 0x30, 0xD3, 0x30,
			0xC0, 0x30
		},
		.msg2b_len = 0x4a,
		.msg2b_data = {
			0x00, 0x0C, 0xFF, 0x0F, 0x00, 0x02, 0x02, 0x00,
			0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00
		}
	},
	{
		.name = "MSP430F2132",
		.msg28_data = {
			0xf2, 0x13, 0x01, 0x60, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x02, 0x02, 0x01, 0x02, 0xf0, 0x73,
			0x80, 0x00
		},
		.msg29_params = {0x00, 0x58, 0x50}, /* From snoopy logs */
		.msg29_data = {
			 0x00, 0xe0, 0xff, 0xff, 0x00, 0x00, 0x00, 0x10,
			 0xff, 0x10, 0x40, 0x00, 0x00, 0x02, 0xff, 0x03,
			 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x01, 0x00,
			 0x01, 0x00, 0xd7, 0x60, 0x00, 0x00, 0x00, 0x00,
			 0x08, 0x07, 0x10, 0x0e, 0xc4, 0x09, 0x70, 0x17,
			 0x58, 0x1b, 0x01, 0x00, 0x03, 0x00, 0x00, 0x00,
			 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00,
			 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			 0x00, 0x00, 0x00, 0x00, 0x33, 0x0f, 0x1f, 0x0f,
			 0xff, 0xff
		 },
		.msg2b_len = 0x4a,
		.msg2b_data = {
			 0x00, 0x0c, 0xff, 0x0f, 0x00, 0x02, 0x00, 0x00,
			 0x02, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00,
			 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
			 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			 0x00, 0x00
		 }
	},
	{
		.name = "MSP430F249",
		.msg28_data = {
			0xF2, 0x49, 0x02, 0x60, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x02, 0x02, 0x01, 0x00, 0xF3, 0x2B,
			0x80, 0x00
		},
		.msg29_params = {0x00, 0x4f, 0x47},
		.msg29_data = {
			0x00, 0x11, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x10,
			0xFF, 0x10, 0x40, 0x00, 0x00, 0x02, 0xFF, 0x09,
			0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x02, 0x00,
			0x02, 0x00, 0xD7, 0x60, 0x00, 0x00, 0x00, 0x00,
			0x08, 0x07, 0x10, 0x0E, 0xC4, 0x09, 0x70, 0x17,
			0x58, 0x1B, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00,
			0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x33, 0x0F, 0x1F, 0x0F,
			0xFF, 0xFF
		},
		.msg2b_len = 0x4a,
		.msg2b_data = {
			0x00, 0x0C, 0xFF, 0x0F, 0x00, 0x02, 0x00, 0x00,
			0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00
		}
	},
	{ /* Copied from MSP430F249 */
		.name = "MSP430F247",
		.msg28_data = {
			0xf2, 0x49, 0x03, 0x60, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x02, 0x02, 0x01, 0x00, 0xf2, 0x2b,
			0x82, 0x00
			/* extra: 89 00 00 00 00 00 00 00 */
		},
		.msg29_params = {0x00, 0x4f, 0x47},
		.msg29_data = {
			0x00, 0x80, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x10,
			0xFF, 0x10, 0x40, 0x00, 0x00, 0x02, 0xFF, 0x09,
			0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x02, 0x00,
			0x02, 0x00, 0xD7, 0x60, 0x00, 0x00, 0x00, 0x00,
			0x08, 0x07, 0x10, 0x0E, 0xC4, 0x09, 0x70, 0x17,
			0x58, 0x1B, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00,
			0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x33, 0x0F, 0x1F, 0x0F,
			0xFF, 0xFF
		},
		.msg2b_len = 0x4a,
		.msg2b_data = {
			0x00, 0x0C, 0xFF, 0x0F, 0x00, 0x02, 0x00, 0x00,
			0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00
		}
	},
	{
		.name = "MSP430F2616",
		.msg28_data = {
			0xf2, 0x6f, 0x04, 0x60, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x02, 0x12, 0x01, 0x00, 0xf5, 0x1d,
			0x88, 0x00
		},
		.msg29_params = {0x00, 0x41, 0x39},
		.msg29_data = {
			0x00, 0x21, 0xff, 0xff, 0x01, 0x00, 0x00, 0x10,
			0xff, 0x10, 0x40, 0x00, 0x00, 0x02, 0xff, 0x09,
			0x00, 0x11, 0xff, 0x20, 0x08, 0x00, 0x03, 0x00,
			0x02, 0x00, 0xd7, 0x60, 0x00, 0x00, 0x00, 0x00,
			0x08, 0x07, 0x10, 0x0e, 0xc4, 0x09, 0x70, 0x17,
			0x58, 0x1b, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x01, 0x00,
			0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x33, 0x0f, 0x1f, 0x0f,
			0xff, 0xff
		},
		.msg2b_len = 0x4a,
		.msg2b_data = {
			0x00, 0x0c, 0xff, 0x0f, 0x00, 0x02, 0x02, 0x00,
			0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00
		}
	},
	{ /* copied from MSP430F2616, with modifications */
		.name = "MSP430F2618",
		.msg28_data = {
			0xf2, 0x6f, 0x05, 0x60, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x02, 0x13, 0x01, 0x00, 0xf4, 0x1c,
			0x89, 0x00
			/* extra: 89 00 00 00 00 00 00 00 */
		},
		.msg29_params = {0x00, 0x41, 0x39},
		.msg29_data = {
			0x00, 0x31, 0xff, 0xff, 0x01, 0x00, 0x00, 0x10,
			0xff, 0x10, 0x40, 0x00, 0x00, 0x11, 0xff, 0x30,
			0x00, 0x11, 0xff, 0x20, 0x08, 0x00, 0x03, 0x00,
			0x02, 0x00, 0xd7, 0x60, 0x00, 0x00, 0x00, 0x00,
			0x08, 0x07, 0x10, 0x0e, 0xc4, 0x09, 0x70, 0x17,
			0x58, 0x1b, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x01, 0x00,
			0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x33, 0x0f, 0x1f, 0x0f,
			0xff, 0xff
		},
		.msg2b_len = 0x4a,
		.msg2b_data = {
			0x00, 0x0c, 0xff, 0x0f, 0x00, 0x02, 0x02, 0x00,
			0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00
		}
	},
	{
		.name = "MSP430F5437A",
		.msg28_data = {
			0x04, 0x80, 0x11, 0x11, 0x08, 0x0a, 0x26, 0x87,
			0xb4, 0x46, 0x18, 0x0c, 0xec, 0x0f, 0xf8, 0xfe,
			0x30, 0x41
		},
		.msg29_params = {0x00, 0x5c, 0x54},
		.msg29_data = {
			0x00, 0x5c, 0xff, 0x5b, 0x04, 0x00, 0x00, 0x18,
			0xff, 0x19, 0x80, 0x00, 0x00, 0x1c, 0xff, 0x5b,
			0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x03, 0x00,
			0x02, 0x00, 0x0f, 0x04, 0x00, 0x00, 0x00, 0x00,
			0x08, 0x07, 0x10, 0x0e, 0xc4, 0x09, 0x70, 0x17,
			0x58, 0x1b, 0x01, 0x00, 0x03, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x01, 0x00,
			0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
			0xff, 0xff
		},
		.msg2b_len = 0x4a,
		.msg2b_data = {
			0x00, 0x10, 0xff, 0x17, 0x00, 0x02, 0x02, 0x00,
			0x0a, 0x00, 0x40, 0x00, 0x0a, 0x91, 0x8e, 0x9d,
			0x00, 0x00, 0x28, 0x29, 0x2a, 0x2b, 0x80, 0xd8,
			0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00
		},
	},
	{ /* From sniffusb log of CCS */
		.name = "MSP430F5438",
		.msg28_data = {
			0x54, 0x38, 0x10, 0x10, 0x08, 0x0a, 0x28, 0x7e,
			0xc9, 0x47, 0x1d, 0x00, 0x26, 0x00, 0xf8, 0xfe,
			0xff, 0x3f
			/* extra bytes: 91 00 01 00 1a 00 00 05 */
		},
		.msg29_params = {0x00, 0x5c, 0x54},
		.msg29_data = {
			0x00, 0x5c, 0xff, 0x5b, 0x04, 0x00, 0x00, 0x18,
			0xff, 0x19, 0x80, 0x00, 0x00, 0x1c, 0xff, 0x5b,
			0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x07, 0x00,
			0x02, 0x00, 0x0f, 0x04, 0x00, 0x00, 0x00, 0x00,
			0x08, 0x07, 0x10, 0x0e, 0xc4, 0x09, 0x70, 0x17,
			0x58, 0x1b, 0x01, 0x00, 0x03, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x01, 0x00,
			0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
			0xff, 0xff
		},
		.msg2b_len = 0x4a,
		.msg2b_data = {
			0x00, 0x10, 0xff, 0x17, 0x00, 0x02, 0x02, 0x00,
			0x0a, 0x00, 0x40, 0x00, 0x0a, 0x91, 0x8e, 0x9d,
			0x00, 0x00, 0x28, 0x29, 0x2a, 0x2b, 0x8a, 0xd8,
			0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x01,
			0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01,
			0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00
		}
	},
	{
		.name = "MSP430F5529",
		.msg28_data = {
			0x55, 0x29, 0x10, 0x10, 0x08, 0x0a, 0x68, 0xd9,
			0xb4, 0x46, 0x18, 0x00, 0x11, 0x00, 0xf8, 0xfe,
			0x00, 0x00
			/* extra bytes: 91 03 01 00 1a 00 04 05 */
		},
		.msg29_params = {0x00, 0x8b, 0x83},
		.msg29_data = {
			0x00, 0x44, 0xff, 0x43, 0x02, 0x00, 0x00, 0x18,
			0xff, 0x19, 0x80, 0x00, 0x00, 0x1c, 0xff, 0x43,
			0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x07, 0x00,
			0x02, 0x00, 0x1f, 0x04, 0x00, 0x00, 0x00, 0x00,
			0x08, 0x07, 0x10, 0x0e, 0xc4, 0x09, 0x70, 0x17,
			0x58, 0x1b, 0x01, 0x00, 0x03, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x01, 0x00,
			0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
			0xff, 0xff
		},
		.msg2b_len = 0x4a,
		.msg2b_data = {
			0x00, 0x10, 0xff, 0x17, 0x00, 0x02, 0x02, 0x00,
			0x0a, 0x00, 0x20, 0x00, 0x0a, 0x91, 0x8e, 0x8f,
			0x9d, 0x40, 0x28, 0x29, 0x2a, 0x2b, 0x8a, 0xd8,
			0xa8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1c,
			0xff, 0x23, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00,
			0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00,
			0x01, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00
		}
	},
	{
		.name = "CC430F6137",
		.msg28_data = {
			0x61, 0x37, 0x10, 0x10, 0x08, 0x0a, 0xff, 0xff,
			0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
			0x77, 0x7d
		},
		.msg29_params = {0x77, 0x6f, 0x4a},
		.msg29_data = {
			0x00, 0x80, 0xff, 0xff, 0x00, 0x00, 0x00, 0x18,
			0xff, 0x19, 0x80, 0x00, 0x00, 0x1c, 0xff, 0x2b,
			0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x02, 0x00,
			0x02, 0x00, 0x07, 0x24, 0x00, 0x00, 0x00, 0x00,
			0x08, 0x07, 0x10, 0x0e, 0xc4, 0x09, 0x70, 0x17,
			0x58, 0x1b, 0x01, 0x00, 0x03, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x01, 0x00,
			0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
			0xff, 0xff
		},
		.msg2b_len = 0x4a,
		.msg2b_data = {
			0x00, 0x10, 0xff, 0x17, 0x00, 0x02, 0x01, 0x00,
			0x04, 0x00, 0x40, 0x00, 0x0a, 0x91, 0x8e, 0x00,
			0x00, 0xb0, 0x28, 0x29, 0x2a, 0x2b, 0x80, 0xd8,
			0xa8, 0x60, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00
		}
	},
	{ /* Copied from CC430F6137, with different ID information */
		.name = "CC430F5137",
		.msg28_data = {
			0x51, 0x37, 0x10, 0x10, 0x08, 0x0a, 0xe9, 0x00,
			0xb0, 0x46, 0x1f, 0x00, 0x1f, 0x00, 0xf8, 0xfe,
			0x00, 0x00
			/* extra: 91 01 11 00 1a 00 04 05 */
		},
		.msg29_params = {0x77, 0x6f, 0x4a},
		.msg29_data = {
			0x00, 0x80, 0xff, 0xff, 0x00, 0x00, 0x00, 0x18,
			0xff, 0x19, 0x80, 0x00, 0x00, 0x1c, 0xff, 0x2b,
			0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x02, 0x00,
			0x02, 0x00, 0x07, 0x24, 0x00, 0x00, 0x00, 0x00,
			0x08, 0x07, 0x10, 0x0e, 0xc4, 0x09, 0x70, 0x17,
			0x58, 0x1b, 0x01, 0x00, 0x03, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x01, 0x00,
			0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
			0xff, 0xff
		},
		.msg2b_len = 0x4a,
		.msg2b_data = {
			0x00, 0x10, 0xff, 0x17, 0x00, 0x02, 0x01, 0x00,
			0x04, 0x00, 0x40, 0x00, 0x0a, 0x91, 0x8e, 0x00,
			0x00, 0xb0, 0x28, 0x29, 0x2a, 0x2b, 0x80, 0xd8,
			0xa8, 0x60, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00
		}
	},
	{
		.name = "MSP430F2274",
		.msg28_data = {
			0xf2, 0x27, 0x40, 0x40, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x02, 0x01, 0x01, 0x04, 0xb1, 0x62,
			0x80, 0x00
		},
		.msg29_params = {0x00, 0x39, 0x31},
		.msg29_data = {
			0x00, 0x80, 0xff, 0xff, 0x00, 0x00, 0x00, 0x10,
			0xff, 0x10, 0x40, 0x00, 0x00, 0x02, 0xff, 0x05,
			0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x01, 0x00,
			0x01, 0x00, 0xd7, 0x60, 0x00, 0x00, 0x00, 0x00,
			0x08, 0x07, 0x10, 0x0e, 0xc4, 0x09, 0x70, 0x17,
			0x58, 0x1b, 0x01, 0x00, 0x03, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00,
			0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x33, 0x0f, 0x1f, 0x0f,
			0xff, 0xff
		},
		.msg2b_len = 0x4a,
		.msg2b_data = { /* Copied from MSP430F2616 */
			0x00, 0x0c, 0xff, 0x0f, 0x00, 0x02, 0x02, 0x00,
			0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00
		}
	},
	{ /* Copied from MSP430F2274, with changes */
		.name = "MSP430F2370",
		.msg28_data = {
			0xf2, 0x37, 0x10, 0x60, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x02, 0x01, 0x01, 0x00, 0xe1, 0x56,
			0x80, 0x00
			/* extra: 89 00 00 00 00 00 00 00 */
		},
		.msg29_params = {0x00, 0x39, 0x31},
		.msg29_data = {
			0x00, 0x80, 0xff, 0xff, 0x00, 0x00, 0x00, 0x10,
			0xff, 0x10, 0x40, 0x00, 0x00, 0x02, 0xff, 0x09,
			0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x01, 0x00,
			0x01, 0x00, 0xd7, 0x60, 0x00, 0x00, 0x00, 0x00,
			0x08, 0x07, 0x10, 0x0e, 0xc4, 0x09, 0x70, 0x17,
			0x58, 0x1b, 0x01, 0x00, 0x03, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00,
			0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x33, 0x0f, 0x1f, 0x0f,
			0xff, 0xff
		},
		.msg2b_len = 0x4a,
		.msg2b_data = { /* Copied from MSP430F2616 */
			0x00, 0x0c, 0xff, 0x0f, 0x00, 0x02, 0x02, 0x00,
			0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00
		}
	},
	{
		.name = "MSP430F2013",
		.msg28_data = {
			0xf2, 0x01, 0x10, 0x40, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x00, 0x00,
			0x00, 0x00
		},
		.msg29_params = {0x00, 0x39, 0x31},
		.msg29_data = { /* Copied from MSP430F2274, with changes */
			0x00, 0xf8, 0xff, 0xff, 0x00, 0x00, 0x00, 0x10,
			0xff, 0x10, 0x40, 0x00, 0x00, 0x02, 0x7f, 0x02,
			0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x01, 0x00,
			0x01, 0x00, 0xd7, 0x60, 0x00, 0x00, 0x00, 0x00,
			0x08, 0x07, 0x10, 0x0e, 0xc4, 0x09, 0x70, 0x17,
			0x58, 0x1b, 0x01, 0x00, 0x03, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00,
			0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x33, 0x0f, 0x1f, 0x0f,
			0xff, 0xff
		},
		.msg2b_len = 0x4a,
		.msg2b_data = { /* Copied from MSP430F2616 */
			0x00, 0x0c, 0xff, 0x0f, 0x00, 0x02, 0x02, 0x00,
			0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00
		}
	},
	{
		.name = "MSP430F5438A",
		.msg28_data = {
			0x05, 0x80, 0x11, 0x11, 0x08, 0x0a, 0x85, 0x0f,
			0xb0, 0x46, 0x20, 0x00, 0x0c, 0x00, 0xf8, 0xfe,
			0x00, 0x00
			/* extra bytes: 0x91, 0x03, 0x01, 0x00,
			 *              0x1a, 0x00, 0x04, 0x05
			 */
		},
		.msg29_params = {0x00, 0x8c, 0x84},
		.msg29_data = {
			0x00, 0x5c, 0xff, 0x5b, 0x04, 0x00, 0x00, 0x18,
			0xff, 0x19, 0x80, 0x00, 0x00, 0x1c, 0xff, 0x5b,
			0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x07, 0x00,
			0x02, 0x00, 0x0f, 0x04, 0x00, 0x00, 0x00, 0x00,
			0x08, 0x07, 0x10, 0x0e, 0xc4, 0x09, 0x70, 0x17,
			0x58, 0x1b, 0x01, 0x00, 0x03, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x01, 0x00,
			0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
			0xff, 0xff
		},
		.msg2b_len = 0x4a,
		.msg2b_data = {
			0x00, 0x10, 0xff, 0x17, 0x00, 0x02, 0x02, 0x00,
			0x0a, 0x00, 0x40, 0x00, 0x0a, 0x91, 0x8e, 0x9d,
			0x00, 0x00, 0x28, 0x29, 0x2a, 0x2b, 0x8a, 0xd8,
			0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00,
			0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00,
			0x01, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00
		}
	},
	{ /* Captured using sniffusb 2.0 (IAR) */
		.name = "MSP430F5437",
		.msg28_data = {
			0x54, 0x37, 0x10, 0x10, 0x08, 0x0a, 0x15, 0xae,
			0x83, 0x46, 0x2d, 0x00, 0x16, 0x00, 0xf8, 0xfe,
			0x00, 0x00
			/* extra bytes: 91 00 01 00 1a 00 00 05 */
		},
		.msg29_params = {0x00, 0x61, 0x59},
		.msg29_data = {
			0x00, 0x5c, 0xff, 0x5b, 0x04, 0x00, 0x00, 0x18,
			0xff, 0x19, 0x80, 0x00, 0x00, 0x1c, 0xff, 0x5b,
			0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x07, 0x00,
			0x02, 0x00, 0x0f, 0x04, 0x00, 0x00, 0x00, 0x00,
			0x08, 0x07, 0x10, 0x0e, 0xc4, 0x09, 0x70, 0x17,
			0x58, 0x1b, 0x01, 0x00, 0x03, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x01, 0x00,
			0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
			0xff, 0xff
		},
		.msg2b_len = 0x4a,
		.msg2b_data = {
			0x00, 0x10, 0xff, 0x17, 0x00, 0x02, 0x02, 0x00,
			0x0a, 0x00, 0x40, 0x00, 0x0a, 0x91, 0x8e, 0x9d,
			0x00, 0x00, 0x28, 0x29, 0x2a, 0x2b, 0x8a, 0xd8,
			0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x01,
			0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01,
			0x00, 0x02, 0x00, 0x01, 0x00, 0x01, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00
		}
	},
	{
		.name = "MSP430F169",
		.msg28_data = {
			0xF1, 0x69, 0x40, 0x60, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x01, 0x61, 0x01, 0x00, 0xb1, 0x68,
			0x10, 0x00
		},
		.msg29_params = {0x00, 0x28, 0x21},
		.msg29_data = {
			0x00, 0x11, 0xff, 0xff, 0x00, 0x00, 0x00, 0x10,
			0xff, 0x10, 0x80, 0x00, 0x00, 0x02, 0xff, 0x09,
			0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x03, 0x00,
			0x02, 0x00, 0xd7, 0x60, 0x00, 0x00, 0x00, 0x00,
			0x08, 0x07, 0x10, 0x0e, 0xc4, 0x09, 0x70, 0x17,
			0x58, 0x1b, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0xf3, 0x30, 0xd3, 0x30,
			0xc0, 0x30
		},
		.msg2b_len = 0x34,
		.msg2b_data = {
			0x00, 0x0c, 0xff, 0x0f, 0x00, 0x02, 0x02, 0x00,
			0x08, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00,
			0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x01, 0x00
		},
	},
	{ /* Based on MSP430F2274 */
                .name = "MSP430F2234",
                .msg28_data = {
			0xf2, 0x27, 0x50, 0x40, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x02, 0x02, 0x01, 0x04, 0xa1, 0x61,
			0x82, 0x00
			/* extra bytes: 89 00 00 00 00 00 00 00 */
                },
                .msg29_params = {0x00, 0x39, 0x31},
                .msg29_data = {
                        0x00, 0xe0, 0xff, 0xff, 0x00, 0x00, 0x00, 0x10,
                        0xff, 0x10, 0x40, 0x00, 0x00, 0x02, 0xff, 0x03,
                        0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x01, 0x00,
                        0x01, 0x00, 0xd7, 0x60, 0x00, 0x00, 0x00, 0x00,
                        0x08, 0x07, 0x10, 0x0e, 0xc4, 0x09, 0x70, 0x17,
                        0x58, 0x1b, 0x01, 0x00, 0x03, 0x00, 0x00, 0x00,
                        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00,
                        0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                        0x00, 0x00, 0x00, 0x00, 0x33, 0x0f, 0x1f, 0x0f,
                        0xff, 0xff
                },
                .msg2b_len = 0x4a,
                .msg2b_data = { /* Copied from MSP430F2616 */
                        0x00, 0x0c, 0xff, 0x0f, 0x00, 0x02, 0x02, 0x00,
                        0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                        0x00, 0x00
                }
	},
	{	.name = "MSP430F1232",
		.msg28_data = {
			0x12, 0x32, 0x10, 0x40, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x01, 0x60, 0x01, 0x00, 0x12, 0x12,
			0x00, 0x00
		},
		.msg29_params = {0x00, 0x11, 0x10},
		.msg29_data = {
			0x00, 0xe0, 0xff, 0xff, 0x00, 0x00, 0x00, 0x10,
			0xff, 0x10, 0x80, 0x00, 0x00, 0x02, 0xff, 0x02,
			0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x01, 0x00,
			0x00, 0x00, 0xd7, 0x60, 0x00, 0x00, 0x00, 0x00,
			0x08, 0x07, 0x10, 0x0e, 0xc4, 0x09, 0x70, 0x17,
			0x58, 0x1b, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x33, 0x03, 0x13, 0x03,
			0xff, 0x03
		},
		.msg2b_len = 0x34,
		.msg2b_data = {
			0x00, 0x0c, 0xff, 0x0f, 0x00, 0x02, 0x00, 0x00,
			0x02, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00
		}
	},
	{	.name = "MSP430F413",
		.msg28_data = {
			0xf4, 0x13, 0x02, 0x40, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x01, 0x30, 0x01, 0x00, 0xf6, 0x63,
			0x00, 0x00
		},
		.msg29_params = {0x00, 0x28, 0x21},
		.msg29_data = {
			0x00, 0xe0, 0xff, 0xff, 0x00, 0x00, 0x00, 0x10,
			0xff, 0x10, 0x80, 0x00, 0x00, 0x02, 0xff, 0x02,
			0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x01, 0x00,
			0x01, 0x00, 0xd7, 0x60, 0x90, 0x00, 0x9c, 0x00,
			0x08, 0x07, 0x10, 0x0e, 0xc4, 0x09, 0x70, 0x17,
			0x58, 0x1b, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x01, 0x00, 0x33, 0x80, 0x13, 0x80,
			0xff, 0xff
		},
		.msg2b_len = 0x34,
		.msg2b_data = {
			0x00, 0x0c, 0xff, 0x0f, 0x00, 0x02, 0x00, 0x00,
			0x02, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00
		}
	},
	{ /* Captured with sniffusb/CCS */
		.name = "MSP430FG4618",
		.msg28_data = {
			0xf4, 0x6f, 0x32, 0x40, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x02, 0x12, 0x01, 0x47, 0xd6, 0x7a,
			0x81, 0x00
			/* extra: 89 00 00 00 00 00 00 00 */
		},
		.msg29_params = {0, 0x3a, 0x32},
		.msg29_data = {
			0x00, 0x31, 0xff, 0xff, 0x01, 0x00, 0x00, 0x10,
			0xff, 0x10, 0x80, 0x00, 0x00, 0x02, 0xff, 0x09,
			0x00, 0x11, 0xff, 0x30, 0x08, 0x00, 0x03, 0x00,
			0x02, 0x00, 0xd7, 0x60, 0x90, 0x00, 0x9c, 0x00,
			0x08, 0x07, 0x10, 0x0e, 0xc4, 0x09, 0x70, 0x17,
			0x58, 0x1b, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x01, 0x00,
			0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x33, 0xbf, 0x13, 0xbf,
			0xff, 0x30
		},
		.msg2b_len = 0x4a,
		.msg2b_data = {
			0x00, 0x0c, 0xff, 0x0f, 0x00, 0x02, 0x02, 0x00,
			0x08, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x01,
			0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00
		}
	},
	{ /* Captured with sniffusb (Olimex adapater) */
		.name = "MSP430F2617",
		.msg28_data = {
			0xf2, 0x6f, 0x04, 0x60, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x02, 0x12, 0x01, 0x00, 0xf5, 0x1d,
			0x89, 0x00
			/* extra: 89 00 00 00 00 00 00 00 */
		},
		.msg29_params = {0, 0x42, 0x3a},
		.msg29_data = {
			0x00, 0x31, 0xff, 0xff, 0x01, 0x00, 0x00, 0x10,
			0xff, 0x10, 0x40, 0x00, 0x00, 0x02, 0xff, 0x09,
			0x00, 0x11, 0xff, 0x30, 0x08, 0x00, 0x03, 0x00,
			0x02, 0x00, 0xd7, 0x60, 0x00, 0x00, 0x00, 0x00,
			0x08, 0x07, 0x10, 0x0e, 0xc4, 0x09, 0x70, 0x17,
			0x58, 0x1b, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x01, 0x00,
			0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x33, 0x0f, 0x1f, 0x0f,
			0xff, 0xff
		},
		.msg2b_len = 0x34,
		.msg2b_data = {
			0x00, 0x0c, 0xff, 0x0f, 0x00, 0x02, 0x02, 0x00,
			0x08, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00,
			0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x01, 0x00
		}
	},
	{ /* Captured with sniffusb (Olimex adapter) */
		.name = "MSP430F2131",
		.msg28_data = {
			0xf2, 0x13, 0x50, 0x40, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x02, 0x01, 0x01, 0x01, 0xa1, 0x53,
			0x00, 0x00
			/* extra: 89 00 00 00 00 00 00 00 */
		},
		.msg29_params = {0, 0x2f, 0x27},
		.msg29_data = {
			0x00, 0xe0, 0xff, 0xff, 0x00, 0x00, 0x00, 0x10,
			0xff, 0x10, 0x40, 0x00, 0x00, 0x02, 0xff, 0x02,
			0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x01, 0x00,
			0x01, 0x00, 0xd7, 0x60, 0x00, 0x00, 0x00, 0x00,
			0x08, 0x07, 0x10, 0x0e, 0xc4, 0x09, 0x70, 0x17,
			0x58, 0x1b, 0x01, 0x00, 0x03, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x33, 0xff, 0x1f, 0xff,
			0xff, 0xff
		},
		.msg2b_len = 0x34,
		.msg2b_data = {
			0x00, 0x0c, 0xff, 0x0f, 0x00, 0x02, 0x00, 0x00,
			0x02, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00
		}
	},
	{ /* Captured with sniffusb (Olimex adapter) */
		.name = "MSP430F1121",
		.msg28_data = {
			0xf1, 0x12, 0x10, 0x40, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x01, 0x10, 0x01, 0x00, 0xe1, 0x42,
			0x00, 0x00
			/* extra: 89 00 00 00 00 00 00 00 */
		},
		.msg29_params = {0, 2, 2},
		.msg29_data = {
			0x00, 0xf0, 0xff, 0xff, 0x00, 0x00, 0x00, 0x10,
			0xff, 0x10, 0x80, 0x00, 0x00, 0x02, 0xff, 0x02,
			0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x01, 0x00,
			0x00, 0x00, 0xd7, 0x60, 0x00, 0x00, 0x00, 0x00,
			0x08, 0x07, 0x10, 0x0e, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x33, 0xff, 0x13, 0xff,
			0xff, 0xff
		},
		.msg2b_len = 0x34,
		.msg2b_data = {
			0x00, 0x0c, 0xff, 0x0f, 0x00, 0x02, 0x00, 0x00,
			0x02, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00
		}
	}
};

const struct fet_db_record *fet_db_find_by_msg28(uint8_t *data, int len)
{
	int i;
	int best_score = 0;
	int best = -1;

	if (len < 2)
		return NULL;

	if (len > FET_DB_MSG28_LEN)
		len = FET_DB_MSG28_LEN;

	for (i = 0; i < ARRAY_LEN(fet_db); i++) {
		const struct fet_db_record *r = &fet_db[i];

		if (r->msg28_data[0] == data[0] &&
		    r->msg28_data[1] == data[1]) {
			const static int coefficients[FET_DB_MSG28_LEN] = {
				1, 1, 1, 1, 1, 1, 1, 1,
				1, 1, 0, 0, 1, 1, 1, 1,
				10, 1
			};

			int score = 0;
			int j;

			for (j = 0; j < len; j++)
				if (r->msg28_data[j] == data[j])
					score += coefficients[j];

			if (best < 0 || score > best_score) {
				best = i;
				best_score = score;
			}
		}
	}

	if (best >= 0)
		return &fet_db[best];

	return NULL;
}

const struct fet_db_record *fet_db_find_by_name(const char *name)
{
	int i;

	for (i = 0; i < ARRAY_LEN(fet_db); i++) {
		const struct fet_db_record *r = &fet_db[i];

		if (!strcasecmp(r->name, name))
			return r;
	}

	return NULL;
}

int fet_db_enum(fet_db_enum_func_t func, void *user_data)
{
	int i;

	for (i = 0; i < ARRAY_LEN(fet_db); i++)
		if (func(user_data, &fet_db[i]) < 0)
			return -1;

	return 0;
}
