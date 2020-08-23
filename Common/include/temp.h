/*
 * Content: class that controls Temperature sensor
 * Author : Tarek Al Ayoubi
 * Team   : Sustaingineering UBC
 */

#pragma once
#include <OneWire.h> 
#include <DallasTemperature.h>
#include "farmSensor.h"

class temp: public farmSensor{
private:
    OneWire m_oneWire;
    DallasTemperature m_sensors; 
protected:
    float readRaw() override;
public: 
    temp(int pin, sensorType type, String name, String unit, char shortcut);
    void initialize() override;
};

temp::temp(int pin, sensorType type, String name, String unit, char shortcut): 
                farmSensor(pin, type, name, unit, shortcut), m_oneWire(pin), m_sensors(&m_oneWire) {}


void temp::initialize()
{
    m_sensors.begin();
}

float temp::readRaw()
{
    m_sensors.requestTemperatures();
    return m_sensors.getTempCByIndex(0);
}
