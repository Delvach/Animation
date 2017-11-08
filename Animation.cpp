#include "Animation.h"

Animation::Animation(int numSteps, long frequency) {
	_numSteps = numSteps;
	_frequency = frequency;
}

long Animation::getFrequency(void) {
	return _frequency;
}

void Animation::setFrequency(long frequency) {
	_frequency = frequency;
}

void Animation::start(int mode) {
	_mode = mode;
	_startMS = millis();
	_prevMS = millis();
	_active = true;
}

void Animation::stop(int mode) {
	_mode = mode;
	_active = false;
}

int Animation::execute(void) {
	
	unsigned long elapsedSincePrev = millis() - _prevMS;
	if(elapsedSincePrev >= _frequency) {
		if(_currStep == (_numSteps - 1)) {
			setCurrStep(0);
		} else {
			iterateCurrStep();
		}
		_prevMS = millis();
		return true;
	}
	return false;
}

int Animation::getNumSteps(void) {
	return _numSteps;
}

int Animation::getCurrStep(void) {
	return _currStep;
}

void Animation::setCurrStep(int step) {
	_currStep = step;
}

void Animation::iterateCurrStep(void) {
	_currStep++;
}



int Animation::getStrength(void) {
	return _strength;
}

void Animation::setStrength(int strength) {
	_strength = strength;
}

int Animation::isActive(void) {
	return _active;
}

unsigned long Animation::getStartMS(void) {
	return _startMS;
}

uint32_t Animation::getColor(void) {
	return _color;
}

void Animation::setColor(uint32_t color) {
	_color = color;
}


void Animation::_setStart(unsigned long val) {
	_startMS = val;
}

void Animation::_setPrev(unsigned long val) {
	_prevMS = val;
}


void Animation::_iterate(void) {
	
}