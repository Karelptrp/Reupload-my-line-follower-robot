#ifndef motors
#define motors

#include <avr/io.h>

#define leftMotorPWMPin		OCR1B
#define rightMotorPWMPin	OCR1A

void init_motors(void);
void set_motors(int leftMotorSpeed, int rightMotorSpeed);

void init_motors()
{
    DDRD |= (1<<PIND4) | (1<<PIND5);
	DDRD |= (1<<PIND6) | (1<<PIND7);
	TCCR1A |= (1<<COM1A1) | (1<<COM1B1);	
	TCCR1B |= (1<<CS10) | (1<<CS11);
	TCCR1A |= (1<<WGM11);
	TCCR1B |= (1<<WGM13);
	ICR1 = 250;
}

void set_motors(int leftMotorSpeed, int rightMotorSpeed)
{
    if(leftMotorSpeed >= 0)
    {
        leftMotorPWMPin = leftMotorSpeed;
		PORTD &= ~(1<<PIND7);
    }
    else
    {
        leftMotorPWMPin = 250 + leftMotorSpeed;
        PORTD |= 1<<PIND7;
    }
	if(rightMotorSpeed >= 0)
    {
        rightMotorPWMPin = rightMotorSpeed;
        PORTD &= ~(1<<PIND6);
    }
    else
    {
        rightMotorPWMPin = 250 + rightMotorSpeed;
        PORTD |= 1<<PIND6;
    }
}

#endif