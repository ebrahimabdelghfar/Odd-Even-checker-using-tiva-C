#include "types.h"
#include "DIO.h"
#include "ports.h"
#include "tm4c123gh6pm.h"
#include "stdlib.h"
uint32 x[]={5,3,8,4,8,94,2,8,4,2};
int main()
{
  DIO_init_clk(port_F);
  GPIO_PORTF_LOCK_R|=0x4C4F434B;
  GPIO_PORTF_CR_R|=0x10;
  DIO_Direction_PORT(port_F,B_led,output);
  DIO_Direction_PORT(port_F,R_led,output);
  DIO_Direction_PORT(port_F,G_Led,output);
  DIO_Direction_PORT(port_F,switch_4,input);
  DIO_DEN_PORT(port_F,B_led,enable);
  DIO_DEN_PORT(port_F,R_led,enable);
  DIO_DEN_PORT(port_F,G_Led,enable);
  DIO_PullUP_pin(port_F,switch_4);
  DIO_DEN_PORT(port_F,switch_4,enable);
  while(1){
    uint32 current =x[rand()%10];
    if(DIO_read_pin(port_F,switch_4)==0&&current%2==0){
      for(int i=0;i<34800;i++){
      DIO_Write_pin(port_F,B_led,HIGH);
      DIO_clear_pin(port_F,R_led);
      }
    }
    else if (DIO_read_pin(port_F,switch_4)==0&&current%2!=0){
      for(int i=0;i<34800;i++){
      DIO_Write_pin(port_F,R_led,HIGH);
      DIO_clear_pin(port_F,B_led);
      }
    }
    else{
      DIO_clear_pin(port_F,B_led);
      DIO_clear_pin(port_F,R_led);
    }
}
}