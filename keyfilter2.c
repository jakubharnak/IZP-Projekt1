#include <stdio.h>
#include <string.h>
#include <ctype.h>

char* strlwr(char* ); // aded this ale no global
char* strupr(char* ); // aded this ale no global
 // alebo kukni toto : https://learn.microsoft.com/en-us/cpp/c-runtime-library/reference/strlwr-wcslwr-mbslwr-strlwr-l-wcslwr-l-mbslwr-l?view=msvc-170

void swap(char* a, char* b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

// function to partition the string and return the pivot index
int partition(char* str, int low, int high)
{
    char pivot = str[high]; // choose the last character as the pivot
    int i = low - 1; // index of the smaller element

    // loop through the sub-array to partition it around the pivot
    for (int j = low; j <= high - 1; j++) {
        // if the current character is smaller than or equal to the pivot
        if (str[j] <= pivot) {
            i++; // increment the index of the smaller element
            swap(&str[i], &str[j]); // swap the current character with str[i]
        }
    }
    swap(&str[i + 1], &str[high]); // swap the pivot with str[i + 1]
    return i + 1; // return the pivot index
}

// function to sort the string using the Quick Sort algorithm
void quickSort(char* str, int low, int high)
{
    if (low < high) {
        int pivotIndex = partition(str, low, high); // partition the string and get the pivot index
        quickSort(str, low, pivotIndex - 1); // sort the left sub-array
        quickSort(str, pivotIndex + 1, high); // sort the right sub-array
    }
}

int startWith(char arr[], char substring[])
{
    for (unsigned int i = 0; i < strlen(arr); i++)
    {
        if (arr[i] == '\n')
        {
            arr[i]= 0;
        }
        continue;
    }
    // get number of characters in substring
    int subStrLen = strlen(substring) ;
    // get number of characters in char array string
    int mainStrLen = strlen(arr);
    // Check if char array starts with the given substring

    if( mainStrLen >= subStrLen && (strncmp(arr, substring, subStrLen) == 0)) {
    	return 1;
    }
    return 0;
}

int main(int argc, char *argv[]) 
{
    strlwr(argv[1]);
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
    	    strlwr(lowercase_name);
    		if (argv[1][0] == 0)  {
    			find_address_count++;
    			if (find_address_count == 1) {
        			strcpy(find_address,lowercase_name);
    			}
                    pPosition = strchr(allowed_chars, lowercase_name[0]);

                    // do ifu mozno  strchr(allowed_chars, lowercase_name[0])
				if (strchr(allowed_chars, lowercase_name[0]) == 0)  {
					allowed_chars[allowed_chars_count++] = lowercase_name[0];
				}
    		} else {
            
    			if(startWith(lowercase_name, argv[1]) == 1) {
    				find_address_count++;
        			if (find_address_count == 1) {
            			strcpy(find_address,lowercase_name);
        			}
                    // strcpy(pPosition,strchr(allowed_chars, lowercase_name[strlen(argv[1])]));

    			    pPosition  = strchr(allowed_chars, lowercase_name[strlen(argv[1])]);

                    // mozno do ifu strchr(allowed_chars, lowercase_name[strlen(argv[1])])
    				if (pPosition == 0)  {
    					allowed_chars[allowed_chars_count++] = lowercase_name[strlen(argv[1])];
    				}
                                   
    			}
    		}
    	}
    } while (i < 2);
    if (find_address_count == 1) 
    {
        printf("Found: %s\n", (char*)strupr(find_address));
    } else if (allowed_chars_count > 0) 
    {
        int n = strlen(allowed_chars);
        quickSort(allowed_chars, 0, n - 1);

        printf("Enable: %s\n", strupr(allowed_chars));
    } else 
    {
        printf("Not found\n");
    }

    return 0;
}
