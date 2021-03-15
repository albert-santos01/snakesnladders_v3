#include <stdio.h>

#include "../headers/state.h"

/**
 * TODO: Initializes the state, setting the playing board, the current position to 0 and finished flag to FALSE.
 *
 * @param state The state to be initialized.
 * @param board The playing board.
 *
 * Pre:
 * Post:
 */
void init_state(State* state, Board* board) {
}

/**
 * TODO: Sets the current position.
 *
 * @param state The state to be updated.
 * @param position The current position.
 *
 * Pre:
 * Post:
 */
void set_current_position(State* state, int position) {
}

/**
 * TODO: Retrieves the current position.
 *
 * @param state The state that stores the current position.
 * @return The current position.
 *
 * Pre:
 * Post:
 */
int get_current_position(State* state) {
    return ERROR;
}

/**
 * TODO: Sets the finished flag to finished value (TRUE or FALSE)
 *
 * @param state The state to be updated.
 * @param is_finished The value marking the game as finished or not.
 *
 * Pre:
 * Post:
 */
void set_finished(State* state, int finished) {
}

/**
 * TODO: Returns the value of is_finished flag (TRUE or FALSE), marking a game as finished.
 *
 * @param state The state to be updated.
 *
 * Pre:
 * Post:
 */
int is_finished(State* state) {
    return ERROR;
}

/**
 * TODO: Moves the player a number of steps in the board, updating the state's current position. If the player ends up in a
 * square containing a ladder or a snake updates the state's current position accordingly. Also, sets the state as
 * finished if it moves to or past the last square. Returns SNAKE_FOUND or LADDER_FOUND if found, SUCCESS otherwise.
 *
 * @param board The playing board.
 * @param state The current state.
 * @param steps The number of steps to move.
 *
 * Pre:
 * Post:
 */
int move(State* state, int dice_value) {
    return ERROR;
}

/**
 * TODO: Adds a step to the state's sequence, as the last step of it.
 *
 * Pre:
 * Post:
 */
void add_step(State* state, int dice_value) {
}


/**
 * Prints the sequence of the state.
 * @param sequence The sequence to be shown.
 *
 * Pre:
 * Post:
 */
void print_state_sequence(State* state) {
}
