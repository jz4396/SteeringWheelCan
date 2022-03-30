//Sends a sample CAN message out. 
//Library by Al Thomason for ATmegaxxM1 avr_CAN demo 2016
//Modified by Victor Rowello for Pitt FSAE  
//Last Build: 03/29/2022

#include <avr_can.h>

void setup()
{
  delay(1000);
  Serial.begin(9600);
  
  // Initialize CAN0 Set the proper baud rates here
  
    if (Can0.begin(CAN_BPS_1000K)) 
          Serial.println("Can Init OK");
    else  Serial.println("Can Init FAILED");

}


//README!!!

/* The functions below send a total of 3 CAN messages
 *  with each individual message holding the values of
 *  TWO (2) inputs on the steering wheel.
 *  with one input on the most signifigant half of the message
 *  and the other on the least signifigant half
 *  
 *  NOTE: there are no pin numbers in the analogRead() calls
 *  as the wiring of the circuit is still to be determined.
 *  when the time comes, just replace the foo and bar in each call
 *  with the proper pin number
  */



//Contains shifter data
bool firstMessage() {
    analogReference(DEFAULT);
    
    CAN_FRAME outgoing;
    outgoing.id = 0x01;
    outgoing.extended = false;
    outgoing.priority = 0;                            
    outgoing.length   = 8;
    
    outgoing.data.low = analogRead(foo); //UPSHIFT
    outgoing.data.high = analogRead(bar); //DOWNSHIFT              
    return(Can0.sendFrame(outgoing));  
}                                                          

//Contains Button 1/2 data
bool secondMessage() {
    analogReference(DEFAULT);
    
    CAN_FRAME outgoing;
    outgoing.id = 0x02;
    outgoing.extended = false;
    outgoing.priority = 0;                            
    outgoing.length   = 8;
    
    outgoing.data.low = analogRead(foo); //BUTTON 1
    outgoing.data.high = analogRead(bar) //BUTTON @              
    return(Can0.sendFrame(outgoing));
}

//Contains Rotary Data
bool thirdMessage() {
    analogReference(DEFAULT);
    
    CAN_FRAME outgoing;
    outgoing.id = 0x03;
    outgoing.extended = false;
    outgoing.priority = 0;                           
    outgoing.length   = 8;
    
    outgoing.data.low = analogRead(foo); //Rotary 1
    outgoing.data.high = analogRead(bar); //Clutch                
    return(Can0.sendFrame(outgoing));              
}                                                   
                                                   

void loop(){
  firstMessage();
  secondMessage();
  thirdMessage();
}
