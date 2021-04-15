typedef struct bt_node {
    char value ;
    struct bt_node * left ;
    struct bt_node * right ;
} bt_node ;

/* Reconstruieste un arbore binar pornind de la doua parcurgeri:
    - in_order - parcurgea in_ordine a arborelui (left - root - right)
    - pre_order - parcurgerea in pre-ordine a arborelui (root-left-right)
    - in_start - indexul de inceput pentru arborele curent (in sirul in_order)
    - in_end - indexul de final pentru arborele curent (in sirul in_order)
    - pre_idx - indexul corespunzator radacinii arborelui curent (in sirul pre_order)
    (4 puncte)
*/
bt_node *build_tree(char *in_order, char *pre_order, int in_start, int in_end, int *pre_idx);

/* Parcurge si printeaza un arbore binar in pre-ordine (root-left-right) */
void print_pre_order(bt_node *node);

