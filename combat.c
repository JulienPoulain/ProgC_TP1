#include <stdio.h>

int main() {
	int tour = 1;
	
	int heros_pv = 100;
	int heros_dmgAtk = 10;
	
	int boss_pv = 100;
	int boss_dmgAtk = 15;
	
	while(heros_pv > 0 && boss_pv > 0) {
		printf("Tour %d\n", tour);
		printf("HEROS: %d/100\n", heros_pv);
		printf("BOSS : %d/100\n\n", boss_pv);
		
		printf("JOUEUR attaque BOSS\n");
		printf("%d DMG\n", heros_dmgAtk);
		boss_pv -= heros_dmgAtk;
		printf("PV BOSS : %d\n\n", boss_pv);
		
		printf("BOSS attaque JOUEUR\n");
		printf("%d DMG\n", boss_dmgAtk);
		heros_pv -= boss_dmgAtk;
		printf("PV JOUEUR : %d\n\n", heros_pv);
		
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