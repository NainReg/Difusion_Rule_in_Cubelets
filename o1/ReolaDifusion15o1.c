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
    uint8_t aux1 = get_block_value(820396);//
    uint8_t aux2 = get_block_value(1460283);//
    uint8_t aux3 = get_block_value(1410314);//
    uint8_t aux4 = get_block_value(923624);//
    uint8_t aux5 = get_block_value(1376424);//
    uint8_t aux6 = get_block_value(1407280);//
    uint8_t aux7 = get_block_value(1458486);//
    uint8_t aux8 = get_block_value(1460379);//
    
    uint8_t sum = aux1 + aux2 + aux3 + aux4 + aux5 + aux6 + aux7 + aux8;
    //Condicional en B2/S7 para:
    //flashlight cambiando prendido y apagado
    //rotate cambiando direccion
    //rotate cambiando gira no  gira
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
