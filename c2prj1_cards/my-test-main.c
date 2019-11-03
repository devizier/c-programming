#include <stdio.h>
#include "cards.h"

int main(void) {
    card_t card = {2, 0};
    print_card(card);
    printf("\n");

    card = (card_t) {10, 2};
    print_card(card);
    printf("\n");

    card = (card_t) {12, 3};
    print_card(card);
    printf("\n");

    card = (card_t) {14, 3};
    print_card(card);
    printf("\n");


    card = card_from_num(0);
    print_card(card);
    printf("\n");

    card = card_from_num(1);
    print_card(card);
    printf("\n");

    card = card_from_num(51);
    print_card(card);
    printf("\n");

    card = card_from_letters('Q', 'c');
    print_card(card);
    printf("\n");
}
