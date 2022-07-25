
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
        case 'C': //act as clear
            while(cnt>=0) num[cnt--]=' ';
            num[0]='0';
            cnt=0;
        break;
        case 'A':
        //inc
        if(cnt==0){
            num[cnt++]='1';
            num[cnt]=0;
          }
          else{
          sscanf(num,"%d",&val);

          while(cnt>=0) num[cnt--]=' ';
          lcd.setCursor(col,row);
          lcd.print(num);
          
          
          val++;
          cnt=sprintf(num,"%d",val);
          }
          
        break;
        case 'B':
          if(cnt!=0){
          
          sscanf(num,"%d",&val);
          
          while(cnt>=0) num[cnt--]=' ';
          lcd.setCursor(col,row);
          lcd.print(num);
          
          val--;
          if(val==0){
            cnt=0;
            num[cnt++]='1';
            num[cnt]=0; 
          }
          else{
          cnt=sprintf(num,"%d",val);
          }
          }
          
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
        case '#': //this keys undefined
          return -1; //not supported for input
        break;
        case '*':
          return -2; //not supported for input
        break;         
      }
 
    lcd.setCursor(col,row);
    lcd.print(num);
  }
  
}


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

1
2
4
5
6
7
53
52
51
50
49
48
47
46
18
19
18
19
