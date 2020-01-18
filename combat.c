#include <stdio.h>
#include <stdlib.h>

int main() {
	int tour = 1;
	
	int heros_pv = 100;
	int heros_pm = 10;
	int heros_pmMax = 10;
	int heros_pmRegen = 1;
	int heros_dmgAtk = 10;
	int heros_dmgPoison = 4;
	int heros_coutPoison = 8;
	int heros_action = 0;
	
	int boss_pv = 100;
	int boss_statutPoison = 0;
	int boss_dmgAtk = 15;
	int boss_action = 0;
	
	int dmg;
	
	while (heros_pv > 0 && boss_pv > 0) {
		printf("Tour %d\n", tour);
		printf("HEROS: %d/100 %d/%d\n", heros_pv, heros_pm, heros_pmMax);
		printf("BOSS : %d/100", boss_pv);
		if (boss_statutPoison)
			printf(" POISON");
		printf("\n");
		printf("\n");
		
		// Choix du joueur
		printf("1 Attaquer | 2 Defendre | 3 Poison (%dPM)\n", heros_coutPoison);
		do {
			printf("> ");
			scanf("%d", &heros_action);
		} while (heros_action != 1 && heros_action != 2 && heros_action != 3);
		printf("\n");
		
		// Choix du boss
		boss_action = rand()%2 + 1;
		
		// Action du joueur
		if (heros_action == 1) {
			if (boss_action == 2) {
				printf("Vous attaquez le BOSS, mais celui-ci se defend.\n");
				dmg = heros_dmgAtk/4;
			} else {
				printf("Vous attaquez le BOSS.\n");
				dmg = heros_dmgAtk;
			}
			printf("> %d DMG\n", dmg);
			printf("> PV BOSS : %d => ", boss_pv);
			boss_pv -= dmg;
			printf("%d\n", boss_pv);
		} else if (heros_action == 2) {
			printf("Vous vous preparez a defendre.\n");
		} else if (heros_action == 3) {
			printf("Vous lancez un sort de poison sur le BOSS.\n");
			if (heros_pm >= heros_coutPoison) {
				printf("Le BOSS est empoisonne.\n");
				heros_pm -= heros_coutPoison;
				boss_statutPoison = 1;
			} else {
				printf("Vous n'avez pas assez de magie, le sort echoue.\n");
			}
		}
		printf("\n");
		
		// Action du boss
		if (boss_pv > 0) {
			if (boss_action == 1) {
				if (heros_action == 2) {
					printf("Le BOSS frappe dans votre garde.\n");
					dmg = boss_dmgAtk/4;
				} else {
					printf("Le BOSS attaque.\n");
					dmg = boss_dmgAtk;
				}
				printf("> %d DMG\n", dmg);
				printf("> PV HEROS : %d => ", heros_pv);
				heros_pv -= dmg;
				printf("%d\n", heros_pv);
			} else if (boss_action == 2) {
				printf("Le BOSS vous regarde intensement.\n");
			}
			printf("\n");
		}
		
		// Altération d'état du BOSS
		if(boss_pv > 0) {
			if (boss_statutPoison) {
				printf("Le poison epuise le BOSS.\n");
				printf("> %d DMG\n", heros_dmgPoison);
				printf("> PV BOSS : %d => ", boss_pv);
				boss_pv -= heros_dmgPoison;
				printf("%d\n", boss_pv);
				printf("\n");
			}
		}
		
		// Résolution du tour
		heros_pm += 1;
		if (heros_pm > heros_pmMax) {
			heros_pm = heros_pmMax;
		}
		tour += 1;
		printf("================================\n\n");
	}
	
	if (heros_pv <= 0) {
		printf("VOUS AVEZ PERDU\n");
	} else {
		printf("VICTOIRE !\n");
	}
	
	return 0;
}