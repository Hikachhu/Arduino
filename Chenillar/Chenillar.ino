int led[10] = {4,5,6,7,8,9,10,11,12,13};
int timer = 100;
int Etat=0;
int enable = 2;
int disable = 3;
int play=0;

boolean etatStart;
boolean etatStop;

void setup() {
  Serial.begin(9600);
  
  pinMode(enable, INPUT);
  pinMode(disable, INPUT);
  
  for(int i = 0; i < 10; i++){
    pinMode(led[i], OUTPUT);
  }
}

void loop()
{
  etatStart = digitalRead(enable);
  etatStop = digitalRead(disable);
  
  if(etatStart == HIGH && etatStop == LOW)
  {
    play = 1;
  }
  
  Serial.print(play);
  Serial.print('\n');
  
  for(int i=0;i<10 && play == 1;i++)
  {
    etatStart = digitalRead(enable);
    etatStop = digitalRead(disable);
    
    if(etatStart == LOW && etatStop == HIGH)
    {
      play = 0;
    }
    
    digitalWrite(led[i],HIGH);
    delay(timer);
    digitalWrite(led[i],LOW);
  }
}
