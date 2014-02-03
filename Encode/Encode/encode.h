//header for encode.c

#define FIRST_LC_LETTER 'a'
#define LAST_LC_LETTER  'z'
#define FIRST_CP_LETTER 'A'
#define LAST_CP_LETTER 'Z'

void testEncode(void);
int isLowerCase(char letter);
char encode(char plainText);
int isHigherCase(char letter);