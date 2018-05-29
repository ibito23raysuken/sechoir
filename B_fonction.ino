//fonction de debut 
void bonjour(){
   int cpt=0;
   while(cpt!=3){
    tft.setCursor (200,120);
    tft.setTextSize (2);
    tft.setTextColor (WHITE,BLACK);
    tft.print ("bonjour.  "); 
    delay(500);
    tft.setCursor (200,120);
    tft.setTextSize (2);
    tft.setTextColor (WHITE,BLACK);
    tft.print ("bonjour.. "); 
    delay(500);
    tft.setCursor (200,120);
    tft.setTextSize (2);
    tft.setTextColor (WHITE,BLACK);
    tft.print ("bonjour..."); 
    cpt++;
   }
}
void Initialisation_RTC(){
 // données pour mettre à l'heure l'horloge
 /*
  DS3231_init(DS3231_INTCN);
  t.hour=12; //definir heure
  t.min=43; //definir min
  t.sec=40; //definir seconde
  t.mday=6; //definr jour
  t.mon=4;//definir mois
  t.year=2018;//definir annee
  DS3231_set(t); //entree les configuration
  */
    // Initialize DS3231
  Serial.println("Initialize DS3231");;
  clock.begin();

  // Set sketch compiling time
  clock.setDateTime(__DATE__, __TIME__);
}
void initialisation_temperature(){
 tft.setCursor (54,48);
 tft.setTextSize (2);
 tft.setTextColor (WHITE,BLACK);
 tft.print("veuillez entrer une valeur"); 
 tft.setCursor (100,70);
 tft.print("pour la temperature"); 
 rectangle(40,36,340,60,4,BLUE);
 rectangle(60,142,300,50,4,BLUE);
 lecture_clavier();
 consig_temp=somme;
  
}
void initialisation_heure(){
 tft.setCursor (54,48);
 tft.setTextSize (2);
 tft.setTextColor (WHITE,BLACK);
 tft.print("veuillez entrer une valeur"); 
 tft.setCursor (100,70);
 tft.print("   pour l'heure      "); 
 refresh();
 rectangle(40,36,340,60,4,BLUE);
 rectangle(60,142,300,50,4,BLUE);
 lecture_clavier();
 consig_h=somme;
  
}
void initialisation_interface(){
  rectangle(10,10,190,180,4,BLUE);
  rectangle(210,10,190,95,4,BLUE);
  rectangle(210,110,190,80,4,BLUE);
  rectangle(10,200,390,40,4,BLUE);
  tft.setCursor (220,20);
  tft.setTextSize (1);
  tft.setTextColor (WHITE,BLACK);
  tft.print ("consigne:");
  tft.setCursor (220,35);
  tft.setTextSize (2);
  tft.print ("Heure:");
  tft.print (consig_h);
  tft.setCursor (220,55);
  tft.setTextSize (2);
  tft.print ("temperature:");
  tft.print (consig_temp);
  tft.setCursor (220,75);
  tft.setTextSize (2);
  tft.print ("humiditer:");
  tft.print ("32%");
}
//lecture temperature
void lecture_clavier(){
  tft.setCursor (65,150);
  tft.setTextSize (2);
  tft.setTextColor (WHITE,BLACK);
  int i=0,pos=65, k;
  char k2 ,k3 ,key[4];
  boolean sortie=true;
  key[0] = NO_KEY ;
  key[1] = NO_KEY ;
  key[2] = NO_KEY ;
  key[3] = NO_KEY ;
  somme=0;
  key[i] = clavier.getKey();
  do{
     key[i] = clavier.getKey();
      switch(key[i]) {
           case (NO_KEY) :
              //Serial.println("no key"); 
           break;
           case ('*') :
              Serial.println("valider");
              sortie=false;
           break;
           case ('#') :
           if(i!=0){
              Serial.print("effacer");
              i--;
              refresh();
              pos=pos-15;
              somme = somme/10 ;
           }
           break;  
           case ('A') :
              
           break;     
           default : 
            if(i<3){
              Serial.println(key[i]);
              k= key[i] - '0' ;
              somme= somme *10+k;    
              Serial.println(somme);                 
              i++;
              pos=pos+15;
            }
           break;
      }
  affichage(somme,65);      
 }while(sortie);
 Serial.print("sortie");
}
void lecture_clavier_date(){
  tft.setCursor (65,150);
  tft.setTextSize (2);
  tft.setTextColor (WHITE,BLACK);
  int i=0,pos=65, k;
  char k2 ,k3 ,key[9];
  boolean sortie=true;
  for (int i=0; i <= 9; i++){
    key[i] = NO_KEY ;
  }
  somme=0;
  key[i] = clavier.getKey();
  do{
     key[i] = clavier.getKey();
      switch(key[i]) {
           case (NO_KEY) :
              //Serial.println("no key"); 
           break;
           case ('*') :
              Serial.println("valider");
              sortie=false;
           break;
           case ('#') :
           if(i!=0){
              Serial.print("effacer");
              i--;
              refresh();
              pos=pos-15;
              somme = somme/10 ;
           }
           break;  
           case ('A') :
              
           break;     
           default : 
            if(i<6){
              Serial.println(key[i]);
              k= key[i] - '0' ;
              somme= somme *10+k;    
              Serial.println(somme);                 
              i++;
              pos=pos+15;
            }
           break;
      }
  affichage(somme,65);      
 }while(sortie);
 Serial.print("sortie");
}
void affichage(int chiffre,int pos){
  tft.setCursor (pos,150);
  tft.setTextSize (2);
  tft.setTextColor (WHITE,BLACK);
  tft.print (chiffre);
   
}
void change_temperature(){
  //Serial.println("clavier"); 
  int i=0,pos=65, k;
  char k2 ,k3 ,key[4];
  boolean sortie=true;
  key[0] = NO_KEY ;
  somme=0;
  key[i] = clavier.getKey();
switch(key[i]) {
           case (NO_KEY) :
              //Serial.println("no key"); 
           break;
           case ('A') :
              Serial.println("changer temperature");
              
           break;
           case ('B') :
              Serial.print("changer heur d'arret");
           break;  
           case ('C') :
              Serial.print("changer heur ");
           break;     
           default : 
           break;
      }
 //Serial.print("sortie");
}
void change_h(){
  //Serial.println("clavier"); 
  int i=0,pos=65;
  char k;
  boolean sortie=true;
  k = NO_KEY ;
  somme=0;
  k = clavier.getKey();
  if(k=='B'){
    tft.fillScreen(BLACK);
    initialisation_heure();
    tft.fillScreen(BLACK);  
    initialisation_interface();   
 }
 //Serial.print("sortie");
}
void change_date(){
  //Serial.println("clavier"); 
  int i=0,pos=65;
  char k;
  boolean sortie=true;
  k= NO_KEY ;
  somme=0;
  k= clavier.getKey();
  if(k=='C'){
    tft.fillScreen(BLACK);
 lecture_clavier_date();
}
}
int lire4chiffresMDP(){
    tft.setCursor (200,120);
    tft.setTextSize (2);
    tft.setTextColor (WHITE,BLACK);
char k1 ,k2 ,k3 ,k4 ;
char key1 = NO_KEY ;
char key2 = NO_KEY ;
char key3 = NO_KEY ;
char key4 = NO_KEY ;
key1 = clavier.getKey();
  while(key1 == NO_KEY ) {
     key1 = clavier.getKey();
     if(key1 != NO_KEY ) tft.print (key1); 
           k1 = key1 - '0' ;
            while(key2 == NO_KEY ){
                    key2 = clavier.getKey();
                    if(key2 != NO_KEY ) tft.print (key2);
                    k2 = key2 - '0' ;
                      
                 while(key3 == NO_KEY){
                       key3 = clavier.getKey() ;
                       if(key3 != NO_KEY ) tft.print (key3); 
                       k3 = key3 - '0' ;
                 }
            }
        }
    return (k3 * 100 + k2 * 10 + k1 ) ;
}
void refresh(){
 tft.fillRect(68,148,200,40,BLACK);
 rectangle(60,142,300,50,4,BLUE);
}
void _Affichagelcd(){
   dt = clock.getDateTime();
 // jour,mois,annee,heure,minu,seco
 jour=dt.day;
 mois=dt.month;
 annee=dt.year;
 heure=dt.hour;
 minu=dt.minute;
 seco=dt.second;
  /**affichage de date**/
  //tft.print(tempo.date, DEC);
 // tft.print(tempo.mon, DEC);
  //tft.print(tempo.year, DEC);
}
/*###########################################################################
#############################################################################*/
void initialisation_tache(){
     initTimer2();   // initialise TIMER2 comme Base de Temps 

   /*------------- initialise les tâches et les étapes initiales -----------------*/
  
  for (int i =0;i<NBTACHE;i++) {      
    etatTache[i]=false;
  }
  etatTache[_init] = true;   // active la tâche maître     
}

void initialisation_tft(){
    tft.reset();
    uint16_t identifier = tft.readID();
    Serial.print("ID = 0x");
    Serial.println(identifier, HEX);
    if (identifier == 0xEFEF) identifier = 0x9486;
    tft.begin(identifier);
    aspect=3;   
    tft.setRotation(aspect); 
    vide=true;
    wid = tft.width();
    hei=tft.height();
}

/********************************************************************** 
*         initialiser le timer2 en mode CTC avec interruption
**********************************************************************/

void initTimer2() 
{
  noInterrupts(); // désactiver toutes les interruptions
  TCCR2A = 0;
  TCCR2B = 0;
  TCNT2 = 0;

  TCCR2A |= (1 << WGM21);   // CTC mode
  TCCR2B |= (1 << CS22);  // 64 prescaler
  //TCCR2B |= (1 << CS21);    // 8 prescaler

  OCR2A = 250; // 16MHz/64/1000Hz => Base de Temps = 1 ms
  //OCR2A = 25; // 16MHz/64/10000Hz => Base de Temps = 100 µs

  TIMSK2 |= (1 << OCIE2A); // Activer l'IT du mode comparaison
  interrupts(); // valiser les interruptions
}

ISR(TIMER2_COMPA_vect){     
 
  if(compteur100ms == 0 ){
    //Serial.print(processus) ;
      compteur100ms = 1000 ;
      processus++ ;
      if(processus > NBTACHE ) processus = 0  ;
    
  }else {
    compteur100ms-- ;   
  }   
}

/*###########################################################################
#############################################################################*/
// #########################################################################
//  Draw the meter on the screen, returns x coord of righthand side
// #########################################################################
int ringMeter(int value, int vmin, int vmax, int x, int y, int r, char *units, byte scheme)
{
  // Minimum value of r is about 52 before value text intrudes on ring
  // drawing the text first is an option
  
  x += r; y += r;   // Calculate coords of centre of ring
  int w = r / 3;    // Width of outer ring is 1/4 of radius 
  int angle = 150;  // Half the sweep angle of meter (300 degrees)
  int v = map(value, vmin, vmax, -angle, angle); // Map the value to an angle v
  byte seg = 3; // Segments are 3 degrees wide = 100 segments for 300 degrees
  byte inc = 6; // Draw segments every 3 degrees, increase to 6 for segmented ring
  // Variable to save "value" text colour from scheme and set default
  int colour = BLUE;
 
  // Draw colour blocks every inc degrees
  for (int i = -angle+inc/2; i < angle-inc/2; i += inc) {
    // Calculate pair of coordinates for segment start
    float sx = cos((i - 90) * 0.0174532925);
    float sy = sin((i - 90) * 0.0174532925);
    uint16_t x0 = sx * (r - w) + x;
    uint16_t y0 = sy * (r - w) + y;
    uint16_t x1 = sx * r + x;
    uint16_t y1 = sy * r + y;

    // Calculate pair of coordinates for segment end
    float sx2 = cos((i + seg - 90) * 0.0174532925);
    float sy2 = sin((i + seg - 90) * 0.0174532925);
    int x2 = sx2 * (r - w) + x;
    int y2 = sy2 * (r - w) + y;
    int x3 = sx2 * r + x;
    int y3 = sy2 * r + y;

    if (i < v) { // Fill in coloured segments with 2 triangles
      switch (scheme) {
        case 0: colour = RED; break; // Fixed colour
        case 1: colour = GREEN; break; // Fixed colour
        case 2: colour = BLUE; break; // Fixed colour
        case 3: colour = rainbow(map(i, -angle, angle, 0, 127)); break; // Full spectrum blue to red
        case 4: colour = rainbow(map(i, -angle, angle, 70, 127)); break; // Green to red (high temperature etc)
        case 5: colour = rainbow(map(i, -angle, angle, 127, 63)); break; // Red to green (low battery etc)
        default: colour = BLUE; break; // Fixed colour
      }
      tft.fillTriangle(x0, y0, x1, y1, x2, y2, colour);
      tft.fillTriangle(x1, y1, x2, y2, x3, y3, colour);
      //text_colour = colour; // Save the last colour drawn
    }
    else // Fill in blank segments
    {
      tft.fillTriangle(x0, y0, x1, y1, x2, y2, GREY);
      tft.fillTriangle(x1, y1, x2, y2, x3, y3, GREY);
    }
  }
  // Convert value to a string
  char buf[10];
  byte len = 2; if (value > 999) len = 4;
  dtostrf(value, len, 0, buf);
  buf[len] = ' '; buf[len] = 0; // Add blanking space and terminator, helps to centre text too!
  // Set the text colour to default
  tft.setTextSize(1);

  if(value>9){
  tft.setTextColor(colour,BLACK);
  tft.setCursor(x-25,y-10);tft.setTextSize(3);
  tft.print(buf);}
  if(value<10){
  tft.setTextColor(colour,BLACK);
  tft.setCursor(x-25,y-10);tft.setTextSize(3);
  tft.print(buf);}

  tft.setTextColor(WHITE,BLACK);
  
  tft.setCursor(x-20,y+55);tft.setTextSize(1);
  tft.print(units); // Units display
  
  // Calculate and return right hand side x coordinate
  return x + r;
}

// #########################################################################
// Return a 16 bit rainbow colour
// #########################################################################
unsigned int rainbow(byte value)
{
  // Value is expected to be in range 0-127
  // The value is converted to a spectrum colour from 0 = blue through to 127 = red

  byte red = 0; // Red is the top 5 bits of a 16 bit colour value
  byte green = 0;// Green is the middle 6 bits
  byte blue = 0; // Blue is the bottom 5 bits
  byte quadrant = value / 32;

  if (quadrant == 0) {
    blue = 31;
    green = 2 * (value % 32);
    red = 0;
  }
  if (quadrant == 1) {
    blue = 31 - (value % 32);
    green = 63;
    red = 0;
  }
  if (quadrant == 2) {
    blue = 0;
    green = 63;
    red = value % 32;
  }
  if (quadrant == 3) {
    blue = 0;
    green = 63 - 2 * (value % 32);
    red = 31;
  }
  return (red << 11) + (green << 5) + blue;
}

// #########################################################################
// Return a value in range -1 to +1 for a given phase angle in degrees
// #########################################################################
float sineWave(int phase) {
  return sin(phase * 0.0174532925);
}
void rectangle(int x,int y,int longueur,int largeur,int epaisseur,int couleur){
      for (int i = 0; i < epaisseur; i++)
            tft.drawRect(x + i, y + i, longueur - 2 * i, largeur - 2 * i,couleur);
}
void principale_action(){
tft.setCursor (220,120);
tft.setTextSize (2);
tft.setTextColor (WHITE,BLACK);
// jour,mois,annee,heure,minu,seco
tft.print (jour); 
tft.print("-");
tft.print(mois);
tft.print("-");
tft.print(annee);
tft.setCursor (220,140);
tft.setTextSize (2);
tft.setTextColor (WHITE,BLACK);
tft.print (heure); 
tft.print(":");
tft.print(minu);
tft.print(":");
tft.print(seco);
tft.print("  ");
h++;
t++;
f++;
hic++;
hic++;

    if(h>100 || t>105|| f>455 || hif>445 ||hic>445){
    h=0;
    t=h;
    f=t;
    hic=f;
    hif=hic;
  }
if (millis() - runTime >= 500) { // Execute every 500ms
    runTime = millis();
    if(tesmod==0){reading=99; }
    if(tesmod==1){reading = t;}  
    
    int xpos = 25, ypos = 30, gap = 100, radius = 80;
    ringMeter(reading,0,100, xpos,ypos,radius,"Celsius",GREEN2RED); // Draw analogue meter
  if(h>0){  //Humidity %
    tft.setCursor (220,160);
    tft.setTextSize (3);
    tft.setTextColor (BLUE,BLACK);
    tft.print (h,0); 
    tft.print ('%');
    tesmod=1;
  }
  
  }
}

