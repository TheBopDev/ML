


#ifndef UNITTEST_H
#define UNITTEST_H



// Test all activation functions.
uint16_t fnu16_test_afn_all(void);

uint8_t fnu8_test_afn_mean(double *pad_input, int i_array_length);
uint8_t fnu8_test_afn_sigmoid(double d_input);
uint8_t fnu8_test_afn_identity(double d_input);



#endif
/* EOF unittest.h */



