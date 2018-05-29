
//***************************************
//**************** LES TÂCHES ***********
//***************************************

void  Tache_init(){
Serial.println("principale");
principale_action();
_Affichagelcd();
}

void  Tache_T_1(){
   Serial.println("clavier");
   change_temperature();
   //change_h();
   //change_date();
}

void  Tache_T_2(){
   Serial.println("capteur");
   Serial.println(processus);
}

