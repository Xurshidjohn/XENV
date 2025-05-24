#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
const char *text = "[font] = `Jetbrains Mono`;";
const char words[100];

typedef enum TokenType {
	BRACK_L = 0,
	LETTER = 1,
	BRACK_R = 2,
	EQUAL = 3,
	QUOTE = 4,
	COLON = 5,
	BACK_TAG = 6,
	SPACE = 7
} t_type;

typedef struct Token {
	t_type type;
	char value;
} t_token;

void display_token(t_token token)
{

	printf("<Token value='%c' type='%d'>\n", token.value, token.type);
}

void tokenizer(char *text)
{
	int i = 0;
	while(text[i] != '\0') {
		struct Token token;
		switch(text[i]) {
			case '"':
				token.type = 4;
				token.value = text[i];
				break;
			case '[':
				token.type = 0;
				token.value = text[i];
				break;
			case ']':
				token.type = 2;
				token.value = text[i];
				break;
			case '=':
				token.type = 3;
				token.value = text[i];
				break;
			case ';':
				token.type = 5;
				token.value = text[i];
				break;
			case '`':
				token.type = 6;
				token.value = text[i];
				break;
			case ' ':
				token.type = 7;
				token.value = text[i];
				break;
			default:
				token.type = 1;
				token.value = text[i];
				break; 
		}
		display_token(token);
		i++;
	}
}

int main() {
	tokenizer(text);
}
