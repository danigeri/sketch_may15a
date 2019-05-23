#define FIRST_STAGE  4
#define SECOND_STAGE  2
#define THIRD_STAGE  4
#define FAST  250
#define SLOW  500

#define NUM_OF_LEDS 3

int led_0 = 13;
int led_1 = 12;
int led_2 = 11;
int led_3 = 10;
int led_4 = 9;
int led_5 = 8;
int state = 0;
int main_cnt = 0;
int btn_state = 1;
int start_button = 2;
int stop_button = 3;

int btn_array_1[ NUM_OF_LEDS ] = { led_0 , led_2, led_4 };
int btn_array_2[ NUM_OF_LEDS ] = { led_1 , led_3, led_5 };

void check_btn();
void handle_main_cnt( int cnt , int next_state );
void state_func( int t );
void turn_on_off_led( int* button_array , int size_of_array , int port_state );



// the setup routine runs once when you press reset:
void setup() {
  // initialize the digital pin as an output.
  pinMode(led_0, OUTPUT);
  pinMode(led_1, OUTPUT);
  pinMode(led_2, OUTPUT);
  pinMode(led_3, OUTPUT);
  pinMode(led_4, OUTPUT);
  pinMode(led_5, OUTPUT);
  
  //Init buttons
  pinMode(start_button, INPUT);
  pinMode(stop_button, INPUT);
  
}

// the loop routine runs over and over again forever:
void loop() {
   handle_led_states();  
}


void handle_led_states()
{

  switch( state )
  {
    case 0:
      state_func( FAST );
      handle_main_cnt( FIRST_STAGE , 1 );        
      break;
      
    case 1: 
      state_func( SLOW );
      handle_main_cnt( SECOND_STAGE , 2 );
      break;
      
    case 2:
      state_func( FAST ); 
      handle_main_cnt( THIRD_STAGE , 0 );
      break;
      
    default:
      break;
  } 
  
}

void check_btn()
{
  //Handle buttons:
  if( digitalRead(start_button) && !digitalRead(stop_button) )
  {
    btn_state = 1;
  }
  else if( !digitalRead(start_button) && digitalRead(stop_button) )
  {
    btn_state = 0;
  }
  else
  {
    //Do nothing ...  
  }
}

void handle_main_cnt( int cnt , int next_state )
{
 if( cnt == main_cnt )
 {
   main_cnt = 0;
   state = next_state; 
 }
 else
 {
   main_cnt++;
 }
}


void state_func( int t )
{
 
  check_btn();
  if( btn_state )
  {
    turn_on_off_led( btn_array_1 , NUM_OF_LEDS , HIGH);
    turn_on_off_led( btn_array_2 , NUM_OF_LEDS , LOW);    
    delay( t );
  }  

  check_btn();
  if( btn_state )
  {  
    turn_on_off_led( btn_array_1 , NUM_OF_LEDS , LOW);
    turn_on_off_led( btn_array_2 , NUM_OF_LEDS , HIGH);
    delay( t );
  }
}

void turn_on_off_led( int* button_array , int size_of_array , int port_state )
{
  int inner_cnt = 0;
  
  while( inner_cnt < size_of_array )
  {
    digitalWrite( button_array[ inner_cnt ],  port_state );
    inner_cnt++;
  }
}

