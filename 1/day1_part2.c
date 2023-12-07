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
	char c;
	int string_position = 0;
	int numeric_digit = 0;
	int numbers_of_this_line[256];
	int number_of_numbers = 0;
	int summand = 0;
	int sum = 0;
	char line[256];
	char *string;
	char *written_out_number;
	char *three_letter_numbers;
	char *four_letter_numbers;
	char *five_letter_numbers;

	input_file = fopen(input_filename, "r");

	while (fgets(line, sizeof(line), input_file) != NULL)
	{
		string = (char *)calloc(strlen(line) + 1, sizeof(char));
		sscanf(line, "%s", string);
		written_out_number 		= calloc(strlen(line) + 1, sizeof(char));
		three_letter_numbers 	= calloc(3, sizeof(char));
		four_letter_numbers 	= calloc(4, sizeof(char));
		five_letter_numbers 	= calloc(5, sizeof(char));
		
		for (i = 0; i < strlen(string); i++)
		{
			c = string[i];
			j = i;
			k = 0;
			realloc(written_out_number, (strlen(line) + 1) * sizeof(char));
			realloc(three_letter_numbers, 3 * sizeof(char));
			realloc(four_letter_numbers, 4 * sizeof(char));
			realloc(five_letter_numbers, 5 * sizeof(char));

			if (c >= '0' && c <= '9')
			{
				numeric_digit = c - '0';
				numbers_of_this_line[string_position++] = numeric_digit;
				number_of_numbers++;
			}
			else
			{
				while (isalpha(string[j]) != 0 && k < strlen(string))
				{
					written_out_number[k] = string[j];
					k++;
					j++;
				}
			}
			three_letter_numbers[0] = written_out_number[0];
			three_letter_numbers[1] = written_out_number[1];
			three_letter_numbers[2] = written_out_number[2];

			four_letter_numbers[0] = written_out_number[0];
			four_letter_numbers[1] = written_out_number[1];
			four_letter_numbers[2] = written_out_number[2];
			four_letter_numbers[3] = written_out_number[3];

			five_letter_numbers[0] = written_out_number[0];
			five_letter_numbers[1] = written_out_number[1];
			five_letter_numbers[2] = written_out_number[2];
			five_letter_numbers[3] = written_out_number[3];
			five_letter_numbers[4] = written_out_number[4];

			if (strcmp(three_letter_numbers, "one") == 0)
			{
				numbers_of_this_line[string_position++] = 1;
				number_of_numbers++;
			}
			if (strcmp(three_letter_numbers, "two") == 0)
			{
				numbers_of_this_line[string_position++] = 2;
				number_of_numbers++;
			}
			if (strcmp(five_letter_numbers, "three") == 0)
			{
				numbers_of_this_line[string_position++] = 3;
				number_of_numbers++;
			}
			if (strcmp(four_letter_numbers, "four") == 0)
			{
				numbers_of_this_line[string_position++] = 4;
				number_of_numbers++;
			}
			if (strcmp(four_letter_numbers, "five") == 0)
			{
				numbers_of_this_line[string_position++] = 5;
				number_of_numbers++;
			}
			if (strcmp(three_letter_numbers, "six") == 0)
			{
				numbers_of_this_line[string_position++] = 6;
				number_of_numbers++;
			}
			if (strcmp(five_letter_numbers, "seven") == 0)
			{
				numbers_of_this_line[string_position++] = 7;
				number_of_numbers++;
			}
			if (strcmp(five_letter_numbers, "eight") == 0)
			{
				numbers_of_this_line[string_position++] = 8;
				number_of_numbers++;
			}
			if (strcmp(four_letter_numbers, "nine") == 0)
			{
				numbers_of_this_line[string_position++] = 9;
				number_of_numbers++;
			}
		}

		if (number_of_numbers == 1)
		{
			summand = numbers_of_this_line[0] * 10 + numbers_of_this_line[0];
		}
		if (number_of_numbers == 2)
		{
			summand = numbers_of_this_line[0] * 10 + numbers_of_this_line[1];
		}
		if (number_of_numbers >= 2)
		{
			summand = numbers_of_this_line[0] * 10 + numbers_of_this_line[string_position - 1];
		}

		sum = sum + summand;
		string_position = 0;
		number_of_numbers = 0;
		summand = 0;
		free(string);
		free(written_out_number);
		free(three_letter_numbers);
		free(four_letter_numbers);
		free(five_letter_numbers);
	}

	fclose(input_file);
	printf("The answer is: %d\n", sum);
	return 0;
}