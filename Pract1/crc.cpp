#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    unsigned short Rx1 = 0x0000;
    unsigned short Rx2;
    FILE * pFile;
    int c1,c2;
    unsigned short Px = 0x8E47;
    unsigned short bite;

    pFile=fopen ("prob.txt","r");
    if (pFile==NULL) perror ("Error opening file");
    else
    {
      while ((c1 = getc (pFile)) != EOF)
        {
          for(int i =0; i<8; i++)
             {
                bite = 0;
                c2 = c1 >> 7 ;
                if(c2 & 1)
                {
                    bite = 1;
                }
                c1 = c1 << 1;
                Rx2 = Rx1 >>15;
                if(Rx2 & 1)
                {
                    Rx1 = Rx1 << 1;
                    Rx1 += bite;
                    Rx1 = Rx1 ^ Px;
                }
                else
                {
                    Rx1 = Rx1 << 1;
                    Rx1 += bite;
                }
             }
        }
      fclose (pFile);
      for(int i =0; i<16; i++)
       {
          Rx2 = Rx1 >>15;
          if( Rx2 & 1)
          {
              Rx1 = Rx1 <<  1;
              Rx1 = Rx1 ^ Px;
          }
          else
          {
              Rx1 = Rx1 << 1;
          }
       }
    }
    cout<<"crc = "<<hex<<Rx1<<endl;
    cout<<"Px = "<<hex<<Px<<endl;

  return 0;
}
