#include <stdlib.h>
#include <stdio.h>

typedef struct {
	char* data;
	long long int len;
} kstring;

long long int string_len(char* s){
	long long int res = 0;
	while(*s != '\0'){
		res++;
		s++;
	}
	return res;
}

kstring* create_string(char* str){
	kstring* pnt = malloc(sizeof(kstring));

	pnt->data = malloc(sizeof(char) * string_len(str));
	pnt->len = string_len(str);

	int i;

	for(i = 0; i < string_len(str);i++)
		pnt->data[i] = str[i];

	return pnt;
}

void delete_string(kstring* str){
	free(str->data);
	free(str);
}

void append(kstring* str, char ch){
	char* result = malloc(sizeof(char) * (str->len + 1));

	long long int i;

	for(i = 0; i < str->len; i++){
		result[i] = str->data[i];
	}

	result[str->len] = ch;
	str->len++;
	free(str->data);
	str->data = result;
}

void replace(kstring* str, char a, char b){
	long long int i;
	for(i = 0; i < str->len; i++){
		if(str->data[i] == a){
			str->data[i] = b;
			return;
		}
	}
}

void replace_all(kstring* str, char a, char b){
	long long int i;
	for(i = 0; i < str->len; i++){
		if(str->data[i] == a)
		str->data[i] = b;
	}
}


void strprint(kstring* string){
	printf(string->data);
}

int contains(kstring* string, char ch){
	long long int i;
	for(i = 0; i < string->len; i++){
		if(string->data[i] == ch)
			return 1;
	}
	return 0;
}

int contain_str(kstring* string, char* a){
	int contain;
	long long int copy;
	long long int i;
	long long int j;
	for(i = 0; i < string->len;i++){
		copy = i;
		for(j = 0; j < string_len(a);j++){
			if(string->data[copy] == a[j])
				contain = 1;
			else {
				contain = 0;
				break;
			}
			copy++;
		}
		if(contain){
			return 1;
		}
	}
	return 0;
}
