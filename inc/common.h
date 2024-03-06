/**
 * @file common.h
 * @brief a sample for pybind11, doxygen and sphinx.
 * @details None
 * @author kuanghl
 * @version v01.00.00
 * @date 2023-03-06
 * @copyright MIT
 */

#ifndef __COMMON_H__
#define __COMMON_H__

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief 这个函数用于计算两个数的和
 * @param a 第一个参数
 * @param b 第二个参数
 * @return 返回两个数的和
 */
int add_fn(int a, int b);

/**
 * @brief 一个简单的颜色打印函数
 * @retval void
 */
void printf_color(void);

/**
 * @brief Set a value to a pointer
 * @param val pointer address
 * @param set_val transfer into value
 * @retval pointer address space will be set
 */
void *void_fn(void *val, int set_val);

/**
 * @brief Swap two string.
 * @see swap_u8_max() swap_u16_max() swap_u32_max
 * @param a the first argument for a-string.
 * @param b the second argument for b-string.
 * @param alen the thrid argument for a-string len.
 * @param blen the fourth argument for b-string len.
 * @return return maxlen string
 */
char *swap_str_maxlen(char* a, char* b, unsigned int alen, unsigned int blen);


#ifdef __cplusplus
}
#endif

#endif // !__COMMON_H__