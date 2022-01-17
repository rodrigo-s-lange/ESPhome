#pragma once
#ifndef _ESPhome_H
#define _ESPhome_H
#include <Arduino.h>

#define DELAY_MS 120 * 1000
#define DELAY_BIP 350
#define DELAY_PULSE 400

#define P4_PUL 4   // saida abre e fecha portão
#define P5_LGT 5   // saida liga refletor 200w
#define P14_AUX 14 // entrada rele placa
#define P12_SCL 12 // entrada sensor fechado
#define P13_SOP 13 // entrada sensor aberto
#define P0_SPR 0   //boot high // sensor de presença
#define P2_LED 2   //boot high // led blue saida led sinalização
#define P15_BUZ 15 //boot low  // sirene
#define P16_DBL 16 // entrada de campainha
#define P3_IN1 3   // entrada para saida rele 1 do dvr
#define P1_IN2 1   // entrada para saida rele 2 do dvr

class ESPhome
{
protected:
    bool Aux1;
    bool Aux2;
    bool sa;
    bool sr;
    bool sf;
    bool sp;
    bool AlarmState;
    unsigned long ms;
    uint8_t sensorState;
    bool doorbellState;

private:
public:
    /* motor */
    void run(void) const;

    /* begin */
    void begin(int pin_Buzzer = P15_BUZ,
               int pin_blink = P2_LED,
               int pin_sPresence = P0_SPR,
               int pin_sAux1 = P3_IN1,
               int pin_sAux2 = P1_IN2,
               int pin_pulse = P4_PUL,
               int pin_sOpen = P13_SOP,
               int pin_sClosed = P12_SCL,
               int pin_sRoute = P14_AUX,
               int pin_lighting = P5_LGT,
               int pin_doorbell = P16_DBL);

    /* alarm */
    void alarm(bool state) const;
    bool isalarmtriggered() const;
    void blink(bool state) const;
    bool isAux1triggered() const;
    bool isAux2triggered() const;
    void bip(bool state) const;

    /* garagedoor */
    bool isgaragedooropen() const;
    void pulse() const;
    uint8_t sensors() const;
    bool isSensorOpenTriggered() const;
    bool isSensorClosedTriggered() const;
    bool isSensorRouteTriggered() const;

    /* lighting */
    bool islightingon() const;
    void lighting(bool state) const;

    /* doorbell */
    bool isdoorbellpressed() const;
};
#endif