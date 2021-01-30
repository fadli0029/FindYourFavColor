//Assigning the Pin for each color of your RGB
int RGB_RedPin = 3;
int RGB_GreenPin = 5;
int RGB_BluePin = 6; 
 
void setup() 
{ 
 Serial.begin(9600); // initialize serial communications at 9600 bps
 //Tell the Arduino that our RGB LED is the output
 pinMode(RGB_RedPin, OUTPUT);
 pinMode(RGB_GreenPin, OUTPUT);
 pinMode(RGB_BluePin, OUTPUT);
}
 
void loop() 
{  
 int Potentiometer_RedPin = analogRead(A0); 
 //tell the arduino to read the voltage across the wiper terminal of our potentiometer at the Analog pin as stated
 int PWM_RedPin = Potentiometer_RedPin/4;
 //We divide by 4 to convert the values to the 0-255 range 
 //since we are using arduino mega which has PWM function of 0-255 range 
 //isntead of the 10-bit ADC resolution 0-1023
 int Potentiometer_GreenPin = analogRead(A1);
 int PWM_GreenPin = Potentiometer_GreenPin/4;
 int Potentiometer_BluePin = analogRead(A2);
 int PWM_BluePin = Potentiometer_BluePin/4;

 
 //Use this if your RGB LED is COMMON CATHODE
 analogWrite(RGB_RedPin, PWM_RedPin);
 analogWrite(RGB_GreenPin, PWM_GreenPin);
 analogWrite(RGB_BluePin, PWM_BluePin);
 
 
 //Use this code for RGB LED is COMMON ANODE
 /*analogWrite(RGB_RedPin, 255-PWM_RedPin);
 analogWrite(RGB_GreenPin, 255-PWM_GreenPin);
 analogWrite(RGB_BluePin, 255-PWM_BluePin);
 */
 delay(2);
}
