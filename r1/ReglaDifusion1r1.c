#include "cubelet.h"
#include <stdint.h>
#include "routing_table.h"

void setup() {
    set_flashlight(100);
    block_value = 1;
    wait(1000);
}

void loop() {
    uint8_t aux1 = get_block_value(2318759);
    uint8_t aux2 = get_block_value(2365157);
    uint8_t aux3 = get_block_value(2318556);
//    uint8_t aux4 = get_block_value(1457307);
//    uint8_t aux5 = get_block_value(1458561);
//    uint8_t aux6 = get_block_value(1458297);
//    uint8_t aux7 = get_block_value(1408211);
//    uint8_t aux8 = get_block_value(1458486);
    
    uint8_t sum = aux1 + aux2 + aux3;// + aux4 + aux5 + aux6 + aux7 + aux8;

    if(sum == 2 && block_value == 0){
        set_flashlight(100);
        block_value = 1;
    } else if(sum != 2 && block_value == 0){
        set_flashlight(0);
        block_value = 0;
    } else if(sum != 7 && block_value == 1){
        set_flashlight(0);
        block_value = 0;
    } else if(sum == 7 && block_value == 1){
        set_flashlight(100);
        block_value = 1;
    }

    wait(1000);
}
