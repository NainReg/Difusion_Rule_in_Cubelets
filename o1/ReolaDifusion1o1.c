#include "cubelet.h"
#include <stdint.h>
#include "routing_table.h"

void setup() {
    set_flashlight(0);
    //set_drive_direction(BACKWARD);
    //set_drive(0);
    block_value = 0;
    wait(1000);
}

void loop() {
    uint8_t aux1 = get_block_value(935673);
    uint8_t aux2 = get_block_value(820396);
    uint8_t aux3 = get_block_value(1408211);//
    uint8_t aux4 = get_block_value(1365046);
    uint8_t aux5 = get_block_value(1457307);
    uint8_t aux6 = get_block_value(1376339);
    uint8_t aux7 = get_block_value(1460358);
    uint8_t aux8 = get_block_value(935512);
    
    uint8_t sum = aux1 + aux2 + aux3 + aux4 + aux5 + aux6 + aux7 + aux8;
    //Condicional en B2/S7 para rotate
    if(sum == 2 && block_value == 0){
        set_flashlight(100);
        //set_drive_direction(FORWARD);
        //set_drive(100);
        block_value = 1;
    } else if(sum != 2 && block_value == 0){
        set_flashlight(0);
        //set_drive_direction(BACKWARD);
        //set_drive(0);
        block_value = 0;
    } else if(sum != 7 && block_value == 1){
        set_flashlight(0);
        //set_drive_direction(BACKWARD);
        //set_drive(0);
        block_value = 0;
    } else if(sum == 7 && block_value == 1){
        set_flashlight(100);
        //set_drive_direction(FORWARD);
        //set_drive(100);
        block_value = 1;
    }

    wait(1000);
}
