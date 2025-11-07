// Projeto de dispositivo de detecção de movimento; 

// Display do LCD ;

#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd_1(32, 16, 12); // pino 02 sensor para o display; 

// Declaração dos pinos e componentes eletr}onicos:
int pirPin = 2; // Pino do sensor PIR movimento
int led01 = 12; // led verde 
int led02 = 13; // led vermelho
int buzzer = 11; // buzzer sonoro

// Variável para armazenar o estado do sensor;

int pirState = LOW; // O sensor começa sem nenhuma informação.
int val = 0; // leitura do pino do sensor

void setup() {

  // configuração do display LCD 16x2 i2c; 
  
  lcd_1.init();

  lcd_1.setCursor(0, 0);
  lcd_1.backlight();
  lcd_1.display();

 // Leds e sensor de movimento
  
  pinMode(pirPin, INPUT);   // define o pino do PIR como entrada
  pinMode(led01, OUTPUT);  // define o pino do LED como saída
  pinMode(led02, OUTPUT);  // define o pino do LED como saída
  pinMode (buzzer, OUTPUT);
 
 
}

void loop() {
  
  
   for (int i = 0; i<5; i++){
   
// Verificar o valor do sensor PIR para ver se detectou movimento   
 
  val = digitalRead (pirPin); // ler o sensor PIR. 
  
   while (val == HIGH) {
   
   
 // mensagem no LCD para o botão pressionado;
 
  lcd_1.setCursor(0, 0);
  lcd_1.print("Movimento");
  delay(2000); // Wait for 2000 millisecond(s)
  lcd_1.setCursor(0, 1);
  lcd_1.print("detectado!!!");
  delay(2000); // Wait for 2000 millisecond(s)
  lcd_1.clear();
     
// Para os leds e buzzers acionar; 
     
  digitalWrite (led01, LOW);
  
  digitalWrite (led02, HIGH); 
  delay (500);   
     
  digitalWrite (led01, LOW); 
  delay (500);  
     
   tone (buzzer,440);
    delay(50);
    noTone (buzzer);
    delay(50);

     // Descansar o sensor; 
     
  val = digitalRead (pirPin);
     
  delay (50);
       
 }
     
   
   }
           
//  mensagem do LCD inicialmente  
  lcd_1.setCursor(0, 0);
  lcd_1.print("Tudo certo");
  delay(2000); // Wait for 2000 millisecond(s)
  lcd_1.setCursor(0, 1);
  lcd_1.print("aqui...");
  delay(2000); // Wait for 2000 millisecond(s)
  lcd_1.clear();
  
   digitalWrite (led02, LOW);
   digitalWrite (led01, HIGH);
   delay (2000);
   
}
