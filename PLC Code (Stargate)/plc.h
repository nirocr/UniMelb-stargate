/* plc.h */


typedef struct {
   unsigned char Fail;
   unsigned char Trip1;
   unsigned char Trip;
   unsigned char C24VDC;
   unsigned char AzBrake;
   unsigned char ElBrake;
   unsigned char AzFinalCW;

   unsigned char AzFinalCCW;
   unsigned char ElFinalUp;
   unsigned char ElFinalDwn;
   unsigned char EmergStop;
   unsigned char SmokeDetect;
   unsigned char Door1;
   unsigned char Door2;
   unsigned char CB5_6;

   unsigned char CB4;
   unsigned char CB3;
   unsigned char RUN1;
   unsigned char RUN2;
   unsigned char C1;
   unsigned char C2;
} PLC_struct;


int ReadPLC (char a, char b, char c, PLC_struct *PLC);
