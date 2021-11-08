#include <stdio.h>

size_t my_strlen(const char *str)
{
	size_t i = 0;
	while (*str != '\0')
	{
		str++;
		i++;
	}
	return i;
}

int next_alpha(const char text[], int old_min)
{
	int min = 65;
	while (*text != '\0')
	{
		if (*text > old_min)
		{
			min = *text;
			break;
		}
		text++;
	}
	while (*text !='\0')
	{
		if (*text < min && *text > old_min)
			min = *text;
		text++;
	}
	return min;
}

size_t count(const char text[], char to_count)
{
	size_t counter = 0;
	while (*text != '\0')
	{
		if (*text == to_count)
			counter++;
		text++;
	}
	return counter;
}

void freq_analysis(const char text[], const char table[])
{
	int curr_char = 0;
	size_t unique_chars = my_strlen(table);
	for (size_t i = 1; i <= unique_chars; i++)
	{
		size_t freq = 0;
		curr_char = next_alpha(text, curr_char);
		freq = count(text, curr_char);
		printf("%c has %ld occurences\n", curr_char, freq);
	}

}

int main(int argc, char *argv[])
{
	if (argc != 3)
		return 1;
	freq_analysis(argv[1], argv[2]);
	return 0;
}
