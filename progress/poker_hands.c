
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <inttypes.h>


#define POKER_HAND_FILE         "../res/poker.txt"
#define FILE_LENGTH             1000
#define LINE_LENGTH             32

struct _poker_hand {
        char n_pairs;
        char n_of_kind;
        char same_suit;
        char royal;
        char high_card;
        char pad[3];
};

typedef struct _poker_hand Hand;

int main(int argc, char** argv);
char** read_poker_file(const char* file);



int main(int argc, char** argv)
{
        (void) argc;
        (void) argv;

        int32_t player_1 = 0;

        char** hands = read_poker_file(POKER_HAND_FILE);

        for(int32_t round = 0; i < FILE_LENGTH; round++){
                char* hand = hands[round];

                player_1 = wins_hand(hand);

                free(hand);
        }

        free(hands);

        printf("%"PRId32"\n", player



}


char** read_poker_file(const char* file);
{
        FILE* poker_file = fopen(file, "r");

        char** lines = calloc(FILE_LENGTH + 1, sizeof(char*));

        for(int32_t i = 0; i < FILE_LENGTH; i++){

                /* Yes, I know sizeof(char) is per definition 1.
                 * Fucking sue me */
                char* line = calloc(LINE_LENGTH, sizeof(char));
                line = fgets(line, LINE_LENGTH, poker_file);

                if(line){
                        lines[i] = line;

                } else break;

        }

        fclose(poker_file);

        return lines;

}


int32_t wins_hand(char* hand)
{

        char* player = hand;
        char* opposition = hand + 15;

        Hand p1 = process_hand(player);
        Hand p2 = process_hand(opposition);

        int32_t wins_hand = compare_hands(p1, p2);

        free(p1);
        free(p2);

        return wins_hand;


}

struct _poker_hand* process_hand(char* str)
{

        Hand hand = calloc(1, sizeof(struct _poker_hand*));

        int32_t card_n = 1;
        for(int32_t i = 0; card_n <= 5; i++){



        }



}


