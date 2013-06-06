int led1 = 4; //Czerwona dioda led LED1
int led2 = 3; //Czerwona dioda led LED2
int led3 = 2; //Czerwona dioda led LED3

int RGB_R = 13; //Dioda RGB - Kolor czerwony
int RGB_G = 12; //Dioda RGB - Kolor zielony
int RGB_B = 11; //Dioda RGB - Kolor niebieski

int button1 = 8; //Przycisk S1
int button2 = 7; //Przycisk S2
int button3 = 6; //Przycisk S3

void setup()
{
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);

  pinMode(RGB_R, OUTPUT);
  pinMode(RGB_G, OUTPUT);
  pinMode(RGB_B, OUTPUT);
  
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);  

  digitalWrite(RGB_R, LOW); 
  digitalWrite(RGB_G, LOW); 
  digitalWrite(RGB_B, LOW); 
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);  
}

void loop()
{
  testLed();
  testButton();
  
  delay(5000);
}

//Test podlaczenia ukladu. Wszystkie diody swieca sie przez 9sek.
void testLed()
{
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  digitalWrite(RGB_R, HIGH);
  delay(3000);
  digitalWrite(RGB_R, LOW);
  digitalWrite(RGB_G, HIGH);
  delay(3000);
  digitalWrite(RGB_G, LOW);
  digitalWrite(RGB_B, HIGH);
  delay(3000);
  digitalWrite(RGB_B, LOW); 
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
}

//Test podlaczenia ukladu. Przez 10sek mozna sprawdzic dzialanie przyciskow.
void testButton()
{
  int czas = 0;
  while(czas < 1000)
  {
     if(digitalRead(button1) == HIGH)
       digitalWrite(led1, HIGH);
     else
       digitalWrite(led1, LOW);
     if(digitalRead(button2) == HIGH)
       digitalWrite(led2, HIGH);
     else
       digitalWrite(led2, LOW);       
     if(digitalRead(button3) == HIGH)
       digitalWrite(led3, HIGH);
     else
       digitalWrite(led3, LOW);       
     delay(10);
     czas++;
    
   }
   digitalWrite(led1, LOW);
   digitalWrite(led2, LOW);
   digitalWrite(led3, LOW);    
}
