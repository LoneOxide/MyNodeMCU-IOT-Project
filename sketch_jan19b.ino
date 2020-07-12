#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "---MY API TOKEN---";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Addison";
char pass[] = "wifi password";

//--DEFINING--
Servo servo;


//-------------------------------------------------------------------------------------\\
//                                        SERVO                                        \\
//-------------------------------------------------------------------------------------\\
Servo servo; 

BLYNK_WRITE(V3)
{
  servo.write(param.asInt()); //Get value as integer
}


//-------------------------------------------------------------------------------------\\
//                                Test Print w/ terminal                               \\
//-------------------------------------------------------------------------------------\\

BLYNK_WRITE(V0)
{
   
  int V0_Value = param.asInt();                  //Get value as integer
  if (V0_Value == 1)                            //Checks if Virtual Pin is 1 or HIGH
  {
  
  Serial.print  ("OwO Microwave");           //Sends to serial monitor for debugging
  Blynk.virtualWrite(V1,"OwO Microwave");    //Sends to BLYNK Virtual LCD
  delay(500);
  Blynk.virtualWrite(V1," ");                 //Clears Previous Word or something on Virtual LCD
  Serial.print('\n');
  
  }
}

//-------------------------------------------------------------------------------------\\
//                                        Other Stuff                                  \\
//-------------------------------------------------------------------------------------\\


void setup()
{
  // Debug console
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);

  servo.attach(D7);
}

void loop()
{
  Blynk.run();
  Blynk.syncAll();
  
}
