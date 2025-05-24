#include <stdio.h>

const char *text = "[ font ] = `Jetbrains Mono`";
const char words[100];

typedef enum TokenType {
	BRACK_L = 0,
	LETTER = 1,
	BRACK_R = 2,
	EQUAL = 3,
	QUOTE = 4,
	COLON = 5
} t_type;

struct Token {
	t_type type;
	char *value;
};

void tokenizer(char *text){
	int i = 0;
	while(text[i] != '\0') {
		printf("%c\n", text[i]);
		i++;
	}
}




int main() {
	tokenizer(text);
}