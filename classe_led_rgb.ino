#define ledR 2
#define ledG 3
#define ledB 4
#define botao 7

class Btn {
public:
  int btnClicado, btnLiberado, pino;

  Btn(int p) {
    pino = p;
    clear();
  }

  bool press() {
    if (digitalRead(pino) == 1) {
      btnClicado = 1;
      btnLiberado = 0;
    } else {
      btnLiberado = 1;
    }

    if (btnClicado == 1 and btnLiberado == 1) {
      clear();
      return true;
    } else {
      return false;
    }
  }

private:
  void clear() {
    btnClicado = btnLiberado = 0;
  }
};

class Cor {
public:
  int pinR, pinG, pinB, ciclo, maximo;

  Cor(int pr, int pg, int pb)
    : pinR(pr), pinG(pg), pinB(pb) {
    ciclo = 0;
    maximo = 3;
  }

  trocaLed() {
    if (ciclo == 0) {
      corLed(1, 0, 0);
    } else if (ciclo == 1) {
      corLed(0, 1, 0);
    } else {
      corLed(0, 0, 1);
    }
    verificaCiclo();
  }

private:
  void corLed(int r, int g, int b) {
    digitalWrite(pinR, r);
    digitalWrite(pinG, g);
    digitalWrite(pinB, b);
  }

  void clear() {
    ciclo = 0;
  }

  void incrementa() {
    ciclo++;
  }

  void verificaCiclo() {
    incrementa();
    if (ciclo > maximo - 1) {
      clear();
    }
  }
};


Btn bot1(botao);
Cor cor1(ledR, ledG, ledB);

void setup() {
  pinMode(ledR, OUTPUT);
  pinMode(ledG, OUTPUT);
  pinMode(ledB, OUTPUT);
  pinMode(botao, INPUT);
}

void loop() {
  if (bot1.press()) {
    cor1.trocaLed();
  }
}
