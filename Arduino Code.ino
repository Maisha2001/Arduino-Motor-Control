// L293d IC Connection
int enablePin1 = 11;
int in1Pin = 10;
int in2Pin = 9;
int enablePin2 = 3;
int in3Pin = 5;
int in4Pin = 6;
// DIP 4 Switch Connection
int switchPin1 = 8;
int switchPin2 = 7;
int switchPin3 = 4;
int switchPin4 = 2;
// Potentio meter connection
int potPin = 0;
// Switch status will be stored digitally in following integer variable
int switchPin1status;
int switchPin2status;
int switchPin3status;
int switchPin4status;

void setup()
{
	// Pinmode as an input or output 
  	pinMode(in1Pin, OUTPUT);
	pinMode(in2Pin, OUTPUT);
	pinMode(in3Pin, OUTPUT);
	pinMode(in4Pin, OUTPUT);
	pinMode(enablePin1, OUTPUT);
	pinMode(enablePin2, OUTPUT);
  	// Switch input as an input pullup
	pinMode(switchPin1, INPUT_PULLUP);
	pinMode(switchPin2, INPUT_PULLUP);
	pinMode(switchPin3, INPUT_PULLUP);
	pinMode(switchPin4, INPUT_PULLUP);
}
void loop()
{
	int speed = analogRead(potPin)/4; // Analog reading from the potentiometer as per the need we can divide analog reading by integer here it is divided by 4.
	// Following 4 line is used to read digital value from DIP4 switch and store in integer respectively.
  	switchPin1status=digitalRead(switchPin1);
	switchPin2status=digitalRead(switchPin2);
	switchPin3status=digitalRead(switchPin3);
	switchPin4status=digitalRead(switchPin4); 
	// if DIP switch1 is on then here it will be detected as active low and remaining will remain as an active high
	// here we will call function setMotorforward by passing speed.
	if(switchPin1status==0 && switchPin2status==1 && switchPin3status==1 && switchPin4status==1)
		{setMotorforward(speed);}
	// if DIP switch2 is on then here it will be detected as active low and remaining will remain as an active high
	// here we will call function setMotorreverse to run motor backward by passing speed.  
  	else if(switchPin1status==1 && switchPin2status==0 && switchPin3status==1 && switchPin4status==1)
		{setMotorreverse(speed);}
	// if DIP switch3 is on then here it will be detected as active low and remaining will remain as an active high
	// here we will call function setMotorright by passing speed.  
  	else if(switchPin1status==1 && switchPin2status==1 && switchPin3status==0 && switchPin4status==1)
		{setMotorright(speed);}
	// if DIP switch4 is on then here it will be detected as active low and remaining will remain as an active high
	// here we will call function setMotorleft by passing speed.
  	else if(switchPin1status==1 && switchPin2status==1 && switchPin3status==1 && switchPin4status==0)
		{setMotorleft(speed);}
	// if any switch is not on or any two or more switch is on which leads to stop all motor
	// here we will call function setMotorstop
  	else
		{setMotorstop(speed);}

}
// Function to move motor forward both motor will rotate in forward direction
void setMotorforward(int speed)
{
analogWrite(enablePin1, speed);
analogWrite(enablePin2, speed);
digitalWrite(in1Pin, HIGH);// Motor1 move in forward direction
digitalWrite(in2Pin, LOW);
digitalWrite(in3Pin, HIGH);// Motor2 move in forward direction
digitalWrite(in4Pin, LOW);
}
// Function to move motor backward both motor will rotate in backward direction
void setMotorreverse(int speed)
{
analogWrite(enablePin1, speed);
analogWrite(enablePin2, speed);
digitalWrite(in1Pin, LOW);// Motor1 move in reverese direction
digitalWrite(in2Pin, HIGH);
digitalWrite(in3Pin, LOW);// Motor2 move in reverese direction
digitalWrite(in4Pin, HIGH);
}
// Function to move motor right.
void setMotorright(int speed)
{
analogWrite(enablePin1, speed);
analogWrite(enablePin2, speed);
digitalWrite(in1Pin, HIGH);// Motor1 move in forward direction
digitalWrite(in2Pin, LOW);
digitalWrite(in3Pin, LOW);// Motor2 move in reverese direction
digitalWrite(in4Pin, HIGH);
}
// Function to move motor Left
void setMotorleft(int speed)
{
analogWrite(enablePin1, speed);
analogWrite(enablePin2, speed);
digitalWrite(in1Pin, LOW);// Motor1 move in reverese direction
digitalWrite(in2Pin, HIGH);
digitalWrite(in3Pin, HIGH);// Motor2 move in forward direction
digitalWrite(in4Pin, LOW);
}
// Function to stop motor
void setMotorstop(int speed)
{
speed=0; // to stop motor we are passing speed with 0 value.
analogWrite(enablePin1, speed);
analogWrite(enablePin2, speed);
}