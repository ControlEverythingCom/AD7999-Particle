bool ready = false;
unsigned long tOut = 500;

void setup() {
    Wire.begin();
    Wire.beginTransmission(0x29);
    byte status = Wire.endTransmission();
    if(status != 0){
        Serial.println("Failed to communicate with sensor");
    }else{
        Serial.println("Communication to sensor initialized");
        ready = true;
    }
}

void loop() {
    while(ready){
        //Read channel 1
        Wire.beginTransmission(0x29);
        Wire.write(16);
        byte status = Wire.endTransmission();
        if(status != 0){
            Serial.println("Failed to communicate with sensor");
        }else{
            ready = true;
        }
        unsigned long startTime = millis();
        Wire.requestFrom(0x29, 2);
        while(Wire.available() != 2 && millis() < startTime+tOut);
        if(Wire.available() !=2){
            Serial.println("Timeout");
            ready = false;
            break;
        }else{
            int msb = Wire.read();
            msb = msb&0x0f;
            int lsb = Wire.read();
            int reading = (msb*256)+lsb;
            Serial.printf("Input 1 reading: %i \n", reading);
        }
        delay(100);
        //Read channel 2
        Wire.beginTransmission(0x29);
        Wire.write(32);
        status = Wire.endTransmission();
        if(status != 0){
            Serial.println("Failed to communicate with sensor");
        }else{
            ready = true;
        }
        startTime = millis();
        Wire.requestFrom(0x29, 2);
        while(Wire.available() != 2 && millis() < startTime+tOut);
        if(Wire.available() !=2){
            Serial.println("Timeout");
            ready = false;
            break;
        }else{
            int msb = Wire.read();
            msb = msb&0x0f;
            int lsb = Wire.read();
            int reading = (msb*256)+lsb;
            Serial.printf("Input 2 reading: %i \n", reading);
        }
        delay(100);
        //Read channel 3
        Wire.beginTransmission(0x29);
        Wire.write(64);
        status = Wire.endTransmission();
        if(status != 0){
            Serial.println("Failed to communicate with sensor");
        }else{
            ready = true;
        }
        startTime = millis();
        Wire.requestFrom(0x29, 2);
        while(Wire.available() != 2 && millis() < startTime+tOut);
        if(Wire.available() !=2){
            Serial.println("Timeout");
            ready = false;
            break;
        }else{
            int msb = Wire.read();
            msb = msb&0x0f;
            int lsb = Wire.read();
            int reading = (msb*256)+lsb;
            Serial.printf("Input 3 reading: %i \n", reading);
        }
        delay(100);
        //Read channel 4
        Wire.beginTransmission(0x29);
        Wire.write(128);
        status = Wire.endTransmission();
        if(status != 0){
            Serial.println("Failed to communicate with sensor");
        }else{
            ready = true;
        }
        startTime = millis();
        Wire.requestFrom(0x29, 2);
        while(Wire.available() != 2 && millis() < startTime+tOut);
        if(Wire.available() !=2){
            Serial.println("Timeout");
            ready = false;
            break;
        }else{
            int msb = Wire.read();
            msb = msb&0x0f;
            int lsb = Wire.read();
            int reading = (msb*256)+lsb;
            Serial.printf("Input 4 reading: %i \n", reading);
        }
        delay(1000);
    }
    Wire.beginTransmission(0x29);
    byte status = Wire.endTransmission();
    if(status != 0){
        Serial.println("Failed to communicate with sensor");
    }else{
        Serial.println("Communication to sensor initialized");
        ready = true;
    }
    delay(1000);
    
}