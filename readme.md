# Q1.15 Library for 8- and 16-bit Embedded Applications #

For a good look at how Q-math operations work, head over to  [for(embed)](http://www.forembed.com/how-fixed-point-math-works.html) and drop a line!

There are a number of math libraries that support Q16.16 and some other fixed-point notations, but I have noted a distinct lack of open-source libraries for Q1.15.  In most applications, Q1.15 math will work well enough to get the job done and there should be an easy-to-use, open source, and optimized library for it.

This library is currently fully tested on the Microchip PIC24 and dsPIC33 series of microcontrollers using optimized code.  See [for(embed)](http://www.forembed.com/testing-the-accuracy-of-libmathq15-on-the-pic24.html) for details.

My reasons for wanting to create this repository:
 1. Every chip maker already has their own implementation which is different from everyone else.
 2. Compiler libraries can change with a different version of compiler.  This library will generate new '.a' files requiring more testing, which may not actually be necessary.
 3. Beginners can easily include these files without having to resort to loading library files - which can be challenging for a beginner.
 4. To share some knowledge
 5. Have fun!

# Contributions #

 * optimizations - provide optimizations for your favorite embedded platform
 * testing - some testing has been completed for correctness, but not all
 * expansion - adding functionality to the library
 * documentation - there are some comments within the source code, but not much
 * examples - any reasonably small examples would be appreciated
 
# Metrics #

Function accuracy, speed, and test data are gathered on each platform that has a port.  See the appropriate directory.
 
# Future #
 
I would like to see assembly-optimized code AND full accuracy and test data for each function (multiplication/division/addition) on:

 * ~~Microchip 16-bit devices (PIC24 and dsPIC33)~~ completed
 * Microchip 8-bit devices (PIC18 and PIC16)
 * TI MSP430 devices
 * STM32 Devices
 * AVR/Arduino 8-bit Devices
 
I have programmed all of these devices to some degree, but I have only written assembly on a couple of them, so some help is needed!

# Library Details #

## Defines ##

The user may customize the header to suit the application for some operations.  For instance, a look-up table is utilized for trigonometric functions.  Simply 'define' the appropriate SINE_TABLE_xBIT based on the amount of program memory that you can dedicate to the task.

## Macros ##

There are currently no macros implemented, but I suspect that a conversion from float-to-q15 will be implemented in the future.

## Type Definitions ##

There are two type definitions that the user must be aware of:

 * q15_t
 * q16angle_t

The 'q15_t' type is a 16-bit, signed number that represents decimal values ranging from -1.0 to +0.9997.  Actual values are -32768 to +32767.  The C compiler will allow the user to simply add two q15_t numbers together, but it is always recommended to use the q15_add() function to keep the number from rolling over.

The 'q16angle_t' type is a 16-bit, unsigned number that represents an angle between 0 degrees and 359.99 degrees (0 radians to 6.283 radians).  Angles can be added or subtracted at will and do not saturate.  For instance, 359 degrees + 1 result in 0 degrees and 65535 + 1 results in 0.  The rollover model is the same.

## Conversion Functions ##

 * double q15_to_dbl(q15_t num) - This function will take a q15 number and convert it to a double between -1.0 and +0.9997.  Note that some embedded target compilers implement 'double' as 'float'.
 * float q15_to_float(q15_t num) - This function will take a q15 number and convert it to a float between -1.0 and +0.9997
 * int16_t q15_to_int(q15_t num) - This function will take a q15 number and convert it to an integer between -1 and 1
 * q15_t q15_from_dbl(double num) - This function will take a double in the range of -1.0 to +0.99997 and convert it to the q15 format
 * q15_t q15_from_float(float num) - This function will take a double in the range of -1.0 to +0.99997 and convert it to the q15 format
 * q15_t q15_from_int(int num) - This function will take an integer in the range of -1 to 1 and convert it to a q15 format.  This function is included for completenes, but it is not expected that it will be utilized in most applications.  Generally, typecasts will be used to convert integers to q15 format.

## Basic Arithmetic ##

 * q15_t q15_mul(q15_t multiplicand, q15_t multiplier) - Multiplies two q15 numbers and returns the result
 * q15_t q15_div(q15_t dividend, q15_t divisor) - Divides two q15 numbers and returns the result.  Note that that the dividend MUST be smaller than the divisor or the output will saturate!
 * q15_t q15_add(q15_t addend, q15_t adder) - Adds two q15 numbers together and returns the result.  Note that if the result is greater than 32767 or less than -32768, the result will saturate!
 * q15_t q15_abs(q15_t num) - Returns the absoluate value of the given q15 number.
 * q15_t q15_sqrt(q15_t num) - Returns the square root of the given q15 number.  Due to resolution, the input 'num' should generally be larger than '1000' or the results will suffer significant skew.
 
## Trigonometry ##
 * q15_t q15_sin(q16angle_t theta) - Returns the sine of the angle in q15 format.  Note that this function uses a lookup table (see 'defines') and interpolation.
 * q15_t q15_fast_sin(q16angle_t theta) - Returns the sine of the angle in q15 format.  This function uses a lookup table only, but is faster than the standard implementation.
 * q15_t q15_cos(q16angle_t theta) - Returns the cosine of the angle in q15 format.  Note that this function uses a lookup table (see 'defines') and interpolation.
 * q15_t q15_fast_cos(q16angle_t theta) - Returns the cosine of the angle in q15 format.  This function uses a lookup table only, but is faster than the standard implementation.
 * q15_t q15_tan(q16angle_t theta) - Returns the tangent of the angle in q15 format.   Note that this function uses a lookup table (see 'defines') and interpolation.  Note also that the return type is q15_t, which will saturate at values which are less than -1.0 (-32768) or greater than 0.9997 (+32767).  If you require a higher range, then you should probably use a method that offers that range.
 * q15_t q15_fast_tan(q16angle_t theta) - Returns the cosine of the angle in q15 format.  This function uses a lookup table only, but is faster than the standard implementation.
 
Note about trigonometric functions - There is a list of undefined defines at the top of 'libmathq15.h' that determines the length of the table used for trigonometric functions.  The default is 8-bit, but the user may specify a smaller value at compile time in order to reduce memory usage.  Accuracy will suffer somewhat as well.
 
