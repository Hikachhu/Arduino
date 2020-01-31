int led[5] = {4,5,6,7,8};
int timer = 100;
int vert = 2;
int rouge = 3;
boolean a;
boolean b;
boolean Et,Ou,Nor,Nand,Xor;

void setup() {
  
  for(int i = 0; i < 5; i++){
    pinMode(led[i], OUTPUT);
  }

}

void loop() {
  a = digitalRead(vert);
  b = digitalRead(rouge);
  if(a&&b){
    digitalWrite(led[0],HIGH);
  }
  if(a||b){
    digitalWrite(led[1],HIGH);
  }
  if(!(a||b)){
    digitalWrite(led[2],HIGH);
  }
  if(!(a&&b)){
    digitalWrite(led[3],HIGH);
  }
  if(a!=b){
    digitalWrite(led[4],HIGH);
  }
  delay(250);
  for(int i=0;i<5;i++){
    digitalWrite(led[i],LOW);
  }
}
