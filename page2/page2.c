
#include <avr/io.h>
#include<util/delay.h>

//functions 
void lcdstring( char *p)
{
	while(*p)
	{
		PORTB=(*p);
		display();
		p++;

	}
}

//command function of LCD
void cmd()
{
	PORTA=0B00000100;
	_delay_ms(200);
	PORTA=0B00000000;
}

//display function of LCD
void display()
{
	PORTA=0B00000101;
	_delay_ms(800);
	PORTA=0B00000001;
}

//command array
unsigned char arr1[]={0x38,0x0e,0x01,0x80,0x06};
	

unsigned char arr2[]={"Enter new pwd"};
	
	//inbuilt password
unsigned char arr4[]={"ABCDE"};
unsigned char ar5[]={"Password based"};
unsigned char arr5[]={"Door Lock System"};
unsigned char arr6[]={"correct pwd"};
unsigned char arr7[]={"wrong pwd"};
unsigned char arr8[]={"enter password"};	
		//array to store password
	unsigned char e[6];
	unsigned char e1[6];
	
int main(void)
{
	int i,j,k=0,l=0;
	//PORTA & PORTB made output ports
	//PORTC is made the imput port
	DDRB=0xff;
	DDRA=0xff;
	DDRC=0x00;
	
	
    //to send commands to the LCD
	for(i=0;i<=4;i++)
    { 
		PORTB=arr1[i];
		cmd();
    }
	
	for(j=0;j<1;j++)
	{
		for(i=0;i<=13;i++)
		 {
		PORTB=ar5[i];
		display();
		 }
	PORTB=0xc0;
	cmd();
	
		for(i=0;i<=15;i++)
		 {
		 PORTB=arr5[i];
		 display();
		 }
	}	 
	
	_delay_ms(2000);
	PORTB=0x01;
	cmd();
	
	//to display text on the LCD
	 for(i=0;i<=13;i++)
	 {
		 PORTB=arr2[i];
		 display();
	 }
	 
	 PORTB=0xc0;
	 cmd();
	 _delay_ms(8000);
	 //to enter characters from the keypad
	 
	 while(k<=4)
	 {
		if (PINC=0x01)
		{
	 if(PINC & 0X10)
	 {
		 PORTB='A';
		 e[k]=PORTB;
		 _delay_ms(500);
		 //to display characters as asterisks
		 lcdstring("*");
		 k++;
	 }
	 		 
      if(PINC & 0X20)
	 	 {
		  PORTB='B';
		   e[k]=PORTB;
		  _delay_ms(500);
		  lcdstring("*");
		   k++;
		  }
	 if(PINC & 0X40)
 	 {
	 	 PORTB='C';
	 	 e[k]=PORTB;
		  _delay_ms(500);
		  lcdstring("*");
		   k++;
  }	
   if(PINC & 0X80)
  {
	  PORTB='D';
	   e[k]=PORTB;
	  _delay_ms(500);
	  lcdstring("*");
	   k++;
  }
	  }  
  	if (PINC=0x02)
	  {
  	 if(PINC & 0X10)
  	 {
	  	 PORTB='E';
	  	e[k]=PORTB;
	  	_delay_ms(500);
	  	lcdstring("*");
	  	k++;
  	 }
  	 
  	 if(PINC & 0X20)
  	 {
	  	 PORTB='F';
	  	 e[k]=PORTB;
	  	 _delay_ms(500);
	  	 lcdstring("*");
	  	 k++;
  	 }
  	 if(PINC & 0X40)
  	 {
	  	 PORTB='G';
	  	 e[k]=PORTB;
	  	 _delay_ms(500);
	  	 lcdstring("*");
	  	 k++;
  	 }
  	 if(PINC & 0X80)
  	 {
	  	 PORTB='H';
	  	 e[k]=PORTB;
	  	 _delay_ms(500);
	  	 lcdstring("*");
	  	 k++;
  	 }
	  
	  }	  
	   if (PINC=0x04)
	   {
		   if(PINC & 0X10)
		   {
			   PORTB='I';
			  e[k]=PORTB;
			  _delay_ms(500);
			  lcdstring("*");
			  k++;
		   }
		   
		   if(PINC & 0X20)
		   {
			   PORTB='J';
			  e[k]=PORTB;
			  _delay_ms(500);
			  lcdstring("*");
			  k++;
		   }
		   if(PINC & 0X40)
		   {
			   PORTB='K';
			   e[k]=PORTB;
			   _delay_ms(500);
			   lcdstring("*");
			   k++;
		   }
		   if(PINC & 0X80)
		   {
			   PORTB='L';
			   e[k]=PORTB;
			   _delay_ms(500);
			   lcdstring("*");
			   k++;
		   }
	   }		  
		   if (PINC=0x08)
		   {
			   if(PINC & 0X10)
			   {
				   PORTB='M';
				   e[k]=PORTB;
				   _delay_ms(500);
				   lcdstring("*");
				   k++;
			   }
			   
			   if(PINC & 0X20)
			   {
				   PORTB='N';
				   e[k]=PORTB;
				   _delay_ms(500);
				   lcdstring("*");
				   k++;
			   }
			   if(PINC & 0X40)
			   {
				   PORTB='O';
				   e[k]=PORTB;
				   _delay_ms(500);
				   lcdstring("*");
				   k++;
			   }
			   if(PINC & 0X80)
			   {
				   PORTB='P';
				  e[k]=PORTB;
				  _delay_ms(500);
				  lcdstring("*");
				  k++;
				    
			   }
			 e[k]='\0';  
		   }	
		   }
		   _delay_ms(8000);
		   PORTB=0x01;
		   cmd();
		   PORTB=0x80;
		   cmd();
		   
		    for(i=0;i<=13;i++)
		    {
			    PORTB=arr8[i];
			    display();
		    }
			  PORTB=0xc0;
			  cmd();
			
		   
		   while(l<=4)
		   {
			   if (PINC=0x01)
			   {
				   if(PINC & 0X10)
				   {
					   PORTB='A';
					   e1[l]=PORTB;
					   _delay_ms(500);
					   //to display characters as asterisks
					   lcdstring("*");
					   l++;
				   }
				   
				   if(PINC & 0X20)
				   {
					   PORTB='B';
					   e1[l]=PORTB;
					   _delay_ms(500);
					   lcdstring("*");
					   l++;
				   }
				   if(PINC & 0X40)
				   {
					   PORTB='C';
					   e1[l]=PORTB;
					   _delay_ms(500);
					   lcdstring("*");
					   l++;
				   }
				   if(PINC & 0X80)
				   {
					   PORTB='D';
					   e1[l]=PORTB;
					   _delay_ms(500);
					   lcdstring("*");
					   l++;
				   }
			   }
			   if (PINC=0x02)
			   {
				   if(PINC & 0X10)
				   {
					   PORTB='E';
					   e1[l]=PORTB;
					   _delay_ms(500);
					   lcdstring("*");
					   l++;
				   }
				   
				   if(PINC & 0X20)
				   {
					   PORTB='F';
					   e1[l]=PORTB;
					   _delay_ms(500);
					   lcdstring("*");
					   l++;
				   }
				   if(PINC & 0X40)
				   {
					   PORTB='G';
					   e1[l]=PORTB;
					   _delay_ms(500);
					   lcdstring("*");
					   l++;
				   }
				   if(PINC & 0X80)
				   {
					   PORTB='H';
					   e1[l]=PORTB;
					   _delay_ms(500);
					   lcdstring("*");
					   l++;
				   }
				   
			   }
			   if (PINC=0x04)
			   {
				   if(PINC & 0X10)
				   {
					   PORTB='I';
					   e1[l]=PORTB;
					   _delay_ms(500);
					   lcdstring("*");
					   l++;
				   }
				   
				   if(PINC & 0X20)
				   {
					   PORTB='J';
					   e1[l]=PORTB;
					   _delay_ms(500);
					   lcdstring("*");
					   l++;
				   }
				   if(PINC & 0X40)
				   {
					   PORTB='K';
					   e1[l]=PORTB;
					   _delay_ms(500);
					   lcdstring("*");
					   l++;
				   }
				   if(PINC & 0X80)
				   {
					   PORTB='L';
					   e1[l]=PORTB;
					   _delay_ms(500);
					   lcdstring("*");
					   l++;
				   }
			   }
			   if (PINC=0x08)
			   {
				   if(PINC & 0X10)
				   {
					   PORTB='M';
					   e1[l]=PORTB;
					   _delay_ms(500);
					   lcdstring("*");
					   l++;
				   }
				   
				   if(PINC & 0X20)
				   {
					   PORTB='N';
					   e1[l]=PORTB;
					   _delay_ms(500);
					   lcdstring("*");
					   l++;
				   }
				   if(PINC & 0X40)
				   {
					   PORTB='O';
					   e1[l]=PORTB;
					   _delay_ms(500);
					   lcdstring("*");
					   l++;
				   }
				   if(PINC & 0X80)
				   {
					   PORTB='P';
					   e1[l]=PORTB;
					   _delay_ms(500);
					   lcdstring("*");
					   l++;
					   
				   }
				   e1[l]='\0';
			   }
		   }
		   
		  PORTB=0x01;
		  cmd();
		   PORTB=0x80;
		   cmd();
		   
		   //to verify whether the password entered matches the inbuilt password 
		   	if(((strncmp(e,e1,5))==0))
		   	{
			   	 for(i=0;i<=10;i++)
			   	 {
				   	 PORTB=arr6[i];
				   	 display();
			   	 }
			   }
			   else
			   {					
			   	for(i=0;i<=8;i++)
			   	{
				   	PORTB=arr7[i];
				   	display();
			   	}
			   }
	   }			   				   