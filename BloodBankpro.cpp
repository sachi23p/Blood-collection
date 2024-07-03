#include <stdio.h>
#include <stdlib.h>

struct BloodDonor {
    char name[50];
    int age;
    char bloodGroup[5];
};

int main() {
    FILE *file;
    struct BloodDonor donor;
    char choice;
    int isFileEmpty = 0;

    file = fopen("NewData.csv", "a+"); // Open file in append mode and allow reading
    if (file == NULL) {
        printf("Error in opening file.");
        exit(1);
    }

    // Check if the file is empty to write column headers
    fseek(file, 0, SEEK_END);
    if (ftell(file) == 0) {
        isFileEmpty = 1;
    }

    // Print column headers if file is empty
    if (isFileEmpty) {
        fprintf(file, "Name,Age,Blood Group\n");
    }

    do {
        printf("Enter donor's name: ");
        scanf("%s", donor.name);
        fflush(stdin);
         printf("Enter donor's blood group:");
        scanf("%s",donor.bloodGroup);
        fflush(stdin);
        printf("Enter donor's age: ");
        scanf("%d", &donor.age);
        if(donor.age>=18)
        {
        	printf("********Thank you!! %s********\n",donor.name);
		}
		else{
			printf("*****You are Not Eligable to Donate Blood Grow up!!******\n");
		}
  

        // Write donor information in CSV format
        fprintf(file, "%s,%d,%s\n", donor.name, donor.age, donor.bloodGroup);

        printf("Do you want to enter another donor? (y/n): ");
        scanf(" %c", &choice); // Notice the space before %c to consume the newline character

    } while (choice == 'y' || choice == 'Y');

    fclose(file);

    return 0;
}

