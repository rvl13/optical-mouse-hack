/*
 ADNS2610.h - Part of optical mouse sensor library for Arduino
 Copyright (c) 2008 Martijn The.  All right reserved.
 http://www.martijnthe.nl/
 Conversion to Arduino 1.x by zapmaker (zapmaker.org)
 
 Based on sketches by Beno�t Rousseau.
 
 This library is free software; you can redistribute it and/or
 modify it under the terms of the GNU Lesser General Public
 License as published by the Free Software Foundation; either
 version 2.1 of the License, or (at your option) any later version.
 
 This library is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public
 License along with this library; if not, write to the Free Software
 Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */

#ifndef ADNS2610_h
#define ADNS2610_h

#include <inttypes.h>
#include "OptiMouse.h"

class ADNS2610 : public OptiMouse
{
  private:
  public:
	ADNS2610(uint8_t, uint8_t);
	//signed char dx(void);
	//signed char dy(void);

	int8_t delta_x(void);
	int8_t delta_y(void);

	uint8_t read_config_reg(void);
	uint8_t read_status_reg(void);
	uint8_t read_inverse_product_reg(void);

	void write_config_reg(uint8_t config_reg_value);

	uint8_t read_pixel_data_reg(void);
	void write_pixel_data_reg(void);
};

#endif
