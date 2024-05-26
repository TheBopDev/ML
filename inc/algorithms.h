


#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <stdint.h>
#include <stddef.h>


// Neuron activation functions
#define MLN_AFN_RELU 0
#define MLN_AFN_LINEAR 1
#define MLN_AFN_TANH 2
#define MLN_AFN_MAX 3
#define MLN_AFN_SIGMOID 4
#define MLN_AFN_BINARY_STEP 5
#define MLN_AFN_LEAKY_RELU 6

// Create the struct
struct st_mln_neuron_ll {
	struct st_mln_neuron_ll *pst_mln_neuron_ll_next;
	struct st_mln_neuron_ll *pst_mln_neuron_ll_prev;
	double d_mln_input;
	double d_mln_output;
	double d_mln_dropout;
	int    i_mln_neuron_id;
	int    i_mln_activation_fn;
	double *pad_mln_weights[]; 
};


struct st_mln_neuron_ll *fnpst_mln_create_neuron(int i_neuron_id);

void fnv_mln_neuron_free(void **ptr_void);

void fnv_mln_neuron_random_init(struct st_mln_neuron_ll *pst_mln_neuron);

double fnd_mln_neuron_calculate_output(struct st_mln_neuron_ll *pst_mln_neuron);

void fnv_mll_link_two_neurons_in_order(struct st_mln_neuron_ll *pst_mln_first, struct st_mln_neuron_ll *pst_mln_second);


// Calculates the mean of an array of doubles.
// Input is a pointer to an array of doubles and the length of that array.
// Returns a double equal to the mean.
double fnd_afn_mean(double *pad_input, int i_n);


// Calculate the sigmoid of an input value.
// Returns a single double value, equal to the sigmoid of d_input.
double fnd_afn_sigmoid(double d_input);


#endif
/* EOF algorithms.h */

