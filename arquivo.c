#include "arquivo.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


void add(Set *set, int elem) {
    if (!isIn(set, elem)) {
        if (set->tamanho == set->capacidade) {
            set->capacidade *= 2;
            set->elementos = realloc(set->elementos, set->capacidade * sizeof(int));
        }
        set->elementos[set->tamanho++] = elem;
    }
}

bool isEmpty(Set *set) {
    return set->tamanho == 0;
}

int len(Set *set) {
    return set->tamanho;
}

bool isIn(Set *set, int elem) {
    for (int i = 0; i < set->tamanho; i++) {
        if (set->elementos[i] == elem) {
            return true;
        }
    }
    return false;
}

bool isNotIn(Set *set, int elem) {
    return !isIn(set, elem);
}

bool isDisjoint(Set *set1, Set *set2) {
    for (int i = 0; i < set1->tamanho; i++) {
        if (isIn(set2, set1->elementos[i])) {
            return false;
        }
    }
    return true;
}

void remove_elem(Set *set, int elem) {
    for (int i = 0; i < set->tamanho; i++) {
        if (set->elementos[i] == elem) {
            for (int j = i; j < set->tamanho - 1; j++) {
                set->elementos[j] = set->elementos[j + 1];
            }
            set->tamanho--;
            break;
        }
    }
}

int pop(Set *set) {
    if (isEmpty(set)) return -1;
    int elem = set->elementos[0];
    remove_elem(set, elem);
    return elem;
}

void clear(Set *set) {
    set->tamanho = 0;
}

Set union_sets(Set *set1, Set *set2) {
    Set result;
    result.elementos = malloc((set1->tamanho + set2->tamanho) * sizeof(int));
    result.tamanho = 0;
    result.capacidade = set1->tamanho + set2->tamanho;

    for (int i = 0; i < set1->tamanho; i++) {
        add(&result, set1->elementos[i]);
    }
    for (int i = 0; i < set2->tamanho; i++) {
        add(&result, set2->elementos[i]);
    }
    return result;
}

Set intersection(Set *set1, Set *set2) {
    Set result;
    result.elementos = malloc((set1->tamanho < set2->tamanho ? set1->tamanho : set2->tamanho) * sizeof(int));
    result.tamanho = 0;
    result.capacidade = set1->tamanho < set2->tamanho ? set1->tamanho : set2->tamanho;

    for (int i = 0; i < set1->tamanho; i++) {
        if (isIn(set2, set1->elementos[i])) {
            add(&result, set1->elementos[i]);
        }
    }
    return result;
}

Set difference(Set *set1, Set *set2) {
    Set result;
    result.elementos = malloc(set1->tamanho * sizeof(int));
    result.tamanho = 0;
    result.capacidade = set1->tamanho;

    for (int i = 0; i < set1->tamanho; i++) {
        if (!isIn(set2, set1->elementos[i])) {
            add(&result, set1->elementos[i]);
        }
    }
    return result;
}

Set symmetric_difference(Set *set1, Set *set2) {
    Set result;
    result.elementos = malloc((set1->tamanho + set2->tamanho) * sizeof(int));
    result.tamanho = 0;
    result.capacidade = set1->tamanho + set2->tamanho;

    for (int i = 0; i < set1->tamanho; i++) {
        if (!isIn(set2, set1->elementos[i])) {
            add(&result, set1->elementos[i]);
        }
    }
    for (int i = 0; i < set2->tamanho; i++) {
        if (!isIn(set1, set2->elementos[i])) {
            add(&result, set2->elementos[i]);
        }
    }
    return result;
}

bool isSubSet(Set *set1, Set *set2) {
    for (int i = 0; i < set1->tamanho; i++) {
        if (!isIn(set2, set1->elementos[i])) {
            return false;
        }
    }
    return true;
}

bool isSuperSet(Set *set1, Set *set2) {
    return isSubSet(set2, set1);
}

void copy(Set *set1, Set *set2) {
    set2->elementos = realloc(set2->elementos, set1->tamanho * sizeof(int));
    set2->tamanho = set1->tamanho;
    set2->capacidade = set1->tamanho;
    for (int i = 0; i < set1->tamanho; i++) {
        set2->elementos[i] = set1->elementos[i];
    }
}

void print(Set *set) {
    printf("{ ");
    for (int i = 0; i < set->tamanho; i++) {
        printf("%d ", set->elementos[i]);
    }
    printf("}\n");
}
