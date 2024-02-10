
#include <stdio.h>
#include <stdint.h>
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include "cmocka.h"
#include <string.h>
#include "ratp.h"
#include "age.h"




static int setup(void **state) {
    (void) state;
    printf("setUp");
 return 0;
}
static int teardown(void **state) {
    (void) state;
    printf("tearDown");
     return 0;
}

/* A test case that does nothing and succeeds. */
static void null_test_success(void **state) {
    (void) state;
}

// ==== Q1 ====
static void q1_wrong_test(void** state){
    (void) state;
    float absurd = 999;
    float prix = computePrice(6,0);
    assert_float_equal(absurd, prix, 0);
}


// ==== Q2 ====
static void q2_wrong_test(void** state){
    (void) state;
    float absurd = 42;
    float prix = computePrice(6,0);
    assert_true(absurd == prix);
}

// ==== Q6 ====
void recupAge(int* limitAge){
    *limitAge = (int)mock();
}

static void limAge_test(void **state){
    (void) state;
    float expected = 2.4;
    will_return(recupAge,12);
    float prix = computePrice2(20,1);
    
    assert_float_equal(expected ,prix, 0.001);
}

// ==== Full coverage ====

static void older_not_tourist(void **state){
    (void) state;
    will_return(recupAge,12);
    float expected = 1.2;
    float prix = computePrice2(15,0);
    assert_float_equal(expected ,prix, 0.001);
}

static void younger_not_tourist(void **state){
    (void) state;
    will_return(recupAge,12);
    float expected = 0.6;
    float prix = computePrice2(8,0);
    assert_float_equal(expected ,prix, 0.001);
}

static void older_tourist(void **state){
    (void) state;
    will_return(recupAge,12);
    float expected = 2.4;
    float prix = computePrice2(15,1);
    assert_float_equal(expected ,prix, 0.001);
}

static void younger_tourist(void **state){
    (void) state;
    will_return(recupAge,12);
    float expected = 1.2;
    float prix = computePrice2(8,1);
    assert_float_equal(expected ,prix, 0.001);
}

// #define QUESTIONS

int main(void) {
    const struct CMUnitTest tests[] = {
        #ifdef QUESTIONS
        cmocka_unit_test(null_test_success),
        cmocka_unit_test(q1_wrong_test),
        cmocka_unit_test(q2_wrong_test),
        cmocka_unit_test_setup(q1_wrong_test, setup),
        cmocka_unit_test_teardown(q1_wrong_test, teardown),
        cmocka_unit_test(limAge_test)
        #else
        cmocka_unit_test(older_not_tourist),
        cmocka_unit_test(older_tourist),
        cmocka_unit_test(younger_not_tourist),
        cmocka_unit_test(younger_tourist)
        #endif 
    };
 //   cmocka_set_message_output(CM_OUTPUT_XML);
    return cmocka_run_group_tests_name("toto",tests, setup, teardown);
}
