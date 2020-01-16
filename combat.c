#include <stdio.h>

int main() {
	int tour = 1;
	
	int heros_pv = 100;
	int heros_dmgAtk = 10;
	int heros_action = 0;
	
	int boss_pv = 100;
	int boss_dmgAtk = 15;
	
	int dmg;
	
	while(heros_pv > 0 && boss_pv > 0) {
		printf("Tour %d\n", tour);
		printf("HEROS: %d/100\n", heros_pv);
		printf("BOSS : %d/100\n\n", boss_pv);
		
		// Choix du joueur
		printf("1 Attaquer | 2 Defendre\n");
		do {
			scanf("%d", &heros_action);
		} while(heros_action != 1 && heros_action != 2);
		printf("\n");
		
		// Action du joueur
		if(heros_action == 1) {
			printf("Le HEROS attaque le BOSS.\n");
			printf("%d DMG\n", heros_dmgAtk);
			boss_pv -= heros_dmgAtk;
			printf("PV BOSS : %d\n\n", boss_pv);
		} else if (heros_action == 2) {
			printf("Le HEROS se defend.\n\n");
		}
		
		// Action du boss
		printf("Le BOSS attaque.\n");
		if(heros_action == 2) {
			dmg = boss_dmgAtk/4;
		} else {
			dmg = boss_dmgAtk;
		}
		printf("%d DMG\n", dmg);
		heros_pv -= dmg;
		printf("PV HEROS : %d\n\n", heros_pv);
		
		printf("================================\n\n");
		tour += 1;
	}
	
	if(heros_pv <= 0) {
		printf("VOUS AVEZ PERDU\n");
	} else {
		printf("VICTOIRE !\n");
	}
	
	return 0;
}