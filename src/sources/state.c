#include <stdio.h>

#include "../headers/state.h"

/**
 *  Initializes the state, setting the playing board, the current position to 0 and finished flag to FALSE.
 *
 * @param state The state to be initialized.
 * @param board The playing board.
 *
 * Pre: El board deberia estar inicializado
 * Post:Dado el state copia el board dado, pone la position como 0 y el finishe como FALSE
 */
void init_state(State* state, Board* board) {
    state->board=board;
    state->position=0;
    state->finished=FALSE;
    init_sequence(&state->sequence);  //Hemos inicializado sequence
}

/**
 * Sets the current position.
 *
 * @param state The state to be updated.
 * @param position The current position.
 *
 * Pre: La position deberia ser un número entre las medidas del tablero
 * Post: Se actualiza el state con la posicion dada
 */
void set_current_position(State* state, int position) {
    state->position = position;
}

/**
 *  Retrieves the current position.
 *
 * @param state The state that stores the current position.
 * @return The current position.
 *
 * Pre: el state debe estar al menos inicializado
 * Post:Se devuelve la position que contiene el state
 */
int get_current_position(State* state) {
    return state->position;
}

/**
 * Sets the finished flag to finished value (TRUE or FALSE)
 *
 * @param state The state to be updated.
 * @param is_finished The value marking the game as finished or not.
 *
 * Pre: el state debe estar al menos inicializado y finished deberia ser o TRUE o FALSE
 * Post: el state  es actualizado con el finished dado
 */
void set_finished(State* state, int finished) {
    state->finished = finished;
}

/**
 *  Returns the value of is_finished flag (TRUE or FALSE), marking a game as finished.
 *
 * @param state The state to be updated.
 *
 * Pre: el state debe estar al menos inicializado
 * Post:Devuelve el valor del finished del state dado
 */
int is_finished(State* state) {
    return state->finished;
}

/**
 *  Moves the player a number of steps in the board, updating the state's current position. If the player ends up in a
 * square containing a ladder or a snake updates the state's current position accordingly. Also, sets the state as
 * finished if it moves to or past the last square. Returns SNAKE_FOUND or LADDER_FOUND if found, SUCCESS otherwise.
 *
 * @param board The playing board.
 * @param state The current state.
 * @param steps The number of steps to move.
 *
 * Pre: el state debe estar almenos inicializado y el dice_value se recomienda que este entre 1 y 6
 * Post: La función devuelve  LADDER_FOUND si se ha encontrado una escalera, SNAKE_FOUND si se ha encontrado una serpiente o un 20
 *      si ninguno de los dos casos. El state será actualizado con la nueva posición y si la nueva posición es más grande que el tamaño
 *      del tablero el finished pasa a ser  TRUE.
 */
int move(State* state, int dice_value) {
    int status=20;
    Board* board=state->board; // this is the address
    int board_size= get_size(board);
    int current_position= get_current_position(state);
    current_position+= dice_value;
    if (current_position<board_size){
        Square* current_square = get_square_at(board,current_position);
        if (is_ladder(current_square)==TRUE){
            status = LADDER_FOUND;
            current_position = get_target_position(current_square);
        } else if (is_snake(current_square)==TRUE){
            status = SNAKE_FOUND;
            current_position= get_target_position(current_square);
        }
    } else if(current_position>board_size-1) {//ESTO ES QUE HA GANADO SIN CONTAR EL REBOTE
        current_position = board_size - 1;
        set_finished(state, TRUE);
    }
    set_current_position(state,current_position);
    return status;
}

/**
 * Adds a step to the state's sequence, as the last step of it.
 *
 * Pre:  el state debe estar almenos inicializado y el dice_value se recomienda que este entre 1 y 6 y la sequencia debe ser una lista
 *      bien enlazada
 * Post: Crea el step dinámicamente con los datos dados y lo añade alfinal de la sequence. Si es el primer step de la sequence será el
 *       primero y el último.
 */
void add_step(State* state, int dice_value) {
    add_step_as_last(&state->sequence,state->position,dice_value); //CADA VEZ QUE AGREGAMOS UN PASO LO PONE COMO LAST
}


/**
 * Prints the sequence of the state.
 * @param sequence The sequence to be shown.
 *
 * Pre: el state debe estar almenos inicializado y la sequencia debe ser una lista
 *      bien enlazada
 * Post: imprime los movimientos  en orden que guarda la sequence
 * */
void print_state_sequence(State* state) {
   print_sequence(&state->sequence);
}
