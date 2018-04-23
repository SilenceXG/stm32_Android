#define Modserial

#include "mbed.h"

#ifdef Modserial
#include "MODSERIAL.h"
#else
//#include "BufferedSerial.h"
#endif


DigitalOut led1(p21);
DigitalOut led4(p22);

#ifdef Modserial
MODSERIAL pc(USBTX,USBRX);
#else
RawSerial pc(USBTX,USBRX);
#endif


bool new_send = false;
void parse_cmd(int sizeCMD);
char bufferRX[50];
int i = 0;


// interrupt call
#ifdef Modserial
void rxCallback(MODSERIAL_IRQ_INFO *q)
{
     new_send = true;
}
#else
void rxCallback()
{
    led1 = 1;

    char test = pc.getc();
    if(test != '\n')
    {
         bufferRX[i] = test;
         i++;
    }else
    {
        new_send = true;
    }
    led1 = 0;
    return;
}
#endif 




int main() 
{
    pc.baud(9600);       
    pc.printf("SystemCoreClock: %dMHz\r\n", SystemCoreClock/1000000);       // print the clock frequency
    led4 = 0;
    int n = 0;
    

    #ifdef Modserial
    pc.attach(&rxCallback);
    #else
    pc.attach(&rxCallback, Serial::RxIrq);
    #endif 
 
 
    while(1) 
    { 
        #ifdef Modserial
        if(new_send)
        {
            int i = 0;
            led1 = 1;
            
            while(pc.readable())
            {
                bufferRX[i] = pc.getc();
                i++;
            }
            parse_cmd(i);
            led1 = 0; 
        }
        #else
        if(new_send)
        {

            parse_cmd(i);        
          
            memset(bufferRX, 0, sizeof(bufferRX));
            new_send = false;
            i = 0;
        }
        #endif             
        wait_ms(50);
        n++;
        if(n == 10)
        {
            led4 = !led4;
            n = 0;
        }
    }
}





void parse_cmd(int sizeCMD)
{
        new_send = false;
        
        
        pc.printf("bufferRX: %s\r\n", bufferRX);
        
               
        if(strcmp("hello", bufferRX) == 0)              
        {
            pc.printf("Test OK\r\n");   
        }
        
        memset(bufferRX, 0, sizeof(bufferRX)); 
}


