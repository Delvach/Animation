#include "Arduino.h"
#include "Adafruit_NeoPixel.h"
#ifndef Animation_h
#define Animation_h

class Animation {
	public:
		Animation(int, long);
		long getFrequency(void);
		void setFrequency(long);
		void start(int);
		void stop(int);
		int execute(void);
		int getNumSteps(void);
		int getCurrStep(void);
		void setCurrStep(int);
		void iterateCurrStep(void);
		int getStrength(void);
		void setStrength(int);
		int isActive(void);
		unsigned long getStartMS(void);
		uint32_t getColor(void);
		void setColor(uint32_t);
		
		
	private:
		int _active;
		int _mode;
		int _numSteps;
		int _currStep;
		int _strength;
// 		uint32_t _color;
		long _frequency;
		unsigned long _startMS;
		unsigned long _prevMS;
		uint32_t _color;
		
		void _setStart(unsigned long);
		void _setPrev(unsigned long);
		void _iterate(void);
};

#endif