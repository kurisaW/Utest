/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2022-10-31     Yifang       the first version
 */

#include <rtthread.h>
#include "utest.h"

static void test_memcmp_uint8(void)
{
    rt_uint8_t *a1 = "abe";
    rt_uint8_t *a2 = "acf";
    rt_uint8_t *a3 = "abe";
    rt_uint8_t *a4 = "abcde";

    uint8_t r = rt_memcmp(&a1, &a2, 3);
    uint8_t k = rt_memcmp(&a1, &a3, 3);

    uassert_true(r);
    uassert_null(k);
    uassert_int_not_equal(&a1, &a4);
}

static void test_memcmp_uint16(void)
{
    rt_uint16_t *a1 = 1;
    rt_uint16_t *a2 = 2;
    rt_uint16_t *a3 = 1;
    rt_uint16_t *a4 = 5;

    uint16_t r = rt_memcmp(&a1, &a2, 1);
    uint16_t k = rt_memcmp(&a1, &a3, 1);

    uassert_true(r);
    uassert_null(k);
    uassert_int_not_equal(&a1, &a4);
}

static void test_memcmp_uint32(void)
{
    rt_uint32_t *a1 = 123;
    rt_uint32_t *a2 = 134;
    rt_uint32_t *a3 = 123;
    rt_uint32_t *a4 = 1234;

    uint32_t r = rt_memcmp(&a1, &a2, 2);
    uint32_t k = rt_memcmp(&a1, &a3, 2);

    uassert_true(r);
    uassert_null(k);
    uassert_int_not_equal(a1, a4);
}

static void test_memcmp_string(void)
{
    char *a1 = "abe";
    char *a2 = "acf";
    char *a3 = "abe";
    char *a4 = "abcde";

    char r = rt_memcmp(&a1, &a2, 3);
    char k = rt_memcmp(&a1, &a3, 3);

    uassert_true(r);
    uassert_null(k);
    uassert_str_not_equal(&a1, &a4);
}

static void test_memcmp_struct(void)
{
    struct Info
    {
        char a;
        int b;
    };

    struct Info i1;
    struct Info i2;
    i1.a = 'a';
    i2.a = 'a';
    i1.b = '1';
    i2.b = '1';

    int c = rt_memcmp(&i1, &i2, sizeof(struct Info));

    uassert_false(c);
    uassert_str_equal(i1.a, i2.a);
    uassert_int_equal(i1.b,i2.b);
}

static rt_err_t utest_tc_init(void)
{
    return RT_EOK;
}

static rt_err_t utest_tc_cleanup(void)
{
    return RT_EOK;
}

static void testcase(void)
{
    UTEST_UNIT_RUN(test_memcmp_uint8);
    UTEST_UNIT_RUN(test_memcmp_uint16);
    UTEST_UNIT_RUN(test_memcmp_uint32);
    UTEST_UNIT_RUN(test_memcmp_string);
    UTEST_UNIT_RUN(test_memcmp_struct);
}
UTEST_TC_EXPORT(testcase, "components.utilities.utest.sample.sample_tc", utest_tc_init, utest_tc_cleanup, 10);
