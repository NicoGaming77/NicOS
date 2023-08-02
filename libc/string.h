#ifndef STRING_H
#define STRING_H

void int_to_ascii(int n, char str[]);
void hex_to_ascii(int n, char str[]);
void reverse(char s[]);
int strlen(char s[]);
void backspace(char s[]);
void append(char s[], char n);
int strcmp(char s1[], char s2[]);
char upper(char c);
char lower(char c);
int isspace(char c);
int isalpha(char c);

#endif
