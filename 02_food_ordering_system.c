#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
struct details{
    char uname[100] ;
    int age;
    char password[12];
    char email[20];
    char mobile[10];
};
struct hotels{
    char hotel[100];
    char first_food[20];
    char second_food[20];
    char third_food[20];
    char fourth_food[20];
    int first , second , third , forth ;
};
struct details d[100];
struct hotels h[5];
int validate();
void signup();
void account_check();
void login();
void hetel_initialize();
void search_by_hotels();
void hotels(int hotel_choice);
void search_by_food();
void food_order(int food);
void cart();
int choice  , temp_age , x , flag=1 , count , caps , small , number , special ,j=0  , search_choice;
int success=0 , i;
int hotel_choice , total , n , food_choice , food , hotel_id , ch , confirm;
char temp_name[100] , temp_email[20] , password1[12] , password2[12] , temp_mob[10];
int main()
{
while(1){
    printf("\n\n******WELCOME To FOOD ORDERING SYSTEM ******\n\n");
    printf(" 1)SIGNUP\n 2)LOGIN \n 3)EXIT\n\n");
    printf("Please enter your choice : ");
    scanf("%d" , &choice);
    switch (choice)
    {
    case 1: {signup();  break; }
    case 2: {login();  break; }
    case 3: {exit(1);     break; }
    default: { printf("\n Please enter the valid choice \n"); break;}
        }
}
getch();
return 0;
}
void signup(){
printf("Enter your name  : ");
scanf("%s" , temp_name);
printf("Enter your age   : ");
scanf("%d" , &temp_age);
printf("Enter your email : ");
scanf("%s" , temp_email);
printf("Enter your mobileNo. :  ");
scanf("%s" , temp_mob);
printf("Enter password  : ");
scanf("%s" , password1);
printf("Confirm password   : ");
scanf("%s" , password2);
 x = validate();
if(x==1){
 account_check();
}
}

int validate()
{
	for (int i = 0; temp_name[i] != '\0'; i++) {
		if (!((temp_name[i] >= 'a' && temp_name[i] <= 'z')
			|| (temp_name[i] >= 'A'
				&& temp_name[i] <= 'Z'))) {
			printf("\nPlease Enter the");
			printf("valid Name\n");
			flag = 0;
			break;
		}
	}
	if (flag == 1) {
		count = 0;
		for (int i = 0;	temp_email[i] != '\0'; i++) {
			if (temp_email[i] == '@'
				|| temp_email[i] == '.')
				count++;
		}
		if (count >= 2
			&& strlen(temp_email) >= 5) {
			if (!strcmp(password1,
						password2)) {
				if (strlen(password1) >= 8
					&& strlen(password1) <= 12) {
					caps = 0;
					small = 0;
					number = 0;
					special = 0;
					for (int i = 0; password1[i] != '\0'; i++) {
						if (password1[i] >= 'A'
							&& password1[i] <= 'Z')
							caps++;
						else if (password1[i] >= 'a'
								&& password1[i]
										<= 'z')
							small++;
						else if (password1[i] >= '0'
								&& password1[i]
										<= '9')
							number++;
						else if (password1[i] == '@'
								|| password1[i] == '&'
								|| password1[i] == '#'
								|| password1[i]
										== '*')
							special++;
					}
					if (caps >= 1 && small >= 1
						&& number >= 1 && special >= 1) {
                         if (temp_age != 0 && temp_age > 0) {
                            if (strlen(temp_mob) == 10) {
								for (int i = 0; i < 10; i++) {
									if (temp_mob[i]
											>= '0'
										&& temp_mob[i]
											<= '9') {
										success = 1;
									}
									else {
										printf("\n\nPlease Enter valid Mobile Number");
                                        return 0;
										break;
									}
								}
								if (success == 1)
                                return 1 ;
							}
							else {
								printf("\n\nPlease Enter the 10 digit mobile number");
                                return 0;
							}
						}
						else {
							printf("\n\nPlease Enter the valid age ");
                            return 0;
						}
					}
					else {
						printf("\n\nPlease Enter the strong password , your password must contain atlease one uppercase ,");
						printf("Lowercase, Number and ");
						printf("special character\n\n");
						return 0;
					}
				}
				else {
					printf("\nYour Password is very short Length must between 8 to 12 \n");
                    return 0;
				}
			}
			else {
				printf("\nPassword Mismatch\n\n");
				return 0;
			}
		}
		else {
			printf("\nPlease Enter Valid E-Mail\n\n");
			return 0;
		}
	}
}


void account_check()
{
	for ( i = 0; i < 100; i++) {
		if (!(strcmp(temp_email , d[i].email) && strcmp(password1 , d[i].password))) {
			printf("\n\nAccount Already Existed. Please Login !! \n\n" );
			main();
			break;
		}
	}
	if (i == 100) {
		strcpy(d[j].uname, temp_name);
		d[j].age = temp_age;
		strcpy(d[j].password, password1);
		strcpy(d[j].email, temp_email);
		strcpy(d[j].mobile, temp_mob);
		j++;
		printf("\n\nAccount Successfully Created !! \nPlease Login\n");
	}
}


void login()
{
	printf("\n\n****LOGIN****\n\n");
	printf("\nEnter Your Email :  ");
	scanf("%s", temp_email);
	printf("Enter Your Password :  ");
	scanf("%s", password1);
	for (int i = 0; i < 100; i++) {
		if (!strcmp(d[i].email, temp_email)) {
			if (!strcmp(d[i].password, password1)) {
				printf("\n\nWelcome %s, ", d[i].uname);
				printf("Your are successfully logged in \n We provide two ways of search\n 1.Search by Hotels\n 2.");
				printf("Search by Food\n 3.Exit \n Please Enter your choice\n");
				scanf("%d", &search_choice);

				switch (search_choice) {
				case 1: {
					search_by_hotels();
					break;
				}
				case 2: {
					search_by_food();
					break;
				}
				case 3: {
					exit(1);
					return;
				}
				default: {
					printf("Please Enter the valid choice\n\n");
					break;
				}
				}
				break;
			}
			else {
				printf("\n\nInvalid Password! ");
				printf("Please Enter the correct password\n\n");
				main();
				break;
			}
		}
		else {
			printf("\n\nAccount doesn't exist, Please signup!!\n\n");
			main();
			break;
		}
	}
}

void hotel_initialize()
{
	strcpy(h[1].hotel, "Aarya_Bhavan");
	strcpy(h[1].first_food, "Sandwich");
	strcpy(h[1].second_food, "Pizza");
	strcpy(h[1].third_food, "Fried_Rice");
	strcpy(h[1].fourth_food , "Gulab Jamun");
	h[1].first = 70;
	h[1].second = 100;
	h[1].third = 95;
	h[1].forth = 220 ;

	strcpy(h[2].hotel, "Pushkar_Hotel");
	strcpy(h[2].first_food, "Parotta");
	strcpy(h[2].second_food, "Noodles");
	strcpy(h[2].third_food, "Chicken_Rice");
	strcpy(h[2].fourth_food, "Paneer Do Pyazaa");
	h[2].first = 15;
	h[2].second = 75;
	h[2].third = 80;
	h[2].forth = 180;

	strcpy(h[3].hotel, "SR_Bhavan");
	strcpy(h[3].first_food, "Chicken_Biriyani");
	strcpy(h[3].second_food, "Prawn");
	strcpy(h[3].third_food, "Faloda");
	strcpy(h[3].fourth_food, "Paneer Butter Masala");
	h[3].first = 90;
	h[3].second = 120;
	h[3].third = 35;
	h[3].forth = 235;
}

void search_by_hotels()
{
	hotel_initialize();
	printf("\n\n**My listed Hotels are**\n 1. %s \n 2. %s \n 3. %s" , h[1].hotel , h[2].hotel , h[3].hotel);
	printf("\n4. Exit\n\nPlease select the hotel : ");
	scanf("%d", &hotel_choice);
	if (hotel_choice > 4) {
		printf("Please Enter the valid choice\n\n");
		search_by_hotels();
	}
	else if (hotel_choice == 4){
		exit(1);
		return;
	}
	else
		hotels(hotel_choice);
}

void hotels(int hotel_choice)
{
	total = 0;
	while (1) {
		printf("\n\n**List of foods available in %s**\n" , h[hotel_choice].hotel);

		printf("\n\n1. %s\tRs: %d\n", h[hotel_choice].first_food, h[hotel_choice].first);
		printf("2. %s\tRs: %d\n", h[hotel_choice].second_food, h[hotel_choice].second);
		printf("3. %s\tRs: %d\n", h[hotel_choice].third_food, h[hotel_choice].third);
		printf("4. %s\tRs: %d\n", h[hotel_choice].fourth_food, h[hotel_choice].forth);
		printf("5. Cart\n6. Exit\n\nPlease Enter Your choice : ");
		scanf("%d", &food_choice);

		if (food_choice == 1) {
			printf("Please Enter the no of plate of %s : \t", h[hotel_choice].first_food);
			scanf("%d", &n);
			total = total + (n * h[hotel_choice].first);
		}
		else if (food_choice == 2) {
			printf("Please Enter the no of plate of %s : \t", h[hotel_choice].second_food);
			scanf("%d", &n);
			total = total + (n * h[hotel_choice].second);
		}
		else if (food_choice == 3) {
			printf("Please Enter the no of plate of %s : \t", h[hotel_choice].third_food);			
			scanf("%d", &n);
			total = total + (n * h[hotel_choice].third);
		}
		else if (food_choice == 4) {
			printf("Please Enter the no of plate of %s : \t", h[hotel_choice].fourth_food);			
			scanf("%d", &n);
			total = total + (n * h[hotel_choice].forth);
		}
		else if (food_choice == 5) {
			cart();
		}
		else if (food_choice == 6) {
			search_by_hotels();
		}
		else {
			printf("Please Enter the valid Choice\n");
		}
	}
	printf("Your item is successfully saved in your cart\nPlease check Cart!!");
}

void search_by_food()
{
	total = 0;
	hotel_initialize();
	while (1) {
		printf("\n\n**Please choose the food** ");
		printf("\n\n1. %s\t%d\n2. %s\t%d", h[1].first_food, h[1].first, h[1].second_food, h[1].second);
		printf("\n3. %s\t%d\n4. %s\t%d\n", h[1].third_food, h[1].third,	h[1].fourth_food, h[1].forth);
		printf("\n5. %s\t%d\n6. %s\t%d", h[2].first_food, h[2].first, h[2].second_food, h[2].second);
		printf("\n7. %s\t%d\n8. %s\t%d\n", h[2].third_food, h[2].third,	h[2].fourth_food, h[2].forth);
		printf("\n9. %s\t%d\n10. %s\t%d", h[3].first_food, h[3].first, h[3].second_food, h[3].second);
		printf("\n11. %s\t%d\n12. %s\t%d\n", h[3].third_food, h[3].third,	h[3].fourth_food, h[3].forth);
		printf("\n13. Cart\n 14. Exit");
		printf("\nPlease Enter Your Choice : ");
		scanf("%d", &food);
		if (food > 13) {
			printf("Please Enter the valid choice \n\n");
			search_by_food();
		}
		else if (food == 13)
			cart();
		else if (food == 14){
			exit(1);
			return;
		}
		else
			food_order(food);
	}
}

void food_order(int food)
{
	if (food >= 1 && food <= 4)
		hotel_id = 1;
	else if (food >= 5 && food <= 8)
		hotel_id = 2;
	else
		hotel_id = 3;
	if ((food % 3) == 1) {
		printf("Please Enter the no of plate of %s\t" , h[hotel_id].first_food);
		scanf("%d", &n);
		total = total + (n * h[hotel_id].first);
	}
	else if ((food % 3) == 2) {
		printf("Please Enter the no of plate of %s\t",h[hotel_id].second_food);
		scanf("%d", &n);
		total = total + (n * h[hotel_id].second);
	}
	else if ((food % 3) == 0) {
		printf("Please Enter the no of plate of %s\t", h[hotel_id].third_food);
		scanf("%d", &n);
		total = total + (n * h[hotel_id].third);
	}
	else if ((food % 3) == 1) {
		printf("Please Enter the no of plate of %s\t", h[hotel_id].fourth_food);
		scanf("%d", &n);
		total = total + (n * h[hotel_id].forth);
	}
}

void cart()
{
	printf("\n\n\n\n--------------Cart----------------");
	printf("\nYour Total Order Amount is %d : " , total);
	printf("\n\nDo You wish to order (yes=1/no=0): ");
	scanf("%d", &ch);
	if (ch == 1) {
		printf("\n\nThank You for your order!! Your food is on the way. Welcome again!!\n\n");
		exit(1);
		return;
	}
	else if (ch == 0) {
		printf("Do You want to exit 1 or Go back 0\n");
		scanf("%d", &confirm);
		if (confirm == 1) {
			printf("\n\nOops! Your order is ");
			printf("cancelled!! Exiting..");
			printf("Thank You visit again!\n");
			exit(1);
			return;
		}
		else {
			printf("\n\nThank You\n\n");
			login();
		}
	}
	else {
		printf("\n\nPlease Enter the correct choice\n\n");
		cart();
	}
}
