/* Unit testing file */

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#include "../inc/unittest.h"
#include "../inc/ml.h"

/* Testing activation functions */


static const uint8_t scu8_test_success = 0;
static const uint8_t scu8_test_fail_params = 1;
static const uint8_t scu8_test_fail_value = 2;


static const double scd_test_input_val = 0.69;


uint8_t fnu8_test_afn_mean(double *pad_input, int i_array_length)
{
	double d_temp = 0.0;

	d_temp = fnd_afn_mean(pad_input, i_array_length);
	
	if (d_temp == scd_test_input_val)
	{
		return scu8_test_success;
	} 
	else
	{
		printf("Test: Activation function mean failed");
		return scu8_test_fail_value;
	}
}
