#include <stdio.h>
#include <assert.h>
#include <string.h>

const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};


struct Colorpair
{
	int Num;
	char MajorColor[8];
	char MinorColor[8];
};

Colorpair colorpair[25];

void PrintOnConsole( int i, int j)
{
printf("%d | %s | %s\n", i * 5 + j, majorColor[i], minorColor[i]);
}

int printColorMap() {
    
    int i = 0, j = 0, ColorPairIdx=0;
    for(i = 0; i < 5; i++) 
	{
        for(j = 0; j < 5; j++)
		{
			
			colorpair[ColorPairIdx].Num = i * 5 + j;
			strcpy(colorpair[ColorPairIdx].MajorColor , majorColor[i]);
			strcpy(colorpair[ColorPairIdx].MinorColor , minorColor[j]);
			PrintOnConsole(i,j);	
		        ColorPairIdx++;				          
        }
    }
    return i * j;
}

int main() {
    int result = printColorMap();
    assert(result == 25);
	assert(colorpair[23].Number == 23);	
	assert(strcmp(colorpair[23].MajorColor, "Violet") == 0);
	assert(strcmp(colorpair[23].MinorColor, "Green") == 0);
	assert(colorpair[15].Number == 15);	
	assert(strcmp(colorpair[15].MajorColor, "Black") == 0);
	assert(strcmp(colorpair[15].MinorColor, "Slate") == 0);
    printf("All is well (Yes,it is! :> )\n");
    return 0;
}
