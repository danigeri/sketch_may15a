int ledpin=11;
int STARTPIN=8;
int STOPPIN=9;
int val;// define val

bool RUNNING = true;

void setup()
{
pinMode(ledpin,OUTPUT);// set LED pin as “output”
pinMode(STARTPIN,INPUT);
pinMode(STOPPIN,INPUT);
}
void loop()
{
  if(digitalRead(STARTPIN) == HIGH)
  {
    RUNNING = true;
  }
  else if(digitalRead(STOPPIN) == HIGH)
  {
    RUNNING = false;
  }
  else if(RUNNING)
  {
    digitalWrite(ledpin,HIGH);
  }
  else
  {
    digitalWrite(ledpin,LOW);
  }
 

  
  /*val=digitalRead(inpin);// read the level value of pin 7 and assign if to val
  if(val==LOW)// check if the button is pressed, if yes, turn on the LED
  { digitalWrite(ledpin,LOW);}
  else
  { digitalWrite(ledpin,HIGH);}*/

}
