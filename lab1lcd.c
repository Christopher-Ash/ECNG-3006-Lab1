#include <p18f452.h>
#include <stdio.h>
#include "xlcd.h"
#include <delays.h>


/* Set configuration bits for use with ICD2 */
#pragma config OSC = HS
#pragma config WDT = OFF
#pragma config LVP = OFF

//Set Delay functions
void DelayFor18TCY( void )
{
    Nop();
    Nop();
    Nop();
    Nop();
    Nop();
    Nop();
    Nop();
    Nop();
    Nop();
    Nop();
    Nop();
    Nop();
}
void DelayPORXLCD (void)
{
    Delay1KTCYx(15); // Delay of 15ms
                        
    return;
}
void DelayXLCD (void)
{
    Delay1KTCYx(5); // Delay of 5ms
    return;
}

void main (void)
{
    
    
    //configure external LCD
    while( BusyXLCD() );
    OpenXLCD(FOUR_BIT & LINES_5X7); //four bit mode and multiple line display
    while( BusyXLCD() );
    WriteCmdXLCD( FOUR_BIT & LINES_5X7 );
    while( BusyXLCD() );
    WriteCmdXLCD(BLINK_ON );
    while( BusyXLCD() );
    WriteCmdXLCD( SHIFT_DISP_LEFT );
    
   //configuring starting position of LCD
    while( BusyXLCD() );
    SetDDRamAddr( 0x43 );
    
   //while( BusyXLCD() );
    //SetCGRamAddr(0x00); 
    
    //Writing to LCD
    while( BusyXLCD() );
    putrsXLCD( "Micro LoL" );
   
    while(1);


}


