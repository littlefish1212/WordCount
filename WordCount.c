#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
#include <ctype.h>  
  
// 函数声明  
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
        printf("字符数：%d\n", result);  
    } else if (strcmp(argv[1], "-w") == 0) {  
        result = count_words(file);  
        printf("单词数：%d\n", result);  
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
    rewind(file); // 重置文件指针到文件开始，以便下一个函数可以读取  
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
    // 检查文件末尾是否有未计数的单词  
    if (in_word) {  
        words++;  
    }  
    return words;  
}

