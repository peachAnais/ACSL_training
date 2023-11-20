// Boolean - Written by St Fancis Xavier CI, Ontario
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
void Label (bool col1[20],char lc1[30],bool col2[20],char lc2[30],bool col3[20], char lc3[30],int nvar);

int main(int argc, char* argv[])
{
    bool map[10][20];
    char label [10][30];

   char buf[256];
    while (1)
    {
        memset (map, 0, 10*20*sizeof(bool));
        memset (label, 0, 10*30*sizeof(char));

        fgets(buf, 256, stdin);
        int ncol;
        int &nvar = ncol;
        sscanf (buf, "%d\n",&ncol);
        //get #vars

        fgets(buf, 256, stdin);
        int nops;
        sscanf (buf, "%d\n",&nops);
        //get #ops

        for (int i=0;i<ncol;i++)
        {
            label[i][0]='A'+i;
        }
        //initialise init headers;

        for (int i=0;i<nvar;i++)
        {
            for (int j=0;j< (1<<nvar); j++)
            {
                map[i][j] = j & (1 << (nvar-i-1));
            }
        }
        //init first nvar colums

        for (int i=0;i< (1<<nvar);i++)
        {
            memset (buf, 0, 256);
            fgets(buf, 256, stdin);
            for (int j=0;j<nops;j++)
            {
                map[j+nvar][i] = (bool)(buf[j]=='1');
            }
        }
        //table filled... generate labels.
        for (int i=0;i<nops;i++)
        {
            const int col = i+nvar;
            fgets(buf, 256, stdin);
            int c1,c2;
            sscanf (buf, "%01d%01d\n",&c1,&c2);
            //now generate column label based on c1 and c2,
            c1--;c2--;
            Label (map[c1],label[c1],map[c2],label[c2],map[col],label[col],nvar);
        }
        printf ("%s\n", label[nops + nvar - 1]);
    }

}
//---------------------------------------------------------------------------
void Label (bool col1[20],char lc1[30],bool col2[20],char lc2[30],bool col3[20], char lc3[30],int nvar)
{
    bool op;

    op = true;
    for (int i=0;i< (1<< nvar); i++)
    {
        op &= ((col1[i] && col2[i]) == col3[i]);
    }
    if (op)
    {
        strcpy (lc3, "(");
        if (lc1[0]!='(') strcat (lc3, " ");
        strcat (lc3, lc1);

        strcat (lc3, " AND ");

        strcat (lc3, lc2);
        if (lc2[strlen(lc2)-1]!=')') strcat (lc3, " ");
        strcat (lc3, ")");
        return;
    }



//========================================================================
    op = true;
    for (int i=0;i< (1<< nvar); i++)
    {
        op &= ((col1[i] || col2[i]) == col3[i]);
    }
    if (op)
    {
        strcpy (lc3, "(");
        if (lc1[0]!='(') strcat (lc3, " ");
        strcat (lc3, lc1);

        strcat (lc3, " OR ");

        strcat (lc3, lc2);
        if (lc2[strlen(lc2)-1]!=')') strcat (lc3, " ");
        strcat (lc3, ")");
        return;
    }



//========================================================================
    op = true;
    for (int i=0;i< (1<< nvar); i++)
    {
        op &= ((bool)(col1[i] ^ col2[i]) == col3[i]);
    }
    if (op)
    {
        strcpy (lc3, "(");
        if (lc1[0]!='(') strcat (lc3, " ");
        strcat (lc3, lc1);

        strcat (lc3, " XOR ");

        strcat (lc3, lc2);
        if (lc2[strlen(lc2)-1]!=')') strcat (lc3, " ");
        strcat (lc3, ")");
        return;
    }



//========================================================================
    op = true;
    for (int i=0;i< (1<< nvar); i++)
    {
        op &= ((!(col1[i] && col2[i])) == col3[i]);
    }
    if (op)
    {
        strcpy (lc3, "(");
        if (lc1[0]!='(') strcat (lc3, " ");
        strcat (lc3, lc1);

        strcat (lc3, " NAND ");

        strcat (lc3, lc2);
        if (lc2[strlen(lc2)-1]!=')') strcat (lc3, " ");
        strcat (lc3, ")");
        return;
    }



//========================================================================
    op = true;
    for (int i=0;i< (1<< nvar); i++)
    {
        op &= ((!(col1[i] || col2[i])) == col3[i]);
    }
    if (op)
    {
        strcpy (lc3, "(");
        if (lc1[0]!='(') strcat (lc3, " ");
        strcat (lc3, lc1);

        strcat (lc3, " NOR ");

        strcat (lc3, lc2);
        if (lc2[strlen(lc2)-1]!=')') strcat (lc3, " ");
        strcat (lc3, ")");
        return;
    }



//========================================================================
    op = true;
    for (int i=0;i< (1<< nvar); i++)
    {
        op &= ((!((bool)(col1[i] ^ col2[i]))) == col3[i]);
    }
    if (op)
    {
        strcpy (lc3, "(");
        if (lc1[0]!='(') strcat (lc3, " ");
        strcat (lc3, lc1);

        strcat (lc3, " XNOR ");

        strcat (lc3, lc2);
        if (lc2[strlen(lc2)-1]!=')') strcat (lc3, " ");
        strcat (lc3, ")");
        return;
    }

    printf ("Error. No Operation matches cols %s and %s\n", lc1, lc2);




}
 