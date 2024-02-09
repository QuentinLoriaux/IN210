
#include <stdio.h>
#include <stdint.h>
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include "cmocka.h"
#include <string.h>
#include "ratp.h"
#include "age.h"

/* A test case that does nothing and succeeds. */



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
static void null_test_success(void **state) {
    (void) state;
}

// ==== Q1 ====
static void q1_wrong_test(void** state){
    (void) state;
    float prix = computePrice(6,0);
    assert_float_equal(0.67, prix, 0);
}
/*
Pour comparer des flottants, il est nécessaire de demander une précision car la précision n'est pas infinie
*/

// ==== Q2 ====
static void q2_wrong_test(void** state){
    (void) state;
    float prix = computePrice(6,0);
    assert_true(42 == prix);
}
/*
Il vaut mieux utiliser utiliser un assert_float_equal avec un epsilon inférieur à 0.01 (centime)
*/

/*//////////////////////////////////
faire tous les trucs de tests...
//////////////////////////////////*/

// ==== Q6 ====
void recupAge(int* limitAge){
    *limitAge = (int)mock();
}

static void limAge_test(void **state){
    (void) state;
    will_return(recupAge,12);
    float prix = computePrice(20.0,0);
    assert_float_equal(999,prix, 0.001);
}


int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(null_test_success),
        cmocka_unit_test(q1_wrong_test),
        // cmocka_unit_test(q2_wrong_test),
        // cmocka_unit_test_setup(q1_wrong_test, setup),
        // cmocka_unit_test_teardown(q1_wrong_test, teardown),
        cmocka_unit_test(limAge_test)
    };
 //   cmocka_set_message_output(CM_OUTPUT_XML);
    return cmocka_run_group_tests_name("toto",tests, setup, teardown);
}
