#include <stdio.h>

struct info
{
	const char *text;
	const char *table;
	size_t unique_chars;
};

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

int find_corresponding(struct info inf, size_t freq, size_t limit)
{
	size_t max_freq = 0;
	int curr_char = 0;
	for (size_t i = 0; i < inf.unique_chars; i++)
	{
		curr_char = next_alpha(inf.text, curr_char);
		size_t temp = count(inf.text, curr_char);
		if (temp > max_freq && temp < limit)
			max_freq = temp;
	}
	if (max_freq == freq)
		return *inf.table;
	else
	{
		inf.table++;
		return find_corresponding(inf, freq, max_freq);
	}	
}

void freq_analysis(const char text[], const char table[])
{
	int curr_char = 0;
	int unique_char = table[0];
	size_t unique_chars = my_strlen(table);

	struct info inf;
	inf.text = text;
	inf.table = table;
	inf.unique_chars = unique_chars;

	for (size_t i = 1; i <= unique_chars; i++)
	{
		size_t freq = 0;
		curr_char = next_alpha(text, curr_char);
		freq = count(text, curr_char);

		unique_char = find_corresponding(inf, freq, 91);

		printf("%c %c\n", curr_char, unique_char);
	}
}
