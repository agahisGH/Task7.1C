// Including the necessary libraries for application
#include <SoftwareSerial.h>
#include <ArduinoBlue.h>

// MOTOR A (right side)
int in1 = 13;
int in2 = 12;

// MOTOR B (left side)
int in3 = 11;
int in4 = 10;

// Bluetooth TX in the Arduino D8 pin
const int BLUETOOTH_TX = 8;

// Bluetooth RX in the Arduino D7 pin
const int BLUETOOTH_RX = 7;

SoftwareSerial bluetooth(BLUETOOTH_TX, BLUETOOTH_RX);
ArduinoBlue phone(bluetooth); // passes the reference of the bluetooth object, to the ArduinoBlue constructor (application)

void setup()
{
    // Starts serial monitor at 9600 bps
    Serial.begin(9600);

    // Starts bluetooth serial at 9600 bps
    bluetooth.begin(9600);

    // Delay 100ms (0.1 sec) just in case the bluetooth module needs a bit of time to get ready
    delay(100);

    // Prints a message in serial to confirm it's ready to go
    Serial.println("setup is now complete.");

    // Sets up all motor pins as output
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);
}

// Moves both motors forwards
void moveForward()
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

// Moves left motor forwards
void moveLeft()
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

// Moves right motor forwards
void moveRight()
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

// Turn off all motors
void moveStop()
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

void loop()
{
    // Returns the text data sent from the phone
    // After it returns the latest data, empty string "" is sent in subsequent and calls until text data is sent again
    String str = phone.getText();

    // If a text from the phone "Forward" is received, move robot forwards, and print movement command in serial monitor
    if (str == "Forward")
    {
        Serial.println(str);
        moveForward();
    }

    // If a text from the phone "Left" is received, move robot towards left direction, and print movement command in serial monitor
    if (str == "Left")
    {
        Serial.println(str);
        moveLeft();
    }

    // If a text from the phone "Right" is received, move robot towards right direction, and print movement command in serial monitor
    if (str == "Right")
    {
        Serial.println(str);
        moveRight();
    }

    // If a text from the phone "Stop" is received, stop robot movement, and print movement command in serial monitor
    if (str == "Stop")
    {
        Serial.println(str);
        moveStop();
    }
}
