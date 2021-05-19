#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include <LiquidCrystal_I2C.h> // Library for LCD

LiquidCrystal_I2C lcd(0x3F, 16, 2); // I2C address 0x27, 16 column and 2 rows
#define enter_button A0

void setup(){
    Serial.begin(9600);
    lcd.init(); //initialize the lcd
    lcd.backlight(); //open the backlight 
    randomSeed(analogRead(0));
    for(int i = 2; i < 6 ; i++)
      pinMode(i, INPUT);
    for(int i = 6; i < 14 ; i++)
      pinMode(i, OUTPUT);
    turn_off_leds();
}

char *generate_code(bool repeat, int lenght){
    if(lenght <= 0){
      char *code = NULL;
      return code;
    }
    int i;
    char *code = malloc((lenght+1) * sizeof(char));
    int num;
    if(repeat){
        for(i=0;i<lenght;i++){
//            num = rand()%10;
            code[i] = random(48, 58);
        }
    }
    else{
      for(i=0;i<lenght;i++){
            num = rand()%9;
            for(int j = 0; j < i;j++){
              //Serial.println(num);
              while(code[j] == (char)48 + num){
                num = rand()%9;
                j = 0;//ked na tretej pozicii vygeneruje cislo a bude rovnake ako na druhej tak vygeneruje na novo ale bude konvtrolovat len druhu poziciu nie prvu
              }
            }
            code[i] = (char)48 + num;
        }
    }
    code[i] = '\0';
    Serial.println(code);
    return code;
}
char *play_game(int c, char **hist){
  int pos = 0;
  char *code = malloc(4 * sizeof(char));
  code[0] = '0';
  code[1] = '0';
  code[2] = '0';
  code[3] = '0';
  code[4] = '\0';
  while(!digitalRead(enter_button)){
    if(digitalRead(2)){
      if(digitalRead(3)){
        pos += 1;
        code[0] -= 1;
        if(pos > c)
          pos=0;
          Serial.println(pos);
        render_history(hist, pos);
        }
      else if(digitalRead(4)){
         pos -= 1;
         code[0] -= 1;
          if(pos < 0)
            pos = c;
            Serial.println(pos);
         render_history(hist, pos);
      }
      code[0] += 1;
    }
    else if(digitalRead(3)){
      code[1] += 1;
    }
    else if(digitalRead(4)){
      code[2] += 1;
    }
    else if(digitalRead(5)){
      code[3] += 1;
    }
    for(int i = 0; i < 4; i++)
      if(code[i] > '9'){
        code[i] = '0';
      }
    delay(300);
    lcd.setCursor(0, 1);
    lcd.print(code);
  }
  return code;  
}
void render_leds(const int peg_a,const int peg_b){
   //6 8 10 12  RED
   //7 9 11 13  GREEN
   int i;
   for(i = 6;i <= (peg_a+2)*2; i+=2)
      digitalWrite(i,HIGH);
   if(peg_b != 0 && peg_a != 0)
      for(i=i+1 ;i <= ((peg_b +2.5)*2+peg_a+2); i+=2)
          digitalWrite(i,HIGH);
   else if(peg_b != 0 && peg_a == 0)
      for(i=7 ;i <= ((peg_b +2.5)*2); i+=2)
          digitalWrite(i,HIGH);
}
void turn_off_leds(){
  for(int i = 6; i < 14;i++){
    digitalWrite(i,LOW);
  }
}
char **render_history(char **history,int cyklus){
  char code[5];
  code[4] = '\0';
  for(int i=0; i < 4; i++){
    code[i] = history[cyklus][i];
  } 
  lcd.setCursor(0, 0);
  lcd.print(code);
}
void win(){
  lcd.setCursor(0, 0);
  lcd.print("Congrats");
  lcd.setCursor(0, 1);
  lcd.print("You win");
  for(int j = 0; j<3 ;j++){ 
    for(int i = 6;i<=13;i++){
      digitalWrite(i,HIGH);
      if(i == 6)
        digitalWrite(13,LOW);
      else
        digitalWrite(i-1,LOW);
      delay(150);
    }
  }
  digitalWrite(13,LOW);
  lcd.setCursor(0, 0);
  lcd.print("         ");
  lcd.setCursor(0, 1);
  lcd.print("       ");
}
void loop(){
    int podm = 0;
    const int pocet_pokusov = 10;
    char **history = NULL;
    char *secret = NULL;
    char *guess = NULL;
    history  = (char **)malloc(pocet_pokusov * sizeof(char *)); //kvoli vyjebanemu vypisu z minuleho nahravania 
    for(int i = 0;i < pocet_pokusov;i++)
      history[i] = (char *)malloc(4 * sizeof(char));
    for(int i = 0; i < pocet_pokusov;i++)
      free(history[i]);
    free(history);
    history  = (char **)malloc(pocet_pokusov * sizeof(char *));
    for(int i = 0;i < pocet_pokusov;i++)
      history[i] = (char *)malloc(4 * sizeof(char));
    
    int a = 0, b = 0, c = 0;
    
    secret = generate_code(false, 4);
    for(c=0;c< pocet_pokusov;c++){
      guess = play_game(c, history);
      podm = get_score(secret, guess);
      
      for(int i=0; i < 4; i++)
        history[c][i] = guess[i];    
      if(podm == 4 || peg_a == 4){
        win();
        break; 
        }
    }
    for(int i = 0; i < pocet_pokusov;i++)
      free(history[i]);
    free(history);
    free(secret);
    free(guess); 
    delay(1000);
}
int get_score(char *secret, char *guess){
    int peg_a = 0;
    int peg_b = 0;
    for(int i = 0;i<4;i++){
      for(int j = 0;j<4;j++){
        if(secret[i]==guess[j]){  //asi pointer
          if(i == j){
            peg_a+=1;
            i++;
            }
          else{
            peg_b+=1;
          }
        }
      }
    }
    turn_off_leds();
    Serial.println(peg_a);
    Serial.println(peg_b);
    render_leds(peg_a,peg_b);
    delay(300);
    return peg_a;
}
