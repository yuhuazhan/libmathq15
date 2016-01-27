/*******************************************************************************
 *    INCLUDED FILES
 ******************************************************************************/
 
//-- unity: unit test framework
#include "unity.h"
#include "libmathq15.h"
 
//-- module being tested
//   TODO
 
 
/*******************************************************************************
 *    DEFINITIONS
 ******************************************************************************/
 
/*******************************************************************************
 *    PRIVATE TYPES
 ******************************************************************************/
 
/*******************************************************************************
 *    PRIVATE DATA
 ******************************************************************************/
 
 
/*******************************************************************************
 *    PRIVATE FUNCTIONS
 ******************************************************************************/
 
 
/*******************************************************************************
 *    SETUP, TEARDOWN
 ******************************************************************************/
 
void setUp(void)
{
}
 
void tearDown(void)
{
}
 
/*******************************************************************************
 *    TESTS
 ******************************************************************************/
void test_q15_to_dbl_0(void){
    TEST_ASSERT_FLOAT_WITHIN(0.000031, 0, q15_to_dbl(0));
}

void test_q15_to_dbl_16384(void){
    TEST_ASSERT_FLOAT_WITHIN(0.000031, 0.5, q15_to_dbl(16384));
}

void test_q15_to_dbl_n16384(void){
    TEST_ASSERT_FLOAT_WITHIN(0.000031, -0.5, q15_to_dbl(-16384));
}

void test_q15_to_dbl_32767(void){
    TEST_ASSERT_FLOAT_WITHIN(0.000031, 1.0, q15_to_dbl(32767));
}

void test_q15_to_dbl_n32768(void){
    TEST_ASSERT_FLOAT_WITHIN(0.000031, -1.0, q15_to_dbl(-32768));
}

void test_q15_to_float_0(void){
    TEST_ASSERT_FLOAT_WITHIN(0.000031, 0, q15_to_float(0));
}

void test_q15_to_float_16384(void){
    TEST_ASSERT_FLOAT_WITHIN(0.000031, 0.5, q15_to_float(16384));
}

void test_q15_to_float_n16384(void){
    TEST_ASSERT_FLOAT_WITHIN(0.000031, -0.5, q15_to_float(-16384));
}

void test_q15_to_float_32767(void){
    TEST_ASSERT_FLOAT_WITHIN(0.000031, 1.0, q15_to_float(32767));
}

void test_q15_to_float_n32768(void){
    TEST_ASSERT_FLOAT_WITHIN(0.000031, -1.0, q15_to_float(-32768));
}

void test_q15_to_int_0(void){
    TEST_ASSERT_EQUAL_INT16(0, q15_to_int(0));
}

void test_q15_to_int_16383(void){
    TEST_ASSERT_EQUAL_INT16(0, q15_to_int(16383));
}

void test_q15_to_int_16384(void){
    TEST_ASSERT_EQUAL_INT16(1, q15_to_int(16384));
}

void test_q15_to_int_n16383(void){
    TEST_ASSERT_EQUAL_INT16(0, q15_to_int(-16383));
}

void test_q15_to_int_n16384(void){
    TEST_ASSERT_EQUAL_INT16(-1, q15_to_int(-16384));
}

void test_q15_from_dbl_0(){
    TEST_ASSERT_EQUAL_INT16(0, q15_from_dbl(0));
}

void test_q15_from_dbl_0500(){
    TEST_ASSERT_EQUAL_INT16(16384, q15_from_dbl(0.5));
}

void test_q15_from_dbl_1000(){
    TEST_ASSERT_EQUAL_INT16(32767, q15_from_dbl(1.0));
}

void test_q15_from_dbl_n0500(){
    TEST_ASSERT_EQUAL_INT16(-16384, q15_from_dbl(-0.5));
}

void test_q15_from_dbl_n1000(){
    TEST_ASSERT_EQUAL_INT16(-32768, q15_from_dbl(-1.0));
}

void test_q15_from_float_0(){
    TEST_ASSERT_EQUAL_INT16(0, q15_from_float(0));
}

void test_q15_from_float_0500(){
    TEST_ASSERT_EQUAL_INT16(16384, q15_from_float(0.5));
}

void test_q15_from_float_1000(){
    TEST_ASSERT_EQUAL_INT16(32767, q15_from_float(1.0));
}

void test_q15_from_float_n0500(){
    TEST_ASSERT_EQUAL_INT16(-16384, q15_from_float(-0.5));
}

void test_q15_from_float_n1000(){
    TEST_ASSERT_EQUAL_INT16(-32768, q15_from_float(-1.0));
}

void test_q15_from_int_0(){
    TEST_ASSERT_EQUAL_INT16(0, q15_from_int(0));
}

void test_q15_from_int_1(){
    TEST_ASSERT_EQUAL_INT16(32767, q15_from_int(1));
}

void test_q15_from_int_2(){
    TEST_ASSERT_EQUAL_INT16(32767, q15_from_int(2));
}

void test_q15_from_int_n1(){
    TEST_ASSERT_EQUAL_INT16(-32768, q15_from_int(-1));
}

void test_q15_from_int_n2(){
    TEST_ASSERT_EQUAL_INT16(-32768, q15_from_int(-2.0));
}

void test_q15_mul_32767x32767(void)
{
    q15_t multiplier = 32767;
    q15_t multiplicand = 32767;
    q15_t result = q15_mul(multiplier, multiplicand);
    
    TEST_ASSERT_EQUAL_INT16(32766, result);
}

void test_q15_mul_32767xneg32768(void)
{
    q15_t multiplier = -32768;
    q15_t multiplicand = 32767;
    q15_t result = q15_mul(multiplier, multiplicand);
    
    TEST_ASSERT_EQUAL_INT16(-32767, result);
}

void test_q15_mul_neg32768xneg32768(void)
{
    q15_t multiplier = -32768;
    q15_t multiplicand = -32768;
    q15_t result = q15_mul(multiplier, multiplicand);
    
    TEST_ASSERT_EQUAL_INT16(-32768, result);
}

void test_q15_mul_0x0(void)
{
    q15_t multiplier = 0;
    q15_t multiplicand = 0;
    q15_t result = q15_mul(multiplier, multiplicand);
    
    TEST_ASSERT_EQUAL_INT16(0, result);
}

void test_q15_mul_16384xneg16384(void)
{
    q15_t multiplier = 16384;
    q15_t multiplicand = -16384;
    q15_t result = q15_mul(multiplier, multiplicand);
    
    TEST_ASSERT_EQUAL_INT16(-8192, result);
}

void test_q15_div_0_0(void){
    q15_t result = q15_div(0, 0);
    
    TEST_ASSERT_EQUAL_INT16(32767, result);
}

void test_q15_div_1_0(void){
    q15_t result = q15_div(1, 0);
    
    TEST_ASSERT_EQUAL_INT16(32767, result);
}

void test_q15_div_n1_0(void){
    q15_t result = q15_div(-1, 0);
    
    TEST_ASSERT_EQUAL_INT16(-32768, result);
}

void test_q15_div_16384_n32768(void){
    q15_t result = q15_div(16384, -32768);
    
    TEST_ASSERT_EQUAL_INT16(-16384, result);
}

void test_q15_div_n16384_32767(void){
    q15_t result = q15_div(-16384, 32767);
    
    TEST_ASSERT_EQUAL_INT16(-16384, result);
}

void test_q15_add_0_0(void){
    TEST_ASSERT_EQUAL_INT16(0, q15_add(0,0));
}

void test_q15_add_100_n100(void){
    TEST_ASSERT_EQUAL_INT16(0, q15_add(100,-100));
}

void test_q15_add_32000_1000(void){
    TEST_ASSERT_EQUAL_INT16(32767, q15_add(32000,1000));
}

void test_q15_add_n32000_n1000(void){
    TEST_ASSERT_EQUAL_INT16(-32768, q15_add(-32000,-1000));
}

void test_q15_abs_0(void){
    TEST_ASSERT_EQUAL_INT16(0, q15_abs(0));
}

void test_q15_abs_16384(void){
    TEST_ASSERT_EQUAL_INT16(16384, q15_abs(-16384));
}

void test_q15_abs_n16384(void){
    TEST_ASSERT_EQUAL_INT16(16384, q15_abs(-16384));
}

void test_q15_sqrt_8192(void){
    TEST_ASSERT_EQUAL_INT16(16384, q15_sqrt(8192));
}

void test_q15_sqrt_1000(void){
    /* actual should be closer to 5724, but this loss of resolution is acceptable */
    TEST_ASSERT_EQUAL_INT16(5728, q15_sqrt(1000));
}

void test_q15_sqrt_0(void){
    /* sqrt doesn't work well at low values */
    TEST_ASSERT_EQUAL_INT16(182, q15_sqrt(0));
}
