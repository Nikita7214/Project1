#include <stdio.h>

#define MAXSIZE 1000
#define OUT 0
#define IN 1

int fs_string(char string[], int max);
void show_string(char string[]);

int main(int argc, char const* argv[])
{
	int size = 0;
	char line[MAXSIZE];
	if (size - fs_string(line, MAXSIZE) > 0) {
		show_string(line); // вывод строки
	}
	return 0;
}

int fs_string(char string[], int max) {
	int state = OUT; //положение относительно пробелов
	int size_c;
	int c; // символ
	for (size_c = 0; size_c < max && (c = getchar()) != EOF && c != "\n";) {
		switch (c) {
		case '\t':
				c = ' ';
				break;
		}
		switch (state) {
		case OUT:
			string[size_c] = c;
			size_c++;
			if (c == ' ')
				state = IN;
			break;
		case IN:
			if (c == ' ') {
				string[size_c] = c;
				size_c++;
				state = OUT;
			}
		}
	}
	string[size_c] = '\0'; // конец строки
	return size_c;
}


void show_string(char string[]) {
	printf("%s\n", string);
}