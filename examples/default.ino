/*
*
* �o�׎��X�P�b�`
*
*/

// �ݒ�
int duration = 20;  // LED��_�����鎞�ԁi�~���b�j
int inputPin = 6;  // �X�C�b�`���̓s���i�I����LOW�j
int ledMin = 7;   // LED�s���͈͂̍ŏ�
int ledMax = 13;  // LED�s���͈͂̍ő�
int buzzPin = 14;  // �u�U�[�s���iA0��D14�Ƃ��ăA�N�Z�X�j
int buzzTone = 4000;  // �u�U�[�̉���
int buzzTime = 10;  // �u�U�[��炷���ԁi�~���b�j

// �O���[�o���ϐ�
unsigned long lastOn = 0; // �u�U�[�炵�n�ߎ����i0�Ȃ���Ă��Ȃ��j

void setup() {
 pinMode(inputPin, INPUT); // �X�C�b�`�͓���
 digitalWrite(inputPin, HIGH); // �����v���A�b�v�L��
 for (int i = ledMin; i <= ledMax; i++) {
   pinMode(i, OUTPUT);  // LED�ւ̐ڑ��͏o��
 }
 pinMode(buzzPin, OUTPUT); // �u�U�[�͏o��
}

// LED�_�����ɂ��ׂ�����
void pause() {
 unsigned long started = millis();

 for (;;) {
   unsigned long now = millis();

   // LED�_�����Ԃ��o�߂�����A
   if (now - started > duration) {
     // ���̊֐����I���B
     return;
   }

   // �X�C�b�`���I���ɂȂ��Ă�����A
   if (digitalRead(inputPin) == LOW) {
     tone(buzzPin, buzzTone); // �u�U�[��炷�B
     lastOn = now;  // �炵�n�߂��������o���Ă����B
   }

   // �u�U�[�����Ă��āA����莞�Ԍo�߂��Ă�����A
   if (lastOn != 0 && now - lastOn > buzzTime) {
     noTone(buzzPin);  // �u�U�[���~�߂�B
     lastOn = 0;  // �~�߂����Ƃ��o���Ă����B
   }
 }
}

void loop() {
 // �����
 for (int i = ledMin; i <= ledMax; i++) {
   digitalWrite(i, HIGH); // �_������
   pause();
   digitalWrite(i, LOW); // ��������
 }

 // ������
 for (int i = ledMax; i >= ledMin; i--) {
   digitalWrite(i, HIGH); // �_������
   pause();
   digitalWrite(i, LOW); // ��������
 }
}
