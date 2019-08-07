//  Automobile Database
//  Created by Milan Patel on 4/24/18.
//  Copyright © 2018 Milan Patel. All rights reserved.

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define STR_MAX 20

typedef struct                                  //Structure for Date
{
    int month, day, year;
} date_t;
typedef struct                                  //Structure for Tank
{
    double capacity, current;
} tank_t;
typedef struct                                  //Structure for Automobile
{
    char make[STR_MAX], model[STR_MAX];
    int odometer;
    date_t manufacture, purchase;
    tank_t tank;
} auto_t;

int scan_date(date_t *date);
int scan_tank(tank_t *tank);
int scan_auto(auto_t *aauto);
void print_date(date_t date);
void print_tank(tank_t tank);
void print_auto(auto_t aauto);

int
main(void)
{
 
    auto_t veh;
    int i=0;
    printf("\nMake\tModel\tOdometer\tDate of\t\tDate of\t   Tank\tCurrent");
    printf("\n\t\t\t\tReading    Manufacture  Purchase Capcity fuel\n");
    
    FILE *infp;                                     //Driver Function
    int status = 1;
    infp = fopen("auto.txt","r");                   //Open File
    if(infp == NULL)
        printf("\nauto.txt File does not exist.  Please Check.");
    else{
        while(status>0){                            //Input Data and Print auto_t Structure
            status = fscanf(infp, "%s %s %d %d %d %d %d %d %d %lf %lf", veh.make, veh.model, &veh.odometer, &veh.manufacture.month, &veh.manufacture.day, &veh.manufacture.year, &veh.purchase.month, &veh.purchase.day, &veh.purchase.year, &veh.tank.capacity, &veh.tank.current);
            if(status==11){
                printf("\n%s\t%s\t%d\t %d-%d-%d\t %d-%d-%d\t %2.1lf\t%2.1lf", veh.make, veh.model, veh.odometer, veh.manufacture.month, veh.manufacture.day, veh.manufacture.year, veh.purchase.month, veh.purchase.day, veh.purchase.year, veh.tank.capacity, veh.tank.current);
                i++;
            }else if(status<11 && status>0){
                printf("\n Invalid input, number of items is less than 11. \n");
            }
        }
    }
    void rewind(FILE *infp);
    
    int scan_date(date_t *date);
    int scan_tank(tank_t *tank);
    int scan_auto(auto_t *aauto);
    void print_date(date_t date);
    void print_tank(tank_t tank);
    void print_auto(auto_t aauto);
    
    fclose(infp);                                   //Close File
    printf("\n");
    

    
    return (0);
}

int scan_date(date_t *date){                        //Enter date function
    int result;
    result = scanf("%d %d %d", &(*date).month, &(*date).day, &(*date).year);
    if(result ==3){
        result=1;}
    else if(result!=EOF){
        result=0;}
    return(result);
}

int scan_tank(tank_t *tank){                        //Enter tank function
    int result;
    result = scanf("%lf %lf", &(*tank).capacity, &(*tank).current);
    if(result ==2){
        result=1;}
    else if(result!=EOF){
        result=0;}
    return(result);
}

int scan_auto(auto_t *aauto){                       //Enter automobile function
    int result;
    result = scanf("%s %s %d %d %d %d %d %d %d %lf %lf", (*aauto).make, (*aauto).model, &(*aauto).odometer, &(*aauto).manufacture.month, &(*aauto).manufacture.day, &(*aauto).manufacture.year, &(*aauto).purchase.month, &(*aauto).purchase.day, &(*aauto).purchase.year, &(*aauto).tank.capacity, &(*aauto).tank.current);
    if(result==11){
        result=1;
    }
    else if(result != EOF){
        result=0;
    }
    
    return(result);
}

//Print Functions for corresponding Scan functions

void print_date(date_t date){
    printf("%d-%d-%d", date.month, date.day, date.year);
}

void print_tank(tank_t tank){
    printf("%2.1f %2.1f", tank.capacity, tank.current);
}

void print_auto(auto_t aauto){
    printf("\n%s\t%s\t%d\t%d-%d-%d\t%d-%d-%d\t%2.1f\t%2.1f", aauto.make, aauto.model, aauto.odometer, aauto.manufacture.month, aauto.manufacture.day, aauto.manufacture.year, aauto.purchase.month, aauto.purchase.day, aauto.purchase.year, aauto.tank.capacity, aauto.tank.current);
}
