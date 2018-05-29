void setup() {
    // put your setup code here, to run once:
    Serial.begin(9600);
    Initialisation_RTC();
    initialisation_tache();
    initialisation_tft();
    tft.fillScreen(BLACK); //background
    //bonjour();
    tft.fillScreen(BLACK);
    delay(10); // pause rapide pour laisser temps initialisation
    Serial.println("init OK") ; // affiche la chaîne texte - message de test
    initialisation_temperature();
    initialisation_heure();
    tft.fillScreen(BLACK);
    initialisation_interface();
}

void loop() {
   switch(processus){
     case 0 :
        Tache_init();
        break;
     case 1 :
        Tache_T_1();
        break;
     case 2 :
        Tache_T_2();
        break ;
     default:
     break;
   }
}


