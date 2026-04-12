#include <REGX52.H>
/*
0000 0001   按一次按键左移一次
0000 0010
0000 0100
0000 1000

*/
void Delay(unsigned int xms);		//@11.0592MHz

unsigned char LEDNum;

void main()
{
    
    
    P2=~0x01;
    while(1)
    {
        
        if(P3_1==0)
        {
            Delay(20);
            while(P3_1==0);
            Delay(20);
            
            LEDNum++;
            if(LEDNum>=8)
                LEDNum=0;
            P2=~(0x01<<LEDNum);
        }
        if(P3_0==0)
        {
            Delay(20);
            while(P3_0==0);
            Delay(20);
            
            if(LEDNum==0)
                LEDNum=7;
            else
            LEDNum--;
            P2=~(0x01<<LEDNum);
        }
    }

}

void Delay(unsigned int xms)		//@11.0592MHz
{
	unsigned char i, j;
	while(xms--)
	{
		i = 2;
		j = 199;
		do
		{
			while (--j);
		} while (--i);
	}
	
}
