#include <stdlib.h>
#include <stdio.h>

#include "../headers/sequence.h"

/**
 * TODO: Initializes a sequence, setting the initial values of the structure according to the implementation.
 *
 * Pre:
 * Post:
 */
void init_sequence(Sequence* sequence) {
}

/**
 * TODO: Adds a step, creating it if needed, as the first step of the sequence.
 *
 * Pre:
 * Post:
 */
void add_step_as_first(Sequence* sequence, int position, int dice_value) {
}

/**
 * TODO: Adds a step, creating it if needed, as the last step of the sequence.
 *
 * Pre:
 * Post:
 */
void add_step_as_last(Sequence* sequence, int position, int dice_value) {
}

/**
 * TODO: Returns the number of steps stored in the sequence.
 *
 * Pre:
 * Post:
 */
int get_sequence_size(Sequence* sequence) {
    return 0;
}

/**
 * Deletes (freeing if needed) all the steps stored in the sequence.
 * @param sequence The sequence to be cleared.
 *
 * Pre:
 * Post:
 */
 void clear_sequence(Sequence* sequence) {
}

/**
 * Prints the sequence of moves leading to the state.
 * @param sequence The sequence to be shown.
 *
 * Pre:
 * Post:
 */
void print_sequence(Sequence* sequence) {
}
