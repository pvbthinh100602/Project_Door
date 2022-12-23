#include "password.h"

unsigned char arrayPassword[4];
unsigned char indexOfNumber = 0;
unsigned char pass[5] = "";
unsigned int seed = 0;

unsigned char CheckPassword()
{
    unsigned char j;
        for (j=0;j<4;j++)
        {
            if (arrayPassword[j] != pass[j])
                return 0;
        }
        return 1;

}

unsigned char* generate_pass(){
    int i;
    for(i = 0; i < 4; i++){
        pass[i] = rand()%5 + 1 + '0';
    }
    pass[5] = '\0';
    return pass;
}