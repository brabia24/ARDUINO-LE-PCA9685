#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
int gelen_deger=0;
int duty_value=0;
int kanal_secim=0;

// called this way, it uses the default address 0x40
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

int egale = 0;

void setup() {
  Serial.begin(115200);
 
  pwm.begin();
  pwm.setPWMFreq(571);  // This is the maximum PWM frequency
  Wire.setClock(400000);
 

 
}
 
void loop() 
{
 
    if (Serial.available() )
     {
        
        kanal_secim =Serial.parseInt();
        if(kanal_secim==1){
        Serial.print("kanal1 seçildi.");
     
        Serial.print("Duty değeri giriniz:");
        delay(2000);
        gelen_deger =Serial.parseInt();
        
        egale++;
          if(egale == 1)
        { 

            duty_value= map( gelen_deger, 0, 100, 0, 4095);
            
            
         //  eğer duty value 0 sa setpwm i sıfırla dury value 100 se 100le
           if(duty_value>0 && duty_value<4095)
           {
            pwm.setPWM(0,4095,duty_value);
            Serial.print("Duty değeri:% ");
            Serial.println(duty_value);
            
            }
            else if(duty_value==4095)
            {
             pwm.setPWM(0,4096,0);
            Serial.print("Duty değeri:% ");
            Serial.println(duty_value);
        }
        else{
           //pwm.setPWM(0,4096,0);
           pwm.setPWM(0,0,4096);
           Serial.print("Duty değeri:% ");
           Serial.println(duty_value);
        }
        }
        
               egale = 0;
        }
          else if(kanal_secim==2)
          {
          Serial.print("kanal2 seçildi.");
          Serial.print("Duty değeri giriniz:");
          delay(2000);
          gelen_deger =Serial.parseInt();
          
          egale++;
          if(egale == 1)
          { 
  
                duty_value= map( gelen_deger, 0, 100, 0, 4095);
                
                
               if(duty_value>0 && duty_value<4095)
               {
                pwm.setPWM(4,4095,duty_value);
                Serial.print("Duty değeri:% ");
                Serial.println(duty_value);
                
                }
                else if(duty_value==4095)
                {
                 pwm.setPWM(4,4096,0);
                Serial.print("Duty değeri:% ");
                Serial.println(duty_value);
            }
            else{
               //pwm.setPWM(0,4096,0);
               pwm.setPWM(4,0,4096);
               Serial.print("Duty değeri:% ");
               Serial.println(duty_value);
            }
          }
         
              egale = 0;
              
          }
            else if (kanal_secim==3)
            
            {
              Serial.print("kanal3 seçildi.");
              Serial.print("Duty değeri giriniz:");
              delay(2000);
              gelen_deger =Serial.parseInt();
              
              egale++;
              if(egale == 1)
              { 
      
                 duty_value= map( gelen_deger, 0, 100, 0, 4095);

                 if(duty_value>0 && duty_value<4095)
                 {
                  pwm.setPWM(9,4095,duty_value);
                  Serial.print("Duty değeri:% ");
                  Serial.println(duty_value);
                  
                  }
                  else if(duty_value==4095)
                  {
                   pwm.setPWM(9,4096,0);
                  Serial.print("Duty değeri:% ");
                  Serial.println(duty_value);
              }
              else{
                 //pwm.setPWM(0,4096,0);
                 pwm.setPWM(9,0,4096);
                 Serial.print("Duty değeri:% ");
                 Serial.println(duty_value);
              }
            }
            
                egale = 0;

            }
    
     
     
     }
     }
