#ifndef ARQUIVO_H
#define ARQUIVO_H

#include <stdbool.h>
#include <stdio.h>

typedef struct {
    int *elementos;
    int tamanho;
    int capacidade;
} Set;

void add(Set *set , int elem);
bool isEmpty(Set *set);
int len(Set *set);
bool isIn(Set *set,int elem);
bool isNotIn(Set *set,int elem);
bool isDisjoint(Set *set1, Set *set2);
void remove_elem(Set *set, int elem);
int pop(Set *set);
void clear(Set *set);
Set union_sets(Set *set1, Set *set2);
Set intersection(Set *set1, Set *set2);
Set difference(Set *set1, Set *set2);
Set symmetric_difference(Set *set1, Set *set2);
bool isSubSet(Set *set1, Set *set2);
bool isSuperSet(Set *set1, Set *set2);
void copy(Set *set1, Set *set2);
void print(Set *set);

#endif