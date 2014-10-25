/*psuedocode
*/

//dependencies
#include <avr/io.h>
#include "m_general.h"
#include <avr/interrupt.h>
#define TIMER_MAX 0x80;

//prototype functions
turn(char direction, int time);
fire(int power);
init(void);
enable_timer(void);
analog_input(void);
//enable ADC functionality

volatile int OCR0A = TIMER_MAX;
volatile int OCR0B = 0x00;


int main(void){
    //take in ADC values and initialize timer
    init();
    //lots of if statements...
    //call turn() based on ADC values
    //threshold to prevent shaking around target
    
    //figure out the power from distance... ADC value after the comparing stage
    
    //fire that shit
}

void init(void)
{
    // Sets B6
    set(DDRB, 6);
    //runs method analog_input below
    analog_input();
    //runs method enable_timer below
    enable_timer();
}

void analog_input(void)
{
    // hardware settings
    m_disableJTAG();
    m_clockdivide(0);

    //voltage reference - set to Vcc
    clear(ADMUX, REFS1);
    set(ADMUX, REFS0);

    // Scale to /128, for 125kHz
    set(ADCSRA, ADPS2);
    set(ADCSRA, ADPS1);
    set(ADCSRA, ADPS0);

    //disable digital input bits 0-7
    set(DIDR0, ADC0D);

    //enables interrupts
    clear(ADCSRA, ADIE);

    // Disable ADC system
    clear(ADCSRA, ADEN);
    
    //F0 input for timer
    clear(ADCSRB, MUX5);
    clear(ADMUX, MUX2);
    clear(ADMUX, MUX1);
    clear(ADMUX, MUX0);

    // Enable ADC system
    set(ADCSRA, ADEN);

    //Begins the conversion
    set(ADCSRA, ADSC);
}

void enable_timer(void)
{
    // timer values
    OCR0A = TIMER_MAX;
    OCR0B = 0x00;

    // Sets the timer mode: OCR0A register
    set(TCCR0B, WGM02);
    set(TCCR0A, WGM01);
    set(TCCR0A, WGM00);

    //compare B7
    set(TCCR0A, COM0B1);
    clear(TCCR0A, COM0B0);

    // clockdivide
    set(TCCR0B, CS02);
    clear(TCCR0B, CS01);
    set(TCCR0B, CS00);
}


//motor turn function
//better functionality would be to turn for degrees not time... need feedback loop for this probably. worth it?
turn(char direction, int time){                     //check on char & string calling... " "?
    switch (direction) {
        case "l":
            //turn forward pin on & reverse pin off
            
            //enable pin high
            
            //wait for time
            
            //enable pin low
            break;
        case "r":
            //turn reverse pin on & forward pin off
            
            //enable pin high
            
            //wait for time
            
            //enable pin low
            break;
        case "o"
            //enable pin LOW
            break;
        default:
            m_green(ON);
            break;
    }
}

fire(int power){
    //switch firing circuit off
    
    //switch the charging circuit on
    
    //wait for a time proportional to power
    
    //switch capacitor charging circuit off
    
    //switch firing circuit on
    
    //rinse
    
    //repeat
}