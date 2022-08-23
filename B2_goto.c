
int TTCT = 0;

byte ledpin[] = {2,3,4,5,6,7,8,9};
byte pinCount;
int solan =0;

void off8led(){
  for(int i =0 ;i<8;i++)
     digitalWrite(ledpin[i],LOW);
}


void choptatled()
{
  if(solan<20)
  {
    for(int i =0 ;i<8;i++)
        digitalWrite(ledpin[i],HIGH);
    delay(500);
    for(int i =0 ;i<8;i++)
        digitalWrite(ledpin[i],LOW);
    delay(500);
    if (solan == 10 && digitalRead(11) == HIGH)
    {
      off8led();
      TTCT =1;
      Serial.println("chuyen sang ct2");
      solan =0;
    }
  }
  else{
        off8led();
        solan = 0;
  }
  solan++;
  Serial.print("so lan dem ct1 :");
  Serial.println(solan);
}

void sang_duoi_8led()
{
  if (solan<5)
  {
    digitalWrite(ledpin[0],HIGH);
    delay(100);
    digitalWrite(ledpin[0],LOW);
   //
    digitalWrite(ledpin[1],HIGH);
    delay(100);
    digitalWrite(ledpin[1],LOW);
    //
    digitalWrite(ledpin[2],HIGH);
    delay(100);
    digitalWrite(ledpin[2],LOW);
    //
    digitalWrite(ledpin[3],HIGH);
    delay(100);
    digitalWrite(ledpin[3],LOW);
    //
    digitalWrite(ledpin[4],HIGH);
    delay(100);
    digitalWrite(ledpin[4],LOW);
    //
    digitalWrite(ledpin[5],HIGH);
    delay(100);
    digitalWrite(ledpin[5],LOW);
    //
    digitalWrite(ledpin[6],HIGH);
    delay(100);
    digitalWrite(ledpin[6],LOW);
    //
    digitalWrite(ledpin[7],HIGH);
    delay(100);
    digitalWrite(ledpin[7],LOW);

    if(digitalRead(10)==HIGH && solan == 2)
    {
      off8led();
      TTCT = 0;
      solan =0;
      Serial.println("chuyen sang ct1");
    }
  }
  else
  {
    off8led();
    solan =0;
  }
  solan++;
  Serial.print("so lan dem ct2 :");
  Serial.println(solan);
}
int tatled()
{
  if (digitalRead(12) == HIGH)
  {
    off8led();
    TTCT = 0;
    solan = 0;
  }
}
void setup() {
  Serial.begin(9600);   
  pinMode(10, INPUT);
  pinMode(11, INPUT);
  pinMode(12, INPUT_PULLUP);

  pinCount = sizeof(ledpin);  
  for (int i=0;i<pinCount;i++) {
    pinMode(ledpin[i],OUTPUT);  
    digitalWrite(ledpin[i],LOW); 
  }
  while(1)
  {
    if(TTCT == 0)
    {
      
      choptatled();
      if (digitalRead(12) == LOW)
      {
        Serial.println("ok");
        off8led();
//      TTCT = 0;
        solan = 0;
        goto thoat;
      }
    }
    else if (TTCT == 1)
    {
      sang_duoi_8led();
      if (digitalRead(12) == LOW)
      {
        Serial.println("ok");
        off8led();
        TTCT = 0;
        solan = 0;
        goto thoat;
      }
    }

  }
thoat:
Serial.println("thoat khoi chuong trinh");
}

void loop() {
                               //Chờ 200ms
}
