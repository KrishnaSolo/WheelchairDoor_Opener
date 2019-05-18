#include <VirtualWire.h>
#include <VirtualWire_Config.h>


// TRANSMITTER CODE

//NOTE :- THIS TRANSMITTER CODE IS USED WHEN YOU WANT TO CONTROL THE ROBOT VIA THE BREADBOARD REMOTE


//Assigning controller buttons to Digital Pins
int on = 12;
int remotePins[]= {12};//array to store pin nos

void setup()
{
    Serial.begin(9600);    // Debugging only
    Serial.println("setup");
    // Initialise the IO and ISR
    vw_setup(2000);  // Bits per sec
    vw_set_tx_pin(3); //Transmitter Data Pin to Digital Pin 3
        
 
    for(int i = 0; i<1 ; i++)
    {
      pinMode(remotePins[i], INPUT);
      digitalWrite(remotePins[i],HIGH);
    }
     
}

void loop()
{
  char *msg2;
  
  if(digitalRead(on) == LOW)//if the on button is pressed
  {
    char *msg2 = "1";//send 1 to the receiver
    digitalWrite(13, true); // Flash a light to show transmitting
    vw_send((uint8_t *)msg2, strlen(msg2));//send the byte to the receiver
    vw_wait_tx(); // Wait until the whole message is gone
    digitalWrite(13, false);
  }
  
  
}//close loop
  
 // End Of Code 
  
