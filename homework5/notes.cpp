//interrupt vector
TIMER0_COMPA //timer/counter0 compare match

ISR (TIMER0_COMPA);


TCCR0A = 0;
TCCR0A |= (1<<WGM01);// CTC mode
OCR0A = 0xff;
