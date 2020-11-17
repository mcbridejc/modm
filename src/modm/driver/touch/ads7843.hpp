/*
 * Copyright (c) 2009-2011, 2013, Fabian Greif
 * Copyright (c) 2010, Martin Rosekeit
 * Copyright (c) 2012-2014, 2018, Niklas Hauser
 * Copyright (c) 2013, Daniel Krebs
 *
 * This file is part of the modm project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
// ----------------------------------------------------------------------------

#ifndef MODM_ADS7843_HPP
#define MODM_ADS7843_HPP

#include <stdint.h>
#include <modm/ui/display/graphic_display.hpp>
#include <modm/architecture/interface/delay.hpp>



namespace modm
{
	/**
	 * @author	Fabian Greif <fabian.greif@rwth-aachen.de>
	 * @ingroup modm_driver_ads7843
	 */
	template <typename Spi, typename Cs, typename Int>
	class Ads7843
	{
	public:
		static void
		initialize();

		/**
		 * Get the smoothed (x,y) position.
		 *
		 * @param	point
		 * 		(x,y) position on the pressed touchscreen
		 *
		 * @return	`true` if the touchscreen is pressed and the value is
		 * 			stable enough to provide a reading, otherwise `false`.
		 */
		static bool
		read(modm::glcd::Point * point, uint16_t pressure_threshold=defaultThreshold);

		static inline uint16_t
		readX()
		{
			return readData(CHX);
		}

		static inline uint16_t
		readY()
		{
			return readData(CHY);
		}

		static inline uint16_t
		readZ1()
		{
			return readData(CHZ1);
		}

		static inline uint16_t
		readZ2()
		{
			return readData(CHZ2);
		}

		static inline uint16_t
		readPressure()
		{
			uint16_t z1 = readZ1();
			uint16_t z2 = readZ2();
			return z1 + 4095 - z2;
		}

	private:
		static const uint8_t CHX = 0x90;
		static const uint8_t CHY = 0xd0;
		static const uint8_t CHZ1 = 0xb0;
		static const uint8_t CHZ2 = 0xc0;

		static const uint16_t defaultThreshold = 72;

		static uint16_t
		getBestTwo(uint16_t *temp);

		static uint16_t
		readData(uint8_t command);
	};
}

#include "ads7843_impl.hpp"

#endif // MODM_ADS7843_HPP
