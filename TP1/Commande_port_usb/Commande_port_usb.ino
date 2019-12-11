/**Scriptmontrantl'usagedelacommunicationsérie *pourdébuggerducode*/ 
int pinBouton= 2; 
int etatBouton; 
int lecture1, lecture2; 
void setup(){ 
  pinMode( pinBouton, INPUT); // Bouton d'entrée 
  etatBouton=digitalRead( pinBouton); 
  Serial.begin(9600); // Démarrage de la communication  série 
  Serial.print("Démarrage du programme,\n"); 
  Serial.print("Presser le bouton.\n");
}
void loop(){ 
  // ---Lecture du bouton avec déparasitage logiciel --// Si pas de parasite, lecture1 égal lecture2 
  lecture1=digitalRead( pinBouton); // première lecture du bouton 
  delay( 10 ); // attendre 10 milli-secondes 
  lecture2=digitalRead( pinBouton); // deuxième lecture du bouton // changement d'état ? 
  if( (lecture1==lecture2) && (lecture1 != etatBouton) ) 
  changeEtatBouton(lecture1); 
} 
void changeEtatBouton( int nouvelEtat)
{ 
  if( nouvelEtat== LOW) { 
    Serial.print( "Bouton relache!\n"); } 
  else{ 
    Serial.print( "Bouton enfonce\n"); } 
  etatBouton=nouvelEtat; 
}
