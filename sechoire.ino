#include <Adafruit_GFX.h> //specification du materiel
#include <MCUFRIEND_kbv.h>
#include <Keypad.h> 
#include <util/atomic.h>
// *** definition des couleur
#define BLACK   0x0000
#define WHITE   0xFFFF
#define RED     0xF800
#define GREEN   0x07E0
#define BLUE    0x001F
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define GREY    0x2108

// couleur du valeur mesurer
#define RED2RED 0
#define GREEN2GREEN 1
#define BLUE2BLUE 2
#define BLUE2RED 3
#define GREEN2RED 4
#define RED2GREEN 5
MCUFRIEND_kbv tft;
uint32_t runTime = -99999;       // temps pour nouvelle mise ajour 
int reading = 0; //valeur a afficher
int d = 0; // valeur pour testet le mouvement
boolean alert = 0;
int8_t ramp = 1;
int tesmod =0;
char *msg[] = { "PORTRAIT", "LANDSCAPE", "PORTRAIT_REV", "LANDSCAPE_REV" };
uint8_t aspect;
uint16_t wid,hei;
char c;
String c1,c2;
boolean vide;
extern const uint8_t coeur[];
float h = 60.5+1;
float t =  25.5+1;
float f =  60.5+1;
int consig_temp,consig_h,somme;
// temperature en Fahrenheit 
float hif =  60.5+1;
// temperature en Celsius 
float hic =  60.5+1;
//clavier matriciel
byte BrochesLignes[4] = {22,23,24,25};
byte BrochesColonnes[4] = {26,27,28,29}; 
char touches[4][4] = {
            {'1','2','3','A'},
            {'4','5','6','B'},
            {'7','8','9','C'},
            {'*','0','#','D'}
      }; 
 char touche; 
 Keypad clavier = Keypad( makeKeymap(touches), BrochesLignes, BrochesColonnes, 4, 4 ); 
 int valeur_temperature;
 /*************************************************
 initialisation des composante
 ******************************************************/
#include <DS3231.h>
#include <Wire.h>
DS3231 clock;
RTCDateTime dt;
int jour,mois,annee,heure,minu,seco;
 //****************************************************************************************************
byte  compteur100ms = 1000;

const int NBTACHE = 2;             // Nb de tâches à réserver

volatile boolean etatTache[NBTACHE];        //Table de l'état d'activité des tâches 
volatile byte Etape [NBTACHE];              //Table de l'étape active des tâches

typedef void (*action_t)(void);   //définir un pointeur pour les tâches
int processus = 0 ;

//****************************************************************************************************
 /******** déclaration des tâches ********/

void  Tache_init();
void  Tache_T_1();
void  Tache_T_2();
/**************************************** 
     Tableau de pointeurs sur les tâches
     dans l'ordre des N° des tâches 
*****************************************/

action_t Tache[] = {
    Tache_init,  
    Tache_T_1,
    Tache_T_2,
}; 

/******** N° des tâches **************/
const unsigned int _init = 0;
//****************************************************************************************************
    

