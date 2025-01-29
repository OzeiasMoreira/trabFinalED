#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "arquivo.h"

int main() {
    Set set1 = {malloc(10 * sizeof(int)), 0, 10};
    Set set2 = {malloc(10 * sizeof(int)), 0, 10};

    add(&set1, 1);
    add(&set1, 2);
    add(&set2, 2);
    add(&set2, 3);

    printf("Conjunto 1: ");
    print(&set1);
    printf("Conjunto 2: ");
    print(&set2);

    printf("Os conjuntos 1 e 2 são disjuntos? %s\n", isDisjoint(&set1, &set2) ? "Sim" : "Não");

    Set union_result = union_sets(&set1, &set2);
    printf("União dos conjuntos: ");
    print(&union_result);

    printf("O número 2 está no Conjunto 1? %s\n", isIn(&set1, 2) ? "Sim" : "Não");
    printf("O número 5 está no Conjunto 2? %s\n", isIn(&set2, 5) ? "Sim" : "Não");

    printf("O número 5 não está no Conjunto 1? %s\n", isNotIn(&set1, 5) ? "Sim" : "Não");

    Set difference_result = difference(&set1, &set2);
    printf("Diferença entre Conjunto 1 e Conjunto 2: ");
    print(&difference_result);

    Set intersection_result = intersection(&set1, &set2);
    printf("Interseção entre Conjunto 1 e Conjunto 2: ");
    print(&intersection_result);

    free(set1.elementos);
    free(set2.elementos);
    free(union_result.elementos);
    free(difference_result.elementos);
    free(intersection_result.elementos);

    return 0;
}
