#include "main.h"
// Noi khai bao hang so
#define     LED     PORTB
#define     ON      1
#define     OFF     0

#define     INIT_SYSTEM        0
#define     ENTER_PASSWORD     1
#define     CHECK_PASSWORD     2
#define     UNLOCK_DOOR        3
#define     WRONG_PASSWORD     4
#define     DOOR_IS_OPEN       5
// Noi khai bao bien toan cuc
unsigned char arrayMapOfOutput [8] = {0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};
unsigned char statusOutput[8] = {0,0,0,0,0,0,0,0};
// Khai bao cac ham co ban IO
void init_system(void);
void delay_ms(int value);
void OpenOutput(int index);
void CloseOutput(int index);
void TestOutput(void);
void ReverseOutput(int index);
unsigned char isButtonMotorOn();
unsigned char isButtonMotorOff();
void MotorOn();
void MotorOff();
void BaiTap_Motor();
void Test_KeyMatrix();
unsigned char isButtonEnter();
void UnlockDoor();
void LockDoor();
unsigned char CheckPassword();
void App_PasswordDoor();
//Chuong trinh Password Door
unsigned char arrayMapOfNumber [16] = {1,2,3,'A',4,5,6,'B',
                                       7,8,9,'C','*',0,'E','D'};
unsigned char arrayMapOfPassword [5][4]= {
  {1,2,3,4},
  {2,7,8,9},
  {3,3,3,3},
  {4,8,6,8},
  {5,'A','B','C'},
};
unsigned char arrayPassword[4];
unsigned char statusPassword = INIT_SYSTEM;
unsigned char indexOfNumber = 0;
unsigned char timeDelay = 0;
unsigned int ReadValueAdc = 0;

void App_PasswordDoor();
unsigned char CheckPassword();
unsigned char isButtonNumber();
unsigned char numberValue;
unsigned char isButtonEnter();
void UnlockDoor();
void LockDoor();

////////////////////////////////////////////////////////////////////
//Hien thuc cac chuong trinh con, ham, module, function duoi cho nay
////////////////////////////////////////////////////////////////////
void main(void)
{
	unsigned int k = 0;
	init_system();
        //TestOutput();
    
	while (1)
	{     
//        if(isButtonEnter()){
//            ReverseOutput(0);
//        }
        if(flag_timer1){
            SetTimer1_ms(50);
            scan_key_matrix();
//            ReadValueAdc = get_adc_value(0);
            DisplayLcdScreen();    
            App_PasswordDoor();
        }
        
	}
}
// Hien thuc cac module co ban cua chuong trinh
void delay_ms(int value)
{
	int i,j;
	for(i=0;i<value;i++)
		for(j=0;j<238;j++);
}

void init_system(void)
{
    TRISB = 0x00;		//setup PORTB is output
    TRISD = 0x00;
    init_lcd();
    LcdClearS();
      LED = 0x00;
    init_adc();
    init_interrupt();
    init_pwm();
    delay_ms(1000);
//    init_timer0(4695);//dinh thoi 1ms sai so 1%
//    init_timer1(9390);//dinh thoi 2ms
    init_timer3(46950);//dinh thoi 10ms
    SetTimer1_ms(50);
//    SetTimer2_ms();
//    SetTimer3_ms(50); //Chu ky thuc hien viec xu ly input,proccess,output
    init_key_matrix();
}

void OpenOutput(int index)
{
	if (index >= 0 && index <= 7)
	{
		LED = LED | arrayMapOfOutput[index];
	}

}

void CloseOutput(int index)
{
	if (index >= 0 && index <= 7)
	{
		LED = LED & ~arrayMapOfOutput[index];
	}
}

void ReverseOutput(int index)
{
    if (statusOutput[index]  == ON)
    {
        CloseOutput(index);
        statusOutput[index] = OFF;
    }
    else
    {
        OpenOutput(index);
        statusOutput[index] = ON;
    }
}

void TestOutput(void)
{
	int k;
	for (k=0;k<=7 ;k++ )
	{
		OpenOutput(k);
		delay_ms(500);
		CloseOutput(k);
		delay_ms(500);
	}
}
unsigned char isButtonMotorOn()
{
    if (key_code[2] == 1)
        return 1;
    else
        return 0;
}

unsigned char isButtonMotorOff()
{
    if (key_code[3] == 1)
        return 1;
    else
        return 0;
}

void App_PasswordDoor()
{
    switch (statusPassword)
    {
        case INIT_SYSTEM:
            LcdPrintStringS(0,0,"PRESS * FOR PASS");
            LcdPrintStringS(1,0,"                ");
            // con thieu action
            if (isButtonEnter())
            {
                indexOfNumber = 0;
                timeDelay = 0;
                statusPassword = ENTER_PASSWORD;
            }
            break;
        case ENTER_PASSWORD:
            LcdPrintStringS(0,0,"ENTER PASSWORD  ");
            timeDelay ++;
            if (isButtonNumber())
            {
                LcdPrintStringS(1,indexOfNumber,"*");
                arrayPassword [indexOfNumber] = numberValue;
                indexOfNumber ++;
                timeDelay = 0;
            }
            if (indexOfNumber >= 4)
                statusPassword = CHECK_PASSWORD;
            if (timeDelay >= 100)
                statusPassword = INIT_SYSTEM;
            // con thieu dieu kien chuyen trang thai
            break;
        case CHECK_PASSWORD:
            timeDelay = 0;
            if (CheckPassword())
                statusPassword = UNLOCK_DOOR;
            else
                statusPassword = WRONG_PASSWORD;
            break;
        case UNLOCK_DOOR:
            timeDelay++;
            LcdPrintStringS(0,0,"UNLOCK DOOR     ");
            LcdPrintStringS(1,0,"                ");
            LcdPrintNumS(1,0,ReadValueAdc);
            UnlockDoor();
            if(ReadValueAdc >= 1000){
                statusPassword = DOOR_IS_OPEN;
            }
            // con thieu dieu kien chuyen trang thai
            
            break;
        case DOOR_IS_OPEN:
            LcdPrintStringS(0,0,"OPENING DOOR    ");
            LcdPrintStringS(1,0,"                ");
            LcdPrintNumS(1,0,ReadValueAdc);
            if(ReadValueAdc < 1000){
                statusPassword = INIT_SYSTEM;
            }
            break;
        case WRONG_PASSWORD:
            timeDelay++;
            LcdPrintStringS(0,0,"PASSWORD WRONG  ");
            if(isButtonEnter()){
                statusPassword = INIT_SYSTEM;
            }
            // con thieu dieu kien chuyen trang thai
            break;
        default:
            break;
    }
}
unsigned char CheckPassword()
{
    unsigned char i,j;
    unsigned result = 1;
    for (i=0;i<5;i++)
    {
        result = 1;
        for (j=0;j<4;j++)
        {
            if (arrayPassword[j] != arrayMapOfPassword[i][j])
                result = 0;
        }
        if (result == 1)
            return (i+1);
    }

}
unsigned char isButtonNumber()
{
    unsigned char i;
    for (i = 0; i<=15; i++)
        if (key_code[i] == 1)
        {
            numberValue = arrayMapOfNumber[i];
            return 1;
        }
    return 0;
}

unsigned char isButtonEnter()
{
    if (key_code[12] == 1){
        return 1;
    }
    else
        return 0;
}
void UnlockDoor()
{
    OpenOutput(0);
    //OpenOutput(4);
}
void LockDoor()
{
    CloseOutput(0);
    //CloseOutput(4);
}

