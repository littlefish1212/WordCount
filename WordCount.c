#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
#include <ctype.h>  
  
// ��������  
int count_chars(FILE *file);  
int count_words(FILE *file);  
  
int main(int argc, char *argv[]) {  
    if (argc != 3) {  
        fprintf(stderr, "Usage: %s [-c|-w] [input_file_name]\n", argv[0]);  
        return 1;  
    }  
  
    FILE *file = fopen(argv[2], "r");  
    if (!file) {  
        perror("Error opening file");  
        return 1;  
    }  
  
    int result;  
    if (strcmp(argv[1], "-c") == 0) {  
        result = count_chars(file);  
        printf("�ַ�����%d\n", result);  
    } else if (strcmp(argv[1], "-w") == 0) {  
        result = count_words(file);  
        printf("��������%d\n", result);  
    } else {  
        fprintf(stderr, "Invalid parameter: %s\n", argv[1]);  
        fclose(file);  
        return 1;  
    }  
  
    fclose(file);  
    return 0;  
}  
  
int count_chars(FILE *file) {  
    int chars = 0;  
    int c;  
    while ((c = fgetc(file)) != EOF) {  
        chars++;  
    }  
    rewind(file); // �����ļ�ָ�뵽�ļ���ʼ���Ա���һ���������Զ�ȡ  
    return chars;  
}  
  
int count_words(FILE *file) {  
    int words = 0;  
    int in_word = 0;  
    int c;  
    while ((c = fgetc(file)) != EOF) {  
        if (isspace(c) || c == ',') {  
            if (in_word) {  
                words++;  
                in_word = 0;  
            }  
        } else {  
            in_word = 1;  
        }  
    }  
    // ����ļ�ĩβ�Ƿ���δ�����ĵ���  
    if (in_word) {  
        words++;  
    }  
    return words;  
}

