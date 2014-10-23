/*psuedocode
*/

//prototype functions
turn(char direction, int time);
fire(int power);

//enable ADC functionality

int main(void){
    //take in ADC values

    //lots of if statements...
    //call turn() based on ADC values
    //threshold to prevent shaking around target
    
    //figure out the power from distance... ADC value after the comparing stage
    
    //fire that shit
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