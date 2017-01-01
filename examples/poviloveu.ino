// Japanino POV by Musashinodenpa

#define LEDPIN 7     // �ɤΥԥ󤫤�LED��Ĥʤ���
#define SWPIN 6      // �����å���Ĥʤ��ԥ�

// �ӥåȥޥå�(����)�����
byte bitmap[] = {
0b00000000,
0b01000001,
0b01111111,
0b01000001,
0b00000000,
0b00000000,
0b00001110,
0b00011111,
0b00111111,
0b01111110,
0b00111111,
0b00011111,
0b00001110,
0b00000000,
0b00000000,
0b00111111,
0b01000000,
0b01000000,
0b00111111,
0b10000000   // �Ǹ�ιԤ�0b10000000(�Ĥޤ��ܰ�)
};


unsigned char pos = 0;  // ���ߤΥӥåȥޥå���ΰ���
unsigned char i = 0;


void setup() {
// LED����³���줿�ԥ����Ϥ����ꤷ�ޤ�
for(char pin = LEDPIN; pin < LEDPIN + 7; pin++) {
  pinMode(pin, OUTPUT);
}
pinMode(SWPIN, INPUT);      // �����å��Υԥ�����Ϥ�
digitalWrite(SWPIN, HIGH);  // ��¢�ץ륢�å�ͭ��
}

void loop() {

if(digitalRead(SWPIN) == LOW) {  // �����å�������ʤ��1������

  delay(6);  // �����Ϥ��ȵͤޤäƸ�����ΤǤ���ä��Ԥ�
  pos = 0;

  while(bitmap[++pos] != 0b10000000) {  // �ӥåȥޥåפ�ü�ޤǷ����֤�
    for(i = 0; i < 7; i++) {  // �ӥåȥޥåפι⤵��ʬ���������֤�
      // �ӥåȥޥåץǡ�������1�ӥåȤ���Ф��ƥԥ�ξ��֤�ȿ��
      digitalWrite(LEDPIN + 6 - i, (bitmap[pos] >> i) & 0b00000001);
    }
    delay(1);  // LED�����äƤ������
  }

  for(i = LEDPIN; i < LEDPIN + 7; i++) {  // ���ɥåȡ�����
    digitalWrite(i, LOW);
  }
 }
}

