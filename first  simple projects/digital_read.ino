void setup()
{
    pinMode(2, OUTPUT);
    serial.begin(9600);    
}

void loop()
{
    int key=digitalRead(2);
    serial.printIn(key);

    delay(100);
}
