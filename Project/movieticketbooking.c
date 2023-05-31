#include <stdio.h>
#include <strings.h>
//Function to print copncert ticket
void confirmation(char name[],char location[],int nooftickets,float price,float time,int day,int month){
    printf("\n\t\t ________________________________________________________ \n");
    printf("\t\t│ BOOKING CONFIRMED\t\t\t\t\t │\n\t\t│ Hope You Enjoy The Show!\t\t\t\t │\n");
    printf("\t\t│                                                        │\n");
    printf("\t\t  SHOW : %s\n",name);
    printf("\t\t│                                         Date:%d/%d/2023 │\n",day,month);
    printf("\t\t│ TIME : %.2f                                            │\n",time);
    printf("\n\t\t                                  Amount : Rs %.2f/-\n",nooftickets*price);
    printf("\t\t  LOCATION : %s\n",location);
    printf("\t\t│                                                        │\n");
    printf("\t\t│                        THANK YOU                       │\n");
    printf("\t\t│                     HAVE A NICE DAY                    │\n");
    printf("\t\t ________________________________________________________\n\n\n");
}
//Function to print ticket
void ticket(int ROW,int COL,int arrange[ROW][COL],char name[],float price){
    int check=0;
    for(int i=0;i<ROW;i++){
        for(int j=0;j<COL;j++){
            if(arrange[i][j]!=0) check++;
        }
    }
    printf("\n\t\t ________________________________________________________ \n");
    printf("\t\t│ BOOKING CONFIRMED\t\t\t\t\t │\n\t\t│ Hope You Enjoy The Show!\t\t\t\t │\n");
    printf("\t\t│                                                        │\n");
    printf("\t\t  SHOW : %s\n",name);
    printf("\t\t│                                        Date:02/06/2023 │\n");
    printf("\t\t  %d tickets - ",check);
        for(int i=0;i<ROW;i++){
        for(int j=0;j<COL;j++){
            if(arrange[i][j]!=0) printf("%c%d, ",i+65,j+1);
        }
    }
    printf("\n\t\t│                                                        │");
    printf("\n\t\t                                    Amount : Rs %.2f/-\n",check*price);
    printf("\t\t│                        THANK YOU                       │\n");
    printf("\t\t│                     HAVE A NICE DAY                    │\n");
    printf("\t\t ________________________________________________________\n\n\n");
}
// Function to book a seat
void bookSeat(int ROW,int COL,int arrange[ROW][COL],int r,int c){
    if (arrange[r-1][c-1] == 0) {
        arrange[r-1][c-1] = 1; // Mark seat as occupied
        printf("\nSeat booked successfully!\n");
    } else {
        printf("\nSorry, the seat is already occupied.\n");
    }
}
// Function to display the seating arrangement
void displaySeats(int ROW,int COL,int arrange[ROW][COL]){
    for (int i=0;i<ROW;i++){
        if(i==0){
            printf("    ");
            for(int k=0;k<COL;k++){
                if(k<9) printf(" %d  ",k+1);
                else printf(" %d ",k+1);
            }printf("\n");
        }
        for (int j=0;j<COL;j++){
            if(j==0) printf("%c   ",i+65);
            if(arrange[i][j]==0){
                printf("[ ] "); // Available seat
            } else{
                printf("[X] "); // Occupied seat
            }
        }
        printf("\n");
    }
}
//Function to select seat
void seatSelection(int ROW,int COL,int arrange[ROW][COL],float price){
    int r,c;char choice;
    do{
        printf("Recliner : %.2f\n",price);
        displaySeats(ROW,COL,arrange);
        printf("\nEnter the row of first seat you to select : ");
        scanf("%d",&r);
        printf("Enter the column of first seat you to select : ");
        scanf("%d",&c);

        bookSeat(ROW,COL,arrange,r,c);

        printf("\nDo you want to book another seat?\nPress Y for Yes/N for No) : ");
        scanf(" %c", &choice);
        printf("\n");
    }while(choice=='y' || choice=='Y');

    printf("Seats you booked : \n");
    displaySeats(ROW,COL,arrange);
}
// Function to initialize the seating arrangement
void initializeSeats(int ROW,int COL,int arrange[ROW][COL],float price){
    for (int i=0;i<ROW;i++){
        for (int j=0;j<COL;j++){
            arrange[i][j]=0; // 0 represents an available seat
        }
    }
    seatSelection(ROW,COL,arrange,price);
}

int main ()
{
    printf("\n\n\t\t|====================================================|\n");
    printf("\t\t|         SIMPLE MOVIE TICKET BOOKING SYSTEM         |\n");
    printf("\t\t|====================================================|\n\n\n");

    printf("1.HYDREABAD\n2.CHENNAI\n3.BHUBANESHWAR\n\n");
    int city,movie,theatre,time;float price;
    char name[100];
    printf("Choose a city from above : ");
    scanf("%d",&city);

    switch(city){
        //HYDERABAD
        case 1:
        printf("\n1.Fast X\n2.The Kerala Story\n3.Guardians of the Galaxy Vol.3\n");
        printf("\nSelect Movie : ");
        scanf("%d",&movie);
        switch(movie){
            //FAST X
            case 1:
            printf("\n1.INOX: GVK One, Banjara Hills\n2.Prasads Multiplex\n3.PVR: Nexux Mall\n");
            printf("\nSelect Threatre : ");
            scanf("%d",&theatre);
            strcpy(name,"FAST X");
            switch(theatre){
                case 1:
                printf("\n1. 05:30 PM\n");
                printf("Select Timing : ");
                scanf("%d",&time);
                switch(time){
                    case 1:
                    price=385;
                    int ROW=9,COL=15,arrange[ROW][COL];
                    initializeSeats(ROW,COL,arrange,price);
                    ticket(ROW,COL,arrange,name,price);
                    break;
                }
                break;
                case 2:
                printf("\n1. 08:30 PM - PCX DOLBY ATMOS\n");
                printf("Select Timing : ");
                scanf("%d",&time);
                switch(time){
                    case 1:
                    price=400;
                    int ROW=10,COL=18,arrange[ROW][COL];
                    initializeSeats(ROW,COL,arrange,price);
                    ticket(ROW,COL,arrange,name,price);
                    break;
                }
                break;
                case 3:
                printf("\n1. 07:30 PM - 4K DOLBY 7.1 Real D\n");
                printf("Select Timing : ");
                scanf("%d",&time);
                switch(time){
                    case 1:
                    price=385;
                    int ROW=8,COL=12,arrange[ROW][COL];
                    initializeSeats(ROW,COL,arrange,price);
                    ticket(ROW,COL,arrange,name,price);
                    break;
                }
                break;
                

                default:
                printf("Invalid Input\n");
                
            }
            break;
            //THE KERALA STORY
            case 2:
            printf("\n1.Cinepolis: Mantra Mall, Attapur\n2.Prasads Multiplex\n3.INOX: Maheswari\n");
            printf("\nSelect Threatre : ");
            scanf("%d",&theatre);
            strcpy(name,"The Kerala Story");
            switch(theatre){
                case 1:
                printf("\n1. 10:40 PM - DOLBY 7.1\n");
                printf("Select Timing : ");
                scanf("%d",&time);
                switch(time){
                    case 1:
                    price=200;
                    int ROW=12,COL=7,arrange[ROW][COL];
                    initializeSeats(ROW,COL,arrange,price);
                    ticket(ROW,COL,arrange,name,price);
                    break;

                }
                break;
                case 2:
                printf("\n1. 11:00 PM\n");
                printf("Select Timing : ");
                scanf("%d",&time);
                switch(time){
                    case 1:
                    price=250;
                    int ROW=10,COL=18,arrange[ROW][COL];
                    initializeSeats(ROW,COL,arrange,price);
                    ticket(ROW,COL,arrange,name,price);
                    break;
                }
                break;
                case 3:
                printf("\n1. 10:35 AM\n");
                printf("Select Timing : ");
                scanf("%d",&time);
                switch(time){
                    case 1:
                    price=200;
                    int ROW=10,COL=16,arrange[ROW][COL];
                    initializeSeats(ROW,COL,arrange,price);
                    ticket(ROW,COL,arrange,name,price);
                    break;
                }
                break;
                

                default:
                printf("Invalid Input\n");
                
            }
            break;
            //GUARDIANS OF THE GALAXY VOL.3
            case 3:
            printf("\n1.AMB Cinemas: Gachibowli\n2.PVR: INorbit, Cyderbabad\n3.PVR: Central Mall, Panjagutta\n");
            printf("\nSelect Threatre : ");
            scanf("%d",&theatre);
            strcpy(name,"Guardians Of The Galaxy Vol.3");
            switch(theatre){
                case 1:
                printf("\n1. 04:30 PM\n");
                printf("Select Timing : ");
                scanf("%d",&time);
                switch(time){
                    case 1:
                    price=325;
                    int ROW=15,COL=20,arrange[ROW][COL];
                    initializeSeats(ROW,COL,arrange,price);
                    ticket(ROW,COL,arrange,name,price);
                    break;

                }
                break;
                case 2:
                printf("\n1. 04:45 PM - DOLBY 7.1\n");
                printf("Select Timing : ");
                scanf("%d",&time);
                switch(time){
                    case 1:
                    price=235;
                    int ROW=9,COL=15,arrange[ROW][COL];
                    initializeSeats(ROW,COL,arrange,price);
                    ticket(ROW,COL,arrange,name,price);
                    break;
                }
                break;
                case 3:
                printf("\n1. 10:20 AM - DOLBY 7.1\n");
                printf("Select Timing : ");
                scanf("%d",&time);
                switch(time){
                    case 1:
                    price=235;
                    int ROW=11,COL=17,arrange[ROW][COL];
                    initializeSeats(ROW,COL,arrange,price);
                    ticket(ROW,COL,arrange,name,price);
                    break;
                }
                break;
                

                default:
                printf("Invalid Input\n");
                
            }
            break;
            

            default:
            printf("Invalid Input\n");
        }
        break;
        //CHENNAI
        case 2:
        printf("\n1.Ponniyin Selvan - Part 2\n2.Kazhuvethhi Moorkan\n3.Fast X\n");
        printf("\nSelect Movie : ");
        scanf("%d",&movie);
        switch(movie){
            //PONNIYIN SELVAN
            case 1:
            printf("\n1.AGS Cinemas: T. Nagar\n2.Rohini Silver Screens: Koyambedu\n3.PVR: Aerohub, Chennai\n");
            printf("\nSelect Threatre : ");
            scanf("%d",&theatre);
            strcpy(name,"Ponniyin Selvan");
            switch(theatre){
                case 1:
                printf("\n1. 10:50 PM - 4K DOLBY 7.1n");
                printf("Select Timing : ");
                scanf("%d",&time);
                switch(time){
                    case 1:
                    price=190;
                    int ROW=8,COL=12,arrange[ROW][COL];
                    initializeSeats(ROW,COL,arrange,price);
                    ticket(ROW,COL,arrange,name,price);
                    break;

                }
                break;
                case 2:
                printf("\n1. 08:30 PM - PCX DOLBY ATMOS\n");
                printf("Select Timing : ");
                scanf("%d",&time);
                switch(time){
                    case 1:
                    price=140;
                    int ROW=9,COL=15,arrange[ROW][COL];
                    initializeSeats(ROW,COL,arrange,price);
                    ticket(ROW,COL,arrange,name,price);
                    break;
                }
                break;
                case 3:
                printf("\n1. 10:50 PM\n");
                printf("Select Timing : ");
                scanf("%d",&time);
                switch(time){
                    case 1:
                    price=149;
                    int ROW=6,COL=10,arrange[ROW][COL];
                    initializeSeats(ROW,COL,arrange,price);
                    ticket(ROW,COL,arrange,name,price);
                    break;
                }
                break;
                

                default:
                printf("Invalid Input\n");
                
            }
            break;
            //KAZHUVETHI MOORKAN
            case 2:
            printf("\n1.PVR: Aerohub, Chennai\n2.INOX: LUXE Phoenix Market City\n3.Rohini Silver Screens: Koyambedu\n");
            printf("\nSelect Threatre : ");
            scanf("%d",&theatre);
            strcpy(name,"Kazhuvethi Moorkan");
            switch(theatre){
                case 1:
                printf("\n1. 10:45 PM\n");
                printf("Select Timing : ");
                scanf("%d",&time);
                switch(time){
                    case 1:
                    price=190;
                    int ROW=6,COL=10,arrange[ROW][COL];
                    initializeSeats(ROW,COL,arrange,price);
                    ticket(ROW,COL,arrange,name,price);
                    break;

                }
                break;
                case 2:
                printf("\n1. 10:40 PM\n");
                printf("Select Timing : ");
                scanf("%d",&time);
                switch(time){
                    case 1:
                    price=190.78;
                    int ROW=7,COL=10,arrange[ROW][COL];
                    initializeSeats(ROW,COL,arrange,price);
                    ticket(ROW,COL,arrange,name,price);
                    break;
                }
                break;
                case 3:
                printf("\n1. 11:35 PM\n");
                printf("Select Timing : ");
                scanf("%d",&time);
                switch(time){
                    case 1:
                    price=140;
                    int ROW=9,COL=15,arrange[ROW][COL];
                    initializeSeats(ROW,COL,arrange,price);
                    ticket(ROW,COL,arrange,name,price);
                    break;
                }
                break;
                

                default:
                printf("Invalid Input\n");
                
            }
            break;
            //FAST X
            case 3:
            printf("\n1.PVR: Grand: Galada, Pallavaram\n2.Cinepolis: BSR Mall, OMR\n3.PVR: Grand Mall, Velachery\n");
            printf("\nSelect Threatre : ");
            scanf("%d",&theatre);
            strcpy(name,"FAST X");
            switch(theatre){
                case 1:
                printf("\n1. 07:00 PM - ATMOS enabled\n");
                printf("Select Timing : ");
                scanf("%d",&time);
                switch(time){
                    case 1:
                    price=246.46;
                    int ROW=15,COL=20,arrange[ROW][COL];
                    initializeSeats(ROW,COL,arrange,price);
                    ticket(ROW,COL,arrange,name,price);
                    break;

                }
                break;
                case 2:
                printf("\n1. 03:30 PM\n");
                printf("Select Timing : ");
                scanf("%d",&time);
                switch(time){
                    case 1:                   
                    price=240.96;
                    int ROW=10,COL=16,arrange[ROW][COL];
                    initializeSeats(ROW,COL,arrange,price);
                    ticket(ROW,COL,arrange,name,price);
                    break;
                }
                break;
                case 3:
                printf("\n1. 10:00 PM  - DOLBY ATMOS\n");
                printf("Select Timing : ");
                scanf("%d",&time);
                switch(time){
                    case 1:
                    price=246.46;
                    int ROW=8,COL=10,arrange[ROW][COL];
                    initializeSeats(ROW,COL,arrange,price);
                    ticket(ROW,COL,arrange,name,price);
                    break;
                }
                break;
                

                default:
                printf("Invalid Input\n");
                
            }
            break;
            

            default:
            printf("Invalid Input\n");
        }
        break;
        //BHUBANESHWAR
        case 3:
        printf("\n1.IB71\n2.Aazam\n3.The Kerala Story\n");
        printf("\nSelect Movie : ");
        scanf("%d",&movie);
        switch(movie){
            //IB71
            case 1:
            printf("\n1.INOX: DN Regalia Mall\n2.Stutee Cineplexx\n3.INOX: BMC Bhawani Mall\n");
            printf("\nSelect Threatre : ");
            scanf("%d",&theatre);
            strcpy(name,"IB71");
            switch(theatre){
                case 1:
                printf("\n1. 06:55 PM\n");
                printf("Select Timing : ");
                scanf("%d",&time);
                switch(time){
                    case 1:
                    price=180;
                    int ROW=9,COL=15,arrange[ROW][COL];
                    initializeSeats(ROW,COL,arrange,price);
                    ticket(ROW,COL,arrange,name,price);
                    break;

                }
                break;
                case 2:
                printf("\n1. 07:30 PM - 4K DOLBY ATMOS\n");
                printf("Select Timing : ");
                scanf("%d",&time);
                switch(time){
                    case 1:
                    price=149;
                    int ROW=15,COL=20,arrange[ROW][COL];
                    initializeSeats(ROW,COL,arrange,price);
                    ticket(ROW,COL,arrange,name,price);
                    break;
                }
                break;
                case 3:
                printf("\n1. 07:30 PM - 4K DOLBY 7.1 Real D\n");
                printf("Select Timing : ");
                scanf("%d",&time);
                switch(time){
                    case 1:
                    price=160;
                    int ROW=14,COL=21,arrange[ROW][COL];
                    initializeSeats(ROW,COL,arrange,price);
                    ticket(ROW,COL,arrange,name,price);
                    break;
                }
                break;
                

                default:
                printf("Invalid Input\n");
                
            }
            break;
            //AAZAM
            case 2:
            printf("\n1.Stutee Cineplexx\n2.INOX: Nexus Esplande\n3.INOX: DN Regalia Mall\n");
            printf("\nSelect Threatre : ");
            scanf("%d",&theatre);
            strcpy(name,"Aazam");
            switch(theatre){
                case 1:
                printf("\n1. 07:45 PM - RGB/DOLBY ATMOS\n");
                printf("Select Timing : ");
                scanf("%d",&time);
                switch(time){
                    case 1:
                    price=120;
                    int ROW=15,COL=20,arrange[ROW][COL];
                    initializeSeats(ROW,COL,arrange,price);
                    ticket(ROW,COL,arrange,name,price);
                    break;

                }
                break;
                case 2:
                printf("\n1. 12:15 PM - DOLBY 5.1\n");
                printf("Select Timing : ");
                scanf("%d",&time);
                switch(time){
                    case 1:
                    price=150;
                    int ROW=9,COL=15,arrange[ROW][COL];
                    initializeSeats(ROW,COL,arrange,price);
                    ticket(ROW,COL,arrange,name,price);
                    break;
                }
                break;
                case 3:
                printf("\n1. 09:45 PM\n");
                printf("Select Timing : ");
                scanf("%d",&time);
                switch(time){
                    case 1:
                    price=160;
                    int ROW=8,COL=10,arrange[ROW][COL];
                    initializeSeats(ROW,COL,arrange,price);
                    ticket(ROW,COL,arrange,name,price);
                    break;
                }
                break;
                

                default:
                printf("Invalid Input\n");
                
            }
            break;
            //THE KERALA STORY
            case 3:
            printf("\n1.INOX: Nexus Esplande\n2.Maharaja\n3.Keshari Theatre\n");
            printf("\nSelect Threatre : ");
            scanf("%d",&theatre);
            strcpy(name,"The Kerala Story");
            switch(theatre){
                case 1:
                printf("\n1. 05:30 PM\n");
                printf("Select Timing : ");
                scanf("%d",&time);
                switch(time){
                    case 1:
                    price=180;
                    int ROW=8,COL=10,arrange[ROW][COL];
                    initializeSeats(ROW,COL,arrange,price);
                    ticket(ROW,COL,arrange,name,price);
                    break;

                }
                break;
                case 2:
                printf("\n1. 07:30 PM\n");
                printf("Select Timing : ");
                scanf("%d",&time);
                switch(time){
                    case 1:
                    price=160;
                    int ROW=10,COL=18,arrange[ROW][COL];
                    initializeSeats(ROW,COL,arrange,price);
                    ticket(ROW,COL,arrange,name,price);
                    break;

                }
                break;
                case 3:
                printf("\n1. 1:45 PM\n");
                printf("Select Timing : ");
                scanf("%d",&time);
                switch(time){
                    case 1:
                    price=130;
                    int ROW=12,COL=17,arrange[ROW][COL];
                    initializeSeats(ROW,COL,arrange,price);
                    ticket(ROW,COL,arrange,name,price);
                    break;

                }
                break;
                
                default:
                printf("Invalid Input\n");
                
            }
            break;
            

            default:
            printf("Invalid Input\n");
        }
        break;

        default:
        printf("Invalid Input\n");
    }
    char opt[5],title[100],location[100];int selction,block,tic,day,month;float cost,time2;
    printf("   \"EXPLORE MORE EVENTS\"\n");
    printf("To see press Y/N for return : ");
    scanf("%s",opt);

    if(opt[0]=='y' || opt[0]=='Y'){
        printf("\nEnjoy the Concerts in the city you selected : ");
        if(city==1){
            printf("\t\n\n1.Anirudh\t\t\t2.Sid Sriram\n  04/06/23\t\t\t  07/06/23\n  6.00PM\t\t\t  7.30PM\n  GMR Arena Ground\t\t  Pheonix Arena\n");
            printf("\nEnter choice : ");
            scanf("%d",&selction);
            if(selction==1){
                printf("\n1.Platinum - Rs.5000/-\n2.Gold - Rs.3000/-\n3.Silver - Rs.1000/-\n");
                printf("\nEnter the area you want to book : ");
                scanf("%d",&block);
                printf("Enter the number of tickets you want to book : ");
                scanf("%d",&tic);
                time2=06;day=04;month=06;
                if(block==1) cost=5000;
                if(block==2) cost=3000;
                if(block==3) cost=1000;
                strcpy(title,"ANIRUDH");strcpy(location,"GMR Arena Ground");
                confirmation(title,location,tic,cost,time2,day,month);
            }
            if(selction==2){
                printf("\n1.Platinum - Rs.3000/-\n2.Gold - Rs.1000/-\n3.Silver - Rs.500/-\n");
                printf("\nEnter the area you want to book : ");
                scanf("%d",&block);
                printf("Enter the number of tickets you want to book : ");
                scanf("%d",&tic);
                time2=07.3;day=07;month=06;
                if(block==1) cost=3000;
                if(block==2) cost=1000;
                if(block==3) cost=500;
                strcpy(title,"SID SRIRAM");strcpy(location,"Pheonix Arena");
                confirmation(title,location,tic,cost,time2,day,month);
            }
        }
        if(city==2){
            printf("\t\n\n1.Badshah\t\t2.Martin Garrix\n  04/06/23\t\t  11/06/23\n  06:45PM\t\t  07:45PM\n  Vani Mahal\t\t  Sunburn Arena\n");            
            printf("\nEnter choice : ");
            scanf("%d",&selction);
            if(selction==1){
                printf("\n1.Platinum - Rs.3500/-\n2.Gold - Rs.2000/-\n3.Silver - Rs.1000/-\n");
                printf("\nEnter the area you want to book : ");
                scanf("%d",&block);
                printf("Enter the number of tickets you want to book : ");
                scanf("%d",&tic);
                time2=06.45;day=04;month=06;
                if(block==1) cost=3500;
                if(block==2) cost=2000;
                if(block==3) cost=1000;
                strcpy(title,"BADSHAH");strcpy(location,"Vani Mahal");
                confirmation(title,location,tic,cost,time2,day,month);
            }
            if(selction==2){
                printf("\n1.Platinum - Rs.10000/-\n2.Gold - Rs.5000/-\n3.Silver - Rs.1000/-\n");
                printf("\nEnter the area you want to book : ");
                scanf("%d",&block);
                printf("Enter the number of tickets you want to book : ");
                scanf("%d",&tic);
                time2=07.45;day=11;month=06;
                if(block==1) cost=10000;
                if(block==2) cost=5000;
                if(block==3) cost=1000;
                strcpy(title,"MARTIN GARRIX");strcpy(location,"Sunburn Arena");
                confirmation(title,location,tic,cost,time2,day,month);
            }
        }
        if(city==3){
            printf("\t\n\n1.Dhvani Bhanushali\t\t2.Javed Ali\n  05/06/23\t\t\t  10/06/23\n  8:30PM\t\t\t  09:45PM\n  Hockey stadium\t\t  Utkal Mandap\n");            
            printf("\nEnter choice : ");
            scanf("%d",&selction);
            if(selction==1){
                printf("\n1.Platinum - Rs.2000/-\n2.Gold - Rs.700/-\n3.Silver - Rs.500/-\n");
                printf("\nEnter the area you want to book : ");
                scanf("%d",&block);
                printf("Enter the number of tickets you want to book : ");
                scanf("%d",&tic);
                time2=08.30;day=05;month=06;
                if(block==1) cost=2000;
                if(block==2) cost=7000;
                if(block==3) cost=500;
                strcpy(title,"DHVANI BHANUSHALI");strcpy(location,"Hockey Stadium");
                confirmation(title,location,tic,cost,time2,day,month);
            }
            if(selction==2){
                printf("\n1.Platinum - Rs.1000/-\n2.Gold - Rs.700/-\n3.Silver - Rs.250/-\n");
                printf("\nEnter the area you want to book : ");
                scanf("%d",&block);
                printf("Enter the number of tickets you want to book : ");
                scanf("%d",&tic);
                time2=09.45;day=10;month=06;
                if(block==1) cost=1000;
                if(block==2) cost=700;
                if(block==3) cost=250;
                strcpy(title,"JAVED ALI");strcpy(location,"Utkal Mandap");
                confirmation(title,location,tic,cost,time2,day,month);
            }
        }
    }

    return 0;
}