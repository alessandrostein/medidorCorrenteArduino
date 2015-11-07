#include <EmonLib.h>

EnergyMonitor emon1;                   // Create an instance
 
// Tensao da rede eletrica
double rede = 220.0;
double potenciaW;
double custoEnergia;
double hora = 1;
double reaisKwh = 0.444360;
double custoTotal = 0;
double totalHoras = 0;
 
// Pino do sensor SCT
int pino_sct = 1;
 
void setup() 
{
  Serial.begin(9600);   
  // Pino, calibracao - Cur Const= Ratio/BurdenR. 1800/62 = 29. 
  emon1.current(pino_sct, 29);
} 
  
void loop() 
{ 
  // Calcula a corrente  
  double Irms = emon1.calcIrms(1480);
  
  Serial.print("Potencia: ");
  Serial.print(Irms); // Irms
  Serial.print("W");
  
  totalHoras = totalHoras + 1;  
  Serial.print(" Horas utilizadas: ");
  Serial.print(totalHoras);

  potenciaW = Irms*rede;
  custoEnergia = ((potenciaW * hora) / 1000) *  reaisKwh;
  custoTotal = custoTotal + custoEnergia;  
  Serial.print(" Custo por hora: ");
  Serial.print("R$: ");
  Serial.print(custoEnergia);
  Serial.print(" Custo total: ");
  Serial.print("R$: ");
  Serial.println(custoTotal);
  
  delay(1000);
}
