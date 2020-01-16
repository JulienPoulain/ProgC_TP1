#include <stdio.h>

int main() {
	int tour = 1;
	int boss_pv = 100;
	int heros_dmgAtk = 10;
	
	while(boss_pv > 0) {
		printf("================================\n");
		printf("Tour %d\n", tour);
		printf("PV BOSS: %d\n", boss_pv);
		
		printf("JOUEUR attaque BOSS\n");
		printf("%d DMG\n", heros_dmgAtk);
		boss_pv -= heros_dmgAtk;
		
		printf("BOSS - PV : %d\n", boss_pv);
		
		tour += 1;
	}
	
	return 0;
}