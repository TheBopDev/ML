


#include <stdio.h>
#include <math.h>
#include <stddef.h>
#include <stdint.h>

#include "../inc/ml.h"
#include "../inc/unittest.h"
//#include "../inc/algorithms.h"


int main(int argc, char **argv[])
{
	// Create the first layer.
	struct st_mln_neuron_ll st_mln_neuron_1, st_mln_neuron_2;

	int i_test_id = 1;

	struct st_mln_neuron_ll *pst_mln_neuron_ptr = fnpst_mln_create_neuron(i_test_id);










	/* Unit testing */
	double d_test_input = 0.69;
	double ad_test_array[4];
	ad_test_array[0] = 1.1;
	ad_test_array[1] = 2.0;
	ad_test_array[2] = 3.2;
	ad_test_array[3] = 4.4;
	double *pad_test_array = ad_test_array;

	uint8_t u8_test_afn_mean = fnu8_test_afn_mean(pad_test_array, 4);
	




	// Testing stuff

	double d_test_data = 0.93;
	double d_out = 0;

	printf("Test data: %f\n", d_test_data);
	for (int i = 0; i < 10; i++)
	{
		d_out = fnd_afn_function_single_input(i, d_test_data);
		printf("Output: %f\n", d_out);
	}

	
	// Exit success
	return 0;
}



