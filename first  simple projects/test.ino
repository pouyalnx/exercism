#include <LiquidCrystal.h>
#include <Keypad.h>

#define Rs  1
#define R_W 0
#define EN  2
#define D4  4
#define D5  5
#define D6  6
#define D7  7
LiquidCrystal lcd(Rs, R_W, EN, D4, D5, D6, D7);



#define ROWS 4
#define COLS 4
byte rowPins[ROWS] = { 49,48, 47, 46 };
byte colPins[COLS] = { 53, 52, 51, 50 };

char keys[ROWS][COLS] =
  {
    { '1', '2', '3', 'A', },
    { '4', '5', '6', 'B', },
    { '7', '8', '9', 'c', },
    { '*', '0', '#', 'D'  }
  };


Keypad kpd = Keypad (makeKeymap (keys), rowPins, colPins, ROWS, COLS);


///////////////////////////////////////////////////////////////////////////////////////////


#define MAX_map_addr_to_pinchip_lookup_table 102
char map_addr_to_pinchip_lookup_table[MAX_map_addr_to_pinchip_lookup_table][2]={
/* name:x led:x value:x*/   { 0,0 } ,
/* name:V+ led:1 value:1*/ { 2,1 } ,
/* name:V- led:1 value:2*/ { 2,2 } ,
/* name:R+ led:1 value:3*/ { 2,3 } ,
/* name:R- led:1 value:4*/ { 2,4 } ,
/* name:GND led:1 value:5*/ { 2,5 } ,
/* name:V+ led:2 value:6*/ { 2,6 } ,
/* name:V- led:2 value:7*/ { 2,7 } ,
/* name:R+ led:2 value:8*/ { 2,8 } ,
/* name:R- led:2 value:9*/ { 2,9 } ,
/* name:GND led:2 value:10*/ { 2,10 } ,
/* name:V+ led:3 value:11*/ { 2,11 } ,
/* name:V- led:3 value:12*/ { 2,12 } ,
/* name:R+ led:3 value:13*/ { 2,13 } ,
/* name:R- led:3 value:14*/ { 2,14 } ,
/* name:GND led:3 value:15*/ { 2,15 } ,
/* name:V+ led:4 value:16*/ { 2,16 } ,
/* name:V- led:4 value:17*/ { 2,17 } ,
/* name:R+ led:4 value:18*/ { 2,20 } ,
/* name:R- led:4 value:19*/ { 2,21 } ,
/* name:GND led:4 value:20*/ { 2,22 } ,
/* name:V+ led:5 value:21*/ { 2,23 } ,
/* name:V- led:5 value:22*/ { 2,24 } ,
/* name:R+ led:5 value:23*/ { 2,25 } ,
/* name:R- led:5 value:24*/ { 2,26 } ,
/* name:GND led:5 value:25*/ { 2,27 } ,
/* name:V+ led:6 value:26*/ { 2,28 } ,
/* name:V- led:6 value:27*/ { 2,29 } ,
/* name:R+ led:6 value:28*/ { 2,30 } ,
/* name:R- led:6 value:29*/ { 2,31 } ,
/* name:GND led:6 value:30*/ { 2,32 } ,
/* name:V+ led:7 value:31*/ { 2,33 } ,
/* name:V- led:7 value:32*/ { 2,34 } ,
/* name:R+ led:7 value:33*/ { 2,35 } ,
/* name:R- led:7 value:34*/ { 2,36 } ,
/* name:GND led:7 value:35*/ { 2,37 } ,
/* name:V+ led:8 value:36*/ { 2,38 } ,
/* name:V- led:8 value:37*/ { 2,39 } ,
/* name:R+ led:8 value:38*/ { 2,40 } ,
/* name:R- led:8 value:39*/ { 2,41 } ,
/* name:GND led:8 value:40*/ { 2,42 } ,
/* name:V+ led:9 value:41*/ { 2,43 } ,
/* name:V- led:9 value:42*/ { 2,44 } ,
/* name:R+ led:9 value:43*/ { 2,45 } ,
/* name:R- led:9 value:44*/ { 2,46 } ,
/* name:GND led:9 value:45*/ { 2,47 } ,
/* name:V+ led:10 value:46*/ { 2,48 } ,
/* name:V- led:10 value:47*/ { 2,49 } ,
/* name:R+ led:10 value:48*/ { 2,50 } ,
/* name:R- led:10 value:49*/ { 2,51 } ,
/* name:GND led:10 value:50*/ { 2,52 } ,
/* name:V+ led:11 value:51*/ { 2,53 } ,
/* name:V- led:11 value:52*/ { 2,54 } ,
/* name:R+ led:11 value:53*/ { 2,55 } ,
/* name:R- led:11 value:54*/ { 2,56 } ,
/* name:GND led:11 value:55*/ { 2,57 } ,
/* name:V+ led:12 value:56*/ { 2,58 } ,
/* name:V- led:12 value:57*/ { 2,59 } ,
/* name:R+ led:12 value:58*/ { 2,60 } ,
/* name:R- led:12 value:59*/ { 2,61 } ,
/* name:GND led:12 value:60*/ { 2,62 } ,
/* name:V+ led:13 value:61*/ { 2,63 } ,
/* name:V- led:13 value:62*/ { 2,64 } ,
/* name:R+ led:13 value:63*/ { 2,65 } ,
/* name:R- led:13 value:64*/ { 2,66 } ,
/* name:GND led:13 value:65*/ { 2,67 } ,
/* name:V+ led:14 value:66*/ { 2,68 } ,
/* name:V- led:14 value:67*/ { 2,69 } ,
/* name:R+ led:14 value:68*/ { 1,1 } ,
/* name:R- led:14 value:69*/ { 1,2 } ,
/* name:GND led:14 value:70*/ { 1,3 } ,
/* name:V+ led:15 value:71*/ { 1,4 } ,
/* name:V- led:15 value:72*/ { 1,5 } ,
/* name:R+ led:15 value:73*/ { 1,6 } ,
/* name:R- led:15 value:74*/ { 1,7 } ,
/* name:GND led:15 value:75*/ { 1,8 } ,
/* name:V+ led:16 value:76*/ { 1,9 } ,
/* name:V- led:16 value:77*/ { 1,10 } ,
/* name:R+ led:16 value:78*/ { 1,11 } ,
/* name:R- led:16 value:79*/ { 1,12 } ,
/* name:GND led:16 value:80*/ { 1,13 } ,
/* name:V+ led:17 value:81*/ { 1,14 } ,
/* name:V- led:17 value:82*/ { 1,15 } ,
/* name:R+ led:17 value:83*/ { 1,16 } ,
/* name:R- led:17 value:84*/ { 1,17 } ,
/* name:GND led:17 value:85*/ { 1,20 } ,
/* name:V+ led:18 value:86*/ { 1,21 } ,
/* name:V- led:18 value:87*/ { 1,22 } ,
/* name:R+ led:18 value:88*/ { 1,23 } ,
/* name:R- led:18 value:89*/ { 1,24 } ,
/* name:GND led:18 value:90*/ { 1,25 } ,
/* name:V+ led:19 value:91*/ { 1,26 } ,
/* name:V- led:19 value:92*/ { 1,27 } ,
/* name:R+ led:19 value:93*/ { 1,28 } ,
/* name:R- led:19 value:94*/ { 1,29 } ,
/* name:GND led:19 value:95*/ { 1,30 } ,
/* name:V+ led:20 value:96*/ { 1,31 } ,
/* name:V- led:20 value:97*/ { 1,32 } ,
/* name:R+ led:20 value:98*/ { 1,33 } ,
/* name:R- led:20 value:99*/ { 1,34 } ,
/* name:GND led:20 value:100*/ { 1,35 }
};

#define CHIP_ID 1
///////////////////////////////////////////////////////////////////////////////////////////

void setup() {
  const char cols=16;
  const char rows=2;
  int gpv0;
  // put your setup code here, to run once: 
  lcd.begin(cols, rows);
  
  Serial1.begin(9600);

  //we should init hardware
  for(gpv0=1;gpv0<MAX_map_addr_to_pinchip_lookup_table;gpv0++){
    if(map_addr_to_pinchip_lookup_table[gpv0][0]==CHIP_ID){
      pinMode(map_addr_to_pinchip_lookup_table[gpv0][1],OUTPUT);
      digitalWrite(map_addr_to_pinchip_lookup_table[gpv0][1],LOW);
    }
  }

 


  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("TabrizCisco");
  lcd.setCursor(0,1);
  lcd.print("0914-914-9291");
  delay(1000);
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("HEALTH TESTER "); 
  delay(1000);
}


////////////////////////////////////////////////////////
//serial functions
#define RETRY 2
int send_msg(String &dat){
    int gpv0,gpv1;
    String resp;
    for(gpv0=0;gpv0<RETRY;gpv0++){
      Serial1.print(dat);
      resp=Serial1.readStringUntil('\n');
      if(resp=="OK\n")
        return 0;
      else if(resp=="ERROR\n"){
        return  -1;
      }
    }
    return -2;//no connection
}

////////////////////////////////////////////////////////
//read value function

#define BUFF_LEN 8
int key_read(char col,char row){
  char num[BUFF_LEN+2];
  char key;
  int val;
  char cnt=0;
  num[0]='0';
  num[1]=0;
  num[BUFF_LEN+1]=0;
  num[BUFF_LEN]=0;
  num[BUFF_LEN-1]=0;

  lcd.setCursor(col,row);
  lcd.print(num);
  
  while(1){
    key=kpd.waitForKey();
    if(key>='0' && key<='9' && cnt<BUFF_LEN){
        num[cnt++]=key;
        num[cnt]=0;
    }
    else
      switch(key){
        case '*':
        //clr
        if(cnt==1){
            cnt--;
            num[cnt]='0';
        }
        else if(cnt>1){
            cnt--;
            num[cnt]=' ';
        }
        break;
        case '#':
        //HELP
          return -1; //not supported for input
        break;
        case 'A':
          return -2; //not supported for input
        break;
        case 'B':
          return -3; //not supported for input
        break;
        case 'C':
          return -4; //not supported for input
        break; 
        case 'D':
          //ok
          
          if(cnt==0){
            lcd.setCursor(col,row);
            lcd.print(' ');
            return 0;
          }
          
          sscanf(num,"%d",&val);
          while(cnt>=0) num[cnt--]=' ';
          lcd.setCursor(col,row);
          lcd.print(num);
          return val;
          
        break;               
      }
 
    lcd.setCursor(col,row);
    lcd.print(num);
  }
  
}

////////////////////////////////////////////////////////
char check_led_range_vaild(int val){
  if(val>=1 && val<=20) return 1;
  return 0;
}

void map_val_to_addr(int *in,int *out){
  int gpv0;
  for(gpv0=0;gpv0<4;gpv0++)
    out[gpv0]=(in[gpv0]-1)*5+gpv0+1;
}


void map_addr_to_pinchip(int *in,char *chip_id,char *chip_pin){
  int gpv0;
  for(gpv0=0;gpv0<4;gpv0++){
    chip_id[gpv0]=map_addr_to_pinchip_lookup_table[in[gpv0]][0];
    chip_pin[gpv0]=map_addr_to_pinchip_lookup_table[in[gpv0]][1];
  }
}


////////////////////////////////////////////////////////
#define COUNT_LEVEL 4
const char msg[COUNT_LEVEL][32]={
"pls slct V+:",
"pls slct V-:",
"pls slct R+:",
"pls slct R-:",
};

///////////////////////////////////////////////////////
int start_hardware(int *regs){
  int port_id[COUNT_LEVEL];
  char chip_ids[COUNT_LEVEL];
  char port_ids[COUNT_LEVEL];
  int gpv0,gpv1;
  map_val_to_addr(regs,port_id);
  map_addr_to_pinchip(port_id,chip_ids,port_ids);
        

  //clr all ports
  for(gpv0=1;gpv0<MAX_map_addr_to_pinchip_lookup_table;gpv0++)
  if(map_addr_to_pinchip_lookup_table[gpv0][0]==CHIP_ID)
  digitalWrite(map_addr_to_pinchip_lookup_table[gpv0][1],LOW);

  String cmd=String("CLR ALL\n");
  gpv0=send_msg(cmd);
  if(gpv0!=0)
    return -1;

  for(gpv0=0;gpv0<4;gpv0++){
    if(chip_ids[gpv0]==CHIP_ID)
      digitalWrite(port_ids[gpv0],HIGH);
    else{
      String cmd=String("SET"+String(port_ids[gpv0],DEC)+"\n");
      gpv1=send_msg(cmd);
      if(gpv1!=0)
        return -1;
    }
  }
   return 0;
}


int stop_hardware(){
  //clr all ports
  int gpv0;
  for(gpv0=1;gpv0<MAX_map_addr_to_pinchip_lookup_table;gpv0++)
  if(map_addr_to_pinchip_lookup_table[gpv0][0]==CHIP_ID)
     digitalWrite(map_addr_to_pinchip_lookup_table[gpv0][1],LOW);
  
  String cmd=String("CLR ALL\n");
  gpv0=send_msg(cmd);
  if(gpv0!=0)
    return -1;

return 0;  
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int regis[COUNT_LEVEL];

int regp;
int resp;


void loop() {
  int gpv0;
  regp=0;
 
  while(true){
    lcd.clear();
    lcd.setCursor(0,0); 
    lcd.print(msg[regp]); 
       
    resp=key_read(0,1);
    if(resp>=0){
      if(check_led_range_vaild(resp)){
        regis[regp++]=resp;
      }
      else{
        lcd.setCursor(0,1); 
        lcd.print("out of range");
        kpd.waitForKey();  //for show
      }
    }
    else{
      switch(resp){
        case -1:
        if(regp>0)
          regp--;
        break;
        default:
        lcd.setCursor(0,1); 
        lcd.print("undefined key");
        kpd.waitForKey();  //for show
      }
    }

    if(regp==COUNT_LEVEL){
      lcd.clear();
      lcd.setCursor(0,0); 
      lcd.print("for start plz press *");
      lcd.setCursor(0,0); 
      lcd.print("for sbac plz press *"); 
      while(true){
        resp=kpd.waitForKey();  //for show
        if(resp=='#'){
          regp--;
          break;
        }
        if(resp=='*'){
          break;
        }
      }

      if(regp==COUNT_LEVEL){
        gpv0=start_hardware(regis);
        if(gpv0==0){
          lcd.clear();
          lcd.setCursor(0,0); 
          lcd.print("for stop plz press #");
          while(true){
            resp=kpd.waitForKey();  //for show
            if(resp=='#')
            break;
          }   
          regp=0;
          stop_hardware();
        }
        else{
          stop_hardware();
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("for back plz press #");
          lcd.setCursor(0,1);           
          lcd.print("hardware error ...");
          while(true){
            resp=kpd.waitForKey();  //for show
            if(resp=='#')
            break;
          }   
          regp--;
        }
        }    
     }
    }
    
}