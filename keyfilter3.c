#include <stdio.h>
#include <string.h>
#include <ctype.h>

void swap(char* a, char* b){
    char temp = *a;
    *a = *b;
    *b = temp;
}

int partition(char* str, int low, int high){
    char pivot = str[high]; 
    int i = low - 1; 

    for (int j = low; j <= high - 1; j++) {
        if (str[j] <= pivot) {
            i++;
            swap(&str[i], &str[j]); 
        }
    }
    swap(&str[i + 1], &str[high]); 
    return i + 1; 
}

void quickSort(char* str, int low, int high){
    if (low < high) {
        int pivotIndex = partition(str, low, high); 
        quickSort(str, low, pivotIndex - 1); 
        quickSort(str, pivotIndex + 1, high); 
    }
}

int startWith(char arr[], char substring[]){
    for (unsigned int i = 0; i < strlen(arr); i++)
    {
        if (arr[i] == '\n')
        {
            arr[i]= 0;
        }
        continue;
    }
    int subStrLen = strlen(substring) ;
    int mainStrLen = strlen(arr);

    if( mainStrLen >= subStrLen && (strncmp(arr, substring, subStrLen) == 0)) {
    	return 1;
    }
    return 0;
}

int main(int argc, char *argv[]) {   
    
    for (int i = 0; argv[1][i] != '\0'; i++) {
        argv[1][i] = tolower(argv[1][i]);
    }
    
    char *pPosition;
    char lowercase_name[100];
    char allowed_chars[100] = "";
    size_t allowed_chars_count = 0;
    size_t find_address_count = 0;
    char find_address[100] = "";

    if (argc < 1)
    {
        return 1;
    }

    int i = 10;
    do  {
    	char line[100];
    	if (fgets( line, 100, stdin ) == NULL) {
    		i = 100;
    	} else {
    		i = 1;

    		strcpy(lowercase_name,line);
    	    for (int i = 0; lowercase_name[i] != '\0'; i++) {
        			lowercase_name[i] = tolower(lowercase_name[i]);
    			}
    		if (argv[1][0] == 0)  {
    			find_address_count++;
    			if (find_address_count == 1) {
        			strcpy(find_address,lowercase_name);
    			}
                    pPosition = strchr(allowed_chars, lowercase_name[0]);

				if (strchr(allowed_chars, lowercase_name[0]) == 0)  {
					allowed_chars[allowed_chars_count++] = lowercase_name[0];
				}
    		} else {
    			if(startWith(lowercase_name, argv[1]) == 1) {
    				find_address_count++;
        			if (find_address_count == 1) {
            			strcpy(find_address,lowercase_name);
        			}

    			    pPosition  = strchr(allowed_chars, lowercase_name[strlen(argv[1])]);

    				if (pPosition == 0)  {
    					allowed_chars[allowed_chars_count++] = lowercase_name[strlen(argv[1])];
    				}
                                   
    			}
    		}
    	}
    } while (i < 2);
    if (find_address_count == 1) 
    {
        for (int i = 0; find_address[i] != '\0'; i++) {
            find_address[i] = toupper(find_address[i]);
        }
        printf("Found: %s\n", find_address);
    } else if (allowed_chars_count > 0) 
    {
        int n = strlen(allowed_chars);
        quickSort(allowed_chars, 0, n - 1);

        for (int i = 0; allowed_chars[i] != '\0'; i++) {
            allowed_chars[i] = toupper(allowed_chars[i]);
        }

        printf("Enable: %s\n", allowed_chars);
    } else 
    {
        printf("Not found\n");
    }

    return 0;
}
