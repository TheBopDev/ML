// 

#include <stdio.h>
#include <math.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

#include "../inc/ml.h"
//#include "../inc/algorithms.h"




///////////////////////////////////////////
/// Neuron structure
///////////////////////////////////////////
// I use a linked list format, as defined in "../inc/ml.h"


// structure to create a neuron.
// Returns a pointer to the neuron.
struct st_mln_neuron_ll *fnpst_mln_create_neuron(int i_neuron_id)
{
	// Malloc the struct.
	struct st_mln_neuron_ll *pst_mln_neuron_return = (struct st_mln_neuron_ll*)malloc(sizeof(struct st_mln_neuron_ll));
	if (pst_mln_neuron_return == NULL) return NULL; // If malloc didn't work, don't pretend it did.
	else return pst_mln_neuron_return; // Otherwise, malloc worked and we return the happy little pointer.
}



// frees a neuron from the heap (used malloc to create it)
void fnv_mln_neuron_free(void **ptr_void)
{
	// code;
}



void fnv_mln_neuron_random_init(struct st_mln_neuron_ll *pst_mln_neuron)
{
	// code;
}



double fnd_mln_neuron_calculate_output(struct st_mln_neuron_ll *pst_mln_neuron)
{
	// code;
}



///////////////////////////////////////////
/// Layer structure
///////////////////////////////////////////

void fnv_mll_link_two_neurons(struct st_mln_neuron_ll *pst_mln_first, struct st_mln_neuron_ll *pst_mln_second)
{
	// code;
}




///////////////////////////////////////////
/// Activation functions
///////////////////////////////////////////

double fnd_afn_function_single_input(int i_afn, double d_input)
{
	switch(i_afn) {
		case I_AFN_MEAN:
			printf("Error. Cannot calculate mean based off of single input. Check afn_function_single_input.\n");
			break;
		case I_AFN_SIGMOID:
			return fnd_afn_sigmoid(d_input);
			break;
		case I_AFN_IDENTITY:
			return fnd_afn_identity(d_input);
			break;
		case I_AFN_TANH:
			return fnd_afn_tanh(d_input);
			break;
		case I_AFN_RELU:
			return fnd_afn_relu(d_input);
			break;
		case I_AFN_LEAKY_RELU:
			return fnd_afn_leaky_relu(d_input);
			break;
		case I_AFN_GAUSSIAN:
			return fnd_afn_gaussian(d_input);
			break;
		case I_AFN_BINARY_STEP:
			return fnd_afn_binary_step(d_input);
			break;
		default:
			// return error.
			printf("Error. Unexpected case from afn_function_single_input function.\n");
			return -1.0;
	}
	
	return -1.0;

}

double fnd_afn_mean(double *pad_input, int i_array_length)
{
	double d_return = 0.0;
	double d_sum = 0.0;
	
	for (int i = 0; i < i_array_length; i++)
	{
		d_sum += pad_input[i];
	}
	
	d_return = d_sum / i_array_length;

	return d_return;
}



double fnd_afn_sigmoid(double d_input)
{
	// Return the result from the formula.
	return (1 / (1 + exp(-d_input)) );
}



double fnd_afn_identity(double d_input)
{
	return d_input;
}



double fnd_afn_tanh(double d_input)
{
	return tanh(d_input);
}



double fnd_afn_relu(double d_input)
{
	// Could use the tertiary operator, but for code readability,
	// just use a simple if/else.
	if (d_input >= 0) return d_input;
	else return 0;
}



double fnd_afn_leaky_relu(double d_input)
{
	// Could use the tertiary operator, but for code readability,
	// just use a simple if/else.
	if (d_input >= 0) return d_input;
	else return (0.01 * d_input);
}



double fnd_afn_gaussian(double d_input)
{
	double d_squared_input = d_input * d_input;
	double d_return = exp(-d_squared_input);

	return d_return;
}



double fnd_afn_binary_step(double d_input)
{
	// Could use the tertiary operator, but for code readability,
	// just use a simple if/else.
	if (d_input >= 0) return 1.0;
	else return 0.0;
}


/* EOF ml.c*/


