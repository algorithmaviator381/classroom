#include <stdio.h>
#include <stdbool.h>

bool isgoodboy(int age){
    if(age<10){
        return true;
    }else{
        return false;
    }
}

int main(){
    int age;

    for(int i=0; i<10; i++){
        printf("Enter your age: ");
        scanf("%d",&age);

        // if(isgoodboy(age)){
        //     printf("Good boy\n");
        // }

        if(age > 10){
            continue;
        }

        printf("Good Boy!\n");
    }

}