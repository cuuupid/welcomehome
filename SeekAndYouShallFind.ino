  /*
    Copyright (c) 2014 MediaTek Inc.  All right reserved.
  
    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License..
  
    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
     See the GNU Lesser General Public License for more details.
  */
  #include <LBT.h>
  #include <LBTClient.h>
  #include <LSD.h>
  #include <LAudio.h>
  #define file_name (char *)"badblood.mp3"
  
  void play(char * filename){
    LAudio.setVolume(5);
    LAudio.playFile(storageFlash, filename);
    delay(5000);
  }
  
  static LBTDeviceInfo info = {0};
  boolean find = 0;
  boolean go = false;
  #define SPP_SVR "woodworks" // it should be the prefer server's name,  customize it yourself.
  int read_size = 0;
  bool success;
  void setup()  
  {
    pinMode(2,OUTPUT);pinMode(3,OUTPUT);
    success = LBTClient.begin();
  }
   
  void loop()
  {
    if(!go){
    digitalWrite(2,HIGH); digitalWrite(3,LOW);
    if( !success )
    {
        digitalWrite(2,LOW);
        delay(0xffffffff);
    }
    else
    {
        int num = LBTClient.scan(30);
        digitalWrite(2,LOW);
        delay(500);
        digitalWrite(2,HIGH);
        delay(500);
        digitalWrite(2,LOW);
        delay(500);
        digitalWrite(2,HIGH);
        for (int i = 0; i < num; i++)
        {
          memset(&info, 0, sizeof(info));
          // to check the prefer master(server)'s name
          if (!LBTClient.getDeviceInfo(i, &info))
          {
              continue;
          }
          if (0 == strcmp(info.name, SPP_SVR))
          {
              find = 1;
              digitalWrite(3,HIGH);
              go=true;
              play(file_name);
              break;
          }
        }
        
    }
    }
      delay(500);
      digitalWrite(2,LOW);
      delay(500);
      digitalWrite(2,HIGH);
      delay(500);
      digitalWrite(2,LOW);
      delay(500);
      digitalWrite(2,HIGH);
      delay(500);
      digitalWrite(2,LOW);
      delay(500);
      digitalWrite(2,HIGH);
  }
