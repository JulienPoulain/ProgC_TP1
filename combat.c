#include <stdio.h>

int main() {
	int boss_pv = 100;
	int heros_dmgAtk = 10;
	
	printf("PV Monstre: %d\n", boss_pv);
	
	printf("Joueur attaque Monstre\n");
	printf("%d DMG\n", heros_dmgAtk);
	boss_pv -= heros_dmgAtk;
	
	printf("BOSS - PV : %d\n", boss_pv);
	
	return 0;
}