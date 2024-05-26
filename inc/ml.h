
// Boh

#ifndef ML_H
#define ML_H

#include <stddef.h>
#include <stdint.h>
#include <math.h>


// Neuron structure.
struct st_mln_neuron_ll {
	struct st_mln_neuron_ll *pst_mln_neuron_ll_next;
	struct st_mln_neuron_ll *pst_mln_neuron_ll_prev;
	int		 i_mln_activation_fn;
	int    i_mln_neuron_id;
	double d_mln_input;
	double d_mln_output;
	double d_mln_dropout;
	double *pad_mln_weights[];
};


struct st_mln_neuron_ll *fnpst_mln_create_neuron(int i_neuron_id);

void fnv_mln_neuron_free(void **ptr_void);

void fnv_mln_neuron_random_init(struct st_mln_neuron_ll *pst_mln_neuron);

double fnd_mln_neuron_calculate_output(struct st_mln_neuron_ll *pst_mln_neuron);

void fnv_mll_link_two_neurons_in_order(struct st_mln_neuron_ll *pst_mln_first, struct st_mln_neuron_ll *pst_mln_second);


// Activation function defines
#define I_AFN_MEAN			  1
#define I_AFN_SIGMOID		  2
#define I_AFN_IDENTITY	  3
#define I_AFN_TANH			  4
#define I_AFN_RELU			  5
#define I_AFN_LEAKY_RELU  6
#define I_AFN_GAUSSIAN	  7
#define I_AFN_BINARY_STEP	8


// Activation function declarations

double fnd_afn_function_single_input(int i_afn, double d_input);

double fnd_afn_mean(double *pad_input, int i_array_length);

double fnd_afn_sigmoid(double d_input);

double fnd_afn_identity(double d_input);

double fnd_afn_tanh(double d_input);

double fnd_afn_relu(double d_input);

double fnd_afn_leaky_relu(double d_input);

double fnd_afn_gaussian(double d_input);

double fnd_afn_binary_step(double d_input);


// 


#endif
/* EOF ml.h */

 
 
