/*
 * Encoder.h
 *
 *  Created on: Sep 4, 2022
 *  Author: shahjesal15, pheonix17,
 *  refer : https://robu.in/product/incremental-optical-rotary-encoder-6002400-pulse-600-ppr/?gclid=CjwKCAjwscGjBhAXEiwAswQqNDc4HHohENaeZ23OpaCop73IPW-LUKrKHrJ42yftrqOlECX64xapKRoC_2EQAvD_BwE
 */

#ifndef INC_ENCODER_H_
#define INC_ENCODER_H_

#include <Arduino.h>

namespace Sensors {
	class Encoder{
		protected:
			int MSB = 0, LSB = 0, encoded = 0, sum = 0, lastEncoded = 0;
			volatile long encoderValue = 0;
			byte inA, inB;
		public:
			Encoder(byte inA, byte inB);
			void update();
			void write(long count);
			long read();
	};
};

#endif /* INC_ENCODER_H_ */
