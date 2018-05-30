#define M1Rpwm 6
#define M1Lpwm 5
#define M2Rpwm 9
#define M2Lpwm 10
#define Lled 7
#define Rled 13

char data = 0;            //Variable for storing received data

void setup()
{
  Serial.begin(9600);   //Sets the baud for serial data transmission
  pinMode(M1Rpwm, OUTPUT);
  pinMode(M1Lpwm, OUTPUT);
  pinMode(M2Rpwm, OUTPUT);
  pinMode(M2Lpwm, OUTPUT);
  pinMode(Lled, OUTPUT);
  pinMode(Rled, OUTPUT);
}
void loop()
{
  if (Serial.available() > 0)     // Send data only when you receive data:
  {
    data = Serial.read();        //Read the incoming data & store into data

    /*
     * *****************************************************************************************************
       Drive Mode
     * *****************************************************************************************************
    */
    if (data == '1')
    {
      switch (data)
      {
        case 'f':                   //Case to move forward
          digitalWrite(Rled, LOW);
          digitalWrite(Lled, LOW);
          analogWrite(M1Rpwm, 0);
          analogWrite(M1Lpwm, 255);
          analogWrite(M2Rpwm, 0);
          analogWrite(M2Lpwm, 255);
          break;

        case 'b':                   // case to move backwards
          digitalWrite(Rled, LOW);
          digitalWrite(Lled, LOW);
          analogWrite(M1Rpwm, 255);
          analogWrite(M1Lpwm, 0);
          analogWrite(M2Rpwm, 255);
          analogWrite(M2Lpwm, 0);
          break;

        case 'l':                   // case to turn left
          digitalWrite(Lled, HIGH);
          digitalWrite(Rled, LOW);
          analogWrite(M1Rpwm, 0);
          analogWrite(M1Lpwm, 255);
          analogWrite(M2Rpwm, 255);
          analogWrite(M2Lpwm, 0);
          break;

        case 'r':                   // case to turn right
          digitalWrite(Lled, LOW);
          digitalWrite(Rled, HIGH);
          analogWrite(M1Rpwm, 255);
          analogWrite(M1Lpwm, 0);
          analogWrite(M2Rpwm, 0);
          analogWrite(M2Lpwm, 255);
          break;

        case 's':                   // case to stop
          digitalWrite(Rled, LOW);
          digitalWrite(Lled, LOW);
          analogWrite(M1Rpwm, 0);
          analogWrite(M1Lpwm, 0);
          analogWrite(M2Rpwm, 0);
          analogWrite(M2Lpwm, 0);
          break;

        default:                    // default case
          break;
      }
    }

    /*
    * *****************************************************************************************************
      Crane Mode
    * *****************************************************************************************************
    */
    if (data == '2')
    {
      switch (data)
      {
        case 'l':                   // case to turn left
          break;

        case 'r':                   // case to turn right
          break;

        case 'u':                   // case to move up
          break;

        case 'd':                   // case to move down
          break;

        case 'o':                   // case to open the claw
          break;

        case 'c':                   // case to close the claw
          break;

        default:                    // default case
          break;

      }
    }
  }
}

