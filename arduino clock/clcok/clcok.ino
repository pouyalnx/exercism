#include <LiquidCrystal.h>
#include <Timer1.h>

#define Rs  1
#define R_W 0
#define EN  2
#define D4  4
#define D5  5
#define D6  6
#define D7  7
LiquidCrystal lcd(Rs, R_W, EN, D4, D5, D6, D7);


void setup() {
  // put your setup code here, to run once:
  
  pinMode(8, INPUT); // UP
  pinMode(9, INPUT); // DOWN
  pinMode(10, INPUT);// LEFT
  pinMode(11, INPUT);// RIGHT
  pinMode(12, INPUT);// ENTER

  startTimer1(1000000L);
  
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("digital clock");
  lcd.setCursor(0,1);
  lcd.print("951131010");
  delay(2000);
  lcd.clear();
}

///////////////////////////////////////////////////////
/////////////////time global varibles//////////////////
int sec_t,min_t,hour_t;
///////////////////////////////////////////////////////
int sec_s,min_s,hour_s;
char time_buffer[32];
///////////////////////////////////////////////////////
int update_time(uint8_t row,int time_diff,uint8_t force_update){
  int sec_d,min_d,hour_d,temp;
  if(sec_t!=sec_s || min_t!=min_s || hour_t!=hour_s || force_update){
    sec_s=sec_t;
    min_s=min_t;
    hour_s=hour_t;

    sec_d=sec_s;
    temp=min_s+hour_s*60+time_diff;
    if(temp<0) 
        temp+=24*60;
    min_d=temp%60;
    hour_d=temp/60;
  
      
    sprintf(time_buffer,"time: 2 %02d:%02d:%02d   ",hour_d,min_d,sec_d);
    lcd.setCursor(0,row);
    lcd.print(time_buffer);
    return 1;
  }
  return 0;
}
///////////////////////////////////////////////////////
ISR(timer1Event)
{
  resetTimer1();
  sec_t++;
  if(sec_t>=60){
     sec_t=0;
     min_t++;
    if(min_t>=60){
     min_t=0;
     hour_t++;
     if(hour_t>=24)
     hour_t=0;
  }
  }
}

///////////////////////////////////////////////////////
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4
#define OK 5

int get_keypad_val(){
  if(digitalRead(8)==0) return UP;
  if(digitalRead(9)==0) return DOWN;
  if(digitalRead(10)==0) return LEFT;
  if(digitalRead(11)==0) return RIGHT;
  if(digitalRead(12)==0) return OK;
  return 0;
}

int get_keypad(int time_diff){
  int key;
  while(1){
     update_time(1,time_diff,0);
     key=get_keypad_val();
     if(key){
      while(key==get_keypad_val()){
        update_time(1,time_diff,0);
      }
      return key;
     }
  }
}

///////////////////////////////////////////////////////
const char lcd_set_time_menu[3][20]={
  "    set:hour   >",
  "<   set:min    >",
  "<   set:sec     ",
};

void menu_set_time(){
  int menu_selector=0;
  int key;
  while(1){
    lcd.setCursor(0,0);
    lcd.print(lcd_set_time_menu[menu_selector]);
    key=get_keypad(0);
    switch(key){
      case UP:
        switch(menu_selector){
          case 0:
            hour_t=(hour_t+1)%24;
          break;
          case 1:
            min_t=(min_t+1)%60;
          break;
          case 2:
            sec_t=(sec_t+1)%60;
          break;                    
        }
        break;
      case DOWN:
        switch(menu_selector){
          case 0:
            hour_t=(hour_t-1)%24;
          break;
          case 1:
            min_t=(min_t-1)%60;
          break;
          case 2:
            sec_t=(sec_t-1)%60;
          break;                    
        }
        break;
      case  LEFT:
         if(menu_selector>0)  
            menu_selector--;
        break;
      case RIGHT:
         if(menu_selector<2)  
            menu_selector++;
        break;
      case OK:
        return ;
        break;                        
    }
  }  
}
///////////////////////////////////////////////////////
#define MENU_ITEM 21

const char lcd_menu[MENU_ITEM][20]={
  "<e  iran       >",
  "<   *setting*  >",
  "<   oman       >",  
  "<   germany    >", 
  "<   uae        >", 
  "<   italy      >", 
  "<   england    >", 
  "<   pakistan   >", 
  "<   turkey     >", 
  "<   china      >",
  "<   russia     >",
  "<   japan      >",
  "<   syria      >",
  "<   iraq       >",
  "<   france     >",
  "<   qatar      >",
  "<   india      >",
  "<   greece     >",
  "<   australia  >",
  "<   protebla   >",
  "<   ireland   s>",                     
};

const int lcd_time_diff[MENU_ITEM]={
  0,
  0,
  30,
  -2*60-30,
  30,
  -2*60-30,
  -2*60-30,
  1*60+30,
  -30,
  4*60+30,
  -30,
  5*60+30,
  -1*60-30,
  0,
  -2*60-30,
  -30,
  2*60,
  -1*60-30,
   6*60+30,
   -30,
  -3*60-30,        
  };

  
void loop() {
  int menu_selector=0;
  int key;
  sec_t=0;
  min_t=0;
  hour_t=0;
  sec_s=0;
  min_s=0;
  hour_s=-1;
  while(1){
    lcd.setCursor(0,0);
    lcd.print(lcd_menu[menu_selector]);
    update_time(1,lcd_time_diff[menu_selector],1);
    key=get_keypad(lcd_time_diff[menu_selector]);
    switch(key){
      case UP:
        //
        break;
      case DOWN:
        //
        break;
      case  LEFT:
         menu_selector=(menu_selector-1)%MENU_ITEM;
        break;
      case RIGHT:
        menu_selector=(menu_selector+1)%MENU_ITEM;
        break;
      case OK:
        if(menu_selector==1){
          menu_set_time();
        }
        break;                        
    }
  }
}
