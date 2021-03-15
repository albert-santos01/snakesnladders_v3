#ifndef STATE_H
#define STATE_H

#include "board.h"
#include "sequence.h"
#include "common.h"

#define SNAKE_FOUND 2
#define LADDER_FOUND 3

// TODO: Add a sequence to the state, to store the historic of steps.
typedef struct {
} State;

void init_state(State* state, Board* board);

int get_current_position(State* state);
void set_current_position(State* state, int position);

int is_finished(State* state);
void set_finished(State* state, int finished);

void reset(State* state);

int move(State* state, int dice_value);

void add_step(State* state, int dice_value);
void print_state_sequence(State* state);

#endif //DUNGEON_STATE_H
