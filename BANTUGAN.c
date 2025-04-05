/*I declare, upon my honor, that I did this machine problem assignment as a
collaboration with (enumerate your collaborators, maximum of 3 other collaborators).
Further, my solution is not a copy of any of my collaborators.*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>


typedef struct{
    int mana;
    int health;
    int sword; 
    int shield;
    int jade;
    int blink;
    int blink_used;
    int dodgeShield;
    char name[50];
}stats;


void printStats(stats Stats){
    
    //First player stats
    printf("BANTUGAN %s\n", Stats.name);
    printf("Health: %i Mana: %i ", Stats.health, Stats.mana);

    //firstplayer Attack information
    if (Stats.sword == 3){
        printf("Weapon: Diamond Scythe ");
        if (Stats.shield == 3)
            printf("Shield: Diamond Shield ");
        else if(Stats.shield == 2)
            printf("Shield: Silver Shield ");
        else 
            printf("Shield: Wooden Shield ");
    }
    else if (Stats.sword == 2){
        printf("Weapon: Silver Axe ");
        if (Stats.shield == 3)
            printf("Shield: Diamond Shield ");
        else if(Stats.shield == 2)
            printf("Shield: Silver Shield ");
        else 
            printf("Shield: Wooden Shield ");
    }
    else{
        printf("Weapon: Wooden Spear ");
        if (Stats.shield == 3)
            printf("Shield: Diamond Shield ");
        else if(Stats.shield == 2)
            printf("Shield: Silver Shield ");
        else 
            printf("Shield: Wooden Shield ");
    }

    if (Stats.jade){
        printf ("Jade Palapa: %i ", Stats.jade);
        if (Stats.blink)
            printf("Bai-a-Labi's Blink: %i \n", Stats.blink);
        else 
            printf("Bai-a-Labi's Blink: %i \n", Stats.blink);
    }
    else {
        printf ("Jade Palapa: %i ", Stats.jade);
        if (Stats.blink)
            printf("Bai-a-Labi's Blink: %i \n", Stats.blink);
        else 
            printf("Bai-a-Labi's Blink: %i \n", Stats.blink);
    }
}
void spellUsed(stats *A_stats, stats *B_stats, int blink){
    A_stats->mana -= 6;
    if (blink && B_stats->mana >= 6 && !B_stats->blink_used){

    }
}
void swordOnly(stats *A_stats, stats *B_stats, int def){
    int damageHolder = 0;
    if (def){
        if (A_stats->sword > B_stats->shield){
            damageHolder = A_stats->sword - B_stats->shield;
            B_stats->health -= damageHolder;
        }
        else if (A_stats->sword == B_stats->shield){
            return;
        }
        else {
            damageHolder = B_stats->shield - A_stats->sword;
            A_stats->health -= damageHolder;

        }
    }

    else {
        B_stats->health -= A_stats->sword;
    }
    if (A_stats->health < 0)
    A_stats->health = 0;
    if (B_stats->health < 0)
    B_stats->health = 0;
}

void gameProper(stats *atk_stats, stats *def_stats, int atk_UseSpell, int defDodge, int def_useBlink){
    if (atk_stats->mana >= 6 && atk_stats->jade == 1 && atk_UseSpell == 1 ){
        spellUsed(atk_stats, def_stats, def_useBlink);
    }
    else{
        swordOnly(atk_stats, def_stats, defDodge);
    }
    atk_stats->mana += 2;
    def_stats->mana += 2;

    if (atk_stats->mana > 10)
        atk_stats->mana = 10;
    if(def_stats->mana > 10)
        def_stats->mana = 10;
}   

int main(){
    unsigned int testCase;
    int numTurns;

    scanf("%i", &testCase);
    for (int i = 0; i < testCase; i++){
        srand(time(NULL));
        int firstTurn;

        stats timuaStats; 
        stats duaStats; 

        // copy 
        stats *atk_stats;
        stats *def_stats; 

        timuaStats.mana = 10; 
        timuaStats.health = 10;
        strcpy(timuaStats.name, "TIMAN");
        timuaStats.jade = 0;
        timuaStats.blink = 0;
        //timuaStats.sword = (rand()%3) + 1;
        //timuaStats.shield = (rand()%3) + 1;

        
        duaStats.mana = 10;
        duaStats.health = 10;
        strcpy(duaStats.name, "DUA");
        duaStats.jade = 0;
        duaStats.blink = 0;
        // duaAttack.sword = (rand()%3) + 1;
        // duaAttack.shield = (rand()%3) + 1;    
        do{
            //printf("TIMUA SWORD AND SHIELD");
        scanf("%i %i", &timuaStats.sword, &timuaStats.shield);
        }while(timuaStats.sword < 1 || timuaStats.sword > 4 ||
            timuaStats.shield < 1 || timuaStats.shield > 4);

            //printf("DUA SWORD AND SHIELD");
        scanf("%i %i", &duaStats.sword, &duaStats.shield);
    
        
        //selecting player turn
        do{
        scanf("%i", &firstTurn);
        /*if (firstTurn > 2 || firstTurn == 0)
            printf("Retry the first player turn\n");*/
        }while(firstTurn < 0 || firstTurn > 3);


        // for adjusting which player should Stats first



        scanf("%i", &numTurns);
        for (int j = 0; j <2*numTurns; j++){
            int spellUse;
            int atk_jade, atk_blink, def_jade, def_blink, atk_UseSpell, def_dodgeShield, def_useBlink;
            //printf("INPUT ATTACK INFO: ");
            scanf("%i %i %i %i", &timuaStats.jade, &timuaStats.blink, &duaStats.jade, &duaStats.blink);
            scanf("%i", &atk_UseSpell);
            scanf("%i %i", &def_dodgeShield, &def_useBlink);


            if (firstTurn == 1){
                atk_stats = &timuaStats;
                def_stats = &duaStats;
            }
    
            else {
                atk_stats = &duaStats;
                def_stats = &timuaStats;
            }

            gameProper(atk_stats, def_stats, atk_UseSpell, def_dodgeShield, def_useBlink);


            printStats(timuaStats);
            printStats(duaStats);

            if(timuaStats.health <= 0 && duaStats.health <= 0){
                printf("DRAW! BOTH BANTUGANS SUCCUMBED AND WILL BE OFFERED TO LAKE RANAO AS SACRIFICE. MAY THE PAPANOKA MRA REWARD THEM GRACIOUSLY.\n");
                break;
            }else if (timuaStats.health <= 0){
                printf("BANTUGAN TIMAN FALLS! MAY THE PAPANOKA MRA REWARD HIS COURAGE GRACIOUSLY. TO THE LAKE RANAO!\n");
                break;
            }else if(duaStats.health <= 0){
                printf("BANTUGAN DUA FALLS! MAY THE PAPANOKA MRA REWARD HIS COURAGE GRACIOUSLY. TO THE LAKE RANAO!\n");
                break;
            }

            // atk_stats->mana += 2;
            // def_stats->mana += 2;
        
            // if (atk_stats->mana > 10)
            //     atk_stats->mana = 10;
            // if(def_stats->mana > 10)
            //     def_stats->mana = 10;


            if (firstTurn == 1)
                firstTurn = 2;
            else 
                firstTurn = 1;
            
            
        }



        

        

    }
    return 0;
}


