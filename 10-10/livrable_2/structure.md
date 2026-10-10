mode maintenance

fonction principale


FONCTION principale()
    // Initialisation du matériel
    INITIALISER_systeme()
    INITIALISER_capteurs()
    INITIALISER_carte_SD()
    INITIALISER_RTC()
    INITIALISER_UART()
    
    // Détermination du mode au démarrage
    SI bouton_rouge_presse_au_demarrage ALORS
        mode_actuel = "CONFIGURATION"
    SINON
        mode_actuel = "STANDARD"
    FIN SI
    
    mode_precedent = "STANDARD"
    
    // Boucle infinie du système
    TANT QUE (vrai) FAIRE
        
        // 1. Mise à jour de la LED selon l'état du système
        ACTUALISER_LED(mode_actuel)
        
        // 2. Gestion globale des transitions par boutons
        // Appui de 5 secondes sur le bouton rouge : bascule vers/depuis la maintenance
        SI detecter_appui_long(bouton_rouge, 5_secondes) ALORS
            SI mode_actuel == "MAINTENANCE" ALORS
                mode_actuel = mode_precedent // Rebascule dans le mode précédent[cite: 1]
            SINON SI mode_actuel == "STANDARD" OU mode_actuel == "ECONOMIQUE" ALORS
                mode_precedent = mode_actuel
                mode_actuel = "MAINTENANCE"
            FIN SI
        FIN SI
        
        // 3. Exécution du comportement selon le mode actif
        SELON (mode_actuel) FAIRE
            
            CAS "STANDARD":
                // Vérifier si le bouton vert est pressé 5s pour aller en mode économique[cite: 1]
                SI detecter_appui_long(bouton_vert, 5_secondes) ALORS
                    mode_precedent = "STANDARD"
                    mode_actuel = "ECONOMIQUE"
                FIN SI
                executer_mode_standard()
                
            CAS "CONFIGURATION":
                // Le mode configuration bascule en mode standard après 30 min sans activité[cite: 1]
                SI timeout_inactivite(30_minutes) ALORS
                    mode_actuel = "STANDARD"
                FIN SI
                executer_mode_configuration()
                
            CAS "MAINTENANCE":
                executer_mode_maintenance()
                
            CAS "ECONOMIQUE":
                // Appui de 5 secondes sur le bouton rouge pour rebasculer en mode standard[cite: 1]
                SI detecter_appui_long(bouton_rouge, 5_secondes) ALORS
                    mode_actuel = "STANDARD"
                FIN SI
                executer_mode_economique()
                
        FIN SELON
        
    FIN TANT QUE
FIN FONCTION


FONCTION executer_mode_maintenance()
    // Initialisation spécifique à l'entrée dans le mode maintenance (exécutée une seule fois)
    SI mode_actuel_vient_de_changer ALORS
        DEFINIR_COULEUR_LED("ORANGE")[cite: 2]
        SUSPENDRE_ECRITURE_CARTE_SD() // Sécurise la carte SD pour retrait[cite: 1, 5]
        AFFICHER_CONSOLE_SERIE("--- MODE MAINTENANCE ACTIVE ---")
    FIN SI
    
    // Acquisition et affichage en direct des données capteurs sur le port série
    POUR CHAQUE capteur DANS liste_capteurs FAIRE
        valeur_capteur = LIRE_CAPTEUR(capteur)
        ENVOYER_SUR_UART(nom_capteur, valeur_capteur)[cite: 1, 5]
    FIN POUR
    
    // Vérification de la sécurité de la carte SD (témoin matériel ou optionnel)
    SI carte_SD_retiree_ou_prete_a_changer() ALORS
        AFFICHER_CONSOLE_SERIE("Carte SD prête à être manipulée en sécurité.")
    FIN SI
    
    // Petite pause pour éviter de saturer le processeur et le port série
    ATTENDRE(1_seconde)
    
    // Note : La sortie de ce mode est gérée globalement dans la boucle principale 
    // par l'intermédiaire de l'appui long de 5 secondes sur le bouton rouge[cite: 1, 5].
FIN FONCTION
