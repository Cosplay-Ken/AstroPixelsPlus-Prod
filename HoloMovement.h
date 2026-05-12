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

extern bool holoAutomationEnabled;

extern bool holoRandomMode;
extern uint8_t currentHoloMode;
extern unsigned long nextMoodChange;

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
    holoAckEnd = millis() + 500;
    holoAckMode = mode;

    switch (mode)
    {
        case 0:
            CommandEvent::process(F("HPF0000"));
            delay(10);
            CommandEvent::process(F("HPF0055")); // Blue / Calm
            break;

        case 1:
            CommandEvent::process(F("HPF0000"));
            delay(10);
            CommandEvent::process(F("HPF0053")); // Green / Normal
            break;

        case 2:
            CommandEvent::process(F("HPF0000"));
            delay(10);
            CommandEvent::process(F("HPF0051")); // Red / Excited
            break;

        case 3:
            CommandEvent::process(F("HPF0000"));
            delay(10);
            CommandEvent::process(F("HPF006")); // Rainbow / Random
            break;            

        case 99:
            CommandEvent::process(F("HPF0000"));
            delay(10);
            CommandEvent::process(F("HPF0029")); // White Flicker / Save
            holoAckEnd = millis() + 1000;
            break;    
    }
}

////////////////////////////////////////////////////////////////////////////////
// HOLO STATUS / DEBUG OUTPUT
////////////////////////////////////////////////////////////////////////////////

const char* holoModeToString(uint8_t mode)
{
    switch (mode)
    {
        case 0: return "Calm";
        case 1: return "Normal";
        case 2: return "Excited";
        default: return "Unknown";
    }
}

void printHoloStatus()
{
    Serial.print("[HOLO] Mode: ");
    Serial.print(holoModeToString(currentHoloMode));

    Serial.print(" | Random: ");
    Serial.print(holoRandomMode ? "ON" : "OFF");

    Serial.print(" | Automation: ");
    Serial.print(holoAutomationEnabled ? "ON" : "OFF");

    Serial.print(" | NextMood(s): ");

    if (nextMoodChange > millis())
    {
        Serial.print((nextMoodChange - millis()) / 1000);
    }
    else
    {
        Serial.print(0);
    }

    Serial.println();
}

////////////////////////////////////////////////////////////////////////////////
// HOLO MOVEMENT ENGINE
////////////////////////////////////////////////////////////////////////////////

inline void updateHoloMovement()
{
    if (!holoAutomationEnabled)
    {
        return;
    }    
    
    unsigned long currentTime = millis();

    // ---------------- RANDOM MOOD MODE ----------------
    if (holoRandomMode)
    {
        if (currentTime >= nextMoodChange)
        {
            uint8_t randomMode;
            do
            {
                randomMode = random(0, 3);
            }
            while (randomMode == currentHoloMode);
            currentHoloMode = randomMode;
            applyHoloMode(currentHoloMode);
            nextMoodChange = currentTime + random(300000, 480000);
        }
    }

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

    static unsigned long lastDebugPrint = 0;

    if (millis() - lastDebugPrint > 2000)
    {
        printHoloStatus();
        lastDebugPrint = millis();
    }
}