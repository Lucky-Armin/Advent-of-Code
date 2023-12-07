#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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
	unsigned int j = 0;
	unsigned int k = 0;
	char line[256];
    char string[256];
    char c;
	int  string_position = 0;
	int  numeric_digit = 0;
	int  numbers_of_this_line[256];
	int  number_of_numbers = 0;
	int  summand = 0;
	int  sum = 0;
	char *written_out_number;
	char three_letter_numbers[10];
	written_out_number = (char *)calloc(5, sizeof(char));

	input_file = fopen(input_filename, "r");

while (fgets(line, sizeof(line), input_file) != NULL)
    {
      sscanf(line, "%s", string);
      for(i=0;i<strlen(string);i++)
      {
        c = string[i];
		j = i;
		k = 0;

        if(c>='0' && c<='9')
		{
			numeric_digit = c - '0';
			numbers_of_this_line[string_position++] = numeric_digit;
			number_of_numbers++;
		} else {
			while(isalpha(string[j]) != 0){
				written_out_number[k++] = string[j++];
			}

//			written_out_number[j] = '\0';
		}
		three_letter_numbers[0] = written_out_number[0];
		three_letter_numbers[1] = written_out_number[1];
		three_letter_numbers[2] = written_out_number[2];

		printf("%s\n" , written_out_number);

		if(strcmp(three_letter_numbers, "one") == 0){
			numbers_of_this_line[string_position++] = 1;
			number_of_numbers++;
		}
		if(strcmp(three_letter_numbers, "two") == 0){
			numbers_of_this_line[string_position++] = 2;
			number_of_numbers++;

		}		
		if(strcmp(three_letter_numbers, "six") == 0){
			numbers_of_this_line[string_position++] = 6;
			number_of_numbers++;

		}

      }

	written_out_number = realloc(written_out_number, 5 * sizeof(char));

	if(number_of_numbers == 1){
		summand = numbers_of_this_line[0] * 10 + numbers_of_this_line[0];
	}
	if(number_of_numbers == 2){
		summand = numbers_of_this_line[0] * 10 + numbers_of_this_line[1];
	}
	if(number_of_numbers >=2){
		summand = numbers_of_this_line[0] * 10 + numbers_of_this_line[string_position - 1];
	}

	sum = sum + summand;
	string_position = 0;
	number_of_numbers = 0;
	summand = 0;
    }

	fclose(input_file);
	printf("The answer is: %d\n", sum);
	return 0;
}