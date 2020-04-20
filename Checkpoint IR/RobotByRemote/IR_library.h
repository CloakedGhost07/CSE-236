#define REMOTE_UP 0x20df02fd
#define REMOTE_DOWN 0x20df827d
#define REMOTE_LEFT 0x20dfe01f
#define REMOTE_RIGHT 0x20df609f
#define REMOTE_OK 0x20df22dd
#define REMOTE_NUM1 0x20df8877
#define REMOTE_NUM2 0x20df48b7
#define REMOTE_NUM3 0x20dfc837
#define REMOTE_CH_UP 0x20df00ff
#define REMOTE_CH_DOWN 0x20df807f

#define IR_DECODER_PIN (PIND & (1<<PIND4))
#define IR_PIN (PIND4)
#define SAMPLE_SIZE    34
#define   TRUE        1
#define   FALSE       0



void printRemoteButton(uint32_t val);
void decodeRemote(uint32_t val);
void setupIR();
void handleIRinput();
