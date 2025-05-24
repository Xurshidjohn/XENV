#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
const char *text = "[font] = `Menlo`;";
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

t_token tokens[200] = {};
int i_token = 0;
void display_token(t_token token)
{

	printf("<Token value='%c' type='%d'>\n", token.value, token.type);
}

char *get_keys() {
 	int flag = 0;
 	char *key = malloc(100 * sizeof(char*));
 	int key_i = 0;
	for(int i = 0;i < 200;i++) {
		if(tokens[i].value == '[') {
			flag = 1;
		}

		if(tokens[i-1].value == ']') {
			flag = 0;
		}
		
		if(flag == 1) {
			key[key_i] = tokens[i].value;
			printf("%c", key[key_i]);
			key_i++;
		}
	}
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
				tokens[i_token] = token;
				i_token++;
				break;
			case '[':
				token.type = 0;
				token.value = text[i];
				tokens[i_token] = token;
				i_token++;
				break;
			case ']':
				token.type = 2;
				token.value = text[i];
				tokens[i_token] = token;
				i_token++;
				break;
			case '=':
				token.type = 3;
				token.value = text[i];
				tokens[i_token] = token;
				i_token++;
				break;
			case ';':
				token.type = 5;
				token.value = text[i];
				tokens[i_token] = token;
				i_token++;
				break;
			case '`':
				token.type = 6;
				token.value = text[i];
				tokens[i_token] = token;
				i_token++;
				break;
			case ' ':
				token.type = 7;
				token.value = text[i];
				tokens[i_token] = token;
				i_token++;
				break;
			default:
				token.type = 1;
				token.value = text[i];
				tokens[i_token] = token;
				i_token++;
				break; 
		}
		//display_token(token);
		i++;
	}
}
int main() {
	tokenizer(text);
	get_keys();
}
