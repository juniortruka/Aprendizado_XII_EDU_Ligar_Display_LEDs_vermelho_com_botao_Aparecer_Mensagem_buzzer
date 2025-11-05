#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd_1(32, 16, 2);

// Pino do botão
const int botaoPin = 2;
int led01 = 13;
int led02 = 10;
int buzzer = 12; 
int val = 0; 

void setup() {
  
  // Inicializa o LCD e configuração 
  
 lcd_1.init();

  lcd_1.setCursor(0, 0);
  lcd_1.backlight();
  lcd_1.display();
  
  
// Demais componentes: 
  
  pinMode (botaoPin, INPUT);
  pinMode (led01, OUTPUT);
  pinMode (led02, OUTPUT);
  pinMode (buzzer, OUTPUT);
  
  
  
  
}

void loop() {
  
  
   for (int i = 0; i<5; i++){
   
   
   val = digitalRead (botaoPin);
  
   while (val == HIGH) {
   
   
 // mensagem no LCD para o botão pressionado;
 
  lcd_1.setCursor(0, 0);
  lcd_1.print("Botao");
  delay(2000); // Wait for 2000 millisecond(s)
  lcd_1.setCursor(0, 1);
  lcd_1.print("pressionado!!!");
  delay(2000); // Wait for 2000 millisecond(s)
  lcd_1.clear();
     
// Para os leds e buzzers acionar; 
     
  digitalWrite (led02, LOW);
  
  digitalWrite (led01, HIGH); 
  delay (500);   
     
  digitalWrite (led01, LOW); 
  delay (500);  
     
   tone (buzzer,440);
    delay(50);
    noTone (buzzer);
    delay(50);
  
  val = digitalRead (botaoPin);
     
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
  
   digitalWrite (led01, LOW);
   digitalWrite (led02, HIGH);
   delay (2000);
   
}
