/*
 * segment.c
 *
 * Created: 23-03-2016 14:15:32
 *  Author: RISHABH JAIN
 */ 


#include <avr/io.h>
#include <util/delay.h>
#define seg PORTB

void main()
{
	DDRD=0xFF;
	DDRB=0xFF;
	int ar[]={0xFC,0x60,0xDA,0xF2,0x66,0xB6,0xBE,0xE0,0xFE,0xF6};
	int i,j,k;
	int c=1,a=0,b=0,p=0,q=0;	
    while(1)
    {
		for(i=0;i<6;i++)
		{
			for(j=0;j<10;j++)
			{
				
				for(k=0;k<150;k++)
				{
				 seg=0xFD;
				 PORTD=ar[i];
			     _delay_ms(1);
				 seg=0xFE;
				 PORTD=ar[j];
				 _delay_ms(1);
				 seg=0xF7;
				 PORTD=ar[a];
				 _delay_ms(1);
				 seg=0xFB;
				 PORTD=ar[b];
				 _delay_ms(1);
				 seg=0xDF;
				 PORTD=ar[p];
				 _delay_ms(1);
				 seg=0xEF;
				 PORTD=ar[q];
				 _delay_ms(1);
				    if(c==60)
				  {
				   c=0;
				   b++;
				   if(b==10)
				   {
					   b=0;
				       a++;
					   if (a==6)
					   {
						   a=0;
						   q++;
						   if(q==10)
						   {
							   q=0;
							   p++;
						   }
					   }
				   }
				  }
				  
				}
				 c++;
				}
			}
		} 
    }
