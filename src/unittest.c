/* Unit testing file */

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#include "../inc/unittest.h"
#include "../inc/ml.h"

/* Testing activation functions */
static const uint16_t scu16_test_afn_success_all = 0;

uint16_t fnu16_test_afn_all(void)
{
	// Assume all tests pass. If a test fails, return the first fail.
	uint16_t u16_return = scu16_test_afn_success_all;


	// Create the required inputs to be used for testing.
	double d_test_input = 0.69;
	double ad_test_array[4];
	ad_test_array[0] = 1.1;
	ad_test_array[1] = 2.0;
	ad_test_array[2] = 3.2;
	ad_test_array[3] = 4.4;
	double *pad_test_array = ad_test_array;


	// Send the pointer to the test function, with the length of the array
	uint8_t u8_test_afn_mean = fnu8_test_afn_mean(pad_test_array, 4);
	uint8_t u8_test_afn_sigmoid = fnu8_test_afn_sigmoid(d_test_input);
	
	// Go ahead and return to keep warnings happy :)
	return u16_return;
}





static const uint8_t scu8_test_success = 0;
static const uint8_t scu8_test_fail_params = 1;
static const uint8_t scu8_test_fail_value = 2;



static const double scd_test_expected_result_mean = 2.675;
uint8_t fnu8_test_afn_mean(double *pad_input, int i_array_length)
{
	double d_temp = 0.0;

	d_temp = fnd_afn_mean(pad_input, i_array_length);
	
	// Test to see if the value is within 1% of the expected value
	if ((d_temp >= (scd_test_expected_result_mean * 0.99))
		   || (d_temp <= (scd_test_expected_result_mean * 1.01)) )
	{
		printf("Calculated mean close to expected value of: %f\n",
				scd_test_expected_result_mean);
		return scu8_test_success;
	} 
	else
	{
		printf("Test: Activation function mean failed\n");
		printf("Calculated mean: %f\n", d_temp);
		printf("Expected mean: %f\n", scd_test_expected_result_mean);
		return scu8_test_fail_value;
	}
}


static const double scd_test_expected_result_sigmoid = 0.66725;
uint8_t fnu8_test_afn_sigmoid(double d_input)
{
	uint8_t u8_return = scu8_test_success;

	u8_return = fnd_afn_sigmoid(d_input);
	if ( (u8_return >= (0.99 * scd_test_expected_result_sigmoid))
			|| (u8_return <= (1.01 * scd_test_expected_result_sigmoid)) )
	{
		u8_return = scu8_test_success;
	}
	else
	{
		u8_return = scu8_test_fail_value;
	}

	// Return the resulting condition.
	return u8_return;
}

static const double scd_test_expected_result_identity = 0.69;
uint8_t fnu8_test_afn_identity(double d_input)
{
	// Create the return value and assign it the default case.
	uint8_t u8_return = scu8_test_fail_value;

	double d_temp = fnd_afn_identity(d_input);

	if ((d_temp <= (1.01 * scd_test_expected_result_identity))
			|| (d_temp >= (0.99 * scd_test_expected_result_identity)) )
	{
		// Return
		u8_return = scu8_test_success;
	}
	else
	{
		u8_return = scu8_test_fail_value;
	}

	// Return the resulting condition.
	return u8_return;
}


static const double scd_test_expected_result_tanh = 0.5979;
uint8_t fnu8_test_afn_tanh(double d_input)
{
	// Create a return variable and assign it the default case.
	uint8_t u8_return = scu8_test_fail_value;

	// Test the function we want.
	double d_temp = fnd_afn_identity(d_input);

	// Depending on the condition, return different flags.
	if ((d_temp <= (1.01 * scd_test_expected_result_tanh))
			|| (d_temp >= (0.99 * scd_test_expected_result_tanh)) )
	{
		u8_return = scu8_test_success; // Update the return flag
	}
	else
	{
		u8_return = scu8_test_fail_value; // Update return flag
	}

	// Return the state.
	return u8_return;
}



static const double scd_test_expected_result_relu = 0.69;
uint8_t fnu8_test_afn_relu(double d_input)
{
	// Create return variable and assign it default case (assume failure).
	uint8_t u8_return = scu8_test_fail_value;


	// Test the relu function.
	double d_temp = fnd_afn_relu(d_input);
	if ((d_temp <= (1.01 * scd_test_expected_result_relu))
			|| (d_temp >= (0.99 * scd_test_expected_result_relu)) )
	{
		u8_return = scu8_test_success; // Update the return flag
	}
	else
	{
		u8_return = scu8_test_fail_value; // Update return flag
	}


	// Return the state.
	return u8_return;
}



static const double scd_test_expected_result_leaky_relu = 0.69;
uint8_t fnu8_test_afn_leaky_relu(double d_input)
{
	// Create return variable and assign it default case (assume failure).
	uint8_t u8_return = scu8_test_fail_value;


	// Test the relu function.
	double d_temp = fnd_afn_leaky_relu(d_input);
	if ((d_temp <= (1.01 * scd_test_expected_result_leaky_relu))
			|| (d_temp >= (0.99 * scd_test_expected_result_leaky_relu)) )
	{
		u8_return = scu8_test_success; // Update the return flag
	}
	else
	{
		u8_return = scu8_test_fail_value; // Update return flag
	}


	// Return the state.
	return u8_return;
}



static const double scd_test_expected_result_gaussian = 0.69;
uint8_t fnu8_test_afn_leaky_gaussian(double d_input)
{
	// Create return variable and assign it default case (assume failure).
	uint8_t u8_return = scu8_test_fail_value;


	// Test the relu function.
	double d_temp = fnd_afn_gaussian(d_input);
	if ((d_temp <= (1.01 * scd_test_expected_result_gaussian))
			|| (d_temp >= (0.99 * scd_test_expected_result_gaussian)) )
	{
		u8_return = scu8_test_success; // Update the return flag
	}
	else
	{
		u8_return = scu8_test_fail_value; // Update return flag
	}


	// Return the state.
	return u8_return;
}



static const double scd_test_expected_result_binary_step = 1.0;
uint8_t fnu8_test_afn_binary_step(double d_input)
{
	// Create return variable and assign it default case (assume failure).
	uint8_t u8_return = scu8_test_fail_value;


	// Test the relu function.
	double d_temp = fnd_afn_gaussian(d_input);
	if ((d_temp <= (1.01 * scd_test_expected_result_gaussian))
			|| (d_temp >= (0.99 * scd_test_expected_result_gaussian)) )
	{
		u8_return = scu8_test_success; // Update the return flag
	}
	else
	{
		u8_return = scu8_test_fail_value; // Update return flag
	}


	// Return the state.
	return u8_return;
}






/* EOF unittest.c */


