#include "tm4c123gh6pm.h"
#include "types.h"
#include "bitwise_operation.h"
void DIO_init_clk(uint8 Port) {
    SYSCTL_RCGCGPIO_R |= selected_port(Port, 1);
    while (SYSCTL_PRGPIO_R & selected_port(Port, 1)==0) {};
}
void DIO_Direction_PORT(uint8 Port,uint8 pin,uint8 Direction){ //do you want direction
    switch (Port) {
        case 0://port A
            GPIO_PORTA_DIR_R |= set_selected_pin(pin,Direction);
            break;
        case 1://port B
            GPIO_PORTB_DIR_R |= set_selected_pin(pin,Direction);
            break;
        case 2://port C
            GPIO_PORTC_DIR_R |= set_selected_pin(pin,Direction);
            break;
        case 3://port D
            GPIO_PORTD_DIR_R |= set_selected_pin(pin,Direction);
            break;
        case 4://port E
            GPIO_PORTE_DIR_R |= set_selected_pin(pin,Direction);
            break;
        case 5://port F
            GPIO_PORTF_DIR_R |= set_selected_pin(pin,Direction);
            break;
    }
}
void DIO_DEN_PORT(uint8 Port,uint8 pin,uint8 DEN) { //do you want DEN
    switch (Port) {
        case 0://port A
            GPIO_PORTA_DEN_R |= set_selected_pin(pin, DEN);
            break;
        case 1://port B
            GPIO_PORTB_DEN_R |= set_selected_pin(pin, DEN);
            break;
        case 2://port C
            GPIO_PORTC_DEN_R |= set_selected_pin(pin, DEN);
            break;
        case 3://port D
            GPIO_PORTD_DEN_R |= set_selected_pin(pin, DEN);
            break;
        case 4://port E
            GPIO_PORTE_DEN_R |= set_selected_pin(pin, DEN);
            break;
        case 5://port F
            GPIO_PORTF_DEN_R |= set_selected_pin(pin, DEN);
            break;
     }
}
    void DIO_Write_pin(uint8 Port,uint8 pin,uint8 Status){ //write pin with status HIGH =1 or LOW=0
        switch (Port) {
            case 0://port A
                GPIO_PORTA_DATA_R |= set_selected_pin(pin,Status);
                break;
            case 1://port B
                GPIO_PORTB_DATA_R |= set_selected_pin(pin,Status);
                break;
            case 2://port C
                GPIO_PORTC_DATA_R |= set_selected_pin(pin,Status);
                break;
            case 3://port D
                GPIO_PORTD_DATA_R |= set_selected_pin(pin,Status);
                break;
            case 4://port E
                GPIO_PORTE_DATA_R |= set_selected_pin(pin,Status);
                break;
            case 5://port F
                GPIO_PORTF_DATA_R |= set_selected_pin(pin,Status);
                break;
                   }
}

void DIO_PullUP_pin(uint8 port,uint8 location_button){
    switch (port) {
        case 0://port A
             GPIO_PORTA_PUR_R |= set_selected_pin(location_button,1);
            break;
        case 1://port B
             GPIO_PORTB_PUR_R |= set_selected_pin(location_button,1);
            break;
        case 2://port C
             GPIO_PORTC_PUR_R |= set_selected_pin(location_button,1);
            break;
        case 3://port D
             GPIO_PORTD_PUR_R |= set_selected_pin(location_button,1);
            break;
        case 4://port E
             GPIO_PORTE_PUR_R |= set_selected_pin(location_button,1);
            break;
        case 5://port F
             GPIO_PORTF_PUR_R |= set_selected_pin(location_button,1);
            break;
    }
}
uint8 DIO_read_pin(uint8 port,uint8 location_button){
    switch (port) {
        case 0://port A
            return GPIO_PORTA_DATA_R & status_pin(location_button,1);
            break;
        case 1://port B
            return GPIO_PORTB_DATA_R & status_pin(location_button,1);
            break;
        case 2://port C
            return GPIO_PORTC_DATA_R & status_pin(location_button,1);
            break;
        case 3://port D
            return GPIO_PORTD_DATA_R & status_pin(location_button,1);
            break;
        case 4://port E
            return GPIO_PORTE_DATA_R & status_pin(location_button,1);
            break;
        case 5://port F
            return GPIO_PORTF_DATA_R &status_pin(location_button,1);
            break;
    }
}
void DIO_clear_pin(uint8 port,uint8 pin){
    switch (port) {
        case 0://port A
            GPIO_PORTA_DATA_R &= clear_pin(pin,1);
            break;
        case 1://port B
             GPIO_PORTB_DATA_R &= clear_pin(pin,1);
            break;
        case 2://port C
            GPIO_PORTC_DATA_R &= clear_pin(pin,1);
            break;
        case 3://port D
            GPIO_PORTD_DATA_R &= clear_pin(pin,1);
            break;
        case 4://port E
            GPIO_PORTE_DATA_R &= clear_pin(pin,1);
            break;
        case 5://port F
            GPIO_PORTF_DATA_R &= clear_pin(pin,1);
            break;
    }
}