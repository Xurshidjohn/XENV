#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
const char *text = "[font] = `Menlo`;[salom] = `salom`";
const char words[100];

typedef enum TokenType {BRACK_L = 0,LETTER = 1,BRACK_R = 2,
EQUAL = 3,QUOTE = 4,COLON = 5,BACK_TAG = 6,SPACE = 7} t_type;
typedef enum KEYWORD{KEY = 0,VALUE = 1} KEYWORD;
typedef struct Token {t_type type;char value;} t_token;
typedef struct Token_v2 {KEYWORD type;char *value;} token_v2;

t_token tokens[200];
token_v2 v2_tokens[200];
int i_token = 0, v2_token_i = 0;
void display_token(t_token token)
{
	printf("<Token value='%c' type='%d'>\n", token.value, token.type);
}

char *get_keys() {
int flag = 0;
 	char *key = malloc(100 * sizeof(char*));int key_i = 0;
	for(int i = 0;i < 200;i++) {
		if(tokens[i].value == '[') {
			flag = 1;
		}
		if(tokens[i-1].value == ']') {
			struct Token_v2 token;
			token.type =1;
			token.value = malloc(100 * sizeof(char*));
			strcpy(token.value, key);
			v2_tokens[v2_token_i] = token;
			v2_token_i++;key_i=0;key[0]='\0';flag=0;
		}
		if(flag == 1) {
			key[key_i] = tokens[i].value;
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
			case '"':token.type = 4;token.value = text[i];tokens[i_token] = token;i_token++;break;
			case '[':token.type = 0;token.value = text[i];tokens[i_token] = token;i_token++;break;
			case ']':token.type = 2;token.value = text[i];tokens[i_token] = token;i_token++;break;
			case '=':token.type = 3;token.value = text[i];tokens[i_token] = token;i_token++;break;
			case ';':token.type = 5;token.value = text[i];tokens[i_token] = token;i_token++;break;
			case '`':token.type = 6;token.value = text[i];tokens[i_token] = token;i_token++;break;
			case ' ':token.type = 7;token.value = text[i];tokens[i_token] = token;i_token++;break;
			default:token.type = 1;token.value = text[i];tokens[i_token] = token;i_token++;break; 
		}i++;
	}
}
int main() {
	tokenizer(text);
	get_keys();
	for(int i = 0;i < 10;i++) {
		if(v2_tokens[i].type == 1 || v2_tokens[i].type == 0) {
			printf("%s", v2_tokens[i].value); // ERROR BOR MANA SHU QATORDA NAXUY
		}
	}
}
