#pragma once

#include <Arduino.h>
#include "core/CommandEvent.h"
#include "core/SetupEvent.h"

////////////////////////////////////////////////////////////////////////////////
// HOLO MOVEMENT STATE (DEFINED IN .INO)
////////////////////////////////////////////////////////////////////////////////

extern unsigned long lastMoveTime;
extern unsigned long nextInterval;
extern int burstCount;

extern int burstMin;
extern int burstMax;

extern int burstSpeedMin;
extern int burstSpeedMax;

extern int idleMin;
extern int idleMax;

extern bool holoAckActive;
extern unsigned long holoAckEnd;
extern uint8_t holoAckMode;

////////////////////////////////////////////////////////////////////////////////
// HOLO MODE CONFIGURATION
////////////////////////////////////////////////////////////////////////////////

inline void applyHoloMode(uint8_t mode)
{
    switch (mode)
    {
        case 0: // Calm
            burstMin = 1;
            burstMax = 2;
            burstSpeedMin = 700;
            burstSpeedMax = 1500;
            idleMin = 8000;
            idleMax = 20000;
            break;

        case 1: // Normal
            burstMin = 1;
            burstMax = 4;
            burstSpeedMin = 300;
            burstSpeedMax = 800;
            idleMin = 3000;
            idleMax = 8000;
            break;

        case 2: // Excited
            burstMin = 3;
            burstMax = 7;
            burstSpeedMin = 150;
            burstSpeedMax = 400;
            idleMin = 500;
            idleMax = 3000;
            break;
    }
}

////////////////////////////////////////////////////////////////////////////////
// HOLO ACKNOWLEDGEMENT (LIGHT + STATE TRIGGER)
////////////////////////////////////////////////////////////////////////////////

inline void triggerHoloAck(uint8_t mode)
{
    holoAckActive = true;
    holoAckEnd = millis() + 300;
    holoAckMode = mode;

    switch (mode)
    {
        case 0:
            CommandEvent::process(F("HPA0000"));
            delay(10);
            CommandEvent::process(F("HPF0055")); // Blue / Calm
            break;

        case 1:
            CommandEvent::process(F("HPA0000"));
            delay(10);
            CommandEvent::process(F("HPF0053")); // Green / Normal
            break;

        case 2:
            CommandEvent::process(F("HPA0000"));
            delay(10);
            CommandEvent::process(F("HPF0051")); // Red / Excited
            break;

        case 99:
            CommandEvent::process(F("HPA0000"));
            delay(10);
            CommandEvent::process(F("HPF0029")); // White Flicker / Save
            holoAckEnd = millis() + 1000;
            break;    
    }
}

////////////////////////////////////////////////////////////////////////////////
// HOLO MOVEMENT ENGINE
////////////////////////////////////////////////////////////////////////////////

inline void updateHoloMovement()
{
    unsigned long currentTime = millis();

    // ---------------- ACK HANDLING ----------------
    if (holoAckActive)
    {
        if (currentTime >= holoAckEnd)
        {
            holoAckActive = false;
            CommandEvent::process(F("HPA0000"));
        }
    }

    // ---------------- SAFETY CLAMPS ----------------
    if (burstMin > burstMax)
    {
        int t = burstMin;
        burstMin = burstMax;
        burstMax = t;
    }

    if (burstSpeedMin > burstSpeedMax)
    {
        int t = burstSpeedMin;
        burstSpeedMin = burstSpeedMax;
        burstSpeedMax = t;
    }

    if (idleMin > idleMax)
    {
        int t = idleMin;
        idleMin = idleMax;
        idleMax = t;
    }

    // ---------------- BURST MOVEMENT LOGIC ----------------
    if (currentTime - lastMoveTime >= nextInterval)
    {
        if (burstCount == 0)
        {
            burstCount = random(burstMin, burstMax);
        }

        burstCount--;

        int move = random(0, 6);

        switch (move)
        {
            case 0:
            case 1:
                CommandEvent::process(F("HPF104"));
                break;

            case 2:
            case 3:
                CommandEvent::process(F("HPR104"));
                break;

            case 4:
                CommandEvent::process(F("HPT104"));
                break;

            default:
                break;
        }

        if (burstCount > 0)
        {
            nextInterval = random(burstSpeedMin, burstSpeedMax);
        }
        else
        {
            nextInterval = random(idleMin, idleMax);
        }

        lastMoveTime = currentTime;
    }
}