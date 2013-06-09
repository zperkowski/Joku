int led1 = 4; //Czerwona dioda led LED1
int led2 = 3; //Czerwona dioda led LED2
int led3 = 2; //Czerwona dioda led LED3

int RGB_R = 13; //Dioda RGB - Kolor czerwony
int RGB_G = 12; //Dioda RGB - Kolor zielony
int RGB_B = 11; //Dioda RGB - Kolor niebieski

int button1 = 8; //Przycisk S1
int button2 = 7; //Przycisk S2
int button3 = 6; //Przycisk S3

int buzzer = 10; //Glosnik

void setup()
{
  //Ewentualny podglad danych dla programisty
  Serial.begin(9600);
  
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);

  pinMode(RGB_R, OUTPUT);
  pinMode(RGB_G, OUTPUT);
  pinMode(RGB_B, OUTPUT);
  
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);  
  
  pinMode(buzzer, OUTPUT);

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
  testBuzzer();
  while(true)
  {
    gra();
    delay(5000);
  }
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
     {
       digitalWrite(led1, HIGH);
       buzz(1);
     }
     else
         digitalWrite(led1, LOW);
     if(digitalRead(button2) == HIGH)
     {
       digitalWrite(led2, HIGH);
       buzz(1);
     }
     else
       digitalWrite(led2, LOW);       
     if(digitalRead(button3) == HIGH)
     {
       digitalWrite(led3, HIGH);
       buzz(1);
     }
     else
       digitalWrite(led3, LOW);       
     delay(10);
     czas++;
    
   }
   digitalWrite(led1, LOW);
   digitalWrite(led2, LOW);
   digitalWrite(led3, LOW);    
}

void testBuzzer()
{
  for (int j = 0; j<3; j++)
  {
    for (int buzz = 0; buzz<100; buzz++)
    {
      digitalWrite(buzzer, HIGH);
      delay(1);
      digitalWrite(buzzer, LOW);
      delay(1);
    }
    delay(300);
  }
}

void buzz(int melodia) //funkcja zawiera zestaw melodii buzzera.
{
  switch (melodia)
  {
    case 1: //melodia przy wcisnieciu guzika podczas gry
    {
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH);      
      for (int z = 0; z<300; z++)
      {
        digitalWrite(buzzer, HIGH);
        delay(1);
        digitalWrite(buzzer, LOW);
        delay(1);
      }
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);     
      delay(400);      
    } break;
    case 2: //melodia przy wygranej
    {
      for (int z1 = 0; z1<3; z1++)
      {
        for (int z2 = 0; z2<300; z2++)
        {
          digitalWrite(buzzer, HIGH);
          delayMicroseconds(100);
          digitalWrite(buzzer, LOW);
          delayMicroseconds(100);
        }
        delay(300);
      }
    } break;
    case 3: // melodia przy przegranej
    {
      for (int z = 0; z<300; z++)
      {
        digitalWrite(buzzer, HIGH);
        delay(3);
        digitalWrite(buzzer, LOW);
        delay(3);
      }
    }
  }
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led2, LOW); 
}

void gra()
{
  //Przechowuje podana ilosc poziomow rozgrywki
  const int poziomy = 6;
  /*
  *  Ze wzgledu na to, ze łatwo wyjsc poza zakres tablicy podajac wlasnorecznie wartosci
  *  zmiennych poziomy i x, program sam oblicza x - odpowiednia wielkosc tablicy
  */
  int dlTab = 0;
  for(unsigned int i = 0; i < poziomy; i++)
    for(unsigned int j = 0; j <= i; j++)
      dlTab++;
  //Tablica zawierajaca wylosowane diody      
  int tab[dlTab];
  
  //Tablica odpowiedzi gracza
  int graczTab[dlTab];
  
  //Losowanie zawartosci tablicy tab[]. Mozliwe wylosowane liczby: 1, 2, 3
  for(unsigned int i = 0; i < dlTab; i++)
    tab[i] = random(1, 4);
    
   /*
   //W tym miejscu mozna wypisac tablice, ktora bedzie
   //podstawa do kolejnosci swiecenia diod - pomoc dla programi
   for(unsigned int i = 0; i < dlTab; i++)
    Serial.println(tab[i]);
   */
  delay(1000);
  //Sprawdza czy gracz sie pomylil
  bool przegrana = false;
  int x = 0;
  int y = 0;
  //Glowna czesc rozgrywki - przerywana jest gdy skoncza sie poziomy
    for(unsigned int i = 0; i < poziomy; i++)
    {
      for(unsigned int j = 0; j <= i; j++)
      {
        if(tab[x] == 1)
          digitalWrite(led1, HIGH);
        else if(tab[x] == 2)
          digitalWrite(led2, HIGH);
        else if(tab[x] == 3)
          digitalWrite(led3, HIGH);
          
        delay(850);
        
        digitalWrite(led1, LOW);
        digitalWrite(led2, LOW);
        digitalWrite(led3, LOW);        

        delay(850);        
        x++;
      }
                   
      //Oczekiwanie na wprowadzenie sekwencji zapamietanej przez gracza
      for(unsigned int k = 0; k <= i; k++)
      {
        while(k <= i){
          if(digitalRead(button1) == HIGH)
          {
           buzz(1);
           graczTab[y] = 1;
           break;
          }
          else if(digitalRead(button2) == HIGH)
          {
           buzz(1);
           graczTab[y] = 2;
           break;
          }
          else if(digitalRead(button3) == HIGH)
          {
           buzz(1);
           graczTab[y] = 3;
           break;
          }
          delay(150);
        }
        y++;
      }
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);     
      
    }
    
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    
    Serial.println("-");
    for(unsigned int i = 0; i < dlTab; i++)
      Serial.println(graczTab[i]);
    delay(300);
  
  for(unsigned int i = 0; i < dlTab; i++)
    if(tab[i] != graczTab[i])
      przegrana = true;
  
  if(przegrana)
  {
    Serial.println("Przegrales");
    digitalWrite(RGB_R, HIGH);
    buzz(3);
  }
  else if(!przegrana)
  {
    Serial.println("Wygrales");
    digitalWrite(RGB_G, HIGH);
    buzz(2);
  }
  delay(1000);
  digitalWrite(RGB_R, LOW);
  digitalWrite(RGB_G, LOW);
}

