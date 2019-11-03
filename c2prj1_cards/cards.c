#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cards.h"

void assert_card_valid(card_t c) {
    assert(c.value >= 2 && c.value <= VALUE_ACE);
    assert(c.suit >= SPADES && c.suit <= CLUBS);
}

const char *ranking_to_string(hand_ranking_t r) {
    switch (r) {
        case STRAIGHT_FLUSH:
            return "STRAIGHT_FLUSH";
        case FOUR_OF_A_KIND:
            return "FOUR_OF_A_KIND";
        case FULL_HOUSE:
            return "FULL_HOUSE";
        case FLUSH:
            return "FLUSH";
        case STRAIGHT:
            return "STRAIGHT";
        case THREE_OF_A_KIND:
            return "THREE_OF_A_KIND";
        case TWO_PAIR:
            return "TWO_PAIR";
        case PAIR:
            return "PAIR";
        case NOTHING:
            return "NOTHING";
        default:
            printf("there is no such hand ranking");
            exit(EXIT_FAILURE);
    }
}

char value_letter(card_t c) {
    assert_card_valid(c);
    unsigned value = c.value;
    if (value >= 2 && value <= 9) {
        return '0' + value;
    } else {
        switch (value) {
            case 10:
                return '0';
            case VALUE_JACK:
                return 'J';
            case VALUE_QUEEN:
                return 'Q';
            case VALUE_KING:
                return 'K';
            case VALUE_ACE:
                return 'A';
            default:
                printf("Card is not valid");
                exit(EXIT_FAILURE);
        }
    }
}

char suit_letter(card_t c) {
    assert_card_valid(c);
    switch (c.suit) {
        case SPADES:
            return 's';
        case HEARTS:
            return 'h';
        case DIAMONDS:
            return 'd';
        case CLUBS:
            return 'c';
        default:
            printf("card is not valid");
            exit(EXIT_FAILURE);
    }
}

void print_card(card_t c) {
    printf("%c%c", value_letter(c), suit_letter(c));
}

card_t card_from_letters(char value_let, char suit_let) {
    int value_val;
    if (value_let >= '2' && value_let <= '9') {
        value_val = atoi(&value_let);
    } else {
        switch (value_let) {
            case '0':
                value_val = 10;
                break;
            case 'J':
                value_val = VALUE_JACK;
                break;
            case 'Q':
                value_val = VALUE_QUEEN;
                break;
            case 'K':
                value_val = VALUE_KING;
                break;
            case 'A':
                value_val = VALUE_ACE;
                break;
            default:
                printf("there is no such value: %c", value_let);
                exit(EXIT_FAILURE);
        }
    }
    int suit_val;
    switch (suit_let) {
        case 's':
            suit_val = SPADES;
            break;
        case 'h':
            suit_val = HEARTS;
            break;
        case 'd':
            suit_val = DIAMONDS;
            break;
        case 'c':
            suit_val = CLUBS;
            break;
        default:
            printf("there is no such suit: %c", suit_let);
            exit(EXIT_FAILURE);
    }
    card_t card = {value_val, suit_val};
    return card;
}

card_t card_from_num(unsigned c) {
    assert(c >= 0 && c < 52);
    unsigned value_val = c / 4 % 13;
    unsigned suit_value = c % 4;
    card_t card = { value_val + 2, suit_value};
    return card;
}
