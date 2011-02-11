// coding: utf-8
// ----------------------------------------------------------------------------
/* Copyright (c) 2011, Roboterclub Aachen e.V.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the Roboterclub Aachen e.V. nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY ROBOTERCLUB AACHEN E.V. ''AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL ROBOTERCLUB AACHEN E.V. BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
// ----------------------------------------------------------------------------
/*
 * WARNING: This file is generated automatically, do not edit!
 * Please modify the corresponding *.in file instead and rebuild this file.
 */
// ----------------------------------------------------------------------------


#ifndef XPCC__XMEGA_ADC_A_HPP
#define XPCC__XMEGA_ADC_A_HPP

#include <avr/io.h>
#include <stdint.h>
#include <xpcc/architecture/platform.hpp>

#if defined(ADCA) || defined(__DOXYGEN__)

namespace xpcc
{
	/**
	 * \brief		ADC Module A
	 *
	 * \ingroup		atxmega_adc
	 */
	class AdcModuleA
	{
	public:
		inline static ADC_t&
		getModuleBase()
		{
			return ADCA;
		}
		
		static void
		initialize(uint8_t reference=ADC_REFSEL_VCC_gc,
				ADC_PRESCALER_t prescaler=ADC_PRESCALER_DIV512_gc);
		
		inline static void
		enable(bool enable=true)
		{
			ADCA_CTRLA = (ADCA_CTRLA & ~ADC_ENABLE_bm) | (enable ? ADC_ENABLE_bm : 0);
		}
		
		/// Flush the ADC pipeline.
		inline static void
		flush()
		{
			ADCA_CTRLA |= ADC_FLUSH_bm;
		}
		
		inline static void
		setDMARequest(ADC_DMASEL_t selection=ADC_DMASEL_OFF_gc)
		{
			ADCA_CTRLA = (ADCA_CTRLA & ~ADC_DMASEL_gm) | selection;
		}
		
		/// Set signed or unsigned conversion.
		inline static void
		setConversionMode(bool unsgnd=true)
		{
			ADCA_CTRLB = (ADCA_CTRLB & ~ADC_CONMODE_bm) | (unsgnd?ADC_CONMODE_bm:0);
		}
		
		/// Enable free running mode as defined in setChannelSweep.
		inline static void
		setFreeRunningMode(bool enable=true)
		{
			ADCA_CTRLB = (ADCA_CTRLB & ~ADC_FREERUN_bm) | (enable?ADC_FREERUN_bm:0);
		}
		
		inline static void
		setResolution(ADC_RESOLUTION_t resolution=ADC_RESOLUTION_12BIT_gc)
		{
			ADCA_CTRLB = (ADCA_CTRLB & ~ADC_RESOLUTION_gm) | resolution;
		}
		
		inline static void
		setReference(uint8_t reference=ADC_REFSEL_VCC_gc)
		{
			ADCA_REFCTRL = reference;
		}
		
		inline static void
		setChannelEvent(uint8_t mode)
		{
			ADCA_EVCTRL = (ADCA_EVCTRL & ~(ADC_EVACT_gm|ADC_EVSEL_gm)) | mode;
		}
		
		inline static void
		setChannelSweep(ADC_SWEEP_t sweep)
		{
			ADCA_EVCTRL = (ADCA_EVCTRL & ~ADC_SWEEP_gm) | sweep;
		}
		
		inline static void
		setPrescaler(ADC_PRESCALER_t prescaler=ADC_PRESCALER_DIV512_gc)
		{
			ADCA_PRESCALER = prescaler;
		}
	};
}

#endif // ADCA
#endif // XPCC__XMEGA_ADC_A_HPP
