void setup() 
{
  pinMode(8,INPUT_PULLUP);
  pinMode(13,OUTPUT);

  TIMSK1 = (1<<ICIE1);
  TCCR1B = (1<<ICNC1) | (1<<CS11);  //  Noise Canceler,1/8 Prescaler 
  TCCR1B &=~ (1<<ICES1);            // Falling edge select
  
  sei();
}

void loop()
{
  

}
ISR(TIMER1_CAPT_vect)
{      
    PORTB ^= 1<<PB5;  
}
