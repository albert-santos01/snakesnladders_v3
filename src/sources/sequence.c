#include <stdlib.h>
#include <stdio.h>

#include "../headers/sequence.h"

/**
 * TODO: Initializes a sequence, setting the initial values of the structure according to the implementation.
 *
 * Pre:
 * Post:
 */
void init_sequence(Sequence* sequence) {  //Se genera cuando
    sequence->first = NULL;
    sequence->last = NULL;
    sequence->size = 0;
}

/**
 * TODO: Adds a step, creating it if needed, as the first step of the sequence.
 *
 * Pre:
 * Post:
 */
void add_step_as_first(Sequence* sequence, int position, int dice_value) { //GENERA SPACE EN LA MEMORIA (MALLOC)
    // TODO buscar donde se implementa
    Step* step = (Step*) malloc(sizeof(Step));  //mirar en struct step  GENERAR MEMORIA TIPO STEP
    step->position = position;
    step->value = dice_value;
    step->next  = NULL;  //NO HAY NADA EN EL SIGUIENTE
    if(sequence->last == NULL){
        sequence->last= step;
         //step = es la memoria que acabamos de crear (contiene el position y dice_value
    }else {
        step->next = sequence->first; //es el primero, el que recien entró ---lo determina la de abajo
    }
    sequence->first = step;
    sequence->size++; //Va incrementando el tamaño
    //FIRST == NULL <---> LAST == STEP

}

/**
 * TODO: Adds a step, creating it if needed, as the last step of the sequence.
 *
 * Pre:
 * Post:
 */
void add_step_as_last(Sequence* sequence, int position, int dice_value) { //GENERA SPACE EN LA MEMORIA (MALLOC)
    Step* step = (Step*) malloc(sizeof(Step));  //mirar en struct step  GENERAR MEMORIA TIPO STEP
    step->position = position;
    step->value = dice_value;
    step->next  = NULL;  //NO HAY NADA EN EL SIGUIENTE
    if(sequence->first == NULL){
        sequence->first = step; //step = es la memoria que acabamos de crear (contiene el position y dice_value
    }else {
        sequence->last->next = step; //es el primero, el que recien entró ---lo determina la de abajo
        //el siguiente ultimo va a ser un step (lo de arriba)
    }
    sequence->last = step;
    sequence->size++; //Va incrementando el tamaño
    //FIRST == NULL <---> LAST == STEP
    //NEXT ES NULL PK NO HAY NADA
    //FIRST == NULL <---> LAST == STEP
    //ES EL SIGUIENTE CASO CUMPLIENDO QUE SE HAGA EL ADDSTEPASFIRST
}

/**
 * TODO: Returns the number of steps stored in the sequence.
 *
 * Pre:
 * Post:
 */
int get_sequence_size(Sequence* sequence) {
    return sequence->size;
}

/**
 * Deletes (freeing if needed) all the steps stored in the sequence.
 * @param sequence The sequence to be cleared.
 *
 * Pre:
 * Post: Libera todas las steps enlazadas una a una pero NO LIBERA LA SEQUENCE!!!
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
 * Pre:
 * Post:
 */
void print_sequence(Sequence* sequence) {
    Step* step= sequence->first;
    while (step!=NULL){
        printf("With a %d, move to square %d\n",step->value,step->position);
        step=step->next;
    }
}
