# 1 "C:\\Users\\BIgC46263347\\Desktop\\iranparvar\\arduino clock\\clcok\\clcok.ino"
# 2 "C:\\Users\\BIgC46263347\\Desktop\\iranparvar\\arduino clock\\clcok\\clcok.ino" 2
# 3 "C:\\Users\\BIgC46263347\\Desktop\\iranparvar\\arduino clock\\clcok\\clcok.ino" 2
# 11 "C:\\Users\\BIgC46263347\\Desktop\\iranparvar\\arduino clock\\clcok\\clcok.ino"
LiquidCrystal lcd(1, 0, 2, 4, 5, 6, 7);


void setup() {
  // put your setup code here, to run once:

  pinMode(8, 0x0); // UP
  pinMode(9, 0x0); // DOWN
  pinMode(10, 0x0);// LEFT
  pinMode(11, 0x0);// RIGHT
  pinMode(12, 0x0);// ENTER

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


    sprintf(time_buffer,"time: %02d:%02d:%02d   ",hour_d,min_d,sec_d);
    lcd.setCursor(0,row);
    lcd.print(time_buffer);
    return 1;
  }
  return 0;
}
///////////////////////////////////////////////////////

# 65 "C:\\Users\\BIgC46263347\\Desktop\\iranparvar\\arduino clock\\clcok\\clcok.ino" 3
extern "C" void __vector_13 /* Timer/Counter1 Overflow */ (void) __attribute__ ((signal,used, externally_visible)) ; void __vector_13 /* Timer/Counter1 Overflow */ (void)

# 66 "C:\\Users\\BIgC46263347\\Desktop\\iranparvar\\arduino clock\\clcok\\clcok.ino"
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






int get_keypad_val(){
  if(digitalRead(8)==0) return 1;
  if(digitalRead(9)==0) return 2;
  if(digitalRead(10)==0) return 3;
  if(digitalRead(11)==0) return 4;
  if(digitalRead(12)==0) return 5;
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
      case 1:
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
      case 2:
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
      case 3:
         if(menu_selector>0)
            menu_selector--;
        break;
      case 4:
         if(menu_selector<2)
            menu_selector++;
        break;
      case 5:
        return ;
        break;
    }
  }
}
///////////////////////////////////////////////////////


const char lcd_menu[21][20]={
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

const int lcd_time_diff[21]={
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
      case 1:
        //
        break;
      case 2:
        //
        break;
      case 3:
         menu_selector=(menu_selector-1)%21;
        break;
      case 4:
        menu_selector=(menu_selector+1)%21;
        break;
      case 5:
        if(menu_selector==1){
          menu_set_time();
        }
        break;
    }
  }
}
