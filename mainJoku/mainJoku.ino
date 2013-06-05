int led1 = 4; //Czerwona dioda led LED1
int led2 = 3; //Czerwona dioda led LED2
int led3 = 2; //Czerwona dioda led LED3

int RGB_R = 13; //Dioda RGB - Kolor czerwony
int RGB_B = 12; //Dioda RGB - Kolor niebieski
int RGB_G = 11; //Dioda RGB - Kolor zielony

int button1 = 8; //Przycisk S1
int button2 = 7; //Przycisk S2
int button3 = 6; //Przycisk S3

void setup()
{
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);

  pinMode(RGB_R, OUTPUT);
  pinMode(RGB_B, OUTPUT);
  pinMode(RGB_G, OUTPUT);
  
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);  
}

void loop()
{
  
}
