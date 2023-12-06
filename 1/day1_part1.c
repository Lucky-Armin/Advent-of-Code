#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	char *input_filename = argv[1];

	if (argc != 2)
	{
		return 1;
	}

	FILE *input_file = fopen(input_filename, "r");

	if (input_file == NULL)
	{
		printf("Error: unable to open input file!\n");
		return 1;
	}

	unsigned int i = 0;
	char line[256];
    char string[256];
    char c;
	int number = 0;
	int position = 0;
	int line_numbers[256];
	int stringlength = 0;
	int summand = 0;
	int sum = 0;

	input_file = fopen(input_filename, "r");

while (fgets(line, sizeof(line), input_file) != NULL)
    {
      sscanf(line, "%s", string);
      for(i=0;i<strlen(string);i++)
      {
        c = string[i];
        if(c>='0' && c<='9')
		{
			number = c - '0';
			line_numbers[position++] = number;
	//		position++;
			stringlength++;
		}
      }

	if(stringlength == 1){
		summand = line_numbers[0] * 10 + line_numbers[0];
	}
	if(stringlength == 2){
		summand = line_numbers[0] * 10 + line_numbers[1];
	}
	if(stringlength >=2){
		summand = line_numbers[0] * 10 + line_numbers[position - 1];
	}

	sum = sum + summand;
	position = 0;
	stringlength = 0;
	summand = 0;
    }

	fclose(input_file);
	printf("The answer is: %d\n", sum);
	return 0;
}