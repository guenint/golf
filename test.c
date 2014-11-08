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
parse_analog_left(void);
analog_input_left(void);
parse_analog_right(void);
analog_input_right(void);
init(void);
//enable ADC functionality

volatile int OCR0A = TIMER_MAX;
volatile int OCR0B = 0x00;
volatile int val_left = 0;
volatile int val_right = 0;


int main(void){
    //take in ADC values and initialize timer
    init();
    while(1) 
    {
        if(val_left > val_right) {
        //    turn('r', )
        }
    }
    //lots of if statements...
    //call turn() based on ADC values
    //threshold to prevent shaking around target
    
    //figure out the power from distance... ADC value after the comparing stage
    
    //fire that shit


    /*
    first, have three
    if left one is sensing more than the right, turn to the left
    if right one is sensing more than the left, turn to the right
    only stop when the one over the solenoid is very hot

    then in fire, 
    charge time for specific distance

    */
}

void init(void)
{
    // Sets B6
    set(DDRB, 6);
    //runs method analog_input below
    analog_input();

}

int parse_analog_left(void)
{
    //run every time, sets conversion
    set(ADCSRA, ADSC);
    while(1)
    {
        if(check(ADCSRA, ADIF))
        {
            //flag set to reset
            set(ADCSRA, ADIF);
            val_left = ADC;
            return ADC;
        }
    }
}
int parse_analog_right(void) {
    //set up alternate analog timer
}

// need analog input for other pin for right
void analog_input_right(void) {

}


//analog input for phototransistor LEFT = F0
void analog_input_left(void)
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
    
    //F0 input FOR LEFT
    clear(ADCSRB, MUX5);
    clear(ADMUX, MUX2);
    clear(ADMUX, MUX1);
    clear(ADMUX, MUX0);

    // Enable ADC system
    set(ADCSRA, ADEN);

    //Begins the conversion
    set(ADCSRA, ADSC);
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