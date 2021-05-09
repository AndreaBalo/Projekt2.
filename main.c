#include <stdio.h>
#include "hajokirandulas.h"
int main() {
<<<<<<< HEAD
    int press;
    Node *root;
    Person *persons=createPerson();
    root=NULL;
    Date date;
    int id=0,place;
    int ok=0;
    char firstname[20],lastname[20];
    printf("Udvozoljuk oldalunkon! \n");
    while (ok==0)
    {
        printf("Mit szeretne tenni? \n");
        printf("Ha foglalni szeretne nyomja meg az egyes gombot! \n");
        printf("Ha foglalast szeretne torolni nyomja meg az kettes gombot! \n");
        printf("A foglalassal kapcsolatos informaciokert nyomja meg a harmas gombot! \n");
        printf("Ha ki szeretne lepni nyomja meg a negyes gombot! \n");
        scanf("%i",&press);
        switch (press)
        {
            case 1:
            {
                printf("Kerem adja meg az Evet. \n");
                scanf("%i",&date.year);
                printf("Kerem adja meg az Honap. \n");
                scanf("%i",&date.month);
                printf("Kerem adja meg az Nap. \n");
                scanf("%i",&date.day);
                if(isValidDate(date.year,date.month,date.day))
                {
                    if(search(root,date))
                    {
                        printf("A megadott datum foglalt \n");
                    } else
                    {
                        insert(&root,date,id);

                        printf("Adja meg a Keresztnev \n");
                        scanf("%s",lastname);
                        printf("Adja meg a Vezeteknevet \n");
                        scanf("%s",firstname);
                        printf("Adja meg hany szemelyre szeretne foglalni \n");
                        scanf("%i",&place);
                        persons=insertPerson(persons,firstname,lastname,id,place);
                        id++;
                        printf("Sikeres foglalas! \n");
                    }
                }
                else
                {
                    printf("Nem valos datum\n");
                }
                break;
            }

            case 2:
            {
                printf("Kerem adja meg az Evet. \n");
                scanf("%i",&date.year);
                printf("Kerem adja meg az Honap. \n");
                scanf("%i",&date.month);
                printf("Kerem adja meg az Nap. \n");
                scanf("%i",&date.day);
                if(isValidDate(date.year,date.month,date.day))
                {
                    if(!search(root,date))
                    {
                        printf("A megadott datum nem  foglalt \n");
                    }
                    else
                    {
                        deleteNode(root,date);
                        printf("Sikeres torles! \n");
                    }
                }
                else
                {
                    printf("Nem valos datum\n");
                }


                break;
            }
            case 3:
            {
                //Foglalas Info
                if(root==NULL)
                {
                    printf("Egyetlen datum sem foglalt!\n");
                } else
                {
                    printf("Foglalt datumok :\n");
                    inorder(root);
                }

                break;
            }
            case 4:
            {
                ok=1;
                break;
            }
            default:
            {
                printf("Nem a megadott lehetoegek kozul valasztott\n" );
                break;

            }

        }
    }
=======
    printf(" World!\n");
    printf("Proba");

    return 0;
}
