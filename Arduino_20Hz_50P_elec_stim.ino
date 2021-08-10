// setting voltage，single pulse duration=1ms

int image_pin = 1; // 2P imaging
int stim_pin = 13; // electrical stimulation
int freq = 20; 
int pulse = 50;
int stimdelay = 10000; // baseline=10s
//  0: test, 50 pulse (2s after enter) 

//  Stim @ 20Hz------ 1: 1p   2: 2p   3: 5p   4: 10p  5: 20p  6: 50p  7: 100p
//  Stim @ 50P------ a: 1Hz   b: 2Hz   c: 5Hz   d: 10Hz  e: 20Hz  f: 50Hz  g: 100Hz

void setup()
{
pinMode(image_pin,OUTPUT); //make sure the pin number that control 2p imaging
pinMode(stim_pin,OUTPUT); //electrical stimulator. trigger.
digitalWrite(image_pin,LOW);
digitalWrite(stim_pin,LOW);
Serial.begin(9600);
}

byte state=0;
void loop()
{
  if(Serial.available()!=0){state=Serial.read();Serial.flush();}
  switch(state)
  {
    case '0': // 0 = test
    Serial.println("test imaging and stimulator");
    digitalWrite(image_pin,HIGH);digitalWrite(image_pin,LOW); //start imaging
    delay(5000);
    Serial.println("electrical stimulation start");
    for (int i=1; i<=1; i++) {
     digitalWrite(stim_pin,HIGH);delay(2000);digitalWrite(stim_pin,LOW);
    }
    Serial.println("test over");
    Serial.println("--------------------");
    state=0;break;

    case '1': // 1 = single pulse
    Serial.println("imaging and 1 pulse");
    digitalWrite(image_pin,HIGH);digitalWrite(image_pin,LOW); //start imaging
    delay(stimdelay);
    Serial.println("electrical stimulation start");
    digitalWrite(stim_pin,HIGH);delay(1);digitalWrite(stim_pin,LOW);
    Serial.println("1 pulse over");
    Serial.println("--------------------");
    state=0;break;

    case '2': // 2 = 2 pulses
    Serial.println("imaging and 2 pulses");
    digitalWrite(image_pin,HIGH);;digitalWrite(image_pin,LOW); //start imaging
    delay(stimdelay);
    Serial.println("electrical stimulation start");
    for (int i=1; i<=2; i++) {
     digitalWrite(stim_pin,HIGH);delay(1);digitalWrite(stim_pin,LOW);delay(1000/freq-1);
    }
    Serial.println("2 pulses over");
    Serial.println("--------------------");
    state=0;break;

    case '3': // 3 = 5 pulses
    Serial.println("imaging and 5 pulses");
    digitalWrite(image_pin,HIGH);digitalWrite(image_pin,LOW); //start imaging
    delay(stimdelay);
    Serial.println("electrical stimulation start");
    for (int i=1; i<=5; i++) {
     digitalWrite(stim_pin,HIGH);delay(1);digitalWrite(stim_pin,LOW);delay(1000/freq-1);
    }
    Serial.println("5 pulses over");
    Serial.println("--------------------");
    state=0;break;

    case '4': // 4 = 10 pulses
    Serial.println("imaging and 10 pulses");
    digitalWrite(image_pin,HIGH);digitalWrite(image_pin,LOW); //start imaging
    delay(stimdelay);
    Serial.println("electrical stimulation start");
    for (int i=1; i<=10; i++) {
     digitalWrite(stim_pin,HIGH);delay(1);digitalWrite(stim_pin,LOW);delay(1000/freq-1);
    }
    Serial.println("10 pulses over");
    Serial.println("--------------------");
    state=0;break;

    case '5': // 5 = 20 pulses
    Serial.println("imaging and 20 pulses");
    digitalWrite(image_pin,HIGH);digitalWrite(image_pin,LOW); //start imaging
    delay(stimdelay);
    Serial.println("electrical stimulation start");
    for (int i=1; i<=20; i++) {
     digitalWrite(stim_pin,HIGH);delay(1);digitalWrite(stim_pin,LOW);delay(1000/freq-1);
    }
    Serial.println("20 pulses over");
    Serial.println("--------------------");
    state=0;break;

    case '6': // 6 = 50 pulses
    Serial.println("imaging and 50 pulses");
    digitalWrite(image_pin,HIGH);digitalWrite(image_pin,LOW); //start imaging
    delay(stimdelay);
    Serial.println("electrical stimulation start");
    for (int i=1; i<=50; i++) {
     digitalWrite(stim_pin,HIGH);delay(1);digitalWrite(stim_pin,LOW);delay(1000/freq-1);
    }
    Serial.println("50 pulses over");
    Serial.println("--------------------");
    state=0;break;

    case '7': // 7 = 100 pulses
    Serial.println("imaging and 100 pulses");
    digitalWrite(image_pin,HIGH);digitalWrite(image_pin,LOW); //start imaging
    delay(stimdelay);
    Serial.println("electrical stimulation start");
    Serial.println("100 pulses start");
    for (int i=1; i<=100; i++) {
     digitalWrite(stim_pin,HIGH);delay(1);digitalWrite(stim_pin,LOW);delay(1000/freq-1);
    }
    Serial.println("100 pulses over");
    Serial.println("--------------------");
    state=0;break;

    case 'a': // a = 1hz
    Serial.println("imaging and 1 hz");
    digitalWrite(image_pin,HIGH);digitalWrite(image_pin,LOW); //start imaging
    delay(stimdelay);
    Serial.println("electrical stimulation start");
    for (int i=1; i<=pulse; i++) {
    digitalWrite(stim_pin,HIGH);delay(1);digitalWrite(stim_pin,LOW);delay(999);
    }
    Serial.println("1 hz over");
    Serial.println("--------------------");
    state=0;break;

   case 'b': // b = 2hz
    Serial.println("imaging and 2 hz");
    digitalWrite(image_pin,HIGH);digitalWrite(image_pin,LOW); //start imaging
    delay(stimdelay);
    Serial.println("electrical stimulation start");
    for (int i=1; i<=pulse; i++) {
    digitalWrite(stim_pin,HIGH);delay(1);digitalWrite(stim_pin,LOW);delay(499);
    }
    Serial.println("2 hz over");
    Serial.println("--------------------");
    state=0;break;

    case 'c': // c = 5hz
    Serial.println("imaging and 5 hz");
    digitalWrite(image_pin,HIGH);digitalWrite(image_pin,LOW); //start imaging
    delay(stimdelay);
    Serial.println("electrical stimulation start");
    for (int i=1; i<=pulse; i++) {
    digitalWrite(stim_pin,HIGH);delay(1);digitalWrite(stim_pin,LOW);delay(199);
    }
    Serial.println("5 hz over");
    Serial.println("--------------------");
    state=0;break;

    case 'd': // d = 10hz
    Serial.println("imaging and 10 hz");
    digitalWrite(image_pin,HIGH);digitalWrite(image_pin,LOW); //start imaging
    delay(stimdelay);
    Serial.println("electrical stimulation start");
    for (int i=1; i<=pulse; i++) {
    digitalWrite(stim_pin,HIGH);delay(1);digitalWrite(stim_pin,LOW);delay(99);
    }
    Serial.println("10 hz over");
    Serial.println("--------------------");
    state=0;break;

    case 'e': // e = 20hz
    Serial.println("imaging and 20 hz");
    digitalWrite(image_pin,HIGH);digitalWrite(image_pin,LOW); //start imaging
    delay(stimdelay);
    Serial.println("electrical stimulation start");
    for (int i=1; i<=pulse; i++) {
    digitalWrite(stim_pin,HIGH);delay(1);digitalWrite(stim_pin,LOW);delay(49);
    }
    Serial.println("20 hz over");
    Serial.println("--------------------");
    state=0;break;

    case 'f': // f = 50hz
    Serial.println("imaging and 50 hz");
    digitalWrite(image_pin,HIGH);digitalWrite(image_pin,LOW); //start imaging
    delay(stimdelay);
    Serial.println("electrical stimulation start");
    for (int i=1; i<=pulse; i++) {
    digitalWrite(stim_pin,HIGH);delay(1);digitalWrite(stim_pin,LOW);delay(19);
    }
    Serial.println("50 hz over");
    Serial.println("--------------------");
    state=0;break;

    case 'g': // g = 100hz
    Serial.println("imaging and 100 hz");
    digitalWrite(image_pin,HIGH);digitalWrite(image_pin,LOW); //start imaging
    delay(stimdelay);
    Serial.println("electrical stimulation start");
    for (int i=1; i<=pulse; i++) {
    digitalWrite(stim_pin,HIGH);delay(1);digitalWrite(stim_pin,LOW);delay(9);
    }
    Serial.println("100 hz over");
    Serial.println("--------------------");
    state=0;break;
  }
}
 
