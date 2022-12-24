#include <stdio.h>
#include <string.h>

// Hash table size (must be a power of 2)


// Hash table
char hash_table[15][4];

// Hash function for strings
int hash_string(char *str)
{
    // Calculate the hash value as the sum of the ASCII values of the characters in the string
    int hash = 0;
    for (int i = 0; i < strlen(str); i++)
    {
        hash += ((((int)str[i])+5))*666 ;
    }

    // Return the hash value modulo the table size
    return hash % 15;
}

// Function to insert a string into the hash table
int insert_string(char *str)
{
    // Calculate the hash value of the string
    int hash = hash_string(str);

    // Perform linear probing to find an empty slot
    int num_probes = 0;
    while (strlen(hash_table[hash]) > 0 && num_probes < 15)
    {
        hash = (hash + 1) % 15; // Move to the next slot in the table
        num_probes++;
    }

    // Check if we found an empty slot
    if (num_probes < 15)
    {
        // Insert the string into the empty slot
        strcpy(hash_table[hash], str);
        return hash;
    }
    else
    {
        // The table is full, return -1 to indicate failure
        return -1;
    }
}

int main()
{
    // Insert some strings into the hash table
    insert_string("rid");
    insert_string("aal");
    insert_string("lah");
    insert_string("jai");
    insert_string("ja ");
    // Print the contents of the hash table
    for (int i = 0; i < 15; i++)
    {
        printf("%d: %s\n", i, hash_table[i]);
    }

    return 0;
}
