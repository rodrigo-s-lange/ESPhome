#include <ESPhome.h>


/* begin */
void ESPhome::begin(int pin_Buzzer = P15_BUZ, int pin_blink = P2_LED, int pin_sPresence = P0_SPR, int pin_sAux1 = P3_IN1, int pin_sAux2 = P1_IN2, int pin_pulse = P4_PUL, int pin_sOpen = P13_SOP, int pin_sClosed = P12_SCL, int pin_sRoute = P14_AUX, int pin_lighting = P5_LGT, int pin_doorbell = P16_DBL)
{
   pinMode(pin_Buzzer, OUTPUT);
   pinMode(pin_blink, OUTPUT);
   pinMode(pin_pulse, OUTPUT);
   pinMode(pin_lighting, OUTPUT);
   pinMode(pin_sPresence, IMPUT);
   pinMode(pin_sAux1, IMPUT);
   pinMode(pin_sAux2, IMPUT);
   pinMode(pin_sOpen, IMPUT);
   pinMode(pin_sClosed, IMPUT);
   pinMode(pin_sRoute, IMPUT);
   pinMode(pin_doorbell, IMPUT);
   digitalWrite(pin_Buzzer, LOW);
   digitalWrite(pin_blink, LOW);
   digitalWrite(pin_pulse, LOW);
   digitalWrite(pin_lighting, LOW);
}

/* alarm */
void ESPhome::alarm(bool state) const
{
   AlarmState = state;
}

bool ESPhome::isalarmtriggered() const
{
   sp = digitalRead(P0_SPR);
   if (sp)
   {
      ms = millis();
   }
   return sp;
}

void ESPhome::blink(bool state) const
{
   if (state)
   {
      digitalWrite(pin_blink, !digitalRead(pin_blink));
   }
   else
      digitalWrite(pin_blink, LOW);
}

bool ESPhome::isAux1triggered() const
{
   Aux1 = digitalRead(P1_IN1);
   return Aux1;
}

bool ESPhome::isAux2triggered() const
{
   bool Aux2 = digitalRead(P1_IN2);
   return Aux2;
}

void ESPhome::bip(bool state) const
{
   if (state)
   {
      if (AlarmState)
      {
         digitalWrite(P15_BUZ, HIGH)
             delay(DELAY_BIP);
         digitalWrite(P15_BUZ, LOW)
             delay(DELAY_BIP);
         digitalWrite(P15_BUZ, HIGH)
             delay(DELAY_BIP);
         digitalWrite(P15_BUZ, LOW)
             delay(DELAY_BIP);
      }
      else
      {
         digitalWrite(P15_BUZ, HIGH)
             delay(DELAY_BIP);
         digitalWrite(P15_BUZ, LOW)
             delay(DELAY_BIP);
      }
   }
}

/* garagedoor */

uint8_t ESPhome::sensors() const
{
   sf = digitalRead(P12_SCL);
   sa = digitalRead(P13_SOP);
   sr = digitalRead(P14_AUX);

   if (sa == 1 && sr == 1 && sf == 1)
   {
      sensorState = 0;
      return 0;
   }
   if (sa == 1 && sr == 1 && sf == 0)
   {
      sensorState = 1;
      return 1;
   }
   if (sa == 0 && sr == 1 && sf == 1)
   {
      sensorState = 2;
      return 2;
   }
   if (sa == 1 && sr == 0 && sf == 0)
   {
      sensorState = 3;
      return 3;
   }
   if (sa == 0 && sr == 0 && sf == 1)
   {
      sensorState = 4;
      return 4;
   }
   if (sa == 0 && sr == 1 && sf == 0)
   {
      sensorState = 5;
      return 5;
   }
   if (sa == 0 && sr == 0 && sf == 0)
   {
      sensorState = 6;
      ms = millis();
      return 6;
   }
   else
   {
      sensorState = 7;
      return 7;
   }
}

bool ESPhome::isSensorOpenTriggered() const
{
   return sa;
}

bool ESPhome::isSensorClosedTriggered() const
{
   return sf
}

bool ESPhome::isSensorRouteTriggered() const
{
   return sr;
}

bool ESPhome::isgaragedooropen() const
{
   uint8_t x = sensors();
   if (x == 1 || x == 3 || x == 5 || x == 6)
      return true;
   else
      return false;
}

void ESPhome::pulse() const
{
   digitalWrite(P4_PUL, HIGH);
   delay(DELAY_PULSE);
   digitalWrite(P4_PUL, LOW);
}

/* lighting */
bool ESPhome::islightingon() const
{
   return digitalRead(P5_LGT);
}

void ESPhome::lighting(bool state) const
{
   digitalWrite(P5_LGT, state);
}

/* doorbell */
bool ESPhome::isdoorbellpressed() const
{
   if (digitalRead(P16_DBL))
   {
      doorbellState = true;
   }
   else doorbellState = false;
   return doorBell ? true : false;
}

void run(void)
{
   sensors();
   isdoorbellpressed();
   isalarmtriggered();

   if (AlarmState)
   {
      if (sensorSate == 6)
      {
         digitalWrite(P15_BUZ, HIGH);
      }
   }

   if ((millis() - ms) >= DELAY_MS)
   {
      digitalWrite(P15_BUZ, LOW);
   }

}
