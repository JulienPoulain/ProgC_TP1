#include <stdio.h>
#include <stdlib.h>

int main() {
	int tour = 1;
	
	int heros_pv = 100;
	int heros_dmgAtk = 10;
	int heros_action = 0;
	
	int boss_pv = 100;
	int boss_dmgAtk = 15;
	int boss_action = 0;
	
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
		
		// Choix du boss
		boss_action = rand()%2 + 1;
		
		// Action du joueur
		if(heros_action == 1) {
			if(boss_action == 2) {
				printf("Vous attaquez le BOSS, mais celui-ci se defend.\n");
				dmg = heros_dmgAtk/4;
			} else {
				printf("Vous attaquez le BOSS.\n");
				dmg = heros_dmgAtk;
			}
			printf("%d DMG\n", dmg);
			printf("PV BOSS : %d => ", boss_pv);
			boss_pv -= dmg;
			printf("%d\n\n", boss_pv);
		} else if (heros_action == 2) {
			printf("Vous vous preparez a defendre.\n\n");
		}
		
		// Action du boss
		if (boss_action == 1) {
			if(heros_action == 2) {
				printf("Le BOSS frappe dans votre garde.\n");
				dmg = boss_dmgAtk/4;
			} else {
				printf("Le BOSS attaque.\n");
				dmg = boss_dmgAtk;
			}
			printf("%d DMG\n", dmg);
			printf("PV HEROS : %d => ", heros_pv);
			heros_pv -= dmg;
			printf("%d\n\n", heros_pv);
		} else if (boss_action == 2){
			printf("Le BOSS vous regarde intensement.\n\n");
		}
		
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