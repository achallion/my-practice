int LED = 3;
int bright = 0;
int fade = 5;


void setup() {
  // put your setup code here, to run once:
  pinMode(LED,OUTPUT);
  


}

/*

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(LED,bright);
  bright = bright + fade;
  if(bright >= 255 || bright <= 0)
  {
    fade = -fade;
  }
  delay(30);
  
}*/

void loop()
{
  for(int i = 0; i <= 255; i+=5)
  {
    analogWrite(LED,i);
    delay(30);
  }
  for(int i = 255;i >= 0;i-=5)
  {
    analogWrite(LED,i);
    delay(30);
  }
}
