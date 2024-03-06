/**
 * @file common.c
 * @brief a sample for pybind11, doxygen and sphinx.
 * @details None
 * @author kuanghl
 * @version v01.00.00
 * @date 2023-03-06
 * @copyright MIT
 */

#include "common.h"
#include "stdint.h"
#include "stdlib.h"
#include "string.h"
#include "stdio.h"

int add_fn(int a, int b) {
    return a + b;
}

void printf_color(void){

    // \0 33 OCT
    printf("\033[1;31mThis text is red.\033[0m\n");
    printf("\033[1;32mThis text is green.\033[0m\n");
    printf("\033[1;33mThis text is yellow.\033[0m\n");
    printf("\033[1;34mThis text is blue.\033[0m\n");
    printf("\033[1;35mThis text is magenta.\033[0m\n");
    printf("\033[1;36mThis text is cyan.\033[0m\n");
    printf("\033[1;37;44mThis text is white.\033[m\n");
    printf("This text is default.\n");

    // \x 1b HEX
    printf("\x1b[1;31mThis text is red.\x1b[0m\n");
    printf("\x1b[1;32mThis text is green.\x1b[0m\n");
    printf("\x1b[1;33mThis text is yellow.\x1b[0m\n");
    printf("\x1b[1;34mThis text is blue.\x1b[0m\n");
    printf("\x1b[1;35mThis text is magenta.\x1b[0m\n");
    printf("\x1b[1;36mThis text is cyan.\x1b[0m\n");
    printf("\x1b[1;37;44mThis text is white.\x1b[m\n");
    printf("This text is default.\n");
}

char *swap_str_maxlen(char* a, char* b, unsigned int alen, unsigned int blen) {
    char *temp = (char *)calloc(1, (alen >= blen ? alen : blen));
    memcpy(temp, a, alen);
    memcpy(a, b, (alen >= blen ? blen : alen));
    memcpy(b, temp, (alen >= blen ? blen : alen));

    if(alen >= blen){
        return b;
    } 
    else{
        return a;
    }
}

uint8_t *swap_u8_max(uint8_t* a, uint8_t* b) {
    uint8_t temp = *a;
    *a = *b;
    *b = temp;
    return (*a >= *b ? a : b);
}

uint16_t *swap_u16_max(uint16_t* a, uint16_t* b) {
    uint16_t temp = *a;
    *a = *b;
    *b = temp;
    return (*a >= *b ? a : b);
}

uint32_t *swap_u32_max(uint32_t* a, uint32_t* b) {
    uint32_t temp = *a;
    *a = *b;
    *b = temp;
    return (*a >= *b ? a : b);
}

void *void_fn(void *val, int set_val) {
    printf("val = %d\n", *((int*)val));
    *((int*)val) = set_val;
    return val;
}


/**
 * @struct cval_s
 * @brief there is a structure for pybind11 test
*/
struct cval_s
{
    /* data */
    uint8_t val0;   /*!< 定义一个整型变量val0 */
    uint16_t val1;  /*!< 定义一个整型变量val0 */
    uint32_t val2;  /*!< 定义一个整型变量val0 */
    uint64_t val3;  /*!< 定义一个整型变量val0 */
    char *str0;     /*!< 定义一个整型变量str0 */
    char str1[256]; /*!< 定义一个整型变量str1 */
}cval_t;


void *struct_fn(struct cval_s *cval, uint8_t val0, 
    uint16_t val1, uint32_t val2, uint64_t val3, const char* str0) 
{
    char *str1 = cval->str1;
    str1 = "Hello world\n";

    printf("val0 %d\n", cval->val0);
    printf("val1 %d\n", cval->val1);
    printf("val2 %d\n", cval->val2);
    printf("val3 %lld\n", cval->val3);
    printf("str0 %s\n", cval->str0);
    printf("str1 %s\n", cval->str1);

    cval->val0 = val0;
    cval->val1 = val1;
    cval->val2 = val2;
    cval->val3 = val3;
    cval->str0 = str0;

    return cval;
}

/**
 * @union uval_s
 * @brief there is a union for pybind11 test
*/
union uval_s
{
    /**
     * @struct u_s
     * @brief there is a structure for pybind11 test
    */
    struct u_s
    {
        uint8_t bit0 : 1;
        uint8_t bit1 : 1;
        uint8_t bit2 : 1;
        uint8_t bit3 : 1;
        uint8_t bit4 : 1;
        uint8_t bit5 : 1;
        uint8_t bit6 : 1;
        uint8_t bit7 : 1;   // 1bytes
        uint8_t val0;       // 2bytes
        uint16_t val1;      // 4bytes
        uint32_t val2;      // 8bytes
        uint64_t val3;      // 16bytes
        uint8_t val4;       // 24bytes
        uint8_t val5;       // 24bytes
    }u_t;

    /**
     * @struct p_s
     * @brief there is a structure for pybind11 test
    */
    struct p_s
    {
        uint64_t size;  // 8bytes
        uint32_t blen;  // 16bytes
        uint32_t count; // 16bytes
        uint64_t valp;  // 24bytes
    }p_t;
}uval_t;


void *union_fn(void){
    sizeof(uval_t);
}