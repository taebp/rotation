
int photoInterruptor = 12;
int Motor = 75;
int rotation = 0;
int interval = 60000;
int base_rpm = 1500;
int rpm;
int flag;
void setup() {
  // put your setup code here, to run once:
   pinMode(photoInterruptor,INPUT);
   pinMode(Motor,OUTPUT);
   Serial.begin(9600);
   attachInterrupt(photoInterruptor, counting_rotations, LOW);
}
void counting_rotations(){
  rotation++;
}

int count_rpm()
{
  rpm = rotation * 60;
  return rpm;
}
void slow_down()
{
  
  while(true){
    int a = count_rpm();
    digitalWrite(Motor, HIGH);
    delay(100);
    digitalWrite(Motor, LOW);
    delay(100);
    if(a < base_rpm){break;}
    
  }
}
void speed_up()
{

  while(true){
    int a = count_rpm();
    digitalWrite(Motor, HIGH);
    delay(50);
    digitalWrite(Motor, LOW);
    delay(50);
    if(a > base_rpm ){break;}
  }
}
int change_rpm(int newrpm){
  base_rpm = newrpm;
  return base_rpm;
}

void loop() {
  // put your main code here, to run repeatedly: 
  rotation = 0;
  delay(1000); // take measurement every second
  rpm = count_rpm();
  
  if( rpm < base_rpm ){ speed_up(); }
  if( rpm > base_rpm ){ slow_down();}
  Serial.println("RPM : ");
  Serial.print(rpm); // 
}
