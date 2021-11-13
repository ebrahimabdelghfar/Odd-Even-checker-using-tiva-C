#define selected_port(register,bit) bit<<register
#define set_selected_pin(register,bit) bit<<register
#define clear_pin(register,bit)  ~(bit<<register)
#define toggle_pin(register,bit) bit<<register
#define status_pin(register,bit) bit<<register
