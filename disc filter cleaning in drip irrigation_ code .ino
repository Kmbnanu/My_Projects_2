#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#define FIREBASE_HOST "drip-9b463-default-rtdb.firebaseio.com"           // Your Firebase Project URL 
#define FIREBASE_AUTH "0A9eys1OSO1zNQzIuVucqraPNHko5x9IA6ICy6QV"         // Your Firebase Database Secret
#define WIFI_SSID "suhan"           // your WiFi SSID
#define WIFI_PASSWORD "123456781"             // your WiFi PASSWORD
 

 
#define Relay1 5 //D1
int value1;
 


 
#define Relay2 0 //D3
int value2;

#define Relay3 2 //D4
int value3;

#define Relay4 14 //D5
int value4;
 



void setup() 
{
  Serial.begin(115200);               
 
  pinMode(Relay1,OUTPUT);
  
  pinMode(Relay2,OUTPUT);
  pinMode(Relay3,OUTPUT);
  pinMode(Relay4,OUTPUT);
  

 
  
  digitalWrite(Relay1,HIGH);
  
  digitalWrite(Relay2,HIGH);
  digitalWrite(Relay3,HIGH);
  digitalWrite(Relay4,HIGH);
 

 
  WiFi.begin(WIFI_SSID,WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status()!=WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected:");
  Serial.println(WiFi.localIP());
 
  Firebase.begin(FIREBASE_HOST);
}
 
 
void firebasereconnect()
{
  Serial.println("Trying to reconnect");
    Firebase.begin(FIREBASE_HOST);
  }
 
void loop() 
{
  if (Firebase.failed())
      {
      Serial.print("setting number failed:");
      Serial.println(Firebase.error());
      firebasereconnect();
      return;
      }
      
  value1=Firebase.getString("FV1").toInt();        //Reading the Status of Variable 1 from the firebase
  
  if(value1==0)                                             
     {
      digitalWrite(Relay1,LOW);
      Serial.println("Relay 1 oN");
    }
    else if(value1==1)                                    
    {                                      
      digitalWrite(Relay1,HIGH);
      Serial.println("Relay 1 OFF");
    }
 
  value2=Firebase.getString("FV2").toInt();         //Reading the Status of Variable 2 from the firebase
  
  if(value2==0)                                                           
     {
      digitalWrite(Relay2,LOW);
      Serial.println("Relay 2 ON");
    }
    else if(value2==1)                                                   
    {                                      
      digitalWrite(Relay2,HIGH);
      Serial.println("Relay 2 OFF");
    }
 
   value3=Firebase.getString("FV3").toInt();         //Reading the Status of Variable 3 from the firebase
  
  if(value3==0)                                                         
     {
      digitalWrite(Relay3,LOW);
      Serial.println("Relay 3 ON");
    }
    else if(value3==1)                                                    
    {                                      
      digitalWrite(Relay3,HIGH);
      Serial.println("Relay 3 OFF");
    }
 
   value4=Firebase.getString("FV4").toInt();         //Reading the Status of Variable 4 from the firebase
  
  if(value4==0)                                                           
     {
      digitalWrite(Relay4,LOW);
      Serial.println("Relay 4 ON");
    }
    else if(value4==1)                                                    
    {                                      
      digitalWrite(Relay4,HIGH);
      Serial.println("Relay 4 OFF");
    }    
            //Reading the Status of Variable 3 from the firebase



}
