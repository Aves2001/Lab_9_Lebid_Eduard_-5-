   /*/----------------------!!!----------------------------/*/
  /*/ Before compilation Save with Encoding Windows 1251  /*/
 /*/              Saved in Encoding UTF-8                /*/
/*/-------------------------!!!-------------------------/*/
#include <stdio.h>
#include <stdlib.h>
#include "default_cfg.h"
#include <string.h>
                                 /////////////////////////////////////////////////////////////
#define _yellow SetColor(14,0); // жовний вивід тексту на екран + чорний фон               //
#define _red SetColor(12,0);   // червоний вивід тексту на екран + чорний фон             //
#define _green SetColor(10,0);// повернення зеленого виводу тексту на екран + чорний фон //
                             /////////////////////////////////////////////////////////////

void copy(char *s1, char *result); // Копіює фрагмент тексту, заданий користувачем, з одного рядка в інший

int main(void) {
start_cfg(); //default_cfg.h

char s1[] = "Створити програми для розв’язування задачі згідно свого варіанту.";//Речення з якого відбувається копіювання

puts("\nРечення з якого відбувається копіювання:");
_yellow
puts(s1);
_green

char *s2 = (char*)malloc(strlen(s1)); // рядок в який потрібно скопіювати фрагмент тексту

copy(s1, s2); // копіювання фрагмента тексту з рядка s1 в рядок s2, 

printf("\n\nРезультат виконання функції:\n");
_yellow
puts(s2);
_green

end_cfg(); //default_cfg.h
return 0;
}

//////////////////////////////////////////////////////////////////////////////////
void copy(char *s1, char *result){

_Bool error, errors; //error - окремо повторне введення початку і кінця речення | errors - повторне введення початку і кінця речення
char *s2 = (char*)malloc(strlen(s1)); // виділення памяті для вмісту початку речення, з таким же розміром як і у речення яке передали у функцію
char *s3 = (char*)malloc(strlen(s1));// виділення памяті для вмісту кінця речення, з таким же розміром як і у речення яке передали у функцію
char *x; //зберігає позицію першого входження рядка s2 в рядок s1.
char *y; //зберігає позицію першого входження рядка s3 в рядок s1.
int index_x = 0; // індекс від якого потрібно копіювати
int index_y = 0; // індекс до якого потрібно копіювати
int k=0; // лічильник для масива в який відбувається копіювання
int size; // розмір масива в який відбувається копіювання

do{do{
error = 0;
errors = 0;
puts("\nВведіть початок речення, звідки копіювати:");
_yellow
gets(s2);
_green

if (s2[0] == 0)
{
	_red
	printf("Потрібно хоть щось ввести\n");
	_green
	error = 1;
	continue;
}

x = strstr(s1, s2);

if (x == NULL)
{
	_red
	printf("\nВ реченні такого фрагмента не знайдено, корректно введіть дані\n");
	_green
	error = 1;
}}while(error == 1);

do{
error = 0;
puts("\nВведіть кінець речення, доки копіювати:");
_yellow
gets(s3);
_green

if (s3[0] == 0)
{
	_red
	printf("Потрібно хоть щось ввести\n");
	_green
	error = 1;
	continue;
}

y = strstr(s1, s3);

if (y == NULL)
{
	_red
	printf("\nВ реченні такого фрагмента не знайдено, корректно введіть дані\n");
	_green
	error = 1;
	continue;
}}while(error == 1);

index_x = (x - &s1[0]); // індекс початку
index_y = (y - &s1[0] + strlen(s3))-1; // індекс кінця

if (index_x > index_y)
{
	_red
	printf("\nВи задали індекси наоборот неможливо виконати копіювання з %d[%c] по %d[%c]\n", index_x, s1[index_x], index_y, s1[index_y]);
	_green
	errors = 1;
	continue;
}}while(errors == 1);
// printf("index_x = %d\n", index_x);// debug
// printf("index_y = %d\n", index_y);// debug
// printf("index_y-index_x = %d\n", index_y-index_x);// debug
// system("pause");// debug

size = index_y-index_x;

while(k <= size){
	// printf("%c", s1[index_x]); // debug
	result[k] = s1[index_x];
	k++;
	index_x++;
}
result[size+1] = '\0';
}