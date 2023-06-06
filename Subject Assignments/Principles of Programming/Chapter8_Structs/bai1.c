#include <stdio.h>
#include <string.h>

typedef struct {
    int phone;
    char name[100];
    char address[100];
} Contacts;

void printPhonebook(Contacts *contacts, int size);
void filterByAddress(char *address, Contacts *contacts, int *size);
void filterByPhone(int phone, Contacts *contacts, int *size);

int nextIndex = 0;
Contacts phonebook[100];

int main() {
    printf("Enter the number of contacts in the phonebook: ");
    int n;
    scanf("%d", &n);
    
    while(n--) {
        Contacts contact;
        printf(">> Contact %d", (nextIndex + 1));
        fflush(stdin);
        printf("\n\t- Name: ");
        gets(contact.name);
        fflush(stdin);
        printf("\t- Address: ");
        gets(contact.address);
        fflush(stdin);
        printf("\t- Phone: ");
        scanf("%d", &contact.phone);

        phonebook[nextIndex] = contact;
        nextIndex++;
    }

    printPhonebook(phonebook, nextIndex);

    fflush(stdin);
    printf("Enter the address to filter: ");
    char toFilter[100];
    gets(toFilter);
    Contacts addressFilterResult[1000];
    int addressFilterSize = 0;
    if(addressFilterSize == 0) {
        printf("Khong tim thay dia chi nay trong danh ba\n");
    } else {
        filterByAddress(toFilter, addressFilterResult, &addressFilterSize);
        printPhonebook(addressFilterResult, addressFilterSize);
    }

    printf("Enter the phone to filter: ");
    int filter;
    scanf("%d", &filter);
    Contacts phoneFilterResult[1000];
    int phoneFilterSize = 0;
    if(phoneFilterSize == 0) {
        printf("Khong tim thay so dien thoai nay trong danh ba\n");
    } else {
        filterByPhone(filter, phoneFilterResult, &phoneFilterSize);
        printPhonebook(phoneFilterResult, phoneFilterSize);
    }
}

void printPhonebook(Contacts *contacts, int size) {
    printf("|-------------------------|--------------------|--------------------|\n");
    printf("| Name                    | Address            | Phone              |\n");
    printf("|-------------------------|--------------------|--------------------|\n");

    for (int i = 0; i < size; i++) {
        Contacts contact = contacts[i];
        printf("| %-24s| %-19s| 0%-18d|\n", contact.name, contact.address, contact.phone);
    }
    printf("|-------------------------|--------------------|--------------------|\n");
}

void filterByAddress(char *address, Contacts *result, int *size) {
    int index = 0;
    for (int i = 0; i < nextIndex; i++) {
        Contacts contact = phonebook[i];
        if(strcmp(address, contact.address) == 0)
        {
            result[index] = contact;
            index++;
        }
    }
    *size = index;
}

void filterByPhone(int phone, Contacts *result, int *size) {
    int index = 0;
    for (int i = 0; i < nextIndex; i++) {
        Contacts contact = phonebook[i];
        if(contact.phone == phone)
        {
            result[index] = contact;
            index++;
        }
    }
    *size = index;
}