#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct address {
    char *name;
    size_t length;
};

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <address>\n", argv[0]);
        return 1;
    }

    char *address = argv[1];
    size_t address_length = strlen(address);

    // Convert the input address to lowercase
    strlwr(address);

    struct address addresses[] = {
        {"Praha", 6},
        {"Brno", 5},
        {"Bruntal", 7},
        {"Bratislava", 10},
    };

    size_t addresses_count = sizeof(addresses) / sizeof(addresses[0]);

    char allowed_chars[100] = "";
    size_t allowed_chars_count = 0;

    for (size_t i = 0; i < addresses_count; i++) {
        char lowercase_name[100];
        strcpy(lowercase_name, addresses[i].name);
        strlwr(lowercase_name);

        if (strncmp(lowercase_name, address, address_length) == 0) {
            for (size_t j = 0; j < addresses[i].length; j++) {
                if (allowed_chars_count < sizeof(allowed_chars) - 1) {
                    allowed_chars[allowed_chars_count++] = toupper(addresses[i].name[j]);
                }
            }
        }
    }

    if (allowed_chars_count == 1) {
        printf("Found: %c\n", allowed_chars[0]);
    } else if (allowed_chars_count > 0) {
        printf("Enable: %s\n", allowed_chars);
    } else {
        printf("Not found\n");
    }

    return 0;
}
