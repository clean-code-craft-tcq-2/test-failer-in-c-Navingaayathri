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

void PrintOnConsole(int ColorPairArrayIndex, char *majorColor, char *minorColor)
{
printf("%d | %s | %s\n", ColorPairArrayIndex, majorColor, minorColor);
}

int printColorMap() {
    
    int i = 0, j = 0, ColorPairIdx=1;
    for(i = 0; i < 5; i++) 
	{
        for(j = 0; j < 5; j++)
		{
			
			colorpair[ColorPairIdx].Num = ColorPairIdx;
			strcpy(colorpair[ColorPairIdx].MajorColor , majorColor[i]);
			strcpy(colorpair[ColorPairIdx].MinorColor , minorColor[j]);
			PrintOnConsole(ColorPairIdx, colorpair[ColorPairIdx].MajorColor, colorpair[ColorPairIdx].MinorColor);	
		    ColorPairIdx++;
				          
        }
    }
    return i * j;
}

int main() {
    int result = printColorMap();
    assert(result == 25);
	assert(colorpair[6].Num == 6);	
	assert(strcmp(colorpair[6].MajorColor, "Red") == 0);
	assert(strcmp(colorpair[6].MinorColor, "Blue") == 0);
	assert(colorpair[15].Num == 15);	
	assert(strcmp(colorpair[15].MajorColor, "Black") == 0);
	assert(strcmp(colorpair[15].MinorColor, "Slate") == 0);

    printf("All is well (Yes,it is! :> )\n");
    return 0;
}
