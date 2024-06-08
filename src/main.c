


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
	// Test all activation functions.
	uint16_t u16_test_afn_all = fnu16_test_afn_all();
	




	// Exit success
	return 0;
}



