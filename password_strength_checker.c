#include<stdio.h>
#include<string.h>
#include<ctype.h>

void print_guidelines();
int password_length_checker(const char *password);         //compiler need to know about the function when we call it in main.
void get_password(char *password);
int password_strength_checker(const char *password,int length);       // if not, causes compilation error.

int main(){
    char password[100];
    int is_strong = 0;
    
    print_guidelines();             //calls the print_guidelines function.

    while(!is_strong){
        get_password(password);      //calls the function to get password
        int length = password_length_checker(password);        //call the function to check the length
        is_strong=password_strength_checker(password,length);   //checks the strength of a password

        if(!is_strong){
            printf("\nPassword is weak! Please try again by following the Guidelines.\n");
        }
        else{
            printf("\nStrong Password!\n");
        }
    }
    return 0;

}


void print_guidelines(){
    
    printf("\nPassword Guidelines:\n");
    printf("1. Must contain at least 8 characters long.\n");
    printf("2. Should contain at least one upper and lower case letter.\n");
    printf("3. Should contain at least one digit.\n");
    printf("4. Should contain at lest one special charecter.\n");
}
void get_password(char *password){
    printf("\nEnter your password:");           // for security purpose "space" is also included in the input password.
    fgets(password,100, stdin);                         // also we can use scanf("%99s", &password) or sizeof(password)  or fgets(password, 100, stdin);      
    password[strcspn(password, "\n")]=0;          //removes the newline/ nul terminator
}


int password_length_checker(const char *password){
    int length = strlen(password);
    printf("length :%d",length);
    return length;
    }

int password_strength_checker(const char *password,int  length ){
    int is_upper=0, is_lower=0, is_digit=0, is_special=0;

    for (int i=0; password[i]; i++){
        if(isupper(password[i])){
            is_upper = 1;
        }
        else if (islower(password[i])){
            is_lower = 1;
        }
        else if(isdigit(password[i])){
            is_digit = 1;
        }
        else if(ispunct(password[i])){
            is_special = 1;
        }
    }
    if (length >= 8 && is_upper && is_lower && is_digit && is_special){
        return 1;   //Strong Password
    }
    else{
        return 0;   //Weak Password
    }
}