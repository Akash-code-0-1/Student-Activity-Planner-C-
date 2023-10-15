#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
void welcome_page();
void main_manue();
void account_register();
void login();
void menue();
void add_plans();
void modify_plans();
void week_act_pln();
void class_rtn_pln();
void meetings_pln();
void modify_week_act_pln();
void modify_class_rtn_pln();
void modify_meetings_pln();
void main_interface();
void user_plans();
void customization();
struct student
{
    char username[10];
    char password[10];
};
struct stdnt_week_act
{
    char day[10];
    char input1[50];
    char input2[50];
    char input3[50];
    char input4[50];
    char input5[50];
};
struct stdnt_routine_pln
{
    char day[10];
    char sub1_nam[10];
    char sub2_nam[10];
    char sub3_nam[10];
    char sub4_nam[10];
    char sub5_nam[10];
    char sub1_time[10];
    char sub2_time[10];
    char sub3_time[10];
    char sub4_time[10];
    char sub5_time[10];
};
struct stdnt_meeting_pln
{
    char day[10];
    char mtnwith[15];
    char address[20];
    char time[10];
    char drtn[10];
    char note[300];
};

int num;
char matchday[10];
int main()
{
    system("cls");
    welcome_page();
    system("cls");
    main_manue();
    system("cls");
    return 0;
}

void welcome_page()
{
    printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t        =                 WELCOME                   =");
    printf("\n\t\t\t        =                   TO                      =");
    printf("\n\t\t\t        =            STUDENT ACTIVITY               =");
    printf("\n\t\t\t        =                 PALANNER                  =");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-****-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    printf("\n\n\n\t\t\t Enter any key to continue.....");
    getch();
    system("cls");
}

void main_manue()
{
    printf("\n\t\t\t\t1) Regisrter Account\n\n\t\t\t\t2) Login");
    printf("\n\n\t\t\t\tEnter your Choice: ");
    scanf("%d", &num);
    switch (num)
    {
    case 1:
        account_register();
        printf("\n\n\n\t\t\t Enter any key to continue.....");
        getch();
        login();
        break;
    case 2:
        login();
    default:
        break;
    }
}

void account_register()
{
    FILE *registrationinfo;
    struct student std;
    registrationinfo = fopen("regiinfo.text", "w");
    if (registrationinfo == NULL)
    {
        printf("Error");
        exit(1);
    }
    system("cls");
    printf("\n\t\t\t\tRegister Your Account");
    printf("\n********************************************************************************");

    fflush(stdin);
    printf("\nUser Name: ");
    gets(std.username);
    fflush(stdin);
    printf("\nPassword: ");
    gets(std.password);
    fwrite(&std, sizeof(std), 1, registrationinfo);
    fclose(registrationinfo);
    system("cls");
    printf("\n*********** Add Your Plans ***************\n");
    add_plans();
}

void login()
{
    char try;
    FILE *registrationinfo;
    struct student std;
    char usrnm[10];
    char pass[10];
    system("cls");
    printf("\n\t\t\t\tLogin Your Account");
    printf("\n********************************************************************************");

    fflush(stdin);
    printf("\nUser Name: ");
    gets(usrnm);
    fflush(stdin);
    printf("\nPassword: ");
    gets(pass);
    fflush(stdin);
    printf("\nDay: ");
    gets(matchday);
    fflush(stdin);
    registrationinfo = fopen("regiinfo.text", "r");
    if (registrationinfo == NULL)
    {
        printf("Error");
        exit(1);
    }
    while (fread(&std, sizeof(std), 1, registrationinfo) == 1)
    {
        if (strcmp(usrnm, std.username) == 0 && strcmp(pass, std.password) == 0)
        {
            printf("\nSUCCESSFULLY LOGGED IN");
            system("cls");
            menue();
            system("cls");
        }
        else
        {
            printf("\nIncorrect Password!");
            printf("\n\nYou want to try again  'y'or 'n' :");
            try = getchar();
            if (try == 'y')
            {
                login();
            }
            else if (try == 'n')
            {
                main_manue();
            }
        }
    }
    fclose(registrationinfo);
}
void menue()
{
    system("cls");
    main_interface();
    system("cls");
    customization();
}

void customization()
{
    int choice;
    system("cls");
    printf("\n\n\t1. Add Your Plans\n");
    printf("\t2. Modify Your Plans\n");
    printf("\t3. Search plan");
    printf("\n\n\tEnter your choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        system("cls");
        add_plans();
        break;
    case 2:
        system("cls");
        modify_plans();
        break;
    case 3:
        system("cls");
        login();
        break;
    default:
        break;
    }
}
void add_plans()
{

    int choice2;
    system("cls");
    printf("\n\n\t1. Week activity Planner\n");
    printf("\t2. Class Routine Planner\n");
    printf("\t3. Meetings Planner\n");
    printf("\t4. Skip & Your Plan\n");
    printf("\t5. Back to Main Menue\n");
    printf("\n\n\tEnter Your Choice: ");
    scanf("%d", &choice2);
    switch (choice2)
    {
    case 1:
        week_act_pln();
        break;
    case 2:
        class_rtn_pln();
        break;
    case 3:
        meetings_pln();
        break;
    case 4:
        user_plans();
        break;
    case 5:
        system("cls");
        customization();
        break;
    default:
        break;
    }
}
void modify_plans()
{
    int choice3;
    printf("1. Modify Week activity Planner\n");
    printf("2. Modify Class Routine Planner\n");
    printf("3. Modify Meetings Planner\n");
    printf("4.Back to Main Menue\n");
    printf("\n\nEnter Your Choice: ");
    scanf("%d", &choice3);
    switch (choice3)
    {
    case 1:
        modify_week_act_pln();
        break;
    case 2:
        modify_class_rtn_pln();
        break;
    case 3:
        modify_meetings_pln();
        break;
    case 4:
        system("cls");
        customization();
        break;

    default:
        break;
    }
}
void week_act_pln()
{
    char another = 'y';
    FILE *week_act;
    struct stdnt_week_act wk;
    system("cls");
    week_act = fopen("week_act_plan.txt", "ab+");
    if (week_act == NULL)
    {
        printf("Error opening file");
        exit(1);
    }
    fflush(stdin);
    while (another == 'y')
    {
        printf("\t\t\t<--:ADD WEEK SCYIVITIES :-->\n");
        printf("\tEnter Day : ");
        gets(wk.day);
        printf("\n\t1 : ");
        gets(wk.input1);
        printf("\n\t2 : ");
        gets(wk.input2);
        printf("\n\t3 : ");
        gets(wk.input3);
        printf("\n\t4 : ");
        gets(wk.input4);
        printf("\n\t5 : ");
        gets(wk.input5);
        fflush(stdin);
        fwrite(&wk, sizeof(wk), 1, week_act);
        printf("\n\tWant to add of another record? Then press 'y' else 'n'.");
        fflush(stdin);
        another = getch();
        system("cls");
        fflush(stdin);
    }
    fclose(week_act);
    printf("\n\n\tPress any key to continue.");
    getch();
    if (another == 'n')
    {
        system("cls");
        add_plans();
        system("cls");
    }
}
void class_rtn_pln()
{
    char another = 'y';
    FILE *cls_rtn;
    struct stdnt_routine_pln crp;
    system("cls");
    fflush(stdin);
    cls_rtn = fopen("cls_rtn_plan.txt", "ab+");
    if (cls_rtn == NULL)
    {
        printf("Error opening file");
        exit(1);
    }
    fflush(stdin);
    while (another == 'y')
    {
        printf("\t\t\t<--:ADD CLASS ROUTINE:-->\n");
        printf("\tEnter Day : ");
        gets(crp.day);
        printf("\n\tEnter Subject Name : ");
        gets(crp.sub1_nam);
        printf("\n\tEnter Class Time : ");
        gets(crp.sub1_time);
        printf("\n\tEnter Subject Name : ");
        gets(crp.sub2_nam);
        printf("\n\tEnter Class Time : ");
        gets(crp.sub2_time);
        printf("\n\tEnter Subject Name : ");
        gets(crp.sub3_nam);
        printf("\n\tEnter Class Time : ");
        gets(crp.sub3_time);
        printf("\n\tEnter Subject Name : ");
        gets(crp.sub4_nam);
        fflush(stdin);
        printf("\n\tEnter Class Time : ");
        gets(crp.sub4_time);
        fflush(stdin);
        printf("\n\tEnter Subject Name : ");
        gets(crp.sub5_nam);
        fflush(stdin);
        printf("\n\tEnter Class Time : ");
        gets(crp.sub5_time);
        fflush(stdin);
        fwrite(&crp, sizeof(crp), 1, cls_rtn);
        printf("\n\tWant to add of another record? Then press 'y' else 'n'.");
        fflush(stdin);
        another = getch();
        system("cls");
        fflush(stdin);
    }
    fflush(stdin);
    fclose(cls_rtn);
    printf("\n\n\tPress any key to continue.");
    getch();
    if (another == 'n')
    {
        system("cls");
        add_plans();
    }
}
void meetings_pln()
{
    char another = 'y';
    FILE *mtn_plan;
    struct stdnt_meeting_pln mtg;
    system("cls");

    mtn_plan = fopen("meeting_act_plan.txt", "ab+");
    if (mtn_plan == NULL)
    {
        printf("Error opening file");
        exit(1);
    }
    fflush(stdin);
    while (another == 'y')
    {
        printf("\t\t\t<--:ADD MEETING DETAILS:-->\n");
        printf("\tEnter Day : ");
        gets(mtg.day);
        printf("\n\tMeeting With: ");
        gets(mtg.mtnwith);
        fflush(stdin);
        printf("\n\tAddress: ");
        gets(mtg.address);
        fflush(stdin);
        printf("\n\tEnter Time: ");
        gets(mtg.time);
        fflush(stdin);
        printf("\n\tDuration: ");
        gets(mtg.drtn);
        fflush(stdin);
        printf("\n\tImportant Note: ");
        gets(mtg.note);
        fflush(stdin);
        fwrite(&mtg, sizeof(mtg), 1, mtn_plan);
        printf("\n\tWant to add of another record? Then press 'y' else 'n'.");
        fflush(stdin);
        another = getch();
        system("cls");
        fflush(stdin);
    }
    fclose(mtn_plan);
    printf("\n\n\tPress any key to continue.");
    getch();
    if (another == 'n')
    {
        system("cls");
        add_plans();
    }
}
void modify_week_act_pln()
{
    char usrday[10];
    FILE *week_act;
    struct stdnt_week_act wk;
    system("cls");
    printf("\t\t\t<--:MODIFY WEEK ACTIVITIES:-->\n");
    printf("\n\tEnter name of Day to modify: ");
    fflush(stdin);
    gets(usrday);
    week_act = fopen("week_act_plan.txt", "rb+");
    if (week_act == NULL)
    {
        printf("Error opening file");
        exit(1);
    }
    rewind(week_act);
    fflush(stdin);
    while (fread(&wk, sizeof(wk), 1, week_act) == 1)
    {
        if (strcmp(usrday, wk.day) == 0)
        {
            printf("\n\t1 : ");
            gets(wk.input1);
            printf("\n\t2 : ");
            gets(wk.input2);
            printf("\n\t3 : ");
            gets(wk.input3);
            printf("\n\t4 : ");
            gets(wk.input4);
            printf("\n\t5 : ");
            gets(wk.input5);
            fflush(stdin);
            fseek(week_act, -sizeof(wk), SEEK_CUR);
            fwrite(&wk, sizeof(wk), 1, week_act);
            break;
        }
    }
    fclose(week_act);
    printf("\n\nPress any key to continue.");
    getch();
    system("cls");
    modify_plans();
}
void modify_class_rtn_pln()
{
    char usrday[10];
    FILE *cls_rtn;
    struct stdnt_routine_pln crp;
    system("cls");
    printf("\t\t\t<--:MODIFY CLASS ROUTINE:-->\n");
    printf("\nEnter name of Day to modify: ");
    fflush(stdin);
    gets(usrday);
    cls_rtn = fopen("cls_rtn_plan.txt", "rb+");
    if (cls_rtn == NULL)
    {
        printf("Error opening file");
        exit(1);
    }
    rewind(cls_rtn);
    fflush(stdin);
    system("cls");
    while (fread(&crp, sizeof(crp), 1, cls_rtn) == 1)
    {
        if (strcmp(usrday, crp.day) == 0)
        {
            printf("\t\t\t<--:Modify CLASS ROUTINE:-->\n");
            printf("\n\tEnter Subject Name : ");
            gets(crp.sub1_nam);
            printf("\n\tEnter Class Time : ");
            gets(crp.sub1_time);
            printf("\n\tEnter Subject Name : ");
            gets(crp.sub2_nam);
            printf("\n\tEnter Class Time : ");
            gets(crp.sub2_time);
            printf("\n\tEnter Subject Name : ");
            gets(crp.sub3_nam);
            printf("\n\tEnter Class Time : ");
            gets(crp.sub3_time);
            printf("\n\tEnter Subject Name : ");
            gets(crp.sub4_nam);
            fflush(stdin);
            printf("\n\tEnter Class Time : ");
            gets(crp.sub4_time);
            fflush(stdin);
            printf("\n\tEnter Subject Name : ");
            gets(crp.sub5_nam);
            fflush(stdin);
            printf("\n\tEnter Class Time : ");
            gets(crp.sub5_time);
            fflush(stdin);
            fwrite(&crp, sizeof(crp), 1, cls_rtn);
            fflush(stdin);
            system("cls");
            fflush(stdin);
            fseek(cls_rtn, -sizeof(crp), SEEK_CUR);
            fwrite(&crp, sizeof(crp), 1, cls_rtn);
            break;
        }
    }
    fclose(cls_rtn);
    printf("\n\nPress any key to continue.");
    getch();
    system("cls");
    modify_plans();
}
void modify_meetings_pln()
{
    char usrday[10];
    FILE *mtn_plan;
    struct stdnt_meeting_pln mtg;
    system("cls");
    printf("\t\t\t<--:MODIFY MEETING DETAILS:-->\n");
    printf("\nEnter name of Day to modify: ");
    fflush(stdin);
    gets(usrday);

    mtn_plan = fopen("meeting_act_plan.txt", "rb+");
    if (mtn_plan == NULL)
    {
        printf("Error opening file");
        exit(1);
    }
    rewind(mtn_plan);
    fflush(stdin);
    system("cls");
    while (fread(&mtg, sizeof(mtg), 1, mtn_plan) == 1)
    {
        if (strcmp(usrday, mtg.day) == 0)
        {
            printf("\t\t\t<--:Modify MEETING  DETAILS:-->\n");
            printf("Enter Day : ");
            gets(mtg.day);
            printf("\nMeeting With: ");
            gets(mtg.mtnwith);
            fflush(stdin);
            printf("\nAddress: ");
            gets(mtg.address);
            fflush(stdin);
            printf("\nEnter Time: ");
            gets(mtg.time);
            fflush(stdin);
            printf("\nDuration: ");
            gets(mtg.drtn);
            fflush(stdin);
            printf("\nImportant Note: ");
            gets(mtg.note);
            fflush(stdin);
            fwrite(&mtg, sizeof(mtg), 1, mtn_plan);
            fflush(stdin);
            system("cls");
            fflush(stdin);
            fseek(mtn_plan, -sizeof(mtg), SEEK_CUR);
            fwrite(&mtg, sizeof(mtg), 1, mtn_plan);
            break;
        }
    }
    fclose(mtn_plan);
    printf("\n\nPress any key to continue.\n");
    getch();
    system("cls");
    modify_plans();
}
void main_interface()
{
    system("cls");
    FILE *week_act;
    struct stdnt_week_act wk;
    char stname[20];

    fflush(stdin);
    week_act = fopen("week_act_plan.txt", "rb+");
    if (week_act == NULL)
    {
        printf("Error opening file");
        exit(1);
    }
    while (fread(&wk, sizeof(wk), 1, week_act) == 1)
    {

        if (strcmp(matchday, wk.day) == 0)
        {
            printf("***************      %s     *************", matchday);
            printf("\n***********************************************");
            printf("\n*           1 : %s               ", wk.input1);
            printf("\n*           2 : %s               ", wk.input2);
            printf("\n*           3 : %s               ", wk.input3);
            printf("\n*           4 : %s               ", wk.input4);
            printf("\n*           5 : %s               ", wk.input5);
            printf("\n***********************************************\n");
            fflush(stdin);
        }
    }
    fclose(week_act);
    fflush(stdin);
    FILE *cls_rtn;
    struct stdnt_routine_pln crp;
    cls_rtn = fopen("cls_rtn_plan.txt", "rb+");
    if (cls_rtn == NULL)
    {
        printf("Error opening file");
        exit(1);
    }
    while (fread(&crp, sizeof(crp), 1, cls_rtn) == 1)
    {
        if (strcmp(matchday, crp.day) == 0)
        {
            printf("\n.............Academic Classes............\n");
            printf("........|     Time     |.......|  Subject Name  |....\n");
            printf("\n______________________________________________");
            printf("\n.       %s             ---            %s", crp.sub1_time, crp.sub1_nam);
            printf("\n.       %s             ---            %s", crp.sub2_time, crp.sub2_nam);
            printf("\n.       %s             ---            %s", crp.sub3_time, crp.sub3_nam);
            printf("\n.       %s             ---            %s", crp.sub4_time, crp.sub4_nam);
            printf("\n.       %s             ---            %s", crp.sub5_time, crp.sub5_nam);
            printf("\n.______________________________________________");
        }
    }
    fclose(cls_rtn);
    fflush(stdin);
    FILE *mtn_pln;
    struct stdnt_meeting_pln mtg;
    mtn_pln = fopen("meeting_act_plan.txt", "rb+");
    if (mtn_pln == NULL)
    {
        printf("Error opening file");
        exit(1);
    }
    while (fread(&mtg, sizeof(mtg), 1, mtn_pln) == 1)
    {
        if (strcmp(matchday, mtg.day) == 0)
        {
            printf("\n.............Meetings Today............\n");
            printf("\n***********************************************");
            printf("\n*     Meeting With: %s    ", mtg.mtnwith);
            printf("\n*     Address: %s         ", mtg.address);
            printf("\n*     Time: %s            ", mtg.time);
            printf("\n*     Duration: %s        ", mtg.drtn);
            printf("\n*     Important Notes: %s ", mtg.note);
            printf("\n***********************************************");
        }
    }
    fclose(mtn_pln);
    printf("\n\nPress any key to continue.");
    getch();
    system("cls");
}

void user_plans()
{
    system("cls");
    FILE *week_act;
    struct stdnt_week_act wk;
    char stname[20];

    fflush(stdin);
    week_act = fopen("week_act_plan.txt", "rb+");
    if (week_act == NULL)
    {
        printf("Error opening file");
        exit(1);
    }
    while (fread(&wk, sizeof(wk), 1, week_act) == 1)
    {

        if (strcmp(matchday, wk.day) == 0)
        {
            printf("***************      %s     *************", matchday);
            printf("\n***********************************************");
            printf("\n*           1 : %s               ", wk.input1);
            printf("\n*           2 : %s               ", wk.input2);
            printf("\n*           3 : %s               ", wk.input3);
            printf("\n*           4 : %s               ", wk.input4);
            printf("\n*           5 : %s               ", wk.input5);
            printf("\n***********************************************\n");
            fflush(stdin);
        }
    }
    fclose(week_act);
    fflush(stdin);
    FILE *cls_rtn;
    struct stdnt_routine_pln crp;
    cls_rtn = fopen("cls_rtn_plan.txt", "rb+");
    if (cls_rtn == NULL)
    {
        printf("Error opening file");
        exit(1);
    }
    while (fread(&crp, sizeof(crp), 1, cls_rtn) == 1)
    {
        if (strcmp(matchday, crp.day) == 0)
        {
            printf("\n.............Academic Classes............\n");
            printf("........|     Time     |.......|  Subject Name  |....\n");
            printf("\n______________________________________________");
            printf("\n.       %s             ---            %s", crp.sub1_time, crp.sub1_nam);
            printf("\n.       %s             ---            %s", crp.sub2_time, crp.sub2_nam);
            printf("\n.       %s             ---            %s", crp.sub3_time, crp.sub3_nam);
            printf("\n.       %s             ---            %s", crp.sub4_time, crp.sub4_nam);
            printf("\n.       %s             ---            %s", crp.sub5_time, crp.sub5_nam);
            printf("\n.______________________________________________");
        }
    }
    fclose(cls_rtn);
    fflush(stdin);
    FILE *mtn_pln;
    struct stdnt_meeting_pln mtg;
    mtn_pln = fopen("meeting_act_plan.txt", "rb+");
    if (mtn_pln == NULL)
    {
        printf("Error opening file");
        exit(1);
    }
    while (fread(&mtg, sizeof(mtg), 1, mtn_pln) == 1)
    {
        if (strcmp(matchday, mtg.day) == 0)
        {
            printf("\n.............Meetings Today............\n");
            printf("\n***********************************************");
            printf("\n*     Meeting With: %s    ", mtg.mtnwith);
            printf("\n*     Address: %s         ", mtg.address);
            printf("\n*     Time: %s            ", mtg.time);
            printf("\n*     Duration: %s        ", mtg.drtn);
            printf("\n*     Important Notes: %s ", mtg.note);
            printf("\n***********************************************");
        }
    }
    fclose(mtn_pln);
    printf("\n\nPress any key to continue.");
    getch();
    system("cls");
    add_plans();
}