#include "password.h"

unsigned char arrayPassword[6];
unsigned char indexOfNumber = 0;
unsigned char pass[7] = "";


unsigned char CheckPassword()
{
    unsigned char j;
        for (j=0;j<6;j++)
        {
            if (arrayPassword[j] != pass[j])
                return 0;
        }
        return 1;

}

unsigned char* generate_pass(){
    int i;
    for(i = 0; i < 6; i++){
        pass[i] = rand()%10 + '0';
    }
    pass[7] = '\0';
    return pass;
}