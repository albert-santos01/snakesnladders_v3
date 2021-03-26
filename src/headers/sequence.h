#ifndef SEQUENCE_H
#define SEQUENCE_H

// TODO: Define the attributes of a step having the dice value and the resulting position. Also, it may store the next Step.
typedef struct _step {
    int position;   //user position
    int value; //dice value
    struct _step* next;
} Step;

// TODO: Define the attributes of a sequence, being a implementation of a dynamic array or linked list of Steps.
typedef struct {
    Step* first;
    Step* last;       //LINKED LIST
    int size;   //Tamaño de esta secuencia (lista)
} Sequence;

void init_sequence(Sequence* sequence);
void add_step_as_first(Sequence* sequence, int position, int dice_value); //CADA VEZ QUE LANZAMOS UN DADO DEBEMOS LLAMARLA
void add_step_as_last(Sequence* sequence, int position, int dice_value);
int get_sequence_size(Sequence* sequence);
void clear_sequence(Sequence* sequence);
void print_sequence(Sequence* sequence);

#endif //SEQUENCE_H
