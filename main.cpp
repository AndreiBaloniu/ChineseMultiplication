#include <iostream>

using namespace std;

int cifre_nr(int n)
{int nr = 0;
    if (n == 0)
//daca numarul este 0 atunci lui nr i se atribuie 1 deoarece n are o singura cifra
        nr = 1;
    else
    {
//cat timp n este diferit de 0 se numara si se taie pe rand cifrele acestuia
        while (n!=0)
        {
            nr++;
            n = n / 10;
        }

    }
    return nr;
}

int chinese_multiplication(int a, int b)
{   /*
 * u_a/ u_b reprezinta unitatile
 * z_a/ z_b reprezinta zecile
 * s_a/ s_b reprezinta sutele
 * */
    int res=0;//rezultatul inmultirii
    int nr_cifre_a = cifre_nr(a);
    int nr_cifre_b = cifre_nr(b);
    //Vom facem pe cazuri inmultirea in functie de nr de cifre al numerelor
    //Cazul 1: numerele sunt cifre
    if (nr_cifre_a == 1 && nr_cifre_b== 1)
        res = a*b;
    //Cazul 2: primul numar este de 2 cifre, iar celalalt e o cifra
    if (nr_cifre_a == 2 && nr_cifre_b == 1)
        {
        res = b*(a%10 + a/10%10*10);
        }
    //Cazul 2*: primul numar este o cifra, iar celalalt un numar de 2 cifre asa ca le inversam
    if (nr_cifre_a == 1 && nr_cifre_b == 2)
    {
        swap(a,b);
        res = b*(a%10 + a/10%10*10);
    }
    //Cazul 2**: primul numar este de 3 cifre, iar celalalt este de o cifra
    if (nr_cifre_a == 3 && nr_cifre_b == 1)
    {
        res = b*(a%10 + a/10%10*10+a/100%10*100);
    }
    //Cazul 2***: primul numar este o cifra, iar celalalt un numar de 3 cifre asa ca le inversam
    if (nr_cifre_a == 1 && nr_cifre_b == 3)
    {
        swap(a,b);
        res = b*(a%10 + a/10%10*10+a/100%10*100);
    }
    //Cazul 3: numerele sunt de 2 cifre
    if(nr_cifre_a==2 && nr_cifre_b==2)
        {int u_a=a%10;
        int z_a=a/10%10;
        int u_b=b%10;
        int z_b=b/10%10;
        res = u_a*u_b+10*(z_a*u_b+z_b*u_a)+z_a*z_b*100;

        }
    //Cazul 4: primul numar este de 3 cifre, celalalt de 2
    if (nr_cifre_a==3 && nr_cifre_b == 2)
    {   int u_a=a%10;
        int z_a=a/10%10;
        int s_a=a/100%10;
        int u_b=b%10;
        int z_b=b/10%10;
        res = u_a*u_b+10*(z_a*u_b+z_b*u_a)+100*(s_a*u_b+z_a*z_b)+1000*(s_a*z_b);

    }
    //Cazul 4*: primul numar este de 2 cifre, celalalt de 3 asa ca le inversam
    if (nr_cifre_a==2 && nr_cifre_b == 3)
    {
        swap(a,b);
        int u_a=a%10;
        int z_a=a/10%10;
        int s_a=a/100%10;
        int u_b=b%10;
        int z_b=b/10%10;
        res = u_a*u_b+10*(z_a*u_b+z_b*u_a)+100*(s_a*u_b+z_a*z_b)+1000*(s_a*z_b);

    }
    //Cazul 5: ambele numere sunt de 3 cifre
    if (nr_cifre_a==3 && nr_cifre_b == 3)
    {int u_a=a%10;
        int z_a=a/10%10;
        int s_a=a/100%10;
        int u_b=b%10;
        int z_b=b/10%10;
        int s_b=b/100%10;
        res = u_a*u_b+10*(z_a*u_b+z_b*u_a)+100*(s_a*u_b+z_a*z_b+s_b*u_a)+1000*(s_a*z_b+s_b*z_a)+10000*(s_a*s_b);

    }
    //Cazul 0: in caz de vreun numar este 0
    if (nr_cifre_a == 0 || nr_cifre_b == 0)
        res = 0;

    //Returnam rezultatul
    return res;
}
int main()
{
    int a,b;
    cin>>a>>b;
    cout<<chinese_multiplication(a,b);
}
