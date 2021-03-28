#include <stdlib.h>
#include <stdio.h>

#include "../headers/sequence.h"

/**
 * Initializes a sequence, setting the initial values of the structure according to the implementation.
 *
 * Pre:La struct de sequence debería tener los siguientes atributos para rellenar: first, last y size; los dos primeros como steps y el size como un int
 * Post:sequence se inicializa con first y last como NULL y size con 0
 */
void init_sequence(Sequence* sequence) {
    sequence->first = NULL;
    sequence->last = NULL;
    sequence->size = 0;
}

/**
 * Adds a step, creating it if needed, as the first step of the sequence.
 *
 * Pre: sequence debe estar incializada correctamente  y debe estar bien enlazada
 * Post: Crea el step dinámicamente con los datos dados y lo añade al principio de la sequence. Si es el primer step de la sequence será el primero y el último.
 */
void add_step_as_first(Sequence* sequence, int position, int dice_value) {
    Step* step = (Step*) malloc(sizeof(Step));

    step->position = position;
    step->value = dice_value;
    step->next  = NULL;
    if(sequence->last == NULL){
        sequence->last= step;

    }else {
        step->next = sequence->first;
    }
    sequence->first = step;
    sequence->size++;

}

/**
 *  Adds a step, creating it if needed, as the last step of the sequence.
 *
 * Pre: sequence debe estar incializada correctamente  y debe estar bien enlazada
 * Post: Crea el step dinámicamente con los datos dados y lo añade alfinal de la sequence. Si es el primer step de la sequence será el primero y el último.
 */
void add_step_as_last(Sequence* sequence, int position, int dice_value) {
    Step* step = (Step*) malloc(sizeof(Step));
    step->position = position;
    step->value = dice_value;
    step->next  = NULL;
    if(sequence->first == NULL){
        sequence->first = step;
    }else {
        sequence->last->next = step;

    }
    sequence->last = step;
    sequence->size++;
}

/**
 *  Returns the number of steps stored in the sequence.
 *
 * Pre: sequence debe estar incializada correctamente
 * Post: Devuelve  el número de steps que hay dentro de la sequence
 */
int get_sequence_size(Sequence* sequence) {
    return sequence->size;
}

/**
 * Deletes (freeing if needed) all the steps stored in the sequence.
 * @param sequence The sequence to be cleared.
 *
 * Pre: sequence debe estar incializada correctamente  y debe estar bien enlazada
 * Post: Libera todas las steps enlazadas una a una pero no libera la sequence dada
 */
 void clear_sequence(Sequence* sequence) {
     Step * step=sequence->first;
    while (sequence->last!=NULL){
        if(step!=NULL){
            sequence->first=step->next;
            sequence->size--;
            if (sequence->last==step){
                sequence->last=NULL;
            }
            free(step);
            step=sequence->first;
        }
    }
}

/**
 * Prints the sequence of moves leading to the state.
 * @param sequence The sequence to be shown.
 *
 * Pre: sequence debe estar incializada correctamente  y debe estar bien enlazada
 * Post: imprime los movimientos  en orden que guarda la sequence
 */
void print_sequence(Sequence* sequence) {
    Step* step= sequence->first;
    while (step!=NULL){
        printf("With a %d, move to square %d\n",step->value,step->position);
        step=step->next;
    }
}
