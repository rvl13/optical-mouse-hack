/*
 ADNS2610.cpp - Part of optical mouse sensor library for Arduino
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

/******************************************************************************
 * Includes
 ******************************************************************************/

#include "Arduino.h"
#include "OptiMouse.h"
#include "ADNS2610.h"

/******************************************************************************
 * Definitions
 ******************************************************************************/

#define Delta_Y				0x02
#define Delta_X				0x03

#define ADDR_CONFIG				(0x00)
#define ADDR_STATUS				(0x01)
#define ADDR_DELTA_Y			(0x02)
#define ADDR_DELTA_X			(0x03)
#define ADDR_SQUAL				(0x04)
#define ADDR_MAX_PIXEL			(0x05)
#define ADDR_MIN_PIXEL			(0x06)
#define ADDR_PIXEL_SUM			(0x07)
#define ADDR_PIXEL_DATA			(0x08)
#define ADDR_SHUTTER_UPPER		(0x09)
#define ADDR_SHUTTER_LOWER		(0x0A)
#define ADDR_INVERSE_PRODUCT	(0x11)

/******************************************************************************
 * Constructors
 ******************************************************************************/


ADNS2610::ADNS2610(uint8_t sclkPin, uint8_t sdioPin) : OptiMouse::OptiMouse(sclkPin, sdioPin)
{

}

/******************************************************************************
 * User API
 ******************************************************************************/
/*
signed char ADNS2610::dx(void)
{
	return (signed char) readRegister(Delta_X);
}
*/

/*
signed char ADNS2610::dy(void)
{
	return (signed char) readRegister(Delta_Y);
}
*/

int8_t ADNS2610::delta_x(void)
{
	return (int8_t) readRegister((uint8_t)ADDR_DELTA_X);
}

int8_t ADNS2610::delta_y(void)
{
	return (int8_t) readRegister((uint8_t)ADDR_DELTA_Y);
}

uint8_t ADNS2610::read_config_reg(void)
{
	return readRegister((uint8_t)ADDR_CONFIG);
}

uint8_t ADNS2610::read_status_reg(void)
{
	return readRegister((uint8_t)ADDR_STATUS);
}

uint8_t ADNS2610::read_inverse_product_reg(void)
{
	return readRegister((uint8_t)ADDR_INVERSE_PRODUCT);
}


void ADNS2610::write_config_reg(uint8_t config_reg_value)
{
	writeRegister( (uint8_t)ADDR_CONFIG , config_reg_value);
}

uint8_t ADNS2610::read_pixel_data_reg(void)
{
	return readRegister((uint8_t)ADDR_PIXEL_DATA);
}

void ADNS2610::write_pixel_data_reg(void)
{
	// just write any value, it doesn't matter
  // we will write 0x13
	writeRegister( (uint8_t)ADDR_PIXEL_DATA, 0x13);
}

// Private Methods /////////////////////////////////////////////////////////////

