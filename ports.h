enum P {  //select the wanted port
    port_A =0,
    port_B,
    port_C,
    port_D,
    port_E,
    port_F
};
enum operation { //the operation I want
    Direction=0,
    digital,

};
enum Dir{ //Direction of the port
    input=0,
    output
};
enum Status{ //status of the either High or LOW
    LOW=0,
    HIGH
};
enum Digital_enable{
  disable=0,
  enable
};
enum pin_portF{
  switch_0=0,
  R_led,
  B_led,
  G_Led,
  switch_4
};