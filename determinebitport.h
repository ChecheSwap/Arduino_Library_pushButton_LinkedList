#ifndef determinebitport_h
#define determinebitport_h
#include <arduino.h>//USAR PREFERENTEMENTE PINES DIGITALES 3-7
template <typename bitport>
bitport determinebitport(bitport pin)
{
    if(pin>0 && pin<8)
        return PORTD;
        else if(pin>7 && pin<14)
            return PORTB;
        else
            return PORTC;
}
#endif
